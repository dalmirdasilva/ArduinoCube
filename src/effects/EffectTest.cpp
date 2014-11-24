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

void EffectTest::run() {
  selfTest();
  rainTest();
  blinkTest();
  boingBoingTest();
  boxShrinkGrowTest();
  boxWoopWoopTest();
  flowingBoxTest();
  gameOfLifeTest();
  randomSparkleTest();
  ripplesTest();
  stairsTest();
  suspendTest();
  upDownTest();
  wormSqueezeTest();
}

void EffectTest::selfTest() {
  Point p = {0, 0, 0};
  Effect effect = Effect(cube);
  cube->clear();
  effect.sendVoxel(AXIS_Y, FRONT, &p, 0);
  Asserter::assertEqual(0, 0, "selfTest: It should not break.");
}

void EffectTest::blinkTest() {
  Blink::BlinkSettings effectSettings = {750};
  Blink effect = Blink(cube, &effectSettings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "blinkTest: It should not break, we cannot test it.");
}

void EffectTest::rainTest() {
  unsigned char i, aux = 0;
  Rain::RainSettings effectSettings = {1, 1, 200};
  Rain effect = Rain(cube, &effectSettings);
  cube->clear();
  effect.run(40);
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, Cube::SIZE - 1);
  }
  Asserter::assertEqual(aux, 0, "rainTest: It should clear the top plane.");
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, 0);
  }
  Asserter::assertNotEqual(aux, 0, "rainTest: It should have turned on some LEDs.");
}

void EffectTest::boingBoingTest() {
}

void EffectTest::boxShrinkGrowTest() {
}

void EffectTest::boxWoopWoopTest() {
}

void EffectTest::flowingBoxTest() {
}

void EffectTest::gameOfLifeTest() {
  GameOfLife::GameOfLifeSettings effectSettings = {0, 8};
  GameOfLife effect = GameOfLife(cube, &effectSettings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "GameOfLife: It should not break, we cannot test it.");
}

void EffectTest::randomSparkleTest() {
}

void EffectTest::ripplesTest() {
}

void EffectTest::stairsTest() {
}

void EffectTest::suspendTest() {
}

void EffectTest::upDownTest() {
  UpDown::UpDownSettings effectSettings = {3, 0, AXIS_X};
  UpDown effect = UpDown(cube, &effectSettings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "upDownTest: It should not break, we cannot test it.");
}

void EffectTest::wormSqueezeTest() {
}