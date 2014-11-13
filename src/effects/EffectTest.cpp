#include <EffectTest.h>
#include <Asserter.h>
#include <Util.h>
#include <stdio.h>
#include <string.h>

EffectTest::EffectTest(Cube *cube) : cube(cube) {
}

void EffectTest::run() {
  rainTest();
}

void EffectTest::rainTest() {
  Rain::RainParameters rp = {40, 8, 64, 200};
  Rain r = Rain(cube, &rp);
  cube->clear();
  Util::dumpCube(&Cube::cube[0][0]);
  r.run();
  Util::dumpCube(&Cube::cube[0][0]);
  Asserter::assertEqual(1, 2, "rainTest: errou");
}