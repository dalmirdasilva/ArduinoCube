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
  printf("Cube error count: %d\n", Asserter::counter.error);
  printf("Cube success count: %d\n", Asserter::counter.success);

  Asserter::reset();
  effectSpec.run();
  printf("Effect error count: %d\n", Asserter::counter.error);
  printf("Effect success count: %d\n", Asserter::counter.success);

  Asserter::reset();
  pointSpec.run();
  printf("Point error count: %d\n", Asserter::counter.error);
  printf("Point success count: %d\n", Asserter::counter.success);

  return 0;
}
