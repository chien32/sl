#define SOY_DEBUG
#define SOY_HARDWARE_ENABLE
#include "soy.h"

/* @soylib callbacks *******************************************************/

#define CHUNK_WIDTH 64
#define CHUNK_SCALE 64.0f
#define BLOCK_DIVISOR 8.0f
#define CHUNK_SIZE CHUNK_WIDTH*CHUNK_WIDTH
#define MAP_WIDTH 32

typedef struct tag_gameModel {
  SOY_VAO vao;
  SOY_VBO vbo;
  size_t numVertices;
} gameModel;

typedef struct tag_gameChunk gameChunk;

typedef struct tag_gameTile {
  uint16 height;
  uint16 flags;
} gameTile;

typedef struct tag_gameVertex {
  uint32 lo;
  uint32 hi;
} gameVertex;

struct tag_gameChunk {
  gameTile tiles[CHUNK_SIZE];
  gameVertex vertices[CHUNK_SIZE*6];
  int32 x;
  int32 y;
  gameModel model;
  gameChunk* neighbours[8];
};

typedef struct tag_gameTransform {
  vec3f position;
  vec3f direction;
  vec3f lookAt;
} gameTransform;

typedef struct tag_gameCamera {
  gameTransform transform;
  real32 reticleSize;
  real32 fieldOfView;
  real32 nearPlane;
  real32 farPlane;
} gameCamera;

typedef struct tag_gamePlayer {
  gameTransform transform;
} gamePlayer;

typedef struct tag_gameWorld {
  gameChunk chunks[MAP_WIDTH*MAP_WIDTH];
  gameChunk water[MAP_WIDTH*MAP_WIDTH];
  gamePlayer player;
  real32 oceanLevel;
  uint32 divisions;
  int32 pointX;
  int32 pointY;
  int32 debugRender;
  int32 renderMode;
  real32 worldTime;
  gameCamera camera;
  soyGLTexture framebufferTexture;
  gameModel tileModel;
  soyModel quadModel;
  soyModel cubeModel;
  soyShader tileShader;
  soyShader blockShader;
  soyShader waterShader;
  soyShader framebufferShader;
  int32 guiUpdateFrame;
  real32 editTimer;
  real32 editSpeed;
  int64 editClock;
  int32 debugControls;
} gameWorld;

SOY_GLOBAL gameWorld g_world;

#define GAME_wrap(x, max) \
  ((((x)%(max)) + (max))%max)

#define GAME_orientQuad(t1, t2, t3, t4) \
  (fabs((t2) - (t3)) >= fabs((t1) - (t4)))

/* math ********************************************************************/

real32 GAME_getEditGradient(real32 x, real32 y) {
  return sqrt(SOY_MIN(SOY_MAX(1.0f - x*x - y*y, 0.0f), 1.0f));
}

real32 GAME_heightGenerate(real32 x, real32 y) {
  real32 rh;
  rh = SOY_noiseDomainWarp2D(SOY_noiseSimplex2D,
      x*0.01f, y*0.01f,
      0.2f, 0.3f, 0.5f,
      1.0f, 0.5f, 12, 6);
  rh = SOY_noiseSimplexNormalize(rh);
  rh = SOY_MIN(SOY_MAX(rh, 0.0f), 1.0f);
  return rh;
  return GAME_getEditGradient(fmod(x, 4.0f) - 2.0f, fmod(y, 4.0f) - 2.0f)*0.02f + 0.51;
}

gameTile* GAME_findTilePtr(gameChunk* chunk, int32 x, int32 y) {
  int32 cw = CHUNK_WIDTH - 1;
  int32 cf = CHUNK_WIDTH;
  if(!chunk) { return NULL; }
  if(x < 0) { return GAME_findTilePtr(chunk->neighbours[0], cf + x, y); }
  if(x > cw) { return GAME_findTilePtr(chunk->neighbours[1], x - cf, y); }
  if(y < 0) { return GAME_findTilePtr(chunk->neighbours[2], x, cf + y); }
  if(y > cw) { return GAME_findTilePtr(chunk->neighbours[3], x, y - cf); }
  return &chunk->tiles[x + y*CHUNK_WIDTH];
}

gameTile* GAME_getTilePtr(gameChunk* chunk, int32 x, int32 y) {
  if(!chunk) { return NULL; }
  if(x < 0  || y < 0 || x >= CHUNK_WIDTH || y >= CHUNK_WIDTH) {
    return GAME_findTilePtr(chunk, x, y);
  } else {
    return &chunk->tiles[x + y*CHUNK_WIDTH];
  }
}

gameTile GAME_getVertex(gameChunk* chunk, int32 x, int32 y) {
  gameTile ret;
  int32 cw = CHUNK_WIDTH - 1;
  ret.flags = 0;
  ret.height = 0;
  if(!chunk) { return ret; }
  if(x < 0  || y < 0 || x >= CHUNK_WIDTH || y >= CHUNK_WIDTH) {
    if(x <  0) { return GAME_getVertex(chunk->neighbours[0], cw, y); }
    if(x > cw) { return GAME_getVertex(chunk->neighbours[1], 0,  y); }
    if(y <  0) { return GAME_getVertex(chunk->neighbours[2], x, cw); }
    if(y > cw) { return GAME_getVertex(chunk->neighbours[3], x,  0); }
  } else {
    return chunk->tiles[x + y*CHUNK_WIDTH];
  }
  return ret;
}

gameChunk* GAME_getChunkPtr(gameChunk* chunks,
    int32 x, int32 y) {
  if(!chunks) { return NULL; }
  if(x < 0  || y < 0 || x >= MAP_WIDTH || y >= MAP_WIDTH) { return 0; }
  return &chunks[x + y*MAP_WIDTH];
}

/* chunk *******************************************************************/

int32 GAME_terrainChunkInit(gameChunk* chunk) {
  SOY_glGenVertexArrays(1, &chunk->model.vao);
  SOY_glGenBuffers(1, &chunk->model.vbo);
  SOY_glBindVertexArray(chunk->model.vao);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, chunk->model.vbo);
  SOY_glVertexAttribEnable(0);
  SOY_glVertexAttribIPointer(0, 2, GL_UNSIGNED_INT, 0, 0);
  chunk->model.numVertices = 0;
  return TRUE;
}

