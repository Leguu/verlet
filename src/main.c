#include "main.h"
#include "circle.h"
#include "node.h"
#include "point.h"
#include <SDL2/SDL.h>
#include <math.h>

void app_initialize(Application *app) {
  SDL_Init(SDL_INIT_VIDEO);
  app->window = SDL_CreateWindow(0, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
  if (!app->window || !app->renderer)
    FAILURE(1, "App initialization failed: %s\n", SDL_GetError());
}

#include <time.h>
float time_previous;
// Tries to keep the framerate to target.
int do_fps(float target) {
  float time_current = clock() / 1000000.0;
  int result = time_current - time_previous > 1 / target;

  if (result)
    time_previous = time_current;
  return result;
}

int main() {
  LOG("Initializing app...\n");
  Application app;
  app_initialize(&app);

  struct circle circles[CIRCLES_QUANTITY];
  circles_initialize(circles);

  Node nodes[QUANTITY];
  /// This is the head of the chain of nodes.
  Node *head = nodes_initialize(nodes);
  LOG("App initialized!\n");

  SDL_Event event;
  while (1) {
    // Checks the next event (mouse / keyboard, etc.) and places it in `event`
    // Using a `goto` here in order to be cleaner, and to do cleanup at the end.
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT || event.button.button == SDL_SCANCODE_Q)
      goto exit;

    // If the mouse is clicked, move the head of the node to the mouse cursor's
    // position
    if (SDL_GetMouseState(NULL, NULL))
      head->position = (Point){.x = event.button.x, .y = event.button.y};
    nodes_update(circles, nodes);

    if (!do_fps(60))
      continue;

    SDL_SetRenderDrawColor(app.renderer, 20, 20, 20, 255);
    SDL_RenderClear(app.renderer);

    SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);
    circles_draw(app, circles);
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
    nodes_draw(app, nodes);

    SDL_RenderPresent(app.renderer);
  }

exit:
  LOG("Quit signal recieved.\n");
}
