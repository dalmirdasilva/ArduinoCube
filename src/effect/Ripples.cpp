/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__
#define __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ 1

#include <Ripples.h>

Ripples::Ripples(Cube *cube, RipplesSettings *settings) : Effect(cube), settings(settings) {
}

void Ripples::run(unsigned int iterations) {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {

  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ */
