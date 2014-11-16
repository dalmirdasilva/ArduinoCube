/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__
#define __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__ 1

#include <UpDown.h>

UpDown::UpDown(Cube *cube, UpDownParameters *parameters) : Effect(cube), parameters(parameters) {
}

void UpDown::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__ */
