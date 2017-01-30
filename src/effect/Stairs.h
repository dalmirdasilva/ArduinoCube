/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_STAIRS_H__
#define __ARDUINO_CUBE_EFFECTS_STAIRS_H__ 1

#include <Effect.h>
#include <Cube.h>

class Stairs : public Effect {
public:

  Stairs(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

  virtual bool iterate();
};

#endif /* __ARDUINO_CUBE_EFFECTS_STAIRS_H__ */
