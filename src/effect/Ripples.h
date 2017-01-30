/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RIPPLES_H__
#define __ARDUINO_CUBE_EFFECTS_RIPPLES_H__ 1

#include <Effect.h>
#include <Cube.h>

class Ripples: public Effect {
public:

    Ripples(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

    virtual bool interate();
};

#endif /* __ARDUINO_CUBE_EFFECTS_RIPPLES_H__ */
