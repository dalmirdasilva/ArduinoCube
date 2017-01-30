/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoxShrinkGrow: public Effect {

public:

    typedef enum {
        WIREFRAME = 0x00,
        FILLED = 0x01,
        WALL = 0x02
    } BoxType;

    BoxShrinkGrow(Cube *cube, unsigned int iterations, unsigned int iterationDelay, BoxType boxType);

    virtual bool iterate();

    void shrink();

    void grow();

    void drawFrame(signed char size);

    virtual void draw(signed char size);

protected:

    BoxType boxType;
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ */
