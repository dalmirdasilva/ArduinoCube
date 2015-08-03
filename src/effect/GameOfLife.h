/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__
#define __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__ 1

#include <Effect.h>
#include <Cube.h>

class GameOfLife : public Effect {

  unsigned char firstGenerationSize;

public:

  static const unsigned char LONELY_DEATH = 1;
  static const unsigned char CROWDED_DEATH = 4;
  static const unsigned char CREATE_MIN = 3;
  static const unsigned char CREATE_MAX = 3;

  GameOfLife(Cube *cube, unsigned int iterations, unsigned int iterationDelay, unsigned char firstGenerationSize);

  virtual void run();

  void genesis();

  unsigned char getNeighbors(Point *p);

  void nextGeneration();

  bool hasChanges();
};

#endif /* __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__ */
