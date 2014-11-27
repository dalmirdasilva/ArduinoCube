/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__
#define __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ 1

#include <RandomSparkle.h>

RandomSparkle::RandomSparkle(Cube *cube, RandomSparkleSettings *settings) : Effect(cube), settings(settings) {
}

void RandomSparkle::run(unsigned int iterations) {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ */
