#pragma once

#include "point.h"

#define QUANTITY 4096

typedef struct {
  Point position;
  Point previous;
} Node;

Node nodes[QUANTITY];

Node *nodes_initialize();
void nodes_draw();
void nodes_update();
void fix_constraints();
