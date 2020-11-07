#include "node.h"
#include "circle.h"
#include "main.h"

/// Returns head of node as a pointer.
Node *nodes_initialize(Node *nodes) {
  for (int i = 0, j = 5; i < QUANTITY; i++, j++) {
    nodes[i].position.x = j;
    nodes[i].position.y = 25;
    nodes[i].previous = nodes[i].position;
  }

  return &nodes[QUANTITY - 1];
}

void nodes_draw(Application app, Node *nodes) {
  for (int i = 0; i < QUANTITY - 1; i++) {
    float x = nodes[i].position.x;
    float y = nodes[i].position.y;
    float next_x = nodes[i + 1].position.x;
    float next_y = nodes[i + 1].position.y;
    SDL_RenderDrawLineF(app.renderer, x, y, next_x, next_y);
  }
}

void nodes_update(struct circle *circles, Node *nodes) {
  for (int i = QUANTITY - 2; i >= 0; i--) {
    /// The currently selected node's position
    /// Separate variable because it's used often here
    Point *current = &nodes[i].position;

    // The difference between the node's old position, and new one
    Point difference = point_subtract(*current, nodes[i].previous);

    // CONSTRAINTS
    // This will move the current point 0.7% of the distance to the next point.
    point_redistance(current, nodes[i + 1].position, 0.7);

    // For every circle, checks if the current node is inside the circle, and
    // moves it away That's why point_redistance has a negative value.
    for (int j = 0; j < CIRCLES_QUANTITY; j++)
      if (point_distance(*current, circles[j].position) < circles[j].radius)
        point_redistance(current, circles[j].position, -0.01);

    // Adds the difference to the node's current position and resets its
    // previous position
    *current = point_add(*current, difference);
    nodes[i].previous = *current;
  }
}
