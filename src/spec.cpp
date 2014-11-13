#include <CubeTest.h>
#include <EffectTest.h>

#define TEST_MODE 1

int main(int argc, char *argv[]) {
  
  Cube cube = Cube();
  CubeTest cubeTest = CubeTest(&cube);
  EffectTest effectTest = EffectTest(&cube);

  cubeTest.run();
  effectTest.run();

  
  return 0;
}
