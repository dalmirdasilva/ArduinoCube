#include <EffectTest.h>
#include <Asserter.h>
#include <Util.h>
#include <Blink.h>
#include <Rain.h>
#include <UpDown.h>
#include <stdio.h>
#include <string.h>

#define AT(b, y, z) *(b + ((((z) * CUBE_SIZE) + (y))))

EffectTest::EffectTest(Cube *cube) : cube(cube) {
}

void EffectTest::run() {
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

void EffectTest::rainTest() {
  unsigned char i, aux = 0;
  Rain::RainParameters rp = {40, 1, 1, 200};
  Rain r = Rain(cube, &rp);
  cube->clear();
  r.run();
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, Cube::SIZE - 1);
  }
  Asserter::assertEqual(aux, 0, "rainTest: It should clear the top plane.");
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, 0);
  }
  Asserter::assertNotEqual(aux, 0, "rainTest: It should have turned on some LEDs.");
}

void EffectTest::blinkTest() {
  Blink::BlinkParameters bp = {0};
  Blink b = Blink(cube, &bp);
  b.run();
  Asserter::assertEqual(0, 0, "blinkTest: It should not break, we cannot test it.");
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
  UpDown::UpDownParameters up = {0x03, 0x01, 0x00, AXIS_X};
  UpDown u = UpDown(cube, &up);
  u.run();
  Asserter::assertEqual(0, 0, "upDownTest: It should not break, we cannot test it.");

}

void EffectTest::wormSqueezeTest() {
}