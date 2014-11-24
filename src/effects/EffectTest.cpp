#include <EffectTest.h>
#include <Asserter.h>
#include <Util.h>
#include <Blink.h>
#include <Rain.h>
#include <UpDown.h>
#include <GameOfLife.h>
#include <stdio.h>
#include <string.h>

#define AT(b, y, z) *(b + ((((z) * CUBE_SIZE) + (y))))

EffectTest::EffectTest(Cube *cube) : cube(cube) {
}

unsigned int EffectTest::run() {
  unsigned int errorCount = 0;
  errorCount += selfTest();
  errorCount += rainTest();
  errorCount +git add = blinkTest();
  errorCount += boingBoingTest();
  errorCount += boxShrinkGrowTest();
  errorCount += boxWoopWoopTest();
  errorCount += flowingBoxTest();
  errorCount += gameOfLifeTest();
  errorCount += randomSparkleTest();
  errorCount += ripplesTest();
  errorCount += stairsTest();
  errorCount += suspendTest();
  errorCount += upDownTest();
  errorCount += wormSqueezeTest();
  return errorCount;
}

unsigned int EffectTest::selfTest() {
  unsigned int errorCount = 0;
  Point p = {0, 0, 0};
  Effect effect = Effect(cube);
  cube->clear();
  effect.sendVoxel(&p, FRONT, 0);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "selfTest: It should not break.");
  return errorCount;
}

unsigned int EffectTest::blinkTest() {
  unsigned int errorCount = 0;
  Blink::BlinkSettings effectSettings = {750};
  Blink effect = Blink(cube, &effectSettings);
  effect.run(1);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "blinkTest: It should not break, we cannot test it.");
  return errorCount;
}

unsigned int EffectTest::rainTest() {
  unsigned int errorCount = 0;
  unsigned char i, aux = 0;
  Rain::RainSettings effectSettings = {1, 1, 200};
  Rain effect = Rain(cube, &effectSettings);
  cube->clear();
  effect.run(40);
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, Cube::SIZE - 1);
  }
  errorCount += (unsigned int) Asserter::assertEqual(aux, 0, "rainTest: It should clear the top plane.");
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, 0);
  }
  errorCount += (unsigned int) Asserter::assertNotEqual(aux, 0, "rainTest: It should have turned on some LEDs.");
  return errorCount;
}

unsigned int EffectTest::boingBoingTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::boxShrinkGrowTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::boxWoopWoopTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::flowingBoxTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::gameOfLifeTest() {
  unsigned int errorCount = 0;
  GameOfLife::GameOfLifeSettings effectSettings = {0, 8};
  GameOfLife effect = GameOfLife(cube, &effectSettings);
  effect.run(1);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "GameOfLife: It should not break, we cannot test it.");
  return errorCount;
}

unsigned int EffectTest::randomSparkleTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::ripplesTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::stairsTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::suspendTest() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectTest::upDownTest() {
  unsigned int errorCount = 0;
  UpDown::UpDownSettings effectSettings = {Axis::AXIS_X, 3, 0};
  UpDown effect = UpDown(cube, &effectSettings);
  effect.run(1);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "upDownTest: It should not break, we cannot test it.");
  return errorCount;
}

unsigned int EffectTest::wormSqueezeTest() {
  unsigned int errorCount = 0;
  return errorCount;
}