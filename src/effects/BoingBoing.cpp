/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__ 1

#include <BoingBoing.h>

BoingBoing::BoingBoing(Cube *cube, BoingBoingParameters *parameters) : Effect(cube), parameters(parameters) {
}

void BoingBoing::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__ */
