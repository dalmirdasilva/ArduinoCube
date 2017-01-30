/**
 */

#ifndef __ARDUINO_CUBE_UTIL_CPP__
#define __ARDUINO_CUBE_UTIL_CPP__ 1

#include <Util.h>

unsigned char Util::rotatingShift(unsigned char v, unsigned char isLeft) {
    if (isLeft) {
        return (v << 1) | (v >> 7 & 0x01);
    } else {
        return (v >> 1) | (v << 7 & 0x80);
    }
}

void Util::flipNibble(unsigned char *p) {
    unsigned char flop = 0x00;
    flop |= (0x01 & (*p >> 3));
    flop |= (0x02 & (*p >> 1));
    flop |= (0x04 & (*p << 1));
    flop |= (0x08 & (*p << 3));
    *p = flop;
}

void Util::flipByte(unsigned char *p) {
    unsigned char flop = 0x00;
    flop = (flop & 0xfe) | (0x01 & (*p >> 7));
    flop = (flop & 0xfd) | (0x02 & (*p >> 5));
    flop = (flop & 0xfb) | (0x04 & (*p >> 3));
    flop = (flop & 0xf7) | (0x08 & (*p >> 1));
    flop = (flop & 0xef) | (0x10 & (*p << 1));
    flop = (flop & 0xdf) | (0x20 & (*p << 3));
    flop = (flop & 0xbf) | (0x40 & (*p << 5));
    flop = (flop & 0x7f) | (0x80 & (*p << 7));
    *p = flop;
}

void Util::orderArgs(unsigned char *a, unsigned char *b) {
    if (*a > *b) {
        swapArgs(a, b);
    }
}

void Util::swapArgs(unsigned char *a, unsigned char *b) {
    unsigned char _ = *b;
    *b = *a;
    *a = _;
}

#endif /* __ARDUINO_CUBE_UTIL_CPP__ */

