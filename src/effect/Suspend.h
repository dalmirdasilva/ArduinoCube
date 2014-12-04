/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SUSPEND_H__
#define __ARDUINO_CUBE_EFFECTS_SUSPEND_H__ 1

#include <Effect.h>
#include <Cube.h>

class Suspend : public Effect {
public:

  Suspend(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_SUSPEND_H__ */