int32 GAME_terrainChunkWaterGenerate(gameWorld* world,
    gameChunk* chunk,
    int32 worldX, int32 worldY) {
  int32 x, y;
  int32 waterLevel = 4096 / 2;
  int32 cx = GAME_wrap(worldX, MAP_WIDTH);
  int32 cy = GAME_wrap(worldY, MAP_WIDTH);
  chunk->x = worldX;
  chunk->y = worldY;
  chunk->neighbours[0] = GAME_getChunkPtr(world->water, cx - 1, cy);
  chunk->neighbours[1] = GAME_getChunkPtr(world->water, cx + 1, cy);
  chunk->neighbours[2] = GAME_getChunkPtr(world->water, cx, cy - 1);
  chunk->neighbours[3] = GAME_getChunkPtr(world->water, cx, cy + 1);
  chunk->neighbours[4] = GAME_getChunkPtr(world->water, cx - 1, cy - 1);
  chunk->neighbours[5] = GAME_getChunkPtr(world->water, cx - 1, cy + 1);
  chunk->neighbours[6] = GAME_getChunkPtr(world->water, cx + 1, cy - 1);
  chunk->neighbours[7] = GAME_getChunkPtr(world->water, cx + 1, cy + 1);
  for(y = 0; y < CHUNK_WIDTH; y++) {
    for(x = 0; x < CHUNK_WIDTH; x++) {
      chunk->tiles[x + y*CHUNK_WIDTH].height = (uint16)waterLevel;
    }
  }
  return TRUE;
}

int32 GAME_terrainChunkGenerate(gameWorld* world, gameChunk* chunk,
    int32 worldX, int32 worldY) {
  int32 x, y;
  real32 rx, ry;
  real32 height;
  real32 noise;
  int32 cx = GAME_wrap(worldX, MAP_WIDTH);
  int32 cy = GAME_wrap(worldY, MAP_WIDTH);
  chunk->x = worldX;
  chunk->y = worldY;
  chunk->neighbours[0] = GAME_getChunkPtr(world->chunks, cx - 1, cy);
  chunk->neighbours[1] = GAME_getChunkPtr(world->chunks, cx + 1, cy);
  chunk->neighbours[2] = GAME_getChunkPtr(world->chunks, cx, cy - 1);
  chunk->neighbours[3] = GAME_getChunkPtr(world->chunks, cx, cy + 1);
  chunk->neighbours[4] = GAME_getChunkPtr(world->chunks, cx - 1, cy - 1);
  chunk->neighbours[5] = GAME_getChunkPtr(world->chunks, cx - 1, cy + 1);
  chunk->neighbours[6] = GAME_getChunkPtr(world->chunks, cx + 1, cy - 1);
  chunk->neighbours[7] = GAME_getChunkPtr(world->chunks, cx + 1, cy + 1);
  for(y = 0; y < CHUNK_WIDTH; y++) {
    for(x = 0; x < CHUNK_WIDTH; x++) {
      rx = (real32)((real32)x + 0.5f + worldX*CHUNK_SCALE) / CHUNK_SCALE;
      ry = (real32)((real32)y + 0.5f + worldY*CHUNK_SCALE) / CHUNK_SCALE;
      noise = GAME_heightGenerate(rx, ry);
      height = (real32)((noise*4096.0f));
      chunk->tiles[x + y*CHUNK_WIDTH].height = ((uint16)height) & 0xFFF;
    }
  }
  return TRUE;
}

uint32 GAME_getAO(gameChunk* chunk, int32 x, int32 y) {
  real32 v = (real32)chunk->tiles[x + y*CHUNK_WIDTH].height / 4096.0f;
  real32 d = v*v*v*v*4.0f;
  return (uint32)(SOY_clamp(d, 0.0f, 1.0f)*255.0f);
}

int32 GAME_terrainChunkUpdate(gameChunk* chunk) {
  real32 rx, ry;
  real32 t1, t2, t3, t4;
  int32 x, y;
  int32 index;
  uint32 invertNormal;
  uint32 packX, packY, pack, packedType, packedNormal;
  uint32 nx, ny, nz;
  uint32 heights[4];
  uint32 verts[4];
  vec3f tri[3];
  vec3f normal;
  int32 obX, obY;
  uint32 orderA[6] = { 1, 5, 3, 3, 5, 7 };
  uint32 orderB[6] = { 3, 1, 7, 7, 1, 5 };
  uint32 kernelA[4] = { 0, 1, 2, 3 };
  uint32 kernelB[4] = { 2, 0, 3, 1 };
  uint32* kern = kernelA;
  uint32* order = orderA;
  real32 div = 8.0f;
  if(!chunk) { SOY_LOG("Fatal error. NULL chunk\n"); return FALSE; }
  chunk->model.numVertices = 0;
  for(y = 0; y < CHUNK_WIDTH; y++) {
    for(x = 0; x < CHUNK_WIDTH; x++) {
      rx = (real32)x;
      ry = (real32)y;
      index = (x + y*CHUNK_WIDTH)*6;
      packX = (x & 0xFF) << 0;
      packY = (y & 0xFF) << 8;
      pack = packX | packY;
      packedType = GAME_getAO(chunk, x, y) << 24;
      
      /* Land pass *********************************************************/
      obX = !(x == CHUNK_WIDTH - 1 && chunk->x == MAP_WIDTH - 1);
      obY = !(y == CHUNK_WIDTH - 1 && chunk->y == MAP_WIDTH - 1);
      t1 = ((real32)GAME_getVertex(chunk, x, y).height) / div;
      t2 = ((real32)GAME_getVertex(chunk, x + obX, y).height) / div;
      t3 = ((real32)GAME_getVertex(chunk, x, y + obY).height) / div;
      t4 = ((real32)GAME_getVertex(chunk, x + obX, y + obY).height) / div;
      if(GAME_orientQuad(t1, t2, t3, t4)) {
        order = orderB;
        kern = kernelB;
        invertNormal = TRUE;
      } else {
        order = orderA;
        kern = kernelA;
        invertNormal = FALSE;
      }
      verts[kern[0]] = GAME_getVertex(chunk, x, y).height;
      verts[kern[1]] = GAME_getVertex(chunk, x + obX, y).height;
      verts[kern[2]] = GAME_getVertex(chunk, x, y + obY).height;
      verts[kern[3]] = GAME_getVertex(chunk, x + obX, y + obY).height;
      heights[0] = (verts[0] & 0xFFF) << 16;
      heights[1] = (verts[1] & 0xFFF) << 16;
      heights[2] = (verts[2] & 0xFFF) << 16;
      heights[3] = (verts[3] & 0xFFF) << 16;
      /* Triangle A */
      if(invertNormal) {
        tri[0] = SOY_vec3f(rx, (real32)(verts[0])/div, ry);
        tri[1] = SOY_vec3f(rx, (real32)(verts[2])/div, ry + 1.0f);
        tri[2] = SOY_vec3f(rx + 1.0f, (real32)(verts[1])/div, ry);
      } else {
        tri[0] = SOY_vec3f(rx, (real32)(verts[0])/div, ry + 1.0f);
        tri[1] = SOY_vec3f(rx + 1.0f, (real32)(verts[2])/div, ry + 1.0f);
        tri[2] = SOY_vec3f(rx, (real32)(verts[1])/div, ry);
      }
      normal = v3Norm(SOY_getNormal(tri));
      nx = (uint32)(normal.x*127.0f + 128.0f);
      ny = (uint32)(normal.y*127.0f + 128.0f);
      nz = (uint32)(normal.z*127.0f + 128.0f);
      packedNormal = (nx & 0xFF) | ((ny & 0xFF) << 8) | ((nz & 0xFF) << 16);
      
      chunk->vertices[index + 0].lo = heights[0] | pack | (order[0] << 28);
      chunk->vertices[index + 0].hi = packedNormal | packedType;
      chunk->vertices[index + 1].lo = heights[2] | pack | (order[1] << 28);
      chunk->vertices[index + 1].hi = packedNormal | packedType;
      chunk->vertices[index + 2].lo = heights[1] | pack | (order[2] << 28);
      chunk->vertices[index + 2].hi = packedNormal | packedType;

      /* Triangle B */
      if(invertNormal) {
        tri[0] = SOY_vec3f(rx + 1.0f, (real32)(verts[1])/div, ry);
        tri[1] = SOY_vec3f(rx, (real32)(verts[2])/div, ry + 1.0f);
        tri[2] = SOY_vec3f(rx + 1.0f, (real32)(verts[3])/div, ry + 1.0f);
      } else {
        tri[0] = SOY_vec3f(rx, (real32)(verts[1])/div, ry);
        tri[1] = SOY_vec3f(rx + 1.0f, (real32)(verts[2])/div, ry + 1.0f);
        tri[2] = SOY_vec3f(rx + 1.0f, (real32)(verts[3])/div, ry);
      }
      normal = v3Norm(SOY_getNormal(tri));
      nx = (uint32)(normal.x*127.0f) + 128;
      ny = (uint32)(normal.y*127.0f) + 128;
      nz = (uint32)(normal.z*127.0f) + 128;
      packedNormal = (nx & 0xFF) | ((ny & 0xFF) << 8) | ((nz & 0xFF) << 16);
      
      chunk->vertices[index + 3].lo = heights[1] | pack | (order[3] << 28);
      chunk->vertices[index + 3].hi = packedNormal | packedType;
      chunk->vertices[index + 4].lo = heights[2] | pack | (order[4] << 28);
      chunk->vertices[index + 4].hi = packedNormal | packedType;
      chunk->vertices[index + 5].lo = heights[3] | pack | (order[5] << 28);
      chunk->vertices[index + 5].hi = packedNormal | packedType;
      
      chunk->model.numVertices += 6;
    }
  }
  return TRUE;
}

