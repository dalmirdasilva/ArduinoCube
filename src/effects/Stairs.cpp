/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__
#define __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__ 1

#include <Stairs.h>

Stairs::Stairs(Cube *cube, StairsSettings *settings) : Effect(cube), settings(settings) {
}

void Stairs::run(unsigned int iterations) {
  for (iteration = 0; iteration < iterations ; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__ */
