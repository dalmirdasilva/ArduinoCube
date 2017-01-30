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

Point::Point(unsigned char x, unsigned char y, unsigned char z) {
    init(x, y, z);
}

void Point::randomize(unsigned char maxRange) {
    x = random(maxRange);
    y = random(maxRange);
    z = random(maxRange);
}

unsigned char Point::distanceOnXTo(Point *p) {
    return (unsigned char) abs(x - p->x);
}

unsigned char Point::distanceOnYTo(Point *p) {
    return (unsigned char) abs(y - p->y);
}

unsigned char Point::distanceOnZTo(Point *p) {
    return (unsigned char) abs(z - p->z);
}

float Point::distance2DTo(Point *p) {
    unsigned char dx = distanceOnXTo(p);
    unsigned char dy = distanceOnYTo(p);
    return sqrt(dx * dx + dy * dy);
}

float Point::distance3DTo(Point *p) {
    unsigned char dx = distanceOnXTo(p);
    unsigned char dy = distanceOnYTo(p);
    unsigned char dz = distanceOnZTo(p);
    return sqrt(dx * dx + dy * dy + dz * dz);
}

bool Point::is(Point *p) {
    return x == p->x && y == p->y && z == p->z;
}

#endif /* __ARDUINO_CUBE_POINT_CPP__ */
