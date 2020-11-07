#pragma once

#include "point.h"

// Quantity of nodes
#define QUANTITY 4096

typedef struct {
  Point position;
  Point previous;
} Node;

Node *nodes_initialize();
void nodes_draw();
void nodes_update();
