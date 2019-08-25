#include "point.h"

Point point_new(float x, float y) { return (Point){.x = x, .y = y}; }

Point point_subtract(Point point1, Point point2) {
  return (Point){.x = point1.x - point2.x, .y = point1.y - point2.y};
}

Point point_add(Point point1, Point point2) {
  return (Point){.x = point1.x + point2.x, .y = point1.y + point2.y};
}

float point_distance(Point point1, Point point2) {
  return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

float point_scalar(Point point1, Point point2) {
  float distance = point_distance(point1, point2);
  return (1 - distance) / distance;
}

void point_redistance(Point *position1, Point position2, float percentage) {
  float scalar = point_scalar(*position1, position2);
  position1->x += (position1->x - position2.x) * percentage * scalar;
  position1->y += (position1->y - position2.y) * percentage * scalar;
}
