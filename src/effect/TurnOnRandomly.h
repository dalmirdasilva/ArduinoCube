/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_H__
#define __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_H__ 1

#include <Effect.h>
#include <Cube.h>

class TurnOnRandomly : public Effect {

  unsigned char maxOnVoxels;

public:

  TurnOnRandomly(Cube *cube, unsigned int iterations, unsigned int iterationDelay, unsigned char maxOnVoxels);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_H__ */
