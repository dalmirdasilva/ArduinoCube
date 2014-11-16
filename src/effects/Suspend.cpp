/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__
#define __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__ 1

#include <Suspend.h>

Suspend::Suspend(Cube *cube, SuspendParameters *parameters) : Effect(cube), parameters(parameters) {
}

void Suspend::run() {
  for (int it = 0; it < parameters->iterations; it++) {
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__ */
