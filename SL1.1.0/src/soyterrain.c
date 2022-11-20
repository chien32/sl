#define SOY_DEBUG
#define SOY_HARDWARE_ENABLE
#include "soy.h"

/* TODO: was doing rigid body physics and mesh creation */

/* @soylib callbacks *******************************************************/

#define CHUNK_WIDTH 64
#define CHUNK_SCALE 64.0f
#define MAX_HEIGHT 4096.0f
#define BLOCK_DIVISOR 8.0f
#define CHUNK_SIZE CHUNK_WIDTH*CHUNK_WIDTH
#define CHUNK_VERTEX_SIZE CHUNK_SIZE*6*2
#define MAP_WIDTH 1

#define MAX_MODELS 16

#define VERTEX_X1 0
#define VERTEX_X2 CHUNK_WIDTH - 1
#define VERTEX_Y1 CHUNK_SIZE - CHUNK_WIDTH - 1
#define VERTEX_Y2 CHUNK_SIZE - 1

#define GAME_EPSILON 0.000001f

#define TILE_DIRTY 0x8000

typedef struct tag_gameMesh gameMesh;

typedef struct tag_gameTransform {
  vec3f position;
  vec3f direction;
  vec3f lookAt;
} gameTransform;

struct tag_gameMesh {
  uint32* vertices;
  size_t maxVertices;
  size_t numVertices;
  SOY_VAO vao;
  SOY_VBO vbo;
  real32 scale;
};

typedef struct tag_gameModel {
  gameMesh mesh;
  gameTransform transform;
} gameModel;

typedef struct tag_gameTile {
  uint16 height;
  uint16 flags;
  uint32 normalA;
  uint32 normalB;
} gameTile;

typedef struct tag_gameChunk gameChunk;

struct tag_gameChunk {
  gameTile* tiles;
  int32 x;
  int32 y;
  int32 min;
  int32 max;
  uint32 maxTiles;
  uint32 roughness;
  uint32 upNormal;
  gameMesh mesh;
  gameChunk* neighbours[8];
};

typedef struct tag_gameCamera {
  gameTransform transform;
  mat4f projection;
  real32 reticleSize;
} gameCamera;

typedef struct tag_gamePlayer {
  gameTransform transform;
} gamePlayer;

typedef struct tag_gameWorld {
  gameModel models[MAX_MODELS];
  gameChunk chunk[MAP_WIDTH*MAP_WIDTH];
  gameChunk water[MAP_WIDTH*MAP_WIDTH];
  gamePlayer player;
  real32 oceanLevel;
  int32 numModels;
  vec3f worldScale;
  int32 pointX;
  int32 pointY;
  int32 framesPerSecond;
  int32 frameCounter;
  real32 secondTimer;
  real32 worldTime;
  gameCamera camera;
  soyGLTexture framebufferTexture;
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
  int32 lockMouse;
  soyMemorySector memory;
  soyMemorySector tileMemory;
  soyMemorySector meshMemory;
} gameWorld;

SOY_GLOBAL gameWorld g_world;

/* @math *******************************************************************/

int32 GAME_mat4fTranslate(mat4f* m, vec3f t) {
  return SOY_mat4fTranslate(m, t.x, t.y, t.z);
}

real32 GAME_getEditGradient(real32 x, real32 y) {
  return sqrt(SOY_MIN(SOY_MAX(1.0f - x*x - y*y, 0.0f), 1.0f));
}

real32 GAME_heightGenerate(real32 x, real32 y) {
  real32 rh;
  rh = SOY_noiseDomainWarp2D(SOY_noiseSimplex2D,
      x*0.0002f*CHUNK_SCALE, y*0.0002f*CHUNK_SCALE,
      0.2f, 0.3f, 0.5f,
      1.0f, 0.5f, 12, 6);
  rh = SOY_noiseSimplexNormalize(rh);
  rh = SOY_MIN(SOY_MAX(rh, 0.0f), 1.0f);
  return 0.01f;
  return rh;
}

gameTile* GAME_getTilePtr(gameChunk* chunk, int32 x, int32 y) {
  int32 cw = CHUNK_WIDTH - 1;
  int32 cf = CHUNK_WIDTH;
  if(!chunk) { return NULL; }
  if(x < 0  || y < 0 || x >= CHUNK_WIDTH || y >= CHUNK_WIDTH) {
    if(x <  0) { return GAME_getTilePtr(chunk->neighbours[0], cf + x, y); }
    if(x > cw) { return GAME_getTilePtr(chunk->neighbours[1], x - cf, y); }
    if(y <  0) { return GAME_getTilePtr(chunk->neighbours[2], x, cf + y); }
    if(y > cw) { return GAME_getTilePtr(chunk->neighbours[3], x, y - cf); }
    return GAME_getTilePtr(chunk, x, y);
  } else {
    return &chunk->tiles[x + y*CHUNK_WIDTH];
  }
}

gameTile GAME_getTileValue(gameChunk* chunk, int32 x, int32 y) {
  gameTile ret;
  gameTile* tile = GAME_getTilePtr(chunk, x, y);
  ret.flags = 0;
  ret.height = 0;
  if(tile) {
    ret = *tile;
  }
  return ret;
}

/* @mesh *******************************************************************/

int32 GAME_meshPushVertex(gameMesh* mesh, int32 x, int32 y, int32 z) {
  uint32 pack;
  if(mesh->numVertices < mesh->maxVertices) {
    pack = x | (z << 8) | (y << 16);
    mesh->vertices[mesh->numVertices] = pack;
    mesh->vertices[mesh->numVertices + 1] = 0;
    mesh->numVertices += 2;
  }
  return TRUE;
}

int32 GAME_meshSetScale(gameMesh* mesh, real32 s) {
  mesh->scale = s;
  return TRUE;
}

gameMesh GAME_mesh(uint32* memory, size_t maxMemory) {
  gameMesh mesh;
  mesh.vertices = memory;
  mesh.maxVertices = maxMemory / (sizeof(uint32)*2);
  mesh.scale = 1.0f;
  mesh.numVertices = 0;
  SOY_glGenVertexArrays(1, &mesh.vao);
  SOY_glGenBuffers(1, &mesh.vbo);
  SOY_glBindVertexArray(mesh.vao);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
  SOY_glVertexAttribEnable(0);
  SOY_glVertexAttribIPointer(0, 2, GL_UNSIGNED_INT, 0, 0);
  return mesh;
}

