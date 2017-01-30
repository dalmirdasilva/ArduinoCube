/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__
#define __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__ 1

#include <UpDown.h>
#include <Arduino.h>
#include <Util.h>

UpDown::UpDown(Cube *cube, unsigned int iterations, unsigned int iterationDelay, Axis axis, unsigned char initialPosition)
        : Effect(cube, iterations, iterationDelay), axis(axis), initialPosition(initialPosition) {
}

void UpDown::run() {
    cube->clear();
    for (unsigned char i = 0; i < Cube::BYTE_SIZE; i++) {
        locations[i].position = initialPosition;
    }
    Effect::run();
}

bool UpDown::iterate() {
    for (unsigned char i = 0; i < Cube::BYTE_SIZE; i++) {
        locations[i].destination = random(Cube::SIZE);
    }
    for (unsigned char i = 0; i < Cube::SIZE; i++) {
        move();
        draw();
        delay(iterationDelay);
    }
    return true;
}

void UpDown::draw() {
    unsigned char i, j, p;
    cube->useDoubleBuffer();
    cube->clear();
    for (i = 0; i < Cube::SIZE; i++) {
        for (j = 0; j < Cube::SIZE; j++) {
            p = locations[i * Cube::SIZE + j].position;
            switch (axis) {
            case AXIS_Z:
                cube->writeVoxel(i, j, p, ON);
                break;
            case AXIS_Y:
                cube->writeVoxel(i, p, j, ON);
                break;
            case AXIS_X:
                cube->writeVoxel(p, j, i, ON);
                break;
            }
        }
    }
    cube->swapBuffers();
    cube->useSingleBuffer();
}

void UpDown::move() {
    unsigned char i;
    for (i = 0; i < Cube::BYTE_SIZE; i++) {
        Location *location = &(locations[i]);
        if (location->position < location->destination) {
            location->position++;
        }
        if (location->position > location->destination) {
            location->position--;
        }
    }
}

#endif /* __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__ */
