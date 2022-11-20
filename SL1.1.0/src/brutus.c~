#include "soy.h"
#include "soyim.h"
#include "soyrect.h"

#define B_MAX_SONGS 8
#define B_MAX_TEXT 256
#define B_MAX_INDICES 256
#define B_MAX_PATTERNS 128
#define B_MAX_TRACKS 16
#define B_MAX_NODES 256*B_MAX_TRACKS

typedef struct tag_bNode {
  uint32 dataLow;
  uint32 dataHigh;
} bNode;

typedef struct tag_bPattern {
  uint32 tracks;
  uint32 division;
  uint32 beats;
  uint32 bars;
  uint32 ID;
  bNode nodes[B_MAX_NODES];
} bPattern;

typedef struct tag_bSong {
  int8* text;
  int32 numIndices;
  int32 numPatterns;
  int32 sizePattern;
  uint32 indices[B_MAX_INDICES];
  bPattern patterns[B_MAX_PATTERNS];
  bNode* nodes;
} bSong;

typedef struct tag_bTracker {
  bSong songs[B_MAX_SONGS];
  uint32 songIndex;
} bTracker;

/* pattern *****************************************************************/

int32 BRUT_patternInit(bPattern* pattern,
    int32 tracks, int32 divisions, int32 beats, int32 bars, int32 id) {
  pattern->tracks = tracks;
  pattern->division = divisions;
  pattern->beats = beats;
  pattern->bars = bars;
  pattern->ID = id;
  SOY_memorySet(pattern->nodes, 0, sizeof(bNode)*B_MAX_NODES);
  return TRUE;
}

int32 BRUT_songInit(bSong* song) {
  SOY_memorySet(song, 0, sizeof(bSong));
  return TRUE;
}

/* tracker *****************************************************************/

int32 BRUT_trackerInit(bTracker* tracker) {
  int32 i;
  tracker->songIndex = 0;
  for(i = 0; i < B_MAX_SONGS; i++) {
    BRUT_songInit(&tracker->songs[i]);
  }
  return TRUE;
}

int32 BRUT_trackerUpdate(soyApp* app, bTracker* tracker, real64 dt) {

  return TRUE;
}

/* drawing *****************************************************************/

int32 BRUT_buttonProc(imInfo* info, void* args) {
  SOY_LOG("Hello retard\n");
  return TRUE;
}

#define MAX_WIDTH 8
#define MAX_SAMPLES MAX_WIDTH*MAX_WIDTH

SOY_GLOBAL uint32 g_anchorPoint = 0;
SOY_GLOBAL real32 g_time = 0.0f;
SOY_GLOBAL real32 floats[MAX_SAMPLES];
SOY_GLOBAL uint32 uints[MAX_SAMPLES];
SOY_GLOBAL int32 g_toggle[5] = { 0, 0, 0, 0, 0 };

