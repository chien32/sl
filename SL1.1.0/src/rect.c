#include "soy.h"
#include "soyrect.h"

soyForm form;

int32 mode = 0;

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  SOY_formUpdate(&form, 0, 0, SOY_width(app), SOY_height(app), mode);
  

  if(SOY_keyPressed(app, SOY_K)) { mode++; }
  if(SOY_keyPressed(app, SOY_J)) { mode--; }
  mode &= 8;

  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  SOY_drawSetColour(app->framebuffer, 0xFF000000);
  SOY_drawClear(app->framebuffer);
  SOY_drawSetColour(app->framebuffer, 0xFF224499);
  SOY_formRender(app->framebuffer, app->fontRegular, &form);
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  SOY_formCreate(&form, 40, 40, 120, 32);
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

