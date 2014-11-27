/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__
#define __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__ 1

#include <Suspend.h>

Suspend::Suspend(Cube *cube, SuspendSettings *settings) : Effect(cube), settings(settings) {
}

void Suspend::run(unsigned int iterations) {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__ */
