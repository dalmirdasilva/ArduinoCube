#include <CubeSpec.h>
#include <EffectSpec.h>
#include <PointSpec.h>
#include <Asserter.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  Cube cube = Cube();

  CubeSpec cubeSpec = CubeSpec(&cube);
  PointSpec pointSpec = PointSpec();
  EffectSpec effectSpec = EffectSpec(&cube);

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

  return 0;
}
