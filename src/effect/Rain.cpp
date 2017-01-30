/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_CPP__
#define __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ 1

#include <Rain.h>
#include <Arduino.h>
#include <Point.h>

Rain::Rain(Cube *cube, unsigned int iterations, unsigned int iterationDelay, unsigned char minDrops, unsigned char maxDrops)
        : Effect(cube, iterations, iterationDelay), minDrops(minDrops), maxDrops(maxDrops) {
}

bool Rain::iterate() {
    Point p = Point(0, 0, Cube::SIZE - 1);
    unsigned char n = random(minDrops, maxDrops);
    for (unsigned char k = 0; k < n; k++) {
        p.x = random(0, Cube::SIZE);
        p.y = random(0, Cube::SIZE);
        cube->turnVoxelOn(&p);
    }
    delay(iterationDelay);
    cube->shiftOnZ(DOWN);
    cube->turnPlaneZOff(Cube::SIZE - 1);
    return true;
}

#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ */
