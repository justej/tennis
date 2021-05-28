#include <simple2d.h>
#include "ball.h"
#include "field.h"

static Ball ball;

void initBall(int width, int height) {
  ball.x = width / 2;
  ball.y = height / 2;
  ball.dx = 3;
  ball.dy = 3;
  ball.r = 10;

  ball.color.a = 1;
  ball.color.r = 1;
  ball.color.g = 1;
  ball.color.b = 0;

  ball.boom = S2D_CreateSound("media/boom.ogg");
}

void updateBall() {
  const Field *const f = getField();

  ball.x += ball.dx;
  if ((ball.x < f->left + ball.r) || (ball.x > f->right - ball.r)) {
    ball.dx = -ball.dx;
    ball.x += ball.dx;
    S2D_PlaySound(ball.boom);
  }

  ball.y += ball.dy;
  if ((ball.y < f->top + ball.r) || (ball.y > f->bottom - ball.r)) {
    ball.dy = - ball.dy;
    ball.x += ball.dy;
    S2D_PlaySound(ball.boom);
  }
}

void renderBall() {
  S2D_DrawCircle(ball.x, ball.y, ball.r, 360, ball.color.r, ball.color.g, ball.color.b, ball.color.a);
}

Ball *getBall() {
  return &ball;
}