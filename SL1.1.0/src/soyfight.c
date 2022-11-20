#include "soy.h"


#define TILE_SIZE 16.0f

typedef struct tag_gameEntity {
  uint32 state;
  real32 x;
  real32 y;
  int32 ID;
  int8* name;
  real32 dir;
  real32 motion;
} gameEntity;


gameEntity GAME_entity(int8* name,
    real32 x, real32 y, int32 state, int32 ID) {
  gameEntity ret;
  ret.name = name;
  ret.x = x;
  ret.y = y;
  ret.state = state;
  ret.ID = ID;
  ret.dir = 0.0f;
  return ret;
}

#define MAX_ENTITIES 1024

static gameEntity entities[MAX_ENTITIES];
static uint32 playerID = 0;

int32 GAME_entityMove(int32 x, int32 y, gameEntity* entity) {
   entity->x += (real32)x*0.1f;
   entity->y -= (real32)y*0.1f;
   entity->dir += (atan2(x, -y) - entity->dir)*0.1f;
   entity->motion -= atan2(x, -y)*0.1f;
   return TRUE;
}

int32 GAME_entityUpdate(soyApp* app, gameEntity* entity) {
  if(entity->ID == playerID) { return FALSE; } 
  return TRUE;
}

int32 GAME_entityDraw(soyApp* app, gameEntity* entity) {
  int32 cx = (int32)(entity->x*TILE_SIZE + TILE_SIZE/2);
  int32 cy = (int32)(entity->y*TILE_SIZE + TILE_SIZE/2);
    SOY_drawSetColour(app->framebuffer, 0xFF000000);
  SOY_drawCircleFill(app->framebuffer, cx, cy, 6);
  SOY_drawTextMono(app->framebuffer, app->fontRegular,
      cx - 16, cy - 16,
      entity->name);
  
  SOY_drawCircle(app->framebuffer, cx, cy + 24, 12);
  SOY_drawCircleFill(app->framebuffer, cx + sin(entity->motion)*12, cy + 24 + cos(entity->motion)*12, 2);
  SOY_drawLine(app->framebuffer,
      cx, 
      cy + 24,
      cx + sin(entity->dir)*24, 
      cy + cos(entity->dir)*24 + 24);
  return TRUE;
}

int32 GAME_keyCallback(soyApp* app, int32 key, int32 state) {
  if(state) {

  }
  return TRUE;
}

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  int32 i;

  if(SOY_keyHeld(app, SOY_A)) { GAME_entityMove(-1, 0, &entities[playerID]);}
  if(SOY_keyHeld(app, SOY_D)) { GAME_entityMove(1, 0, &entities[playerID]); }
  if(SOY_keyHeld(app, SOY_W)) { GAME_entityMove(0, 1, &entities[playerID]); }
  if(SOY_keyHeld(app, SOY_S)) { GAME_entityMove(0, -1, &entities[playerID]);}

  for(i = 0; i < MAX_ENTITIES; i++) {
    if(entities[i].state) { GAME_entityUpdate(app, &entities[i]); }
  }
  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  int32 i;
  SOY_drawSetColour(app->framebuffer, 0xFFFFFFFF);
  SOY_drawClear(app->framebuffer);
  for(i = 0; i < MAX_ENTITIES; i++) {
    if(entities[i].state) { GAME_entityDraw(app, &entities[i]); }
  }
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  int32 i;
  SOY_registerKeyCallback(app, GAME_keyCallback);
  SOY_memorySet(entities, 0, MAX_ENTITIES*sizeof(gameEntity));
  for(i = 0; i < MAX_ENTITIES; i++) {
    entities[i] = GAME_entity("(null)", 0, 0, 0, i);
  }
  entities[playerID] = GAME_entity("(you)", 5, 5, 1, playerID);
  return TRUE;
}

int32 SOY_userStop(soyApp* app) {
  return TRUE;
}

int32 main() {
  soyApp app;
  SOY_create(&app, "soyIM", 640, 480);
  return TRUE;
}

