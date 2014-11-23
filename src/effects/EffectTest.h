/**
 */

#ifndef __ARDUINO_CUBE_EFFECT_TEST_H__
#define __ARDUINO_CUBE_EFFECT_TEST_H__ 1

#include <Cube.h>

class EffectTest {
  
public:

  Cube *cube;
  
  EffectTest(Cube *cube);

  void run();

  void selfTest();

  void rainTest();

  void blinkTest();

  void boingBoingTest();

  void boxShrinkGrowTest();

  void boxWoopWoopTest();

  void flowingBoxTest();

  void gameOfLifeTest();

  void randomSparkleTest();

  void ripplesTest();

  void stairsTest();

  void suspendTest();

  void upDownTest();

  void wormSqueezeTest();
};

#endif /* __ARDUINO_CUBE_EFFECT_TEST_H__ */