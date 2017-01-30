/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_CPP__
#define __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_CPP__ 1

#include <MovingBoxShrinkGrow.h>
#include <Arduino.h>

const unsigned char MovingBoxShrinkGrow::MAX_DIFF_MOVEMENTS = 0x06;

MovingBoxShrinkGrow::MovingBoxShrinkGrow(Cube *cube, unsigned int iterations, unsigned int iterationDelay, BoxType boxType)
        : BoxShrinkGrow(cube, iterations, iterationDelay, boxType) {
}

void MovingBoxShrinkGrow::draw(signed char size) {
    BoxShrinkGrow::draw(size);
    switch (iteration % MAX_DIFF_MOVEMENTS) {
    case 0:
        cube->mirrorX();
        break;
    case 1:
        cube->mirrorY();
        break;
    case 2:
        cube->mirrorZ();
        break;
    case 3:
        cube->mirrorX();
        cube->mirrorY();
        break;
    case 4:
        cube->mirrorY();
        cube->mirrorZ();
        break;
    case 5:
        cube->mirrorZ();
        cube->mirrorX();
        break;
    }
}
#endif /* __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_CPP__ */
