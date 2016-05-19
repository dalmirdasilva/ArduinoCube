/**
 */
 
#ifndef __ARDUINO_CUBE_UTIL_CPP__
#define __ARDUINO_CUBE_UTIL_CPP__ 1

#include <Util.h>

unsigned int Util::rotatingShift(unsigned int v, unsigned int isLeft) {
  if (isLeft) {
    return (v << 1) | (v >> 7 & 0x01);
  } else {
    return (v >> 1) | (v << 7 & 0x80);
  }
}

void Util::flipByte(unsigned int *p) {
  int mask = (1 << 32) - 1;
  *p = ~(*p) & mask;
}

void Util::orderArgs(unsigned int *a, unsigned int *b) {
  if (*a > *b) {
    swapArgs(a, b);
  }
}

void Util::swapArgs(unsigned int *a, unsigned int *b) {
  unsigned char _ = *b;
  *b = *a;
  *a = _;
}

#endif /* __ARDUINO_CUBE_UTIL_CPP__ */

