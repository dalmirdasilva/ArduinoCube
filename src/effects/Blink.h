/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BLINK_H__
#define __ARDUINO_CUBE_EFFECTS_BLINK_H__ 1

#include <Effect.h>
#include <Cube.h>

class Blink : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } BlinkParameters;

  BlinkParameters *parameters;


  Blink(Cube *cube, BlinkParameters *parameters);

  virtual void run();

  void executeBlink();
};

#endif /* __ARDUINO_CUBE_EFFECTS_BLINK_H__ */
