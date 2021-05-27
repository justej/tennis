#include <simple2d.h>
#include "ball.h"
#include "field.h"

#define SCREEN_W 300
#define SCREEN_H 200

void update() {
  updateBall();
}

void render() {
  renderField();
  renderBall();
}

int main() {
  initField(SCREEN_W, SCREEN_H);
  initBall(SCREEN_W, SCREEN_H);

  S2D_Window *window = S2D_CreateWindow(
    "Hello Triangle", SCREEN_W, SCREEN_H, update, render, 0
  );

  S2D_Show(window);
  return 0;
}