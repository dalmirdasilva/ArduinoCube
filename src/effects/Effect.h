/**
 * 
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_H__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_H__ 1

#include <Cube.h>

class Effect {


public:

  Cube *cube;

  Effect(Cube *cube);
  
  virtual void run() = 0;
};
  
#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_H__ */
