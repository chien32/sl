#define SOY_DEBUG
#define SOY_HARDWARE_ENABLE
#include "soy.h"

SOY_GLOBAL real32 g_glQuad[] = {
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f
};

SOY_GLOBAL uint32 g_glQuadIndices[] = {
  0, 1, 3,
  1, 2, 3
};

SOY_GLOBAL int8* g_vertShader =
"#version 330 core\n"
"layout(location = 0) in vec3 inPos;\n"
"layout(location = 1) in vec3 inCol;\n"
"layout(location = 2) in vec2 inUVCoord;\n"

"out vec3 outPos;\n"
"out vec3 outCol;\n"
"out vec2 outCoords;\n"

"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"

"void main() {\n"
"  outCoords = inUVCoord;\n"
"  outCol = inCol;\n"
"  outPos = normalize(inPos);\n"
"  gl_Position = projection * view * model * vec4(inPos, 1.0);\n"
"  gl_Position = vec4(inPos*1.8, 1.0);\n"
"}\n";

SOY_GLOBAL int8* g_fragShader =
"#version 330 core\n"
"out vec4 fragColor;\n"
"in vec3 outPos;\n"
"in vec3 outCol;\n"
"in vec2 outCoords;\n"
"void main() {\n"
"  fragColor = vec4(outCoords.x, outCoords.y, 1.0, 1.0);\n"
"}\n";


typedef struct tag_ccShader {
  soyGLShader shader;
} ccShader;

typedef struct tag_ccModel {
  SOY_VAO vao;
  SOY_VBO vbo;
  SOY_EBO ebo;
} ccModel;

int32 CC_modelInit(ccModel* model) {
  SOY_glGenVertexArrays(1, &model->vao);
  SOY_glGenBuffers(1, &model->vbo);
  SOY_glGenBuffers(1, &model->ebo);
  SOY_glBindVertexArray(model->vao);
  SOY_glBindBuffer(GL_ARRAY_BUFFER, model->vbo);
  SOY_glBufferData(GL_ARRAY_BUFFER, sizeof(g_glQuad), g_glQuad);
  SOY_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->ebo);
  SOY_glBufferData(GL_ELEMENT_ARRAY_BUFFER,
      sizeof(g_glQuadIndices), g_glQuadIndices);
  SOY_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
      8 * sizeof(real32), (void*)0);
  SOY_glVertexAttribEnable(0);
  SOY_glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
      8 * sizeof(real32), (void*)(3 * sizeof(real32)));
  SOY_glVertexAttribEnable(1);
  SOY_glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
      8 * sizeof(real32), (void*)(6 * sizeof(real32)));
  SOY_glVertexAttribEnable(2);
  

  return TRUE;
}

int32 CC_createShader(ccShader* shader) {
  SOY_glShaderCreate(
      "shaders/shader_vert.soy",
      "shaders/shader_frag.soy", &shader->shader);
  return TRUE;
}

ccModel g_mainModel;
ccShader g_mainShader;
soyGLTexture g_mainTexture;
soyGLTexture g_noiseTexture;
soyCanvas g_noiseCanvas;
soyMemorySector g_noiseMemory;

real32 playerX = 0.9;
real32 playerY = -0.5;
real32 playerZ = -0.9;
real32 playerPan = -0.5;
real32 playerPitch = -0.1;

int32 CC_genNoise(soyCanvas* canvas) {
  int32 x, y;
  real32 nx, ny;
  real32 n;
  real32 scale = 1.0f;
  real32 c;
  int32 ic;
  for(y = 0; y < canvas->rgba.height; y++) {
    for(x = 0; x < canvas->rgba.width; x++) {
      nx = (real32)x / (real32)canvas->rgba.width;
      ny = (real32)y / (real32)canvas->rgba.height;
      n = SOY_noiseDomainWarp2D(
          nx*scale, ny*scale, 0.2f, 0.4f, 1.0f, 1.0f, 0.5f, 8);
      n*=0.5f + 0.5f;
      c = SOY_MIN(SOY_MAX((n*0.5f + 0.5f), 0.0f), 1.0f);
      ic = (int32)(c * 255.0f);
      SOY_drawSetColour(canvas, SOY_pixel(ic, ic, ic, 255));
      SOY_drawPixel(canvas, x, y);
    }
  }

  g_noiseTexture.data = (uint8*)(canvas->rgba.data);
  SOY_glSetImageParams(TRUE);
  SOY_glGenTextures(1, &g_noiseTexture.id);
  SOY_glBindTexture(GL_TEXTURE_2D, g_noiseTexture.id);
  SOY_glTexImage2D(
      GL_TEXTURE_2D, 0, GL_RGBA,
      canvas->rgba.width, canvas->rgba.height, 0, GL_RGBA,
      GL_UNSIGNED_BYTE, canvas->rgba.data);
  SOY_glGenMipmap(GL_TEXTURE_2D);
  return TRUE;
}

SOY_GLOBAL real32 playerVel = 0.0;
SOY_GLOBAL real32 playerVelSide = 0.0;
SOY_GLOBAL real32 playerVelPan = 0.0;
SOY_GLOBAL real32 playerVelPitch = 0.0;
SOY_GLOBAL real32 playerAcc = 100.0f;
SOY_GLOBAL real32 playerTurn = 8.0f;
SOY_GLOBAL real32 playerFric = 5.0f;
SOY_GLOBAL real32 playerTime = 0.0f;
SOY_GLOBAL int32 state = 0;
SOY_GLOBAL int32 forcefield = 0;

SOY_GLOBAL real32 roomLeft = 10.0;
SOY_GLOBAL real32 roomRight = 10.0;
SOY_GLOBAL real32 roomFront = 10.0;
SOY_GLOBAL real32 roomBack = 10.0;
SOY_GLOBAL real32 roomTop = 10.0;
SOY_GLOBAL real32 roomBot = 10.0;

SOY_GLOBAL real32 warpX = 0.0;
SOY_GLOBAL real32 warpY = 0.0;
SOY_GLOBAL real32 warpZ = 0.0;

int32 CC_saveState() {
  FILE* file = SOY_fileOpen("shaders/state.soy", "wb");
  if(!file) { return FALSE; }
  fwrite(&playerX, 1, sizeof(real32), file);
  fwrite(&playerY, 1, sizeof(real32), file);
  fwrite(&playerZ, 1, sizeof(real32), file);
  fwrite(&playerPan, 1, sizeof(real32), file);
  fwrite(&playerPitch, 1, sizeof(real32), file);
  SOY_fileClose(file);
  return TRUE;
}

int32 CC_loadState() {
  FILE* file = SOY_fileOpen("shaders/state.soy", "rb");
  if(!file) { return FALSE; }
  fread(&playerX, 1, sizeof(real32), file);
  fread(&playerY, 1, sizeof(real32), file);
  fread(&playerZ, 1, sizeof(real32), file);
  fread(&playerPan, 1, sizeof(real32), file);
  fread(&playerPitch, 1, sizeof(real32), file);
  SOY_fileClose(file);
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  SOY_memorySectorCreate("noise", &g_noiseMemory, Megabytes(32));
  SOY_canvasCreate(&g_noiseMemory, &g_noiseCanvas, 1024, 1024);  

  CC_createShader(&g_mainShader);
  CC_modelInit(&g_mainModel);
  CC_genNoise(&g_noiseCanvas);
  CC_loadState();

  SOY_glSetImageParams(FALSE);
  SOY_glGenTextures(1, &g_mainTexture.id);
  SOY_glBindTexture(GL_TEXTURE_2D, g_mainTexture.id);
  g_mainTexture.data = (uint8*)(app->framebuffer->rgba.data);
  SOY_glTexImage2D(
      GL_TEXTURE_2D, 0, GL_RGB, SOY_width(app), SOY_height(app), 0, GL_RGB,
      GL_UNSIGNED_BYTE, g_mainTexture.data);
  SOY_glGenMipmap(GL_TEXTURE_2D);
  SOY_glBindTexture(GL_TEXTURE_2D, 0);
  return TRUE;
}

