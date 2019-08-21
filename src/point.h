#pragma once

#include <math.h>

typedef struct {
  float x;
  float y;
} Point;

Point point_subtract(Point point1, Point point2);
Point point_add(Point point1, Point point2);
float point_distance(Point point1, Point point2);
float point_scalar(Point point1, Point point2);
