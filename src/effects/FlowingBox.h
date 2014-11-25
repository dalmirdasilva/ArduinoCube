/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_H__
#define __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_H__ 1

#include <Effect.h>
#include <Cube.h>

class FlowingBox : public Effect {

public:

  typedef struct {
  } FlowingBoxSettings;

  FlowingBoxSettings *settings;

  FlowingBox(Cube *cube, FlowingBoxSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_H__ */
