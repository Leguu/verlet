#pragma once

#include "point.h"
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

// The renderer and window for the app, very useful and therefore a global
// variable
typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
} Application;

// General debug statements... not very useful.
// LOG will not run if DEBUG is not true.
#define DEBUG 1
#define LOG(...)                                                               \
  {                                                                            \
    if (DEBUG) {                                                               \
      fprintf(stderr, "LOG: ");                                                \
      fprintf(stderr, __VA_ARGS__);                                            \
    }                                                                          \
  }
#define FAILURE(code, ...)                                                     \
  {                                                                            \
    fprintf(stderr, "ERROR: ");                                                \
    fprintf(stderr, __VA_ARGS__);                                              \
    exit(code);                                                                \
  }
