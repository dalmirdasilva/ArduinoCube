/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__
#define __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__ 1

#include <ShiftingText.h>
#include <Dumper.h>

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
  settings->render->printChar(&p, TextRender::XYZ, settings->charDepth, c);
  Dumper::dumpCube(cube);
}

void ShiftingText::shiftCharacter() {
}

#endif /* __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__ */
