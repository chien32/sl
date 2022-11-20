#ifndef SOY_LAND_H
#define SOY_LAND_H

#ifndef SOY_LIB_H
#include "../soy.h"
#endif

typedef struct tag_landTile {
  uint16 height;
  uint16 flags;
} landTile;

typedef struct tag_landChunk landChunk;

struct tag_landChunk {
  landTile* tiles;
  int32 x;
  int32 y;
  uint32 size;
  landChunk* neighbours[8];
};

typedef struct tag_landGenInfo {
  real32 tide;
  real32 persistance;
  real32 scale;
  real32 warpX;
  real32 warpY;
  real32 warpAmount;
  int32 octavesBase;
  int32 octavesWarp;
} landGenInfo;

typedef real32 (*PFLANDNOISE) (real32 x, real32 y);

int32 LAND_chunkInit(landChunk* chunk, void* memory, int32 memorySize) {
  chunk->tiles = memory;
  chunk->size = memorySize;
  return TRUE;
}

landChunk* LAND_chunkPtr(landChunk* chunks, int32 x, int32 y, int32 s) {
  if(!chunks) { return NULL; }
  if(x < 0  || y < 0 || x >= s || y >= s) { return 0; }
  return &chunks[x + y*s];
}

real32 LAND_generateHeight(landGenInfo* genInfo, real32 x, real32 y) {
  real32 rh;
  rh = SOY_noiseDomainWarp2D(SOY_noiseSimplex2D,
      x*0.01f, y*0.01f,
      0.2f, 0.3f, 0.5f,
      1.0f, 0.5f, 12, 6);
  rh = SOY_noiseSimplexNormalize(rh);
  rh = SOY_MIN(SOY_MAX(rh, 0.0f), 1.0f);
  return rh;
}

int32 LAND_generateTopology(landGenInfo* genInfo,
	landChunk* world, int32 index, int32 stride, int32 max) {
  int32 x, y;
  real32 rx, ry;
  real32 height;
  real32 noise;
  real32 rStride = (real32)stride;
  int32 worldX = index % stride;
  int32 worldY = (index / stride) % stride;
  int32 cx = SOY_wrap(worldX, stride);
  int32 cy = SOY_wrap(worldY, stride);
  landChunk* chunk = world + index;
  chunk->x = worldX;
  chunk->y = worldY;
  chunk->neighbours[0] = LAND_chunkPtr(world, cx - 1, cy, stride);
  chunk->neighbours[1] = LAND_chunkPtr(world, cx + 1, cy, stride);
  chunk->neighbours[2] = LAND_chunkPtr(world, cx, cy - 1, stride);
  chunk->neighbours[3] = LAND_chunkPtr(world, cx, cy + 1, stride);
  chunk->neighbours[4] = LAND_chunkPtr(world, cx - 1, cy - 1, stride);
  chunk->neighbours[5] = LAND_chunkPtr(world, cx - 1, cy + 1, stride);
  chunk->neighbours[6] = LAND_chunkPtr(world, cx + 1, cy - 1, stride);
  chunk->neighbours[7] = LAND_chunkPtr(world, cx + 1, cy + 1, stride);
  for(y = 0; y < stride; y++) {
    for(x = 0; x < stride; x++) {
      rx = (real32)((real32)x + 0.5f + worldX*rStride) / rStride;
      ry = (real32)((real32)y + 0.5f + worldY*rStride) / rStride;
      noise = LAND_generateHeight(genInfo, rx, ry);
      height = noise*(real32)max;
      chunk->tiles[x + y*stride].height = ((uint16)height);
    }
  }
  return TRUE;
}

uint32 LAND_getType(landChunk* chunk, int32 x, int32 y,
	int32 stride, int32 max) {
  int32 cw = stride;
  real32 v = (real32)chunk->tiles[x + y*cw].height / max;
  real32 d = v*v*v*v*4.0f;
  return (uint32)(SOY_clamp(d, 0.0f, 1.0f)*255.0f);
}

#define GAME_PUSH_VERTEX(x) (*(buffer++) = (x))

vec3f LAND_getNormal(uint32* verts,
    real32 rx, real32 ry, int32 invert, int32 side) {
  vec3f tri[4];
  uint32 nx, ny, nz;
  real32 div = 8.0f;
  if(side == 0) {
    /* Triangle A */
    if(invert) {
      tri[0] = SOY_vec3f(rx, (real32)(verts[0])/div, ry);
      tri[1] = SOY_vec3f(rx, (real32)(verts[2])/div, ry + 1.0f);
      tri[2] = SOY_vec3f(rx + 1.0f, (real32)(verts[1])/div, ry);
    } else {
      tri[0] = SOY_vec3f(rx, (real32)(verts[0])/div, ry + 1.0f);
      tri[1] = SOY_vec3f(rx + 1.0f, (real32)(verts[2])/div, ry + 1.0f);
      tri[2] = SOY_vec3f(rx, (real32)(verts[1])/div, ry);
    }
  } else if(side == 1) {
    /* Triangle B */
    if(invert) {
      tri[0] = SOY_vec3f(rx + 1.0f, (real32)(verts[1])/div, ry);
      tri[1] = SOY_vec3f(rx, (real32)(verts[2])/div, ry + 1.0f);
      tri[2] = SOY_vec3f(rx + 1.0f, (real32)(verts[3])/div, ry + 1.0f);
    } else {
      tri[0] = SOY_vec3f(rx, (real32)(verts[1])/div, ry);
      tri[1] = SOY_vec3f(rx + 1.0f, (real32)(verts[2])/div, ry + 1.0f);
      tri[2] = SOY_vec3f(rx + 1.0f, (real32)(verts[3])/div, ry);
    }
  }
  tri[3] = v3Norm(SOY_getNormal(tri));
  nx = (uint32)(tri[3].x*127.0f + 128.0f);
  ny = (uint32)(tri[3].y*127.0f + 128.0f);
  nz = (uint32)(tri[3].z*127.0f + 128.0f);
  return tri[3];
}

