#include "soy.h"





#define TILE_SIZE 16
#define TILE_SCALE 16.0f



typedef struct tag_gameEntity {
  uint32 state;
  int32 x;
  int32 y;
  int32 ID;
  int32 hunger;
  int8* name;
  real32 accum;
  real32 subX;
  real32 subY;
  real32 vision;
  int32 fov;
  int32 dirX;
  int32 dirY;
} gameEntity;


gameEntity GAME_entity(int8* name, int32 x, int32 y, int32 state, int32 ID) {
  gameEntity ret;
  ret.name = name;
  ret.x = x;
  ret.y = y;
  ret.state = state;
  ret.ID = ID;
  ret.hunger = 0;
  ret.subX = (real32)x;
  ret.subY = (real32)y;
  ret.dirX = 0;
  ret.dirY = 1;
  ret.vision = 200.0f;
  ret.fov = 4;
  ret.accum = 0.0f;
  return ret;
}

#define MAX_ENTITIES 1024
#define DOMAIN_SIZE 64

static gameEntity entities[MAX_ENTITIES];
static uint32 tiles[DOMAIN_SIZE*DOMAIN_SIZE];
static uint32 entityCount = 1;
static uint32 playerID = 0;
static real32 subTick = 0.0f;
static int32 inputLState = 0;
static int32 inputRState = 0;
static int32 inputUState = 0;
static int32 inputDState = 0;
static int32 inputHState = 0;
static int32 inputVState = 0;


static int32 dirSin[4] = { -1, 1, 0, 0 };
static int32 dirCos[4] = { 0, 0, -1, 1 };

int32 GAME_entityMove(int32 x, int32 y, real32 speed, gameEntity* entity) {
  if(entity->accum < 1.0f) {
    entity->accum += speed;
  } else {
    entity->accum = 0.0f;
    entity->x += x;
    entity->y -= y;
  }
#if 1
  if((x || y) && (!x != !y)) {
    entity->dirX = x;
    entity->dirY = -y;
  }
#endif
  return TRUE;
}

int32 GAME_entityRotate(int32 s, int32 c, gameEntity* entity) {
  entity->dirX = s;
  entity->dirY = -c;
  return TRUE;
}

int32 GAME_entitySearchForFood(gameEntity* entity) {
  int32 rd = SOY_randInt(4);
  if(rd == 0) { GAME_entityMove(1, 0, 0.05f, entity); }
  if(rd == 1) { GAME_entityMove(-1, 0, 0.05f, entity); }
  if(rd == 2) { GAME_entityMove(0, 1, 0.05f, entity); }
  if(rd == 3) { GAME_entityMove(0, -1, 0.05f, entity); }
  return TRUE;
}

int32 GAME_entityAnimate(gameEntity* entity, real32 dt) {
  real32 speed = 5.0f;
  entity->subX += speed*((real32)entity->x - entity->subX)*dt;
  entity->subY += speed*((real32)entity->y - entity->subY)*dt;
  return TRUE;
}

int32 GAME_entityEvaluateVision(gameEntity* entity) {


  return TRUE;
}

int32 GAME_entityDrawVision(soyApp* app, gameEntity* entity) {
  int32 x, y;
  real32 rx, ry;
  real32 width = 0.0f;
  int32 dirX = entity->dirX;
  int32 dirY = entity->dirY;
  for(x = 0; x < (int32)(entity->vision/TILE_SCALE); x++) {
    SOY_drawSetColour(app->framebuffer, 
        SOY_pixel(0, 0, 0, 255 -
          (uint32)((real32)x / (entity->vision/TILE_SCALE)*255.0f)));
    for(y = -(int32)(width); y <= (int32)(width); y++) {
      rx = (entity->subX + (real32)(dirX*x + 
            dirY*y))*TILE_SCALE + 0.5f;
      ry = (entity->subY + (real32)(dirX*y + 
            dirY*x))*TILE_SCALE + 0.5f;
      if(SOY_distance(
            0.0f, 0.0f,
            rx - entity->subX*TILE_SCALE,
            ry - entity->subY*TILE_SCALE) < entity->vision) {
        SOY_drawRectFill(app->framebuffer,
            (int32)rx, (int32)ry, (int32)rx + TILE_SIZE, (int32)ry + TILE_SIZE);
      }
    }
    width += (((real32)entity->fov*(real32)entity->fov) / TILE_SCALE);
    width = SOY_MIN(width, entity->vision/TILE_SCALE);
  }
  return TRUE;
}

int32 GAME_entityUpdate(soyApp* app, gameEntity* entity) {
  if(!entity->state) { return FALSE; } 
  if(entity->hunger > 10 && entity->ID != playerID) {
#if 1
    GAME_entitySearchForFood(entity); 
#endif
  }
  entity->hunger++;
  if(entity->hunger >= 1000) {
    entity->state = 0;
  }
  return TRUE;
}

int32 GAME_entityPlace(int32 x, int32 y) {
  int32 ID = entityCount;
  if(entityCount < MAX_ENTITIES) {
    entities[entityCount++] = GAME_entity("(new)", x, y, 1, ID);
  } else {
    SOY_LOG("Maximum entities\n");
  }
  return TRUE;
}