int32 GAME_terrainChunkUpdateBuffers(gameChunk* chunk) {
  SOY_glBindBuffer(GL_ARRAY_BUFFER, chunk->model.vbo);
  SOY_glBufferData(GL_ARRAY_BUFFER,
      chunk->model.numVertices*sizeof(uint32)*2, chunk->vertices);
  return TRUE;
}

int32 GAME_terrainChunkUpdateNeighbours(gameChunk* chunk) {
  int32 i;
  for(i = 0; i < 8; i++) {
    if(chunk->neighbours[i]) {
      GAME_terrainChunkUpdate(chunk->neighbours[i]);
      GAME_terrainChunkUpdateBuffers(chunk->neighbours[i]);
    }
  }
  return TRUE;
}

/* terrain edit ************************************************************/

uint32 GAME_changeTileElevation(gameWorld* world, gameChunk* chunk,
    int32 ix, int32 iy, int32 dir) {
  int32 x, y;
  real32 rx, ry;
  gameTile* tile;
  real32 factor;
  int32 rad = (uint32)(world->camera.reticleSize + 1.0f);
  int32 hrad = rad/2;
  int32 signHeight = 0;
  uint32 tempTile = 0;
  for(x = -hrad + 1; x < hrad + 1; x++) {
    for(y = -hrad + 1; y < hrad + 1; y++) {
      rx = (real32)x / (real32)hrad;
      ry = (real32)y / (real32)hrad;
      tile = GAME_getTilePtr(chunk, ix + x, iy + y);
      factor = GAME_getEditGradient(rx, ry)*8.0f;
      if(factor < 0.0f) { factor = 0.0f; }
      if(factor >= 7.0f) { factor = 7.0f; }
      if(tile) {
        tempTile = (tile->height) & 0xFFFF0000;
        signHeight = (int32)((tile->height) & 0xFFF);
        signHeight += dir ? (int32)factor : -(int32)factor;
        tempTile |= (uint32)SOY_MIN(SOY_MAX(signHeight, 0), 4095);
        tile->height = tempTile;
      }
    }
  }
  return TRUE;
}

/* terrain collision *******************************************************/

