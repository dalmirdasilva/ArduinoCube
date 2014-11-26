/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__
#define __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__ 1

#include <Stairs.h>

Stairs::Stairs(Cube *cube, StairsSettings *settings) : Effect(cube), settings(settings) {
}

void Stairs::run(unsigned int iterations) {
  unsigned int iteration;
  for (iteration = 0; iteration < iterations; iteration++) {

  }
}

int effect_telcstairs_do(int x, int val, int delay) {
    int y, z;
    for (y = 0, z = x; y <= z; y++, x--) {
        if (x < CUBE_SIZE && y < CUBE_SIZE) {
            cube[x % CUBE_SIZE][y % CUBE_SIZE] = val;
        }
    }
    delay_ms(delay);
    return z;
}

void effect_telcstairs(int invert, int delay, int val) {
    int x;
    if (invert) {
        for (x = CUBE_SIZE * 2; x >= 0; x--) {
            x = effect_telcstairs_do(x, val, delay);
        }
    } else {
        for (x = 0; x < CUBE_SIZE * 2; x++) {
            x = effect_telcstairs_do(x, val, delay);
        }
    }
}

#endif /* __ARDUINO_CUBE_EFFECTS_STAIRS_CPP__ */
