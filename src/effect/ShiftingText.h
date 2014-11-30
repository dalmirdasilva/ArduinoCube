/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__
#define __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__ 1

#include <Effect.h>
#include <Cube.h>

class ShiftingText : public Effect {

public:

  typedef struct {

  } ShiftingTextSettings;

  ShiftingTextSettings *settings;

  ShiftingText(Cube *cube, ShiftingTextSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__ */
