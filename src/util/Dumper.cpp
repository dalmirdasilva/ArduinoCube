/**
 */
 
#ifndef __ARDUINO_CUBE_DUMPER_CPP__
#define __ARDUINO_CUBE_DUMPER_CPP__ 1

#include <Dumper.h>

void Dumper::dumpPoint(Point *point) {
  printf("Point {\n  x: %d,\n  y: %d,\n  z: %d\n}\n", point->x, point->y, point->z);
}

void Dumper::dumpCube(Cube *cube) {
  unsigned char z, y, *buffer;
  buffer = cube->frontBuffer;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      printf("[%d,%d]%02x ", z, y, *(buffer + (Cube::SIZE * z) + y));
    }
    printf("\n");
  }
  printf("\n");
}

#endif /* __ARDUINO_CUBE_DUMPER_CPP__ */

