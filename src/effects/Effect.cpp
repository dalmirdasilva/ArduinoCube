/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__
#define __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ 1

#include <Effect.h>
#include <Cube.h>
#include <Arduino.h>

Effect::Effect(Cube *cube) : cube(cube) {
}

void Effect::run() {
}

void Effect::sendVoxel(Point *p, Direction dir, unsigned int wait) {
  Voxel origin, current;
  char *dim, inc = 1;
  cube->readVoxel(p, &origin);
  switch (dir) {
    case UP:
      inc = -1;
    case DOWN:
      dim = (char*)&(p->z);
      break;
    case FRONT:
      inc = -1;
    case BACK:
      dim = (char*)&(p->y);
      break;
    case RIGHT:
      inc = -1;
    case LEFT:
      dim = (char*)&(p->x);
      break;
  }
  for (; (inc > 0) ? *dim < Cube::SIZE : *dim >= 0; *dim += inc) {
    cube->readVoxel(p, &current);
    cube->writeVoxel(p, origin);
    delay(wait);
    cube->writeVoxel(p, current);
  }
}


#endif /* __ARDUINO_CUBE_EFFECTS_EFFECT_CPP__ */