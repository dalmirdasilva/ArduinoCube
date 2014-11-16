/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__
#define __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__ 1

#include <Stairs.h>

Stairs::Stairs(Cube *cube, StairsParameters *parameters) : Effect(cube), parameters(parameters) {
}

void Stairs::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__ */
