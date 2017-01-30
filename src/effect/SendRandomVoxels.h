/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SEND_RANDOM_VOXELS_H__
#define __ARDUINO_CUBE_EFFECTS_SEND_RANDOM_VOXELS_H__ 1

#include <Effect.h>
#include <Cube.h>

class SendRandomVoxels: public Effect {
public:

    SendRandomVoxels(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

    virtual void run();

    virtual bool iterate();
};

#endif /* __ARDUINO_CUBE_EFFECTS_SEND_RANDOM_VOXELS_H__ */
