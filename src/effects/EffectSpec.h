/**
 */

#ifndef __ARDUINO_CUBE_EFFECT_TEST_H__
#define __ARDUINO_CUBE_EFFECT_TEST_H__ 1

#include <Cube.h>

class EffectSpec {
  
public:

  Cube *cube;
  
  EffectSpec(Cube *cube);

  unsigned int run();

  unsigned int selfSpec();

  unsigned int rainSpec();

  unsigned int blinkSpec();

  unsigned int boingBoingSpec();

  unsigned int boxShrinkGrowSpec();

  unsigned int boxWoopWoopSpec();

  unsigned int flowingBoxSpec();

  unsigned int gameOfLifeSpec();

  unsigned int randomSparkleSpec();

  unsigned int ripplesSpec();

  unsigned int stairsSpec();

  unsigned int suspendSpec();

  unsigned int upDownSpec();

  unsigned int wormSqueezeSpec();

  unsigned int turnOnRandomlySpec();
};

#endif /* __ARDUINO_CUBE_EFFECT_TEST_H__ */