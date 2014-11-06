/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_H__
#define __ARDUINO_CUBE_EFFECTS_RAIN_H__ 1

#include <Effect.h>
#include <Point.h>
#include <Cube.h>

class Rain : public Effect {
  
  unsigned char minDrops;
  unsigned char maxDrops;
  RainParameters *parameters;
  
public:
  
  struct {
    unsigned int iterations;
    unsigned char intensity;
    unsigned char delay;
  } RainParameters;
  
  Rain(Drawer *drawer, RainParameters *parameters);
  
  virtual void run();
}
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_H__ */
