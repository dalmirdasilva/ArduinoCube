#include <CubeTest.h>
#include <EffectTest.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  unsigned int cubeErrorCount, effectErrorCount;
  Cube cube = Cube();

  CubeTest cubeTest = CubeTest(&cube);
  EffectTest effectTest = EffectTest(&cube);

  cubeErrorCount = cubeTest.run();
  effectErrorCount = effectTest.run();


  printf("cubeErrorCount: %d\n", cubeErrorCount);
  printf("effectErrorCount: %d\n", effectErrorCount);

  return 0;
}
