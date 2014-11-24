/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__
#define __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__ 1

#include <UpDown.h>
#include <Arduino.h>
#include <Util.h>

UpDown::UpDown(Cube *cube, UpDownSettings *settings) : Effect(cube), settings(settings) {
}

void UpDown::run(unsigned int iterations) {
  unsigned char i;
  unsigned int iteration;
  cube->clear();
  for (i = 0; i < Cube::BYTE_SIZE; i++) {
    locations[i].position = settings->initialPosition;
  }
  for (iteration = 0; iteration < iterations; iteration++) {
    for (i = 0; i < Cube::BYTE_SIZE; i++) {
      locations[i].destination = random(Cube::SIZE);
    }
    for (i = 0; i < Cube::SIZE; i++) {
      move(); draw();
      delay(settings->delay);
    }
  }
}

void UpDown::draw() {
  unsigned char i, j, p;
  cube->useBackBuffer(true);
  cube->clear();
  for (i = 0; i < Cube::SIZE; i++) {
    for (j = 0; j < Cube::SIZE; j++) {
      p = locations[i * Cube::SIZE + j].position;
      switch(settings->axis) {
        case AXIS_Z:
          cube->writeVoxel(i, j, p, State::ON);
          break;
        case AXIS_Y:
          cube->writeVoxel(i, p, j, State::ON);
          break;
        case AXIS_X:
          cube->writeVoxel(p, j, i, State::ON);
          break;
      }
    }
  }
  cube->swapBuffers();
  cube->useBackBuffer(false);
}

void UpDown::move() {
  unsigned char i;
  for (i = 0; i < Cube::BYTE_SIZE; i++) {
    Location *location = &(locations[i]);
    if (location->position < location->destination) {
      location->position++;
    }
    if (location->position > location->destination) {
      location->position--;
    }
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_UP_DOWN_CPP__ */