real32 GAME_tileHeightAt(gameWorld* world,
    gameChunk* chunk, real32 x, real32 y) {
  int32 invQuad;
  real32 d1, d2, d3;
  real32 height;
  real32 triangleA[3][3];
  real32 hx = x + 0.5f;
  real32 hy = y + 0.5f;
  int32 bx = GAME_wrap((int32)hx, CHUNK_WIDTH);
  int32 by = GAME_wrap((int32)hy, CHUNK_WIDTH);
  real32 tx = ((real32)chunk->x) * CHUNK_SCALE;
  real32 ty = ((real32)chunk->y) * CHUNK_SCALE; 
  real32 fracX = x - (real32)SOY_FASTFLOOR(hx);
  real32 fracY = y - (real32)SOY_FASTFLOOR(hy);
  real32 t1 = (real32)GAME_getVertex(chunk, bx, by).height / 8.0f;
  real32 t2 = (real32)GAME_getVertex(chunk, bx + 1, by).height / 8.0f;
  real32 t3 = (real32)GAME_getVertex(chunk, bx, by + 1).height / 8.0f;
  real32 t4 = (real32)GAME_getVertex(chunk, bx + 1, by + 1).height / 8.0f;
  real32 fx = bx + tx - 0.5f;
  real32 fy = by + ty - 0.5f;
  invQuad = GAME_orientQuad(t1, t2, t3, t4);
  if(invQuad ? (fracX > fracY) : (fracX < -1.0f*fracY)) {
    if(!invQuad) {
      triangleA[0][0] = 0.0f + fx;
      triangleA[0][1] = t1;
      triangleA[0][2] = 0.0f + fy;
      triangleA[1][0] = 1.0f + fx;
      triangleA[1][1] = t2;
      triangleA[1][2] = 0.0f + fy;
      triangleA[2][0] = 0.0f + fx;
      triangleA[2][1] = t3;
      triangleA[2][2] = 1.0f + fy;
    } else {
      triangleA[0][0] = 0.0f + fx;
      triangleA[0][1] = t1;
      triangleA[0][2] = 0.0f + fy;
      triangleA[1][0] = 1.0f + fx;
      triangleA[1][1] = t2;
      triangleA[1][2] = 0.0f + fy;
      triangleA[2][0] = 1.0f + fx;
      triangleA[2][1] = t4;
      triangleA[2][2] = 1.0f + fy;
    }
  } else {
    if(!invQuad) {
      triangleA[0][0] = 0.0f + fx;
      triangleA[0][1] = t3;
      triangleA[0][2] = 1.0f + fy;
      triangleA[1][0] = 1.0f + fx;
      triangleA[1][1] = t2;
      triangleA[1][2] = 0.0f + fy;
      triangleA[2][0] = 1.0f + fx;
      triangleA[2][1] = t4;
      triangleA[2][2] = 1.0f + fy;
    } else {
      triangleA[0][0] = 0.0f + fx;
      triangleA[0][1] = t1;
      triangleA[0][2] = 0.0f + fy;
      triangleA[1][0] = 1.0f + fx;
      triangleA[1][1] = t4;
      triangleA[1][2] = 1.0f + fy;
      triangleA[2][0] = 0.0f + fx;
      triangleA[2][1] = t3;
      triangleA[2][2] = 1.0f + fy;
    }
  }
  SOY_barycentric(
      triangleA[0][0], triangleA[0][2],
      triangleA[1][0], triangleA[1][2],
      triangleA[2][0], triangleA[2][2],
      x, y, &d1, &d2, &d3);
  height = 0.0f;
  height += triangleA[0][1] * d1;
  height += triangleA[1][1] * d2;
  height += triangleA[2][1] * d3;
  return height;
}

/* transform ***************************************************************/

vec3f GAME_lookAt(vec3f dir) {
  vec3f ret;
  ret.x = cos(dir.x) * sin(dir.y);
  ret.y = sin(-dir.x);
  ret.z = cos(dir.x) * cos(dir.y);
  return ret;
}


int32 GAME_transformInit(gameTransform* t, real32 x, real32 y, real32 z) {
  t->position = SOY_vec3f(x, y, z);
  t->direction = SOY_vec3f(0.0f, 0.0f, 0.0f);
  t->lookAt = GAME_lookAt(t->direction);
  return TRUE;
}

int32 GAME_transformMoveFree(gameTransform* t,
    real32 force, real32 sideForce, real32 up, real32 dt) {
  real32 sx = sin(t->direction.y - SOY_PI/2);
  real32 sz = cos(t->direction.y - SOY_PI/2);
  t->position.x += t->lookAt.x*force + sx*sideForce;
  t->position.y += t->lookAt.y*force + up;
  t->position.z += t->lookAt.z*force + sz*sideForce;
  SOY_UNUSED(dt);
  return TRUE;
}

int32 GAME_transformMoveGround(gameTransform* t,
    real32 force, real32 sideForce, real32 up, real32 dt) {
  real32 sx = sin(t->direction.y - SOY_PI/2);
  real32 sz = cos(t->direction.y - SOY_PI/2);
  t->position.x += t->lookAt.x*force + sx*sideForce;
  t->position.z += t->lookAt.z*force + sz*sideForce;
  t->position.y += up;
  SOY_UNUSED(dt);
  return TRUE;
}

int32 GAME_transformApplyGravity(gameTransform* t,
    real32 gravity, real32 dt) {
  t->position.y -= gravity*dt;
  SOY_UNUSED(dt);
  return TRUE;
}

int32 GAME_transformRotate(gameTransform* t,
    real32 pitch, real32 yaw, real32 dt) {
  t->direction.y += pitch*dt*0.5f;
  t->direction.x += yaw*dt*0.5f;
  t->lookAt = GAME_lookAt(t->direction);
  return TRUE;
}

mat4f GAME_transformViewMatrix(gameTransform* t) {
  mat4f ret = SOY_mat4f(1.0f);
  mat4f rotY = SOY_mat4fRotationY(-t->direction.y);
  mat4f rotX = SOY_mat4fRotationX(-t->direction.x);
  mat4f trans = SOY_mat4fTranslation(
      -t->position.x,
      -t->position.y,
      -t->position.z);
  ret = SOY_mat4fMultiply(ret, trans);
  ret = SOY_mat4fMultiply(ret, rotY);
  ret = SOY_mat4fMultiply(ret, rotX);
  return ret;
}

mat4f GAME_viewMatrix(vec3f position, vec3f direction) {
  mat4f ret = SOY_mat4f(1.0f);
  mat4f rotY = SOY_mat4fRotationY(-direction.y);
  mat4f rotX = SOY_mat4fRotationX(-direction.x);
  mat4f trans = SOY_mat4fTranslation(
      -position.x,
      -position.y,
      -position.z);
  ret = SOY_mat4fMultiply(ret, trans);
  ret = SOY_mat4fMultiply(ret, rotY);
  ret = SOY_mat4fMultiply(ret, rotX);
  return ret;
}

int32 GAME_transformUpdate(gameWorld* world, gameTransform* t,
    real32 forward, real32 side, real32 up, real32 mx, real32 my, 
    int32 debugMode, real32 dt) {
  GAME_transformRotate(t, mx, my, dt);
  if(debugMode) {
    GAME_transformMoveFree(t, forward, side, up, dt);
  } else {
    GAME_transformMoveGround(t, forward, side, up, dt);
  }
  return TRUE;
}

int32 GAME_transformClipToTerrain(gameTransform* t,
    real32 height, real32 dt) {
  t->position.y = SOY_MIN(SOY_MAX(t->position.y, height), 1024.0f);
  SOY_UNUSED(dt);
  return TRUE;
}

int32 GAME_transformClip(gameWorld* world, gameTransform* t,
    real32 offset, real32 dt) {
#if 1
  real32 x = t->position.x;
  real32 y = t->position.z;
  real32 hx = x + 0.5f;
  real32 hy = y + 0.5f;
  int32 cx = GAME_wrap(((int32)hx) / CHUNK_WIDTH, MAP_WIDTH);
  int32 cy = GAME_wrap(((int32)hy) / CHUNK_WIDTH, MAP_WIDTH);
  gameChunk* c = GAME_getChunkPtr(world->chunks, cx, cy);
  GAME_transformClipToTerrain(
      t, GAME_tileHeightAt(world, c, x, y) + offset, dt);
#endif
  return TRUE;
}

