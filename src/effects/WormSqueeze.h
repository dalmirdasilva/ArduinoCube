/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__
#define __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__ 1

#include <Effect.h>
#include <Cube.h>

class WormSqueeze : public Effect {

public:

  typedef struct {

  } WormSqueezeSettings;

  WormSqueezeSettings *settings;

  WormSqueeze(Cube *cube, WormSqueezeSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__ */
