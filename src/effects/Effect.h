/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_H__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_H__ 1

#include <Drawer.h>

class Effect {
  
  Drawer *drawer;
  
  Effect(Drawer *drawer);
  
  virtual void run(void *parameters);
};
  
#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_H__ */