/* camera ******************************************************************/

int32 GAME_cameraInit(gameCamera* cam, real32 x, real32 y, real32 z) {
  GAME_transformInit(&cam->transform, x, y, z);
  cam->farPlane = 1000.0f;
  cam->nearPlane = 0.01f;
  cam->reticleSize = 4.0f;
  cam->fieldOfView = 90.0f;
  return TRUE;
}

/* player ******************************************************************/

int32 GAME_playerInit(gamePlayer* p, real32 x, real32 y, real32 z) {
  GAME_transformInit(&p->transform, x, y, z);
  return TRUE;
}

/* raycasting **************************************************************/

typedef int32 (*PFRAYCASTPROC)
  (soyApp* app, gameWorld* world, int32 x, int32 y, int32 z, vec3f face);

int32 GAME_rayCast(soyApp* app, gameTransform* t, gameWorld* world,
    real32 r, PFRAYCASTPROC proc) {
  int32 maxSteps = (int32)r;
  int32 ix = SOY_FASTFLOOR(t->position.x + 0.5f);
  int32 iy = SOY_FASTFLOOR(t->position.y + 0.5f);
  int32 iz = SOY_FASTFLOOR(t->position.z + 0.5f);
  int32 x = ix;
  int32 y = iy;
  int32 z = iz;
  real32 dx = t->lookAt.x;
  real32 dy = t->lookAt.y;
  real32 dz = t->lookAt.z;
  int32 stepX = SOY_sign(dx);
  int32 stepY = SOY_sign(dy);
  int32 stepZ = SOY_sign(dz);
  real32 maxX = SOY_intBounds(t->position.x + 0.5f, dx);
  real32 maxY = SOY_intBounds(t->position.y + 0.5f, dy);
  real32 maxZ = SOY_intBounds(t->position.z + 0.5f, dz);
  real32 deltaX = stepX / dx;
  real32 deltaY = stepY / dy;
  real32 deltaZ = stepZ / dz;
  vec3f face = SOY_vec3f(0.0f, 0.0f, 0.0f);
  if(dx == 0.0f && dy == 0.0f && dz == 0.0f) { return FALSE; }
  r /= sqrt(dx*dx + dy*dy + dz*dz);
  while(maxSteps--) {
    if(proc) { if(proc(app, world, x, y, z, face)) { break; } }
    if(maxX < maxY) {
      if(maxX < maxZ) {
        if(maxX > r) { break; }
        x += stepX;
        maxX += deltaX;
      } else {
        if(maxZ > r) { break; }
        z += stepZ;
        maxZ += deltaZ;
      }
    } else {
      if(maxY < maxZ) {
        if(maxY > r) { break; }
        y += stepY;
        maxY += deltaY;
      } else {
        if(maxZ > r) { break; }
        z += stepZ;
        maxZ += deltaZ;
      }
    }
  }
  return TRUE;
}

/* TODO: shitty fucking raycasting does work */

int32 GAME_rayCastRenderProc(soyApp* app, gameWorld* world,
    int32 x, int32 y, int32 z, vec3f face) {
  int32 cx, cy;
  int32 bx, by;
  gameTile* verts[4];
  uint32 size[4];
  uint32 min;
  gameChunk* chunk;
  real32 tx, ty;
  int32 rebuild = FALSE;
  real32 w = (real32)SOY_width(app);
  real32 h = (real32)SOY_height(app);
  mat4f model = SOY_mat4f(1.0f);
  mat4f view = GAME_transformViewMatrix(&world->camera.transform);
  mat4f projection = SOY_mat4fProjection(0.1f, 2000.0f, 90.0f, h/w);
  real32 delta = 
    (real32)SOY_wallClockDelta(world->editClock, SOY_wallClock()) * 1000.0f;

  world->editClock = SOY_wallClock();
  SOY_UNUSED(face);

  SOY_glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  cx = GAME_wrap(x/CHUNK_WIDTH, MAP_WIDTH);
  cy = GAME_wrap(z/CHUNK_WIDTH, MAP_WIDTH);
  bx = GAME_wrap(x, CHUNK_WIDTH);
  by = GAME_wrap(z, CHUNK_WIDTH);
  chunk = GAME_getChunkPtr(world->chunks, cx, cy);
  verts[0] = GAME_getTilePtr(chunk, bx, by);
  verts[1] = GAME_getTilePtr(chunk, bx + 1, by);
  verts[2] = GAME_getTilePtr(chunk, bx, by + 1);
  verts[3] = GAME_getTilePtr(chunk, bx + 1, by + 1);
  size[0] = (verts[0] ? (verts[0]->height & 0xFFF) / 8 : 0);
  size[1] = (verts[1] ? (verts[1]->height & 0xFFF) / 8 : 0);
  size[2] = (verts[2] ? (verts[2]->height & 0xFFF) / 8 : 0);
  size[3] = (verts[3] ? (verts[3]->height & 0xFFF) / 8 : 0);
  min = SOY_MIN(SOY_MIN(SOY_MIN(size[0], size[1]), size[2]), size[3]);
  if((int32)min >= y) {
    SOY_useShader(&world->blockShader);
    SOY_glDisable(GL_CULL_FACE);
    SOY_glDisable(GL_DEPTH_TEST);
    SOY_glEnable(GL_BLEND);
    SOY_glSetUniformInt(&world->blockShader, "debugCol", 0);
    SOY_glSetUniformFloat(&world->blockShader, "outlineWidth", 10.0f);
    SOY_mat4fTranslate(&model, x, (real32)(min), z);
    SOY_setMVP(&world->blockShader, &model, &view, &projection);
    SOY_renderModel(&world->cubeModel);
    tx = (real32)cx*CHUNK_SCALE;
    ty = (real32)cy*CHUNK_SCALE;
    SOY_glDisable(GL_CULL_FACE);
    SOY_glEnable(GL_BLEND);
    model = SOY_mat4f(1.0f);
    SOY_mat4fScale(&model, CHUNK_SCALE, CHUNK_SCALE*255.0f, CHUNK_SCALE);
    SOY_mat4fTranslate(&model,
        tx + CHUNK_SCALE*0.5f - 0.5f,
        CHUNK_SCALE*0.5f + 0.49f,
        ty + CHUNK_SCALE*0.5f - 0.5f);
    SOY_setMVP(&world->blockShader, &model, &view, &projection);
    SOY_renderModel(&world->cubeModel);
    SOY_glEnable(GL_CULL_FACE);
    SOY_glEnable(GL_DEPTH_TEST);
    SOY_glDisable(GL_BLEND);
    if(SOY_mouseHeld(app, SOY_MOUSE_LEFT)) {
      if(world->editTimer > world->editSpeed) {
        GAME_changeTileElevation(world, chunk, bx, by, 1);
        world->editTimer -= world->editSpeed;
      }
      world->editTimer += delta;
      rebuild = TRUE;
    }
    if(SOY_mouseHeld(app, SOY_MOUSE_RIGHT)) {
      if(world->editTimer > world->editSpeed) {
        GAME_changeTileElevation(world, chunk, bx, by, 0);
        world->editTimer -= world->editSpeed;
      }
      world->editTimer += delta;
      rebuild = TRUE;
    }
    world->pointX = bx;
    world->pointY = by;
    if(rebuild) {
      GAME_terrainChunkUpdate(chunk);
      GAME_terrainChunkUpdateBuffers(chunk);
      GAME_terrainChunkUpdateNeighbours(chunk);
    }
    return TRUE;
  }
  return FALSE;
}

