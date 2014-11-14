/**
 */

#ifndef __ARDUINO_CUBE_ARDUINO_H__
#define __ARDUINO_CUBE_ARDUINO_H__ 1

extern "C" {
  #include <stdlib.h>
  #include <time.h>
  #include <unistd.h>
}

void randomSeed(unsigned int seed);

long random(long to);

long random(long from, long to);

long map(long x, long in_min, long in_max, long out_min, long out_max);

long analogRead(unsigned char port);

void delay(long millis);

#endif /* __ARDUINO_CUBE_ARDUINO_H__ */