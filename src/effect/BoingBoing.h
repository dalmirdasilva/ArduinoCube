/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__
#define __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoingBoing: public Effect {
public:

    BoingBoing(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

    virtual bool iterate();
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOING_BOING_H__ */
