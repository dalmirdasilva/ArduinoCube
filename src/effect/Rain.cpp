/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_CPP__
#define __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ 1

#include <Rain.h>
#include <Arduino.h>
#include <Point.h>

Rain::Rain(Cube *cube, RainSettings *settings) : Effect(cube), settings(settings) {
}
  
void Rain::run(unsigned int iterations) {
  unsigned char k, n;
  unsigned int iteration;
  Point p = Point(0, 0, Cube::SIZE - 1);
  for (iteration = 0; iteration < iterations; iteration++) {
    n = random(settings->minDrops, settings->maxDrops);
    for (k = 0; k < n; k++) {
      p.x = random(0, Cube::SIZE);
      p.y = random(0, Cube::SIZE);
      cube->turnVoxelOn(&p);
    }
    delay(settings->delay);
    cube->shiftOnZ(DOWN);
    cube->turnPlaneZOff(Cube::SIZE - 1);
  }
}
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ */
