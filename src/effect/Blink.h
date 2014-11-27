/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BLINK_H__
#define __ARDUINO_CUBE_EFFECTS_BLINK_H__ 1

#include <Effect.h>
#include <Cube.h>

class Blink : public Effect {

public:

  typedef struct {
    int delay;
  } BlinkSettings;

  BlinkSettings *settings;

  Blink(Cube *cube, BlinkSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_BLINK_H__ */
