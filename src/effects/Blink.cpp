/**
 */
 
#ifndef __ARDUINO_CUBE_EFFECTS_BLINK_CPP__
#define __ARDUINO_CUBE_EFFECTS_BLINK_CPP__ 1

#include <Blink.h>
#include <Arduino.h>
#include <Point.h>

Blink::Blink(Cube *cube, BlinkSettings *settings) : Effect(cube), settings(settings) {
}
  
void Blink::run(unsigned int iterations) {
  unsigned int iteration;
  unsigned char step;
  int stepDelay;
  for (iteration = 0; iteration < iterations; iteration++) {
    for (step = 0; step < 2; step++) {
      stepDelay = settings->delay;
      while (stepDelay > 0) {
        cube->clear();
        delay((step == 0) ? stepDelay : ((settings->delay + 1) - stepDelay));
        cube->fill();
        delay(100);
        stepDelay -= (15 + (1000 / (stepDelay / 10)));
      }
      if (step == 0) {
        delay(3000);
      }
    }
  }
}

#endif /* __ARDUINO_CUBE_EFFECTS_BLINK_CPP__ */
