/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ 1

#include <BoxShrinkGrow.h>
#include <Arduino.h>

BoxShrinkGrow::BoxShrinkGrow(Cube *cube, unsigned int iterations, unsigned int iterationDelay, BoxType boxType) :
    Effect(cube, iterations, iterationDelay), boxType(boxType) {
}

void BoxShrinkGrow::run() {
  unsigned int iteration;
  cube->useBackBuffer();
  for (iteration = 0; iteration < iterations; iteration++) {
    grow();
    shrink();
  }
  cube->useFrontBuffer();
}

void BoxShrinkGrow::shrink() {
  char size;
  for (size = Cube::SIZE - 1; size >= 0; size--) {
    drawFrame(size);
  }
}

void BoxShrinkGrow::grow() {
  char size;
  for (size = 0; size < Cube::SIZE; size++) {
    drawFrame(size);
  }
}

void BoxShrinkGrow::drawFrame(char size) {
    draw(size);
    cube->swapBuffers();
    delay(iterationDelay);
}

void BoxShrinkGrow::draw(char size) {
  Point from = Point();
  Point to = Point(size, size, size);
  cube->clear();
  switch(boxType) {
    case WIREFRAME:
      cube->wireframeBox(&from, &to);
      break;
    case FILLED:
      cube->filledBox(&from, &to);
      break;
    case WALL:
      cube->wallBox(&from, &to);
      break;
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ */
