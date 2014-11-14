/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_H__
#define __ARDUINO_CUBE_EFFECTS_RAIN_H__ 1

#include <Effect.h>
#include <Cube.h>

class Rain : public Effect {

public:
  
  typedef struct {
    unsigned int iterations;
    unsigned char minDrops;
    unsigned char maxDrops;
    unsigned char delay;
  } RainParameters;

  RainParameters *parameters;
  
  Rain(Cube *cube, RainParameters *parameters);
  
  virtual void run();
};
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_H__ */
