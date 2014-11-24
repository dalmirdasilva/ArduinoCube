/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ 1

#include <Effect.h>
#include <Cube.h>
#include <Arduino.h>

Effect::Effect(Cube *cube) : cube(cube) {
}

void Effect::run(unsigned int iterations) {
}

void Effect::sendVoxel(Axis axis, Direction direction, Point *origin, unsigned int wait) {
  char *dimension;
  char increment = 1;
  switch (axis) {
    case AXIS_X:
      dimension = (char*)&(origin->x);
      break;
    case AXIS_Y:
      dimension = (char*)&(origin->y);
      break;
    case AXIS_Z:
      dimension = (char*)&(origin->z);
      break;
  }
  if (direction == UP || direction == RIGHT || direction == FRONT) {
    increment = -1;
  }
  for (; (increment > 0) ? *dimension < Cube::SIZE : *dimension >= 0; *dimension += increment) {
    cube->turnVoxelOn(origin);
    delay(wait);
    cube->turnVoxelOff(origin);
  }
}

void Effect::randomizePoint(Point *p) {
  p->x = random(Cube::SIZE);
  p->y = random(Cube::SIZE);
  p->z = random(Cube::SIZE);
}

#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ */