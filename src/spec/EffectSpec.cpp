#include <EffectSpec.h>
#include <Asserter.h>
#include <Util.h>
#include <Blink.h>
#include <BoingBoing.h>
#include <BoxShrinkGrow.h>
#include <BoxWoopWoop.h>
#include <FlowingBox.h>
#include <GameOfLife.h>
#include <MovingBoxShrinkGrow.h>
#include <Rain.h>
#include <RandomSparkle.h>
#include <Ripples.h>
#include <Stairs.h>
#include <Suspend.h>
#include <TurnOnRandomly.h>
#include <UpDown.h>
#include <WormSqueeze.h>
#include <ShiftingText.h>
#include <stdio.h>
#include <string.h>
#include <ByteArraySeekableInputStream.h>
#include <BitmapFont.h>
#include <TextRender.h>

#define AT(b, y, z) *(b + ((((z) * CUBE_SIZE) + (y))))

EffectSpec::EffectSpec(Cube *cube) : cube(cube) {
}

void EffectSpec::run() {
  selfSpec();
  rainSpec();
  blinkSpec();
  boingBoingSpec();
  boxShrinkGrowSpec();
  boxWoopWoopSpec();
  flowingBoxSpec();
  gameOfLifeSpec();
  movingBoxShrinkGrowSpec();
  randomSparkleSpec();
  ripplesSpec();
  stairsSpec();
  suspendSpec();
  upDownSpec();
  wormSqueezeSpec();
  turnOnRandomlySpec();
  shiftingTextSpec();
}

void EffectSpec::selfSpec() {
  Point p = Point();
  Effect effect = Effect(cube, 1, 0);
  cube->clear();
  effect.sendVoxel(&p, FRONT, 0);
  Asserter::assertEqual(0, 0, "selfSpec: It should not break.");
}

void EffectSpec::blinkSpec() {
  Blink effect = Blink(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "blinkSpec: It should not break, we cannot test it.");
}

void EffectSpec::rainSpec() {
  unsigned char i, aux = 0;
  Rain effect = Rain(cube, 1, 0, 1, 8);
  cube->clear();
  effect.run();
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, Cube::SIZE - 2);
  }
  Asserter::assertNotEqual(aux, 0, "rainSpec: It should have turned on some LEDs.");
  aux = 0;
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, Cube::SIZE - 1);
  }
  Asserter::assertEqual(aux, 0, "rainSpec: It should clear the top plane.");
}

void EffectSpec::boingBoingSpec() {
  BoingBoing effect = BoingBoing(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "BoingBoing: It should not break, we cannot test it.");
}

void EffectSpec::boxShrinkGrowSpec() {
  BoxShrinkGrow effect = BoxShrinkGrow(cube, 1, 0, BoxShrinkGrow::WALL);
  effect.run();
  Asserter::assertEqual(0, 0, "BoxShrinkGrow: It should not break, we cannot test it.");
}

void EffectSpec::boxWoopWoopSpec() {
  BoxWoopWoop effect = BoxWoopWoop(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "BoxWoopWoop: It should not break, we cannot test it.");
}

void EffectSpec::flowingBoxSpec() {
  FlowingBox effect = FlowingBox(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "FlowingBox: It should not break, we cannot test it.");
}

void EffectSpec::gameOfLifeSpec() {
  GameOfLife effect = GameOfLife(cube, 1, 0, 8);
  effect.run();
  Asserter::assertEqual(0, 0, "GameOfLife: It should not break, we cannot test it.");
}

void EffectSpec::movingBoxShrinkGrowSpec() {
  MovingBoxShrinkGrow effect = MovingBoxShrinkGrow(cube, 1, 0, BoxShrinkGrow::WALL);
  effect.run();
  Asserter::assertEqual(0, 0, "MovingBoxShrinkGrow: It should not break, we cannot test it.");
}

void EffectSpec::randomSparkleSpec() {
  RandomSparkle effect = RandomSparkle(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "RandomSparkle: It should not break, we cannot test it.");
}

void EffectSpec::ripplesSpec() {
  Ripples effect = Ripples(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "Ripples: It should not break, we cannot test it.");
}

void EffectSpec::stairsSpec() {
  Stairs effect = Stairs(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "Stairs: It should not break, we cannot test it.");
}

void EffectSpec::suspendSpec() {
  Suspend effect = Suspend(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "Suspend: It should not break, we cannot test it.");
}

void EffectSpec::upDownSpec() {
  UpDown effect = UpDown(cube, 1, 0, Axis::AXIS_X, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "upDownSpec: It should not break, we cannot test it.");
}

void EffectSpec::wormSqueezeSpec() {
  WormSqueeze effect = WormSqueeze(cube, 1, 0);
  effect.run();
  Asserter::assertEqual(0, 0, "WormSqueeze: It should not break, we cannot test it.");
}

void EffectSpec::turnOnRandomlySpec() {
  TurnOnRandomly effect = TurnOnRandomly(cube, 1, 0, 8);
  effect.run();
  Asserter::assertEqual(0, 0, "turnOnRandomlySpec: It should not break, we cannot test it.");
}

void EffectSpec::shiftingTextSpec() {
  unsigned char fontStream[] = {
    0x0, 0x5, 0x8, 0x2, 0x48, 0x48, 0x0, 0xc, 0x50, 0x50, 0x0, 0x11,
    0x7f, 0x8, 0x8, 0x8, 0x7f, 0x7f, 0x9, 0x9, 0x9, 0x6
  };
  ByteArraySeekableInputStream is = ByteArraySeekableInputStream(&fontStream[0], (unsigned int) sizeof(fontStream));
  BitmapFont font = BitmapFont(&is);
  TextRender render = TextRender(cube, &font);
  Point p = Point(0, 0, 0);
  ShiftingText::ShiftingTextSettings settings = {&render, (const char *) "HP", 2, TextRender::XYZ, &p};
  ShiftingText effect = ShiftingText(cube, 1, 0, &settings);
  effect.run();
  Asserter::assertEqual(0, 0, "shiftingTextSpec: It should not break, we cannot test it.");
}
