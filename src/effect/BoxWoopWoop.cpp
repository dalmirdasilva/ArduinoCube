/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__ 1

#include <BoxWoopWoop.h>

BoxWoopWoop::BoxWoopWoop(Cube *cube, unsigned int iterations, unsigned int iterationDelay) :
    Effect(cube, iterations, iterationDelay) {
}

void BoxWoopWoop::run() {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {
      /*int i, ii;
      cube->clear();
      for (i = 0; i < 4; i++) {
          ii = i;
          if (grow > 0) {
              ii = 3 - i;
          }
          box_wireframe(4 + ii, 4 + ii, 4 + ii, 3 - ii, 3 - ii, 3 - ii);
          delay_ms(delay);
          fill(0x00);
      }*/
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__ */
