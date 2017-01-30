/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_CPP__
#define __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_CPP__ 1

#include <TurnOnRandomly.h>
#include <Arduino.h>
#include <Point.h>

TurnOnRandomly::TurnOnRandomly(Cube *cube, unsigned int iterations, unsigned int iterationDelay, unsigned char maxOnVoxels)
        : Effect(cube, iterations, iterationDelay), maxOnVoxels(maxOnVoxels) {
}

bool TurnOnRandomly::iterate() {
    Point p;
    cube->clear();
    for (unsigned char i = 0; i < maxOnVoxels; i++) {
        p.randomize(Cube::SIZE);
        cube->turnVoxelOn(&p);
    }
    delay(iterationDelay);
    return true;
}

#endif /* __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_CPP__ */