/* files *******************************************************************/

int32 GAME_loadCamera(gameCamera* camera, int8* filename) {
  FILE* file = SOY_fileOpen(filename, "rb");
  if(!file) { return FALSE; }
  fread(camera, 1, sizeof(gameCamera), file);
  SOY_fileClose(file);
  return TRUE;
}

int32 GAME_saveCamera(gameCamera* camera, int8* filename) {
  FILE* file = SOY_fileOpen(filename, "wb");
  if(!file) { return FALSE; }
  fwrite(camera, 1, sizeof(gameCamera), file);
  SOY_fileClose(file);
  return TRUE;
}

/* gui *********************************************************************/

int32 GAME_updateGUITexture(soyCanvas* canvas, soyFont* font,
    gameWorld* gw, int32 w, int32 h) {
  SOY_UNUSED(font);
  SOY_drawSetColour(canvas, 0xFF000000);
  SOY_drawClear(canvas);
  SOY_drawSetColour(canvas, 0x22222222);
  SOY_drawRectFill(canvas, 24, 24, w - 24, 24 + 64);
  SOY_drawSetColour(canvas, 0xFF666666);
  SOY_drawTextFormat(canvas, font, 33, 33,
      "X: %f Y: %f Z: %f\n"
      ,
      gw->camera.transform.position.x,
      gw->camera.transform.position.y,
      gw->camera.transform.position.z
      );
 
  SOY_drawSetColour(canvas, 0xFFFFFFFF);
  SOY_drawTextFormat(canvas, font, 32, 32,
      "X: %f Y: %f Z: %f\n"
      ,
      gw->camera.transform.position.x,
      gw->camera.transform.position.y,
      gw->camera.transform.position.z
      );

  SOY_drawCircle(canvas, w/2, h/2, 4.0f*gw->camera.reticleSize);


  if(gw->guiUpdateFrame > 30) {
    SOY_updateGLTexture(&gw->framebufferTexture,
        w, h, (uint8*)canvas->rgba.data);
   gw->guiUpdateFrame = 0;
  }
  gw->guiUpdateFrame++;
  return TRUE;
}

int32 GAME_renderGUITexture(gameWorld* world) {
  SOY_useShader(&world->framebufferShader);
  SOY_glActiveTexture(GL_TEXTURE0 + 0);
  SOY_glBindTexture(GL_TEXTURE_2D, world->framebufferTexture.id);
  SOY_glSetUniformInt(&world->framebufferShader, "framebuffer", 0);
  SOY_glDisable(GL_DEPTH_TEST);
  SOY_glDisable(GL_CULL_FACE);
  SOY_glEnable(GL_BLEND);
  SOY_glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  SOY_renderModel(&world->quadModel);
  return TRUE;
}

/* world *******************************************************************/

int32 GAME_worldInit(soyApp* app, gameWorld* world) {
  int32 i;
#if 0
  real32 pos = (real32)MAP_WIDTH * CHUNK_SCALE / 2.0f;
#endif
  gameChunk* chunk;
  SOY_UNUSED(app);
  SOY_createShader(&world->tileShader,
      "shaders/terrain_vert.soy",
      "shaders/terrain_frag.soy");
  SOY_createShader(&world->blockShader,
      "shaders/block_vert.soy",
      "shaders/block_frag.soy");
  SOY_createShader(&world->waterShader,
      "shaders/water_vert.soy",
      "shaders/water_frag.soy");
  SOY_createShader(&world->framebufferShader,
      "shaders/framebuffer_vert.soy",
      "shaders/framebuffer_frag.soy");
  SOY_glCullFace(GL_BACK);
  SOY_glEnable(GL_CULL_FACE);
  SOY_glEnable(GL_MULTISAMPLE);
  SOY_glEnable(GL_STENCIL_TEST);
  SOY_glEnable(GL_DEPTH_TEST);
  
  for(i = 0; i < MAP_WIDTH*MAP_WIDTH; i++) {
    chunk = &world->chunks[i];
    GAME_terrainChunkInit(chunk);
    GAME_terrainChunkGenerate(world, chunk, i%MAP_WIDTH, i/MAP_WIDTH);
    chunk = &world->water[i];
    GAME_terrainChunkInit(chunk);
    GAME_terrainChunkWaterGenerate(world, chunk, i%MAP_WIDTH, i/MAP_WIDTH);
  }

  for(i = 0; i < MAP_WIDTH*MAP_WIDTH; i++) {
    chunk = &world->chunks[i];
    GAME_terrainChunkUpdate(chunk);
    GAME_terrainChunkUpdateBuffers(chunk);
    chunk = &world->water[i];
    GAME_terrainChunkUpdate(chunk);
    GAME_terrainChunkUpdateBuffers(chunk);
  }

  SOY_modelInitCube(&world->cubeModel);
  SOY_modelInitQuad(&world->quadModel);
  
  SOY_glGenVertexArrays(1, &world->tileModel.vao);
  SOY_glGenBuffers(1, &world->tileModel.vbo);
  SOY_glBindVertexArray(world->tileModel.vao);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, world->tileModel.vbo);
  SOY_glVertexAttribEnable(0);
  SOY_glVertexAttribIPointer(0, 2, GL_UNSIGNED_INT, 0, 0);
  world->tileModel.numVertices = 0;

  world->camera.reticleSize = 1.0f;
  world->debugRender = FALSE;
  world->renderMode = 0;
  world->guiUpdateFrame = 0;
  world->worldTime = 0.0f;
  world->pointX = 0;
  world->pointY = 0;
  world->editClock = 0;
  world->editSpeed = 0.002f;
  world->editTimer = 0.0f;
  world->divisions = 8;
  world->debugControls = TRUE;

  GAME_cameraInit(&world->camera, 0.0f, 0.0f, 0.0f);
  GAME_playerInit(&world->player, 0.0f, 0.0f, 0.0f);
  return TRUE;
}

