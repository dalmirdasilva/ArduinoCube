#include <EffectSpec.h>
#include <Asserter.h>
#include <Util.h>
#include <Blink.h>
#include <Rain.h>
#include <UpDown.h>
#include <GameOfLife.h>
#include <TurnOnRandomly.h>
#include <stdio.h>
#include <string.h>

#define AT(b, y, z) *(b + ((((z) * CUBE_SIZE) + (y))))

EffectSpec::EffectSpec(Cube *cube) : cube(cube) {
}

unsigned int EffectSpec::run() {
  unsigned int errorCount = 0;
  errorCount += selfSpec();
  errorCount += rainSpec();
  errorCount += blinkSpec();
  errorCount += boingBoingSpec();
  errorCount += boxShrinkGrowSpec();
  errorCount += boxWoopWoopSpec();
  errorCount += flowingBoxSpec();
  errorCount += gameOfLifeSpec();
  errorCount += randomSparkleSpec();
  errorCount += ripplesSpec();
  errorCount += stairsSpec();
  errorCount += suspendSpec();
  errorCount += upDownSpec();
  errorCount += wormSqueezeSpec();
  errorCount += turnOnRandomlySpec();
  return errorCount;
}

unsigned int EffectSpec::selfSpec() {
  unsigned int errorCount = 0;
  Point p = Point();
  Effect effect = Effect(cube);
  cube->clear();
  effect.sendVoxel(&p, FRONT, 0);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "selfSpec: It should not break.");
  return errorCount;
}

unsigned int EffectSpec::blinkSpec() {
  unsigned int errorCount = 0;
  Blink::BlinkSettings effectSettings = {750};
  Blink effect = Blink(cube, &effectSettings);
  effect.run(1);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "blinkSpec: It should not break, we cannot test it.");
  return errorCount;
}

unsigned int EffectSpec::rainSpec() {
  unsigned int errorCount = 0;
  unsigned char i, aux = 0;
  Rain::RainSettings effectSettings = {1, 1, 200};
  Rain effect = Rain(cube, &effectSettings);
  cube->clear();
  effect.run(40);
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, Cube::SIZE - 1);
  }
  errorCount += (unsigned int) Asserter::assertEqual(aux, 0, "rainSpec: It should clear the top plane.");
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, 0);
  }
  errorCount += (unsigned int) Asserter::assertNotEqual(aux, 0, "rainSpec: It should have turned on some LEDs.");
  return errorCount;
}

unsigned int EffectSpec::boingBoingSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::boxShrinkGrowSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::boxWoopWoopSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::flowingBoxSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::gameOfLifeSpec() {
  unsigned int errorCount = 0;
  GameOfLife::GameOfLifeSettings effectSettings = {0, 8};
  GameOfLife effect = GameOfLife(cube, &effectSettings);
  effect.run(1);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "GameOfLife: It should not break, we cannot test it.");
  return errorCount;
}

unsigned int EffectSpec::randomSparkleSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::ripplesSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::stairsSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::suspendSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::upDownSpec() {
  unsigned int errorCount = 0;
  UpDown::UpDownSettings effectSettings = {Axis::AXIS_X, 3, 0};
  UpDown effect = UpDown(cube, &effectSettings);
  effect.run(1);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "upDownSpec: It should not break, we cannot test it.");
  return errorCount;
}

unsigned int EffectSpec::wormSqueezeSpec() {
  unsigned int errorCount = 0;
  return errorCount;
}

unsigned int EffectSpec::turnOnRandomlySpec() {
  unsigned int errorCount = 0;
  TurnOnRandomly::TurnOnRandomlySettings effectSettings = {1};
  TurnOnRandomly effect = TurnOnRandomly(cube, &effectSettings);
  effect.run(1);
  errorCount += (unsigned int) Asserter::assertEqual(0, 0, "turnOnRandomlySpec: It should not break, we cannot test it.");
  return errorCount;
}