#include <CubeTest.h>

#define TEST_MODE 1

int main(int argc, char *argv[]) {
  
  Cube cube = Cube();
  CubeTest cubeTest = CubeTest(&cube);
  cubeTest.run();
  
  return 0;
}
