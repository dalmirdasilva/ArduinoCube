/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_H__
#define __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_H__ 1

#include <Effect.h>
#include <Cube.h>

class TurnOnRandomly : public Effect {

public:

  typedef struct {
    unsigned char maxOnVoxels;
  } TurnOnRandomlySettings;

  TurnOnRandomlySettings *settings;

  Blink(Cube *cube, TurnOnRandomlySettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_H__ */
