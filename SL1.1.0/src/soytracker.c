#define SOY_DEBUG
#define SOY_NO_3D
#define SOY_NO_HARDWARE
#define SOY_NO_MATH
#include "soy.h"

/* soytracker **************************************************************/

#define TRACKER_WIDTH 640*2
#define TRACKER_HEIGHT 480*2

#define TRACKER_TITLE "Brutus Tracker"
#define AUTHOR_TITLE "PRODUCED BY CHIENSOFT 2022"
#define RELEASE_VERSION 0
#define MAJOR_VERSION 1
#define MINOR_VERSION 8

#define MAX_SAMPLES 64
#define MAX_CHANNELS 16
#define MAX_INSTRUMENTS 256
#define MAX_NODES 64
#define MAX_PATTERNS 64
#define MAX_TRACK 256

#define MAX_CHANNEL_BUFFER 48000 / 8

#define MAX_AMP 32767
#define MIN_AMP -32768

#define MAX_NOTES 112

#define TRACKER_DEBUG

static int8* NOTES[MAX_NOTES] = {
  "Ab", "A ", "Bb", "B ", "C ", "Db", "D ", "Eb", "E ", "F ", "Gb", "G "
};

#define KEYMAP_SIZE 256

static int32 KEYMAP[KEYMAP_SIZE] = {-1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 35,
-1, 17, 19, -1, 22, 24, 26, -1, 29, -1, -1, -1,
-1, -1, -1, -1,  0,  8,  4, -1, 20,  5,  7, -1,
28, 10, 12, 14, 11,  9, 30, 32, 16, 21,  2, 23,
27,  6, 18,  3,  1, 25, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 13, -1, 15, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1,
};

typedef enum enum_paletteNames {
  PAL_LIGHTEST,
  PAL_LIGHT,
  PAL_DARK,
  PAL_DARKEST,
  PAL_BLACK,
  PAL_BACKGROUND,
  PAL_TEXT_A,
  PAL_TEXT_B,
  PAL_GRAD_A,
  PAL_GRAD_B,
  PAL_GRAD_C,
  PAL_GRAD_D,

  PAL_CHANNEL_TEXT_A,
  PAL_CHANNEL_TEXT_B,
  PAL_CHANNEL_BG,
  PAL_CHANNEL_GRADA,
  PAL_CHANNEL_GRADB,
  PAL_CHANNEL_GRADC,
  PAL_CHANNEL_GRADD,
  PAL_TRACK_HIGHLIGHT,
  PAL_TRACK_PLAYCURSOR,
  PAL_TRACK_BAR,
  PAL_TRACK_TEXT_A,
  PAL_TRACK_TEXT_B,
  PAL_TRACK_TEXT_C,
  PAL_TRACK_TEXT_D,
  PAL_SPECTRO
} paletteNames;

SOY_GLOBAL soyPixel PALETTE_A[32] = {
  0xFFFFFFFF, /* LIGHTEST */
  0xFFD4D0C8, /* LIGHT */
  0xFF808080, /* DARK */
  0xFF404040, /* DARKEST */
  0xFF000000, /* BLACK */
  0xFFFFFFFF, /* BACKGROUND */
  0xFFFFFFFF, /* TEXT A */
  0xFFD4D0C8, /* TEXT B */
  0xFF050668, /* GRAD A */
  0xFFA4CCF4, /* GRAD B */
  0xFF808080, /* GRAD C */
  0xFFC0C0C0, /* GRAD D */
  0xFF000000, /* CHANNEL TEXT A */
  0xFF505050, /* CHANNEL TEXT B */
  0xFF000000, /* CHANNEL BG */
  0xFFA4CCF4, /* CHANNEL GRAD A */
  0xFF050668, /* CHANNEL GRAD B */
  0xFFD4D0C8, /* CHANNEL GRAD C */
  0xFF808080, /* CHANNEL GRAD D */
  0xFF202020, /* TRACK HIGHLIGHT */
  0xFFEEEEEE, /* TRACK PLAYCURSOR */
  0xFFE1DDD4, /* TRACK BAR */
  0xFF202020, /* TRACK TEXT A */
  0xFF808080, /* TRACK TEXT B */
  0xFF000000, /* TRACK TEXT C */
  0xFF000000, /* TRACK TEXT D */
  0xFF00DD00  /* SPECTROGRAPH */
};

SOY_GLOBAL soyPixel PALETTE_B[32] = {
  0xFF424242, /* LIGHTEST */
  0xFF262626, /* LIGHT */
  0xFF141414, /* DARK */
  0xFF040404, /* DARKEST */
  0xFF808080, /* BLACK */
  0xFFFFFFFF, /* BACKGROUND */
  0xFFFFFFFF, /* TEXT A */
  0xFFAAAAAA, /* TEXT B */
  0xFF262626, /* GRAD A */
  0xFF262626, /* GRAD B */
  0xFF262626, /* GRAD C */
  0xFF262626, /* GRAD D */
  0xFF808080, /* CHANNEL TEXT A */
  0xFF505050, /* CHANNEL TEXT B */
  0xFF000000, /* CHANNEL BG */
  0xFF161616, /* CHANNEL GRAD A */
  0xFF202020, /* CHANNEL GRAD B */
  0xFF262626, /* CHANNEL GRAD C */
  0xFF282828, /* CHANNEL GRAD D */
  0xFF000000, /* TRACK HIGHLIGHT */
  0xFF161616, /* TRACK PLAYCURSOR */
  0xFF151515, /* TRACK BAR */
  0xFF808080, /* TRACK TEXT A */
  0xFF505050, /* TRACK TEXT B */
  0xFFFFFFFF, /* TRACK TEXT C */
  0xFF808000, /* TRACK TEXT D */
  0xFF008888  /* SPECTROGRAPH */
};

SOY_GLOBAL soyPixel PALETTE_C[32] = {
  0xFFFFCC44, /* LIGHTEST */
  0xFFFFAA22, /* LIGHT */
  0xFFBB6611, /* DARK */
  0xFF996600, /* DARKEST */
  0xFF884400, /* BLACK */
  0xFFFFFFFF, /* BACKGROUND */
  0xFFFFFFFF, /* TEXT A */
  0xFFAAAAAA, /* TEXT B */
  0xFFBB6611, /* GRAD A */
  0xFFFFAA22, /* GRAD B */
  0xFFBB6611, /* GRAD C */
  0xFFFFAA22, /* GRAD D */
  0xFF000000, /* CHANNEL TEXT A */
  0xFF550000, /* CHANNEL TEXT B */
  0xFFFFAA22, /* CHANNEL BG */
  0xFFFFBB44, /* CHANNEL GRAD A */
  0xFFFFAA22, /* CHANNEL GRAD B */
  0xFFFFAA22, /* CHANNEL GRAD C */
  0xFFBB6611, /* CHANNEL GRAD D */
  0xFFFFDD88, /* TRACK HIGHLIGHT */
  0xFFFFCC44, /* TRACK PLAYCURSOR */
  0xFFFFCC33, /* TRACK BAR */
  0xFF804000, /* TRACK TEXT A */
  0xFFAA4400, /* TRACK TEXT B */
  0xFF000000, /* TRACK TEXT C */
  0xFF804000, /* TRACK TEXT D */
  0xFFFFFFFF  /* SPECTROGRAPH */
};

SOY_GLOBAL soyPixel PALETTE_D[32] = {
  0xFF88BBAA, /* LIGHTEST */
  0xFF44AA99, /* LIGHT */
  0xFF339988, /* DARK */
  0xFF228877, /* DARKEST */
  0xFF004433, /* BLACK */
  0xFFFFFFFF, /* BACKGROUND */
  0xFFAADDDD, /* TEXT A */
  0xFF88BBBB, /* TEXT B */
  0xFF339988, /* GRAD A */
  0xFF88BBAA, /* GRAD B */
  0xFF339988, /* GRAD C */
  0xFF228877, /* GRAD D */
  0xFFFFFFFF, /* CHANNEL TEXT A */
  0xFFAADDDD, /* CHANNEL TEXT B */
  0xFF88BBAA, /* CHANNEL BG */
  0xFF228877, /* CHANNEL GRAD A */
  0xFF006655, /* CHANNEL GRAD B */
  0xFF44AA99, /* CHANNEL GRAD C */
  0xFF228877, /* CHANNEL GRAD D */
  0xFFAAEEDD, /* TRACK HIGHLIGHT */
  0xFF88CCBB, /* TRACK PLAYCURSOR */
  0xFF88CCAA, /* TRACK BAR */
  0xFF004422, /* TRACK TEXT A */
  0xFF226655, /* TRACK TEXT B */
  0xFF004422, /* TRACK TEXT C */
  0xFF004422, /* TRACK TEXT D */
  0xFFFFFFFF  /* SPECTROGRAPH */
};

soyMemorySector loadMemory;
soyMemorySector soundMemory;
soyMemorySector tempSampleMemory;

#define MAX_SAMPLE_SIZE 48000*20
#define MAX_SAMPLE_LABEL 16

#if 0

- Channel
          - Volume      - Pan Left/Right

          - Instrument  - Sampler
                        - Synthesizer

          - Effects     - Low Pass    - Cutof, Order, Mix
                        - High Pass   - Cutof, Order, Mix
                        - Band Pass   - Cutof, Order, Mix
                        - Delay       - Milis, Decay, Mix
                        - Reverb      - Decay, Diffusion, Mix
                        - Compressor  - Ratio, Gain, Mix
#endif


/* filters *****************************************************************/

#define ST_BW_MAX_ORDER 8

typedef struct tag_soyFilter {
  int32 n;
  real32 a[ST_BW_MAX_ORDER];
  real32 d1[ST_BW_MAX_ORDER];
  real32 d2[ST_BW_MAX_ORDER];
  real32 w0[ST_BW_MAX_ORDER];
  real32 w1[ST_BW_MAX_ORDER];
  real32 w2[ST_BW_MAX_ORDER];
} soyFilter;

int32 ST_filterInit(soyFilter* filter) {
  SOY_memorySet(filter->a, 0, ST_BW_MAX_ORDER*sizeof(real32));
  SOY_memorySet(filter->d1, 0, ST_BW_MAX_ORDER*sizeof(real32));
  SOY_memorySet(filter->d2, 0, ST_BW_MAX_ORDER*sizeof(real32));
  SOY_memorySet(filter->w0, 0, ST_BW_MAX_ORDER*sizeof(real32));
  SOY_memorySet(filter->w1, 0, ST_BW_MAX_ORDER*sizeof(real32));
  SOY_memorySet(filter->w2, 0, ST_BW_MAX_ORDER*sizeof(real32));
  filter->n = 0;
  return TRUE;
}

int32 ST_filterInitLowPass(soyFilter* filter,
    int32 order, real32 s, real32 f) {
  real32 r;
  int32 i;
  real32 a = tan(SOY_PI * f/s);
  real32 a2 = a * a;
  ST_filterInit(filter);
  filter->n = order/2;
  SOY_ASSERT(filter->n < ST_BW_MAX_ORDER);  
  for(i = 0; i < filter->n; i++){
    r = sin((real32)SOY_PI*(2.0f*i+1.0f)/(4.0f*filter->n));
    s = a2 + 2.0f*a*r + 1.0f;
    filter->a[i] = a2/s;
    filter->d1[i] = 2.0f*(1.0f-a2)/s;
    filter->d2[i] = -(a2 - 2.0f*a*r + 1.0f)/s;
  }
  return TRUE;
}

int32 ST_filterInitHighPass(soyFilter* filter,
    int32 order, real32 s, real32 f) {  
  real32 r;
  int32 i;  
  real32 a = tan(SOY_PI * f/s);
  real32 a2 = a * a;
  ST_filterInit(filter);
  filter->n = order/2;
  SOY_ASSERT(filter->n < ST_BW_MAX_ORDER);  
  for(i = 0; i < filter->n; i++){
    r = sin((real32)SOY_PI*(2.0f*i+1.0f)/(4.0f*filter->n));
    s = a2 + 2.0f*a*r + 1.0f;
    filter->a[i] = 1.0f/s;
    filter->d1[i] = 2.0f*(1.0f-a2)/s;
    filter->d2[i] = -(a2 - 2.0f*a*r + 1.0f)/s;
  }
  return TRUE;
}

real32 ST_filterLowPass(soyFilter* f, real32 x) {
  int32 i;
  for(i = 0; i < f->n; i++){
    f->w0[i] = f->d1[i]*f->w1[i] + f->d2[i]*f->w2[i] + x;
    x = f->a[i]*(f->w0[i] + 2.0f*f->w1[i] + f->w2[i]);
    f->w2[i] = f->w1[i];
    f->w1[i] = f->w0[i];
  }
  return x;
}

real32 ST_filterHighPass(soyFilter* f, real32 x) {
  int32 i;
  for(i = 0; i < f->n; i++){
    f->w0[i] = f->d1[i]*f->w1[i] + f->d2[i]*f->w2[i] + x;
    x = f->a[i]*(f->w0[i] - 2.0f*f->w1[i] + f->w2[i]);
    f->w2[i] = f->w1[i];
    f->w1[i] = f->w0[i];
  }
  return x;
}

typedef struct tag_soyDelay {
  int32 cursor;
  int32 delaySamples;
  int32 maxSize;
  real32 decay;
  real32* memory;
} soyDelay;

soyDelay ST_delay(real32* memory,
    int32 memSize, real32 sampleRate, real32 delay, real32 decay) {
  soyDelay ret;
  ret.cursor = 0;
  ret.memory = memory;
  ret.maxSize = memSize;
  ret.delaySamples = (int32)(sampleRate*0.001f*delay);
  ret.decay = decay;
  SOY_memorySet(memory, 0, memSize*sizeof(int16));
  return ret;
}

real32 ST_delayUpdate(soyDelay* delay, real32 input) {
  real32 out;
  int32 delayCursor = delay->cursor - delay->delaySamples;
  if(delayCursor < 0) { delayCursor += delay->maxSize; }
  out = input + delay->memory[delayCursor]*delay->decay;
  delay->memory[delay->cursor++] = out;
  delay->cursor %= delay->maxSize;
  return out;
}

soyDelay g_delay;
int32 g_filterTestInit = 0;
real32 g_delayMemory[MAX_SAMPLE_SIZE];

int32 ST_filtersInit() {
  SOY_memorySet(g_delayMemory, 0, MAX_SAMPLE_SIZE*sizeof(real32));
  g_delay = ST_delay(g_delayMemory, MAX_SAMPLE_SIZE, 48000.0f, 500.0f, 0.4f);
  return TRUE;
}

real32 ST_filterTest(real32 in) {
  if(!g_filterTestInit) {
    ST_filtersInit();
    g_filterTestInit = TRUE;
  }
  return ST_delayUpdate(&g_delay, in);
}

/* effects *****************************************************************/

#define MAX_EFFECT_SLOTS 8
#define MAX_FILTER_LINES 4
#define MAX_DELAY_LINES 8
#define MAX_DELAY_LENGTH 48000

typedef struct tag_soyDelayLine {
  int16 memory[MAX_DELAY_LENGTH];
  int32 used;
} soyDelayLine;

SOY_GLOBAL soyDelayLine g_delayLines[MAX_DELAY_LINES*MAX_EFFECT_SLOTS];
SOY_GLOBAL soyFilter g_filterLines[MAX_FILTER_LINES*MAX_EFFECT_SLOTS];

typedef struct tag_soyEffect {
  int8* label;
  soyDelayLine* delayLines;
  soyFilter* filterLines;
} soyEffect;

typedef struct tag_soyEffectRack {
  soyEffect slots[MAX_EFFECT_SLOTS];
} soyEffectRack;

int32 ST_delayLineInit(soyDelayLine* line) {
  line->used = FALSE;
  SOY_memorySet(line->memory, 0, MAX_DELAY_LENGTH*sizeof(int16));
  return TRUE;
}

int32 ST_effectInit(soyEffect* effect, int8* label, int32 slotID) {
  int32 j;
  effect->label = label;
  effect->delayLines = &g_delayLines[(slotID)*MAX_DELAY_LINES];
  effect->filterLines = &g_filterLines[(slotID)*MAX_FILTER_LINES];
  for(j = 0; j < MAX_DELAY_LINES; j++) {
    ST_delayLineInit(&effect->delayLines[j]);
  }
  for(j = 0; j < MAX_FILTER_LINES; j++) {
    ST_filterInit(&effect->filterLines[j]);
  }
  return TRUE;
}

int32 ST_effectRackInit(soyEffectRack* rack) {
  int32 i;
  for(i = 0; i < MAX_EFFECT_SLOTS; i++) {
    ST_effectInit(&rack->slots[i], "NONE", i);
  }
  return TRUE;
}

int32 ST_effectRackInitAll(soyEffectRack* racks) {
  int32 i;
  for(i = 0; i < MAX_CHANNELS; i++) {
    ST_effectRackInit(&racks[i]);
  }
  return TRUE;
}

SOY_GLOBAL soyEffectRack g_effectRacks[MAX_CHANNELS];

/* tracker *****************************************************************/

typedef struct tag_soyTrackerSample {
  size_t size;
  size_t length;
  uint32 cursor;
  int8 label[MAX_SAMPLE_LABEL];
  int16 data[MAX_SAMPLE_SIZE];
} soyTrackerSample;

typedef struct tag_soyInstrument {
  real32 volumeL;
  real32 volumeR;
  real32 weight;
  real64 pitch;
  int32 cursor;
  int32 index;
  int32 playing;

  int32 loop;
  int32 sampleStart;
  int32 sampleEnd;
  int32 repeatStart;
  int32 repeatEnd;

  int32 sampleIndex;
} soyInstrument;

typedef struct tag_soyChannel {
  soyInstrument soundPrev;
  soyInstrument soundCur;
  int32 interpolation;
  real32 volume;
  real32 pan;
  int32 ID;
} soyChannel;

typedef enum enum_soyTrackerNodeFlags {
  NODE_EMPTY = 0,
  NODE_NOTE = 2,
  NODE_INSTRUMENT = 4,
  NODE_VOLUME = 8,
  NODE_CONTROL = 16,
  NODE_PARAM = 32
} soyTrackerNodeFlags;

typedef enum enum_soyTrackerState {
  TRACKER_MAIN = 0,
  TRACKER_TOOLBAR_OPEN = 1
} soyTrackerState;

typedef enum enum_soyMenuState {
  MENU_INFO,
  MENU_SONG,
  MENU_DISK,
  MENU_FREQ,
  MENU_CONF,
  MENU_LOG,
  MENU_HELP
} soyMenuState;

typedef enum enum_soyToolbarState {
  TOOLBAR_MIXER,
  TOOLBAR_DISK,
  TOOLBAR_SMPEDIT,
  TOOLBAR_INSEDIT,
  TOOLBAR_VISUAL,
  TOOLBAR_CONFIG
} soyToolbarState;

typedef struct tag_soyTrackerNode {
  uint8 controls[5];
  uint32 flags;
} soyTrackerNode;

typedef struct tag_soyPattern {
  soyTrackerNode nodes[MAX_CHANNELS][MAX_NODES];
  int32 nodeCount;
  int32 channelCount;
} soyPattern;

typedef struct tag_soyTrackNode soyTrackNode;

struct tag_soyTrackNode {
  int32 patternIndex;
  int32 deleted;
  soyTrackNode* prev;
  soyTrackNode* next;
};

typedef struct tag_soyTrackList {
  soyTrackNode trackNodes[MAX_TRACK];
  soyTrackNode* current;
  soyTrackNode* first;
  soyTrackNode* last;
  int32 count;
} soyTrackList;

typedef struct tag_soyTracker {
  soyPattern patterns[MAX_PATTERNS];
  soyTrackerSample samples[MAX_SAMPLES];
  soyChannel channels[MAX_CHANNELS];
  soyChannel* mix[MAX_CHANNELS];
  soyInstrument instruments[MAX_INSTRUMENTS];
  soyTrackList trackList;
  soyTrackerState state;
  soyTrackerNode nodeCopy;

  int32 menuX;
  int32 menuY;

  int32 instCount;
  int32 sampleCount;
  int32 sampleBufferSize;
  int32 fftSize;
  int32 activeSounds;

  int32 sampleRate;

  int32 trackLength;

  real64 audioCursor;
  int32 trackCursor;
  int32 playCursor;
  int32 tickCursor;
  int64 bufferCursor;

  real32 masterVolume;
  int32 playing;
  int32 loopPattern;
  int32 tempo;
  int32 ticks;

  real64 realTempo;
  real64 lastDelta;

  soyFont* font;
  soyFont* fontSmall;
  soyFont* fontBold;

  int32 mouseX;
  int32 mouseY;
  int32 mouseLeft;
  int32 mouseRight;
  int32 mouseMiddle;

  soyRect clientRect;
  soyRect toolbarRectLeft;
  soyRect toolbarRectRight;
  soyRect editorRect;

  soyRect toolbarToggleButtonLeft;
  soyRect toolbarToggleButtonRight;
  soyRect toolbarButtons[16];
} soyTracker;

SOY_GLOBAL soyTracker g_tracker;

SOY_GLOBAL soyInstrument g_testInstrument;
SOY_GLOBAL real32 g_sampleBuffersL[MAX_CHANNELS][MAX_CHANNEL_BUFFER];
SOY_GLOBAL real32 g_sampleBuffersR[MAX_CHANNELS][MAX_CHANNEL_BUFFER];
SOY_GLOBAL real32 g_masterBufferL[MAX_CHANNEL_BUFFER];
SOY_GLOBAL real32 g_masterBufferR[MAX_CHANNEL_BUFFER];

soyTrackerNode ST_node(
    int8 note, uint8 instrument, uint8 volume, uint8 control, uint8 param,
    soyTrackerNodeFlags flags) {
  soyTrackerNode ret;
  ret.controls[0] = note;
  ret.controls[1] = instrument;
  ret.controls[2] = volume;
  ret.controls[3] = control;
  ret.controls[4] = param;
  ret.flags = flags;
  return ret;
}

soyTrackNode ST_trackNode(int32 index,
    soyTrackNode* prev, soyTrackNode* next) {
  soyTrackNode ret;
  ret.patternIndex = index;
  ret.next = next;
  ret.prev = prev;
  ret.deleted = TRUE;
  return ret;
}

int32 ST_trackListInit(soyTrackList* list) {
  int32 i;
  for(i = 0; i < MAX_TRACK; i++) {
    list->trackNodes[i] = ST_trackNode(0, NULL, NULL);
  }
  list->count = 1;
  list->trackNodes[0].deleted = FALSE;
  list->first = &list->trackNodes[0];
  list->last = &list->trackNodes[0];
  list->current = list->first;
  return TRUE;
}

int32 ST_sampleInit(soyTrackerSample* sample) {
  SOY_memorySet(sample->data, 0, MAX_SAMPLE_SIZE*sizeof(int16));
  SOY_memorySet(sample->label, 0, MAX_SAMPLE_LABEL*sizeof(int8));
  sample->length = 0;
  sample->size = sizeof(soyTrackerSample);
  sample->cursor = 0;
  return TRUE;
}

soyInstrument ST_instrument(int32 sampleIndex, int32 start, int32 end) {
  soyInstrument ret;
  ret.sampleIndex = sampleIndex;
  ret.sampleEnd = end;
  ret.sampleStart = start;
  ret.repeatStart = 0;
  ret.repeatEnd = end;
  ret.weight = 1.0f;
  ret.volumeL = 1.0f;
  ret.volumeR = 1.0f;
  ret.cursor = 0;
  ret.pitch = 0.0;
  ret.playing = FALSE;
  ret.loop = FALSE;
  return ret;
}

int32 ST_channelInit(soyChannel* channel, int32 id) {
  channel->interpolation = TRUE;
  channel->soundPrev = ST_instrument(0, 0, 0);
  channel->soundCur = ST_instrument(0, 0, 0);
  channel->volume = 0.5f;
  channel->pan = 0.0f;
  channel->ID = id;
  return TRUE;
}

int32 ST_patternInit(soyPattern* pattern) {
  int32 i, j;
  pattern->nodeCount = MAX_NODES;
  pattern->channelCount = MAX_CHANNELS;
  for(i = 0; i < MAX_CHANNELS; i++) {
    for(j = 0; j < MAX_NODES; j++) {
      pattern->nodes[i][j] = ST_node(0, 0, 0, 0, 0, 0);
    }
  }
  return TRUE;
}

int32 ST_trackerInit(soyTracker* tracker, int32 sampleRate) {
  int32 i;
  tracker->playing = FALSE;
  tracker->loopPattern = TRUE;
  tracker->state = TRACKER_TOOLBAR_OPEN;
  tracker->mouseX = 0;
  tracker->mouseY = 0;
  tracker->mouseLeft = FALSE;
  tracker->mouseRight = FALSE;
  tracker->mouseMiddle = FALSE;
  tracker->tempo = 120;
  tracker->ticks = 6;
  tracker->trackCursor = 0;
  tracker->tickCursor = 0;
  tracker->playCursor = 0;
  tracker->bufferCursor = 0;
  tracker->masterVolume = 0.5f;
  tracker->audioCursor = 0.0;
  tracker->sampleRate = sampleRate;
  tracker->instCount = 0;
  tracker->sampleCount = 0;
  tracker->trackLength = 1;
  tracker->realTempo = 0.0;
  tracker->lastDelta = 0.0;
  tracker->menuX = 0;
  tracker->menuY = 0;

  tracker->clientRect = SOY_rectZero();
  tracker->toolbarRectLeft = SOY_rectZero();
  tracker->toolbarRectRight = SOY_rectZero();
  tracker->editorRect = SOY_rectZero();
  tracker->activeSounds = 0;
  tracker->nodeCopy = ST_node(0, 0, 0, 0, 0, 0);
  tracker->sampleBufferSize = MAX_CHANNEL_BUFFER;
  tracker->fftSize = 1024*4;

  ST_trackListInit(&tracker->trackList);

  for(i = 0; i < 16; i++) {
    tracker->toolbarButtons[i] = SOY_rectBase(NULL);
  }

  for(i = 0; i < MAX_CHANNELS; i++) {
    ST_channelInit(&tracker->channels[i], i);
    tracker->mix[i] = NULL;
  }

  for(i = 0; i < MAX_SAMPLES; i++) {
    ST_sampleInit(&tracker->samples[i]);
  }

  for(i = 0; i < MAX_INSTRUMENTS; i++) {
    tracker->instruments[i] = ST_instrument(0, 0, 0);
  }

  for(i = 0; i < MAX_PATTERNS; i++) {
    ST_patternInit(&tracker->patterns[i]);
  }
  return TRUE;
}

/* files *******************************************************************/


int32 ST_loadRAW(soyTrackerSample* sample, int8* filename) {
  size_t fLen;
  int32 i = 0;
  int32 stride = sizeof(int16);
  FILE* file = SOY_fileOpen(filename, "rb");
  SOY_LOG1("Loading RAW audio: %s\n", filename);
  if(!file) { SOY_LOG("Error opening file\n"); return FALSE; }
  fLen = SOY_fileSize(file);
  if(fLen/stride >= MAX_SAMPLE_SIZE) {
    SOY_LOG1("File too large: %s", filename);
    return FALSE;
  }

  ST_sampleInit(sample);

  fread(sample->data, fLen, 1, file);
  SOY_fileClose(file);

  sample->length = fLen/stride;
  while(filename[i] != '\0' &&
        filename[i] != '.' &&
        i < MAX_SAMPLE_LABEL - 1) {
    sample->label[i] = filename[i];
    i++;
  }
  sample->label[i] = '\0';
  return TRUE;
}



int32 ST_setInstrument(soyTracker* tracker, int32 index, int32 sampleIndex) {
  int32 len = tracker->samples[sampleIndex].length;
  tracker->instruments[index%MAX_INSTRUMENTS] =
   ST_instrument(sampleIndex, 0, len);
 return TRUE;
}

int32 ST_fileCallback(soyFileData data, void* args) {
  soyTracker* tracker = (soyTracker*)args;
  if(tracker->sampleCount < MAX_SAMPLES) {
    ST_loadRAW(&tracker->samples[tracker->sampleCount], data.name);
    ST_setInstrument(&g_tracker, tracker->instCount, tracker->sampleCount);
    tracker->sampleCount++;
    tracker->instCount++;
  }
  return TRUE;
}

int32 ST_loadSoundBank(soyTracker* tracker, int8* folder) {
  SOY_listFilesInDir(folder, ST_fileCallback, tracker);
  return TRUE;
}

/* utility *****************************************************************/

int16 ST_toShort(real32 a) {
  return (int16)(SOY_MIN(SOY_MAX(a, -1.0f), 1.0f)*(real32)MAX_AMP);
}

real32 ST_toReal(int16 a) {
  return (real32)a / (real32)MAX_AMP;
}

#define FFT_MAX MAX_CHANNEL_BUFFER

SOY_GLOBAL soyComplex g_FFTBuffer[FFT_MAX];
SOY_GLOBAL soyComplex g_FFTBufferTemp[FFT_MAX];
SOY_GLOBAL real32 g_FFTBufferPers[FFT_MAX];
SOY_GLOBAL int32 g_fftInitialized = FALSE;

real32 sfmm = 0.0f;

SOY_GLOBAL int32 g_fftCursor = 0;

int32 ST_computeFFT(soyApp* app, soyTracker* tracker, int32 size) {
  int32 i = 0;
  real32 nor = 0.0f;
  real32 win = 0.0f;
  real32 value = 0.0f;
  real32 max = 0.0f;
  
  for(i = 0; i < size; i++) {
    nor = (real32)i / (real32)size;
    win = cos(nor*SOY_2PI + SOY_PI)*0.5f + 0.5f;
    g_FFTBuffer[i].real = g_masterBufferL[g_fftCursor]*win;
    g_FFTBuffer[i].imag = 0.0f;
    if(!g_fftInitialized) {
      g_FFTBufferPers[i] = 0;
      g_fftInitialized = TRUE;
    }
    g_fftCursor++;
    g_fftCursor %= MAX_CHANNEL_BUFFER;
  }
  SOY_fft(g_FFTBuffer, size, g_FFTBufferTemp);

  for(i = 0; i < size; i++) {
    value = SOY_fabs(g_FFTBuffer[i].real)/128.0f;
#if 1
    g_FFTBufferPers[i] *= 0.0f;
    if(value > g_FFTBufferPers[i]) {
      g_FFTBufferPers[i] = value;
    }
    if(g_FFTBufferPers[i] > sfmm) {
      sfmm = g_FFTBufferPers[i];
    }
    value = g_FFTBufferPers[i];
    if(value > max) { max = value; }
#endif
  }
  return TRUE;
}

real32 ST_pitchFromNote(int32 note) {
  return pow(2.0, (real64)(note-49)/12.0)*440.0;
}

real32 ST_averageAmplitude(real32* left, real32* right, int32 count) {
  int32 i;
  real32 l, r;
  real32 maxL = 0.0f;
  real32 maxR = 0.0f;
  for(i = 0; i < MAX_CHANNEL_BUFFER; i++) {
    l = SOY_fabs(left[i]);
    r = SOY_fabs(right[i]);
    if(l > maxL) { maxL = l; };
    if(r > maxR) { maxR = r; };
  }
  return (maxL + maxR) / 2.0f;
}

int32 ST_drawDecoLines(soyApp* app, int32 x1, int32 y1, int32 x2) {
  SOY_drawLine(app->framebuffer, x1, y1, x2, y1);
  SOY_drawLine(app->framebuffer, x1, y1 + 2, x2, y1 + 2);
  SOY_drawLine(app->framebuffer, x1, y1 + 4, x2, y1 + 4);
  return TRUE;
}

int32 ST_drawTextInset(soyApp* app,
    soyFont* font, int32 x, int32 y, int8* text) {
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_LIGHTEST));
  SOY_drawText(app->framebuffer, font, x + 1, y + 1, text);
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_DARKEST));
  SOY_drawText(app->framebuffer, font, x, y, text);
  return TRUE;
}

int32 ST_playNode(soyTracker* tracker,
    soyTrackerNode* node, int32 channelIndex) {
  soyChannel* channel = &tracker->channels[channelIndex];
  real32 volume = (real32)node->controls[2]/255.0f;
  int32 note = node->controls[0];
  channel->soundPrev = channel->soundCur;
  channel->soundCur = tracker->instruments[node->controls[1]];
  channel->soundCur.cursor = 0;
  channel->soundCur.volumeL = volume;
  channel->soundCur.volumeR = volume;
  channel->soundCur.pitch = ST_pitchFromNote(note)/(ST_pitchFromNote(40));
  channel->soundCur.playing = TRUE;
  return TRUE;
}

/* track list **************************************************************/

soyTrackNode* ST_trackListNew(soyTrackList* trackList) {
  int32 i;
  for(i = 0; i < MAX_TRACK; i++) {
    if(trackList->trackNodes[i].deleted) {
      trackList->trackNodes[i].deleted = FALSE;
      return &trackList->trackNodes[i];
    }
  }
  return NULL;
}

SOY_GLOBAL int32 trackListStartOffset = 0;
SOY_GLOBAL int32 trackListSelectCounter = 0;

int32 ST_trackListSelectPrev(soyTrackList* trackList) {
  if(trackList->current->prev) {
    trackList->current = trackList->current->prev;
    trackListSelectCounter--;
    if(trackListSelectCounter < trackListStartOffset) {
      trackListStartOffset--;
    }
  }
  return TRUE;
}

int32 ST_trackListSelectNext(soyTrackList* trackList) {
  if(trackList->current->next) {
    trackList->current = trackList->current->next;
    trackListSelectCounter++;
    if(trackListSelectCounter > trackListStartOffset + 39) {
      trackListStartOffset++;
    }
  }
  return TRUE;
}

int32 ST_trackListInsert(soyTrackList* trackList) {
  soyTrackNode* new = ST_trackListNew(trackList);
  if(new) {
    new->next = trackList->current->next;
    new->prev = trackList->current;
    if(trackList->current->next) {
      trackList->current->next->prev = new;
    }
    trackList->current->next = new;
    ST_trackListSelectNext(trackList);
    trackList->count++;
  } else {
    SOY_LOG("Error, track list full\n");
  }
  return TRUE;
}

int32 ST_trackListRemove(soyTrackList* trackList) {
  soyTrackNode* cur = trackList->current;
  if(!cur->prev && !cur->next) { return FALSE; }
  if(cur->prev && cur->next) {
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    trackList->current = cur->next;
  } else if(cur->prev) {
    cur->prev->next = NULL;
    ST_trackListSelectPrev(trackList);
  } else if(cur->next) {
    cur->next->prev = NULL;
    ST_trackListSelectNext(trackList);
  }
  trackList->count--;
  cur->patternIndex = 0;
  cur->next = NULL;
  cur->prev = NULL;
  cur->deleted = TRUE;
  return TRUE;
}

/* track editor ************************************************************/

typedef enum enum_soyVisualEditorState {
  EDITOR_PATTERN,
  EDITOR_SONG
} soyVisualEditorState;

typedef struct tag_soyVisualEditor {
  int32 headerHeight;
  int32 trackWidth;
  int32 labelWidth;
  int32 nodeHeight;
  int32 selectedPattern;
  int32 selectedControl;
  int32 selectedNode;
  int32 selectedTrack;
  int32 trackEnd;
  int32 trackNum;
  int32 nodeEnd;
  int32 nodeNum;
  int32 maxNodes;
  int32 maxChannels;
  int32 playCursor;
  int32 compact;
  int32 scrollEnable;
  int32 mousePressedOutside;
  soyTrackerNode nodeCopy;
  soyVisualEditorState state;
  soyFont* font;
} soyVisualEditor;

SOY_GLOBAL soyVisualEditor g_visualEditor;

int32 ST_visualEditorInit(soyVisualEditor* editor, soyFont* font) {
  editor->state = EDITOR_PATTERN;
  editor->font = font;
  editor->trackWidth = font->data.scaledDrawWidth*16 - 2;
  editor->nodeHeight = font->data.scaledDrawHeight + 2;
  editor->headerHeight = 60;
  editor->selectedPattern = 0;
  editor->selectedTrack = 0;
  editor->selectedNode = 0;
  editor->trackNum = 0;
  editor->trackEnd = 0;
  editor->nodeNum = 0;
  editor->nodeEnd = 0;
  editor->labelWidth = 32;
  editor->compact = FALSE;
  editor->maxChannels = MAX_CHANNELS;
  editor->maxNodes = MAX_NODES;
  editor->nodeCopy = ST_node(0, 0, 0, 0, 0, 0);
  editor->scrollEnable = TRUE;
  editor->mousePressedOutside = FALSE;
  return TRUE;
}

int32 ST_visualEditorResize(soyVisualEditor* editor, soyTracker* tracker) {
  int32 i = 0;
  int32 headerHeight = 0;
  int32 drawAreaW = 0;
  int32 drawAreaH = 0;
  int32 drawNumNode = 0;
  int32 drawNumTrack = 0;
  int32 labelWidth = editor->labelWidth;
  int32 posX = labelWidth;
  int32 mx = tracker->mouseX;
  int32 my = tracker->mouseY;
  int32 ml = tracker->mouseLeft;

  editor->compact =
    (tracker->editorRect.y2 - tracker->editorRect.y1 < 
     64 + editor->nodeHeight*2);
  
  headerHeight = !editor->compact ? editor->headerHeight : 10;

  drawAreaW =
    (tracker->editorRect.x2 - tracker->editorRect.x1) - labelWidth*2;
  drawAreaH =
    (tracker->editorRect.y2 - tracker->editorRect.y1) 
    - 4 - headerHeight - 10;
  drawNumTrack =
    SOY_MIN(drawAreaW / editor->trackWidth, editor->maxChannels);
  
  drawNumNode =
    SOY_MIN(drawAreaH / (editor->nodeHeight), editor->maxNodes);
  
  if(drawNumTrack <= 0) { return FALSE; }
  
  editor->trackNum = drawNumTrack;
  editor->nodeNum = drawNumNode;
  editor->playCursor = tracker->playCursor;
  
  editor->trackEnd =
    SOY_MIN(SOY_MAX(drawNumTrack, editor->trackEnd),
        editor->selectedTrack + editor->trackNum);
  if(editor->scrollEnable) {
    editor->nodeEnd =
      SOY_MIN(SOY_MAX(drawNumNode, editor->nodeEnd),
        editor->selectedNode + editor->nodeNum);
  } else {
    editor->nodeEnd =
      SOY_MIN(SOY_MAX(drawNumNode, editor->nodeEnd),
        editor->selectedNode + editor->nodeNum);
  }

  posX += tracker->editorRect.x1;
  for(i = editor->trackEnd - drawNumTrack; i < editor->trackEnd; i++) {
    if(mx > posX && mx < posX + editor->trackWidth &&
        my > tracker->editorRect.y1 &&
        my < tracker->editorRect.y2) {
      if(ml && !editor->mousePressedOutside) {
        editor->selectedTrack = i;
      }
    }
    posX += editor->trackWidth;
  }

  if(ml) { 
    if(mx < tracker->editorRect.x1 || mx > tracker->editorRect.x2 ||
        my < tracker->editorRect.y1 || my > tracker->editorRect.y2) {
      editor->mousePressedOutside = TRUE;
    }
  } else {
    editor->mousePressedOutside = FALSE;
  }

  return TRUE;
}

int32 ST_visualEditorMoveTo(soyVisualEditor* editor, int32 to) {

  editor->selectedNode = to;

  return TRUE;
}

int32 ST_visualEditorMove(soyVisualEditor* editor, int32 key) {

  if(key == SOY_UP) {
    editor->selectedNode--;
    if(editor->scrollEnable) {
      editor->nodeEnd--;
    }
  }
  if(key == SOY_DOWN) {
    editor->selectedNode++;
    if(editor->scrollEnable) {
      editor->nodeEnd++;
    }
  }

  if(key == SOY_LEFT) { editor->selectedControl--; }
  if(key == SOY_RIGHT) { editor->selectedControl++; }

  if(editor->selectedControl > 9) {
    editor->selectedTrack++;
    editor->selectedControl = 0;
  }

  if(editor->selectedControl < 0) {
    editor->selectedTrack--;
    editor->selectedControl = 9;
  }

  if(editor->selectedNode >= editor->maxNodes) {
    editor->selectedNode = 0;
    editor->nodeEnd = 1;
    if(editor->state != EDITOR_PATTERN) {
      ST_trackListSelectNext(&g_tracker.trackList);
    }
  } else if(editor->selectedNode < 0) {
    editor->selectedNode = editor->maxNodes - 1;
    editor->nodeEnd = editor->maxNodes;
    if(editor->state != EDITOR_PATTERN) {
      ST_trackListSelectPrev(&g_tracker.trackList);
    }
    if(editor->scrollEnable) {
      editor->nodeEnd += editor->nodeNum;
    }
  }

  if(editor->selectedNode >= editor->nodeEnd &&
      editor->nodeEnd <= editor->maxNodes) {
    editor->nodeEnd++;
  } else if(editor->selectedNode < editor->nodeEnd - editor->nodeNum &&
      editor->nodeEnd - editor->nodeNum > 0) {
    editor->nodeEnd--;
  }

  if(editor->selectedTrack >= editor->maxChannels) {
    editor->selectedTrack = 0;
    editor->trackEnd = 1;
  } else if(editor->selectedTrack < 0) {
    editor->selectedTrack = editor->maxChannels - 1;
    editor->trackEnd = editor->maxChannels;
  }

  if(editor->selectedTrack >= editor->trackEnd &&
      editor->trackEnd <= editor->maxChannels) {
    editor->trackEnd++;
  } else if(editor->selectedTrack < editor->trackEnd - editor->trackNum &&
      editor->trackEnd - editor->trackNum > 0) {
    editor->trackEnd--;
  }
  return TRUE;
}

int32 ST_visualEditorMoveSkip(soyVisualEditor* editor,
    int32 dir, int32 amount) {
  while(amount--) {
    ST_visualEditorMove(editor, dir);
  }
  return TRUE;
}

int32 ST_visualEditorMoveChannel(soyVisualEditor* editor, int32 dir) {
  if(dir) {
    editor->selectedTrack++;
  } else {
    editor->selectedTrack--;
  }
  if(editor->selectedTrack >= editor->maxChannels) {
    editor->selectedTrack = 0;
    editor->trackEnd = 1;
  } else if(editor->selectedTrack < 0) {
    editor->selectedTrack = editor->maxChannels - 1;
    editor->trackEnd = editor->maxChannels;
  }

  if(editor->selectedTrack >= editor->trackEnd &&
      editor->trackEnd <= editor->maxChannels) {
    editor->trackEnd++;
  } else if(editor->selectedTrack < editor->trackEnd - editor->trackNum &&
      editor->trackEnd - editor->trackNum > 0) {
    editor->trackEnd--;
  }
  return TRUE;
}

int32 ST_visualEditorSetNode(soyVisualEditor* editor, soyTrackerNode* node,
    int32 value, int32 flag, int32 control, int32 skipAmt, int32 lockMove) {
  int32 controlType = (control) ? control/2 : 0;
  int32 keyToNum = 0;
  if(value < 0x40) {
    keyToNum = value - 0x30;
  } else if(value < 0x60) {
    keyToNum = value - 0x41+10;
  } else {
    keyToNum = value - 0x60;
  }
  if(control > 1) {
    if(control%2 == 0) {
      node->controls[controlType] |= 0xF0;
      node->controls[controlType] ^= 0xF0;
      node->controls[controlType] += keyToNum << 4;
    } else {
      node->controls[controlType] |= 0x0F;
      node->controls[controlType] ^= 0x0F;
      node->controls[controlType] += keyToNum;
    }
    if(editor->selectedControl%2) {
      if(!lockMove) {
        ST_visualEditorMoveSkip(editor, SOY_DOWN, skipAmt);
      }
      ST_visualEditorMove(editor, SOY_LEFT);
    } else {
      ST_visualEditorMove(editor, SOY_RIGHT);
    }
  } else {
    if(control == 0) {
      if(KEYMAP[value] < 0) { return FALSE; }
      node->controls[0] |= 0xFF;
      node->controls[0] ^= 0xFF;
      node->controls[0] += (KEYMAP[value]) + 3*12;
      if(!lockMove) {
        ST_visualEditorMoveSkip(editor, SOY_DOWN, skipAmt);
      }
    } else {
      if(keyToNum > 9) { return FALSE; }
      node->controls[0] = node->controls[0]%12 + (keyToNum)*12;
      if(!lockMove) {
        ST_visualEditorMoveSkip(editor, SOY_DOWN, skipAmt);
      }
    }
  }
  node->flags |= flag;
  return TRUE;
}

