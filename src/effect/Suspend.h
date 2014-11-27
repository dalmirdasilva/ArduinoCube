/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SUSPEND_H__
#define __ARDUINO_CUBE_EFFECTS_SUSPEND_H__ 1

#include <Effect.h>
#include <Cube.h>

class Suspend : public Effect {

public:

  typedef struct {

  } SuspendSettings;

  SuspendSettings *settings;

  Suspend(Cube *cube, SuspendSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_SUSPEND_H__ */
