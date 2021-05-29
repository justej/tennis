#ifndef _RACKET_H_
#define _RACKET_H_

#include "field.h"

typedef struct _Racket {
  int x;
  int y;
  int width;
  int height;
  int minX;
  int maxX;
  int minY;
  int maxY;
  S2D_Color color;
} Racket;

Racket initRacket(int width, int height, int x, const Field *field);
void updateRacket();
void renderRacket();

#endif