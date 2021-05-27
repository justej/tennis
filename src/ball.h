#ifndef _BALL_H_
#define _BALL_H_

typedef struct _Ball {
  int x;
  int y;
  int dx;
  int dy;
  int r;
  S2D_Color color;
} Ball;

void initBall(int width, int height);
Ball *getBall();
void updateBall();
void renderBall();

#endif