/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__
#define __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_CPP__ 1

#include <GameOfLife.h>

GameOfLife::GameOfLife(Cube *cube, GameOfLifeParameters *parameters) : Effect(cube), parameters(parameters) {
  genesis();
}

void GameOfLife::run() {
  unsigned char neighbors;
  int it;
  for (it = 0; it < parameters->iterations; it++) {
    nextGeneration();
    if (!hasChanges()) {
      return;
    }
		delay(parameters->delay);
  }
}

void GameOfLife::genesis() {
}

unsigned char GameOfLife::neighbors(Point *p) {
  cube->fitInRange(p);
  for ()
}

void GameOfLife::nextGeneration() {
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
