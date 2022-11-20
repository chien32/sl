#ifndef SOY_IMMEDIATE_H
#define SOY_IMMEDIATE_H
#include "soy.h"

#define IM_STD_WIDTH 12
#define IM_STD_HEIGHT IM_STD_WIDTH*8

#define IM_PLOT_LINES   0x01
#define IM_PLOT_COLUMNS 0x02
#define IM_PLOT_RECTS   0x04
#define IM_PLOT_POINTS  0x08
#define IM_PLOT_GRID    0x10
#define IM_PLOT_TEXT    0x20
#define IM_PLOT_LABEL   0x40
#define IM_PLOT_FILL    0x80

#define IM_TOP_LEFT      0
#define IM_TOP           1
#define IM_TOP_RIGHT     2
#define IM_RIGHT         3
#define IM_BOTTOM_RIGHT  4
#define IM_BOTTOM        5
#define IM_BOTTOM_LEFT   6
#define IM_LEFT          7

#define IM_RELEASED     0x01
#define IM_PRESSED      0x02
#define IM_HELD         0x04
#define IM_HOVER        0x08

#define IM_HORIZONTAL   0x01
#define IM_VERTICAL     0x02

typedef struct tag_imInfo {
  int32 winX1;
  int32 winY1;
  int32 winX2;
  int32 winY2;
  int32 menuX1;
  int32 menuY1;
  int32 menuX2;
  int32 menuY2;
  int32 anchorX;
  int32 anchorY;
  int32 mouseX;
  int32 mouseY;
  int32 alignX;
  int32 alignY;
  int32 wrapX;
  int32 wrapY;
  int32 mouseLeft;
  int32 mouseRight;
  int32 mouseMiddle;
  int32 anchor;
  int32 reactMode;
  int32 placeMode;
  int32 plotMode;
  int32 lineThickness;
  int32 pad;
  int32 rectCount;
  int32 maxRects;
  
  soyCanvas* canvas;
  soyFont* font;
  soyApp* app;
  soyRect* memory;
  soyRect* curRect;
} imInfo;

typedef int32 (*PFIMPROC) (imInfo* info, void* args);

SOY_GLOBAL imInfo g_imInfo;

int32 SOYIM_reset() {
  SOY_memorySet(g_imInfo.memory, 0, sizeof(soyRect)*g_imInfo.maxRects);
  return TRUE;
}

int32 SOYIM_init(void* memory, uint32 memorySize) {
  SOY_memorySet(&g_imInfo, 0, sizeof(imInfo));
  g_imInfo.memory = memory;
  g_imInfo.maxRects = memorySize / sizeof(soyRect);
  SOYIM_reset();
  SOY_LOG1("soyIm initialized with capacity %d\n", g_imInfo.maxRects);
  return TRUE;
}

int32 SOYIM_translate(int32* rx, int32* ry,
    int32 x, int32 y, int32 w, int32 h, int32 ax, int32 ay) {
  *rx = x + ax + g_imInfo.pad;
  *ry = y + ay + g_imInfo.pad;
  if(g_imInfo.anchor == IM_TOP_RIGHT) { *rx = ax - x - w - g_imInfo.pad; }
  if(g_imInfo.anchor == IM_RIGHT) { *rx = ax - x - w - g_imInfo.pad; }
  if(g_imInfo.anchor == IM_BOTTOM) { *ry = ay - y - h - g_imInfo.pad; }
  if(g_imInfo.anchor == IM_BOTTOM_LEFT) { *ry = ay - y - h - g_imInfo.pad; }
  if(g_imInfo.anchor == IM_BOTTOM_RIGHT) {
    *rx = ax - x - w - g_imInfo.pad; *ry = ay - y - h - g_imInfo.pad;
  }
  return TRUE;
}

