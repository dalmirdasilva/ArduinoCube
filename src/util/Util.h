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
    static unsigned char rotatingShift(unsigned char v, unsigned char isLeft);

    /**
     * Flip a byte
     */
    static void flipByte(unsigned char *p);

    /**
     * Flip low nibble
     */
    static void flipNibble(unsigned char *p);

    /**
     * Order the args, lower first
     */
    static void orderArgs(unsigned char *a, unsigned char *b);

    /**
     * Swap args
     */
    static void swapArgs(unsigned char *a, unsigned char *b);

    /**
     * Returns a byte with a row of 1's drawn in it.
     * byteLine(2, 5) gives 0b00111100
     */
    static inline unsigned char byteLine(unsigned char start, unsigned char end) {
        return ((0xff << start) & ~(0xff << (end + 1)));
    }

    /**
     * Sets the ON bit on the mask
     */
    static inline void set(unsigned char *p, unsigned char mask) {
        *p |= mask;
    }

    /**
     * Clears the ON bit on the mask
     */
    static inline void clr(unsigned char *p, unsigned char mask) {
        *p &= ~mask;
    }
};

#endif /* __ARDUINO_CUBE_UTIL_H__ */
