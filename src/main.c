#include "main.h"
#include "circle.h"
#include "node.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <math.h>

void app_initialize() {
  SDL_Init(SDL_INIT_VIDEO);
  app.window = SDL_CreateWindow(0, 0, 0, 800, 400, 0);
  app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
  if (!app.window || !app.renderer)
    FAILURE(1, "App initialization failed: %s\n", SDL_GetError());
}

int main() {
  LOG("Initializing app...\n");
  app_initialize();
  circles_initialize();
  Node *head = nodes_initialize();
  LOG("App initialized!\n");

  while (1) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT || event.button.button == SDL_SCANCODE_Q)
      exit(0);

    if (SDL_GetMouseState(NULL, NULL))
      head->position = (Point){.x = event.button.x, .y = event.button.y};
    nodes_update();

    SDL_SetRenderDrawColor(app.renderer, 20, 20, 20, 255);
    SDL_RenderClear(app.renderer);

    SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);
    circles_draw();
    nodes_draw();

    SDL_RenderPresent(app.renderer);

    SDL_Delay(1);
  }
}
