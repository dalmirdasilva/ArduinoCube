/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__
#define __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__ 1

#include <WormSqueeze.h>

WormSqueeze::WormSqueeze(Cube *cube, WormSqueezeParameters *parameters) : Effect(cube), parameters(parameters) {
}

void WormSqueeze::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__ */
