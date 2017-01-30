/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__
#define __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ 1

#include <Ripples.h>

Ripples::Ripples(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : Effect(cube, iterations, iterationDelay) {
}

bool Ripples::interate() {
    return false;
}

#endif /* __ARDUINO_CUBE_EFFECTS_RIPPLES_CPP__ */
