#pragma once

#include "point.h"
#include <SDL2/SDL.h>

#define RADIUS 25

struct {
  Point position;
} circles[2];

void DrawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY,
                int32_t radius);
void circles_initialize();
void circles_draw();