SOY_GLOBAL uint32 g_currentTileBuffer[6*2];

int32 GAME_worldGenerateCurrentTile(gameWorld* world, gameTransform* t) {
  real32 x = t->position.x;
  real32 y = t->position.z;
  int32 cx = GAME_wrap((int32)x / CHUNK_WIDTH, MAP_WIDTH);
  int32 cy = GAME_wrap((int32)y / CHUNK_WIDTH, MAP_WIDTH);
  int32 bx = GAME_wrap((int32)x, CHUNK_WIDTH);
  int32 by = GAME_wrap((int32)x, CHUNK_WIDTH);
  gameChunk* chunk = GAME_getChunkPtr(world->chunks, cx, cy);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, world->tileModel.vbo);
  SOY_glBufferData(GL_ARRAY_BUFFER,
      6*2, &chunk->vertices[bx + by*CHUNK_WIDTH]);
  world->tileModel.numVertices = 6*2;
  return TRUE;
}

SOY_GLOBAL real32 g_jumpForce = 0.0f;

int32 GAME_worldUpdate(soyApp* app, gameWorld* world, real32 dt) {
  real32 playerSpeed = dt*5.0f;
  real32 mdx = ((real32)SOY_mouseDeltaX(app));
  real32 mdy = ((real32)SOY_mouseDeltaY(app));
  real32 force = 0.0f;
  real32 sideForce = 0.0f;
  real32 upForce = 0.0f;
  gameTransform* controller;
  if(SOY_keyHeld(app, SOY_SHIFT)) { playerSpeed = dt*100.0f; }
  if(SOY_keyHeld(app, SOY_CONTROL)) { playerSpeed = dt*0.2f; }
  if(SOY_keyHeld(app, SOY_W)) { force = playerSpeed; }
  if(SOY_keyHeld(app, SOY_S)) { force = -playerSpeed; }
  if(SOY_keyHeld(app, SOY_A)) { sideForce = playerSpeed; }
  if(SOY_keyHeld(app, SOY_D)) { sideForce = -playerSpeed; }
  if(SOY_keyPressed(app, SOY_F1)) { SOY_glEnable(GL_MULTISAMPLE); }
  if(SOY_keyPressed(app, SOY_F2)) { SOY_glDisable(GL_MULTISAMPLE); }
  if(SOY_keyPressed(app, SOY_F3)) {
    world->renderMode++;
    world->renderMode %= 4;
  }
  if(SOY_keyPressed(app, SOY_F5)) {
    GAME_saveCamera(&world->camera, "camera.soy");
  }
  if(SOY_keyPressed(app, SOY_F6)) {
    GAME_loadCamera(&world->camera, "camera.soy");
  }
  if(SOY_keyPressed(app, SOY_F7)) {
    world->debugControls = !world->debugControls;
  }
  if(SOY_keyPressed(app, SOY_F8)) {
    world->debugRender = !world->debugRender;
  }
  if(SOY_keyPressed(app, SOY_SPACE)) {
    if(g_jumpForce <= 0.0f) {
      g_jumpForce = 1.0f;
    }
  }

  if(g_jumpForce > 0.0f) {
    g_jumpForce -= 0.01f;
  } else {
    g_jumpForce = 0.0f;
  }
  upForce = g_jumpForce;
  SOY_setMouseCapture(app, TRUE);
  

  controller = &world->camera.transform;
  
  GAME_transformUpdate(world, controller,
      force, sideForce, upForce, mdx, mdy, world->debugControls, dt);
  
  if(world->debugControls) {
  } else {
    GAME_transformApplyGravity(controller, 60.0f, dt);
    GAME_transformClip(world, controller, 2.0f, dt);
  }

  if(SOY_mouseScroll(app)) {
    if(SOY_mouseScroll(app) > 0) {
      world->camera.reticleSize += 0.5f;
    } else {
      world->camera.reticleSize -= 0.5f;
    }
    if(world->camera.reticleSize < 1.0f) {
      world->camera.reticleSize = 1.0f;
    }
  }
  world->worldTime += dt;
  return TRUE;
}

int32 GAME_worldRenderCurrentTile(gameWorld* world, gameChunk* chunk,
    mat4f model, mat4f view, mat4f projection) {
  int32 hx = world->camera.transform.position.x + 0.5f;
  int32 hy = world->camera.transform.position.z + 0.5f;
  int32 bx = GAME_wrap((int32)hx, CHUNK_WIDTH);
  int32 by = GAME_wrap((int32)hy, CHUNK_WIDTH);
  model = SOY_mat4f(1.0f);
  view = GAME_viewMatrix(
    SOY_vec3f(0.0f, 2.0f, -2.0f),
    SOY_vec3f(SOY_PI/4, 0.0f, 0.0f)
  );
  SOY_mat4fTranslate(&model,
      -bx, -0.5f - chunk->tiles[bx + by*CHUNK_WIDTH].height / 8.0f, -by);
  model = 
    SOY_mat4fMultiply(model,
      SOY_mat4fRotationY(world->worldTime*0.1f));
  SOY_mat4fTranslate(&projection, -0.6f, 0.0f, 0.0f);
  SOY_glSetUniformInt(&world->tileShader, "debugCol", 3);
  SOY_useShader(&world->tileShader);
  SOY_glDisable(GL_CULL_FACE);
  SOY_glDisable(GL_DEPTH_TEST);
  SOY_setMVP(&world->tileShader, &model, &view, &projection);
  SOY_glBindVertexArray(chunk->model.vao);
  SOY_glDrawArrays(GL_TRIANGLES, (bx + by*CHUNK_WIDTH)*6, 6);         
  SOY_mat4fTranslate(&model, 0.0f, 0.01f, 0.0f);
  SOY_glSetUniformInt(&world->tileShader, "debugCol", 1);
  SOY_setMVP(&world->tileShader, &model, &view, &projection);
  SOY_glBindVertexArray(chunk->model.vao);
  SOY_glDrawArrays(GL_LINE_STRIP, (bx + by*CHUNK_WIDTH)*6, 6);         
  SOY_glEnable(GL_CULL_FACE);
  SOY_glEnable(GL_DEPTH_TEST);
  return TRUE;
}

