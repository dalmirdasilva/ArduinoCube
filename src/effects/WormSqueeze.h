/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__
#define __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__ 1

#include <Effect.h>
#include <Cube.h>

class WormSqueeze : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } WormSqueezeParameters;

  WormSqueezeParameters *parameters;

  WormSqueeze(Cube *cube, WormSqueezeParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__ */
