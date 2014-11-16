/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAMEOFLIFE_CPP__
#define __ARDUINO_CUBE_EFFECTS_GAMEOFLIFE_CPP__ 1

#include <Gameoflife.h>

Gameoflife::Gameoflife(Cube *cube, GameoflifeParameters *parameters) : Effect(cube), parameters(parameters) {
}

void Gameoflife::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_GAMEOFLIFE_CPP__ */
