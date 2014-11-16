/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__
#define __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__ 1

#include <Effect.h>
#include <Cube.h>

class RandomSparkle : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } RandomSparkleParameters;

  RandomSparkleParameters *parameters;

  RandomSparkle(Cube *cube, RandomSparkleParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__ */
