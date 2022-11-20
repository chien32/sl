#include "minisoy.h"

int32 SOY_userUpdate(soyApp* app, real64 dt) {

	return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
	int32 x, y;
	int32 w = SOY_drawWidth(app->framebuffer);
	int32 h = SOY_drawHeight(app->framebuffer);
	uint32* base = SOY_drawBuffer(app->framebuffer);
	uint32* pixel = base;
	for(y = 0; y < h; y++) {
	  for(x = 0; x < w; x++) {
		*pixel = x + y;
		pixel++;
	  }
	}
	SOY_drawText(app->framebuffer, app->font, 16, 16, "Nigger");
	return TRUE;
}

int32 SOY_userStart(soyApp* app) {
	return TRUE;
}

int32 SOY_userStop(soyApp* app) {
	return TRUE;
}

int main() {
	soyApp app;
	SOY_create(&app, "minisoy", 320, 240);
	return TRUE;
 }
