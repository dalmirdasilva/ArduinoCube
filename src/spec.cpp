#include <CubeSpec.h>
#include <EffectSpec.h>
#include <PointSpec.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  unsigned int cubeErrorCount, effectErrorCount, pointErrorCount;

  Cube cube = Cube();

  CubeSpec cubeSpec = CubeSpec(&cube);
  PointSpec pointSpec = PointSpec();
  EffectSpec effectSpec = EffectSpec(&cube);

  cubeErrorCount = cubeSpec.run();
  effectErrorCount = effectSpec.run();
  pointErrorCount = pointSpec.run();

  printf("cubeErrorCount: %d\n", cubeErrorCount);
  printf("effectErrorCount: %d\n", effectErrorCount);
  printf("pointErrorCount: %d\n", pointErrorCount);

  return cubeErrorCount + effectErrorCount + pointErrorCount;
}
