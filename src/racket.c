#include <simple2d.h>
#include "racket.h"
#include "field.h"

Racket initRacket(int width, int height, int x) {
  Racket racket;

  racket.width = 10;
  racket.hight = 40;
  racket.x = x;
  racket.y = height / 2;

  Field *field = getField();

  if (x < width / 2) {
    // Left racket
    racket.minX = field->left + 1 + racket.width / 2;
    racket.maxX = width / 2 - 1 - racket.width / 2;
  } else {
    // Right racket
    racket.minX = width / 2 + 1 + racket.width / 2;
    racket.maxX = field->right - 1 - racket.width / 2;
  }
  racket.minY = field->top + 1 + racket.width / 2;
  racket.maxY = field->bottom - 1 - racket.width / 2;

  racket.color.a = 1;
  racket.color.r = 0;
  racket.color.g = 1;
  racket.color.b = 0;

  return racket;
}

void updateRacket(Racket *racket, int dx, int dy) {
  racket->x += dx;
  if (racket->x < racket->minX) {
    racket->x = racket->minX;
  }
  if (racket->x > racket->maxX) {
    racket->x = racket->maxX;
  }

  racket->y += dy;
  if (racket->y < racket->minY) {
    racket->y = racket->minY;
  }
  if (racket->y > racket->maxY) {
    racket->y = racket->maxY;
  }
}

void renderRacket(Racket *racket) {
  S2D_DrawLine(
    racket->x, racket->y - racket->hight / 2, racket->x, racket->y + racket->hight / 2,
    racket->width,
    racket->color.r, racket->color.g, racket->color.b, racket->color.a,
    racket->color.r, racket->color.g, racket->color.b, racket->color.a,
    racket->color.r, racket->color.g, racket->color.b, racket->color.a,
    racket->color.r, racket->color.g, racket->color.b, racket->color.a
  );
}