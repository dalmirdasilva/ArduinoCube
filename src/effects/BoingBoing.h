/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__
#define __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoingBoing : public Effect {

public:

  typedef struct {
  } BoingBoingSettings;

  BoingBoingSettings *settings;

  BoingBoing(Cube *cube, BoingBoingSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__ */
