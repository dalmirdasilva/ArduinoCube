/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_CPP__
#define __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_CPP__ 1

#include <MovingBoxShrinkGrow.h>

const unsigned char MovingBoxShrinkGrow::MAX_DIFF_MOVEMENTS = 0x03;

MovingBoxShrinkGrow::MovingBoxShrinkGrow(Cube *cube, unsigned int iterations, unsigned int iterationDelay, BoxType boxType) :
   BoxShrinkGrow(cube, iterations, iterationDelay, boxType) {
}

void MovingBoxShrinkGrow::run() {
  unsigned int iteration;
  cube->useBackBuffer();
  for (iteration = 0; iteration < iterations; iteration++) {
    grow();
    state++;
    shrink();
  }
  cube->useFrontBuffer();
}

void MovingBoxShrinkGrow::draw(char size) {
  this->BoxShrinkGrow::draw(size);
  switch(state % MAX_DIFF_MOVEMENTS) {
    case 0:
      cube->mirrorX();
      break;
    case 1:
      cube->mirrorY();
      break;
    case 2:
      cube->mirrorZ();
      break;
  }
}
#endif /* __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_CPP__ */
