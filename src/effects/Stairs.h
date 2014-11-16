/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_STAIRS_H__
#define __ARDUINO_CUBE_EFFECTS_STAIRS_H__ 1

#include <Effect.h>
#include <Cube.h>

class Stairs : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } StairsParameters;

  StairsParameters *parameters;

  Stairs(Cube *cube, StairsParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_STAIRS_H__ */
