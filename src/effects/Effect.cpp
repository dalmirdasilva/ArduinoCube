/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ 1

#include <Effect.h>

Effect::Effect(Cube *cube, EffectParameters *parameters) : Effect(cube), parameters(parameters) {
}

void Effect::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ */
