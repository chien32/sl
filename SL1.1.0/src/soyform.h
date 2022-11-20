#ifndef SOY_FORM_H
#define SOY_FORM_H
#include "soy.h"

#define SOY_FORM_MEMORY 1024
#define SOY_FORM_CHILDREN 16

typedef struct tag_soyForm soyForm;

struct tag_soyForm {
  soyRect rect;
  soyForm* parent;
  soyForm* children[SOY_FORM_CHILDREN];
  uint32 numChildren;
};

SOY_GLOBAL soyForm g_formMemory[SOY_FORM_MEMORY];
SOY_GLOBAL uint32 g_formAllocCount = 0;

soyForm* SOY_formAllocate(void* memory, soyForm* parent) {
  soyForm* ret;
  if(g_formAllocCount < SOY_FORM_MEMORY) {
	ret = ((soyForm*)memory) + g_formAllocCount;
	if(ret) {
	  ret->numChildren = 0;
      ret->children[0] = NULL;
	  ret->children[1] = NULL;
	  ret->parent = parent;
	  if(parent && parent->numChildren < 2) {
		parent->children[parent->numChildren++] = ret;
	  }
	  ret->rect = SOY_rect(0, 0, 0, 0);
	}
  } else {
	SOY_LOG("Error, maximum forms reached\n");
  }
  return NULL;
}


int32 SOY_formFlusH() {
  g_formAllocCount = 0;
  return TRUE;
}

int32 main() {
  soyForm* form = SOY_formAllocate(g_formMemory, NULL);

  return 0;
}

#endif /* SOY_FORM_H */
