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
    unsigned int delay;
    unsigned char charDepth;
  } ShiftingTextSettings;

  ShiftingTextSettings *settings;

  ShiftingText(Cube *cube, ShiftingTextSettings *settings);

  virtual void run(unsigned int iterations);

  void displayChar(const char c);
};

#endif /* __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__ */
