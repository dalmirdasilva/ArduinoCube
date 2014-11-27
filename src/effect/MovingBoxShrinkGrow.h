/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_H__
#define __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_H__ 1

#include <BoxShrinkGrow.h>
#include <Cube.h>

class MovingBoxShrinkGrow : public BoxShrinkGrow {

public:

  const static unsigned char MAX_DIFF_MOVEMENTS;
  unsigned char state;

  typedef struct {
    BoxShrinkGrowSettings *parentSettings;
  } MovingBoxShrinkGrowSettings;

  MovingBoxShrinkGrowSettings *settings;

  MovingBoxShrinkGrow(Cube *cube, MovingBoxShrinkGrowSettings *settings);

  virtual void run(unsigned int iterations);

  void draw(char size);
};

#endif /* __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_H__ */
