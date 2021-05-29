#include <simple2d.h>
#include "ball.h"
#include "field.h"
#include "racket.h"

#define SCREEN_W 300
#define SCREEN_H 200

#define DX_STEP 3
#define DY_STEP 3

Racket racketLeft;
Racket racketRight;
int dxLeft;
int dyLeft;
int dxRight;
int dyRight;

void onKey(S2D_Event e) {
  switch (e.type) {
    case S2D_KEY_HELD:
      switch (*e.key) {
        case 'A': dxLeft = -DX_STEP; break;
        case 'D': dxLeft = DX_STEP; break;
        case 'S': dyLeft = DY_STEP; break;
        case 'W': dyLeft = -DY_STEP; break;
      }
      break;
  }
}

void update() {
  updateRacket(&racketLeft, dxLeft, dyLeft);
  updateRacket(&racketRight, dxRight, dxRight);
  dxLeft = 0;
  dyLeft = 0;
  dxRight = 0;
  dyRight = 0;
  updateBall(&racketLeft, &racketRight);
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

  Field *field = getField();

  racketLeft = initRacket(SCREEN_W, SCREEN_H, SCREEN_W / 4, field);
  racketRight = initRacket(SCREEN_W, SCREEN_H, SCREEN_W * 3 / 4, field);

  S2D_Window *window = S2D_CreateWindow(
    "Hello Triangle", SCREEN_W, SCREEN_H, update, render, 0
  );

  window->on_key = onKey;

  S2D_Show(window);
  return 0;
}