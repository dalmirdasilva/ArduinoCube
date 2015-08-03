/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__
#define __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__ 1

#include <Effect.h>
#include <Cube.h>

class RandomSparkle : public Effect {
public:

  RandomSparkle(Cube *cube, unsigned int iterations, unsigned int iterationDelay);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_H__ */
