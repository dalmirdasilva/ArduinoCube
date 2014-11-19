/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__
#define __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__ 1

#include <Effect.h>
#include <Cube.h>

class UpDown : public Effect {

  typedef struct {
    unsigned char position : 4;
    unsigned char destination : 4;
  } Location;

  Location locations[Cube::BYTE_SIZE];

public:

  typedef struct {
    unsigned char iterations;
  } UpDownParameters;

  UpDownParameters *parameters;

  UpDown(Cube *cube, UpDownParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__ */
typedef struct {
  unsigned char x : 4;
  unsigned char y : 4;
} A;

int main() {
  A a = {};
  a.x++;
  a.y++;
  return a.x + a.y;
}

typedef struct {
  unsigned char position : 4;
  unsigned char destination : 4;
} Location;

Location locations[Cube::BYTE_SIZE];

positions[i] = parameters->initialPosition;

void UpDown::run() {
  Location locations[Cube::BYTE_SIZE];
  unsigned char i, y, move;
  randomSeed(analogRead(0));
  for (i = 0; i < Cube::BYTE_SIZE; i++) {
    locations[i].destination = random(Cube::SIZE);
  }
  for (i = 0; i < Cube::SIZE; i++) {
    move(&locations[0]);
    draw(&locations[0], parameters->axis);
    delay(parameters->delay);
  }
}

void UpDown::draw(Location *locations) {
  unsigned char i, j, p;
  cube->useBackBuffer(true);
  cube->clear();
  for (i = 0; i < Cube::SIZE; i++) {
    for (j = 0; j < Cube::SIZE; j++) {
      p = locations[(i * Cube::SIZE) + j].position;
      switch(axis) {
        case AXIS_Z:
          cube->writeVoxel(i, j, p, State::ON);
        case AXIS_Y:
          cube->turnOnVoxel(i, p, j, State::ON);
        case AXIS_X:
          cube->turnOnVoxel(p, j, i, State::ON);
      }
    }
  }
  cube->swapBuffers();
  cube->useBackBuffer(false);
}

void UpDown::move() {
  unsigned char i;
  for (i = 0; i < Cube::BYTE_SIZE; i++) {
    Location location = locations + i;
    if (location[i].position < location[i].destination) {
      location[i].position++;
    }
    if (location[i].position > location[i].destination) {
      location[i].position--;
    }
  }
}
