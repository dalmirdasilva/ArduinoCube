/**
 */
 
#ifndef __ARDUINO_CUBE_UTIL_CPP__
#define __ARDUINO_CUBE_UTIL_CPP__ 1

#include <Util.h>

void Util::dumpPoint(Point *p) {
  printf("Point {\n  x: %d,\n  y: %d,\n  z: %d\n}\n", p->x, p->y, p->z);
}

void Util::dumpCube(unsigned char *buffer) {
  unsigned z, y;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      printf("[%d,%d]%02x ", z, y, *(buffer + (Cube::SIZE * z) + y));
    }
    printf("\n");
  }
  printf("\n");
}

unsigned char Util::shift(unsigned char v, unsigned char isLeft) {
  if (isLeft) {
    return (v << 1) | (v >> 7 & 0x01);
  } else {
    return (v >> 1) | (v << 7 & 0x80);
  }
}

#endif /* __ARDUINO_CUBE_UTIL_CPP__ */

