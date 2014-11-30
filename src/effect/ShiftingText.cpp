/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__
#define __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__ 1

#include <ShiftingText.h>

ShiftingText::ShiftingText(Cube *cube, ShiftingTextSettings *settings) : Effect(cube), settings(settings) {
}

void ShiftingText::run(unsigned int iterations) {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {

  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__ */
