/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__
#define __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__ 1

#include <Effect.h>
#include <Cube.h>
#include <TextRender.h>

class ShiftingText : public Effect {

public:

  typedef struct {
    TextRender *render;
    const char *text;
    unsigned char charDepth;
    unsigned char orientation;
    unsigned int delay;
  } ShiftingTextSettings;

  ShiftingTextSettings *settings;

  ShiftingText(Cube *cube, ShiftingTextSettings *settings);

  virtual void run(unsigned int iterations);

  void displayCharacter(const char c);
  
  void shiftCharacter();
};

#endif /* __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__ */
