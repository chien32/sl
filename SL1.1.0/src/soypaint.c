#define SOY_NO_HARDWARE
#include "soy.h"

#define PAINT_MAX_KERNEL 512*512

typedef struct tag_paintMemory {
  soyMemorySector canvasMemory;
} paintMemory;

typedef real32 (*PFBRUSH) (real32 x, real32 y, real32 s);

typedef struct tag_paintBrush {
  int32 offsetX;
  int32 offsetY;
  int32 startX;
  int32 startY;
  int32 endX;
  int32 endY;
  int32 paintX;
  int32 paintY;
  int32 scale;
  vec4f colour;
  vec4f background;
  PFBRUSH proc;
} paintBrush;

typedef struct tag_paintWorld {
  paintBrush brush;
  soyMemorySector canvasMemory;
  soyCanvas drawCanvas;
  soyPixel background;
  int32 offsetX;
  int32 offsetY;
} paintWorld;

SOY_GLOBAL paintWorld g_paintWorld;

paintBrush PAINT_brush(PFBRUSH shapeProc,
    real32 r, real32 g, real32 b, int32 s) {
  paintBrush ret;
  SOY_ASSERT(shapeProc != NULL);
  ret.startX = 0;
  ret.startY = 0;
  ret.endX = 0;
  ret.endY = 0;
  ret.paintX = 0;
  ret.paintY = 0;
  ret.scale = s;
  ret.proc = shapeProc;
  ret.colour = SOY_vec4f(r, g, b, 1.0f);
  return ret;
}

real32 PAINT_brushCreateSphere(real32 x, real32 y, real32 s) {
  real32 ret = SOY_distance(0.0f, 0.0f, x, y);
  real32 nor = (ret) / (s*0.5f);
  real32 dis = sqrt(nor);
  return SOY_MIN(SOY_MAX((1.0f - dis), 0.0f), 1.0f);
}

int32 PAINT_brushMove(soyApp* app, paintBrush* brush,
    int32 offsetX, int32 offsetY, int32 mx, int32 my) {
  brush->startX = brush->endX;
  brush->startY = brush->endY;
  brush->endX = mx;
  brush->endY = my;
  brush->offsetX = offsetX;
  brush->offsetY = offsetY;
  return TRUE;
}

int32 PAINT_brushApply(soyCanvas* canvas, paintBrush* brush, int32 erase) {
  int32 x, y;
  real32 rx, ry;
  real32 alpha;
  vec4f colour;
  soyPixel pix;
  int32 halfScale = brush->scale/2;
  int32 cw = canvas->rgba.width;
  int32 ch = canvas->rgba.height;
  int32 cx = brush->paintX;
  int32 cy = brush->paintY;
  for(y = -halfScale + 1; y < halfScale + 1; y++) {
    for(x = -halfScale + 1; x < halfScale + 1; x++) {
      rx = (real32)x / (real32)brush->scale;
      ry = (real32)y / (real32)brush->scale;
      alpha = brush->proc(x, y, (real32)brush->scale);
      if(erase) {
        colour = brush->background;      
      } else {
        colour = brush->colour;
      }
      
      colour.w = alpha;
      
      colour = SOY_vec4fMultiplyScalar(colour, 255.0f);
      pix = SOY_vec4fToPixel(colour);
      if(SOY_boundsCheck(cx + x, cy + y, 0, 0, cw, ch)) {
        SOY_drawSetColour(canvas, pix);
        SOY_drawPixelBlend(canvas, cx + x, cy + y);  
      }
    }
  }
  return TRUE;
}

int32 PAINT_brushDrawLine(soyCanvas* canvas, paintBrush* brush, 
    real32 x1, real32 y1, real32 x2, real32 y2, int32 erase) {
  real32 dx, dy, dax, day, x, y, step;
  int32 i;
  dx = (x2 - x1);
  dy = (y2 - y1);
  dax = SOY_fabs(dx);
  day = SOY_fabs(dy);
  step = ((dax >= day) ? dax : day);
  dx /= step;
  dy /= step;
  x = x1;
  y = y1;
  i = 0;
  while(i <= (int32)step) {
    brush->paintX = (int32)x - brush->offsetX;
    brush->paintY = (int32)y - brush->offsetY;
    PAINT_brushApply(canvas, brush, erase); 
    x += dx;
    y += dy;
    i += 1;
  }
  return TRUE;
}

