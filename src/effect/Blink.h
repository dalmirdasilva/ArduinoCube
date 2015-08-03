/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BLINK_H__
#define __ARDUINO_CUBE_EFFECTS_BLINK_H__ 1

#include <Effect.h>
#include <Cube.h>

class Blink : public Effect {
public:

  Blink(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_BLINK_H__ */
