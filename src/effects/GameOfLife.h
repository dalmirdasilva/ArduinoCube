/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_GAMEOFLIFE_H__
#define __ARDUINO_CUBE_EFFECTS_GAMEOFLIFE_H__ 1

#include <Effect.h>
#include <Cube.h>

class Gameoflife : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } GameoflifeParameters;

  GameoflifeParameters *parameters;

  Gameoflife(Cube *cube, GameoflifeParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_GAMEOFLIFE_H__ */
