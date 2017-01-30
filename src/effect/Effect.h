/**
 * 
 */

#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_H__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_H__ 1

#include <Cube.h>
#include <math.h>

class Effect {

public:

    Cube *cube;
    unsigned int iterations;
    unsigned int iterationDelay;
    unsigned int iteration;

    Effect(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

    virtual ~Effect();

    virtual void run();

    virtual bool iterate() = 0;

    void sendVoxel(Point *origin, Direction direction, unsigned int stepDelay);
};

#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_H__ */
