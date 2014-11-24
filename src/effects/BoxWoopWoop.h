/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_H__
#define __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoxWoopWoop : public Effect {

public:

  typedef struct {

  } BoxWoopWoopSettings;

  BoxWoopWoopSettings *settings;

  BoxWoopWoop(Cube *cube, BoxWoopWoopSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_H__ */
