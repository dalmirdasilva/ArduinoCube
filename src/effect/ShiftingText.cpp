/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__
#define __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_CPP__ 1

#include <ShiftingText.h>
#include <TextRender.h>
#include <Arduino.h>

ShiftingText::ShiftingText(Cube *cube, unsigned int iterations, unsigned int iterationDelay, ShiftingTextSettings *settings)
        : Effect(cube, iterations, iterationDelay), settings(settings) {
}

bool ShiftingText::interate() {
    const char *c;
    c = settings->text;
    while (*c != '\0') {
        displayCharacter(*c);
        shiftCharacter();
        c++;
    }
    return true;
}

void ShiftingText::displayCharacter(const char c) {
    cube->clear();
    settings->render->printChar(settings->point, (TextRender::TextOrientation) settings->orientation, settings->charDepth, c);
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
