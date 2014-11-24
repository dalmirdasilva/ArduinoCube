/**
 */

#ifndef __ARDUINO_CUBE_EFFECT_TEST_H__
#define __ARDUINO_CUBE_EFFECT_TEST_H__ 1

#include <Cube.h>

class EffectTest {
  
public:

  Cube *cube;
  
  EffectTest(Cube *cube);

  unsigned int run();

  unsigned int selfTest();

  unsigned int rainTest();

  unsigned int blinkTest();

  unsigned int boingBoingTest();

  unsigned int boxShrinkGrowTest();

  unsigned int boxWoopWoopTest();

  unsigned int flowingBoxTest();

  unsigned int gameOfLifeTest();

  unsigned int randomSparkleTest();

  unsigned int ripplesTest();

  unsigned int stairsTest();

  unsigned int suspendTest();

  unsigned int upDownTest();

  unsigned int wormSqueezeTest();
};

#endif /* __ARDUINO_CUBE_EFFECT_TEST_H__ */