soyTrackerNode* ST_curNode(soyTracker* tracker, soyVisualEditor* editor) {
  return &tracker->patterns[editor->selectedPattern].
    nodes[editor->selectedTrack][editor->selectedNode];
}

int32 ST_visualEditorClearNodeControl(soyVisualEditor* editor,
    soyTrackerNode* node, int32 controlType) {
  int32 flags = node->flags;
  int32 mask = ~(1 << (controlType + 1));
  node->flags = flags & mask;
  node->controls[controlType] = 0;
  editor->nodeCopy = *node;
  return TRUE;
}

int32 ST_visualEditorClearNode(soyVisualEditor* editor,
    soyTrackerNode* node) {
  *node = ST_node(0, 0, 0, 0, 0, 0);
  ST_visualEditorMove(editor, SOY_DOWN);
  return TRUE;
}

int32 ST_visualEditorNodeUpdate(soyVisualEditor* editor,
    soyTrackerNode* node, int32 key, int32 skipAmt, int32 lockMove) {
  int32 control = editor->selectedControl;
  int32 controlType = control/2;
  if(control > 1) {
    if((
        (key >= SOY_0 && key <= SOY_F) ||
        (key >= SOY_NUMPAD0 && key <= SOY_NUMPAD9))) {
      if(!node->flags) { *node = editor->nodeCopy; }
      ST_visualEditorSetNode(editor,
          node, key, 1 << (controlType + 1), control, skipAmt, lockMove);
      editor->nodeCopy = *node;
      ST_playNode(&g_tracker, node, editor->selectedTrack);
    }
  } else {
    if(SOY_alphanumeric(key)) {
      if(!node->flags) { *node = editor->nodeCopy; }
      ST_visualEditorSetNode(editor,
          node, key, NODE_NOTE, control, skipAmt, lockMove);
      editor->nodeCopy = *node;
      ST_playNode(&g_tracker, node, editor->selectedTrack);
    }
  }
  return TRUE;
}

int32 ST_drawVisualEditorNode(soyApp* app,
    soyVisualEditor* editor, soyTrackerNode node,
    int32 xPos, int32 yPos, int32 channel, int32 index) {
  soyCanvas* canvas = app->framebuffer;
  int32 i;
  int32 origX = xPos;
  soyFont* font = editor->font;
  int32 control = editor->selectedControl;
  int32 note = node.controls[0]%12;
  int32 octave = node.controls[0]/12;
  int32 fontWidth = font->data.scaledDrawWidth;
  int32 fontHeight = font->data.scaledDrawHeight;
  int32 selectX = 0;
  int32 highlighted =
    (editor->selectedNode == index && editor->selectedTrack == channel);
  int32 offset = control > 0 ? fontWidth : 0;
  int32 selectWidth = control > 0 ? fontWidth + 1 : fontWidth*2 + 2;
  int8 hexChars[16] = "0123456789ABCDEF";
  if(font == app->fontSmall) {
    xPos += 2;
  } else {
    xPos += 6;
  }
  selectX = xPos + offset + control*fontWidth + (control/2)*2;
  if(highlighted) {
    SOY_drawSetColour(canvas, SOY_indexColour(PAL_TRACK_PLAYCURSOR));
    if(editor->selectedControl == 0) {
      SOY_drawRectFill(canvas,
        origX + 1, yPos + 1,
        selectX + selectWidth - 1,
        yPos + fontHeight + 1);
    } else if(editor->selectedControl == 9) {
      SOY_drawRectFill(canvas,
        selectX + 1, yPos + 1,
        origX + editor->trackWidth - 9,
        yPos + fontHeight + 1);
    } else {
      SOY_drawRectFill(canvas,
        selectX + 1, yPos + 1,
        selectX + selectWidth,
        yPos + fontHeight + 1);
    }
  }
  for(i = 0; i < 10; i++) {
    if(i == editor->selectedControl && highlighted) {
      SOY_drawSetColour(canvas, SOY_indexColour(PAL_TRACK_TEXT_C));
    } else if(highlighted) {
      SOY_drawSetColour(canvas, SOY_indexColour(PAL_TRACK_TEXT_B));
    } else {
      SOY_drawSetColour(canvas,
          (index%2) ?
          SOY_indexColour(PAL_TRACK_TEXT_B) :
          SOY_indexColour(PAL_TRACK_TEXT_B));
    }

    if((node.flags >> (i/2 + 1)) & 1) {
      if(i == editor->selectedControl && highlighted) {
        SOY_drawSetColour(canvas, SOY_indexColour(PAL_TRACK_TEXT_C));
      } else if(highlighted) {
         SOY_drawSetColour(canvas,
            SOY_indexColour(PAL_TRACK_TEXT_B));
      } else {
         SOY_drawSetColour(canvas,
            SOY_indexColour(PAL_TRACK_TEXT_D));
      }

      if(i == 0) {
        SOY_drawChar(canvas, font, xPos, yPos + 1, NOTES[note][0]);
        xPos += fontWidth;
        SOY_drawChar(canvas, font, xPos, yPos + 1, NOTES[note][1]);
      } else if(i == 1) {
        SOY_drawChar(canvas, font, xPos, yPos + 1, hexChars[octave]);
      } else if(i%2 == 0) {
        SOY_drawChar(canvas, font,
          xPos, yPos + 1, hexChars[(node.controls[i/2] >> 4) & 0xF]);
      } else {
        SOY_drawChar(canvas, font,
          xPos, yPos + 1, hexChars[(node.controls[i/2]) & 0xF]);
      }
    } else {
      if(i == 0) {
        SOY_drawChar(canvas, font, xPos, yPos + 1, '.');
        xPos += fontWidth;
      }
      SOY_drawChar(canvas, font, xPos, yPos + 1, '.');
    }
    xPos += fontWidth;
    if(i >= 1 && i%2) {
      xPos += 2;
    }
  }
  return TRUE;
}

int32 ST_drawVisualEditorTrack(soyApp* app, soyRect* parent,
    soyVisualEditor* editor, soyPattern** patterns,
    int32 xPos, int32 channelID, int32 channelWidth) {
  int32 i;
  int32 posY = 0;
  int32 spacing = 4;
  int32 channelHeader = editor->headerHeight;
  int32 nodeHeight = editor->nodeHeight;
  int32 nodeEnd = editor->nodeEnd;
  int32 nodeID = 0;
  soyTrackerSample* samp;
  soyRect rect =
    SOY_rect(
        xPos, parent->y1,
        xPos + channelWidth, parent->y2);
  soyPattern* pattern = patterns[1];
  soyCanvas* canvas = app->framebuffer;
  soyChannel* channel = &g_tracker.channels[channelID];
  soyPixel colBar = SOY_indexColour(PAL_TRACK_BAR);
  int8* sampleName = "EMPTY";
  if(channel->soundCur.sampleEnd) {
    samp = &g_tracker.samples[channel->soundCur.sampleIndex];
    sampleName = samp->label;
  }

  if(editor->scrollEnable) { nodeEnd -= editor->nodeNum / 2; }

  if(channelID != editor->selectedTrack) {
    SOY_drawUIRect(canvas, rect.x1, rect.y1, rect.x2, rect.y2, GUI_DARK);
    if(!editor->compact) {
      SOY_drawGradientV(canvas,
        rect.x1+4, rect.y1+4, rect.x2-4, rect.y1+channelHeader - 1,
        SOY_indexColour(PAL_CHANNEL_GRADC),
        SOY_indexColour(PAL_CHANNEL_GRADD));
    }
  } else {
    SOY_drawUIRect(canvas, rect.x1, rect.y1, rect.x2, rect.y2, GUI_INVERT);
    if(!editor->compact) {
      SOY_drawGradientV(canvas,
        rect.x1+4, rect.y1+4, rect.x2-4, rect.y1+channelHeader - 1,
        SOY_indexColour(PAL_CHANNEL_GRADA),
        SOY_indexColour(PAL_CHANNEL_GRADB));
    }
  }
  if(!editor->compact) {
    SOY_drawUIRect(canvas,
        rect.x1+3, rect.y1+3, rect.x2-3, rect.y1+channelHeader, GUI_INVERT);
    if(channelID != editor->selectedTrack) {
      SOY_drawSetColour(canvas, SOY_indexColour(PAL_CHANNEL_TEXT_B));
    } else {
      SOY_drawSetColour(canvas, SOY_indexColour(PAL_CHANNEL_TEXT_A));
    }
    if(editor->font == app->fontSmall) {
      SOY_drawTextFormatBold(canvas, app->fontRegular,
          rect.x1 + spacing + 2, rect.y1 + spacing + 2,
          "Ch. %d", channelID);
    } else {
      SOY_drawTextFormatBold(canvas, app->fontRegular,
          rect.x1 + spacing + 2, rect.y1 + spacing + 2,
          "Channel %d", channelID);
    }


    SOY_drawSetColour(canvas, SOY_indexColour(PAL_CHANNEL_BG));
    SOY_drawUIRect(canvas,
      rect.x1 + spacing + 1, rect.y1 + channelHeader/2,
      rect.x2 - spacing - 1, rect.y1 + channelHeader - spacing - 4,
      GUI_INVERT | GUI_COLOUR | GUI_FILL);
    SOY_drawSetColour(canvas, SOY_indexColour(PAL_SPECTRO));
    SOY_drawTextFormat(canvas, editor->font,
        rect.x1 + spacing + 2, rect.y1 + channelHeader/2 + 2,
        "%s", sampleName);
  }
  if(editor->compact) { channelHeader = 2; }
  SOY_drawSetColour(canvas, SOY_indexColour(PAL_DARK));
  ST_drawDecoLines(app, rect.x1 + spacing, rect.y1 + channelHeader + 2,
      rect.x2 - spacing - 1);

  posY = rect.y1 + channelHeader + 10;

  for(i = nodeEnd - editor->nodeNum; i < nodeEnd; i++) {
    pattern = patterns[1];
    nodeID = i;
    if(i < 0) {
      pattern = patterns[0];
      nodeID = editor->maxNodes + i;
    }
    if(i >= editor->maxNodes) {
      pattern = patterns[2];
      nodeID = i % editor->maxNodes;
    }

    if(pattern != NULL) {
      SOY_drawSetColour(canvas, SOY_indexColour(PAL_TRACK_PLAYCURSOR));
      
      if(i != editor->playCursor) {
        if(i % 4 == 0) { SOY_drawSetColour(canvas, colBar); }
      }

      if(i == editor->playCursor || (i % 4 == 0)) {
        SOY_drawUIRect(canvas,
          rect.x1 + spacing, posY, rect.x2 - spacing, posY + nodeHeight,
          GUI_INVERT | GUI_FILL | GUI_COLOUR);
      }

      if(i == editor->selectedNode && channelID == editor->selectedTrack) {
        SOY_drawSetColour(canvas, SOY_indexColour(PAL_TRACK_HIGHLIGHT));
        SOY_drawUIRect(canvas,
          rect.x1 + spacing, posY, rect.x2 - spacing, posY + nodeHeight,
          GUI_INVERT | GUI_FILL | GUI_COLOUR);
      }

      SOY_drawUIRect(canvas,
        rect.x1 + spacing, posY, rect.x2 - spacing, posY + nodeHeight,
        GUI_INVERT);

      ST_drawVisualEditorNode(app, editor,
          pattern->nodes[channelID][nodeID],
          rect.x1 + spacing, posY, channelID, nodeID);
    }
    posY += nodeHeight;
  }
  return TRUE;
}

int32 ST_drawVisualEditor(soyApp* app, soyTracker* tracker,
    soyVisualEditor* editor) {
  int32 i = 0;
  int32 labelPos = 6;
  int32 posY = tracker->editorRect.y1 + editor->headerHeight + 10;
  int32 posX = tracker->editorRect.x1 + editor->labelWidth;
  int32 labelXL = tracker->editorRect.x1;
  int32 labelXR = tracker->editorRect.x2 - editor->labelWidth + 1;
  int32 labelYT = tracker->editorRect.y1;
  int32 labelYB = tracker->editorRect.y2;
  int32 nodeEnd = editor->nodeEnd;
  int32 nodeID = 0;
  int32 channelWidth = editor->trackWidth;
  soyTrackList* list = &tracker->trackList;
  soyPattern* patterns[3] = { NULL, NULL, NULL };
  soyPattern* pattern = NULL;
  soyPixel col0H = SOY_indexColour(PAL_TRACK_PLAYCURSOR);
  soyPixel col1H = SOY_indexColour(PAL_TRACK_TEXT_A);
  soyPixel col0L = SOY_indexColour(PAL_LIGHT);
  soyPixel col1L = SOY_indexColour(PAL_TRACK_TEXT_B);
  soyPixel col0 = col0L;
  soyPixel col1 = col1L;

  if(editor->font == app->fontSmall) {
    labelPos = 8;
  } else {
    labelPos = 6;
  }

  if(editor->state == EDITOR_PATTERN) {
    patterns[1] = &tracker->patterns[editor->selectedPattern];
  } else {
    if(list->current->prev != NULL) {
      patterns[0] = &tracker->patterns[list->current->prev->patternIndex]; }

    if(list->current != NULL) {
      patterns[1] = &tracker->patterns[list->current->patternIndex]; }

    if(list->current->next != NULL) {
      patterns[2] = &tracker->patterns[list->current->next->patternIndex]; }
  }

  if(editor->scrollEnable) {
    nodeEnd -= editor->nodeNum / 2;
  }

#if 1
  SOY_drawUIRect(app->framebuffer,
      labelXL, labelYT, labelXL + editor->labelWidth - 1, labelYB,
      GUI_FILL | GUI_DARK);
  SOY_drawUIRect(app->framebuffer,
      labelXR, labelYT, labelXR + editor->labelWidth - 1, labelYB,
      GUI_FILL | GUI_DARK);
#endif

  if(editor->compact) {
    posY = tracker->editorRect.y1 + 12;
  }

  for(i = nodeEnd - editor->nodeNum; i < nodeEnd; i++) {
    pattern = patterns[1];
    nodeID = i;
    if(i < 0) {
      pattern = patterns[0];
      nodeID = editor->maxNodes + i;
    }
    if(i >= editor->maxNodes) {
      pattern = patterns[2];
      nodeID = i % editor->maxNodes;
    }

    if(pattern != NULL) {
      if(i == editor->selectedNode) {
        col0 = col0H;
        col1 = col1H;
      } else {
        col0 = col0L;
        col1 = col1L;
      }
      SOY_drawSetColour(app->framebuffer, col0);
      SOY_drawUIRect(app->framebuffer,
        labelXL + 4, posY,
        labelXL + editor->labelWidth - 5, posY + editor->nodeHeight,
        GUI_INVERT | GUI_FILL | GUI_COLOUR);
      SOY_drawUIRect(app->framebuffer,
        labelXR + 4, posY,
        labelXR + editor->labelWidth - 5, posY + editor->nodeHeight,
        GUI_INVERT | GUI_FILL | GUI_COLOUR);
      SOY_drawSetColour(app->framebuffer, col1);
      SOY_drawTextFormatBold(app->framebuffer, editor->font,
        labelXL + labelPos, posY + 1,
        "%02X", nodeID);
      SOY_drawTextFormatBold(app->framebuffer, editor->font,
        labelXR + labelPos, posY + 1,
        "%02X", nodeID);
    }
    posY += editor->nodeHeight;
  }

  for(i = editor->trackEnd - editor->trackNum; i < editor->trackEnd; i++) {
    ST_drawVisualEditorTrack(app, 
        &tracker->editorRect, editor, patterns, posX, i, channelWidth);
    posX += editor->trackWidth;
  }
  return TRUE;
}

/* menu view ***************************************************************/

#define MAX_MENU_BUTTONS 16

typedef struct tag_soyMenuView soyMenuView;

typedef soyMenuView (*PFMENUVIEWADDBUTTON) (soyRect button);
typedef soyMenuView (*PFMENUVIEWSETRATIO) (real32 ratio);
typedef soyMenuView (*PFMENUVIEWSETOFFSET) (int32 offset);

typedef int32 (*PFMENUVIEWRENDER) 
(soyApp* app, soyTracker* tracker, soyRect* userRect, real64 delta);

struct tag_soyMenuView {
  int8* label;
  soyRect rect;
  soyRect scrollbar;
  soyRect screen;
  soyRect buttons[MAX_MENU_BUTTONS];
  int32 buttonCount;
  int32 active;
  int32 hasDisplay;
  int32 hasScrollbar;
  real32 displayRatio;
  int32 displayOffset;
  int32 scrollLock;
  int32 mousePressedOutside;
  int32 scrollStart;
  int32 selection;
  int32 drawButtons;
  int32 drawLabel;
  real32 scrollbarValue;
  PFMENUVIEWADDBUTTON addButton;
  PFMENUVIEWSETRATIO setRatio;
  PFMENUVIEWSETOFFSET setOffset;
  PFMENUVIEWRENDER userRender;
};

typedef enum enum_soyMenuViewFlags {
  MENU_VIEW_EMPTY = 0,
  MENU_VIEW_SCROLL = 1,
  MENU_VIEW_DISPLAY = 2,
  MENU_VIEW_LABEL = 4
} soyMenuViewFlags;

SOY_GLOBAL soyMenuView g_lastMenu;

SOY_GLOBAL int32 g_menuStateLeft = 0;
SOY_GLOBAL int32 g_menuStateRight = 3;
SOY_GLOBAL int32 g_toolbarFullSize = FALSE;
SOY_GLOBAL soyMenuView g_menuLeft[8];
SOY_GLOBAL soyMenuView g_menuRight[8];

int32 ST_menuViewAddButton(soyMenuView* view, soyRect button) {
  if(view->buttonCount < MAX_MENU_BUTTONS) {
    view->buttons[view->buttonCount++] = button;
  }
  return TRUE;
}

soyMenuView ST_menuViewAddButtonProc(soyRect button) {
  ST_menuViewAddButton(&g_lastMenu, button);  
  return g_lastMenu;
}

soyMenuView ST_menuViewSetRatioProc(real32 ratio) {
  g_lastMenu.displayRatio = ratio;
  return g_lastMenu;
}

soyMenuView ST_menuViewSetOffsetProc(int32 offset) {
  g_lastMenu.displayOffset = offset;
  return g_lastMenu;
}

soyMenuView ST_menuView(int8* label, int32 flags,
    PFMENUVIEWRENDER renderProc) {
  int32 i;
  soyMenuView ret;
  ret.drawLabel = flags & MENU_VIEW_LABEL;
  ret.label = label;
  ret.rect = SOY_rectZero();
  ret.scrollbar = SOY_rectZero();
  ret.screen = SOY_rectZero();
  ret.buttonCount = 0;
  ret.drawButtons = g_toolbarFullSize;
  ret.active = TRUE;
  ret.hasDisplay = flags & MENU_VIEW_DISPLAY;
  ret.hasScrollbar = flags & MENU_VIEW_SCROLL;
  ret.displayRatio = 1.0f;
  ret.displayOffset = 0;
  ret.scrollbarValue = 0.0f;
  ret.scrollLock = FALSE;
  ret.userRender = renderProc;
  ret.mousePressedOutside = FALSE;
  ret.scrollStart = 0;
  ret.selection = 0;
  ret.addButton = ST_menuViewAddButtonProc;
  ret.setRatio = ST_menuViewSetRatioProc;
  ret.setOffset = ST_menuViewSetOffsetProc;
  for(i = 0; i < MAX_MENU_BUTTONS; i++) {
    ret.buttons[i] = SOY_rectZero();
  }
  g_lastMenu = ret;
  return ret;
}

int32 ST_menuViewSetScrollbar(soyMenuView* view, int32 enable) {
  view->hasScrollbar = enable;
  return TRUE;
}

int32 ST_menuViewSetDisplay(soyMenuView* view, int32 enable) {
  view->hasDisplay = enable;
  return TRUE;
}

int32 ST_menuViewSetRect(soyMenuView* view, soyRect rect) {
  view->rect = rect;
  return TRUE;
}

int32 ST_drawScrollbar(soyApp* app, soyTracker* tracker,
    soyMenuView* menu,
    int32 x1, int32 y1, int32 x2, int32 y2) {
  int32 md = 0;
  int32 mx = tracker->mouseX;
  int32 my = tracker->mouseY;
  int32 ml = tracker->mouseLeft;
  int32 bflags = 0;
  int32 height = y2 - y1;
  int32 slider = (int32)(menu->scrollbarValue * (real32)(height - 10)) + 5;
  int enable = (height > 16);
  soyCanvas* canvas = app->framebuffer;
  soyRect rect = SOY_rect(x1, y1, x2, y2);
  soyRect btn = SOY_rect(x1 + 1, y1 + slider - 4, x2 - 1, y1 + slider + 4);
  SOY_rectUpdateBase(&rect, mx, my, ml);
  SOY_rectUpdateBase(&btn, mx, my, ml);
  if(menu->scrollLock) { bflags = GUI_INVERT | GUI_DARK; }
  SOY_drawUIRect(canvas, x1, y1, x2, y2, GUI_INVERT);
  
  if(enable) {
    SOY_drawUIRect(canvas,
        x1 + 1, y1 + slider - 4, x2 - 1,
        y1 + slider + 4, GUI_FILL | GUI_DARK | bflags);
    SOY_drawUILine(canvas,
        x1+2, y1+slider-3, x2-4, y1+slider-3, bflags);
    SOY_drawUILine(canvas,
        x1+2, y1+slider-1, x2-4, y1+slider-1, bflags);
    SOY_drawUILine(canvas,
        x1+2, y1+slider+1, x2-4, y1+slider+1, bflags);
  }
  if(!SOY_rectHeld(&btn) && ml) {
    menu->mousePressedOutside = TRUE;
  }
  if((ml) &&
      !menu->scrollLock &&
      SOY_rectHeld(&btn) &&
      !menu->mousePressedOutside) {
    menu->scrollStart = my;
    menu->scrollLock = TRUE;
  }
  if(!ml) {
    menu->scrollLock = FALSE;
    menu->mousePressedOutside = FALSE;
  }
  if(menu->scrollLock && enable) {
    md = my - menu->scrollStart;
    menu->scrollStart = my;
    menu->scrollbarValue = 
      SOY_MIN(
        SOY_MAX(
          menu->scrollbarValue + (real32)md/(real32)height, 0.0f), 1.0f);
    if(my < rect.y1) { menu->scrollbarValue = 0.0; }
    if(my > rect.y2) { menu->scrollbarValue = 1.0; }
  }
  return TRUE;
}

int32 ST_menuViewRender(soyApp* app,
    soyTracker* tracker, soyMenuView* menu, real64 delta) {
  int32 i;
  int32 textWidth;
  if(menu->drawButtons) {
    SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_CHANNEL_TEXT_A));
    for(i = 0; i < menu->buttonCount; i++) { 
      SOY_drawButton(app->framebuffer, app->fontRegular, &menu->buttons[i]);
    }
  }

#if 1
  if(menu->hasScrollbar) {
    ST_drawScrollbar(app, tracker, menu,
      menu->scrollbar.x1,
      menu->scrollbar.y1,
      menu->scrollbar.x2,
      menu->scrollbar.y2);
  }
#endif
#if 1
  if(menu->hasDisplay) {
    SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_CHANNEL_BG));
    SOY_drawUIRect(app->framebuffer,
        menu->screen.x1, menu->screen.y1, menu->screen.x2, menu->screen.y2,
        GUI_INVERT | GUI_FILL | GUI_COLOUR);
  } else if(menu->drawLabel) {
    textWidth = SOY_drawTextWidth(app->fontRegular, menu->label) + 8;
    SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_DARK));
    ST_drawDecoLines(app,
        menu->rect.x1 + 4,
        menu->rect.y1 + 4,
        menu->rect.x1 + 4 + menu->rect.width/2 - textWidth/2);
    ST_drawDecoLines(app,
        menu->rect.x1 + 4,
        menu->rect.y1 + 8,
        menu->rect.x1 + 4 + menu->rect.width/2 - textWidth/2);
    ST_drawDecoLines(app,
        menu->rect.x1 + 4 + menu->rect.width/2 + textWidth/2,
        menu->rect.y1 + 4,
        menu->rect.x2 - 5);
    ST_drawDecoLines(app,
        menu->rect.x1 + 4 + menu->rect.width/2 + textWidth/2,
        menu->rect.y1 + 8,
        menu->rect.x2 - 5);
    SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_CHANNEL_TEXT_A));
    SOY_drawText(app->framebuffer, app->fontRegular,
        menu->rect.x1 + 8 + menu->rect.width/2 - textWidth/2,
        menu->rect.y1 + 2, menu->label);
    /*
    SOY_drawUIRect(app->framebuffer,
      menu->rect.x1 + 4,
      menu->rect.y1 + 4,
      menu->rect.x2 - 4,
      menu->rect.y1 + 18,
      GUI_DARK);
    */
  }
#endif
#if 1
  if(menu->userRender) {
    menu->userRender(app, &g_tracker, &menu->screen, delta);
  }
#endif
  return TRUE;
}

SOY_GLOBAL int32 g_debugSwitch = FALSE;

int32 ST_menuViewResize(soyApp* app, soyTracker* tracker, soyMenuView* menu,
    soyRect* parent) {
  int32 i;
  int32 width;
  int32 nextWidth;
  int32 height = 18;
  int32 xPos = 0;
  int32 yPos = 0;
  int32 strLen = 0;
  int32 fontWidth = app->fontRegular->data.scaledDrawWidth;
  int32 scroll = 0;
  int32 screenWidth = 0;
  SOY_rectResize(&menu->rect,
      parent->x1, parent->y1, parent->x2, parent->y2);
  menu->drawButtons = g_toolbarFullSize;
  if(menu->hasScrollbar) { scroll = 16; }
  xPos = menu->rect.x1 + 4;
  if(menu->drawLabel) {
    yPos = menu->rect.y1 + 4 + 15;
  } else {
    yPos = menu->rect.y1 + 4;
  }
  if(menu->drawButtons) {
    for(i = 0; i < menu->buttonCount; i++) {
      strLen = menu->buttons[i].labelLen;
      width = 4 * fontWidth + 24;
      if(strLen > 5) { width *= 2; }
      SOY_rectResize(&menu->buttons[i],
        xPos, yPos,
        xPos + width - 1, yPos + height - 1);
      xPos += width;
      if(i < menu->buttonCount - 1) {
        strLen = menu->buttons[i + 1].labelLen;
        nextWidth = 4 * fontWidth + 24;
        if(strLen > 5) { nextWidth *= 2; }
      } else {
        nextWidth = 0;
      }
      if(xPos + nextWidth - 1 > menu->rect.x2 - scroll - 4 || 
          i == menu->buttonCount - 1) {
        xPos = menu->screen.x1;
        if(i == menu->buttonCount - 1) {
          yPos += height + 4;
        } else {
          yPos += height;
        }
      }
    }
  }

  if(menu->buttonCount) {
    yPos--;
  }
  
  screenWidth = 
    (int32)((real32)(menu->rect.width - scroll - 8)*menu->displayRatio);
  
  SOY_rectResize(&menu->screen,
    menu->rect.x1 + 4, menu->rect.y1 + 4,
    menu->rect.x1 + 4 + screenWidth - menu->displayOffset,
    menu->rect.y2 - 4);

  SOY_rectResize(&menu->scrollbar,
      menu->rect.x2 - scroll, menu->rect.y1 + 4,
      menu->rect.x2 - 4, menu->rect.y2 - 4);
  
  return TRUE;
}

int32 ST_menuViewUpdate(soyApp* app, soyTracker* tracker,
    soyMenuView* menu, real64 delta, int32 enabled) {
  int32 i;
  menu->drawButtons = TRUE;
  if(menu->drawButtons) {
    for(i = 0; i < menu->buttonCount; i++) {
      if(enabled) {
        SOY_rectUpdateBase(&menu->buttons[i],
          tracker->mouseX, tracker->mouseY, tracker->mouseLeft);
      }
    }
  }
  SOY_rectUpdateBase(&menu->rect,
      tracker->mouseX, tracker->mouseY,
      tracker->mouseLeft);
  if(menu->hasScrollbar && g_toolbarFullSize) {
    SOY_rectUpdateBase(&menu->scrollbar,
      tracker->mouseX, tracker->mouseY, tracker->mouseLeft);
  }
  if(menu->hasDisplay && g_toolbarFullSize) {
    SOY_rectUpdateBase(&menu->screen,
      tracker->mouseX, tracker->mouseY,
      tracker->mouseLeft || tracker->mouseRight);
  }
  return TRUE;
}

/* mixer view **************************************************************/

typedef struct tag_soyVisualMixer {
  int32 numChannels;
  real32 faders[MAX_CHANNELS + 1];
  real32 peakData[MAX_CHANNELS + 1];
  real32 fadeAmounts[MAX_CHANNELS + 1];
  int32 selectedSlider;
  int32 mouseStart;
  int32 compact;
  soyRect sliderRects[MAX_CHANNELS + 1];
  soyRect rect;
} soyVisualMixer;

SOY_GLOBAL soyVisualMixer g_visualMixer;

int32 ST_visualMixerInit(soyVisualMixer* mixer) {
  int32 i;
  for(i = 0; i < MAX_CHANNELS + 1; i++) {
    mixer->faders[i] = 0.5f;
    mixer->peakData[i] = 0.0f;
    mixer->fadeAmounts[i] = 0.0f;
    mixer->sliderRects[i] = SOY_rectZero();
  }
  mixer->numChannels = MAX_CHANNELS + 1;
  mixer->mouseStart = 0;
  mixer->selectedSlider = 0;
  mixer->rect = SOY_rect(0, 0, 0, 0);
  return TRUE;
}

int32 ST_visualMixerUpdate(soyApp* app, soyTracker* tracker,
    soyVisualMixer* mixer, soyRect rect) {
  int32 i;
  real32 sliderValue;
  int32 mx = tracker->mouseX;
  int32 my = tracker->mouseY;
  int32 ml = tracker->mouseLeft;
  int32 mr = tracker->mouseRight;
  int32 md = 0;
  int32 y1 = rect.y1 + 15;
  int32 y2 = rect.y2;
  int32 width = 12;
  int32 sliderHeight = (y2 - 5) - (y1 + 5);
  int32 xPos = rect.x2 - width - 7;
  int32 index = 0;
  int32 start = 0;
  int32 end = 0;
  mixer->compact = rect.width - 6 < MAX_CHANNELS * (12 + 3) + (12);
  start = mixer->numChannels - 1;
  end = (mixer->compact) ? mixer->numChannels - 2 : 0;
  mixer->rect = rect;
  if(!(tracker->state)) {
    ml = 0;
    mr = 0;
  }
  for(i = start; i >= end; i--) {
    width = (i == start) ? 19 : 12; 
    SOY_rectResize(&mixer->sliderRects[i],
        xPos, y1, xPos + width, y2);
    SOY_rectUpdateBase(&mixer->sliderRects[i], mx, my, ml);
    index = i;
    if(mixer->compact && i != start) {
      index = g_visualEditor.selectedTrack;
    }
    if(index == start) {
      tracker->masterVolume = 1.0f - mixer->faders[index];
    } else {
      tracker->channels[index].volume = 1.0f - mixer->faders[index];
    }
    if(mr && SOY_rectHover(&mixer->sliderRects[i])) {
      mixer->faders[index] = 0.5f;
      return FALSE;
    }
    if(SOY_rectHeld(&mixer->sliderRects[i])) {
      mixer->selectedSlider = index;
      md = my - mixer->mouseStart;
      sliderValue = mixer->faders[mixer->selectedSlider];
      sliderValue =
        SOY_MIN(SOY_MAX(sliderValue + (real32)md/sliderHeight, 0.0f), 1.0f);
      mixer->faders[mixer->selectedSlider] = sliderValue;
    }
    xPos -= 12 + 3;
  }
  mixer->mouseStart = my;
  return TRUE;
}

int32 ST_drawFader(soyApp* app, soyTracker* tracker, soyVisualMixer* mixer,
    int32 index, soyRect* rect,
    real32 volume, real32 maxVolume, int32 sliderPos, int32 highlight) {
  soyCanvas* canvas = app->framebuffer;
  int32 xPos = rect->x1;
  int32 yPos = rect->y1;
  int32 height = rect->y2 - rect->y1;
  int32 width = rect->x2 - rect->x1;
  int32 volMaxScr = 
    SOY_MAX(SOY_MIN((int32)(maxVolume*(real32)height), height - 2), 1);
  int32 volScr = 
    SOY_MAX(SOY_MIN((int32)(volume*(real32)height), height - 2), 1);
  int32 bflags = 
    ((mixer->selectedSlider == index) &&
     SOY_rectHeld(rect)) ? GUI_INVERT : 0;
  
  soyPixel colHi = SOY_indexColour(PAL_CHANNEL_GRADA);
  soyPixel colBg = highlight ? colHi : SOY_indexColour(PAL_LIGHT);
  soyPixel colMain = SOY_indexColour(PAL_SPECTRO);
  soyPixel colAvg = SOY_pixelMix(colBg, colMain, 0.3f);
  
  SOY_drawUIRect(canvas,
      xPos,
      yPos,
      xPos + width,
      yPos + height, GUI_INVERT);
  if(highlight) {
    SOY_drawSetColour(canvas, colHi);
    SOY_drawRectFill(canvas,
      xPos + 1,
      yPos + 1,
      xPos + width - 1,
      yPos + height - 1);
  }

  if(volScr >= 2 || volMaxScr >= 2) {
    if(volume > 1.0f) {
      SOY_drawSetColour(canvas, 0xFFFF0000);
    } else {
      SOY_drawSetColour(canvas, colAvg);
    }
    SOY_drawRectFill(canvas,
        xPos + 1,
        yPos + height - 1 - volMaxScr,
        xPos + width - 1,
        yPos + height - 1);
    if(volume > 1.0f) {
      SOY_drawSetColour(canvas, 0xFFFF0000);
    } else {
      SOY_drawSetColour(canvas, colMain);
    }
    SOY_drawRectFill(canvas,
        xPos + 1,
        yPos + height - 1 - volScr,
        xPos + width - 1,
        yPos + height - 1);
  }

  if(height > 16) {
    SOY_drawUIRect(canvas,
        xPos + 1,
        yPos + sliderPos - 4,
        xPos + width - 1,
        yPos + sliderPos + 4, GUI_FILL | GUI_DARK | bflags);
    SOY_drawUILine(canvas,
        xPos+2, yPos + sliderPos-3,
        xPos+width-4, yPos + sliderPos-3, bflags);
    SOY_drawUILine(canvas,
        xPos+2, yPos + sliderPos-1,
        xPos+width-4, yPos + sliderPos-1, bflags);
    SOY_drawUILine(canvas,
        xPos+2, yPos + sliderPos+1,
        xPos+width-4, yPos + sliderPos+1, bflags);
  }
  return TRUE;
}

int32 ST_drawVisualMixer(soyApp* app, soyTracker* tracker,
    soyVisualMixer* mixer, int32 selectedChannel, real64 delta) {
  int32 i;
  int32 sliderPos = 0;
  real32 avgVolume = 0.0f;
  int32 compact = mixer->compact;
  int32 end = compact ? mixer->numChannels - 2 : 0;
  int32 start = mixer->numChannels - 1;
  int32 index = 0;
  int32 height = 0;
  int32 sliderHeight = 0;
  soyRect* curRect;
  for(i = start; i >= end; i--) {
    index = i;
    curRect = &mixer->sliderRects[i];
    height = curRect->y2 - curRect->y1;
    sliderHeight = height - 10;
    if(compact && i != start) { index = selectedChannel; }
    sliderPos = (int32)(mixer->faders[index]*(real32)sliderHeight) + 5;
    avgVolume = 0.0f;
    if(index == start) {
      avgVolume = ST_averageAmplitude(
          g_masterBufferL,
          g_masterBufferR,
          MAX_CHANNEL_BUFFER);
    } else {
      avgVolume = ST_averageAmplitude(
          g_sampleBuffersL[index],
          g_sampleBuffersR[index],
          MAX_CHANNEL_BUFFER);
    }
    if(avgVolume > mixer->peakData[index]) {
      mixer->peakData[index] = avgVolume;
      mixer->fadeAmounts[index] = 0.0f;
    }
    mixer->peakData[index] -= mixer->fadeAmounts[index]*delta;
    mixer->fadeAmounts[index] += delta*0.1f;
#if 0
    if(tracker->playing == FALSE) {
      mixer->peakData[index] -= delta;
    }
#endif
    if(mixer->peakData[index] < 0.0f) { mixer->peakData[index] = 0.0f; }
    if(curRect->height > 0) {
      ST_drawFader(app, tracker, mixer,
          index, curRect,
          avgVolume, mixer->peakData[index], sliderPos,
          index == selectedChannel);
    }
  }
  return TRUE;
}

int32 ST_mixerMenuRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  ST_visualMixerUpdate(app, tracker, &g_visualMixer, *rect);
  ST_drawVisualMixer(app, tracker, &g_visualMixer,
      g_visualEditor.selectedTrack, delta);
  return TRUE;
}

int32 ST_mixerViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  return TRUE;
}

/* sample view *************************************************************/

SOY_GLOBAL int32 g_sampleViewCurSample = 0;
SOY_GLOBAL int32 g_sampleViewStart = 0;
SOY_GLOBAL int32 g_sampleViewSelectionA = 0;
SOY_GLOBAL int32 g_sampleViewSelectionB = 0;
SOY_GLOBAL int32 g_sampleViewInitialized = 0;

SOY_GLOBAL int32 g_sampleViewMovingA = FALSE;
SOY_GLOBAL int32 g_sampleViewMovingB = FALSE;

SOY_GLOBAL int32 g_sampleViewHoverA = FALSE;
SOY_GLOBAL int32 g_sampleViewHoverB = FALSE;

SOY_GLOBAL real32 g_sampleViewZoom = 1.0f;

SOY_GLOBAL int32 g_isRecording = FALSE;
SOY_GLOBAL int32 g_recordCursor = 0;

soyRect g_sampleViewRects[16];

int32 ST_drawWaveForm(soyApp* app, int16* dataL, int16* dataR, int32 length,
    int32 x1, int32 y1, int32 x2, int32 y2, real32 zoom, int32 start,
    int32 enableLines) {
  int32 i;
  int32 x, y;
  int32 px, py;
  int32 index;
  real32 maxAmp = (real32)MAX_AMP;
  int32 width = (x2 - x1);
  int32 height = (y2 - y1);
  int32 end = (int32)((real32)(length + start));
  real32 halfHeight = (real32)(height / 2);
  int32 interval = app->audio.samplingRate / 5;
  int32 mid = y1 + (height) / 2;
  real32 z = (real32)length / zoom;
  soyPixel colA = SOY_indexColour(PAL_SPECTRO);
  soyPixel colB = SOY_pixelDivide(colA, 2);
  x = 0;
  y = mid;
  px = 0;
  py = mid;
  if(enableLines) {
    SOY_drawSetColour(app->framebuffer, colB);
    SOY_drawLine(app->framebuffer, x1, mid, x2, mid);
    SOY_drawLine(app->framebuffer, x1, y1, x2, y1);
  }
  SOY_drawSetColour(app->framebuffer, colA);
  for(i = 0; i <= end; i++) {
    index = i - start;
    y = mid + (int32)(((real32)dataL[index] / maxAmp) * halfHeight);
    x = (int32)(((real32)i / z) * (real32)width);
    if(x >= width) { break; }
#if 1
    if((index % interval) == 0 && enableLines) {
      SOY_drawSetColour(app->framebuffer, colB);
      SOY_drawLine(app->framebuffer, x1 + x, y1 + 1, x1 + x, y1 + 4);
      SOY_drawSetColour(app->framebuffer, colA);
    }
#endif
    if(px != x || py != y) {
#if 0
      if((z < (real32)width/8.0f)) {
        SOY_drawLine(app->framebuffer, x1 + x, y - 4, x1 + x, y + 4);
      }
#endif
      SOY_drawLine(app->framebuffer, x1 + px, py, x1 + x, y);
    }
    px = x;
    py = y;
  }
  return TRUE;
}

int32 ST_sampleViewPrev() {
  soyTrackerSample* samp;
  int32 wasPlaying = g_testInstrument.playing;
  g_sampleViewCurSample--;
  if(g_sampleViewCurSample < 0) {
    g_sampleViewCurSample = MAX_SAMPLES - 1;
  }
  samp = &g_tracker.samples[g_sampleViewCurSample];
  g_testInstrument = ST_instrument(g_sampleViewCurSample, 0, samp->length);
  g_testInstrument.playing = wasPlaying;
  return TRUE;
}

int32 ST_sampleViewNext() {
  soyTrackerSample* samp;
  int32 wasPlaying = g_testInstrument.playing;
  g_sampleViewCurSample++;
  if(g_sampleViewCurSample >= MAX_SAMPLES) {
    g_sampleViewCurSample = 0;
  }
  samp = &g_tracker.samples[g_sampleViewCurSample];
  g_testInstrument = ST_instrument(g_sampleViewCurSample, 0, samp->length);

  g_testInstrument.playing = wasPlaying;
  return TRUE;
}

int32 ST_sampleView(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  int32 ms = SOY_mouseScroll(app);
  int32 mx = tracker->mouseX - rect->x1;
  int32 ml = tracker->mouseLeft;
  int32 mr = tracker->mouseRight;
  soyTrackerSample* samp = &tracker->samples[g_sampleViewCurSample];
  int32 maxW = 
    (rect->x2 - rect->x1) / app->fontRegular->data.scaledDrawWidth;
  int32 strLen = SOY_stringLen(samp->label);
  int32 clipW = 23 + strLen + 1;
  int32 playCursor = 0;
  int32 selectionCursorA = 0;
  int32 selectionCursorB = 0;
  int32 sampleLenScreen = 0;
  int32 width = 0;
  int32 waveOffset = 0;
  soyInstrument* inst = &g_testInstrument;
  if(!g_sampleViewInitialized) {
    g_sampleViewInitialized = TRUE;
    g_sampleViewSelectionA = inst->sampleEnd;
    g_sampleViewSelectionB = inst->sampleStart;
    g_testInstrument = ST_instrument(g_sampleViewCurSample, 0, samp->length);
  }
  if(g_toolbarFullSize) {
    waveOffset = 16 + 4;
  }
  width = (rect->x2 - 2) - (rect->x1 + 1);
#if 1

  if(ms != 0 && 
      SOY_rectHover(rect) && 
      SOY_keyHeld(app, SOY_SHIFT)) {
     if(ms > 0) {
      g_sampleViewStart -= 
        (int32)((real32)samp->length*0.05f / g_sampleViewZoom);
    } else{
      g_sampleViewStart += 
        (int32)((real32)samp->length*0.05f / g_sampleViewZoom);
    }
    if(g_sampleViewStart > 0) { g_sampleViewStart = 0; }
    if(g_sampleViewStart < -(int32)samp->length) {
      g_sampleViewStart = -(int32)samp->length;
    }
  } else if(ms != 0 &&
      SOY_rectHover(rect) &&
      SOY_keyHeld(app, SOY_CONTROL)) {
    if(ms > 0) {
      g_sampleViewZoom *= 1.1;
    } else{
      g_sampleViewZoom *= 0.9;
    }
    g_sampleViewZoom = SOY_MIN(SOY_MAX(g_sampleViewZoom, 1.0f), 8000.0f);
  } else if(ms != 0 && SOY_rectHover(rect) && !g_isRecording) {
    if(ms < 0 && g_sampleViewCurSample > 0) {
      ST_sampleViewPrev();
    } else if(ms > 0 && g_sampleViewCurSample < MAX_SAMPLES - 1) {
      ST_sampleViewNext();
    }
  }
#endif
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_SPECTRO));
  if(maxW > clipW && g_toolbarFullSize) {
    SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
      rect->x1 + 4, rect->y1 + 4,
      "L: %08d | S: %03d | %s",
      samp->length,
      g_sampleViewCurSample,
      samp->label
      );
  } else if (maxW > strLen + 1 && g_toolbarFullSize) {
    SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
      rect->x1 + 4, rect->y1 + 4,
      "%s",
      samp->label
      );
  }
  
  playCursor =
    (int32)(((real32)(inst->cursor + g_sampleViewStart) /
          (real32)inst->sampleEnd * (g_sampleViewZoom)) *
        (real32)width);
  playCursor = SOY_MIN(SOY_MAX(playCursor, 0), width);
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_SPECTRO));
  
  ST_drawWaveForm(app,
    samp->data,
    samp->data,
    samp->length,
    rect->x1 + 1, rect->y1 + 1 + waveOffset, rect->x2 - 2, rect->y2 - 2,
    g_sampleViewZoom,
    g_sampleViewStart,
    g_toolbarFullSize);

  if(playCursor < width) {
    SOY_drawLine(app->framebuffer,
        rect->x1 + 1 + playCursor,
        rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + playCursor,
        rect->y2 - 2);
  }

  selectionCursorA =
    (int32)(((real32)(g_sampleViewSelectionA + g_sampleViewStart) / 
          (real32)samp->length) * (real32)width*g_sampleViewZoom);

  selectionCursorB =
    (int32)(((real32)(g_sampleViewSelectionB + g_sampleViewStart) / 
          (real32)samp->length) * (real32)width*g_sampleViewZoom);

  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_SPECTRO));

  selectionCursorA = SOY_MIN(SOY_MAX(selectionCursorA, 0), width);
  selectionCursorB = SOY_MIN(SOY_MAX(selectionCursorB, 0), width);

  g_sampleViewHoverA = 
    (mx >= selectionCursorA - 4 && mx <= selectionCursorA + 4);
  g_sampleViewHoverB = 
    (mx >= selectionCursorB - 4 && mx <= selectionCursorB + 4);

  if(!ml) { g_sampleViewMovingA = FALSE; g_sampleViewMovingB = FALSE; }
  
  if(ml &&
      SOY_rectCheck(rect, RECT_HELD_INSIDE) &&
      tracker->mouseX < SOY_width(app)) {
    if(g_sampleViewHoverA) { g_sampleViewMovingA = TRUE; }
    if(g_sampleViewHoverB) { g_sampleViewMovingB = TRUE; }
    if(g_sampleViewMovingA) {
      g_sampleViewSelectionA = 
        (int32)(((real32)mx / (real32)width)*
          ((real32)samp->length / g_sampleViewZoom)) - g_sampleViewStart;
    } else if(g_sampleViewMovingB) {
      g_sampleViewSelectionB = 
        (int32)(((real32)mx / (real32)width)*
          ((real32)samp->length / g_sampleViewZoom)) - g_sampleViewStart;
    } else {
      if(SOY_rectPressed(rect)) {
        g_sampleViewSelectionA = 
          (int32)(((real32)mx / (real32)width)*
          ((real32)samp->length / g_sampleViewZoom)) - g_sampleViewStart;
      }
      g_sampleViewSelectionB = 
        (int32)(((real32)mx / (real32)width)*
        ((real32)samp->length / g_sampleViewZoom)) - g_sampleViewStart;   
    }
  }

  if(mr) {
    g_sampleViewSelectionA = 0;
    g_sampleViewSelectionB = samp->length;
  }

  if(g_sampleViewSelectionA > (int32)samp->length) { 
    g_sampleViewSelectionA = (int32)samp->length;
  }

  if(g_sampleViewSelectionB > (int32)samp->length) { 
    g_sampleViewSelectionB = (int32)samp->length;
  }

  if(g_sampleViewSelectionA < 0) { g_sampleViewSelectionA = 0; }
  if(g_sampleViewSelectionB < 0) { g_sampleViewSelectionB = 0; }
  
  sampleLenScreen =
    (int32)(((real32)(samp->length + g_sampleViewStart) / 
          (real32)samp->length) * (real32)width*g_sampleViewZoom);

  sampleLenScreen = SOY_MIN(SOY_MAX(sampleLenScreen, 0), width);

  SOY_drawLine(app->framebuffer,
      rect->x1 + 1 + sampleLenScreen, rect->y1 + 1 + waveOffset,
      rect->x1 + 1 + sampleLenScreen, rect->y2 - 2);

  if(g_sampleViewHoverA) {
    SOY_drawLineDotted(app->framebuffer,
        rect->x1 + 1 + selectionCursorA, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorA, rect->y2 - 2);
  } else {
    SOY_drawLine(app->framebuffer,
        rect->x1 + 1 + selectionCursorA, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorA, rect->y2 - 2);
  }
  
  if(g_sampleViewHoverB) {
    SOY_drawLineDotted(app->framebuffer,
        rect->x1 + 1 + selectionCursorB, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorB, rect->y2 - 2);
  } else {
    SOY_drawLine(app->framebuffer,
        rect->x1 + 1 + selectionCursorB, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorB, rect->y2 - 2);
  }
  
  SOY_drawLine(app->framebuffer,
      rect->x1 + 1 + selectionCursorA, rect->y1 + 1 + waveOffset,
      rect->x1 + 1 + selectionCursorB, rect->y1 + 1 + waveOffset);
  
#if 0
  if(g_sampleViewHoverA) {
    if(selectionCursorA < width - 1) {
      SOY_drawLine(app->framebuffer,
        rect->x1 + 1 + selectionCursorA + 2, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorA + 2, rect->y2 - 2);
    }
    if(selectionCursorA > 1) {
      SOY_drawLine(app->framebuffer,
        rect->x1 + 1 + selectionCursorA - 2, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorA - 2, rect->y2 - 2);
    }
  }

  if(g_sampleViewHoverB) {
    if(selectionCursorB < width - 1) {
      SOY_drawLine(app->framebuffer,
        rect->x1 + 1 + selectionCursorB + 2, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorB + 2, rect->y2 - 2); 
    }
    if(selectionCursorB > 1) {
      SOY_drawLine(app->framebuffer,
        rect->x1 + 1 + selectionCursorB - 2, rect->y1 + 1 + waveOffset,
        rect->x1 + 1 + selectionCursorB - 2, rect->y2 - 2);  
    }
  }
#endif
  return TRUE;
}

int32 ST_sampleViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  ST_sampleView(app, tracker, rect, delta);
  return TRUE;
}

/* instrument view *********************************************************/

int32 ST_instrViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  return TRUE;
}

/* effect view *************************************************************/
#if 1

SOY_GLOBAL int32 g_effectViewCurSlot = 0;
SOY_GLOBAL int32 g_effectViewCurRack = 0;

int32 ST_effectViewRender(soyApp* app, soyTracker* tracker,
    soyRect* rect, real64 delta) {
  soyEffectRack* curRack;
  soyEffect* curEffect;
  soyCanvas* canvas = app->framebuffer;
  soyFont* fontBig = app->fontRegular;
  
  g_effectViewCurRack = g_visualEditor.selectedTrack;
  curRack = &g_effectRacks[g_effectViewCurSlot];
  curEffect = &curRack->slots[g_effectViewCurSlot];
  SOY_drawSetColour(canvas, SOY_indexColour(PAL_SPECTRO));
  SOY_drawTextFormat(canvas, fontBig, rect->x1 + 4, rect->y1 + 4,
      "CHANNEL: %d SLOT: %d\nTYPE: %s",
      g_effectViewCurRack, g_effectViewCurSlot, curEffect->label);

  return TRUE;
}

int32 ST_effectViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  ST_effectViewRender(app, tracker, rect, delta); 
  return TRUE;
}
#endif

/* spectrograph view *******************************************************/

soyCanvas g_spectroCanvas;
soyMemorySector spectroCanvasMemory;

soyFilter g_fftFilter;
int32 g_fftFilterInit = FALSE;

int32 ST_drawSpectrograph(soyApp* app,
    int32 size, int32 x, int32 y, int32 width, int32 height,
    real32 lowCutoff, real32 amp) {
  int32 i = 0;
  int32 lx = 0;
  int32 xv = 0;
  int32 xvp = 0;
  int32 v = 0;
  int32 vp = 0;
  real32 n = 0.0f;
  soyCanvas* canvas = app->framebuffer;
  real32 vr = 0.0f;
  real32 scaled = 0.0f;
  real32 slog = log((real32)size/lowCutoff/2.0f);
  soyPixel colA = SOY_indexColour(PAL_SPECTRO);
  soyPixel colB = SOY_pixelDivide(SOY_indexColour(PAL_SPECTRO), 2);
  soyPixel lerpCol = 0;
  soyPixel prevLerp = 0;
  if(!g_fftFilterInit) {
    ST_filterInitLowPass(&g_fftFilter, 2, 48000.0f, 4096.0f);
    g_fftFilterInit = TRUE;
  }
  for(i = 0; i < size/2; i++) {
    scaled = log(((real32)i/lowCutoff));
    xv = (int32)((scaled / slog*width));
    vr = ST_filterLowPass(&g_fftFilter, g_FFTBufferPers[i]);
    vr *= (scaled);
    v = (int32)(vr*(real32)height*amp);
    v = SOY_MIN(SOY_MAX(v, 0), height);
    SOY_drawSetColour(canvas, colB);
#if 0
    if(i%(10*((i > 100) ? 10 : 1)) == 0) {
      SOY_drawLine(canvas,
          x + xv, y + 1,
          x + xv, y + 1 + height - 2);
    }
#endif
    if(xv > 0) {
      lerpCol =
          SOY_colourLerp(SOY_indexColour(PAL_CHANNEL_BG), colA,
              SOY_MIN(SOY_MAX(sqrt(vr*1.0f)*1.0f, 0.0f), 1.0f));
      n = (real32)(lx - xvp)/(real32)(xv - xvp);
      SOY_drawSetColour(canvas, colA);
      SOY_drawLine(canvas,
        x + xvp, (y + height) - vp,
        x + xv, (y + height) - v);
      prevLerp = lerpCol;
    }
    xvp = xv;
    vp = v;
  }
  return TRUE;
}

int32 ST_drawSpectrographCompact(soyApp* app,
    int32 size, int32 x, int32 y, int32 width, int32 height,
    real32 lowCutoff, real32 amp) {
  int32 i = 0;
  int32 xv = 0;
  int32 xvp = 0;
  int32 v = 0;
  real32 vr = 0.0f;
  real32 scaled = 0.0f;
  real32 slog = log((real32)size/lowCutoff/2.0f);
  for(i = 1; i < size/2; i++) {
    scaled = log(((real32)i/lowCutoff));
    xv = (int32)((scaled / slog*width));
    vr = (0.4f*(g_FFTBufferPers[i])  - (g_FFTBufferPers[i] - g_FFTBufferPers[i - 1]));
    vr *= (scaled);
    v = (int32)(vr*(real32)255.0f*amp*2.0f);
    v = SOY_MIN(SOY_MAX(v, 0.0f), 255.0f);
    if(xv > 0) {
      SOY_drawRectFill(app->framebuffer,
          x + xvp, (y),
          x + xv, (y + height + 2)
          );
    }
    xvp = xv;
  }
  return TRUE;
}

uint32 g_copyTime = 0;

int32 ST_spectroViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_SPECTRO));
  if(rect->y2 - rect->y1 > 32) {
    ST_drawSpectrograph(app, tracker->fftSize,
      rect->x1, rect->y1,
      rect->x2 - rect->x1 - 1,
      rect->y2 - rect->y1 - 2,
      5.0f, 1.0f);
  } else {
    ST_drawSpectrographCompact(app, tracker->fftSize,
      rect->x1, rect->y1,
      rect->x2 - rect->x1 - 1,
      rect->y2 - rect->y1 - 2,
      5.0f, 1.0f);
  }
  return TRUE;
}

/* visual view *************************************************************/

soyPixel ST_shaderProc(real32 x, real32 y) {
  real32 dist = sqrt((x*x + y*y))*10.1f;
  int32 col = (int32)((dist*dist*dist*dist)*255.0f);
  col = SOY_MIN(SOY_MAX(255 - col, 0), 255);
  return SOY_pixel(col, col, col, 255);
}

int32 ST_drawVisualizer(soyApp* app,
    int32 x1, int32 y1, int32 x2, int32 y2) {
  int32 x, y;
  real32 rx, ry;
  int32 width = x2 - x1;
  int32 height = y2 - y1;
  real32 aspect = (real32)height / (real32)width;
  for(y = 0; y < height; y++) {
    ry = (real32)y / (real32)width - (aspect * 0.5f);
    for(x = 0; x < width; x++) {
      rx = (real32)x / (real32)width - 0.5f;
      SOY_drawSetColour(app->framebuffer, ST_shaderProc(rx, ry));
      SOY_drawPixel(app->framebuffer, x1 + x, y1 + y);
    }
  }
  return TRUE;
}

int32 ST_visualViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  ST_drawVisualizer(app,
      rect->x1 + 1, rect->y1 + 1, rect->x2 - 1, rect->y2 - 1);
  return TRUE;
}

/* pattern view ************************************************************/

int32 ST_patternViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  return TRUE;
}

/* song view ***************************************************************/

int32 ST_songViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  int32 i = 0;
  int32 width = app->fontRegular->data.scaledDrawWidth;
  int32 xPos = rect->x1 + 4;
  int32 yPos = rect->y1 + 4;
  int32 offset = 0;
  soyTrackNode* current = tracker->trackList.first;
  soyPixel colA = SOY_indexColour(PAL_SPECTRO);
  soyPixel colB = SOY_pixelDivide(colA, 2);
  while(current->next != NULL && i < trackListStartOffset) {
    current = current->next;
    i++;
  }
  i = 0;
  if(trackListStartOffset) {
    SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
      xPos - offset, yPos, "\n\n+%02X",
      trackListStartOffset);
  }
  while(current != NULL && i <= 39) {
    if(current == tracker->trackList.current) {
      SOY_drawSetColour(app->framebuffer, colA);
      SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
        xPos - offset, yPos, "%X\n%X",
        current->patternIndex & 0xF, (current->patternIndex & 0xF0) >> 4);
      SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
        xPos - offset - 1, yPos, "%X\n%X",
        current->patternIndex & 0xF, (current->patternIndex & 0xF0) >> 4);
    } else {
      SOY_drawSetColour(app->framebuffer, colB);
      SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
        xPos - offset, yPos, "%X\n%X",
        current->patternIndex & 0xF, (current->patternIndex & 0xF0) >> 4);
    }

    if(current == tracker->trackList.current &&
        (i >= (!!trackListStartOffset)*4)) {
      SOY_drawSetColour(app->framebuffer, colA);
      SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
        xPos - offset, yPos, "\n\n|");
    } else {
      if((trackListStartOffset + i)%4 == 0 &&
          (i >= (!!trackListStartOffset)*4)) {
        SOY_drawSetColour(app->framebuffer, colB);
        SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
          xPos - offset, yPos, "\n\n:", trackListStartOffset + i);
      } else {
        SOY_drawSetColour(app->framebuffer, colB);
        SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
          xPos - offset, yPos, "\n\n.", trackListStartOffset + i);
      }
    }

    xPos += width;
    i++;
    current = current->next;
  }
  return TRUE;
}

/* file view ***************************************************************/

SOY_GLOBAL int32 g_fileViewEnd = 0;
SOY_GLOBAL int32 g_fileViewCount = 0;
SOY_GLOBAL int32 g_fileViewRefresh = TRUE;
SOY_GLOBAL int8 g_fileViewBuffer[256][256];
SOY_GLOBAL int32 g_fileViewSizeBuffer[256];
SOY_GLOBAL real32 g_fileViewPos = 0;
SOY_GLOBAL int32 g_fileViewPrevWidth = 0;
SOY_GLOBAL int32 g_fileViewMouseLock = FALSE;
SOY_GLOBAL int8* g_curFileName = NULL;
SOY_GLOBAL int32 g_fileViewMaxRows = 0;
soyRect g_fileViewRects[8];

SOY_GLOBAL int32 g_fileViewSelection = 0;

int32 ST_fileViewCallback(soyFileData data, void* args) {
  int32 maxLen = *((int32*)args);
  int32 strLen = SOY_stringLen(data.name);
  if(!data.name) { return FALSE; }
  if(data.name[0] == '.') { return FALSE; }
  g_fileViewSizeBuffer[g_fileViewCount] = data.fileSize;
  if(strLen < maxLen) {
    snprintf(g_fileViewBuffer[g_fileViewCount++], 64, "%.14s", data.name);
  } else if(maxLen > 2) {
    snprintf(g_fileViewBuffer[g_fileViewCount++], 64, "%.*s..",
        maxLen - 2, data.name);
  } else {
    snprintf(g_fileViewBuffer[g_fileViewCount++], 64, "%.*s",
        maxLen, data.name);
  }
  g_curFileName = data.name;
  return TRUE;
}

int32 ST_fileViewUp() {
  if(g_fileViewSelection < g_fileViewPos ||
    g_fileViewSelection >= g_fileViewPos + g_fileViewMaxRows) {
    g_fileViewPos = g_fileViewSelection;
  } else {
    g_fileViewSelection--;
  }

  if(g_fileViewSelection < g_fileViewPos) {
    g_fileViewPos--;
    if(g_fileViewPos < 0) {
      g_fileViewPos = g_fileViewCount - g_fileViewMaxRows;
      g_fileViewSelection = g_fileViewCount - 1;
    }
  }
  return TRUE;
}

int32 ST_fileViewDown() {
  if(g_fileViewSelection < g_fileViewPos ||
    g_fileViewSelection >= g_fileViewPos + g_fileViewMaxRows) {
    g_fileViewPos = g_fileViewSelection;
  } else {
    g_fileViewSelection++;
  }
  if(g_fileViewSelection >= g_fileViewPos + g_fileViewMaxRows) {
    g_fileViewPos++;
    if(g_fileViewPos > g_fileViewCount - g_fileViewMaxRows) {
      g_fileViewPos = 0;
      g_fileViewSelection = 0;
    }
  }
  return TRUE;
}

int32 ST_fileView(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  int32 i;
  int32 start;
  int32 mx = tracker->mouseX;
  int32 my = tracker->mouseY;
  int32 ml = tracker->mouseLeft;
  int32 xPos = rect->x1 + 4;
  int32 yPos = rect->y1 + 4;
  int32 width = app->fontRegular->data.scaledDrawWidth;
  int32 maxW = (rect->x2 - rect->x1) / width;
  int32 height = app->fontRegular->data.scaledDrawHeight;
  int32 args = SOY_MAX(maxW - 2, 1);
  soyPixel colA = SOY_indexColour(PAL_SPECTRO);
  soyPixel colB = SOY_pixelDivide(colA, 2);
  soyPixel colC = SOY_pixelDivide(colA, 8);
  g_fileViewMaxRows = ((rect->y2 - 2) - (rect->y1 + 4)) / height;
  if(g_fileViewRefresh || g_fileViewPrevWidth != maxW) {
    g_fileViewCount = 0;
    SOY_listFilesInDir("*", ST_fileViewCallback, &args);
    g_fileViewRefresh = FALSE;
  }

  g_fileViewPrevWidth = maxW;
  start = g_fileViewPos;

  g_fileViewEnd = g_fileViewPos + g_fileViewMaxRows;

  for(i = start; i < g_fileViewEnd; i++) {
    SOY_drawSetColour(app->framebuffer, colA);
    if(i%2 == 0) {
      SOY_drawSetColour(app->framebuffer, colC);
      if(i - start == 0 && g_fileViewMaxRows == 1) {
        SOY_drawRectFill(app->framebuffer,
            rect->x1 + 1, rect->y1 + 1, rect->x2 - 1, rect->y2 - 1);
      } else if(i - start == 0) {
        SOY_drawRectFill(app->framebuffer,
            rect->x1 + 1, rect->y1 + 1, rect->x2 - 1, yPos + height);
      } else if(i - start == g_fileViewMaxRows - 1) {
        SOY_drawRectFill(app->framebuffer,
            rect->x1 + 1, yPos, rect->x2 - 1, rect->y2 - 1);
      } else {
        SOY_drawRectFill(app->framebuffer,
            rect->x1 + 1, yPos, rect->x2 - 1, yPos + height);
      }
    }

    SOY_drawSetColour(app->framebuffer, colA);
    if(i < g_fileViewCount) {
      if(i == g_fileViewSelection) {
        SOY_drawSetColour(app->framebuffer, colA);
      } else {
        SOY_drawSetColour(app->framebuffer, colB);
      }
      SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
          xPos, yPos, "%.16s", g_fileViewBuffer[i]);
      if(maxW - 8 > 16) {
        if(g_fileViewSizeBuffer[i] < 1024*512) {
          SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
            rect->x2 - 4 - 8*width, yPos, "%.1fKB",
            (real32)g_fileViewSizeBuffer[i] / 1024.0f);
        } else {
          SOY_drawTextMonoFormat(app->framebuffer, app->fontRegular,
            rect->x2 - 4 - 8*width, yPos, "%.1fMB",
            (real32)g_fileViewSizeBuffer[i] / 1024.0f / 1024.0f);
        }
      }

      if(mx > rect->x1 && mx < rect->x2 && my > yPos && my < yPos + height) {
        if(ml && !g_fileViewMouseLock) { g_fileViewSelection = i; }
      }
    }
    yPos += height;
  }
  g_fileViewMouseLock = ml;
  g_curFileName = g_fileViewBuffer[g_fileViewSelection];
  return TRUE;
}

int32 ST_fileViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  int32 ms = SOY_mouseScroll(app);
  if(SOY_rectHover(rect) && ms != 0) {
    if(ms > 0) {
      if(g_fileViewSelection > 0) { ST_fileViewUp(); }
    } else {
      if(g_fileViewSelection < g_fileViewCount - 1) { ST_fileViewDown(); }
    }
  }
  ST_fileView(app, tracker, rect, delta);
  return TRUE;
}

/* config view *************************************************************/

int32 ST_configViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  return TRUE;
}

/* about view **************************************************************/

int32 ST_aboutViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  return TRUE;
}

/* help view ***************************************************************/

int32 ST_helpViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  return TRUE;
}


/* keyboard config *********************************************************/

SOY_GLOBAL int32 g_keyboardConfigured = FALSE;
SOY_GLOBAL int32 g_keyboardConfCounter = 0;
SOY_GLOBAL uint8 g_keyboardFlags[] = { 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0 };
SOY_GLOBAL uint8 g_keyboardMap[36];
SOY_GLOBAL int32 g_fadeTimer = 64;
SOY_GLOBAL int32 g_fadeAmount = 64;

int32 ST_updateVirtualKeyboard(int32 index, uint8 key) {
  KEYMAP[key] = index;
  g_keyboardMap[index] = (uint8)key;
  return TRUE;
}

int32 ST_drawVirtualKeyboard(soyApp* app, soyTracker* tracker) {
  int32 i;
  int8* warnString = "MAP KEYS TO VIRTUAL KEYBOARD or PRESS ESCAPE";
  int32 textLen = SOY_drawTextWidth(app->fontRegular, warnString);
  int32 pw = 10;
  int32 ph = 96;
  int32 px = SOY_width(app)/2-18*(pw+4) + pw/4;
  int32 py = tracker->clientRect.y1+32+SOY_height(app)/2;
  int32 stepX = 0;
  real32 fadeT = (((real32)g_fadeTimer / (real32)g_fadeAmount));
  uint8 fade = 255;
  soyCanvas* canvas = app->framebuffer;
  if(g_keyboardConfigured) {
    if(g_fadeTimer) {
      fadeT *= fadeT*fadeT;
      fade = (uint8)(fadeT*255.0f);
      g_fadeTimer--;
    }
  } else {
    g_fadeTimer = g_fadeAmount;
  }
  SOY_drawSetColour(canvas, SOY_pixel(0, 0, 0, fade));
  SOY_drawUIRectThick(canvas,
      tracker->clientRect.x1 + 48,
      tracker->clientRect.y1 + 48,
      tracker->clientRect.x2 - 48,
      tracker->clientRect.y2 - 48,
      GUI_FILL);

  SOY_drawTextBold(canvas, app->fontRegular,
      SOY_width(app)/2 - textLen/2,
      tracker->clientRect.y1 + 48 + 32,
      warnString);
  for(i = 0; i < 36; i++) {
    if(g_keyboardFlags[i%12]) {
      SOY_drawSetColour(canvas, SOY_pixel(0, 0, 0, fade));
      SOY_drawSetAlpha(canvas, fade);
      if(i == g_keyboardConfCounter) {
        SOY_drawSetColour(canvas, SOY_pixel(0, 0, 255, fade));
        SOY_drawSetAlpha(canvas, fade);
      }
      SOY_drawUIRect(canvas,
          px+stepX, py, px+stepX+pw, py+ph - ph/4, GUI_FILL | GUI_COLOUR);
    } else {
      SOY_drawSetColour(canvas, SOY_pixel(255, 255, 255, fade));
      if(i == g_keyboardConfCounter) {
        SOY_drawSetColour(canvas, SOY_pixel(0, 0, 255, fade));
      }
      SOY_drawUIRect(canvas,
          px+stepX, py, px+stepX+pw, py+ph, GUI_FILL | GUI_COLOUR);
    }
    if(i < g_keyboardConfCounter) {
      if(g_keyboardFlags[i%12]) {
        SOY_drawSetColour(canvas, SOY_pixel(255, 255, 255, fade));
      } else {
        SOY_drawSetColour(canvas, SOY_pixel(0, 0, 0, fade));
      }
      SOY_drawTextFormatBold(canvas, app->fontRegular,
          px + stepX, py, "%c",
          SOY_keyToASCII(g_keyboardMap[i], g_keyboardMap[i]));
    }
    stepX += pw+4;
  }
  return TRUE;
}

int32 ST_saveKeyboardMap(int32* map, int8* filename) {
  FILE* file = SOY_fileOpen(filename, "wb");
  fwrite(map, KEYMAP_SIZE*sizeof(int32), 1, file);
  SOY_fileClose(file);
  return TRUE;
}

int32 ST_loadKeyboardMap(int32* map, int8* filename) {
  FILE* file = SOY_fileOpen(filename, "wb");
  fread(map, KEYMAP_SIZE*sizeof(int32), 1, file);
  SOY_fileClose(file);
  return TRUE;
}

SOY_GLOBAL PFMENUVIEWRENDER g_displayProcs[32] = {
  ST_patternViewRenderProc,
  ST_mixerViewRenderProc,
  ST_sampleViewRenderProc,
  ST_instrViewRenderProc,
  ST_effectViewRenderProc,
  ST_fileViewRenderProc,
  ST_configViewRenderProc,
  ST_helpViewRenderProc
};

int32 ST_displayViewRenderProc(soyApp* app,
    soyTracker* tracker, soyRect* rect, real64 delta) {
  if(g_menuStateRight >= 0) {
    if(g_displayProcs[g_menuStateRight]) {
      g_displayProcs[g_menuStateRight](app, tracker, rect, delta);
    }
  }
  return TRUE;
}


/* mixing ******************************************************************/

typedef struct tag_soyMixerSample {
  real32 left;
  real32 right;
} soyMixerSample;

soyMixerSample ST_mixerSample(real32 l, real32 r) {
  soyMixerSample ret;
  ret.left = l;
  ret.right = r;
  return ret;
}

soyMixerSample ST_mixerSampleAdd(soyMixerSample a, soyMixerSample b) {
  return ST_mixerSample(a.left + b.left, a.right + b.right);
}

soyMixerSample ST_mixerSampleFromData(soyTrackerSample* sample,
    int32 cursor) {
  soyMixerSample ret;
  ret.left = (real32)(*(sample->data + cursor))/(real32)MAX_AMP;
  ret.right = (real32)(*(sample->data + cursor))/(real32)MAX_AMP;
  return ret;
}

soyMixerSample ST_mixerSampleBlend(
    soyMixerSample a, soyMixerSample b, real32 t) {
  soyMixerSample ret;
  ret.left = SOY_lerp(a.left, b.left, t);
  ret.right = SOY_lerp(a.right, b.right, t);
  return ret;
}

soyMixerSample ST_mixerSampleMultiply(soyMixerSample a, real32 l, real32 r) {
  a.left *= l;
  a.right *= r;
  return a;
}

soyMixerSample ST_mixerSampleClip(soyMixerSample a,
    real32 clipLow, real32 clipHigh, real32 volume) {
  a.left = SOY_MIN(SOY_MAX(a.left*volume, clipLow), clipHigh);
  a.right = SOY_MIN(SOY_MAX(a.right*volume, clipLow), clipHigh);
  return a;
}

soySampleResult ST_mixerSampleToInt16(soyMixerSample m) {
  soySampleResult ret;
  ret.left = (int16)(m.left*(real32)MAX_AMP);
  ret.right = (int16)(m.right*(real32)MAX_AMP);
  return ret;
}

int32 ST_trackerAdvancePlayCursor(soyTracker* tracker, soyPattern* pattern) {
  int32 i;

  for(i = 0; i < MAX_CHANNELS; i++) {
    if(pattern->nodes[i][tracker->playCursor].flags & NODE_NOTE) {
      ST_playNode(tracker, &pattern->nodes[i][tracker->playCursor], i);
    }
  }

  tracker->playCursor++;

  if(g_visualEditor.scrollEnable) {
    ST_visualEditorMove(&g_visualEditor, SOY_DOWN);
  }

  if(tracker->playCursor >= pattern->nodeCount) {
    tracker->playCursor = 0;
    if(g_visualEditor.state == EDITOR_SONG) {
      if(tracker->trackList.current->next) {
        ST_trackListSelectNext(&tracker->trackList);
      } else {
        while(tracker->trackList.current->prev != NULL) {
          ST_trackListSelectPrev(&tracker->trackList);
        }
      }
    }
  }
  return TRUE;
}

int32 ST_trackerTick(soyTracker* tracker, real64 tempo) {
  soyPattern* pattern =
    &tracker->patterns[tracker->trackList.current->patternIndex];
  if(g_visualEditor.state == EDITOR_PATTERN) {
    pattern = &tracker->patterns[g_visualEditor.selectedPattern];
  }
  if(!tracker->ticks) { return FALSE; }
  if(tracker->audioCursor > tempo) {
    if(tracker->tickCursor >= tracker->ticks) {
      ST_trackerAdvancePlayCursor(tracker, pattern);
      tracker->tickCursor = 0;
    }
    tracker->tickCursor++;
    tracker->audioCursor -= tempo;
  }
  tracker->audioCursor += 1.0;
  return TRUE;
}

soyFilter g_butterLowPassLeft;
soyFilter g_butterLowPassRight;
soyFilter g_butterHighPassLeft;
soyFilter g_butterHighPassRight;

int32 g_filtersInit = FALSE;

soySampleResult ST_mixerUpdate(soyTracker* tracker, real32 tempo) {
  int32 i;
  soyInstrument* soundCur;
  soyInstrument* soundPrev;
  soyTrackerSample* testData;
  soyTrackerSample* data;
  soyTrackerSample* dataPrev;
  soyMixerSample testSample = ST_mixerSample(0.0f, 0.0f);
  soyMixerSample sample = ST_mixerSample(0.0f, 0.0f);
  soyMixerSample samplePrev = ST_mixerSample(0.0f, 0.0f);
  soyMixerSample sampleNext = ST_mixerSample(0.0f, 0.0f);
  soyMixerSample mix = ST_mixerSample(0.0f, 0.0f);
  real32 lerpAmt = 0.99f;
  real32 subCursor = 0.0f;
  real32 sampleT = 0.0f;
  real32 master = tracker->masterVolume;
  soyChannel* channel = NULL;
  if(!g_filtersInit) {
    ST_filterInitLowPass(&g_butterLowPassLeft, 8, 48000.0f, 100.0f);
    ST_filterInitLowPass(&g_butterLowPassRight, 8, 48000.0f, 100.0f);
    ST_filterInitHighPass(&g_butterHighPassLeft, 8, 48000.0f, 2000.0f);
    ST_filterInitHighPass(&g_butterHighPassRight, 8, 48000.0f, 2000.0f);
   
    g_filtersInit = TRUE;
  }
  for(i = 0; i < MAX_CHANNELS; i++) {
    channel = &tracker->channels[i];
    soundCur = &channel->soundCur;
    soundPrev = &channel->soundPrev;
    subCursor = (real32)(soundCur->pitch * (real64)soundCur->index);
    soundCur->cursor = (int32)(subCursor);
    sampleT = ((subCursor - ((real32)soundCur->cursor)));
    if(soundCur->cursor >= soundCur->sampleEnd) {
      soundCur->index = 0;
      soundCur->cursor = 0;
      soundCur->playing = FALSE;
    }
    if(soundCur->sampleEnd != 0 && soundCur->playing) {
      data = &tracker->samples[soundCur->sampleIndex];
      dataPrev = &tracker->samples[soundPrev->sampleIndex];
      sample = ST_mixerSampleFromData(data, soundCur->cursor);
#if 1
      if(soundCur->cursor < soundCur->sampleEnd - 1 &&
          channel->interpolation) {
        sampleNext = ST_mixerSampleFromData(data, soundCur->cursor + 1);
        sample = ST_mixerSampleBlend(sample, sampleNext, sampleT);

      }
      sample = ST_mixerSampleMultiply(sample,
          soundCur->volumeL, soundCur->volumeR);
#endif
#if 1
      if(soundPrev->sampleEnd) {
        samplePrev = ST_mixerSampleFromData(dataPrev, soundPrev->cursor);
        samplePrev = ST_mixerSampleMultiply(samplePrev,
            soundPrev->volumeL, soundPrev->volumeR);
        sample =
          ST_mixerSampleBlend(samplePrev, sample, 1.0f - soundPrev->weight);
      }
#endif
      sample = ST_mixerSampleMultiply(sample,
          channel->volume,
          channel->volume);
      soundPrev->weight *= lerpAmt;
      mix = ST_mixerSampleAdd(mix, sample);
      g_sampleBuffersL[i][tracker->bufferCursor] = sample.left;
      g_sampleBuffersR[i][tracker->bufferCursor] = sample.right;
      soundCur->index++;
    } else {
      g_sampleBuffersL[i][tracker->bufferCursor] = 0.0f;
      g_sampleBuffersR[i][tracker->bufferCursor] = 0.0f;
    }
  }

  if(g_testInstrument.playing && g_testInstrument.sampleEnd) {
    testData = &tracker->samples[g_testInstrument.sampleIndex];
    testSample = ST_mixerSampleFromData(testData, g_testInstrument.cursor);
    g_testInstrument.cursor++;
    g_testInstrument.cursor %= g_testInstrument.sampleEnd;
    mix = ST_mixerSampleAdd(mix, testSample);
  }

#if 0
  mix.left = ST_filterLowPass(&g_butterLowPassLeft, mix.left);
  mix.right = ST_filterLowPass(&g_butterLowPassRight, mix.right);
#endif
#if 0
  mix.left = ST_filterHighPass(&g_butterHighPassLeft, mix.left);
  mix.right = ST_filterHighPass(&g_butterHighPassRight, mix.right);
#endif
#if 0
  mix.left = ST_filterTest(mix.left);
  mix.right = ST_filterTest(mix.right);
#endif
  g_masterBufferL[tracker->bufferCursor] = mix.left*master;
  g_masterBufferR[tracker->bufferCursor] = mix.right*master;
  
  if(tracker->playing) {
    ST_trackerTick(tracker, tempo);
  }
  tracker->bufferCursor++;
  tracker->bufferCursor %= MAX_CHANNEL_BUFFER;
  return ST_mixerSampleToInt16(ST_mixerSampleClip(mix, -1.0f, 1.0f, master));
}

/* interface ***************************************************************/

#if 0
SOY_GLOBAL int32 g_toolbarMoveButton = FALSE;
SOY_GLOBAL int32 g_toolbarMoveButtonReleased = FALSE;
SOY_GLOBAL int32 g_toolbarMoveButtonID = 0;
SOY_GLOBAL int32 g_toolbarMoveButtonSide = 0;
#endif

int32 ST_toolbarButtonsUpdate(soyApp* app, soyTracker* tracker,
    soyRect* buttons, int32 num,
    soyRect* rectLeft, soyRect* rectRight, real64 delta, int32 enable) {
  int32 i;
  int32 width = rectLeft->x2 - rectLeft->x1;
  int32 height = 17;
  int32 xPos = rectLeft->x1;
  int32 yPos = rectLeft->y2 + 1;
  for(i = 0; i < num; i++) {
    if(i == 8) { 
      xPos = rectRight->x1;
      yPos = rectRight->y2 + 1;
    }
    SOY_rectResize(&buttons[i],
        xPos, yPos,
        xPos + width, yPos + height);
    yPos += height + 1;
    SOY_rectUpdateBase(&buttons[i],
      tracker->mouseX, tracker->mouseY, tracker->mouseLeft);     

#if 0
    if(buttons[i].held && enable &&
        !SOY_boundsCheck(tracker->mouseX, tracker->mouseY,
          buttons[i].x1, buttons[i].y1, buttons[i].x2, buttons[i].y2)) {
      g_toolbarMoveButton = TRUE;
      g_toolbarMoveButtonID = i;
    }
    if(buttons[i].hover && g_toolbarMoveButton && enable) {
      if(!tracker->mouseLeft) {
        tempLabel = buttons[i].label;
        tempLabelLen = buttons[i].labelLen;
        buttons[i].label = buttons[g_toolbarMoveButtonID].label;
        buttons[i].labelLen = buttons[g_toolbarMoveButtonID].labelLen;
        buttons[g_toolbarMoveButtonID].label = tempLabel;
        buttons[g_toolbarMoveButtonID].labelLen = tempLabelLen;
        g_toolbarMoveButton = FALSE;
      }
    }
#endif
    if( SOY_rectReleased(&buttons[i]) && enable) {
      if(i < 8) {
        if(i%8 == g_menuStateLeft) {
        } else {
          g_menuStateLeft = i%8;
        }
      } else {
        if(i%8 == g_menuStateRight) {
        } else {
          g_menuStateRight = i%8;
        }
      }
    }
  }
  return TRUE;
}

SOY_GLOBAL real32 g_toolbarAnimTimer = 1.0f;
SOY_GLOBAL real32 g_animTime = 1.0f;
SOY_GLOBAL int32 g_toolbarAnimFinished = TRUE;

real32 ST_easeInBack(real32 x) {
  real32 c1 = 1.701580f;
  real32 c3 = c1 + 1.0f;
  return c3 * x * x * x - c1 * x * x;
}

real32 ST_easeOutBack(real32 x) {
  real32 c1 = 1.701580f;
  real32 c3 = c1 + 1.0f;
  return 1.0f + c3 * pow(x - 1.0f, 3.0f) + c1 * pow(x - 1.0f, 2.0f);
}
real32 ST_easeInOut(real32 x) {
  return x < 0.5f ? 
    16.0f * x * x * x * x * x : 
    1.0f - pow(-2.0f * x + 2.0f, 5.0f) / 2.0f;
}

int32 ST_interfaceResize(soyApp* app, soyTracker* tracker) {
  int32 i;
  int32 sides = g_visualEditor.labelWidth;
  int32 toolbarX1;
  int32 toolbarX2;
  int32 toolbarMid = 0;
  int32 toolbarWidth = 0;
  int32 pad = 11;
  int32 spacing = 2;
  int32 fontHeight = app->fontRegular->data.scaledDrawHeight;
  int32 toolbarHeightCompact = 20;
  int32 toolbarHeightFull = toolbarHeightCompact + (fontHeight + 4) * 8;
  int32 toolbarHeight = toolbarHeightCompact;
  soyRect* client = &tracker->clientRect;
  soyRect* toolbarLeft = &tracker->toolbarRectLeft;
  soyRect* toolbarRight = &tracker->toolbarRectRight;
  soyRect* toolbarToggleLeft = &tracker->toolbarToggleButtonLeft;
  soyRect* toolbarToggleRight = &tracker->toolbarToggleButtonRight;
  soyRect* editor = &tracker->editorRect; 
  SOY_rectResize(client,
      0 + pad, (SOY_isFullscreen(app) ? 0 : 24) + pad,
      SOY_width(app) - pad, SOY_height(app) - pad);
  toolbarHeight = 
    (int32)((real32)(toolbarHeightFull - toolbarHeightCompact) * 
        g_toolbarAnimTimer) + toolbarHeightCompact;
  
  toolbarX1 = client->x1 + spacing + sides;
  toolbarX2 = client->x2 - spacing - sides;

  toolbarWidth = (g_menuStateLeft >= 0 && g_menuStateRight >= 0) ? 
    (toolbarX2 - toolbarX1) / 2 : (toolbarX2 - toolbarX1);

  toolbarMid = toolbarX2 - 267;

  if(g_menuStateLeft >= 0 && g_menuStateRight >= 0) {
    SOY_rectResize(toolbarLeft,
      toolbarX1, client->y1 + spacing,
      toolbarMid, client->y1 + toolbarHeight);
    SOY_rectResize(toolbarRight,
      toolbarMid, client->y1 + spacing,
      toolbarX2, client->y1 + toolbarHeight);
  } else {
    SOY_rectResize(toolbarLeft,
      toolbarX1, client->y1 + spacing,
      toolbarX2, client->y1 + toolbarHeight);

    SOY_rectResize(toolbarRight,
      toolbarX1, client->y1 + spacing,
      toolbarX2, client->y1 + toolbarHeight);
  }

  SOY_rectResize(editor,
      client->x1 + spacing, client->y1 + toolbarHeight + spacing - 1,
      client->x2 - spacing, client->y2 - spacing);
    
  SOY_rectResize(toolbarToggleLeft,
      client->x1 + 2, toolbarLeft->y1,
      toolbarLeft->x1 - 1, toolbarLeft->y1 + toolbarHeightCompact - 2);

  SOY_rectResize(toolbarToggleRight,
      toolbarRight->x2 + 1, toolbarRight->y1,
      client->x2 - 2, toolbarRight->y1 + toolbarHeightCompact - 2);
 
  for(i = 0; i < 6; i++) {
    ST_menuViewResize(app,
        tracker, &g_menuLeft[i], &tracker->toolbarRectLeft);
    ST_menuViewResize(app,
        tracker, &g_menuRight[i], &tracker->toolbarRectRight);
  }
  
  ST_visualEditorResize(&g_visualEditor, tracker);
  return TRUE;
}

int32 ST_interfaceUpdate(soyApp* app, soyTracker* tracker, real64 delta) {
  real32 toolbarSpeed = 4.0f*0.1f;
  soyRect* toolbarToggleLeft = &tracker->toolbarToggleButtonLeft;
  soyRect* toolbarToggleRight = &tracker->toolbarToggleButtonRight;
  ST_toolbarButtonsUpdate(app, tracker,
      tracker->toolbarButtons, 16,
      toolbarToggleLeft, toolbarToggleRight, delta, g_toolbarFullSize);
  SOY_rectUpdateBase(&tracker->clientRect,
      tracker->mouseX, tracker->mouseY, tracker->mouseLeft); 
  SOY_rectUpdateBase(toolbarToggleLeft,
      tracker->mouseX, tracker->mouseY, tracker->mouseLeft); 
  SOY_rectUpdateBase(toolbarToggleRight,
      tracker->mouseX, tracker->mouseY, tracker->mouseLeft);
  if(SOY_rectReleased(toolbarToggleLeft) || 
      SOY_rectReleased(toolbarToggleRight)) {
    tracker->state ^= TRACKER_TOOLBAR_OPEN;
  }
  if(!tracker->state) {
    g_toolbarFullSize = FALSE;
    if(g_animTime > 0.0f) {
      g_animTime -= delta*toolbarSpeed;
    } else {
      g_toolbarAnimFinished = TRUE;
      g_animTime = 0.0f;
    }
  } else {
    g_toolbarAnimFinished = FALSE;
    if(g_animTime < 1.0f) {
      g_animTime += delta*toolbarSpeed;
    } else {
      g_toolbarFullSize = TRUE;
      g_animTime = 1.0f;
    }
  }
  g_toolbarAnimTimer = ST_easeInOut(g_animTime); 
  if(g_menuStateLeft >= 0) {
    ST_menuViewUpdate(app,
        tracker, &g_menuLeft[g_menuStateLeft], delta, TRUE);
  }
  if(g_menuStateRight >= 0) {
    ST_menuViewUpdate(app,
        tracker, &g_menuRight[g_menuStateRight], delta, TRUE);
  }
  return TRUE;
}

int32 ST_drawInterfaceButton(soyApp* app,
    soyRect* rect, int32 toggle, int8* text) {
  int32 textWidth = 0;
  int32 textPos = 0;
  int32 textOffset = 0;
  textOffset = (SOY_rectHeld(rect) || toggle);
  if(!textOffset) {
    SOY_drawUIRect(app->framebuffer,
      rect->x1, rect->y1, rect->x2, rect->y2, GUI_DARK);
  } else {
    SOY_drawUIRect(app->framebuffer,
      rect->x1, rect->y1, rect->x2, rect->y2, GUI_INVERT);
  }
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_CHANNEL_TEXT_A));
  if(text) {
    textWidth = SOY_drawTextWidth(app->fontRegular, text);
    textPos = (rect->x2 - rect->x1) / 2 - textWidth / 2 - 2;
    SOY_drawText(app->framebuffer, app->fontRegular,
        rect->x1 + textPos + textOffset, rect->y1 + 2 + textOffset, text);
  }
  return TRUE;
}

int32 ST_drawToolbarButtons(soyApp* app,
    soyTracker* tracker, soyRect* buttons, int32 count) {
  int32 i;
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_CHANNEL_TEXT_A));
  for(i = 0; i < count; i++) {
    if(i < count/2 && i%(count/2) == g_menuStateLeft) {
      SOY_drawButtonToggled(app->framebuffer, app->fontRegular, &buttons[i]);
    } else if(i >= count/2 && i%(count/2) == g_menuStateRight) {
      SOY_drawButtonToggled(app->framebuffer, app->fontRegular, &buttons[i]);
    } else {
      SOY_drawButton(app->framebuffer, app->fontRegular, &buttons[i]);
    }
  }
  return TRUE;
}

int32 g_titleScreenTime = 0;

int32 ST_drawTitleScreen(soyApp* app, soyTracker* tracker) {
  int8* stringA = SOY_getVersionString(
      TRACKER_TITLE,
      RELEASE_VERSION,
      MAJOR_VERSION,
      MINOR_VERSION);
  int8* stringB = AUTHOR_TITLE;
  soyRect rect = SOY_rect(
      tracker->toolbarRectLeft.x1,
      tracker->toolbarRectLeft.y1,
      tracker->toolbarRectRight.x2,
      tracker->toolbarRectRight.y2);
  int32 halfWidth = rect.x1 + rect.width/2;
  int32 halfHeight = rect.y1 + rect.height/2;
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_LIGHTEST));
  SOY_drawText(app->framebuffer, app->fontBold,
      halfWidth - SOY_drawTextWidth(app->fontBold, stringA)/2 + 1,
      halfHeight - app->fontBold->data.scaledDrawHeight/2 + 1,
      stringA);
  SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_DARKEST));
  SOY_drawText(app->framebuffer, app->fontBold,
      halfWidth - SOY_drawTextWidth(app->fontBold, stringA)/2,
      halfHeight - app->fontBold->data.scaledDrawHeight/2,
      stringA);
  if(tracker->toolbarRectLeft.height > 32) {
    SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_LIGHTEST));
    SOY_drawText(app->framebuffer, app->fontSmall,
        halfWidth - SOY_drawTextWidth(app->fontSmall, stringB)/2 + 1,
        halfHeight + app->fontBold->data.scaledDrawHeight/2,
        stringB);
    SOY_drawSetColour(app->framebuffer, SOY_indexColour(PAL_DARKEST));
    SOY_drawText(app->framebuffer, app->fontSmall,
        halfWidth - SOY_drawTextWidth(app->fontSmall, stringB)/2,
        halfHeight + app->fontBold->data.scaledDrawHeight/2,
        stringB);
  }
  return TRUE;
}

int32 ST_drawInterface(soyApp* app, soyTracker* tracker, real64 delta) {
  soyCanvas* canvas = app->framebuffer;
  int8* toggleText = tracker->state & TRACKER_TOOLBAR_OPEN ? "---" : "+++";
  SOY_drawSetColour(canvas, SOY_indexColour(PAL_LIGHT));
  SOY_drawUIRectThick(
      canvas,
      0,
      (SOY_isFullscreen(app)) ? 0 : 24,
      SOY_width(app),
      SOY_height(app), GUI_FILL);
  
  SOY_drawUIRect(app->framebuffer,      
      tracker->clientRect.x1 - 2,
      tracker->clientRect.y1 - 2,
      tracker->clientRect.x2 + 2,
      tracker->clientRect.y2 + 2, GUI_DARK);
  
  if(g_menuStateLeft >= 0) {
    SOY_drawUIRect(app->framebuffer,
      tracker->toolbarRectLeft.x1,
      tracker->toolbarRectLeft.y1,
      tracker->toolbarRectLeft.x2,
      tracker->toolbarRectLeft.y2, GUI_DARK);
    ST_menuViewRender(app, tracker, &g_menuLeft[g_menuStateLeft], delta);
  }

  if(g_menuStateRight >= 0) {
    SOY_drawUIRect(app->framebuffer,      
      tracker->toolbarRectRight.x1,
      tracker->toolbarRectRight.y1,
      tracker->toolbarRectRight.x2,
      tracker->toolbarRectRight.y2, GUI_DARK);
    ST_menuViewRender(app, tracker, &g_menuRight[g_menuStateRight], delta);
  }

  if(g_menuStateLeft == -1 && g_menuStateRight == -1) {
    SOY_drawUIRect(app->framebuffer,
      tracker->toolbarRectLeft.x1,
      tracker->toolbarRectLeft.y1,
      tracker->toolbarRectRight.x2,
      tracker->toolbarRectRight.y2, GUI_DARK);
    ST_drawTitleScreen(app, tracker);
  }

  if(!g_toolbarAnimFinished) {
    ST_drawToolbarButtons(app, tracker, tracker->toolbarButtons, 16);
  }

  ST_drawInterfaceButton(app, &tracker->toolbarToggleButtonLeft,
      tracker->state & TRACKER_TOOLBAR_OPEN, toggleText);
  ST_drawInterfaceButton(app, &tracker->toolbarToggleButtonRight,
      tracker->state & TRACKER_TOOLBAR_OPEN, toggleText);

  ST_drawVisualEditor(app, tracker, &g_visualEditor);
  return TRUE;
}

/* tracker *****************************************************************/

int32 ST_setMenuState(void* args, soyMenuState state) {
  soyTracker* tracker = (soyTracker*)args;
  tracker->menuX = 0;
  tracker->menuY = 0;
  return TRUE;
}

SOY_GLOBAL int64 g_lastTime = 0;
SOY_GLOBAL int64 g_curTime = 0;

int32 ST_trackerUpdate(soyApp* app, soyTracker* tracker,
    soyVisualEditor* editor) {
  real64 bpm = (real64)tracker->tempo;
  real64 ticks = (real64)tracker->ticks;
  if(ticks > 0) {
    tracker->realTempo =
      (tracker->sampleRate / ((bpm*4.0) / ((ticks*10.0)/6.0)));
  } else {
    tracker->realTempo = 0.0;
  }
  
  tracker->mouseX = SOY_mouseX(app);
  tracker->mouseY = SOY_mouseY(app);

  tracker->mouseLeft += (tracker->mouseLeft == 1);
  tracker->mouseRight += (tracker->mouseRight == 1);
  tracker->mouseMiddle += (tracker->mouseMiddle == 1);

  if(!SOY_keyState(app, SOY_LBUTTON)) { tracker->mouseLeft = 0; }
  if(!SOY_keyState(app, SOY_RBUTTON)) { tracker->mouseRight = 0; }
  if(!SOY_keyState(app, SOY_MBUTTON)) { tracker->mouseMiddle = 0; }

  if(SOY_keyHeld(app, SOY_CONTROL)) {
    if(SOY_keyPressed(app, SOY_1)) {
      ST_setMenuState(tracker, MENU_INFO);
    }
    if(SOY_keyPressed(app, SOY_2)) {
      ST_setMenuState(tracker, MENU_SONG);
    }
    if(SOY_keyPressed(app, SOY_3)) {
      ST_setMenuState(tracker, MENU_DISK);
    }
    if(SOY_keyPressed(app, SOY_4)) {
      ST_setMenuState(tracker, MENU_FREQ);
    }
    if(SOY_keyPressed(app, SOY_5)) {
      ST_setMenuState(tracker, MENU_CONF);
    }
    if(SOY_keyPressed(app, SOY_6)) {
      ST_setMenuState(tracker, MENU_LOG);
    }
    if(SOY_keyPressed(app, SOY_7)) {
      ST_setMenuState(tracker, MENU_HELP);
    }
  }
  g_curTime = SOY_wallClock();
  g_lastTime = g_curTime;
  return TRUE;
}

/* actions *****************************************************************/

int32 ST_actionSampleLoad(void* args) {
  soyTrackerSample* curSample = &g_tracker.samples[g_sampleViewCurSample];
  ST_loadRAW(curSample, g_fileViewBuffer[g_fileViewSelection]);
  return TRUE;
}

int32 ST_actionSamplePlay(void* args) {
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) { return FALSE; }
  if(!g_testInstrument.playing) {
    g_testInstrument = ST_instrument(g_sampleViewCurSample, 0, samp->length);
    g_testInstrument.cursor = 0;
    g_testInstrument.playing = TRUE;
    return TRUE;
  } else {
    g_testInstrument.cursor = 0;
    g_testInstrument.playing = FALSE;
    return FALSE;
  }
  return TRUE;
}

int32 ST_actionSampleStop(void* args) {
  if(g_isRecording) { return FALSE; }
  g_testInstrument.cursor = 0;
  g_testInstrument.playing = FALSE;
  return TRUE;
}

int32 ST_actionSampleNew(void* args) {
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) {
    SOY_memorySet(samp->data, 0, MAX_SAMPLE_SIZE*sizeof(int16));
  } else {
    ST_sampleInit(samp);
  }
  g_recordCursor = 0;
  g_testInstrument.playing = FALSE;
  g_testInstrument.sampleEnd = 0;
  g_testInstrument.cursor = 0;
  return TRUE;
}

int32 ST_actionSampleRec(void* args) {
  if(g_testInstrument.playing) { return FALSE; }
  if(!g_isRecording && g_recordCursor < MAX_SAMPLE_SIZE) {
    SOY_audioStartCapture((soyApp*)args);
    g_isRecording = TRUE;
  } else {
    SOY_audioStopCapture((soyApp*)args);
    g_isRecording = FALSE;
  }
  return TRUE;
}

int32 ST_actionSampleName(void* args) {
  g_recordCursor = 0;
  return TRUE;
}

int32 ST_actionSamplePrev(void* args) {
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) { return FALSE; }
  ST_sampleViewPrev();
  g_testInstrument = ST_instrument(g_sampleViewCurSample, 0, samp->length);
  return TRUE;
}

int32 ST_actionSampleNext(void* args) {
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) { return FALSE; }
  ST_sampleViewNext();
  g_testInstrument = ST_instrument(g_sampleViewCurSample, 0, samp->length);
  return TRUE;
}

int32 ST_actionSampleAmp(void* args) {
  int32 i;
  real32 amp = 1.1f;
  real32 input = 0.0f;
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(samp->length == 0) { return FALSE; }
  if(g_isRecording) { return FALSE; }
  for(i = start; i < end; i++) {
    input = (((real32)samp->data[i])/(real32)MAX_AMP);
    input*=amp;
    samp->data[i] =
      (int16)(SOY_MIN(SOY_MAX(input, -1.0f), 1.0f)*(real32)MAX_AMP);
  }
  return TRUE;
}

int32 ST_actionSampleDeAmp(void* args) {
  int32 i;
  real32 amp = 0.9f;
  real32 input = 0.0f;
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(samp->length == 0) { return FALSE; }
  if(g_isRecording) { return FALSE; }
  for(i = start; i < end; i++) {
    input = (((real32)samp->data[i])/(real32)MAX_AMP);
    input*=amp;
    samp->data[i] =
      (int16)(SOY_MIN(SOY_MAX(input, -1.0f), 1.0f)*(real32)MAX_AMP);
  }
  return TRUE;
}

int32 ST_actionSampleNorm(void* args) {
  int32 i;
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 max = 0;
  int32 temp = 0;
  int32 maxAmp = MAX_AMP;
  real32 dif = 0.0f;
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(samp->length == 0) { return FALSE; }
  if(g_isRecording) { return FALSE; }
  for(i = start; i < end; i++) {
    if(SOY_abs(samp->data[i]) >= max) { max = SOY_abs(samp->data[i]); }
  }
  temp = maxAmp - max;
  dif = (real32)temp / (real32)maxAmp;
  for(i = start; i < end; i++) {
    samp->data[i] = (int32)((real32)samp->data[i] / (1.0f - dif));
  }
  return TRUE;
}

int32 ST_actionTest(void* args) {
  int32 i;
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) { return FALSE; }
  if(samp->length == 0) { return FALSE; }
  if(!g_filterTestInit) {
    ST_filtersInit();
    g_filterTestInit = TRUE;
  }
  for(i = start; i < end; i++) {
    samp->data[i] = ST_toShort(
        ST_filterTest(ST_toReal(samp->data[i])));
  }
  return TRUE;
}

int32 ST_actionSampleFadeIn(void* args) {
  int32 i;
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  real32 fadeAmt = 1.0f;
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) { return FALSE; }
  if(samp->length == 0) { return FALSE; }
  for(i = start; i < end; i++) {
    fadeAmt = ((real32)(i - start) / (real32)(end - start));
    samp->data[i] = (int32)((real32)samp->data[i] * (fadeAmt));
  }
  return TRUE;
}

int32 ST_actionSampleFadeOut(void* args) {
  int32 i;
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  real32 fadeAmt = 1.0f;
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) { return FALSE; }
  if(samp->length == 0) { return FALSE; }
  for(i = start; i < end; i++) {
    fadeAmt = 1.0f - ((real32)(i - start) / (real32)(end - start));
    samp->data[i] = (int32)((real32)samp->data[i] * (fadeAmt));
  }
  return TRUE;
}

int32 ST_actionSampleRev(void* args) {
  int32 i;
  int16 temp;
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(samp->length == 0) { return FALSE; }
  if(g_isRecording) { return FALSE; }
  for(i = start; i < start + (end - start)/2; i++) {
    temp = samp->data[i];
    samp->data[i] = samp->data[(end - 1) - (i - start)];
    samp->data[(end - 1) - (i - start)] = temp;
  }
  return TRUE;
}

int32 ST_actionSampleTrim(void* args) {
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB); 
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(samp->length == 0) { return FALSE; }
  if(g_isRecording) { return FALSE; }
  SOY_memoryCopy(samp->data, samp->data + start,
      (end - start)*sizeof(int16));
  SOY_memorySet(
      samp->data + (end - start),
      0,
      (samp->length - (end - start))*sizeof(int16));
  samp->length = (end - start);
  g_sampleViewSelectionA = 0;
  g_sampleViewSelectionB = samp->length;
  return TRUE;
}

int32 ST_actionSampleCut(void* args) {
  int32 start = SOY_MIN(g_sampleViewSelectionA, g_sampleViewSelectionB);
  int32 end = SOY_MAX(g_sampleViewSelectionA, g_sampleViewSelectionB);
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(samp->length == 0) { return FALSE; }
  if(g_isRecording) { return FALSE; }
  SOY_memoryCopy(samp->data + start, samp->data + end,
      (samp->length - end)*sizeof(int16));
  SOY_memorySet(
      samp->data + samp->length - (end - start),
      0,
      (end - start)*sizeof(int16));
  g_sampleViewSelectionA = start;
  g_sampleViewSelectionB = start;
  samp->length -= (end - start);
  return TRUE;
}

/* callbacks ***************************************************************/

int32 ST_mouseCallback(soyApp* app, int32 button, int32 state) {
#if 1
  if(button == SOY_MOUSE_LEFT) { g_tracker.mouseLeft = state; }
  if(button == SOY_MOUSE_RIGHT) { g_tracker.mouseRight = state; }
  if(button == SOY_MOUSE_MIDDLE) { g_tracker.mouseMiddle = state; }
#endif
  return TRUE;
}

int32 ST_keyCallback(soyApp* app, int32 key, int32 state) {
  soyTracker* tracker = &g_tracker;
  soyVisualEditor* editor = &g_visualEditor;
  soyTrackList* list = &tracker->trackList;

  soyPattern* pattern = &tracker->patterns[list->current->patternIndex];
  soyTrackerNode* channel = pattern->nodes[editor->selectedTrack];
  soyTrackerNode* node = &channel[editor->selectedNode];

  int32 sV = 1;
  int32 sH = 1;

  if(editor->state == EDITOR_PATTERN) {
    pattern = &tracker->patterns[editor->selectedPattern];
    channel = pattern->nodes[editor->selectedTrack];
    node = &channel[editor->selectedNode];
  }

  if(SOY_keyHeld(app, SOY_SHIFT)) { sV = 4; sH = 2; }
  if(editor->selectedControl % 2 != 0) { sH = 1; }
  
  if(!state) { return FALSE; }
  
   if(SOY_keyPressed(app, SOY_F9)) {
    g_debugSwitch = !g_debugSwitch;
  }

  if(!g_keyboardConfigured) {
    if(key == SOY_ESC) { g_keyboardConfigured = TRUE; }
    if(SOY_alphanumeric(key)) {
      ST_updateVirtualKeyboard(g_keyboardConfCounter++, (uint8)key);
    } else if(key == SOY_BACKSPACE && g_keyboardConfCounter > 0) {
      g_keyboardConfCounter--;
    }
    if(g_keyboardConfCounter == 36) {
      g_keyboardConfigured = TRUE;
    }
    return TRUE;
  }

  if(key == SOY_BACKSPACE) {
    if(SOY_keyHeld(app, SOY_SHIFT)) {
      ST_visualEditorClearNodeControl(editor, ST_curNode(tracker, editor),
          editor->selectedControl/2);
    } else {
      ST_visualEditorClearNode(editor, ST_curNode(tracker, editor));
    }
    return TRUE;
  }

  if(key == SOY_F4) {
    if(!editor->scrollEnable) {
      editor->scrollEnable = TRUE;
      if(tracker->playing) {
        ST_visualEditorMoveTo(editor, tracker->playCursor);
        editor->nodeEnd = tracker->playCursor + editor->nodeNum;
      }
    } else {
      editor->scrollEnable = FALSE;
    }
  }

  if(key == SOY_ESC) {
    tracker->playing = FALSE;
    tracker->playCursor = 0;
    ST_visualEditorMoveTo(editor, 0);
    if(editor->state == EDITOR_PATTERN) {
      tracker->trackList.current = tracker->trackList.first;
    }
  }

  if(key == SOY_SPACE) {
    tracker->playing = !tracker->playing;
    if(editor->scrollEnable) {
      ST_visualEditorMoveTo(editor, tracker->playCursor);
      editor->nodeEnd = tracker->playCursor + editor->nodeNum;
    }
  }

  if(SOY_keyHeld(app, SOY_CONTROL)) {
    if(key == SOY_S) {
      tracker->playing = !tracker->playing;
      if(editor->scrollEnable) {
        ST_visualEditorMoveTo(editor, tracker->playCursor);
        editor->nodeEnd = tracker->playCursor + editor->nodeNum;
      }
    }

    if(key == SOY_P) {
      tracker->playing = !tracker->playing;
      if(editor->scrollEnable) {
        ST_visualEditorMoveTo(editor, tracker->playCursor);
        editor->nodeEnd = tracker->playCursor + editor->nodeNum;
      }
    }

    if(key == SOY_B) {
      tracker->playCursor = 0;
      if(editor->scrollEnable) {
        ST_visualEditorMoveTo(editor, tracker->playCursor);
        editor->nodeEnd = tracker->playCursor + editor->nodeNum;
      }
    }
    if(key == SOY_E) {
      tracker->playCursor = editor->maxNodes - 1;
      if(editor->scrollEnable) {
        ST_visualEditorMoveTo(editor, tracker->playCursor);
        editor->nodeEnd = tracker->playCursor + editor->nodeNum;
      }
    }
  }

  if(!SOY_keyHeld(app, SOY_CONTROL)) {
    ST_visualEditorNodeUpdate(editor, node, key, sV, tracker->playing);
    if(key == SOY_LEFT) { ST_visualEditorMoveSkip(editor, SOY_LEFT, sH); }
    if(key == SOY_RIGHT) { ST_visualEditorMoveSkip(editor, SOY_RIGHT, sH); }
    if(key == SOY_UP) { ST_visualEditorMoveSkip(editor, SOY_UP, sV); }
    if(key == SOY_DOWN) { ST_visualEditorMoveSkip(editor, SOY_DOWN, sV); }
    tracker->playCursor = editor->selectedNode;
  }

  if(key == SOY_PGUP) {
    ST_visualEditorMoveTo(editor, 0);
    tracker->playCursor = 0;
  }

  if(key == SOY_PGDOWN) {
    ST_visualEditorMoveTo(editor, editor->maxNodes - 1);
    tracker->playCursor = editor->selectedNode;
    editor->nodeEnd = editor->maxNodes;
    if(editor->scrollEnable) {
      editor->nodeEnd += editor->nodeNum;
    }
  }

  if(key == SOY_TAB) {
    if(SOY_keyHeld(app, SOY_SHIFT)) {
      ST_visualEditorMoveChannel(&g_visualEditor, 0);
    } else {
      ST_visualEditorMoveChannel(&g_visualEditor, 1);
    }
  }

  return TRUE;
}

int32 toneHz = 440;
int32 toneVolume = 8000;

int32 ST_audioCallback(soyApp* app, int16* left, int16* right) {
#if 1
  soySampleResult sr = ST_mixerUpdate(&g_tracker, g_tracker.realTempo);
  
  *left = sr.left;
  *right = sr.right;
#else
  real32 toneValue = (real32)sin(app->audio.timer);
  real32 sampleValue = (int16)(toneValue * (real32)toneVolume);
  *left = sampleValue;
  *right = sampleValue;
#endif
  return TRUE;
}

int32 ST_audioCaptureCallback(soyApp* app, int16 left, int16 right) {
  int32 mix = ((int32)left + (int32)right)/2;
  soyTrackerSample* samp = &g_tracker.samples[g_sampleViewCurSample];
  if(g_isRecording) {
    mix = SOY_MIN(SOY_MAX(mix, MIN_AMP), MAX_AMP);
    samp->data[g_recordCursor++] = (mix);
    samp->length = g_recordCursor;
    g_tracker.instruments[g_sampleViewCurSample].sampleEnd = samp->length;
    if(g_recordCursor >= MAX_SAMPLE_SIZE) {
      g_isRecording = FALSE;
    }
  }

  return TRUE;
}

/* module ******************************************************************/

int32 SOY_libStart(soyApp* app) {
  soyRect* toolbarButtons = g_tracker.toolbarButtons;
  SOY_LOG("Starting soyTracker\n");
  SOY_memorySectorCreate("SL_LOAD", &loadMemory, Megabytes(4));
  SOY_memorySectorCreate("SL_SOUND", &soundMemory, Megabytes(64));
  SOY_memorySectorCreate("SL_TEMPSAMPLE", &tempSampleMemory, Megabytes(8));
  SOY_memorySectorCreate("SL_SPECTRO", &spectroCanvasMemory, Megabytes(16));

  SOY_canvasCreate(&spectroCanvasMemory, &g_spectroCanvas, 1920, 1080);

  SOY_registerKeyCallback(app, ST_keyCallback);
  SOY_registerAudioCallback(app, ST_audioCallback);
  SOY_registerAudioCaptureCallback(app, ST_audioCaptureCallback);
  SOY_registerMouseCallback(app, ST_mouseCallback);

  ST_trackerInit(&g_tracker, app->audio.samplingRate);
  g_tracker.sampleBufferSize = SOY_MIN(MAX_CHANNEL_BUFFER, 512);
  g_tracker.font = app->fontRegular;
  g_tracker.fontSmall = app->fontSmall;
  g_tracker.fontBold = app->fontBold;
  g_testInstrument = ST_instrument(0, 0, 0);

  ST_visualMixerInit(&g_visualMixer);
  ST_visualEditorInit(&g_visualEditor, app->fontRegular);
  ST_effectRackInitAll(g_effectRacks);

  ST_loadSoundBank(&g_tracker, "*.raw");

  toolbarButtons[0] = SOY_rectAction("INF", NULL, NULL);
  toolbarButtons[1] = SOY_rectAction("VIS", NULL, NULL);
  toolbarButtons[2] = SOY_rectAction("FRQ", NULL, NULL);
  toolbarButtons[3] = SOY_rectFlag("", RECT_DISABLED);
  toolbarButtons[4] = SOY_rectFlag("", RECT_DISABLED);
  toolbarButtons[5] = SOY_rectFlag("", RECT_DISABLED);
  toolbarButtons[6] = SOY_rectFlag("", RECT_DISABLED);
  toolbarButtons[7] = SOY_rectFlag("", RECT_DISABLED);

  toolbarButtons[8] = SOY_rectAction("TRK", NULL, NULL);
  toolbarButtons[9] = SOY_rectAction("MIX", NULL, NULL);
  toolbarButtons[10] = SOY_rectAction("SMP", NULL, NULL);
  toolbarButtons[11] = SOY_rectAction("INS", NULL, NULL);
  toolbarButtons[12] = SOY_rectAction("EFF", NULL, NULL);
  toolbarButtons[13] = SOY_rectAction("DSK", NULL, NULL);
  toolbarButtons[14] = SOY_rectAction("CFG", NULL, NULL);
  toolbarButtons[15] = SOY_rectAction(" ? ", NULL, NULL);

  g_menuRight[0] = ST_menuView("TRACK", 4, NULL);
  g_menuRight[1] = ST_menuView("MIXER", 4, ST_mixerMenuRenderProc);
  g_menuRight[2] = ST_menuView("SAMPLE", 4, NULL)
    .addButton(SOY_rectActionToggle("Play", ST_actionSamplePlay, app, 0))
    .addButton(SOY_rectActionToggle("Rec", ST_actionSampleRec, app, 0))
    .addButton(SOY_rectAction("New", ST_actionSampleNew, app))
    .addButton(SOY_rectAction("Load", ST_actionSampleLoad, app))
    .addButton(SOY_rectAction("Trim", ST_actionSampleTrim, app))
    .addButton(SOY_rectAction("Cut", ST_actionSampleCut, app))
    .addButton(SOY_rectAction("Rev", ST_actionSampleRev, app))
    .addButton(SOY_rectAction("Norm", ST_actionSampleNorm, app))
    .addButton(SOY_rectAction("Amp-", ST_actionSampleDeAmp, app))
    .addButton(SOY_rectAction("Amp+", ST_actionSampleAmp, app))
    .addButton(SOY_rectAction("Fade In", ST_actionSampleFadeIn, app))
    .addButton(SOY_rectAction("Fade Out", ST_actionSampleFadeOut, app))
    .addButton(SOY_rectAction("Test", ST_actionTest, app))
    .setOffset(84);

  g_menuRight[3] = ST_menuView("INSTRUMENT", 4, NULL)
    .addButton(SOY_rectAction("Prev", NULL, NULL))
    .addButton(SOY_rectAction("Prev", NULL, NULL))
    .addButton(SOY_rectAction("Prev", NULL, NULL))
    .addButton(SOY_rectAction("Next", NULL, NULL));
  g_menuRight[4] = ST_menuView("EFFECT", 4, NULL);
  g_menuRight[5] = ST_menuView("DISK", 4, NULL);
  
  g_menuLeft[0] = ST_menuView("Info", 2, ST_displayViewRenderProc);
  g_menuLeft[1] = ST_menuView("Visual", 2, ST_visualViewRenderProc);
  g_menuLeft[2] = ST_menuView("Spectro", 2, ST_spectroViewRenderProc);
  g_menuLeft[3] = ST_menuView("Config", 2, NULL);
  g_menuLeft[4] = ST_menuView("About", 2, NULL);
  g_menuLeft[5] = ST_menuView("Help", 2, NULL);
  
  SOY_audioStart(app);
  return TRUE;
}

int32 SOY_libUpdate(soyApp* app, real64 dt) {
  ST_trackerUpdate(app, &g_tracker, &g_visualEditor);
#if 1
  if(!SOY_windowIsMinimized(app->windowHandle)) {
    ST_interfaceUpdate(app, &g_tracker, dt);
    ST_interfaceResize(app, &g_tracker);
  }
#endif
#if 0
  ST_computeFFT(app, &g_tracker, g_tracker.fftSize);
#endif
  return TRUE;
}

int32 SOY_libRender(soyApp* app, real64 dt) {
  if(!SOY_windowIsMinimized(app->windowHandle)) {
    ST_drawInterface(app, &g_tracker, dt);
  }
#ifdef TRACKER_DEBUG
  g_keyboardConfigured = TRUE;
#else
  if((!g_keyboardConfigured) || (g_fadeTimer)) {
    ST_drawVirtualKeyboard(app, &g_tracker);
  }
#endif
  return TRUE;
}

int32 SOY_libStop(soyApp* app) {
  SOY_memorySectorFree(&loadMemory);
  SOY_memorySectorFree(&soundMemory);
  return TRUE;
}

/* entry *******************************************************************/

int32 cp = 0;

int32 ST_saveState(soyApp* app, soyTracker* tracker, int8* filename) {
  FILE* file = SOY_fileOpen(filename, "wb");
  if(file != NULL) {
    fwrite(tracker->patterns, sizeof(soyPattern)*MAX_PATTERNS, 1, file);
    fwrite(g_visualMixer.faders, sizeof(real32)*MAX_CHANNELS, 1, file);
    fwrite(&tracker->tempo, sizeof(int32), 1, file);
    fwrite(&tracker->ticks, sizeof(int32), 1, file);
    fwrite(&cp, sizeof(int32), 1, file);
    SOY_fileClose(file);
  } else {
    SOY_LOG1("Error! File was NULL! %s\n", filename);
  }
  return TRUE;
}

int32 ST_loadState(soyApp* app, soyTracker* tracker, int8* filename) {
  FILE* file = SOY_fileOpen(filename, "rb");
  if(file != NULL) {
    fread(tracker->patterns, sizeof(soyPattern)*MAX_PATTERNS, 1, file);
    fread(g_visualMixer.faders, sizeof(real32)*MAX_CHANNELS, 1, file);
    fread(&tracker->tempo, sizeof(int32), 1, file);
    fread(&tracker->ticks, sizeof(int32), 1, file);
    fread(&cp, sizeof(int32), 1, file);
    SOY_fileClose(file);
  } else {
    SOY_LOG1("Error! File was NULL! %s\n", filename);
  }
  return TRUE;
}

int32 SOY_userStart(soyApp* app) {
  SOY_setResolution(app, 2);
  SOY_makePalette(32, PALETTE_A);
  SOY_libStart(app);
  ST_loadState(app, &g_tracker, "t_state.soy");
  switch(cp) {
    case(0): { SOY_makePalette(32, PALETTE_A); break; }
    case(1): { SOY_makePalette(32, PALETTE_B); break; }
    case(2): { SOY_makePalette(32, PALETTE_C); break; }
    case(3): { SOY_makePalette(32, PALETTE_D); break; }
  }
  return TRUE;
}

#define MAX_FFT 48000

typedef struct tag_soyFFT {
  soyComplex sampleData[MAX_FFT];
  soyComplex transformedData[MAX_FFT];
  int32 size;

  real32 freq;
  real32 samplingRate;
  real32 fac;
} soyFFT;

int32 ST_fftInit(soyFFT* fft) {
  SOY_memorySet(fft->sampleData, 0, sizeof(real32)*MAX_FFT);
  SOY_memorySet(fft->transformedData, 0, sizeof(real32)*MAX_FFT);
  fft->size = 0;
  fft->freq = 440.0f;
  fft->samplingRate = 48000.0f;
  fft->fac = fft->samplingRate * (fft->freq / fft->samplingRate);
  return TRUE;
}

int32 ST_fftPush(soyFFT* fft, real32 valueReal, real32 valueImag) {
  if(fft->size < MAX_FFT) {
    fft->sampleData[fft->size].real = valueReal;
    fft->sampleData[fft->size].imag = valueImag;
    fft->size++;
  } else {
    SOY_LOG("Insufficient fft size\n");
  }
  return TRUE;
}

SOY_GLOBAL int32 g_fftInit = FALSE;
SOY_GLOBAL soyFFT g_fft;

SOY_GLOBAL real32 g_fftTime = 0.0f;

int32 ST_fourierInit(soyApp* app,
    int32 size, real32 freq1, real32 freq2, real32 freq3) {
  int32 i;
  real32 v;
  ST_fftInit(&g_fft);
  real32 fac1 = g_fft.samplingRate * (freq1 / g_fft.samplingRate);
  real32 fac2 = g_fft.samplingRate * (freq2 / g_fft.samplingRate);
  real32 fac3 = g_fft.samplingRate * (freq3 / g_fft.samplingRate);
  for(i = 0; i < size; i++) {
    v = sin(((real32)i / (real32)MAX_FFT)*SOY_2PI*fac1); 
    if(freq2 > 0.0f) {
      v += sin(((real32)i / (real32)MAX_FFT)*SOY_2PI*fac2); 
    }
    if(freq3 > 0.0f) {
      v += sin(((real32)i / (real32)MAX_FFT)*SOY_2PI*fac3); 
    }
    ST_fftPush(&g_fft, v, 0.0f);
  }
  
  return TRUE;
}

int32 SOY_fourierCompute(soyApp* app,
    soyFFT* fft, int32 xOffset, int32 yOffset) {


  return TRUE;
}

#if 1
int32 ST_fourierDrawDiscrete(soyApp* app, int32 xOffset, int32 yOffset) {
  int32 i, j;
  real32 v = 0.0f;
  int32 probe = 0;
  real32 scale = 50.0f;
  real32 cx = 0.0f;

  real32 fi = 0.0f;
  real32 fr = 0.0f;
  real32 csumX = 0.0f;
  real32 csumY = 0.0f;

  int32 pcsumX = 0;
  int32 pcsumY = 0;

  real32 probeFreq = (real32)SOY_mouseX(app) / (real32)SOY_width(app);
  real32 dist = 0.0f;
  probeFreq *= g_fft.fac;
  probeFreq = SOY_MAX(probeFreq, 1.0f);
  SOY_drawLine(app->framebuffer,
      xOffset, yOffset, xOffset + g_fft.size, yOffset);
  pcsumX = 0;
  pcsumY = 0;
  for(i = 1; i < g_fft.size; i++) {
    csumX = 0.0f;
    csumY = 0.0f;
    for(j = 0; j < g_fft.size; j++) {
      probe = j%i;
      v = g_fft.sampleData[j].real;    
      cx = ((real32)probe / (real32)i)*SOY_2PI;
      fi = sin(cx)*(v*0.5f + 0.5f)*0.2f;
      fr = cos(cx)*(v*0.5f + 0.5f)*0.2f;
      csumX += fi;
      csumY += fr;
    }
    SOY_drawSetColour(app->framebuffer, SOY_pixel(
          i%255, 255 - i%255, 255, 255));
    
    dist = SOY_distance(0.0f, 0.0f, csumX, csumY);
#if 1
    SOY_drawLine(app->framebuffer,
        xOffset + g_fft.size -  i,
        yOffset,
        xOffset + g_fft.size - i,
        yOffset - (int32)(dist)
        );   
#endif
    pcsumX = (int32)csumX;
    pcsumY = (int32)csumY;
  }
  SOY_drawLine(app->framebuffer,
      xOffset + probeFreq,
      yOffset,
      xOffset + probeFreq,
      yOffset - (int32)scale
      );
  return TRUE;
}
#endif

int32 ST_fftRearangeInplace(soyComplex* data, uint32 n) {
  uint32 pos;
  uint32 mask;
  uint32 target = 0;
  soyComplex temp = data[target];
  for(pos = 0; pos < n; pos++) {
    if(target > pos) {
      temp = data[target];
      data[target] = data[pos];
      data[pos] = temp;
    }
    mask = n;
    while(target & (mask >>= 1)) {
      target &= ~mask;
    }
    target |= mask;
  }
  return TRUE;
}

int32 ST_fftRearange(soyComplex* data, soyComplex* output, uint32 n) {
  uint32 pos;
  uint32 mask;
  uint32 target = 0;
  for(pos = 0; pos < n; pos++) {
    output[target] = data[pos];
    mask = n;
    while(target & (mask >>= 1)) {
      target &= ~mask;
    }
    target |= mask;
  }
  return TRUE;
}

int32 ST_fftEval(soyComplex* data, uint32 n, uint32 inverse) {
  uint32 step, group, pair;
  uint32 jump;
  real32 delta;
  real32 sine;
  soyComplex mul;
  soyComplex fac;
  real32 facReal;
  uint32 match;
  soyComplex product;
  real32 pi = inverse ? SOY_PI : -SOY_PI; 
  for(step = 1; step < n; step <<= 1) {
    jump = step << 1;
    delta = pi / (real32)step;
    sine = sin(delta * 0.5f);
    mul.real = -2.0f * sine * sine;
    mul.imag = sin(delta);
    fac.real = 1.0f;
    fac.imag = 0.0f;
    for(group = 0; group < step; group++) {
      for(pair = group; pair < n; pair += jump) {
        match = pair + step;
        product.real = 
          fac.real * data[match].real - fac.imag * data[match].imag;
        product.imag = 
          fac.real * data[match].imag + fac.imag * data[match].real;
        data[match].real = data[pair].real - product.real;
        data[match].imag = data[pair].imag - product.imag;
        data[pair].real += product.real;
        data[pair].imag += product.imag;
      }
      facReal = fac.real;
      fac.real = mul.real * fac.real - mul.imag * fac.imag + fac.real;
      fac.imag = mul.real * fac.imag + mul.imag * facReal + fac.imag;
    }
  }
  return TRUE;
}

int32 ST_fftScale(soyComplex *data, uint32 n) {
	uint32 pos;
	real32 factor = 1.0f / (real32)n;
	for (pos = 0; pos < n; pos++) {
		data[pos].real *= factor;
		data[pos].imag *= factor;
	}
    return TRUE;
}

int32 ST_fftForward(soyComplex* input, soyComplex* output, uint32 n) {
  if(!input || !output || n  < 1 || n & (n - 1)) {
    SOY_LOG4("Error: %d %d %d %d\n", !input, !output, n < 1, n & (n - 1));
    return 0;
  }
  ST_fftRearange(input, output, n);
  ST_fftEval(output, n, 0);
  return TRUE;
}

int32 ST_fftInverse(
    soyComplex* input, soyComplex* output, uint32 n, uint32 scale) {
  if(!input || !output || n  < 1 || n & (n - 1)) {
    return 0;
  }
  ST_fftRearange(input, output, n);
  ST_fftEval(output, n, 1);
  if(scale) {
    ST_fftScale(output, n);
  }
  return TRUE;
}

int32 ST_computeFourierFast(int32 size) {
  ST_fftForward(g_fft.sampleData, g_fft.transformedData, g_fft.size);
  return TRUE;
}

int32 ST_fourierDrawFast(soyApp* app, int32 xOffset, int32 yOffset) {
  int32 i, j;
  real32 n;
  int32 width = SOY_width(app) - xOffset*2;
  real32 v = 0.0f;
  real32 e = 0.0f;
  real32 d = 0.0f;
  real32 probeFreq = (real32)SOY_mouseX(app) / (real32)SOY_width(app);
  real32 scale = 1.0f;
  probeFreq *= g_fft.fac;
  probeFreq = SOY_MAX(probeFreq, 1.0f);  
  ST_computeFourierFast(g_fft.size);
  for(i = 0; i < width; i++) {
    n = (real32)i / (real32)width;
    n = (n*n*n)*0.5f;
    n = SOY_MIN(SOY_MAX(n, 0.0f), 1.0f);
    j = (int32)(n * (real32)(g_fft.size/2));
    v = g_fft.transformedData[j].real;
    e = g_fft.transformedData[j].imag;
    d = SOY_distance(0.0f, 0.0f, fabs(v), fabs(e));
    d *= scale;
    SOY_drawLine(app->framebuffer,
      xOffset + i,
      yOffset,
      xOffset + i,
      yOffset - (int32)d);
  }
/*
  SOY_drawLine(app->framebuffer,
      xOffset + probeFreq,
      yOffset,
      xOffset + probeFreq,
      yOffset - (int32)scale
      );
*/
  return TRUE;
}

SOY_GLOBAL real32 g_freq2 = 800.0f;
SOY_GLOBAL real32 g_freq3 = 0.0f;

int32 ST_fourierTest(soyApp* app) {
  SOY_drawSetColour(app->framebuffer, 0xFF000000);
  SOY_drawClear(app->framebuffer);
  g_freq3 = ((real32)SOY_mouseX(app)/SOY_width(app))*24000.0f;
#if 1
#if 1
  ST_fourierInit(app, 256, 1440.0f, g_freq2, g_freq3);
  ST_fourierDrawDiscrete(app, 32, 100);
#endif
  ST_fourierInit(app, 2 << 12, 1440.0f, g_freq2, g_freq3);
  ST_fourierDrawFast(app, 32, 200);
#endif
  SOY_drawTextFormat(app->framebuffer, app->fontRegular,
      32, 300, "%f %f %f\n", 440.0f, g_freq2, g_freq3);
  g_freq2 += 0.01f;
  return TRUE;
}


  
int32 SOY_userUpdate(soyApp* app, real64 dt) {
  SOY_libUpdate(app, dt);
  if(SOY_keyPressed(app, SOY_F5)) { SOY_makePalette(32, PALETTE_A); cp = 0; }
  if(SOY_keyPressed(app, SOY_F6)) { SOY_makePalette(32, PALETTE_B); cp = 1; }
  if(SOY_keyPressed(app, SOY_F7)) { SOY_makePalette(32, PALETTE_C); cp = 2; }
  if(SOY_keyPressed(app, SOY_F8)) { SOY_makePalette(32, PALETTE_D); cp = 4; }
#if 1
  if(SOY_keyPressed(app, SOY_F9)) { SOY_setResolution(app, 1); }
  if(SOY_keyPressed(app, SOY_F10)) { SOY_setResolution(app, 2); }
#endif
  
  if(SOY_keyPressed(app, SOY_F2)) {
    ST_visualEditorInit(&g_visualEditor, app->fontRegular);
  }
  if(SOY_keyPressed(app, SOY_F3)) {
    ST_visualEditorInit(&g_visualEditor, app->fontSmall);
  }
  return TRUE;
}

int32 SOY_userRender(soyApp* app, real64 dt) {
  SOY_drawSetColour(app->framebuffer, 0);
#if 1
  SOY_libRender(app, dt);
#endif

#if 0
  ST_fourierTest(app);
#endif
#if 0
  SOY_sleep(200);
#endif
  return TRUE;
}

int32 SOY_userStop(soyApp* app) {
  ST_saveState(app, &g_tracker, "t_state.soy");
  SOY_libStop(app);
  return TRUE;
}

int32 main() {
  soyApp app;
  int8* title = SOY_getVersionString(
      TRACKER_TITLE,
      RELEASE_VERSION,
      MAJOR_VERSION,
      MINOR_VERSION);
  SOY_LOG1("Sizeof rect: %f\n", (real32)sizeof(soyRect));
  SOY_create(&app, title, TRACKER_WIDTH, TRACKER_HEIGHT);
  return TRUE;
}

