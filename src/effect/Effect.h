/**
 * 
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_H__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_H__ 1

#include <Cube.h>
#include <math.h>

class Effect {


public:

  Cube *cube;

  Effect(Cube *cube);
  
  virtual void run(unsigned int iterations);

  void sendVoxel(Point *origin, Direction direction, unsigned int wait);
};
  
#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_H__ */