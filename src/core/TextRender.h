/**
 * Arduino Cube Library
 * 
 * TextRender.h
 * 
 * The functions to draw text in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_CUBE_TEXT_RENDER_H__
#define __ARDUINO_CUBE_TEXT_RENDER_H__ 1

#include <BitmapFont.h>
#include <Cube.h>
#include <Util.h>

class TextRender {

  /**
   * The cube.
   */
  Cube *cube;

  /**
   * The used font.
   */
  BitmapFont *font;

public:

  /**
   * Public constructor.
   *
   * @param cube                  The cube instance
   * @param font                  The font to be used.
   */
  TextRender(Cube *cube, BitmapFont *font);

  /**
   * Write a char on the cube
   *
   * @param p                         3D point
   * @param axis                      Axis to print
   * @param c                         The char.
   * @param size                      The size.
   */
  void printChar(Point *p, Orientation orientation, unsigned char depth, const char c);
};

#endif /* __SDCC_CUBE_TEXT_RENDER_H__ */
