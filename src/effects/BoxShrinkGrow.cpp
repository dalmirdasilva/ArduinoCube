/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ 1

#include <BoxShrinkGrow.h>

BoxShrinkGrow::BoxShrinkGrow(Cube *cube, BoxShrinkGrowParameters *parameters) : Effect(cube), parameters(parameters) {
}

void BoxShrinkGrow::run() {
  int iteration, x, i, xyz;
  for (int iteration = 0; iteration < parameters->iterations; iteration++) {
    for (i = 0; i < 16; i++) {
      xyz = 7 - i; // This reverses counter i between 0 and 7.
      if (i > 7) {
          xyz = i - 8; // at i > 7, i 8-15 becomes xyz 0-7.
      }
      fill(0x00);
      delay_ms(1);

      // disable interrupts while the cube is being rotated
      INTCONbits.GIE = 0;

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
  }
}

void BoxShrinkGrow::drawWireframeBox(size) {
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ */
