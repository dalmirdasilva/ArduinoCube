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
  printf("Cube error count: %d\n", Asserter::getCounter()->error);

  Asserter::reset();
  effectSpec.run();
  printf("Effect error count: %d\n", Asserter::getCounter()->error);

  Asserter::reset();
  pointSpec.run();
  printf("Point error count: %d\n", Asserter::getCounter()->error);

  return 0;
}
