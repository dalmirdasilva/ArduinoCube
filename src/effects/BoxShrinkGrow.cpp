/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ 1

#include <BoxShrinkGrow.h>

BoxShrinkGrow::BoxShrinkGrow(Cube *cube, BoxShrinkGrowParameters *parameters) : Effect(cube), parameters(parameters) {
}

void BoxShrinkGrow::run() {
  int iteration, size;
  for (int iteration = 0; iteration < parameters->iterations; iteration++) {
    for (size = 0; size < Cube::SIZE; size++) {
      drawWireframeBox(size);
    }
    for (size = Cube::SIZE - 1; size >= 0; size--) {
      drawWireframeBox(size);
    }
  }
}

void BoxShrinkGrow::drawWireframeBox(size) {
  Point from, to = {size, size, size};
  cube->clear();
  cube->wireframeBox(&from, &to, Cube::BUFFER);


  box_wireframe(0, 0, 0, xyz, xyz, xyz);

  // upside-down
  if (flip > 0) {
      mirror_z();
  }
  if (rot == 1 || rot == 3) {
      mirror_y();
  }
  if (rot == 2 || rot == 3) {
      mirror_x();
  }

  // enable interrupts
  INTCONbits.GIE = 1;
  delay_ms(delay);
  fill(0x00);

}

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ */
