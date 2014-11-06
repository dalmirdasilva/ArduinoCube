/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_CPP__
#define __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ 1

#include <Rain.h>
#include <Arduino.h>

Rain::Rain(Cube *cube, RainParameters *parameters) : Effect(cube), parameters(parameters) {
  minDrops = 0;
  maxDrops = Cube::BYTE_SIZE - Cube::SIZE;
}
  
void Rain::run() {
  unsigned char k, x, y, n;
  unsigned int i;
  Point p = {0, 0, Cube::SIZE - 1};
  minDrops = parameters->intensity & 0x1f;
  for (i = 0; i < parameters->iterations; i++) {
    randomSeed(analogRead(0));
    n = random(minDrops, maxDrops);
    for (k = 0; k < n; k++) {
      p.x = random(0, Cube::SIZE);
      p.y = random(0, Cube::SIZE);
      cube->turnOnVoxel(&p);
    }
    delay(parameters->delay);
    cube->shiftOnZ(Cube::DOWN);
  }
}
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ */
