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
  Axis axis;
  unsigned char initialPosition;

public:

  UpDown(Cube *cube, unsigned int iterations, unsigned int iterationDelay, Axis axis, unsigned char initialPosition);

  virtual void run();

  /**
   * Draws current position to the cube.
   */
  void draw();

  /**
   * Move one step the LEDs to the destination.
   */
  void move();
};

#endif /* __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__ */

