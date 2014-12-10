/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__
#define __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__ 1

#include <ShiftingText.h>
#include <TextRender.h>
#include <Arduino.h>

ShiftingText::ShiftingText(Cube *cube, unsigned int iterations, unsigned int iterationDelay, ShiftingTextSettings *settings) :
  Effect(cube, iterations, iterationDelay), settings(settings) {
}

void ShiftingText::run() {
  unsigned int iteration;
  const char *c;
  for (iteration = 0; iteration < iterations; iteration++) {
    c = settings->text;
    while(*c != '\0') {
      displayCharacter(*c);
      shiftCharacter();
      c++;
    }
  }
}

void ShiftingText::displayCharacter(const char c) {
  Point p = Point(0, 0, 0);
  cube->clear();
  settings->render->printChar(&p, (TextRender::TextOrientation) settings->orientation, settings->charDepth, c);
}

void ShiftingText::shiftCharacter() {
  unsigned char i;
  for (i = 1; i < Cube::SIZE; i++) {
    switch (settings->orientation) {
      case TextRender::ZYX:
        cube->shiftOnX(RIGHT);
      break;
      case TextRender::YZX:
        cube->shiftOnX(LEFT);
      break;
      case TextRender::XZY:
        cube->shiftOnY(FRONT);
      break;
      case TextRender::ZXY:
        cube->shiftOnY(BACK);
      break;
      case TextRender::XYZ:
        cube->shiftOnZ(DOWN);
      break;
      case TextRender::YXZ:
        cube->shiftOnZ(UP);
      break;
    }
    delay(iterationDelay / 8);
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__ */
