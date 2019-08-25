#include "circle.h"
#include "main.h"
#include "point.h"
#include <SDL2/SDL.h>

struct circle circle_new(float x, float y, int radius) {
  return (struct circle){.position = point_new(x, y), .radius = radius};
}

void circles_initialize() {
  circles[4] = circle_new(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 35);
  float default_x = circles[4].position.x;
  float default_y = circles[4].position.y;

  circles[0] = circle_new(default_x - 100, default_y - 100, 25);
  circles[1] = circle_new(default_x + 100, default_y - 100, 25);
  circles[2] = circle_new(default_x - 100, default_y + 100, 25);
  circles[3] = circle_new(default_x + 100, default_y + 100, 25);
}

void circles_draw() {
  for (int i = 0; i < CIRCLES_QUANTITY; i++)
    draw_circle(app.renderer, circles[i].position.x, circles[i].position.y,
                circles[i].radius);
}

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