int32 BRUT_drawTracker(soyApp* app, bTracker* tracker, real64 dt) {
  g_time += (real32)dt;
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(1));
  SOY_drawClear(app->framebuffer);

  if(SOYIM_begin(app)) {
    SOYIM_anchor(g_anchorPoint%8);
    SOYIM_padding(2);
#if 0
    if(SOYIM_beginMenu(3, 26, SOY_width(app) - 4, SOY_height(app) - 4)) {
      SOYIM_wrapMode(TRUE, TRUE);
      SOYIM_placeMode(IM_HORIZONTAL);
      SOYIM_reactMode(IM_RELEASED);
      SOYIM_button("button", BRUT_buttonProc, NULL);
      SOYIM_button("soy", BRUT_buttonProc, NULL);
      SOYIM_button("nigger", BRUT_buttonProc, NULL);
      SOYIM_button("spic", BRUT_buttonProc, NULL);
      SOYIM_button("retard", BRUT_buttonProc, NULL);
      SOYIM_button("retard", BRUT_buttonProc, NULL);
      SOYIM_button("kys", BRUT_buttonProc, NULL);
      SOYIM_button("die", BRUT_buttonProc, NULL);
      SOYIM_button("stupid", BRUT_buttonProc, NULL);
      SOYIM_button("niggerniggernigger", BRUT_buttonProc, NULL);
    }
#endif
#if 0
    if(SOYIM_beginMenu(3, 64, SOY_width(app) - 4, SOY_height(app) - 4)) {
      SOYIM_wrapMode(FALSE, FALSE);
      SOYIM_plotMode(IM_PLOT_LINES);
      SOYIM_placeMode(IM_VERTICAL);
      SOYIM_plot("data1", floats, MAX_SAMPLES);
      SOYIM_placeMode(IM_HORIZONTAL);
      SOYIM_plot2("data2", floats, MAX_WIDTH, MAX_WIDTH);
      SOYIM_plot2("data3", floats, MAX_WIDTH, MAX_WIDTH);
      SOYIM_plot2("data4", floats, MAX_WIDTH, MAX_WIDTH);
      SOYIM_plot2("data5", floats, MAX_WIDTH, MAX_WIDTH);
      SOYIM_image("image", uints, MAX_WIDTH, MAX_WIDTH - 4);
    }
#endif
#if 0
    if(SOYIM_beginMenu(3, 262, 262, SOY_height(app) - 4)) {
      SOYIM_reactMode(IM_HELD);
      SOYIM_placeMode(IM_HORIZONTAL);
      SOYIM_slider("float", &floats[0], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[1], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[2], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[3], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[4], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[5], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[6], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[7], 0.0f, 1.0f);
      SOYIM_slider("float", &floats[8], 0.0f, 1.0f);
    }
#endif
#if 0
    if(SOYIM_beginMenu(262, 262, SOY_width(app) - 4, SOY_height(app) - 4)) {
      SOYIM_wrapMode(TRUE, FALSE);
      SOYIM_placeMode(IM_HORIZONTAL);
      SOYIM_reactMode(IM_RELEASED);
      SOYIM_checkbox("kill em", &g_toggle[0]);
      SOYIM_checkbox("burn em", &g_toggle[1]);
      SOYIM_checkbox("rape em", &g_toggle[2]);
      SOYIM_checkbox("shit em", &g_toggle[3]);
      SOYIM_checkbox("fuck em", &g_toggle[4]);
    }
#endif
#if 0
    if(SOYIM_beginMenu(80, 20, g_anchorPoint)) {
      SOYIM_viewport("roach",
          g_imInfo.canvas->rgba.data,
          g_imInfo.canvas->rgba.width,
          g_imInfo.canvas->rgba.height);
    }
#endif
  }

  if(SOY_keyPressed(app, SOY_K)) {
    g_anchorPoint++;
  }

  if(SOY_keyPressed(app, SOY_J)) {
    g_anchorPoint--;
  }

  return TRUE;
}

#if 0
/* user callbacks **********************************************************/

SOY_GLOBAL bTracker g_tracker;

int32 SOY_userUpdate(soyApp* app, real64 dt) {
  BRUT_trackerUpdate(app, &g_tracker, dt);
  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  BRUT_drawTracker(app, &g_tracker, dt);
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  int32 i;
  soyMemorySector mem;
  SOY_memorySectorPartition("GUI",
      &app->memory.userMemory, &mem, Kilobytes(128));
  BRUT_trackerInit(&g_tracker);

  srand(time(NULL));
  for(i = 0; i < MAX_SAMPLES; i++) {
    uints[i] = 0xFF000000 + (rand() % 0xFFFFFF);
    uints[i] = 0xFFFFFFFF;
    floats[i] = SOY_noiseSimplexNormalize(SOY_noiseDomainWarp2D(
        SOY_noiseSimplex2D,
        (real32)(i%MAX_WIDTH)*0.01f,
        (real32)(i/MAX_WIDTH)*0.01f,
        0.3f, 0.4f, 0.3f, 1.0f, 0.5f, 5, 3));
  }

  SOYIM_init(mem.base, mem.size);
  return TRUE;
}

int32 SOY_userStop(soyApp* app) {
  return TRUE;
}

int32 main() {
  soyApp app;
  SOY_LOG1("sizeof song: %f\n", (real32)(sizeof(bSong))/1024.0f/1024.0f);
  SOY_create(&app, "soyIM", 640, 480);
  return TRUE;
}

#endif
int32 SOY_userUpdate(soyApp* app, real64 dt) {
  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  int32 x, y;
  real32 rx, ry;
  int32 tx, ty;
  SOY_drawSetColour(app->framebuffer, 0xFF000000);
  SOY_drawClear(app->framebuffer);
  SOY_drawSetColour(app->framebuffer, 0xFFFFFFFF);
  for(y = 0; y < 100; y++) {
    ty = y*2;
    SOY_drawLine(app->framebuffer, 0, y*10, SOY_width(app), ty*10);
  }
  for(x = 0; x < 100; x++) {
    tx = x*4;
    SOY_drawLine(app->framebuffer, x*10, 0, tx*10, SOY_height(app));
  }
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
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

