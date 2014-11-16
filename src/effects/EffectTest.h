/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_EFFECTTEST_H__
#define __ARDUINO_CUBE_EFFECTS_EFFECTTEST_H__ 1

#include <Effect.h>
#include <Cube.h>

class Effecttest : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } EffecttestParameters;

  EffecttestParameters *parameters;

  Effecttest(Cube *cube, EffecttestParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_EFFECTTEST_H__ */
