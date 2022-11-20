#define SOY_DEBUG
#define SOY_HARDWARE_ENABLE
#include "soy.h"
#include "libs/soy_terrain.h"

#define CHUNK_WIDTH 64
#define CHUNK_SCALE 64.0f
#define WORLD_WIDTH 64
#define WORLD_SCALE 64.0f
#define CHUNK_SIZE CHUNK_WIDTH*CHUNK_WIDTH
#define WORLD_SIZE WORLD_WIDTH*WORLD_WIDTH

typedef struct tag_gameModel {
  uint32 vao;
  uint32 vbo;
  size_t numVertices;
} gameModel;

typedef uint32 gameVertex;

typedef struct tag_gameCamera {
  soyTransform transform;
  real32 reticleSize;
  real32 fieldOfView;
  real32 nearPlane;
  real32 farPlane;
} gameCamera;

typedef struct tag_gameChunk {
  gameModel model;
  gameVertex vertexBuffer[CHUNK_SIZE*6*2];
} gameChunk;

typedef struct tag_gameWorld {
  landChunk land[WORLD_SIZE];
  gameChunk chunks[WORLD_SIZE];
  gameCamera* camera;
  
  soyShader chunkShader;
  soyShader waterShader;
  soyShader blockShader;
  soyShader guiShader;
  soyShader skyShader;

  real32 chunkScale;
  uint32 chunkSize;
  uint32 worldScale;
  uint32 worldSize;
} gameWorld;

typedef struct tag_gamePlayer {
  gameCamera camera;
  soyTransform transform;
  vec3f velocity;
  real32 accelaration;
  real32 gravity;
  real32 drag;
} gamePlayer;

#define MAP_WIDTH 64
#define CHUNK_WIDTH 64

#define MAP_SIZE MAP_WIDTH*MAP_WIDTH
#define CHUNK_SIZE CHUNK_WIDTH*CHUNK_WIDTH

SOY_GLOBAL gameWorld g_world;
SOY_GLOBAL landTile g_tileMemory[MAP_SIZE*CHUNK_SIZE];

int32 GAME_pushVertex(landVertexInfo* info) {
  gameChunk* chunk = (gameChunk*)info->args; 
  uint32 data = 0;
  chunk->vertexBuffer[chunk->model.numVertices++] = data;
  return TRUE;
}

int32 GAME_worldInit(gameWorld* world, int32 chunkSize, int32 mapSize) {
  int32 i;
  landChunk* land;
  gameChunk* chunk;
  world->chunkSize = chunkSize;
  world->chunkScale = (real32)chunkSize;
  world->worldSize = mapSize;
  world->worldScale = (real32)mapSize;

  for(i = 0; i < world->worldSize*world->worldSize; i++ ) {
    land = &world->land[i];
    chunk = &world->chunks[i];
    LAND_chunkInit(land, &g_tileMemory[i*CHUNK_SIZE], CHUNK_SIZE);
    LAND_generateTopology(NULL, world->land, i, CHUNK_WIDTH, CHUNK_SIZE);
    LAND_generateMesh(land, CHUNK_WIDTH, MAP_WIDTH, GAME_pushVertex, chunk);
  }

  return TRUE;
}

int32 GAME_worldSetUniforms(gameWorld* world, soyShader* shader) {
  vec3f pos, dir, look;
  soyTransform* tran;
  gameCamera* cam = world->camera;
  if(world->camera == NULL) { return FALSE; }
  tran = (cam) ? &cam->transform : NULL;
  pos = tran->position;
  dir = tran->direction;
  look = tran->lookAt;
  SOY_glSetUniformFloat(shader, "chunkScale", world->chunkScale);
  SOY_glSetUniformFloat(shader, "worldScale", world->worldScale);
  SOY_glSetUniformFloat(shader, "camCrosshairSize", cam->reticleSize);
  SOY_glSetUniformFloat(shader, "camFieldOfView", cam->fieldOfView);
  SOY_glSetUniformFloat3(shader, "camPosition", 1, (real32*)&pos);
  SOY_glSetUniformFloat3(shader, "camDirection", 1, (real32*)&dir);
  SOY_glSetUniformFloat3(shader, "camLook", 1, (real32*)&look);
  return TRUE;
}

int32 GAME_worldRenderChunk(gameWorld* world, int32 index,
    mat4f view, mat4f projection, soyShader* shader) {
  landChunk* land = &world->land[index];
  gameModel* model = &world->chunks[index].model;
  real32 tx = ((real32)land->x*world->chunkScale);
  real32 ty = ((real32)land->y*world->chunkScale);
  mat4f mat = SOY_mat4f(1.0f);
  SOY_mat4fTranslate(&mat, tx, 0.0f, ty);
  SOY_setMVP(shader, &mat, &view, &projection);
  SOY_glBindVertexArray(model->vao);
  SOY_glDrawArrays(GL_TRIANGLES, 0, model->numVertices);
  return TRUE;
}

int32 GAME_worldRender(soyApp* app, gameWorld* world) {
  int32 i;
  int32 h = SOY_width(app);
  int32 w = SOY_height(app);
  mat4f projection = SOY_mat4fProjection(0.1f, 2000.0f, 90.0f, h/w);
  mat4f view = SOY_transformViewMatrix(&world->camera->transform);
  soyShader* shader = &world->chunkShader;
  GAME_worldSetUniforms(world, shader);
  for(i = 0; i < world->worldSize*world->worldSize; i++) {
    GAME_worldRenderChunk(world, i, view, projection, shader);
  }
  return TRUE;
}

int32 GAME_update(soyApp* app, real32 dt) {

	return TRUE;
}

int32 GAME_render(soyApp* app, real32 dt) {
  GAME_worldRender(app, &g_world);
  return TRUE;
}

int32 GAME_start(soyApp* app) {

	return TRUE;
}

int32 GAME_stop(soyApp* app) {

	return TRUE;
}

/* library callbacks *******************************************************/

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  GAME_update(app, (real32)dt);
  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  GAME_render(app, (real32)dt);
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  GAME_start(app);
  return TRUE;
}

int32 SOY_userStop(soyApp* app) {
  GAME_stop(app);
  return TRUE;
}

int32 main() {
  soyApp app;
  SOY_create(&app, "soyCraft v0.0.1", 1080, 720);
  return TRUE;
}