int32 GAME_entityDraw(soyApp* app, gameEntity* entity, real32 t) {
  real32 sx = entity->subX;
  real32 sy = entity->subY;
  SOY_drawSetColour(app->framebuffer, 0xFF000000);
  SOY_drawCircleFill(app->framebuffer,
        (int32)(sx*TILE_SCALE + TILE_SCALE/2.0f),
        (int32)(sy*TILE_SCALE + TILE_SCALE/2.0f), 6);
  SOY_drawTextMono(app->framebuffer, app->fontRegular,
      (int32)(sx*TILE_SCALE) - 8, (int32)(sy*TILE_SCALE) - 12, entity->name);
  GAME_entityDrawVision(app, entity);
  return TRUE;
}

int32 GAME_keyCallback(soyApp* app, int32 key, int32 state) {
  if(state) {
    if(key == SOY_ADD) { entities[playerID].fov += 1; }
    if(key == SOY_SUBTRACT) { entities[playerID].fov -= 1; }
  }
  return TRUE;
}

static real32 g_tickTimer = 0.0f;
static real32 g_tickFreq = 1.0f / 2.0f;

int32 GAME_tick(soyApp* app) {
  int32 i;
  for(i = 0; i < MAX_ENTITIES; i++) {
    if(entities[i].state) { GAME_entityUpdate(app, &entities[i]); }
  }
  return TRUE;
}

int32 GAME_animate(soyApp* app, real32 dt) {
  int32 i; 
  for(i = 0; i < MAX_ENTITIES; i++) {
    GAME_entityAnimate(&entities[i], dt);
  }
  return TRUE;
}

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  int32 mwX = SOY_mouseX(app)/TILE_SIZE;
  int32 mwY = SOY_mouseY(app)/TILE_SIZE;
  int32 mL = SOY_keyHeld(app, SOY_A);
  int32 mR = SOY_keyHeld(app, SOY_D);
  int32 mU = SOY_keyHeld(app, SOY_W);
  int32 mD = SOY_keyHeld(app, SOY_S);
  int32 mH = mL && mR ? 0 : mL ? -1 : mR ? 1 : 0; 
  int32 mV = mD && mU ? 0 : mD ? -1 : mU ? 1 : 0; 
  real32 speed = SOY_keyHeld(app, SOY_CONTROL) ? 0.0f : 0.2f;
  if(SOY_mousePressed(app, SOY_MOUSE_LEFT)) {
    GAME_entityPlace(mwX, mwY);
  }
  if(g_tickTimer >= g_tickFreq) {
    GAME_tick(app);
    g_tickTimer = 0.0f;
  }
  GAME_animate(app, dt);
  g_tickTimer += dt;

  if(mR && inputLState && !inputRState) {
    inputHState = 1;
  } else if(mL && inputRState && !inputLState) {
    inputHState = 0;
  }
  
  if(mU && inputDState && !inputUState) {
    inputVState = 1;
  } else if(mD && inputUState && !inputDState) {
    inputVState = 0;
  }


  if(inputHState) { 
    if(mL) { GAME_entityRotate(-1, 0, &entities[playerID]); }
    if(mR) { GAME_entityRotate(1, 0, &entities[playerID]); }
  } else {
    if(mR) { GAME_entityRotate(1, 0, &entities[playerID]); }
    if(mL) { GAME_entityRotate(-1, 0, &entities[playerID]); }
  }
  
  if(inputVState) { 
    if(mD) { GAME_entityRotate(0, -1, &entities[playerID]); }
    if(mU) { GAME_entityRotate(0, 1, &entities[playerID]); }
  } else {
    if(mU) { GAME_entityRotate(0, 1, &entities[playerID]); }
    if(mD) { GAME_entityRotate(0, -1, &entities[playerID]); }
  }

  inputLState = mL;
  inputRState = mR;
  inputUState = mU;
  inputDState = mD;

  GAME_entityMove(mH, mV, speed, &entities[playerID]);
  return TRUE;
}

int32 GAME_drawDomain(soyApp* app, int32 ox, int32 oy) {
  int32 x, y;
  int32 rx, ry;
  for(y = 0; y < DOMAIN_SIZE; y++) {
    for(x = 0; x < DOMAIN_SIZE; x++) {
      rx = ox + x*TILE_SIZE;
      ry = oy + y*TILE_SIZE;
      SOY_drawRect(app->framebuffer,
          rx, ry, rx + TILE_SIZE, ry + TILE_SIZE, 1);
    }
  }
  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  int32 i;
  SOY_drawSetColour(app->framebuffer, 0xFFFFFFFF);
  SOY_drawClear(app->framebuffer);
  for(i = 0; i < MAX_ENTITIES; i++) {
    if(entities[i].state) { GAME_entityDraw(app, &entities[i],
        g_tickTimer * (1.0f / g_tickFreq)); }
  }
  GAME_drawDomain(app, 0, 0);
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  SOY_registerKeyCallback(app, GAME_keyCallback);
  SOY_memorySet(entities, 0, MAX_ENTITIES*sizeof(gameEntity));
#if 0
  for(i = 0; i < MAX_ENTITIES; i++) {
    entities[i] = GAME_entity("(null)", SOY_randInt(54), SOY_randInt(43), (SOY_randInt(20) < 2), i);
  }
#endif
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

