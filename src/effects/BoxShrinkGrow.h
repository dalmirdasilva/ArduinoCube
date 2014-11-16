/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoxShrinkGrow : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } BoxShrinkGrowParameters;

  BoxShrinkGrowParameters *parameters;

  BoxShrinkGrow(Cube *cube, BoxShrinkGrowParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ */
