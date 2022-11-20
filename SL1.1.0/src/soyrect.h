#ifndef SOY_RECT_H
#define SOY_RECT_H
#include "soy.h"

typedef struct tag_soyForm soyForm;

struct tag_soyForm {
  int32 bounds[4];
  int32 offset[4];
  soyForm* parent;
};

int32 SOY_formUpdate(soyForm* base, soyForm* parent,
		int32 x1, int32 y1, int32 x2, int32 y2, int32 mode) {
  int32 px1, py1, px2, py2;
  if(parent) {
    px1 = parent->bounds[0];
    py1 = parent->bounds[1];
    px2 = parent->bounds[2];
    py2 = parent->bounds[3];
  } else {
    px1 = 0;
    py1 = 0;
    px2 = 0;
    py2 = 0;
  }
  switch(mode) {
    case(0): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
	}
	case(1): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
	}
	case(2): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
	}
  	case(3): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
	}
	case(4): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
	}
	case(5): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
	}
	case(6): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
	}
	case(7): {
	  base->bounds[0] = (x1 + px1) + base->offset[0];
 	  base->bounds[1] = (y1 + py1) + base->offset[1];
      base->bounds[2] = SOY_MIN(x2, px2) - base->offset[2];
      base->bounds[3] = SOY_MIN(y2, py2) - base->offset[3];
      break;
    }
    default: {
      break;
    }
  }
  return TRUE;
}

int32 SOY_formRender(soyCanvas* canvas, soyFont* font, soyForm* form) {
  SOY_drawRect(canvas,
		 form->bounds[0],
		 form->bounds[1],
		 form->bounds[2],
		 form->bounds[3], 1);
  return TRUE;
}

int32 SOY_formCreate(soyForm* form,
		int32 ox1, int32 oy1, int32 ox2, int32 oy2) {
  SOY_memorySet(form, 0, sizeof(soyForm));
  form->offset[0] = ox1;
  form->offset[1] = oy1;
  form->offset[2] = ox2;
  form->offset[3] = oy2;
  return TRUE;
}


#endif /* SOY_RECT_H */
