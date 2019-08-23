#include "circle.h"
#include "main.h"
#include "point.h"
#include <SDL2/SDL.h>

void draw_circle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY,
                 int32_t radius) {
  const int32_t diameter = (radius * 2);

  int32_t x = (radius - 1);
  int32_t y = 0;
  int32_t tx = 1;
  int32_t ty = 1;
  int32_t error = (tx - diameter);

  while (x >= y) {
    //  Each of the following renders an octant of the circle
    SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
    SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
    SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
    SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
    SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
    SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
    SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
    SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

    if (error <= 0) {
      ++y;
      error += ty;
      ty += 2;
    }

    if (error > 0) {
      --x;
      tx += 2;
      error += (tx - diameter);
    }
  }
}

void circles_initialize() {
  circles[0].position.x = 300;
  circles[0].position.y = 100;
  circles[0].radius = 20;

  circles[1].position.x = 500;
  circles[1].position.y = 100;
  circles[1].radius = 20;

  circles[2].position.x = 300;
  circles[2].position.y = 300;
  circles[2].radius = 20;

  circles[3].position.x = 500;
  circles[3].position.y = 300;
  circles[3].radius = 20;

  circles[4].position.x = 400;
  circles[4].position.y = 200;
  circles[4].radius = 30;
}

void circles_draw() {
  for (int i = 0; i < CIRCLES_QUANTITY; i++)
    draw_circle(app.renderer, circles[i].position.x, circles[i].position.y,
                circles[i].radius);
}
