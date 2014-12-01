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
  Effect effect = Effect(cube);
  cube->clear();
  effect.sendVoxel(&p, FRONT, 0);
  Asserter::assertEqual(0, 0, "selfSpec: It should not break.");
}

void EffectSpec::blinkSpec() {
  Blink::BlinkSettings settings = {750};
  Blink effect = Blink(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "blinkSpec: It should not break, we cannot test it.");
}

void EffectSpec::rainSpec() {
  unsigned char i, aux = 0;
  Rain::RainSettings settings = {1, 1, 200};
  Rain effect = Rain(cube, &settings);
  cube->clear();
  effect.run(40);
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, Cube::SIZE - 1);
  }
  Asserter::assertEqual(aux, 0, "rainSpec: It should clear the top plane.");
  for (i = 0; i < Cube::SIZE; i++) {
    aux += AT(cube->frontBuffer, i, 0);
  }
  Asserter::assertNotEqual(aux, 0, "rainSpec: It should have turned on some LEDs.");
}

void EffectSpec::boingBoingSpec() {
  BoingBoing::BoingBoingSettings settings = {};
  BoingBoing effect = BoingBoing(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "BoingBoing: It should not break, we cannot test it.");
}

void EffectSpec::boxShrinkGrowSpec() {
  BoxShrinkGrow::BoxShrinkGrowSettings settings = {1, BoxShrinkGrow::WALL};
  BoxShrinkGrow effect = BoxShrinkGrow(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "BoxShrinkGrow: It should not break, we cannot test it.");
}

void EffectSpec::boxWoopWoopSpec() {
  BoxWoopWoop::BoxWoopWoopSettings settings = {};
  BoxWoopWoop effect = BoxWoopWoop(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "BoxWoopWoop: It should not break, we cannot test it.");
}

void EffectSpec::flowingBoxSpec() {
  FlowingBox::FlowingBoxSettings settings = {};
  FlowingBox effect = FlowingBox(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "FlowingBox: It should not break, we cannot test it.");
}

void EffectSpec::gameOfLifeSpec() {
  GameOfLife::GameOfLifeSettings settings = {0, 8};
  GameOfLife effect = GameOfLife(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "GameOfLife: It should not break, we cannot test it.");
}

void EffectSpec::movingBoxShrinkGrowSpec() {
  BoxShrinkGrow::BoxShrinkGrowSettings parentSettings = {1, BoxShrinkGrow::WALL};
  MovingBoxShrinkGrow::MovingBoxShrinkGrowSettings settings = {&parentSettings};
  MovingBoxShrinkGrow effect = MovingBoxShrinkGrow(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "MovingBoxShrinkGrow: It should not break, we cannot test it.");
}

void EffectSpec::randomSparkleSpec() {
  RandomSparkle::RandomSparkleSettings settings = {};
  RandomSparkle effect = RandomSparkle(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "RandomSparkle: It should not break, we cannot test it.");
}

void EffectSpec::ripplesSpec() {
  Ripples::RipplesSettings settings = {};
  Ripples effect = Ripples(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "Ripples: It should not break, we cannot test it.");
}

void EffectSpec::stairsSpec() {
  Stairs::StairsSettings settings = {};
  Stairs effect = Stairs(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "Stairs: It should not break, we cannot test it.");
}

void EffectSpec::suspendSpec() {
  Suspend::SuspendSettings settings = {};
  Suspend effect = Suspend(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "Suspend: It should not break, we cannot test it.");
}

void EffectSpec::upDownSpec() {
  UpDown::UpDownSettings settings = {Axis::AXIS_X, 3, 0};
  UpDown effect = UpDown(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "upDownSpec: It should not break, we cannot test it.");
}

void EffectSpec::wormSqueezeSpec() {
  WormSqueeze::WormSqueezeSettings settings = {};
  WormSqueeze effect = WormSqueeze(cube, &settings);
  effect.run(1);
  Asserter::assertEqual(0, 0, "WormSqueeze: It should not break, we cannot test it.");
}

void EffectSpec::turnOnRandomlySpec() {
  TurnOnRandomly::TurnOnRandomlySettings settings = {1};
  TurnOnRandomly effect = TurnOnRandomly(cube, &settings);
  effect.run(1);
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
  ShiftingText::ShiftingTextSettings settings = {&render, (char *) "HP"};

}