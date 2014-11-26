/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__
#define __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__ 1

#include <FlowingBox.h>

FlowingBox::FlowingBox(Cube *cube, FlowingBoxSettings *settings) : Effect(cube), settings(settings) {
}

void FlowingBox::run(unsigned int iterations) {
  for (iteration = 0; iteration < iterations; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__ */