/* @model ******************************************************************/

gameModel GAME_model(gameMesh mesh, gameTransform transform) {
  gameModel ret;
  ret.mesh = mesh;
  ret.transform = transform;
  return ret;
}

int32 GAME_modelRender(gameModel* model,
    soyShader* shader, mat4f* view, mat4f* projection) {
  mat4f mat = SOY_mat4f(1.0f);
  GAME_mat4fTranslate(&mat, model->transform.position);
  SOY_setMVP(shader, &mat, view, projection);
  SOY_glBindVertexArray(model->mesh.vao);
  SOY_glDrawArrays(GL_TRIANGLES, 0, model->mesh.numVertices); 
  return TRUE;
}

/* @chunk ******************************************************************/

uint32 GAME_getType(gameChunk* chunk, int32 x, int32 y) {
  int32 cw = CHUNK_WIDTH;
  real32 v = (real32)chunk->tiles[x + y*cw].height / MAX_HEIGHT;
  real32 d = v*v*v*v*4.0f;
  return (uint32)(SOY_clamp(d, 0.0f, 1.0f)*255.0f);
}

vec3f GAME_getQuadNormal(real32* verts,
    real32 rx, real32 ry, int32 invert, int32 side) {
  vec3f tri[3];
  vec3f u, v, normal;
  if(side == 0) {
    if(invert) {
      tri[0] = SOY_vec3f(rx, verts[0], ry);
      tri[1] = SOY_vec3f(rx, verts[2], ry + 1.0f);
      tri[2] = SOY_vec3f(rx + 1.0f, verts[1], ry);
    } else {
      tri[0] = SOY_vec3f(rx, verts[0], ry);
      tri[1] = SOY_vec3f(rx + 1.0f, verts[2], ry);
      tri[2] = SOY_vec3f(rx, verts[1], ry + 1.0f);
    }
  } else if(side == 1) {
    if(invert) {
      tri[0] = SOY_vec3f(rx + 1.0f, verts[1], ry);
      tri[1] = SOY_vec3f(rx, verts[2], ry + 1.0f);
      tri[2] = SOY_vec3f(rx + 1.0f, verts[3], ry + 1.0f);
    } else {
      tri[0] = SOY_vec3f(rx, verts[1], ry);
      tri[1] = SOY_vec3f(rx + 1.0f, verts[2], ry + 1.0f);
      tri[2] = SOY_vec3f(rx + 1.0f, verts[3], ry);
    }
  } else {
    SOY_memorySet(tri, 0, 3*sizeof(vec3f));
  }
  u = v3Sub(tri[1], tri[0]);
  v = v3Sub(tri[2], tri[0]);
  normal.x = (u.y * v.z) - (u.z * v.y);
  normal.y = (u.z * v.x) - (u.x * v.z);
  normal.z = (u.x * v.y) - (u.y * v.x);
  return v3Norm(normal);
}

vec3f GAME_getTriangleNormal(
    uint32 x1, uint32 y1, uint32 z1,
    uint32 x2, uint32 y2, uint32 z2,
    uint32 x3, uint32 y3, uint32 z3,
    real32 vScale) {
  vec3f tri[3];
  vec3f u, v, normal;
  tri[0] = SOY_vec3f((real32)x1, (real32)y1 / vScale, (real32)z1);
  tri[1] = SOY_vec3f((real32)x2, (real32)y2 / vScale, (real32)z2);
  tri[2] = SOY_vec3f((real32)x3, (real32)y3 / vScale, (real32)z3);
  u = v3Sub(tri[1], tri[0]);
  v = v3Sub(tri[2], tri[0]);
  normal.x = (u.y * v.z) - (u.z * v.y);
  normal.y = (u.z * v.x) - (u.x * v.z);
  normal.z = (u.x * v.y) - (u.y * v.x);
  return v3Norm(normal);
}

uint32 GAME_packNormal(vec3f normal) {
  uint32 nx = (uint32)(normal.x*127.0f + 128.0f);
  uint32 ny = (uint32)(normal.y*127.0f + 128.0f);
  uint32 nz = (uint32)(normal.z*127.0f + 128.0f);
  return (nx & 0xFF) | ((ny & 0xFF) << 8) | ((nz & 0xFF) << 16);
}

int32 GAME_orientQuad(uint32 a, uint32 b, uint32 c, uint32 d) {
  return abs(((int32)b - (int32)c)) >= abs(((int32)a - (int32)d));
}

int32 GAME_orientQuadF(real32 a, real32 b, real32 c, real32 d) {
  return fabs(b - c) >= fabs(a - d);
}

gameChunk* GAME_getChunkPtr(gameChunk* chunks,
    int32 x, int32 y) {
  if(!chunks) { return NULL; }
  if(x < 0  || y < 0 || x >= MAP_WIDTH || y >= MAP_WIDTH) { return 0; }
  return &chunks[x + y*MAP_WIDTH];
}

int32 GAME_chunkInit(gameChunk* chunk,
    gameTile* tileMemory, uint32 tileMemorySize) {
  real32 scaled[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
  SOY_glGenVertexArrays(1, &chunk->mesh.vao);
  SOY_glGenBuffers(1, &chunk->mesh.vbo);
  SOY_glBindVertexArray(chunk->mesh.vao);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, chunk->mesh.vbo);
  SOY_glVertexAttribEnable(0);
  SOY_glVertexAttribIPointer(0, 2, GL_UNSIGNED_INT, 0, 0);
  chunk->mesh.numVertices = CHUNK_SIZE*6*2;
  chunk->mesh.vertices = NULL;
  chunk->tiles = tileMemory;
  chunk->maxTiles = tileMemorySize / sizeof(gameTile);
  chunk->min = 99999;
  chunk->max = 0;
  chunk->x = 0;
  chunk->y = 0;
  chunk->upNormal = 
    GAME_packNormal(GAME_getQuadNormal(scaled, 0.0f, 0.0f, 0, 0));
  return TRUE;
}

int32 GAME_chunkGenerate(gameWorld* world, gameChunk* chunk,
    int32 worldX, int32 worldY, int32 isWater) {
  int32 x, y;
  int32 prevHeight;
  real32 rx, ry;
  real32 height;
  real32 noise;
  gameTile* tile;
  int32 cx = SOY_wrap(worldX, MAP_WIDTH);
  int32 cy = SOY_wrap(worldY, MAP_WIDTH);
  int32 waterLevel = world->oceanLevel;
  gameChunk* chunks = isWater ? world->water : world->chunk;
  chunk->x = worldX;
  chunk->y = worldY;
  chunk->neighbours[0] = GAME_getChunkPtr(chunks, cx - 1, cy);
  chunk->neighbours[1] = GAME_getChunkPtr(chunks, cx + 1, cy);
  chunk->neighbours[2] = GAME_getChunkPtr(chunks, cx, cy - 1);
  chunk->neighbours[3] = GAME_getChunkPtr(chunks, cx, cy + 1);
  chunk->neighbours[4] = GAME_getChunkPtr(chunks, cx - 1, cy - 1);
  chunk->neighbours[5] = GAME_getChunkPtr(chunks, cx - 1, cy + 1);
  chunk->neighbours[6] = GAME_getChunkPtr(chunks, cx + 1, cy - 1);
  chunk->neighbours[7] = GAME_getChunkPtr(chunks, cx + 1, cy + 1);
  chunk->roughness = 0;
  prevHeight = 0;
  for(y = 0; y < CHUNK_WIDTH; y++) {
    for(x = 0; x < CHUNK_WIDTH; x++) {
      tile = &chunk->tiles[x + y*CHUNK_WIDTH];
      if(!isWater) {
        rx = (real32)((real32)x + 0.5f + worldX*CHUNK_SCALE) / CHUNK_SCALE;
        ry = (real32)((real32)y + 0.5f + worldY*CHUNK_SCALE) / CHUNK_SCALE;
        noise = GAME_heightGenerate(rx, ry);
        height = SOY_MIN(SOY_MAX(noise*MAX_HEIGHT, 0.0f), 4095.0f);
      } else {
        height = (real32)waterLevel;
      }
      tile->height = ((uint16)height);
      tile->flags = TILE_DIRTY;
      if(tile->height != prevHeight) {
        chunk->roughness++;
      }
      prevHeight = (int32)tile->height;
    }
  }
  return TRUE;
}

SOY_GLOBAL uint32 g_vertOrder[6][2] = {
  { 0, 0 },
  { 1, 0 },
  { 0, 1 },
  { 1, 1 }
};

uint32 GAME_pack(int32 x, int32 y, int32 order) {
  return 
    (((x + g_vertOrder[order][0]) & 0xFF) << 0) | 
    (((y + g_vertOrder[order][1]) & 0xFF) << 8);
}

int32 GAME_chunkGenerateMesh(gameChunk* chunk, uint32* buffer) {
  real32 rx, ry;
  int32 x, y;
  int32 idTile;
  int32 idBuffer;
  uint32 invert;
  uint32 packX, packY, pack, packedType, packedNormal;
  uint32 tile[4];
  uint32 verts[4];
  int32 obX, obY;
  gameTile* curTile;
  uint32 orderA[6] = { 0, 1, 2, 3, 4, 5 };
  uint32 orderB[6] = { 0, 1, 2, 3, 4, 5 };
  uint32 kernelA[4] = { 0, 1, 2, 3 };
  uint32 kernelB[4] = { 1, 3, 0, 2 };
  uint32* kern = kernelA;
  uint32* order = orderA;
  real32 vScale = 8.0f;
  if(!chunk) { SOY_LOG("Fatal error. NULL chunk\n"); return FALSE; }
  for(y = 0; y < CHUNK_WIDTH; y++) {
    for(x = 0; x < CHUNK_WIDTH; x++) {
      idTile = x + y*CHUNK_WIDTH;
      idBuffer = idTile*6*2;
      curTile = &chunk->tiles[idTile];
      chunk->min = SOY_MIN(chunk->min, curTile->height);
      chunk->max = SOY_MAX(chunk->max, curTile->height);
      rx = (real32)x;
      ry = (real32)y;
      packX = (x & 0xFF) << 0;
      packY = (y & 0xFF) << 8;
      pack = packX | packY;
      packedType = GAME_getType(chunk, x, y) << 24;
      obX = !(x == CHUNK_WIDTH - 1 && chunk->x == MAP_WIDTH - 1);
      obY = !(y == CHUNK_WIDTH - 1 && chunk->y == MAP_WIDTH - 1);
      tile[0] = GAME_getTileValue(chunk, x, y).height;
      tile[1] = GAME_getTileValue(chunk, x + obX, y).height;
      tile[2] = GAME_getTileValue(chunk, x, y + obY).height;
      tile[3] = GAME_getTileValue(chunk, x + obX, y + obY).height;
      if(1) {
        if(GAME_orientQuad(tile[0], tile[1], tile[2], tile[3])) {
          order = orderB;
          kern = kernelB;
          invert = TRUE;
        } else {
          order = orderA;
          kern = kernelA;
          invert = FALSE;
        }
        verts[0] = tile[kern[0]]; 
        verts[1] = tile[kern[1]]; 
        verts[2] = tile[kern[2]]; 
        verts[3] = tile[kern[3]]; 
        if(curTile->flags & TILE_DIRTY) {
          packedNormal = GAME_packNormal(
            GAME_getTriangleNormal(
              g_vertOrder[kern[0]][0], verts[0], g_vertOrder[kern[0]][1],
              g_vertOrder[kern[2]][0], verts[2], g_vertOrder[kern[2]][1],
              g_vertOrder[kern[1]][0], verts[1], g_vertOrder[kern[1]][1],
              vScale));
          curTile->normalA = packedNormal;
        } else {
          packedNormal = curTile->normalA;
        }
        buffer[idBuffer +  0] = (verts[0] << 16) | GAME_pack(x, y, kern[0]);
        buffer[idBuffer +  1] = (packedNormal | packedType);
        buffer[idBuffer +  2] = (verts[2] << 16) | GAME_pack(x, y, kern[2]);
        buffer[idBuffer +  3] = (packedNormal | packedType);
        buffer[idBuffer +  4] = (verts[1] << 16) | GAME_pack(x, y, kern[1]);
        buffer[idBuffer +  5] = (packedNormal | packedType);
        if(curTile->flags & TILE_DIRTY) {
          packedNormal = GAME_packNormal(
            GAME_getTriangleNormal(
              g_vertOrder[kern[1]][0], verts[1], g_vertOrder[kern[1]][1],
              g_vertOrder[kern[2]][0], verts[2], g_vertOrder[kern[2]][1],
              g_vertOrder[kern[3]][0], verts[3], g_vertOrder[kern[3]][1],
              vScale));
          curTile->normalB = packedNormal;
        } else {
          packedNormal = curTile->normalB;
        }
        buffer[idBuffer +  6] = (verts[1] << 16) | GAME_pack(x, y, kern[1]);
        buffer[idBuffer +  7] = (packedNormal | packedType);
        buffer[idBuffer +  8] = (verts[2] << 16) | GAME_pack(x, y, kern[2]);
        buffer[idBuffer +  9] = (packedNormal | packedType);
        buffer[idBuffer + 10] = (verts[3] << 16) | GAME_pack(x, y, kern[3]);
        buffer[idBuffer + 11] = (packedNormal | packedType);
        curTile->flags = curTile->flags & ~TILE_DIRTY;
      }
    }
  }
  return TRUE;
}

SOY_GLOBAL uint32 g_vertexBuffer[CHUNK_VERTEX_SIZE];

int32 GAME_updateBuffers(gameMesh* mesh, uint32* buffer) {
  SOY_glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
  SOY_glDynBufferData(GL_ARRAY_BUFFER,
      mesh->numVertices*sizeof(uint32), buffer);
  return TRUE;
}

int32 GAME_chunkUpdateBuffers(gameChunk* chunk, uint32* buffer) {
  GAME_updateBuffers(&chunk->mesh, buffer);
  return TRUE;
}


int32 GAME_chunkUpdateNeighbours(gameChunk* chunk) {
  int32 i;
  for(i = 0; i < 8; i++) {
    if(chunk->neighbours[i]) {
      GAME_chunkGenerateMesh(chunk->neighbours[i], g_vertexBuffer);
      GAME_chunkUpdateBuffers(chunk->neighbours[i], g_vertexBuffer);
    }
  }
  return TRUE;
}

/* @water chunk ************************************************************/

int32 GAME_chunkWaterUpdate(gameChunk* chunk) {
  int32 x, y;
  for(y = 0; y < CHUNK_WIDTH; y++) {
    for(x = 0; x < CHUNK_WIDTH; x++) {
    }
  }
  return TRUE;
}

/* @terrain edit ***********************************************************/

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
  for(x = -hrad; x < hrad + 2; x++) {
    for(y = -hrad; y < hrad + 2; y++) {
      tile = GAME_getTilePtr(chunk, ix + x, iy + y);
      if(tile) {
        if(x > -hrad && x < hrad + 1 && y > -hrad && y < hrad + 1) {
          rx = (real32)x / (real32)hrad;
          ry = (real32)y / (real32)hrad;
          factor = GAME_getEditGradient(rx, ry)*8.0f;
          if(factor < 0.0f) { factor = 0.0f; }
          if(factor >= 7.0f) { factor = 7.0f; }
          tempTile = (tile->height) & 0xFFFF0000;
          signHeight = (int32)((tile->height) & 0xFFF);
          signHeight += dir ? (int32)factor : -(int32)factor;
          tempTile |= (uint32)SOY_MIN(SOY_MAX(signHeight, 0), 4095);
          tile->height = tempTile;
        }
        tile->flags |= TILE_DIRTY;
      }
    }
  }
  return TRUE;
}

/* @terrain collision ******************************************************/

real32 GAME_tileHeightAt(gameWorld* world,
    gameChunk* chunk, real32 x, real32 y) {
  int32 invQuad;
  real32 d1, d2, d3;
  real32 height;
  real32 triangleA[3][3];
  real32 hx = x + 0.5f;
  real32 hy = y + 0.5f;
  real32 div = 8.0f;
  int32 bx = SOY_wrap((int32)hx, CHUNK_WIDTH);
  int32 by = SOY_wrap((int32)hy, CHUNK_WIDTH);
  real32 tx = ((real32)chunk->x) * CHUNK_SCALE;
  real32 ty = ((real32)chunk->y) * CHUNK_SCALE; 
  real32 fracX = x - (real32)SOY_FASTFLOOR(hx);
  real32 fracY = y - (real32)SOY_FASTFLOOR(hy);
  real32 t1 = (real32)GAME_getTileValue(chunk, bx, by).height / div;
  real32 t2 = (real32)GAME_getTileValue(chunk, bx + 1, by).height / div;
  real32 t3 = (real32)GAME_getTileValue(chunk, bx, by + 1).height / div;
  real32 t4 = (real32)GAME_getTileValue(chunk, bx + 1, by + 1).height / div;
  real32 fx = bx + tx - 0.5f;
  real32 fy = by + ty - 0.5f;
  invQuad = GAME_orientQuadF(t1, t2, t3, t4);
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

/* @transform **************************************************************/

vec3f GAME_lookAt(vec3f dir) {
  vec3f ret;
  ret.x = cos(dir.x) * sin(dir.y);
  ret.y = sin(-dir.x);
  ret.z = cos(dir.x) * cos(dir.y);
  return ret;
}

gameTransform GAME_transform(vec3f pos, vec3f dir) {
  gameTransform ret;
  ret.position = pos;
  ret.direction = dir;
  ret.lookAt = GAME_lookAt(ret.direction);
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
  real32 x = t->position.x;
  real32 y = t->position.z;
  real32 hx = x + 0.5f;
  real32 hy = y + 0.5f;
  int32 cx = SOY_wrap(((int32)hx) / CHUNK_WIDTH, MAP_WIDTH);
  int32 cy = SOY_wrap(((int32)hy) / CHUNK_WIDTH, MAP_WIDTH);
  gameChunk* c = GAME_getChunkPtr(world->chunk, cx, cy);
  GAME_transformClipToTerrain(
      t, GAME_tileHeightAt(world, c, x, y) + offset, dt);
  return TRUE;
}

/* @camera *****************************************************************/

int32 GAME_cameraInit(gameCamera* cam,
    real32 x, real32 y, real32 z,
    real32 zNear, real32 zFar, real32 fov, real32 aspect) {
  GAME_transformInit(&cam->transform, x, y, z);
  cam->projection = SOY_mat4fProjection(zNear, zFar, fov, aspect);
  cam->reticleSize = 4.0f;
  return TRUE;
}

/* @player *****************************************************************/

int32 GAME_playerInit(gamePlayer* p, real32 x, real32 y, real32 z) {
  GAME_transformInit(&p->transform, x, y, z);
  return TRUE;
}

/* @raycasting *************************************************************/

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


int32 GAME_intersectTriangle(vec3f ro, vec3f rd,
    vec3f vert0, vec3f vert1, vec3f vert2,
    real32* t, real32* u, real32* v) {

  vec3f edge1, edge2, tvec, pvec, qvec;
  real32 det, invdet;

  edge1 = v3Sub(vert1, vert0);
  edge2 = v3Sub(vert2, vert0);
  pvec = v3Cross(rd, edge2);
  det = v3Dot(edge1, pvec);

#ifdef GAME_TEST_CULL
  if(det < GAME_EPSILON) {
    return 0;
  }

  tvec = v3Sub(ro, vert0);
  *u = v3Dot(tvec, pvec);
  if(*u < 0.0f || *u > det) {
    return 0;
  }

  qvec = v3Cross(tvec, edge1);

  *v = v3Dot(rd, qvec);
  if(*v < 0.0f || *u + *v > det) {
    return 0;
  }

  *t = v3Dot(edge2, qvec);
  invdet = 1.0f / det;
  *t *= invdet;
  *u *= invdet;
  *v *= invdet;
#else
  if(det > -GAME_EPSILON && det < GAME_EPSILON) {
    return 0;
  }
  invdet = 1.0f / det;
  tvec = v3Sub(ro, vert0);
  *u = v3Dot(tvec, pvec) * invdet;
  if(*u < 0.0f || *u > 1.0f) {
    return 0;
  }

  qvec = v3Cross(tvec, edge1);
  *v = v3Dot(rd, qvec) * invdet;
  if(*v < 0.0f || *u + *v > 1.0f) {
    return 0;
  }
  *t = v3Dot(edge2, qvec) * invdet;
#endif
  return 1;
}

int32 GAME_getQuad(gameWorld* world, real32 x, real32 y,
    vec3f* a, vec3f* b, vec3f* c, vec3f* d) {
  real32 n = 8.0f;
  real32 rx = x - 0.5f;
  real32 ry = y - 0.5f;
  int32 ix = (int32)x;
  int32 iy = (int32)y;
  int32 cx = SOY_wrap(ix/CHUNK_WIDTH, MAP_WIDTH);
  int32 cy = SOY_wrap(iy/CHUNK_WIDTH, MAP_WIDTH);
  int32 bx = SOY_wrap(ix, CHUNK_WIDTH);
  int32 by = SOY_wrap(iy, CHUNK_WIDTH); 
  gameChunk* chunk = GAME_getChunkPtr(world->chunk, cx, cy);
  real32 vert1 = (real32)GAME_getTileValue(chunk, bx, by).height / n;
  real32 vert2 = (real32)GAME_getTileValue(chunk, bx + 1, by).height / n;
  real32 vert3 = (real32)GAME_getTileValue(chunk, bx, by + 1).height / n;
  real32 vert4 = (real32)GAME_getTileValue(chunk, bx + 1, by + 1).height / n;
  if(a) { *a = SOY_vec3f(rx, vert1 + 0.5f,  ry); }
  if(b) { *b = SOY_vec3f(rx + 1.0f, vert2 + 0.5f,  ry); }
  if(c) { *c = SOY_vec3f(rx, vert3 + 0.5f,  ry + 1.0f); }
  if(d) { *d = SOY_vec3f(rx + 1.0f, vert4 + 0.5f,  ry + 1.0f); }
  return GAME_orientQuadF(vert1, vert2, vert3, vert4);
}

int32 GAME_checkQuadIntersection(gameWorld* world,
    int32 x, int32 y, int32 z, real32* u, real32* v, real32* t) {
  int32 ret1, ret2;
  vec3f a, b, c, d;
  vec3f ro = world->camera.transform.position;
  vec3f rd = world->camera.transform.lookAt;
  int32 invert = GAME_getQuad(world, (real32)x, (real32)z, &a, &b, &c, &d);
  
  if(!invert) {
    ret1 = GAME_intersectTriangle(ro, rd, a, c, b, u, v, t);
    ret2 = GAME_intersectTriangle(ro, rd, b, c, d, u, v, t);
  } else {
    ret1 = GAME_intersectTriangle(ro, rd, a, c, d, u, v, t);
    ret2 = GAME_intersectTriangle(ro, rd, a, d, b, u, v, t);
  }
  return ret1 || ret2;
}

int32 GAME_rayCastRenderProc(soyApp* app, gameWorld* world,
    int32 x, int32 y, int32 z, vec3f face) {
  int32 cx, cy;
  int32 bx, by;
  gameChunk* chunk;
  real32 u, v, t;
  int32 rebuild = FALSE;
  real32 delta = 
    (real32)SOY_wallClockDelta(world->editClock, SOY_wallClock()) * 1000.0f;
  world->editClock = SOY_wallClock();
  SOY_UNUSED(face);
  SOY_glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  cx = SOY_wrap(x/CHUNK_WIDTH, MAP_WIDTH);
  cy = SOY_wrap(z/CHUNK_WIDTH, MAP_WIDTH);
  bx = SOY_wrap(x, CHUNK_WIDTH);
  by = SOY_wrap(z, CHUNK_WIDTH);
  chunk = GAME_getChunkPtr(world->chunk, cx, cy);
  if(GAME_checkQuadIntersection(world, x, y, z, &u, &v, &t)) {
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
    world->pointX = x;
    world->pointY = z;
    if(rebuild) {
      GAME_chunkGenerateMesh(chunk, g_vertexBuffer);
      GAME_chunkUpdateBuffers(chunk, g_vertexBuffer);
      GAME_chunkUpdateNeighbours(chunk);
    }
    return TRUE;
  }
  return FALSE;
}

/* @files ******************************************************************/

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

/* @gui ********************************************************************/

int32 GAME_drawToolbar(soyCanvas* canvas, soyFont* font,
    gameWorld* world, int32 width, int32 height) {
  int32 x, y;
  int32 xPos = 24;
  int32 yPos = 24 + 64 + 4;
  int32 w = 10;
  SOY_drawSetColour(canvas, 0x22222222);
  SOY_drawRectFill(canvas, xPos, yPos, xPos + 128, yPos + 256);

  SOY_drawSetColour(canvas, 0xFF666666);
  for(y = 0; y < MAP_WIDTH; y++) {
    for(x = 0; x < MAP_WIDTH; x++) {
      SOY_drawRect(canvas,
          xPos + 8 + x*w,
          yPos + 8 + y*w,
          xPos + 8 + x*w + w,
          yPos + 8 + y*w + w, 1);
    }
  }
  return TRUE;
}

int32 GAME_updateGUITexture(soyCanvas* canvas, soyFont* font,
    gameWorld* gw, int32 w, int32 h) {
  SOY_UNUSED(font);
  if(gw->guiUpdateFrame > 10) {
    SOY_drawSetColour(canvas, 0xFF000000);
    SOY_drawClear(canvas);
    SOY_drawSetColour(canvas, 0x22222222);
    SOY_drawRectFill(canvas, 24, 24, w - 24, 24 + 64);
    SOY_drawSetColour(canvas, 0xFFFFFFFF);
    SOY_drawTextFormat(canvas, font, 32, 32,
      "X: %f Y: %f Z: %f\nFPS: %d"
      ,
      gw->camera.transform.position.x,
      gw->camera.transform.position.y,
      gw->camera.transform.position.z,
      gw->framesPerSecond
      );
    SOY_drawCircle(canvas, w/2, h/2, 4.0f*gw->camera.reticleSize);
    GAME_drawToolbar(canvas, font, gw, w, h);
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

/* @world ******************************************************************/

int32 GAME_worldGraphicsInit(gameWorld* world) {
  SOY_createShader(&world->tileShader,
      "shaders/tile_vert.soy",
      "shaders/tile_land_frag.soy");
  SOY_createShader(&world->waterShader,
      "shaders/tile_vert.soy",
      "shaders/tile_water_frag.soy");
  SOY_createShader(&world->blockShader,
      "shaders/block_vert.soy",
      "shaders/block_frag.soy");
  SOY_createShader(&world->framebufferShader,
      "shaders/framebuffer_vert.soy",
      "shaders/framebuffer_frag.soy");
  SOY_glCullFace(GL_BACK);
  SOY_glEnable(GL_CULL_FACE);
  SOY_glEnable(GL_MULTISAMPLE);
  SOY_glEnable(GL_DEPTH_TEST);
  
  SOY_modelInitCube(&world->cubeModel);
  SOY_modelInitQuad(&world->quadModel);
  return TRUE;
}

int32 GAME_worldChunksInit(gameWorld* world) {
  int32 i;
  gameChunk* chunk;
  uint32 mapSize = MAP_WIDTH*MAP_WIDTH;
  uint32 tileMemSize = world->tileMemory.size;
  gameTile* tileMem = (gameTile*)world->tileMemory.base;
  
  SOY_ASSERT(mapSize*CHUNK_SIZE*sizeof(gameTile) <= tileMemSize);

  for(i = 0; i < mapSize; i++) {
    chunk = &world->chunk[i];
    GAME_chunkInit(chunk, tileMem, tileMemSize);
    GAME_chunkGenerate(world, chunk, i%MAP_WIDTH, i/MAP_WIDTH, FALSE);
    tileMem += CHUNK_SIZE;
  }

  for(i = 0; i < mapSize; i++) {
    chunk = &world->chunk[i];
    GAME_chunkGenerateMesh(chunk, g_vertexBuffer);
    GAME_chunkUpdateBuffers(chunk, g_vertexBuffer);
  }
  
  for(i = 0; i < mapSize; i++) {
    chunk = &world->water[i];
    GAME_chunkInit(chunk, tileMem, tileMemSize);
    GAME_chunkGenerate(world, chunk, i%MAP_WIDTH, i/MAP_WIDTH, TRUE);
    tileMem += CHUNK_SIZE;
  }

  for(i = 0; i < mapSize; i++) {
    chunk = &world->water[i];
    GAME_chunkGenerateMesh(chunk, g_vertexBuffer);
    GAME_chunkUpdateBuffers(chunk, g_vertexBuffer);
  }
  return TRUE;
}

int32 GAME_worldAddModel(gameWorld* world, gameModel model) {
  if(world->numModels < MAX_MODELS) {
    world->models[world->numModels++] = model;
    world->meshMemory.offset += sizeof(uint32)*model.mesh.numVertices;
    GAME_updateBuffers(&model.mesh, model.mesh.vertices);
  }
  return TRUE;
}

int32 GAME_worldModelsInit(gameWorld* world) {
  gameModel model;
  uint32* mem = (uint32*)(world->meshMemory.base + world->meshMemory.offset);
  uint32 maxMem = world->meshMemory.size - world->meshMemory.offset;
  vec3f pos = SOY_vec3f(0.0f, 0.0f, 0.0f);
  vec3f dir = SOY_vec3f(0.0f, 0.0f, 0.0f);
  


  model = GAME_model(GAME_mesh(mem, maxMem), GAME_transform(pos, dir));
  GAME_meshPushVertex(&model.mesh, 0, 0, 0);
  GAME_meshPushVertex(&model.mesh, 1, 0, 0);
  GAME_meshPushVertex(&model.mesh, 0, 1, 0);
  GAME_meshPushVertex(&model.mesh, 1, 0, 0);
  GAME_meshPushVertex(&model.mesh, 1, 1, 0);
  GAME_meshPushVertex(&model.mesh, 0, 1, 0);
  GAME_meshSetScale(&model.mesh, 1.0f);
  
  GAME_worldAddModel(world, model);
  return TRUE;
}

int32 GAME_worldInit(soyApp* app, gameWorld* world) {
  real32 w = (real32)SOY_width(app);
  real32 h = (real32)SOY_height(app);
  real32 a = h/w;
  uint32 mapSize = MAP_WIDTH*MAP_WIDTH;
  
  uint32 maxTileSize = CHUNK_SIZE*sizeof(gameTile)*mapSize*2;
  uint32 maxMemorySize = maxTileSize + Megabytes(32);
  world->numModels = 0;
  world->guiUpdateFrame = 0;
  world->worldTime = 0.0f;
  world->pointX = 0;
  world->pointY = 0;
  world->editClock = 0;
  world->editSpeed = 0.002f;
  world->editTimer = 0.0f;
  world->worldScale = SOY_vec3f(1.0f, 8.0f, 1.0f);
  world->debugControls = TRUE;
  world->oceanLevel = MAX_HEIGHT / 2.0f;
  world->lockMouse = TRUE;
  world->framesPerSecond = 0;
  world->frameCounter = 0;
  world->secondTimer = 0.0f;

  SOY_memorySectorCreate("GAME", &world->memory, maxMemorySize);
  SOY_memorySectorPartition("TILE",
      &world->memory, &world->tileMemory, maxTileSize);
  SOY_memorySectorPartition("MESH",
      &world->memory, &world->meshMemory, Megabytes(16));
  
  GAME_worldGraphicsInit(world);
  GAME_worldChunksInit(world);
  GAME_worldModelsInit(world);
  
  GAME_cameraInit(&world->camera, 0.0f, 1.0f, 0.0f, 0.1f, 2000.0f, 90.0f, a);
  GAME_playerInit(&world->player, 0.0f, 1.0f, 0.0f);
  return TRUE;
}

int32 GAME_worldUpdateChunks(gameWorld* world, real32 dt) {
  int32 x, y;
  for(y = 0; y < MAP_WIDTH; y++) {
    for(x = 0; x < MAP_WIDTH; x++) {
      GAME_chunkWaterUpdate(&world->water[x + y*MAP_WIDTH]);
      GAME_chunkGenerateMesh(&world->water[x + y*MAP_WIDTH], g_vertexBuffer);
      GAME_chunkUpdateBuffers(&world->water[x + y*MAP_WIDTH], g_vertexBuffer);
    }
  }
  return TRUE;
}

int32 GAME_worldUpdateNearChunks(gameWorld* world, real32 dt) {
  int32 x, y;
  gameChunk* chunkToUpdate;
  int32 size = 1;
  int32 px = world->camera.transform.position.x;
  int32 py = world->camera.transform.position.z;
  int32 cx = SOY_wrap(px / CHUNK_WIDTH, MAP_WIDTH);
  int32 cy = SOY_wrap(py / CHUNK_WIDTH, MAP_WIDTH);
  for(y = cy - size; y <= cy + size; y++) {
    for(x = cx - size; x <= cx + size; x++) {
      chunkToUpdate = GAME_getChunkPtr(world->water, x, y);
#if 0
      if(chunkToUpdate) {
        GAME_chunkWaterUpdate(chunkToUpdate);
        GAME_chunkGenerateMesh(chunkToUpdate, g_vertexBuffer);
        GAME_chunkUpdateBuffers(chunkToUpdate, g_vertexBuffer);   
      }
#endif
    }
  }
  return TRUE;
}

int32 GAME_worldUpdate(soyApp* app, gameWorld* world, real32 dt) {

  world->worldTime += dt;
  if(world->secondTimer >= 1.0f) {
    world->framesPerSecond = world->frameCounter;
    world->frameCounter = 0;
    world->secondTimer -= 1.0f;
  }
  world->secondTimer += dt;
  world->frameCounter++;
  
  GAME_worldUpdateNearChunks(world, dt);
  return TRUE;
}

int32 GAME_worldInputUpdate(soyApp* app, gameWorld* world, real32 dt) {
  real32 playerSpeed = dt*5.0f;
  real32 mdx = ((real32)SOY_mouseDeltaX(app));
  real32 mdy = ((real32)SOY_mouseDeltaY(app));
  real32 force = 0.0f;
  real32 sideForce = 0.0f;
  gameTransform* controller = &world->camera.transform;
  if(SOY_keyHeld(app, SOY_SHIFT)) { playerSpeed = dt*100.0f; }
  if(SOY_keyHeld(app, SOY_CONTROL)) { playerSpeed = dt*0.2f; }
  if(SOY_keyHeld(app, SOY_W)) { force = playerSpeed; }
  if(SOY_keyHeld(app, SOY_S)) { force = -playerSpeed; }
  if(SOY_keyHeld(app, SOY_A)) { sideForce = playerSpeed; }
  if(SOY_keyHeld(app, SOY_D)) { sideForce = -playerSpeed; }
  if(SOY_keyPressed(app, SOY_F1)) { world->lockMouse = !world->lockMouse; }
  if(SOY_keyPressed(app, SOY_F5)) {
    GAME_saveCamera(&world->camera, "camera.soy");
  }
  if(SOY_keyPressed(app, SOY_F6)) {
    GAME_loadCamera(&world->camera, "camera.soy");
  }
  if(SOY_keyPressed(app, SOY_F7)) {
    world->debugControls = !world->debugControls;
  }
  
  if(!world->lockMouse) {
    SOY_setMouseCapture(app, TRUE);
    GAME_transformUpdate(world, controller,
      force, sideForce, 0.0f, mdx, mdy, world->debugControls, dt);
  } else {
    SOY_setMouseCapture(app, FALSE);
    GAME_transformUpdate(world, controller,
      force, sideForce, 0.0f, 0.0f, 0.0f, world->debugControls, dt);
  }
  
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
  return TRUE;
}

real32 GAME_viewRad(real32 d) { return d*SOY_PI + CHUNK_SCALE; }

int32 GAME_pointInFrustum(
    vec3f ro, vec3f rd, real32 x, real32 y, real32 z) {
    vec3f point = SOY_vec3f((x), (y), (z));
    vec3f nPos = SOY_vec3f(ro.x - rd.x, ro.y - rd.y, ro.z - rd.z);
    vec3f nDir = SOY_vec3f(rd.x, rd.y, rd.z);
    vec3f obj = v3Sub(point, nPos);
    real32 dist = SOY_vec3fDot(obj, nDir);
    if(dist < 0.0f) return FALSE;
    return v3Len(v3Cross(obj, nDir)) <= GAME_viewRad(dist);
}

int32 GAME_worldRenderChunk(soyShader* shader, gameCamera* camera,
    gameChunk* chunk, mat4f view, mat4f projection) {
  real32 d = 8.0f;
  real32 cw = CHUNK_SCALE;
  vec3f roa = camera->transform.position;
  vec3f rda = camera->transform.lookAt;
  vec3f rd = SOY_vec3f(rda.x, rda.y, rda.z);
  vec3f ro = SOY_vec3f(roa.x, roa.y, roa.z);
  real32 tx = (real32)chunk->x;
  real32 ty = (real32)chunk->y;
  real32 x = tx*CHUNK_SCALE;
  real32 y = ty*CHUNK_SCALE;
  real32 px = x;
  real32 py = y;
  int32 v1 = (real32)chunk->tiles[VERTEX_X1].height / d; 
  int32 v2 = (real32)chunk->tiles[VERTEX_X2].height / d; 
  int32 v3 = (real32)chunk->tiles[VERTEX_Y1].height / d; 
  int32 v4 = (real32)chunk->tiles[VERTEX_Y2].height / d; 
  int32 ret1 = GAME_pointInFrustum(ro, rd, px, v1, py);
  int32 ret2 = GAME_pointInFrustum(ro, rd, px + cw, v2, py);
  int32 ret3 = GAME_pointInFrustum(ro, rd, px, v3, py + cw);
  int32 ret4 = GAME_pointInFrustum(ro, rd, px + cw, v4, py + cw);
  mat4f model = SOY_mat4f(1.0f);
  if(ret1 + ret2 + ret3 + ret4 == 0) { return FALSE; }
  SOY_mat4fTranslate(&model, x, 0.0f, y);
  SOY_setMVP(shader, &model, &view, &projection);
  SOY_glBindVertexArray(chunk->mesh.vao);
  SOY_glDrawArrays(GL_TRIANGLES, 0, chunk->mesh.numVertices); 
  return TRUE;
}

int32 GAME_worldSetUniforms(soyShader* shader, gameWorld* gw) {
  SOY_glSetUniformFloat(shader, "worldTime", gw->worldTime);
  SOY_glSetUniformFloat(shader, "waterLevel", gw->oceanLevel);
  SOY_glSetUniformFloat3(shader, "worldScale", 1, (real32*)&gw->worldScale);
  SOY_glSetUniformInt(shader, "pointX", gw->pointX);
  SOY_glSetUniformInt(shader, "pointY", gw->pointY);
  SOY_glSetUniformFloat(shader, "playerX",
      gw->camera.transform.position.x + 0.5f);
  SOY_glSetUniformFloat(shader, "playerY",
      gw->camera.transform.position.z + 0.5f);
  return TRUE;
}

int32 GAME_worldSetGraphicsLand(gameWorld* world) {
  SOY_glEnable(GL_CULL_FACE);
  SOY_glEnable(GL_DEPTH_TEST);
  SOY_glDisable(GL_BLEND);
  SOY_glCullFace(GL_BACK);
  SOY_UNUSED(world);
  return TRUE;
}

int32 GAME_worldSetGraphicsWater(gameWorld* world) {
  real32 mh = (real32)MAX_HEIGHT / (real32)world->worldScale.y;
  SOY_glEnable(GL_CULL_FACE);
  SOY_glEnable(GL_DEPTH_TEST);
  SOY_glEnable(GL_BLEND);
  SOY_glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  if(world->camera.transform.position.y < mh * 0.5f + 0.5f) {
    SOY_glCullFace(GL_FRONT);
  } else {
    SOY_glCullFace(GL_BACK);
  }
  return TRUE;
}

int32 GAME_worldSetGraphicsModel(gameWorld* world) {
  vec3f scale = SOY_vec3f(1.0f, 1.0f, 1.0f);
  SOY_glEnable(GL_CULL_FACE);
  SOY_glEnable(GL_DEPTH_TEST);
  SOY_glDisable(GL_BLEND);
  SOY_glCullFace(GL_BACK);
  SOY_glSetUniformFloat3(&world->tileShader,
      "worldScale", 1, (real32*)&scale);
  return TRUE;
}

int32 GAME_worldRenderModels(gameWorld* world, real32 dt) {
  int32 y;
  mat4f projection = world->camera.projection;
  mat4f view = GAME_transformViewMatrix(&world->camera.transform);
  for(y = 0; y < world->numModels; y++) {
    GAME_modelRender(&world->models[y],
        &world->tileShader, &view, &projection);  
  }
  return TRUE;
}

int32 GAME_worldRender(soyApp* app, gameWorld* gw, real32 dt) {
  int32 i;
  real32 px, py;
  int32 cx, cy;
  gameChunk* chunk;
  mat4f projection = gw->camera.projection;
  mat4f view = GAME_transformViewMatrix(&gw->camera.transform);
  SOY_glClearColour(0.1f, 0.5f, 0.8f, 1.0f);
  SOY_glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
#if 1
  /* render chunks */
  SOY_useShader(&gw->tileShader);
  GAME_worldSetGraphicsLand(gw);
  GAME_worldSetUniforms(&gw->tileShader, gw);
  for(i = 0; i < MAP_WIDTH*MAP_WIDTH; i++) {
    chunk = &gw->chunk[i];
    GAME_worldRenderChunk(
        &gw->tileShader, &gw->camera, chunk, view, projection);
  }
#endif
#if 0
  /* render water */
  SOY_useShader(&gw->waterShader);
  GAME_worldSetGraphicsWater(gw);
  GAME_worldSetUniforms(&gw->waterShader, gw);
  for(i = 0; i < MAP_WIDTH*MAP_WIDTH; i++) {
    chunk = &gw->water[i];
    GAME_worldRenderChunk(
        &gw->waterShader, &gw->camera, chunk, view, projection);
  }
#endif

  SOY_useShader(&gw->tileShader);
  GAME_worldSetGraphicsModel(gw);
  GAME_worldRenderModels(gw, dt);

#if 1
  /* raycast from camera */
  px = gw->camera.transform.position.x;
  py = gw->camera.transform.position.z;
  cx = ((int32)(px + 0.5f)) / CHUNK_WIDTH;
  cy = ((int32)(py + 0.5f)) / CHUNK_WIDTH;
  chunk = GAME_getChunkPtr(gw->chunk,
      SOY_wrap(cx, MAP_WIDTH), SOY_wrap(cy, MAP_WIDTH));
  GAME_rayCast(app, &gw->camera.transform, gw,
      CHUNK_WIDTH*MAP_WIDTH, GAME_rayCastRenderProc);
#endif


#if 1
  /* cpu framebuffer */
  GAME_updateGUITexture(app->framebuffer, app->fontRegular,
    gw, SOY_width(app), SOY_height(app));
#endif
  GAME_renderGUITexture(gw);
  
  

  /* finish frame */
  SOY_glSwapBuffers(SOY_getDeviceContext(app->windowHandle));
  return TRUE;
}

/* @library callbacks ******************************************************/

int32 SOY_userRender(soyApp* app, real64 dt) {
  GAME_worldRender(app, &g_world, (real32)dt);
  return TRUE;
}

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  GAME_worldInputUpdate(app, &g_world, (real32)dt);
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
  SOY_memorySectorFree(&g_world.memory);
  return TRUE;
}

int32 main() {
  soyApp app;
  SOY_create(&app, "soyCraft v0.0.1", 1080, 720);
  return TRUE;
}
