/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_CPP__
#define __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ 1

#include <Rain.h>
#include <Arduino.h>

Rain::Rain(Cube *cube, RainParameters *parameters) : Effect(cube), parameters(parameters) {
}
  
void Rain::run() {
  unsigned char k, x, y, n;
  unsigned int i;
  Point p = {0, 0, Cube::SIZE - 1};
  for (i = 0; i < parameters->iterations; i++) {
    randomSeed(analogRead(0));
    n = random(parameters->minDrops, parameters->maxDrops);
    for (k = 0; k < n; k++) {
      p.x = random(0, Cube::SIZE);
      p.y = random(0, Cube::SIZE);
      cube->turnOnVoxel(&p);
    }
    delay(parameters->delay);
    cube->shiftOnZ(Cube::DOWN);
    cube->turnOffPlaneZ(0);
  }
}
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ */
