#ifndef _FIELD_H_
#define _FIELD_H_

typedef struct _Field {
  int left;
  int right;
  int top;
  int bottom;
  int line_width;
  S2D_Color fg_color;
  S2D_Color bg_color;
} Field;

void initField(int width, int height);
Field *getField();
void renderField();

#endif