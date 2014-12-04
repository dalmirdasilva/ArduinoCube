/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__ 1

#include <BoingBoing.h>

BoingBoing::BoingBoing(Cube *cube, unsigned int iterations, unsigned int iterationDelay) :
    Effect(cube, iterations, iterationDelay) {
}

void BoingBoing::run() {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOING_BOING_CPP__ */
