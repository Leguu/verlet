#pragma once

#include "point.h"
#include <SDL2/SDL.h>

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

struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
} app;