int32 GAME_worldRender(soyApp* app, gameWorld* world, real32 dt) {
#if 0
  GLenum err;
#endif
  int32 i;
  mat4f view;
  real32 tx, ty;
  real32 px, py;
  int32 cx, cy;
  gameChunk* chunk;
  real32 w = (real32)SOY_width(app);
  real32 h = (real32)SOY_height(app);
  mat4f model = SOY_mat4f(1.0f);
  mat4f projection = SOY_mat4fProjection(0.1f, 2000.0f, 90.0f, h/w);
  uint32 renderModes[4] = {
    GL_TRIANGLES,
    GL_LINES,
    GL_POINTS,
    GL_TRIANGLES
  };

  uint32 renderMode = renderModes[world->renderMode];
  
  view = GAME_transformViewMatrix(&world->camera.transform);

  SOY_UNUSED(dt);

  /* hardware rendering */
  SOY_glClearColour(0.1f, 0.5f, 0.8f, 1.0f);
  SOY_glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
  
  SOY_useShader(&world->tileShader);
  SOY_glEnable(GL_CULL_FACE);
  SOY_glEnable(GL_DEPTH_TEST);
  SOY_glDisable(GL_BLEND);
  SOY_glSetUniformFloat(&world->tileShader, "worldTime", world->worldTime);
  SOY_glSetUniformInt(&world->tileShader, "debugRender", world->debugRender);
  SOY_glSetUniformFloat(&world->tileShader, "waterLevel", 4096.0f *0.5f);
  SOY_glSetUniformInt(&world->tileShader, "debugCol", 0);
  SOY_glSetUniformInt(&world->tileShader, "pointX", world->pointX);
  SOY_glSetUniformInt(&world->tileShader, "pointY", world->pointY);
  SOY_glSetUniformInt(&world->tileShader, "divisions", world->divisions);
  SOY_glSetUniformFloat(&world->tileShader, "playerX",
      world->camera.transform.position.x + 0.5f);
  SOY_glSetUniformFloat(&world->tileShader, "playerY",
      world->camera.transform.position.z + 0.5f);
#if 0
  while((err = glGetError()) != GL_NO_ERROR) {
    SOY_LOG1("ERROR: %d\n", err);
  }
#endif
  for(i = 0; i < MAP_WIDTH*MAP_WIDTH; i++) {
    chunk = &world->chunks[i];
    tx = ((real32)chunk->x*CHUNK_SCALE);
    ty = ((real32)chunk->y*CHUNK_SCALE);
    model = SOY_mat4f(1.0f);
    SOY_mat4fTranslate(&model, tx, 0.0f, ty);
    SOY_setMVP(&world->tileShader, &model, &view, &projection);
    SOY_glBindVertexArray(chunk->model.vao);
    SOY_glSetUniformInt(&world->tileShader, "debugCol", 0);
#if 1
    SOY_glDrawArrays(renderMode, 0, chunk->model.numVertices);
#endif
    if(world->renderMode == 3) {
      SOY_glSetUniformInt(&world->tileShader, "debugCol", 2);
      model = SOY_mat4f(1.0f);
      SOY_mat4fTranslate(&model, tx, 0.001f, ty);
      SOY_setMVP(&world->tileShader, &model, &view, &projection);
      SOY_glDrawArrays(GL_LINES, 0, chunk->model.numVertices);
#if 0
      while((err = glGetError()) != GL_NO_ERROR) {
        SOY_LOG1("ERROR: %d\n", err);
      }
#endif
    }
  }

#if 1
  SOY_useShader(&world->waterShader);
  SOY_glEnable(GL_CULL_FACE);
  if(world->camera.transform.position.y < 512.0f * 0.5f + 0.5f) {
    SOY_glCullFace(GL_FRONT);
  } else {
    SOY_glCullFace(GL_BACK);
  }
  
  SOY_glEnable(GL_DEPTH_TEST);
  SOY_glEnable(GL_BLEND);
  SOY_glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  SOY_glSetUniformFloat(&world->waterShader, "worldTime", world->worldTime);
  SOY_glSetUniformFloat(&world->waterShader, "waterLevel", 4096.0f *0.5f);
  SOY_glSetUniformInt(&world->waterShader, "debugRender", world->debugRender);
  SOY_glSetUniformInt(&world->waterShader, "debugCol", 0);
  SOY_glSetUniformInt(&world->waterShader, "pointX", world->pointX);
  SOY_glSetUniformInt(&world->waterShader, "pointY", world->pointY);
  SOY_glSetUniformInt(&world->waterShader, "divisions", world->divisions);
  
  for(i = 0; i < MAP_WIDTH*MAP_WIDTH; i++) {
    chunk = &world->water[i];
    tx = ((real32)chunk->x*CHUNK_SCALE);
    ty = ((real32)chunk->y*CHUNK_SCALE);
    model = SOY_mat4f(1.0f);
    SOY_mat4fTranslate(&model, tx, 0.0f, ty);
    SOY_setMVP(&world->waterShader, &model, &view, &projection);
    SOY_glBindVertexArray(chunk->model.vao);
    SOY_glDrawArrays(renderMode, 0, chunk->model.numVertices);
  }
  SOY_glCullFace(GL_BACK);
#endif
#if 1
  px = world->camera.transform.position.x;
  py = world->camera.transform.position.z;
  cx = ((int32)(px + 0.5f)) / CHUNK_WIDTH;
  cy = ((int32)(py + 0.5f)) / CHUNK_WIDTH;
    
  chunk = 
    GAME_getChunkPtr(world->chunks,
        GAME_wrap(cx, MAP_WIDTH), GAME_wrap(cy, MAP_WIDTH));
  
  GAME_worldRenderCurrentTile(world, chunk, model, view, projection);
#endif
  if(world->debugControls) {
    GAME_rayCast(app, &world->camera.transform, world,
        CHUNK_WIDTH*MAP_WIDTH, GAME_rayCastRenderProc);
  } else {
    GAME_rayCast(app, &world->player.transform, world,
        CHUNK_WIDTH*MAP_WIDTH, GAME_rayCastRenderProc);
  }
  GAME_updateGUITexture(app->framebuffer, app->fontRegular,
    world, SOY_width(app), SOY_height(app));
  GAME_renderGUITexture(world);
  SOY_glSwapBuffers(SOY_getDeviceContext(app->windowHandle));
  return TRUE;
}

/* library callbacks *******************************************************/

int32 SOY_userRender(soyApp* app, real64 dt) {
  GAME_worldRender(app, &g_world, (real32)dt);
  return TRUE;
}

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  GAME_worldUpdate(app, &g_world, (real32)dt);
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  SOY_LOG1("sizeof chunk: %f\n", (real32)sizeof(gameChunk)/1024.0f/1024.0f);
  GAME_worldInit(app, &g_world);
  
  return TRUE;
}

int32 SOY_userStop(soyApp* app) {
  SOY_UNUSED(app);
  return TRUE;
}

int32 main() {
  soyApp app;
  SOY_create(&app, "soyCraft v0.0.1", 1080, 720);
  return TRUE;
}