int32 SOYIM_anchorInternal(int32* anchorX, int32* anchorY,
    int32 x1, int32 y1, int32 x2, int32 y2, int32 where) {
  int32 retX = 0;
  int32 retY = 0;
  switch(where) {
    case(IM_TOP_LEFT): {
      retX = x1;
      retY = y1;
      break;  
    }
    case(IM_TOP): {
      retX = 
        x1 + (x2 - x1) / 2;
      retY = y1;
      break;  
    }
    case(IM_TOP_RIGHT): {
      retX = x2;
      retY = y1;
      break;  
    }
    case(IM_RIGHT): {
      retX = x2;
      retY = 
        y1 + (y2 - y1) / 2;
      break;  
    }
    case(IM_BOTTOM_RIGHT): {
      retX = x2;
      retY = y2;
      break;  
    }
     case(IM_BOTTOM): {
      retX = 
        x1 + (x2 - x1) / 2;
      retY = y2;
      break;  
    }
    case(IM_BOTTOM_LEFT): {
      retX = x1;
      retY = y2;
      break;  
    }
    case(IM_LEFT): {
      retX = x1;
      retY = 
        y1 + (y2 - y1) / 2;
      break;  
    }
  }
  if(anchorX) { *anchorX = retX; }
  if(anchorY) { *anchorY = retY; }
  return TRUE;
}

int32 SOYIM_anchor(int32 where) {
  SOYIM_anchorInternal(&g_imInfo.anchorX, &g_imInfo.anchorY,
      g_imInfo.menuX1,
      g_imInfo.menuY1,
      g_imInfo.menuX2,
      g_imInfo.menuY2, where);
  g_imInfo.anchor = where;
  return TRUE;
}

int32 SOYIM_begin(soyApp* app) {
  g_imInfo.lineThickness = 1;
  g_imInfo.mouseX = SOY_mouseX(app);
  g_imInfo.mouseY = SOY_mouseY(app);
  g_imInfo.mouseLeft = SOY_mouseHeld(app, SOY_MOUSE_LEFT);
  g_imInfo.mouseMiddle = SOY_mouseHeld(app, SOY_MOUSE_MIDDLE);
  g_imInfo.mouseRight = SOY_mouseHeld(app, SOY_MOUSE_RIGHT);
  g_imInfo.app = app;
  g_imInfo.canvas = app->framebuffer;
  g_imInfo.font = app->fontRegular;
  g_imInfo.reactMode = IM_RELEASED;
  g_imInfo.placeMode = IM_HORIZONTAL;
  g_imInfo.plotMode = IM_PLOT_LINES;
  g_imInfo.rectCount = 0;
  g_imInfo.wrapX = FALSE;
  g_imInfo.wrapY = FALSE;
  g_imInfo.pad = 0;
  g_imInfo.winX1 = g_soyHitTestRect[1];
  g_imInfo.winY1 = g_soyHitTestRect[0];
  g_imInfo.winX2 = 
    g_imInfo.winX1 + 
    (app->windowWidth - g_soyHitTestRect[1] - g_soyHitTestRect[1]);
  g_imInfo.winY2 = 
    g_imInfo.winY1 + 
    (app->windowHeight - g_soyHitTestRect[1] - g_soyHitTestRect[0]);
  return TRUE;
}

int32 SOYIM_beginMenu(
    int32 offsetX, int32 offsetY, int32 mode) {
  soyRect* rect;
  int32 rx, ry;
  int32 anchorX;
  int32 anchorY;
  int32 pad = g_imInfo.pad;
  SOY_drawResetClipRect(g_imInfo.canvas);
 
  SOYIM_anchorInternal(&anchorX, &anchorY,
      g_imInfo.winX1,
      g_imInfo.winY1,
      g_imInfo.winX2,
      g_imInfo.winY2,
      mode);

  g_imInfo.menuX1 = offsetX;
  g_imInfo.menuY1 = offsetY;
  g_imInfo.menuX2 = offsetX + 200;
  g_imInfo.menuY2 = offsetY + 100;
  
  SOYIM_translate(&rx, &ry, g_imInfo.menuX1, g_imInfo.menuY1,
      g_imInfo.menuX2 - g_imInfo.menuX1, g_imInfo.menuY2 - g_imInfo.menuY1,
      anchorX, anchorY);

  g_imInfo.menuX1 = rx;
  g_imInfo.menuY1 = ry;
  g_imInfo.menuX2 = rx + (g_imInfo.menuX2 - g_imInfo.menuX1);
  g_imInfo.menuY2 = ry + (g_imInfo.menuY2 - g_imInfo.menuY1);

  g_imInfo.alignX = 0;
  g_imInfo.alignY = 0;

  if(g_imInfo.rectCount < g_imInfo.maxRects) {
    rect = &g_imInfo.memory[g_imInfo.rectCount++];
  } else {
    SOY_LOG("Error. Maximum memory exceeded\n");
    g_imInfo.curRect = NULL;
    return FALSE;
  }

  if(g_imInfo.menuX1 < g_imInfo.winX1) { g_imInfo.menuX1 = g_imInfo.winX1; }
  if(g_imInfo.menuX2 > g_imInfo.winX2) { g_imInfo.menuX2 = g_imInfo.winX2; }
  if(g_imInfo.menuY1 < g_imInfo.winY1) { g_imInfo.menuY1 = g_imInfo.winY1; }
  if(g_imInfo.menuY2 > g_imInfo.winY2) { g_imInfo.menuY2 = g_imInfo.winY2; }
  
  if(g_imInfo.menuX2 <= g_imInfo.menuX1 + pad*2) { return FALSE; }
  if(g_imInfo.menuY2 <= g_imInfo.menuY1 + pad*2) { return FALSE; }

  SOY_rectResize(rect,
      g_imInfo.menuX1,
      g_imInfo.menuY1,
      g_imInfo.menuX2,
      g_imInfo.menuY2);
  SOY_rectUpdateBase(rect,
      g_imInfo.mouseX, g_imInfo.mouseY, g_imInfo.mouseLeft);
  SOYIM_anchor(g_imInfo.anchor);
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
  SOY_drawRect(g_imInfo.canvas,
      g_imInfo.menuX1,
      g_imInfo.menuY1,
      g_imInfo.menuX2,
      g_imInfo.menuY2, 1);
  g_imInfo.curRect = rect;
  SOY_drawSetClipRect(g_imInfo.canvas,
    g_imInfo.menuX1 + pad,
    g_imInfo.menuY1 + pad,
    (g_imInfo.menuX2 - g_imInfo.menuX1) - pad*2 + 1,
    (g_imInfo.menuY2 - g_imInfo.menuY1) - pad*2 + 1);
  return TRUE;
}

int32 SOYIM_padding(int32 amount) {
  g_imInfo.pad = amount;
  return TRUE;
}

int32 SOYIM_plotMode(int32 mode) {
  g_imInfo.plotMode = mode;
  return TRUE;
}

int32 SOYIM_placeMode(int32 mode) {
  g_imInfo.placeMode = mode;
  return TRUE;
}

int32 SOYIM_wrapMode(int32 modeX, int32 modeY) {
  g_imInfo.wrapX = modeX;
  g_imInfo.wrapY = modeY;
  return TRUE;
}

int32 SOYIM_reactMode(int32 mode) {
  g_imInfo.reactMode = mode;
  return TRUE;
}

int32 SOYIM_alignNext(int32 w, int32 h) {
  if(g_imInfo.placeMode & IM_HORIZONTAL) {
    g_imInfo.alignX += w + g_imInfo.pad;
    if(g_imInfo.alignX + g_imInfo.pad > g_imInfo.menuX2) {
      g_imInfo.alignX = 0;
      g_imInfo.alignY += h + g_imInfo.pad;
    }
  }
  if(g_imInfo.placeMode & IM_VERTICAL) {
    g_imInfo.alignY += h + g_imInfo.pad;
    if(g_imInfo.alignY + g_imInfo.pad > g_imInfo.menuY2) {
      g_imInfo.alignY = 0;
      g_imInfo.alignX += w + g_imInfo.pad;
    }
  }
  return TRUE;
}

