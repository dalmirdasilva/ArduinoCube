/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__ 1

#include <BoxWoopWoop.h>

BoxWoopWoop::BoxWoopWoop(Cube *cube, BoxWoopWoopParameters *parameters) : Effect(cube), parameters(parameters) {
}

void BoxWoopWoop::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__ */
