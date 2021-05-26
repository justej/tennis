#include <simple2d.h>
#include "field.h"

static Field field;

void initField(int width, int height) {
    field.left = 10;
    field.right = width - 10;
    field.top = 10;
    field.bottom = height - 10;
    field.line_width = 3;

    field.fg_color.a = 1;
    field.fg_color.r = 1;
    field.fg_color.g = 1;
    field.fg_color.b = 1;

    field.bg_color.a = 1;
    field.bg_color.r = 0;
    field.bg_color.g = 0;
    field.bg_color.b = 0;
}

Field *getField() {
  return &field;
}

void renderField() {
  S2D_DrawLine(
    field.left, field.top, field.left, field.bottom,
    field.line_width,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a
  );
  S2D_DrawLine(
    field.left, field.bottom, field.right, field.bottom,
    field.line_width,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a
  );
  S2D_DrawLine(
    field.right, field.bottom, field.right, field.top,
    field.line_width,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a
  );
  S2D_DrawLine(
    field.right, field.top, field.left, field.top,
    field.line_width,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a
  );
  S2D_DrawLine(
    (field.left + field.right) / 2, field.top, (field.left + field.right) / 2, field.bottom,
    field.line_width,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a,
    field.fg_color.r, field.fg_color.g, field.fg_color.b, field.fg_color.a
  );
}