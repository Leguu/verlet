#include "node.h"
#include "circle.h"
#include "main.h"

/// Returns head of node as a pointer.
Node *nodes_initialize() {
  for (int i = 0, j = 20; i < QUANTITY; i++, j++) {
    nodes[i].position.x = j;
    nodes[i].position.y = 50;
    nodes[i].previous = nodes[i].position;
  }

  return &nodes[QUANTITY - 1];
}

void nodes_draw() {
  for (int i = 0; i < QUANTITY - 1; i++) {
    float x = nodes[i].position.x;
    float y = nodes[i].position.y;
    float next_x = nodes[i + 1].position.x;
    float next_y = nodes[i + 1].position.y;
    SDL_RenderDrawLineF(app.renderer, x, y, next_x, next_y);
  }
}

#define RESTING_DISTANCE 1

void node_redistance(Point *position1, Point position2) {
  float x_difference = position1->x - position2.x;
  float y_difference = position1->y - position2.y;

  float scalar_position = point_scalar(*position1, position2);
  position1->x += x_difference * RESTING_DISTANCE * scalar_position;
  position1->y += y_difference * RESTING_DISTANCE * scalar_position;
}

void nodes_update() {
  for (int i = QUANTITY - 2; i >= 0; i--) {

    Point difference = point_subtract(nodes[i].position, nodes[i].previous);
    nodes[i].position = point_add(nodes[i].position, difference);
    nodes[i].previous = nodes[i].position;
    // nodes[i].position.y += 1;

    node_redistance(&nodes[i].position, nodes[i + 1].position);

    for (int j = 0; j < CIRCLES_QUANTITY; j++) {
      if (point_distance(nodes[i].position, circles[j].position) <
          circles[j].radius) {
        Point *position1 = &nodes[i].position;
        Point position2 = circles[j].position;

        float x_difference = position1->x - position2.x;
        float y_difference = position1->y - position2.y;

        float scalar_position = point_scalar(*position1, position2);
        position1->x -= x_difference * 0.05 * scalar_position;
        position1->y -= y_difference * 0.05 * scalar_position;
      }
    }
  }
}
