/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__
#define __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ 1

#include <Ripples.h>

Ripples::Ripples(Cube *cube, RipplesParameters *parameters) : Effect(cube), parameters(parameters) {
}

void Ripples::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ */
