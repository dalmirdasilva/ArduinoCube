/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_H__
#define __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_H__ 1

#include <BoxShrinkGrow.h>
#include <Cube.h>

class MovingBoxShrinkGrow: public BoxShrinkGrow {
public:

    const static unsigned char MAX_DIFF_MOVEMENTS;

    MovingBoxShrinkGrow(Cube *cube, unsigned int iterations, unsigned int iterationDelay, BoxType boxType);

    void draw(signed char size);
};

#endif /* __ARDUINO_CUBE_EFFECTS_MOVING_BOX_SHRINK_GROW_H__ */
