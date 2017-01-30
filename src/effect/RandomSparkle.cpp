/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__
#define __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ 1

#include <RandomSparkle.h>

RandomSparkle::RandomSparkle(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : Effect(cube, iterations, iterationDelay) {
}

bool RandomSparkle::interate() {
    return false;
}

#endif /* __ARDUINO_CUBE_EFFECTS_RANDOM_SPARKLE_CPP__ */
