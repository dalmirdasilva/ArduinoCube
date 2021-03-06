#include <Arduino.h>

unsigned char arduinoCounter;

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

long map(long x, long inMin, long inMax, long outMin, long outMax) {
  return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

long analogRead(unsigned char port) {
  return time(NULL) + (port != 0) ? arduinoCounter++ : 0;
}

void delay(long millis) {
  usleep(millis * 1000);
}

void interrupts() {
}

void noInterrupts() {
}
