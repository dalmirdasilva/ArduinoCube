/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__
#define __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__ 1

#include <Effect.h>
#include <Cube.h>

class WormSqueeze: public Effect {
public:

    WormSqueeze(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

    virtual bool iterate();
};

#endif /* __ARDUINO_CUBE_EFFECTS_WORM_SQUEEZE_H__ */
