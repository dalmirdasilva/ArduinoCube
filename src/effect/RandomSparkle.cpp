/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__
#define __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ 1

#include <RandomSparkle.h>

RandomSparkle::RandomSparkle(Cube *cube, unsigned int iterations, unsigned int iterationDelay) :
    Effect(cube, iterations, iterationDelay) {
}

void RandomSparkle::run() {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ */
