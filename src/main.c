#include <simple2d.h>
#include "field.h"

#define SCREEN_W 640
#define SCREEN_H 480

void render() {
  renderField();
}

int main() {
  initField(SCREEN_W, SCREEN_H);

  S2D_Window *window = S2D_CreateWindow(
    "Hello Triangle", SCREEN_W, SCREEN_H, NULL, render, 0
  );

  S2D_Show(window);
  return 0;
}