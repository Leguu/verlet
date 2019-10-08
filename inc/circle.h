#pragma once

#include "point.h"
#include <SDL2/SDL.h>

// Quantity of circles
#define CIRCLES_QUANTITY 5

struct circle {
  Point position;
  int radius;
} circles[CIRCLES_QUANTITY];

void draw_circle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY,
                 int32_t radius);
void circles_initialize();
void circles_draw();
