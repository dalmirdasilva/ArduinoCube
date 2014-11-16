/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_EFFECTTEST_CPP__
#define __ARDUINO_CUBE_EFFECTS_EFFECTTEST_CPP__ 1

#include <Effecttest.h>

Effecttest::Effecttest(Cube *cube, EffecttestParameters *parameters) : Effect(cube), parameters(parameters) {
}

void Effecttest::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_EFFECTTEST_CPP__ */