uint32 LAND_packNormal(vec3f normal) {
 uint32 nx = (uint32)(normal.x*127.0f + 128.0f);
 uint32 ny = (uint32)(normal.y*127.0f + 128.0f);
 uint32 nz = (uint32)(normal.z*127.0f + 128.0f);
return (nx & 0xFF) | ((ny & 0xFF) << 8) | ((nz & 0xFF) << 16);
}

landTile LAND_getTile(landChunk* chunk, int32 x, int32 y, int32 width) {
  landTile ret;
  int32 cw = width - 1;
  ret.flags = 0;
  ret.height = 0;
  if(!chunk) { return ret; }
  if(x < 0  || y < 0 || x >= width || y >= width) {
    if(x <  0) { return LAND_getTile(chunk->neighbours[0], cw, y, width); }
    if(x > cw) { return LAND_getTile(chunk->neighbours[1], 0,  y, width); }
    if(y <  0) { return LAND_getTile(chunk->neighbours[2], x, cw, width); }
    if(y > cw) { return LAND_getTile(chunk->neighbours[3], x,  0, width); }
  } else {
    return chunk->tiles[x + y*width];
  }
  return ret;
}

typedef struct tag_landVertexInfo {
  int32 index;
  int32 order;
  int32 height;
  int32 x;
  int32 y;
  vec3f normal;
  void* args;
} landVertexInfo;

typedef int32 (*PFLANDPUSHVERTEX) (landVertexInfo* info);

landVertexInfo LAND_vertexInfo(int32 i, int32 order, int32 height,
    int32 x, int32 y, vec3f normal, void* args) {
  landVertexInfo vi;
  vi.index = i;
  vi.order = order;
  vi.height = height;
  vi.x = x;
  vi.y = y;
  vi.normal = normal;
  vi.args = args;
  return vi;
}

int32 LAND_generateMesh(landChunk* chunk, 
	int32 stride, int32 strideMap,
	PFLANDPUSHVERTEX pushVertexProc, void* args) {
  real32 rx, ry;
  real32 t1, t2, t3, t4;
  int32 x, y;
  int32 index;
  vec3f normal;
  uint32 invertNormal;
  uint32 verts[4];
  int32 obX, obY;
  landVertexInfo vi;
  uint32 orderA[6] = { 1, 5, 3, 3, 5, 7 };
  uint32 orderB[6] = { 3, 1, 7, 7, 1, 5 };
  uint32 kernelA[4] = { 0, 1, 2, 3 };
  uint32 kernelB[4] = { 2, 0, 3, 1 };
  uint32* kern = kernelA;
  uint32* order = orderA;
  real32 d = 8.0f;
  if(!chunk) { SOY_LOG("Fatal error. NULL chunk\n"); return FALSE; }
  if(!pushVertexProc) { return FALSE; }
  for(y = 0; y < stride; y++) {
    for(x = 0; x < stride; x++) {
	  index = x + y*stride;
      rx = (real32)x;
      ry = (real32)y;
      obX = !(x == stride - 1 && chunk->x == strideMap - 1);
      obY = !(y == stride - 1 && chunk->y == strideMap - 1);
      t1 = (real32)LAND_getTile(chunk, x, y, stride).height / d;
      t2 = (real32)LAND_getTile(chunk, x + obX, y, stride).height / d;
      t3 = (real32)LAND_getTile(chunk, x, y + obY, stride).height / d;
      t4 = (real32)LAND_getTile(chunk, x + obX, y + obY, stride).height / d;
      if(SOY_orientQuad(t1, t2, t3, t4)) {
        order = orderB;
        kern = kernelB;
        invertNormal = TRUE;
      } else {
        order = orderA;
        kern = kernelA;
        invertNormal = FALSE;
      }
      verts[kern[0]] = LAND_getTile(chunk, x, y, stride).height;
      verts[kern[1]] = LAND_getTile(chunk, x + obX, y, stride).height;
      verts[kern[2]] = LAND_getTile(chunk, x, y + obY, stride).height;
      verts[kern[3]] = LAND_getTile(chunk, x + obX, y + obY, stride).height;
      normal = LAND_getNormal(verts, rx, ry, invertNormal, 0);
	  
      vi = LAND_vertexInfo(index, order[0], verts[0], x, y, normal, args);
	  pushVertexProc(&vi);
      vi = LAND_vertexInfo(index, order[1], verts[2], x, y, normal, args);
	  pushVertexProc(&vi);
      vi = LAND_vertexInfo(index, order[2], verts[1], x, y, normal, args);
	  pushVertexProc(&vi);
      normal = LAND_getNormal(verts, rx, ry, invertNormal, 1);
      vi = LAND_vertexInfo(index, order[3], verts[1], x, y, normal, args);
	  pushVertexProc(&vi);
      vi = LAND_vertexInfo(index, order[4], verts[2], x, y, normal, args);
	  pushVertexProc(&vi);
      vi = LAND_vertexInfo(index, order[5], verts[3], x, y, normal, args);
	  pushVertexProc(&vi);
    }
  }
  return TRUE;
}

int32 LAND_chunkUpdate(landChunk* chunk) {

  return TRUE;
}

int32 LAND_chunkRender(landChunk* chunk, soyShader* shader) {
  
  return TRUE;
}

int32 LAND_chunkFinalize(landChunk* chunk) {

  return TRUE;
}

#endif /* SOY_TERRAIN_H */
