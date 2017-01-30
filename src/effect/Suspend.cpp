/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__
#define __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__ 1

#include <Suspend.h>

Suspend::Suspend(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : Effect(cube, iterations, iterationDelay) {
}

bool Suspend::iterate() {
    return false;
}

#endif /* __ARDUINO_CUBE_EFFECTS_SUSPEND_CPP__ */