int32 SOYIM_checkOverflow(int32 w, int32 h) {
  if(g_imInfo.wrapX && g_imInfo.alignX + w > g_imInfo.menuX2 - g_imInfo.menuX1) {
    g_imInfo.alignX = 0;
    g_imInfo.alignY += h + g_imInfo.pad;
  }
  return w;
}

int32 SOYIM_base(int8* label, int32 width, int32 height,
    int32 offsetX, int32 offsetY,
    PFIMPROC uproc, void* uargs, int32* ox, int32* oy) {
  soyRect* rect;
  soyRect* parent;
  int32 rx, ry;
  int32 x, y;
  int32 ret = 0;
  int32 w = width;
  int32 h = height;
  parent = g_imInfo.curRect;
  if(!parent) { return FALSE; }
  SOYIM_checkOverflow(w + offsetX, h + offsetY);
  x = g_imInfo.alignX;
  y = g_imInfo.alignY;
  SOYIM_translate(&rx, &ry, x, y, w, h, g_imInfo.anchorX, g_imInfo.anchorY);
  *ox = rx;
  *oy = ry;
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFFFFFF);
  SOY_drawRectFill(g_imInfo.canvas, rx, ry, rx + w, ry + h);
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
  SOY_drawRect(g_imInfo.canvas, rx, ry, rx + w, ry + h, 1); 
  if(g_imInfo.rectCount < g_imInfo.maxRects) {
    rect = &g_imInfo.memory[g_imInfo.rectCount++];
    SOY_rectResize(rect, rx, ry, rx + w, ry + h);
    SOY_rectUpdateBase(rect,
        g_imInfo.mouseX, g_imInfo.mouseY, g_imInfo.mouseLeft);
    if(uproc && !SOY_rectHeldOutside(parent)) {
      if(g_imInfo.reactMode & IM_RELEASED) {
        if(SOY_rectReleased(rect)) { ret = uproc(&g_imInfo, uargs); }
      }
      if(g_imInfo.reactMode & IM_HELD) {
       if(SOY_rectHeld(rect)) { ret = uproc(&g_imInfo, uargs); }
      }
      if(g_imInfo.reactMode & IM_PRESSED) {
        if(SOY_rectPressed(rect)) { ret = uproc(&g_imInfo, uargs); }
      }
      if(g_imInfo.reactMode & IM_HOVER) {
        if(SOY_rectHover(rect)) { ret = uproc(&g_imInfo, uargs); }
      }
    } else {
      if(g_imInfo.reactMode & IM_RELEASED) {
        if(SOY_rectReleased(rect)) { ret = TRUE; }
      }
      if(g_imInfo.reactMode & IM_HELD) {
       if(SOY_rectHeld(rect)) { ret = TRUE; }
      }
      if(g_imInfo.reactMode & IM_PRESSED) {
        if(SOY_rectPressed(rect)) { ret = TRUE; }
      }
      if(g_imInfo.reactMode & IM_HOVER) {
        if(SOY_rectHover(rect)) { ret = TRUE; }
      }
    }
    SOYIM_alignNext(w + offsetX, h + offsetY); 
  }
  return ret;
}

/* user interface **********************************************************/

int32 SOYIM_buttonWidth(int32 textWidth) {
  return textWidth + 14;
}

int32 SOYIM_button(int8* label, PFIMPROC callback, void* args) {
  int32 x, y;
  int32 w = SOYIM_buttonWidth(SOY_drawTextWidthMono(g_imInfo.font, label));
  int32 h = IM_STD_WIDTH*2;
  int32 ret = SOYIM_base(label, w, h, 0, 0, callback, args, &x, &y);
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
  SOY_drawTextMono(g_imInfo.canvas, g_imInfo.font, x + 4, y + 4, label); 
  return ret;
}

int32 SOYIM_slider(int8* label, real32* control, real32 min, real32 max) {
  int32 x, y;
  int32 cmy;
  real32 rmy, smy;
  real32 f;
  int32 fi;
  int32 w = g_imInfo.placeMode & IM_VERTICAL ? IM_STD_HEIGHT : IM_STD_WIDTH;
  int32 h = g_imInfo.placeMode & IM_VERTICAL ? IM_STD_WIDTH : IM_STD_HEIGHT;
  int32 ret = SOYIM_base(label, w, h, 0, 0, NULL, NULL, &x, &y);
  if(g_imInfo.placeMode & IM_HORIZONTAL) {
    cmy = g_imInfo.mouseY - y - 2;
    rmy = (real32)(cmy + 0.5f) / (real32)h;
    smy = (1.0f - rmy) * (max - min);
    f =  control ? 1.0f - ((*control) - min) / (max - min) : 0.0f;
    fi = (int32)(f*(real32)(h - 8) + 0.5f) + 4;
    SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
    SOY_drawRect(g_imInfo.canvas, x, y + fi - 4, x + w, y + fi + 4, 1); 
  } else {
    cmy = g_imInfo.mouseX - x;
    rmy = (real32)(cmy + 0.5f) / (real32)w;
    smy = (1.0f - rmy) * (max - min);
    f =  control ? 1.0f - ((*control) - min) / (max - min) : 0.0f;
    fi = (int32)(f*(real32)(w - 8) + 0.5f) + 4;
    SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
    SOY_drawRect(g_imInfo.canvas, x + fi - 4, y, x + fi + 4, y + h, 1); 
  }
  if(ret && control) {
    *control = SOY_MIN(SOY_MAX((smy + min), min), max);
  }
  return ret;
}

int32 SOYIM_plotBackground(int32 x, int32 y, int32 w, int32 h,
    int32 inx, int32 iny) {
  int32 i;
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFFFFFF);
  SOY_drawRectFill(g_imInfo.canvas, x, y, x + w, y + h);
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
  SOY_drawRect(g_imInfo.canvas, x, y, x + w, y + h, 1);
  if(g_imInfo.plotMode & IM_PLOT_GRID) {
    for(i = 0; i < w / inx; i++) {
      SOY_drawLine(g_imInfo.canvas,
        x + i*inx, y, x + i*inx, y + h);
    }
    for(i = 0; i < h / iny; i++) {
      SOY_drawLine(g_imInfo.canvas,
        x, y + i*iny, x + w, y + i*iny);
    }
  }
  return TRUE;
}

int32 SOYIM_plot(int8* label, real32* data, uint32 length) {
  int32 rx, ry;
  real32 d;
  real32 nd;
  real32 scale;
  int32 xPos;
  int32 xPosPrev;
  int32 i;
  int32 id;
  int32 pid;
  int32 w = (g_imInfo.menuX2 - g_imInfo.pad) - (g_imInfo.menuX1 + g_imInfo.pad);
  int32 h = IM_STD_HEIGHT;
  real32 inx = (real32)w / ((real32)length - 1.0f);
  real32 iny = (real32)IM_STD_WIDTH;
  int32 intervalX = (int32)inx;
  int32 intervalY = (int32)iny;
  int32 sig = FALSE;
  int32 ret = SOYIM_base(label, w, h, 0, 0, NULL, NULL, &rx, &ry);
  scale = 0.0f;
  for(i = 0; i < length; i++) {
    scale = SOY_MAX(scale, SOY_fabs(data[i]));
    if(data[i] < 0.0f) { sig = TRUE; }
  }
  SOYIM_plotBackground(rx, ry, w, h, intervalX, intervalY);
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
  if(!data || length == 0) { return FALSE; }
  d = data[0];
  nd = (d / scale);
  if(sig) { nd = nd*0.5f + 0.5f; }
  id = (int32)(nd * h);
  pid = id;
  for(i = 0; i < length; i++) {
    d = data[i];
    nd = (d / scale);
    if(sig) { nd = nd*0.5f + 0.5f; }
    id = (int32)(nd * h);
    xPos = (int32)((real32)i * inx);
    xPosPrev = (int32)((real32)(i - 1) * inx);
    if(g_imInfo.plotMode & IM_PLOT_COLUMNS) {
      SOY_drawLine(g_imInfo.canvas,
        rx + xPos, ry + h, rx + xPos, ry + h - id);
    }
    if(g_imInfo.plotMode & IM_PLOT_LINES) {
      SOY_drawLineThick(g_imInfo.canvas,
        SOY_MAX(rx + xPosPrev, rx),
        ry + h - pid, rx + xPos, ry + h - id, 3, 0);
    }
    if(g_imInfo.plotMode & IM_PLOT_POINTS) {
      if(g_imInfo.plotMode & IM_PLOT_FILL) {
        SOY_drawCircleFill(g_imInfo.canvas,
          rx + xPos, ry + h - id, 2);     
      } else {
        SOY_drawCircle(g_imInfo.canvas,
          rx + xPos, ry + h - id, 2);     
      }
    }
    if(g_imInfo.plotMode & IM_PLOT_RECTS) {
      if(g_imInfo.plotMode & IM_PLOT_FILL) {
        SOY_drawRectFill(g_imInfo.canvas,
          SOY_MAX(rx + (xPosPrev), rx), ry + h - id,
          rx + (xPos), ry + h);     
      } else {
        SOY_drawRect(g_imInfo.canvas,
          SOY_MAX(rx + (xPosPrev), rx), ry + h - id,
          rx + (xPos), ry + h, 1);     
      }
    }
    if(g_imInfo.plotMode & IM_PLOT_TEXT) {
      SOY_drawTextFormat(g_imInfo.canvas, g_imInfo.font,
        rx + xPos + 2, ry + 4, "%.1f", d);     
      SOY_drawTextFormat(g_imInfo.canvas, g_imInfo.font,
        rx + xPos + 2, ry + h - 16, "%d", i);     
    }
    pid = id;
  }
  if(g_imInfo.plotMode & IM_PLOT_TEXT) {
    SOY_drawTextFormat(g_imInfo.canvas, g_imInfo.font,
      rx + 2, ry + h/2 - 16, "%.1f", sig ? 0.0f : scale/2.0f);
  }
  if(g_imInfo.plotMode & IM_PLOT_LABEL) {
    SOY_drawSetColour(g_imInfo.canvas, 0xFFFFFFFF);
    SOY_drawRectFill(g_imInfo.canvas,
        rx, ry,
        rx + SOY_drawTextWidthMono(g_imInfo.font, label) + 6, ry + 16);     
    SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
    SOY_drawRect(g_imInfo.canvas,
        rx, ry,
        rx + SOY_drawTextWidthMono(g_imInfo.font, label) + 6, ry + 16, 1);     
    SOY_drawTextMono(g_imInfo.canvas, g_imInfo.font, rx + 2, ry + 2, label);
  }
  return ret;
}

int32 SOYIM_plot2(int8* label, real32* data, uint32 width, uint32 height) {
  int32 x, y;
  int32 rx, ry;
  real32 nx, ny;
  int32 sx, sy;
  real32 scale = 0.0f;
  int32 winWidth = IM_STD_HEIGHT;
  int32 winHeight = IM_STD_HEIGHT;
  int32 ret = 
    SOYIM_base(label,
        winWidth, 
        winHeight, 
        0, 0, NULL, NULL, &rx, &ry);
  soyPixel bg = 0xFFFFFFFF;
  soyPixel fg = 0xFFFF00FF;
  soyPixel blend = 0;
  for(y = 0; y < width; y++) {
    for(x = 0; x < height; x++) {
      scale = SOY_MAX(scale, data[x + y*width]);
    }
  }
  for(y = 0; y < winWidth; y++) {
    for(x = 0; x < winHeight; x++) {
      nx = (real32)x / (real32)winWidth;
      ny = (real32)y / (real32)winHeight;
      sx = (int32)(nx * (real32)width); 
      sy = (int32)(ny * (real32)height); 
      blend = SOY_colourLerp(bg, fg, data[sx + sy*width] / scale);
      SOY_drawSetColour(g_imInfo.canvas, blend);
      SOY_drawPixel(g_imInfo.canvas, rx + x, ry + y);
    }
  }
  SOY_drawSetColour(g_imInfo.canvas, fg);
  SOY_drawRect(g_imInfo.canvas, rx, ry, rx + winWidth, ry + winHeight, 1);
  return ret;
}

