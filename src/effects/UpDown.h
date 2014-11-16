/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__
#define __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__ 1

#include <Effect.h>
#include <Cube.h>

class UpDown : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } UpDownParameters;

  UpDownParameters *parameters;

  UpDown(Cube *cube, UpDownParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_UP_DOWN_H__ */
