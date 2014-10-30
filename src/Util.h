/**
 */
 
#ifndef __ARDUINO_CUBE_UTIL_H__
#define __ARDUINO_CUBE_UTIL_H__ 1

#include <Point.h>
#include <stdio.h>

class Util {

public:

  static void dumpPoint(Point *p) {
    printf("Point {\n  x: %d,\n  y: %d,\n  z: %d\n}\n", p->x, p->y, p->z);
  }
};

#endif /* __ARDUINO_CUBE_UTIL_H__ */
