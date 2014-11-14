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
  int i, r;
  cube->clear();
  for (r = 0; r < 4; r++) {
    i = 750;
    while (i > 0) {
      cube->clear();
      delay(i);
      cube->fill();
      delay(100);
      i = i - (15 + (1000 / (i / 10)));
    }
    delay(3000);
    i = 750;
    while (i > 0) {
      cube->clear();
      delay(751 - i);
      cube->fill();
      delay(100);
      i = i - (15 + (1000 / (i / 10)));
    }
  }
}
  
#endif /* __ARDUINO_CUBE_EFFECTS_BLINK_CPP__ */
