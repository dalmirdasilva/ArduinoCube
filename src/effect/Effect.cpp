/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ 1

#include <Effect.h>
#include <Cube.h>
#include <Arduino.h>

Effect::Effect(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : cube(cube), iterations(iterations), iterationDelay(iterationDelay), iteration(0) {
}

Effect::~Effect() {
}

void Effect::run() {
    iteration = 0;
    while (iterate() && ++iteration < iterations)
        ;
}

void Effect::sendVoxel(Point *p, Direction dir, unsigned int stepDelay) {
    Voxel origin, current;
    char *axis = NULL, inc = 1;
    cube->readVoxel(p, &origin);
    switch (dir) {
    case UP:
        inc = -1;
        /* no break */
    case DOWN:
        axis = (char*) &(p->z);
        break;
    case FRONT:
        inc = -1;
        /* no break */
    case BACK:
        axis = (char*) &(p->y);
        break;
    case RIGHT:
        inc = -1;
        /* no break */
    case LEFT:
        axis = (char*) &(p->x);
        break;
    }
    for (; (inc > 0) ? *axis < Cube::SIZE : *axis >= 0; *axis += inc) {
        cube->readVoxel(p, &current);
        cube->writeVoxel(p, origin);
        delay(stepDelay);
        cube->writeVoxel(p, current);
    }
}

#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ */
