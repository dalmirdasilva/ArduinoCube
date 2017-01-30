/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__
#define __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__ 1

#include <Effect.h>
#include <Cube.h>
#include <TextRender.h>

class ShiftingText: public Effect {

public:

    typedef struct {
        TextRender *render;
        const char *text;
        unsigned char charDepth;
        unsigned char orientation;
        Point *point;
    } ShiftingTextSettings;

    ShiftingTextSettings *settings;

    ShiftingText(Cube *cube, unsigned int iterations, unsigned int iterationDelay, ShiftingTextSettings *settings);

    virtual bool interate();

    void displayCharacter(const char c);

    void shiftCharacter();
};

#endif /* __ARDUINO_CUBE_EFFECTS_SHIFTING_TEXT_H__ */
