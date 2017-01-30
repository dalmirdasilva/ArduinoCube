/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__
#define __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__ 1

#include <FlowingBox.h>

FlowingBox::FlowingBox(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : Effect(cube, iterations, iterationDelay) {
}

bool FlowingBox::iterate() {
    return false;
}

#endif /* __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_CPP__ */
