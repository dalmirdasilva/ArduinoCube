/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_CPP__
#define __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_CPP__ 1

#include <TurnOnRandomly.h>
#include <Arduino.h>
#include <Point.h>

TurnOnRandomly::TurnOnRandomly(Cube *cube, TurnOnRandomlySettings *settings) : Effect(cube), settings(settings) {
}
  
void TurnOnRandomly::run(unsigned int iterations) {
  unsigned int iteration;
  unsigned char i;
  Point p;
  for (iteration = 0; iteration < iterations; iteration++) {
    cube->clear();
    for (i = 0; i < settings->maxOnVoxels; i++) {
      p.randomizePoint(Cube::SIZE);
      cube->turnVoxelOn(&p);
    }
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_TURN_ON_RANDOMLY_CPP__ */