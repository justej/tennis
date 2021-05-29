#include <simple2d.h>
#include "ball.h"
#include "field.h"
#include "racket.h"

#define SCREEN_W 300
#define SCREEN_H 200

Racket racketLeft;
Racket racketRight;

void update() {
  updateBall();
  updateRacket(&racketLeft, 0, 0);
  updateRacket(&racketRight, 0, 0);
}

void render() {
  renderField();
  renderBall();
  renderRacket(&racketLeft);
  renderRacket(&racketRight);
}

int main() {
  initField(SCREEN_W, SCREEN_H);
  initBall(SCREEN_W, SCREEN_H);

  racketLeft = initRacket(SCREEN_W, SCREEN_H, SCREEN_W / 4);
  racketRight = initRacket(SCREEN_W, SCREEN_H, SCREEN_W * 3 / 4);

  S2D_Window *window = S2D_CreateWindow(
    "Hello Triangle", SCREEN_W, SCREEN_H, update, render, 0
  );

  S2D_Show(window);
  return 0;
}