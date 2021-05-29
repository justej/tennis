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

void updateBall(const Racket *racketLeft, const Racket *racketRight) {
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

  if (((ball.x > racketLeft->x - racketLeft->width / 2 - ball.r) && (ball.x < racketLeft->x + racketLeft->width / 2 + ball.r) &&
      (ball.y > racketLeft->y - racketLeft->height / 2) && (ball.y < racketLeft->y + racketLeft->height / 2)) ||
      ((ball.x > racketRight->x - racketRight->width / 2 - ball.r) && (ball.x < racketRight->x + racketRight->width / 2 + ball.r) &&
      (ball.y > racketRight->y - racketRight->height / 2) && (ball.y < racketRight->y + racketRight->height / 2))) {
    ball.dx = -ball.dx;
    ball.x += ball.dx;
    S2D_PlaySound(ball.boom);
  }

  // Left racket
  if ((ball.x > racketLeft->x - racketLeft->width / 2 - ball.r) && (ball.x < racketLeft->x + racketLeft->width / 2 + ball.r)) {
    int dx = ball.x - racketLeft->x;
    int dy1 = ball.y - (racketLeft->y - racketLeft->height / 2);
    int dy2 = ball.y - (racketLeft->y + racketLeft->height / 2);
    int R = ball.r + racketLeft->width / 2;

    if ((dx * dx + dy1 * dy1 < R * R) || (dx * dx + dy2 * dy2 < R * R)) {
      ball.dx = -ball.dx;
      ball.x += ball.dx;
      ball.dy = -ball.dy;
      ball.y += ball.dy;
      S2D_PlaySound(ball.boom);
    }
  }

  // Right racket
  if ((ball.x > racketRight->x - racketRight->width / 2 - ball.r) && (ball.x < racketRight->x + racketRight->width / 2 + ball.r)) {
    int dx = ball.x - racketRight->x;
    int dy1 = ball.y - (racketRight->y - racketRight->height / 2);
    int dy2 = ball.y - (racketRight->y + racketRight->height / 2);
    int R = ball.r + racketRight->width / 2;

    if ((dx * dx + dy1 * dy1 < R * R) || (dx * dx + dy2 * dy2 < R * R)) {
      ball.dx = -ball.dx;
      ball.x += ball.dx;
      ball.dy = -ball.dy;
      ball.y += ball.dy;
      S2D_PlaySound(ball.boom);
    }
  }
}

void renderBall() {
  S2D_DrawCircle(ball.x, ball.y, ball.r, 360, ball.color.r, ball.color.g, ball.color.b, ball.color.a);
}

Ball *getBall() {
  return &ball;
}