#define CUBE_MAX 9.0
#define CUBE_MIN -9.0

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  real32 fric = 1.0 - (playerFric*dt);
  real32 fricPitch = 1.0 - ((playerFric*4.0f)*dt);
  real32 speed = playerAcc*dt;
  real32 turnSpeed = playerTurn*dt;
  real32 sinPan = sin(playerPan);
  real32 cosPan = cos(playerPan);
  real32 sinSide = sin(playerPan + SOY_PI/2);
  real32 cosSide = cos(playerPan + SOY_PI/2);
  real32 mod = SOY_keyHeld(app, SOY_CONTROL) ? 1.0 : -1.0;
  real32 mouseDeltaX, mouseDeltaY;
  if(SOY_keyHeld(app, SOY_SHIFT)) {
    speed *= 20.0f;
  }

  if(SOY_keyHeld(app, SOY_W)) { playerVel += speed; }
  if(SOY_keyHeld(app, SOY_S)) { playerVel -= speed; }
  if(SOY_keyHeld(app, SOY_D)) { playerVelSide += speed; }
  if(SOY_keyHeld(app, SOY_A)) { playerVelSide -= speed; }
 
  if(SOY_keyHeld(app, SOY_LEFT)) { playerVelPan -= turnSpeed; }
  if(SOY_keyHeld(app, SOY_RIGHT)) { playerVelPan += turnSpeed; }

  if(SOY_keyHeld(app, SOY_DOWN)) { playerVelPitch -= turnSpeed; }
  if(SOY_keyHeld(app, SOY_UP)) { playerVelPitch += turnSpeed; }

  if(SOY_keyPressed(app, SOY_PGUP)) { state++; }
  if(SOY_keyPressed(app, SOY_PGDOWN)) { state--; }
  if(SOY_keyPressed(app, SOY_F)) { forcefield = !forcefield; }
  
  if(SOY_keyPressed(app, SOY_H)) { roomLeft += mod; }
  if(SOY_keyPressed(app, SOY_J)) { roomFront += mod; }
  if(SOY_keyPressed(app, SOY_K)) { roomRight += mod; }
  if(SOY_keyPressed(app, SOY_L)) { roomBack += mod; }
  if(SOY_keyPressed(app, SOY_P)) { roomTop += mod; }
  if(SOY_keyPressed(app, SOY_O)) { roomBot += mod; }

  if(SOY_keyPressed(app, SOY_F5)) { CC_saveState(); }

  SOY_setMouseCapture(app, TRUE);
  
  mouseDeltaX = (real32)(SOY_mouseDeltaX(app));
  mouseDeltaY = (real32)(SOY_mouseDeltaY(app));  

  playerPan += mouseDeltaX*0.005f;
  playerPitch += mouseDeltaY*0.005f;


  if(playerZ >= 8.0) {
    if(roomBack < 1000.0) {
      roomBack += dt*200.0;
    } else {
      roomBack = max(playerZ + 100, roomBack);
    }
  } else if(roomBack > 10.0) {
    roomBack -= dt*200.0;
  }

  if(roomBack < 10.0) {
    roomBack = 10.0;
  }


  state %= 4;

  playerVel *= fric;
  playerVelSide *= fric;
  playerVelPan *= fricPitch;
  playerVelPitch *= fricPitch;
#if 0 
  playerPan += playerVelPan*dt;
  playerPitch += playerVelPitch*dt;
  playerPitch = SOY_MIN(SOY_MAX(playerPitch, -1.0), 1.0);
#endif
  playerX += (sinPan*playerVel + sinSide*playerVelSide)*dt;
#if 0
  playerY += -sin(playerPitch)*playerVel*dt;
#endif
  playerZ += (cosPan*playerVel + cosSide*playerVelSide)*dt;
  playerTime += dt;
  playerY = 2.0f;
#if 1
#if 0
  if(playerY < -roomBot + 0.5) { playerY = -roomBot + 0.5; }
  if(playerY > roomTop - 0.5) { playerY = roomTop - 0.5; }
#endif
  warpX = sin(playerTime + playerZ*0.1 - playerZ*0.1)*((playerZ + 10.0)*0.01);
  warpY = cos(playerTime + playerZ*0.1 - playerZ*0.1)*((playerZ + 10.0)*0.01);
  warpZ = -sin(playerTime + playerZ*0.1 - playerZ*0.1)*((playerZ + 10.0)*0.01);
  
  if(playerX < -roomLeft + 0.5) { playerX = -roomLeft + 0.5; }
  if(playerX > roomRight - 0.5) { playerX = roomRight - 0.5; }
  if(playerZ < -roomFront + 0.5) { playerZ = -roomFront + 0.5; }
  if(playerZ > roomBack - 0.5) { playerZ = roomBack - 0.5; }
#if 0
  if(playerZ > 100.0) {
    playerZ = 100.0 - SOY_2PI;
  }
