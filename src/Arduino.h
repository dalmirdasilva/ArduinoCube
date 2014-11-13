/**
 */

#ifndef __ARDUINO_CUBE_ARDUINO_H__
#define __ARDUINO_CUBE_ARDUINO_H__ 1

extern "C" {
  #include "stdlib.h"
}

void randomSeed(unsigned int seed) {
  if (seed != 0) {
    srandom(seed);
  }
}

long random(long to) {
  if (to == 0) {
    return 0;
  }
  return random() % to;
}

long random(long from, long to) {
  if (from >= to) {
    return from;
  }
  long diff = to - from;
  return random(diff) + from;
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

long analogRead(unsigned char port) {
  return 0;
}

void delay(long millis) {
}

#endif /* __ARDUINO_CUBE_ARDUINO_H__ */