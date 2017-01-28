#include <CubeSpec.h>
#include <EffectSpec.h>
#include <PointSpec.h>
#include <BitmapFontSpec.h>
#include <Asserter.h>
#include <Effect.h>
#include <Rain.h>
#include <Stairs.h>
#include <stdio.h>
#include <Arduino.h>

int main(int argc, char *argv[]) {

  Cube cube = Cube();

  CubeSpec cubeSpec = CubeSpec(&cube);
  PointSpec pointSpec = PointSpec();
  EffectSpec effectSpec = EffectSpec(&cube);
  BitmapFontSpec bitmapFontSpec = BitmapFontSpec();

  randomSeed(time(NULL));

  Asserter::reset();
  cubeSpec.run();
  printf("CubeSpec error: %d\n", Asserter::counter.error);
  printf("CubeSpec success: %d\n", Asserter::counter.success);

  Asserter::reset();
  effectSpec.run();
  printf("EffectSpec error: %d\n", Asserter::counter.error);
  printf("EffectSpec success: %d\n", Asserter::counter.success);

  Asserter::reset();
  pointSpec.run();
  printf("PointSpec error: %d\n", Asserter::counter.error);
  printf("PointSpec success: %d\n", Asserter::counter.success);

  Asserter::reset();
  bitmapFontSpec.run();
  printf("BitmapFontSpec error: %d\n", Asserter::counter.error);
  printf("BitmapFontSpec success: %d\n", Asserter::counter.success);

  return 0;
}
