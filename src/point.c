#include "point.h"

Point point_subtract(Point point1, Point point2) {
  Point point;
  point.x = point1.x - point2.x;
  point.y = point1.y - point2.y;
  return point;
}

Point point_add(Point point1, Point point2) {
  Point point;
  point.x = point1.x + point2.x;
  point.y = point1.y + point2.y;
  return point;
}

float point_distance(Point point1, Point point2) {
  float x_difference = point1.x - point2.x;
  float y_difference = point1.y - point2.y;
  return sqrt(pow(x_difference, 2) + pow(y_difference, 2));
}

float point_scalar(Point point1, Point point2) {
  float distance = point_distance(point1, point2);
  return (1 - distance) / distance;
}
