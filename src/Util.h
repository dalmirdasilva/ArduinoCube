/**
 */
 
#ifndef __ARDUINO_CUBE_UTIL_H__
#define __ARDUINO_CUBE_UTIL_H__ 1

#include <Point.h>
#include <Cube.h>
#include <stdio.h>

class Util {

public:

  static void dumpPoint(Point *p) {
    printf("Point {\n  x: %d,\n  y: %d,\n  z: %d\n}\n", p->x, p->y, p->z);
  }

  static void dumpCube(unsigned char *buffer) {
    unsigned z, y;
    for (z = 0; z < Cube::SIZE; z++) {
      for (y = 0; y < Cube::SIZE; y++) {
        printf("[%d,%d]%02x ", z, y, *(buffer + (Cube::SIZE * z) + y));
      }
      printf("\n");
    }
    printf("\n");
  }
  
  static unsigned char shift(unsigned char v, unsigned char is_left) {
    if (is_left) {
      return (v << 1) | (v >> 7 & 0x01);
    } else {
      return (v >> 1) | (v << 7 & 0x80);
    }
  } 
};

#endif /* __ARDUINO_CUBE_UTIL_H__ */
