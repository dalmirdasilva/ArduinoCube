/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_RAIN_CPP__
#define __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ 1

#include <Rain.h>
#include <Arduino.h>

Rain::Rain(Drawer *drawer) : Effect(drawer) {
  minDrops = 0;
  maxDrops = Cube::BYTE_SIZE - Cube::SIZE;
}
  
void Rain::run(void *parameters) {
  unsigned char k, x, y, n;
  unsigned int i;
  Point p = {0, 0, Cube::SIZE - 1};
  RainParameters *params = (RainParameters *) parameters;
  minDrops = params->intensity & 0x1f;
  for (i = 0; i < params->iterations; i++) {
    randomSeed(analogRead(0));
    n = random(minDrops, maxDrops);
    for (k = 0; k < n; k++) {
      p.x = random(0, Cube::SIZE);
      p.y = random(0, Cube::SIZE);
      drawer->turnOnVoxel(&p);
    }
    delay(params->delay);
    drawer->shiftOnZ(Drawer::DOWN);
  }
}
  
#endif /* __ARDUINO_CUBE_EFFECTS_RAIN_CPP__ */