int32 PAINT_brushAction(paintWorld* world,
    paintBrush* brush, int32 ml, int32 mm, int32 mr) {
  brush->background = SOY_pixelToVec4f(world->background);
  brush->background = SOY_vec4fDivideScalar(brush->background, 255.0f);
  if(ml) {
    PAINT_brushDrawLine(&world->drawCanvas, brush,
        brush->startX, brush->startY,
        brush->endX, brush->endY, FALSE);
  } else if(mr) {
    PAINT_brushDrawLine(&world->drawCanvas, brush,
        brush->startX, brush->startY,
        brush->endX, brush->endY, TRUE);
  }
  return TRUE;
}

int32 PAINT_worldInit(soyApp* app, paintWorld* world) {
  soyCanvas* canvas = &world->drawCanvas;
  world->brush = 
    PAINT_brush(PAINT_brushCreateSphere, 0.5f, 0.7f, 0.2f, 32);
  SOY_memorySectorCreate("CANVAS",
      &world->canvasMemory, Megabytes(128));
  SOY_canvasCreate(
      &world->canvasMemory,
      &world->drawCanvas,
      SOY_width(app), SOY_height(app) - (22 + 64));
  world->background = SOY_pixel(255, 255, 255, 255);
  world->offsetX = 0;
  world->offsetY = 22 + 8;
  SOY_drawSetColour(canvas, world->background);
  SOY_drawClear(canvas);
  return TRUE;
}

SOY_GLOBAL soyPixel g_palette[16] = {
  0xFF000000,
  0xFFFFFFFF,
  0xFF888888,
  0xFFFF0000,
  0xFF00FF00,
  0xFF0000FF,
  0xFFFFFF00,
  0xFF00FFFF,
  0xFFFF00FF,
  0xFF880000,
  0xFF008800,
  0xFF000088,
  0xFF888800,
  0xFF008888,
  0xFF880088
};

int32 PAINT_worldRenderToolbar(soyApp* app, paintWorld* world) {
  int32 i;
  int32 w = 16;
  int32 sx, ex, sy, ey;
  int32 ox = world->offsetX;
  int32 oy = world->offsetY + world->drawCanvas.rgba.height + 2;
  int32 mx = SOY_mouseX(app);
  int32 my = SOY_mouseY(app);
  int32 ml = SOY_mousePressed(app, SOY_MOUSE_LEFT);
  int32 mr = SOY_mousePressed(app, SOY_MOUSE_RIGHT);
  soyCanvas* drawCanvas = &world->drawCanvas;
  vec4f pickedColour;
  for(i = 0; i < 16; i++) {
    sx = ox + i*w;
    ex = sx + w;
    sy = oy;
    ey = sy + w;
    SOY_drawSetColour(app->framebuffer, g_palette[i]);
    SOY_drawRectFill(app->framebuffer, sx, sy, ex, ey);
    if(SOY_boundsCheck(mx, my, sx, sy, ex, ey)) {
      if(ml) {
       pickedColour = SOY_pixelToVec4f(g_palette[i]);
       pickedColour = SOY_vec4fDivideScalar(pickedColour, 255.0f);
       world->brush.colour = pickedColour;
      } else if(mr) {
        pickedColour = SOY_pixelToVec4f(g_palette[i]);
        pickedColour = SOY_vec4fDivideScalar(pickedColour, 255.0f);
        world->brush.background = pickedColour;
      }
    }
    SOY_drawRectFill(app->framebuffer, sx, sy + w + 4, ex, ey + w + 4);
    if(SOY_boundsCheck(mx, my, sx, sy + w + 4, ex, ey + w + 4) && ml) {
       pickedColour = SOY_pixelToVec4f(g_palette[i]);
       world->background = g_palette[i];
       SOY_drawSetColour(drawCanvas, g_palette[i]);
       SOY_drawClear(drawCanvas);
      SOY_LOG("lol\n");
    }
  }
  return TRUE;
}

SOY_GLOBAL int32 g_toggleGrid = FALSE;

int32 PAINT_worldRender(soyApp* app, paintWorld* world, real32 dt) {
  soyCanvas* canvas = app->framebuffer;
  soyCanvas* drawCanvas = &world->drawCanvas;
  int32 w = drawCanvas->rgba.width;
  int32 x, y;
  SOY_drawSetColour(canvas, SOY_pixel(128, 128, 128, 255));
  SOY_drawClear(canvas);
  SOY_drawSetColour(drawCanvas, 0xFF888888);
  if(g_toggleGrid) {
    for(y = 0; y < drawCanvas->rgba.height; y += w/20) {
      SOY_drawLine(drawCanvas,
          0, y, drawCanvas->rgba.width, y);
      for(x = 0; x < drawCanvas->rgba.width; x += w/20) {
        SOY_drawLine(drawCanvas,
          x, 0, x, drawCanvas->rgba.height);
      }
    }
  }
  SOY_canvasCopy(canvas, &world->drawCanvas, world->offsetX, world->offsetY);
  
  SOY_drawSetColour(canvas, 
      SOY_vec4fToPixel(
        SOY_vec4fMultiplyScalar(world->brush.colour, 255.0f)));
  
  SOY_drawCircle(canvas,
      SOY_mouseX(app), SOY_mouseY(app), world->brush.scale/2);
  PAINT_worldRenderToolbar(app, world);
  return TRUE;
}

int32 PAINT_worldPollInput(soyApp* app, paintWorld* world) {
  paintBrush* brush = &world->brush;
  soyPixel col;
  int32 scrollSpeed = SOY_keyHeld(app, SOY_CONTROL) ? 10 : 1;
  int32 mx = SOY_mouseX(app);
  int32 my = SOY_mouseY(app);
  
  if(!SOY_keyHeld(app, SOY_SHIFT) || 
      SOY_mouseHeld(app, SOY_MOUSE_LEFT) ||
      SOY_mouseHeld(app, SOY_MOUSE_RIGHT)) {
    PAINT_brushMove(app, &g_paintWorld.brush,
      g_paintWorld.offsetX, g_paintWorld.offsetY, mx, my);
  }

  if(SOY_mouseScroll(app)) {
    if(SOY_mouseScroll(app) < 0) {
      if(world->brush.scale < 512 - scrollSpeed) {
        world->brush.scale += scrollSpeed;
      }
    } else {
      if(world->brush.scale >= scrollSpeed) {
        world->brush.scale -= scrollSpeed;
      }
    }
  }

  if(SOY_mousePressed(app, SOY_MOUSE_MIDDLE)) {
    col = SOY_drawSample(app->framebuffer, mx, my);
    world->brush.colour = 
      SOY_vec4fDivideScalar(SOY_pixelToVec4f(col), 255.0f);
  }
  
  if(mx > world->offsetX &&
      mx < world->offsetX + world->drawCanvas.rgba.width) {
    if(my > world->offsetY &&
        my < world->offsetY + world->drawCanvas.rgba.height) {
      if(SOY_mouseHeld(app, SOY_MOUSE_LEFT)) { 
        PAINT_brushAction(world, brush, 1, 0, 0);
      }
      if(SOY_mouseHeld(app, SOY_MOUSE_MIDDLE)) { 
        PAINT_brushAction(world, brush, 0, 1, 0);
      }
      if(SOY_mouseHeld(app, SOY_MOUSE_RIGHT)) { 
        PAINT_brushAction(world, brush, 0, 0, 1);
      }
    }
  }

  if(SOY_keyPressed(app, SOY_F3)) {
    g_toggleGrid = !g_toggleGrid;
  }

  return TRUE;
}

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  PAINT_worldPollInput(app, &g_paintWorld);
  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  if(app->resized) {
    SOY_canvasResize(&g_paintWorld.drawCanvas,
      SOY_width(app), SOY_height(app) - 64 - 22);
  }
  PAINT_worldRender(app, &g_paintWorld, dt);
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  PAINT_worldInit(app, &g_paintWorld);
  return TRUE;
}

int32 SOY_userStop(soyApp* app) {
  
  return TRUE;
}

int32 main() {
  soyApp app;
  SOY_create(&app, "soyPaint v0.0.1", 1080, 720);
  return 0;
}
