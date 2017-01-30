/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BLINK_CPP__
#define __ARDUINO_CUBE_EFFECTS_BLINK_CPP__ 1

#include <Blink.h>
#include <Arduino.h>
#include <Point.h>

Blink::Blink(Cube *cube, unsigned int iterations, unsigned int iterationDelay)
        : Effect(cube, iterations, iterationDelay) {
}

bool Blink::iterate() {
    for (unsigned char step = 0; step < 2; step++) {
        unsigned int stepDelay = iterationDelay;
        while (stepDelay > 0) {
            cube->clear();
            delay((step == 0) ? stepDelay : ((iterationDelay + 1) - stepDelay));
            cube->fill();
            delay(100);
            stepDelay -= (15 + (1000 / (stepDelay / 10)));
        }
        if (step == 0) {
            delay(3000);
        }
    }
    return true;
}

#endif /* __ARDUINO_CUBE_EFFECTS_BLINK_CPP__ */
