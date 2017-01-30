/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_TEXT_RENDER_CPP__
#define __ARDUINO_CUBE_EFFECTS_TEXT_RENDER_CPP__ 1

#include <TextRender.h>
#include <stdio.h>

TextRender::TextRender(Cube *cube, BitmapFont *font)
        : cube(cube), font(font) {
}

void TextRender::printChar(Point *p, TextOrientation orientation, unsigned char depth, const char c) {
    Voxel v;
    unsigned char w, h, d, column, width, height, *x, *y, *z, glyphBuffer[font->getGlyphLength()];
    x = y = z = 0;
    width = font->getCharacterWidth();
    height = font->getCharacterHeight();
    font->readGlyphData(glyphBuffer, c);
    adjustCoordinates(p, orientation, &x, &y, &z);
    for (w = 0; w < width; w++) {
        column = glyphBuffer[w];
        for (h = 0; h < height; h++) {
            if ((column & (0x01 << h)) != 0) {
                v.state = ON;
            } else {
                v.state = OFF;
            }
            for (d = 0; d < depth; d++) {
                cube->writeVoxel(*x + w, *y + h, *z + d, v.state);
            }
        }
    }
}

void TextRender::adjustCoordinates(Point *p, TextOrientation orientation, unsigned char **x, unsigned char **y, unsigned char **z) {
    switch (orientation) {
    case XYZ:
        *x = &(p->x);
        *y = &(p->y);
        *z = &(p->z);
        break;
    case XZY:
        *x = &(p->x);
        *y = &(p->z);
        *z = &(p->y);
        break;
    case YZX:
        *x = &(p->y);
        *y = &(p->z);
        *z = &(p->x);
        break;
    case YXZ:
        *x = &(p->y);
        *y = &(p->x);
        *z = &(p->z);
        break;
    case ZYX:
        *x = &(p->z);
        *y = &(p->y);
        *z = &(p->x);
        break;
    case ZXY:
        *x = &(p->z);
        *y = &(p->x);
        *z = &(p->y);
        break;
    }
}

#endif /* __ARDUINO_CUBE_TEXT_RENDER_CPP__ */
