#ifndef _BALL_H_
#define _BALL_H_

#include "racket.h"

typedef struct _Ball {
  int x;
  int y;
  int dx;
  int dy;
  int r;
  S2D_Color color;
  S2D_Sound *boom;
} Ball;

void initBall(int width, int height);
Ball *getBall();
void updateBall(const Racket *racketLeft, const Racket *racketRight);
void renderBall();

#endif