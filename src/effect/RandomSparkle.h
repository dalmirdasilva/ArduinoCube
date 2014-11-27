/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__
#define __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__ 1

#include <Effect.h>
#include <Cube.h>

class RandomSparkle : public Effect {

public:

  typedef struct {

  } RandomSparkleSettings;

  RandomSparkleSettings *settings;

  RandomSparkle(Cube *cube, RandomSparkleSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__ */
