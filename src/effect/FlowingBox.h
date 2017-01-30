/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_H__
#define __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_H__ 1

#include <Effect.h>
#include <Cube.h>

class FlowingBox: public Effect {
public:

    FlowingBox(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

    virtual bool iterate();
};

#endif /* __ARDUINO_CUBE_EFFECTS_FLOWING_BOX_H__ */
