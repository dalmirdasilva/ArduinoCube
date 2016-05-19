/**
 */
 
#ifndef __ARDUINO_CUBE_UTIL_H__
#define __ARDUINO_CUBE_UTIL_H__ 1

#include <Point.h>
#include <Cube.h>
#include <stdio.h>

class Util {

public:

  /**
   * Shift the byte rotating it
   */
  static unsigned int rotatingShift(unsigned int v, unsigned int isLeft);

  /**
   * Flip a byte
   */
  static void flipByte(unsigned int *p);

  /**
   * Order the args, lower first
   */
  static void orderArgs(unsigned int *a, unsigned int *b);

  /**
   * Swap args
   */
  static void swapArgs(unsigned int *a, unsigned int *b);

  /**
   * Returns a byte with a row of 1's drawn in it.
   * byteLine(2, 5) gives 0b00111100
   */
  static unsigned int byteLine(unsigned int start, unsigned int end) {
    return ((0xffffffff << start) & ~(0xffffffff << (end + 1)));
  }

  /**
   * Sets the ON bit on the mask
   */
  static void set(unsigned int *p, unsigned int mask) {
    *p |= mask;
  }

  /**
   * Clears the ON bit on the mask
   */
  static void clr(unsigned int *p, unsigned int mask) {
    *p &= ~mask;
  }
};

#endif /* __ARDUINO_CUBE_UTIL_H__ */
