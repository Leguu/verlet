#pragma once

#include <math.h>

typedef struct {
  float x;
  float y;
} Point;

Point point_new(float, float);
Point point_subtract(Point, Point);
Point point_add(Point, Point);
float point_distance(Point, Point);
float point_scalar(Point, Point);
void point_redistance(Point *, Point, float);
