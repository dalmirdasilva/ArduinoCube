/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__
#define __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__ 1

#include <GameOfLife.h>
#include <Arduino.h>

GameOfLife::GameOfLife(Cube *cube, GameOfLifeSettings *settings) : Effect(cube), settings(settings) {
  genesis();
}

void GameOfLife::run(unsigned int iterations) {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {
    nextGeneration();
    if (!hasChanges()) {
      return;
    }
		delay(settings->delay);
  }
}

void GameOfLife::genesis() {
  unsigned char i;
  Point p;
  cube->clear();
  for (i = 0; i < settings->firstGenerationSize; i++) {
    p.randomize(Cube::SIZE);
    cube->turnVoxelOn(&p);
  }
}

void GameOfLife::nextGeneration() {
	unsigned char neighbors;
	Point p;
	Voxel v;
	cube->useBackBuffer();
	cube->clear();
	for (p.z = 0; p.z < Cube::SIZE; p.z++) {
    for (p.y = 0; p.y < Cube::SIZE; p.y++) {
      for (p.x = 0; p.x < Cube::SIZE; p.x++) {
				neighbors = getNeighbors(&p);
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
	cube->swapBuffers();
	cube->useFrontBuffer();
}

unsigned char GameOfLife::getNeighbors(Point *at) {
  unsigned char neighbors = 0;
  Point p;
  Voxel v;
  cube->fitInRange(&p);
  for (p.z = at->z - 1; p.z <= at->z + 1; p.z++) {
    for (p.y = at->y - 1; p.y <= at->y + 1; p.y++) {
      for (p.x = at->x - 1; p.x <= at->x + 1; p.x++) {
        if (cube->isInRange(&p)) {
          cube->readVoxel(&p, &v);
          if ((p.z != 0 || p.y != 0 || p.x != 0) && (v.state == ON)) {
            neighbors++;
          }
        }
      }
    }
  }
  return neighbors;
}

bool GameOfLife::hasChanges() {
	unsigned char z, y;
	for (z = 0; z < Cube::SIZE; z++) {
		for (y = 0; y < Cube::SIZE; y++) {
		  unsigned char pos = z * Cube::SIZE + y;
			if (*(cube->frontBuffer + pos) != *(cube->backBuffer + pos)) {
				return true;
      }
		}
	}
	return false;
}

#endif /* __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__ */
