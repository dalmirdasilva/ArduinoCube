/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__
#define __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__ 1

#include <GameOfLife.h>
#include <Arduino.h>

GameOfLife::GameOfLife(Cube *cube, unsigned int iterations, unsigned int iterationDelay, unsigned char firstGenerationSize)
        : Effect(cube, iterations, iterationDelay), firstGenerationSize(firstGenerationSize) {
}

void GameOfLife::run() {
    cube->useDoubleBuffer();
    genesis();
    cube->copyBuffer(Cube::BACK_TO_FRONT);
    delay(1000);
    Effect::run();
    cube->useSingleBuffer();
}

bool GameOfLife::iterate() {
    nextGeneration();
    bool changed = hasChanges();

    // Swap buffers is not enough for us. We have to make sure we are using the exactly the last generation.
    cube->copyBuffer(Cube::BACK_TO_FRONT);
    delay(iterationDelay);
    return changed;
}

void GameOfLife::genesis() {
    Point p;
    cube->clear();
    for (unsigned char i = 0; i < firstGenerationSize; i++) {
        p.randomize(Cube::SIZE);
        cube->turnVoxelOn(&p);
    }
}

void GameOfLife::nextGeneration() {
    Point p;
    Voxel v;
    for (p.z = 0; p.z < Cube::SIZE; p.z++) {
        for (p.y = 0; p.y < Cube::SIZE; p.y++) {
            for (p.x = 0; p.x < Cube::SIZE; p.x++) {
                if (cube->isInRange(&p)) {
                    unsigned char neighbors = getNeighbors(&p);
                    cube->readVoxel(&p, &v);
                    if (v.state == ON) {
                        if (neighbors <= LONELY_DEATH || neighbors >= CROWDED_DEATH) {
                            cube->turnVoxelOff(&p);
                        }
                    } else {
                        if (neighbors >= CREATE_MIN && neighbors <= CREATE_MAX) {
                            cube->turnVoxelOn(&p);
                        }
                    }
                }
            }
        }
    }
}

unsigned char GameOfLife::getNeighbors(Point *at) {
    unsigned char neighbors = 0;
    Point p;
    Voxel v;
    cube->fitInRange(&p);
    for (int z = at->z - 1; z <= at->z + 1; z++) {
        for (int y = at->y - 1; y <= at->y + 1; y++) {
            for (int x = at->x - 1; x <= at->x + 1; x++) {
                p.x = x & 0xff;
                p.y = y & 0xff;
                p.z = z & 0xff;
                if (cube->isInRange(&p)) {

                    // Reads the voxel from the buffer we are not using to write to.
                    cube->swapBuffers();
                    cube->readVoxel(&p, &v);
                    cube->swapBuffers();
                    if (!p.is(at) && (v.state == ON)) {
                        neighbors++;
                    }
                }
            }
        }
    }
    return neighbors;
}

bool GameOfLife::hasChanges() {
    for (unsigned int pos = 0; pos < Cube::BYTE_SIZE; pos++) {
        if (*(cube->frontBuffer + pos) != *(cube->backBuffer + pos)) {
            return true;
        }
    }
    return false;
}

#endif /* __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__ */
