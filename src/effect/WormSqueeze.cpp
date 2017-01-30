/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__
#define __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__ 1

#include <WormSqueeze.h>

WormSqueeze::WormSqueeze(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : Effect(cube, iterations, iterationDelay) {
}

bool WormSqueeze::iterate() {
    return false;
}

#endif /* __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_CPP__ */
