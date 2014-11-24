/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_H__
#define __ARDUINO_CUBE_EFFECTS_RAIN_H__ 1

#include <Effect.h>
#include <Cube.h>

class Rain : public Effect {

public:
  
  typedef struct {
    unsigned char minDrops;
    unsigned char maxDrops;
    unsigned char delay;
  } RainSettings;

  RainSettings *settings;

  Rain(Cube *cube, RainSettings *settings);
  
  virtual void run(unsigned int iterations);
};
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_H__ */
