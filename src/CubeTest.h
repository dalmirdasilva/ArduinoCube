/**
 */

#ifndef __ARDUINO_CUBE_CUBE_TEST_H__
#define __ARDUINO_CUBE_CUBE_TEST_H__ 1

#include <Cube.h>

class CubeTest {
  
public:

  Cube *cube;
  
  CubeTest(Cube *cube);
  
  unsigned int run();
  
  unsigned int isInRangeTest();
  
  unsigned int writeVoxelTest();
  
  unsigned int invertVoxelTest();
  
  unsigned int writePlaneZTest();
  
  unsigned int writePlaneYTest();
  
  unsigned int writePlaneXTest();
  
  unsigned int flipByteTest();
  
  unsigned int mirrorXTest();
  
  unsigned int mirrorYTest();
  
  unsigned int mirrorZTest();
  
  unsigned int filledBoxTest();
  
  unsigned int lineTest();
  
  unsigned int shiftOnXTest();
  
  unsigned int shiftOnYTest();
  
  unsigned int shiftOnZTest();
};

#endif /* __ARDUINO_CUBE_CUBE_TEST_H__ */
