/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_H__
#define __ARDUINO_CUBE_EFFECTS_RAIN_H__ 1

#include <Effect.h>
#include <Cube.h>

class Rain : public Effect {

  unsigned char minDrops;
  unsigned char maxDrops;

public:

  Rain(Cube *cube, unsigned int iterations, unsigned int iterationDelay, unsigned char minDrops, unsigned char maxDrops);
  
  virtual void run();
};
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_H__ */
