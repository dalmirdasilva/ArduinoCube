/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_TEXT_RENDER_CPP__
#define __ARDUINO_CUBE_EFFECTS_TEXT_RENDER_CPP__ 1

#include <TextRender.h>

TextRender::TextRender(Cube *cube, BitmapFont *font) : cube(cube), font(font) {
}

void TextRender::printChar(Point p, Axis axis, unsigned char depth, const unsigned char c) {
  Voxel v;
  unsigned char w, h, d, column, width, height, *x, *y, *z, glyphBuf[font->getGlyphLength()];
  with = font->getCharacterWidth();
  height =  font->getCharacterHeight();
  font->readGlyphData(glyphBuf, c);
  for (w = 0; w < with; w++) {
    column = glyphBuf[i];
    for (h = 0; h < height; h++) {
      if ((column & (0x01 << j)) != 0) {
        v.state = ON;
      } else {
        v.state = OFF;
      }
      for (d = 0; d < depth; d++) {

      }
    }
  }
}

void TextRender::adjustCoordinates(Point p, Axis axis, unsigned char *x, unsigned char *y, unsigned char *z) {

}

#endif /* __ARDUINO_CUBE_TEXT_RENDER_CPP__ */
