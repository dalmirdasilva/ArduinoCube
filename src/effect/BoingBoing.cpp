/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__ 1

#include <BoingBoing.h>

BoingBoing::BoingBoing(Cube *cube, BoingBoingSettings *settings) : Effect(cube), settings(settings) {
}

void BoingBoing::run(unsigned int iterations) {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {

  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__ */
