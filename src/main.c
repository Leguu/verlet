#include "main.h"
#include "node.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <math.h>

void initialize() {
  SDL_Init(SDL_INIT_VIDEO);
  app.window = SDL_CreateWindow(0, 0, 0, 800, 400, 0);
  app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
}

int main() {
  Node *head = nodes_initialize();
  // circles_initialize();
  initialize();

  while (1) {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
      exit(0);

    if (SDL_GetMouseState(NULL, NULL)) {
      head->position.x = event.button.x;
      head->position.y = event.button.y;
    }

    SDL_SetRenderDrawColor(app.renderer, 20, 20, 20, 255);
    SDL_RenderClear(app.renderer);

    SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);
    // circles_draw();
    nodes_update();
    nodes_draw();

    SDL_RenderPresent(app.renderer);
    SDL_Delay(1);
  }
}
