/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SEND_RANDOM_VOXELS_CPP__
#define __ARDUINO_CUBE_EFFECTS_SEND_RANDOM_VOXELS_CPP__ 1

#include "SendRandomVoxels.h"
#include <Cube.h>
#include <Voxel.h>
#include <Arduino.h>

SendRandomVoxels::SendRandomVoxels(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : Effect(cube, iterations, iterationDelay) {
}

void SendRandomVoxels::run() {
    Point p = Point();
    cube->useSingleBuffer();
    cube->clear();
    // Loop through all the X and Y coordinates
    for (p.x = 0; p.x < Cube::SIZE; p.x++) {
        for (p.y = 0; p.y < Cube::SIZE; p.y++) {
            p.z = ((rand() % 2) * (Cube::SIZE - 1));
            cube->turnVoxelOn(&p);
        }
    }
    delay(4000);
    Effect::run();
}

bool SendRandomVoxels::iterate() {

    unsigned char last_x = 0, last_y = 0;
    Point p = Point();
    Voxel v;

    // Pick a random x,y position
    p.x = rand() % 8;
    p.y = rand() % 8;

    // but not the same one twice in a row
    if (p.y != last_y && p.x != last_x) {

        // If the voxel at this x,y is at the bottom
        p.z = 0;
        cube->readVoxel(&p, &v);
        if (v.state == ON) {

            // send it to the top
            sendVoxel(&p, DOWN, 100);
        } else {

            sendVoxel(&p, UP, 100);
        }

        // Remember the last move
        last_y = p.y;
        last_x = p.x;
    }
    delay(iterationDelay);
    return true;
}

#endif /* __ARDUINO_CUBE_EFFECTS_SEND_RANDOM_VOXELS_CPP__ */
