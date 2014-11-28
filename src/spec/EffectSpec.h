/**
 */

#ifndef __ARDUINO_CUBE_EFFECT_TEST_H__
#define __ARDUINO_CUBE_EFFECT_TEST_H__ 1

#include <Cube.h>

class EffectSpec {
  
public:

  Cube *cube;
  
  EffectSpec(Cube *cube);

  void run();

  void selfSpec();

  void rainSpec();

  void blinkSpec();

  void boingBoingSpec();

  void boxShrinkGrowSpec();

  void boxWoopWoopSpec();

  void flowingBoxSpec();

  void gameOfLifeSpec();

  void movingBoxShrinkGrowSpec();

  void randomSparkleSpec();

  void ripplesSpec();

  void stairsSpec();

  void suspendSpec();

  void upDownSpec();

  void wormSqueezeSpec();

  void turnOnRandomlySpec();
};

#endif /* __ARDUINO_CUBE_EFFECT_TEST_H__ */