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
    unsigned char initialPosition;
    unsigned char iterations;
    unsigned int delay;
    Axis axis;
  } UpDownParameters;

  UpDownParameters *parameters;

  UpDown(Cube *cube, UpDownParameters *parameters);

  virtual void run();

  void draw();

  void move();
};

#endif /* __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__ */

