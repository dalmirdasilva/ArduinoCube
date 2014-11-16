/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_BLINK_CPP__
#define __ARDUINO_CUBE_EFFECTS_BLINK_CPP__ 1

#include <Blink.h>
#include <Arduino.h>
#include <Point.h>

Blink::Blink(Cube *cube, BlinkParameters *parameters) : Effect(cube), parameters(parameters) {
}
  
void Blink::run() {
  for (int it = 0; it < parameters->iterations; it++) {
    executeBlink();
  }
}

void Blink::executeBlink() {
  int wait;
  for (unsigned char step = 0; step < 2; step++) {
    wait = 750;
    while (wait > 0) {
      cube->clear();
      delay((step == 0) ? wait : (751 - wait));
      cube->fill();
      delay(100);
      wait -= (15 + (1000 / (wait / 10)));
    }
    if (step == 0) {
      delay(3000);
    }
  }
}
#endif /* __ARDUINO_CUBE_EFFECTS_BLINK_CPP__ */
