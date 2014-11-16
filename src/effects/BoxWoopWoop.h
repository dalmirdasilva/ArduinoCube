/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_H__
#define __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoxWoopWoop : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } BoxWoopWoopParameters;

  BoxWoopWoopParameters *parameters;

  BoxWoopWoop(Cube *cube, BoxWoopWoopParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_WOOP_WOOP_H__ */
