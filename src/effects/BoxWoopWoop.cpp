/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__ 1

#include <BoxWoopWoop.h>

BoxWoopWoop::BoxWoopWoop(Cube *cube, BoxWoopWoopSettings *settings) : Effect(cube), settings(settings) {
}

void BoxWoopWoop::run(unsigned int iterations) {
  for (int iteration = 0; iteration < iterations; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_CPP__ */
