/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__
#define __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ 1

#include <Ripples.h>

Ripples::Ripples(Cube *cube, unsigned int iterations, unsigned int iterationDelay) :
    Effect(cube, iterations, iterationDelay) {
}

void Ripples::run() {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {

  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ */
