/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__
#define __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoingBoing : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } BoingBoingParameters;

  BoingBoingParameters *parameters;

  BoingBoing(Cube *cube, BoingBoingParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__ */
