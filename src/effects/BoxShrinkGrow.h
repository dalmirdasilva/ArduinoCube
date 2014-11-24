/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoxShrinkGrow : public Effect {

public:

  typedef struct {
  } BoxShrinkGrowSettings;

  BoxShrinkGrowSettings *settings;

  BoxShrinkGrow(Cube *cube, BoxShrinkGrowSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ */
