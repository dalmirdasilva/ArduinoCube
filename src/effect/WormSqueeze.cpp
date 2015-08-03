/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__
#define __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__ 1

#include <WormSqueeze.h>

WormSqueeze::WormSqueeze(Cube *cube, unsigned int iterations, unsigned int iterationDelay) :
    Effect(cube, iterations, iterationDelay) {
}

void WormSqueeze::run() {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__ */