#endif
#endif

  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  mat4f model = SOY_mat4f(1.0f);
  mat4f view = SOY_mat4f(1.0f);
  mat4f projection = SOY_mat4f(1.0f);
  real32 aspect = (real32)SOY_width(app)/(real32)SOY_width(app);
  
  SOY_drawSetColour(app->framebuffer, 0xFF000000);
  SOY_drawClear(app->framebuffer);
  SOY_drawSetColour(app->framebuffer, 0xFFFFFFFF);
  SOY_drawTextFormat(app->framebuffer, app->fontRegular, 
      32, 32, "cycles: %f\ndelta: %f\nframes: %d\n"
      "x: %f\ny: %f\ny: %f\nv: %f",
      app->timing.userCyclesDelta, dt, g_fps,
      playerX, playerY, playerZ, playerVel);

  model = SOY_mat4fRotationX(45.0f);
  projection = SOY_mat4fProjection(0.01f, 1000.0f, 90.0f, aspect);
  view = SOY_mat4fTranslation(0.0f, 0.0f, 3.0f);
#if 0
  SOY_drawCanvas(app->framebuffer, &g_noiseCanvas, 0, 0, 512, 512);
#endif
  SOY_glSetUniformMat4(&g_mainShader.shader,
      "model", 1, GL_FALSE, &model.m[0][0]);
  SOY_glSetUniformMat4(&g_mainShader.shader,
      "view", 1, GL_FALSE, &view.m[0][0]);
  SOY_glSetUniformMat4(&g_mainShader.shader,
      "projection", 1, GL_FALSE, &projection.m[0][0]);

  g_mainTexture.data = (uint8*)(app->framebuffer->rgba.data);
  SOY_glBindTexture(GL_TEXTURE_2D, g_mainTexture.id);
  SOY_glTexImage2D(
      GL_TEXTURE_2D, 0, GL_RGBA, SOY_width(app), SOY_height(app), 0, GL_RGBA,
      GL_UNSIGNED_BYTE, g_mainTexture.data);
  SOY_glGenMipmap(GL_TEXTURE_2D);
  
  SOY_glSetUniformFloat(&g_mainShader.shader, "playerX", playerX);
  SOY_glSetUniformFloat(&g_mainShader.shader, "playerY", playerY);
  SOY_glSetUniformFloat(&g_mainShader.shader, "playerZ", playerZ);
  SOY_glSetUniformFloat(&g_mainShader.shader, "playerPan", playerPan);
  SOY_glSetUniformFloat(&g_mainShader.shader, "playerPitch", playerPitch);
  SOY_glSetUniformFloat(&g_mainShader.shader, "playerTime", playerTime);
  
  SOY_glSetUniformFloat(&g_mainShader.shader, "roomLeft", roomLeft);
  SOY_glSetUniformFloat(&g_mainShader.shader, "roomRight", roomRight);
  SOY_glSetUniformFloat(&g_mainShader.shader, "roomTop", roomTop);
  SOY_glSetUniformFloat(&g_mainShader.shader, "roomBot", roomBot);
  SOY_glSetUniformFloat(&g_mainShader.shader, "roomFront", roomFront);
  SOY_glSetUniformFloat(&g_mainShader.shader, "roomBack", roomBack);

  SOY_glSetUniformFloat(&g_mainShader.shader, "warpFactorX", warpX);
  SOY_glSetUniformFloat(&g_mainShader.shader, "warpFactorY", warpY);
  SOY_glSetUniformFloat(&g_mainShader.shader, "warpFactorZ", warpZ);
  
  SOY_glSetUniformInt(&g_mainShader.shader, "state", state);
  SOY_glSetUniformInt(&g_mainShader.shader, "forcefield", forcefield);
  
  SOY_glSetUniformInt(&g_mainShader.shader, "framebuffer", 0);
  SOY_glSetUniformInt(&g_mainShader.shader, "noisemap", 1);
  
  SOY_glClearColour(0.2f, 0.3f, 0.8f, 1.0f);
  SOY_glClear(GL_COLOR_BUFFER_BIT);
  SOY_glUseProgram(&g_mainShader.shader);
  
  glActiveTexture(GL_TEXTURE0 + 0);
  glBindTexture(GL_TEXTURE_2D, g_mainTexture.id);

  glActiveTexture(GL_TEXTURE0 + 1);
  glBindTexture(GL_TEXTURE_2D, g_noiseTexture.id);

  SOY_glBindVertexArray(g_mainModel.vao);
  SOY_glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  SOY_glSwapBuffers(GetDC(app->windowHandle));
  
  SOY_glBindTexture(GL_TEXTURE_2D, 0);

  return TRUE;
}

int32 SOY_userStop(soyApp* app) {

  return TRUE;
}

int32 main() {
  soyApp app;
  SOY_create(&app, "soyCraft v0.0.1", 1080, 720);
  return TRUE;
}

