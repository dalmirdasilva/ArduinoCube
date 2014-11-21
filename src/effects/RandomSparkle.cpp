/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__
#define __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ 1

#include <RandomSparkle.h>

RandomSparkle::RandomSparkle(Cube *cube, RandomSparkleParameters *parameters) : Effect(cube), parameters(parameters) {
}

void RandomSparkle::run() {
  int it;
  for (it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ */
