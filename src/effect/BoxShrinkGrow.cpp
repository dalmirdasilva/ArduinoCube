/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ 1

#include <BoxShrinkGrow.h>
#include <Arduino.h>

BoxShrinkGrow::BoxShrinkGrow(Cube *cube, unsigned int iterations, unsigned int iterationDelay, BoxType boxType)
        : Effect(cube, iterations, iterationDelay), boxType(boxType) {
}

bool BoxShrinkGrow::iterate() {
    cube->useDoubleBuffer();
    shrink();
    grow();
    cube->useSingleBuffer();
    return true;
}

void BoxShrinkGrow::shrink() {
    for (signed char size = Cube::SIZE - 1; size >= 0; size--) {
        drawFrame(size);
    }
}

void BoxShrinkGrow::grow() {
    for (signed char size = 0; size < Cube::SIZE; size++) {
        drawFrame(size);
    }
}

void BoxShrinkGrow::drawFrame(signed char size) {
    draw(size);
    cube->swapBuffers();
    delay(iterationDelay);
}

void BoxShrinkGrow::draw(signed char size) {
    Point from = Point();
    Point to = Point(size, size, size);
    cube->clear();
    switch (boxType) {
    case WIREFRAME:
        cube->wireframeBox(&from, &to);
        break;
    case FILLED:
        cube->filledBox(&from, &to);
        break;
    case WALL:
        cube->wallBox(&from, &to);
        break;
    }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_CPP__ */
