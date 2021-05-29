#ifndef _RACKET_H_
#define _RACKET_H_

typedef struct _Racket {
  int x;
  int y;
  int width;
  int hight;
  int minX;
  int maxX;
  int minY;
  int maxY;
  S2D_Color color;
} Racket;

Racket initRacket(int width, int height, int x);
void updateRacket();
void renderRacket();

#endif