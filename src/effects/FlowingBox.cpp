/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__
#define __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__ 1

#include <FlowingBox.h>

FlowingBox::FlowingBox(Cube *cube, FlowingBoxParameters *parameters) : Effect(cube), parameters(parameters) {
}

void FlowingBox::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__ */
