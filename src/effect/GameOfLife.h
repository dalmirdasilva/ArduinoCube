/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__
#define __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__ 1

#include <Effect.h>
#include <Cube.h>

class GameOfLife : public Effect {

public:

  static const unsigned char LONELY_DEATH = 1;
  static const unsigned char CROWDED_DEATH = 4;
  static const unsigned char CREATE_MIN = 3;
  static const unsigned char CREATE_MAX = 3;

  typedef struct {
    unsigned int delay;
    unsigned char firstGenerationSize;
  } GameOfLifeSettings;

  GameOfLifeSettings *settings;

  GameOfLife(Cube *cube, GameOfLifeSettings *settings);

  virtual void run(unsigned int iterations);

  void genesis();

  unsigned char getNeighbors(Point *p);

  void nextGeneration();

  bool hasChanges();
};

#endif /* __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__ */
