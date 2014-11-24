/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_STAIRS_H__
#define __ARDUINO_CUBE_EFFECTS_STAIRS_H__ 1

#include <Effect.h>
#include <Cube.h>

class Stairs : public Effect {

public:

  typedef struct {

  } StairsSettings;

  StairsSettings *settings;

  Stairs(Cube *cube, StairsSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_STAIRS_H__ */
