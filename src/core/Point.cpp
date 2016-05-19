/**
 */
 
#ifndef __ARDUINO_CUBE_POINT_CPP__
#define __ARDUINO_CUBE_POINT_CPP__ 1

#include <Point.h>
#include <Arduino.h>
#include <stdlib.h>
#include <math.h>

Point::Point() {
  init(0, 0, 0);
}

Point::Point(unsigned int x, unsigned int y, unsigned int z) {
  init(x, y, z);
}

void Point::randomize(unsigned int maxRange) {
  x = random(maxRange);
  y = random(maxRange);
  z = random(maxRange);
}

unsigned int Point::distanceOnXTo(Point *p) {
  return (unsigned int) abs(x - p->x);
}

unsigned int Point::distanceOnYTo(Point *p) {
  return (unsigned int) abs(y - p->y);
}

unsigned int Point::distanceOnZTo(Point *p) {
  return (unsigned int) abs(z - p->z);
}

float Point::distance2DTo(Point *p) {
  unsigned int dx = distanceOnXTo(p);
  unsigned int dy = distanceOnYTo(p);
  return sqrt(dx * dx + dy * dy);
}

float Point::distance3DTo(Point *p) {
  unsigned int dx = distanceOnXTo(p);
  unsigned int dy = distanceOnYTo(p);
  unsigned int dz = distanceOnZTo(p);
  return sqrt(dx * dx + dy * dy + dz * dz);
}

#endif /* __ARDUINO_CUBE_POINT_CPP__ */
