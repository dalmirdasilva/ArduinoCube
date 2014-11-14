/**
 */

#ifndef __ARDUINO_CUBE_EFFECT_TEST_H__
#define __ARDUINO_CUBE_EFFECT_TEST_H__ 1

#include <Cube.h>
#include <Blink.h>
#include <Rain.h>

class EffectTest {
  
public:

  Cube *cube;
  
  EffectTest(Cube *cube);

  void run();

  void rainTest();

  void blinkTest();
};

#endif /* __ARDUINO_CUBE_EFFECT_TEST_H__ */
