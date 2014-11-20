/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__
#define __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__ 1

#include <Effect.h>
#include <Cube.h>

class GameOfLife : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } GameOfLifeParameters;

  GameOfLifeParameters *parameters;

  GameOfLife(Cube *cube, GameOfLifeParameters *parameters);

  virtual void run();

  unsigned char neighbors(Point *p);

  void nextGeneration();

  unsigned char changes();
};

#endif /* __ARDUINO_CUBE_EFFECTS_GAME_OF_LIFE_H__ */
