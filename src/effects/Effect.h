/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_H__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_H__ 1

#include <Effect.h>
#include <Cube.h>

class Effect : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } EffectParameters;

  EffectParameters *parameters;

  Effect(Cube *cube, EffectParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_H__ */