int32 SOYIM_image(int8* label, uint32* data, uint32 width, uint32 height) {
  int32 x, y;
  int32 rx, ry;
  real32 nx, ny;
  int32 sx, sy;
  real32 aspect = (real32)width / (real32)height;
  int32 winWidth = (int32)((real32)IM_STD_HEIGHT * aspect);
  int32 winHeight = IM_STD_HEIGHT;
  int32 ret = 
    SOYIM_base(label,
        winWidth, 
        winHeight, 
        0, 0, NULL, NULL, &rx, &ry);
  for(y = 0; y < winHeight; y++) {
    for(x = 0; x < winWidth; x++) {
      nx = (real32)x / (real32)winWidth;
      ny = (real32)y / (real32)winHeight;
      sx = (int32)(nx * (real32)width); 
      sy = (int32)(ny * (real32)height); 
      SOY_drawSetColour(g_imInfo.canvas, data[sx + sy*width]);
      SOY_drawPixel(g_imInfo.canvas, rx + x, ry + y);
    }
  }
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
  SOY_drawRect(g_imInfo.canvas, rx, ry, rx + winWidth, ry + winHeight, 1);
  return ret;
}

int32 SOYIM_checkbox(int8* label, int32* value) {
  int32 rx, ry;
  int32 dtw = SOYIM_buttonWidth(SOY_drawTextWidthMono(g_imInfo.font, label));
  int32 w = IM_STD_WIDTH;
  int32 h = IM_STD_WIDTH;
  int32 ret = SOYIM_base(label, w, h, dtw, 0, NULL, NULL, &rx, &ry);
  SOY_drawTextMono(g_imInfo.canvas,
      g_imInfo.font, rx + w + 4, ry, label);
  if(*value) {
    SOY_drawRectFill(g_imInfo.canvas,
        rx + 2, ry + 2, rx + w - 1, ry + h - 1);
  }
  if(ret) { *value = !(*value); }
  return TRUE;
}

int32 SOYIM_viewport(int8* label,
    uint32* data, uint32 width, uint32 height) {
  int32 x, y;
  int32 rx, ry;
  real32 nx, ny;
  int32 sx, sy;
  int32 pad = g_imInfo.pad;
  int32 winWidth = (g_imInfo.menuX2 - pad) - (g_imInfo.menuX1 + pad);
  int32 winHeight = (g_imInfo.menuY2 - pad) - (g_imInfo.menuY1 + pad);
  int32 ret = 
    SOYIM_base(label,
        winWidth, 
        winHeight, 
        0, 0, NULL, NULL, &rx, &ry);
#if 1
  for(y = 0; y < winHeight; y++) {
    for(x = 0; x < winWidth; x++) {
      nx = (real32)x / (real32)winWidth;
      ny = (real32)y / (real32)winHeight;
      sx = (int32)(nx * (real32)width); 
      sy = (int32)(ny * (real32)height); 
      SOY_drawSetColour(g_imInfo.canvas, data[sx + sy*width]);
      SOY_drawPixel(g_imInfo.canvas, rx + x, ry + y);
    }
  }
#endif
#if 1
  SOY_drawSetColour(g_imInfo.canvas, 0xFFFF00FF);
  SOY_drawRect(g_imInfo.canvas, rx, ry, rx + winWidth, ry + winHeight, 1);
#endif
  return ret;
}


#endif /* SOY_IMMEDIATE_H */
