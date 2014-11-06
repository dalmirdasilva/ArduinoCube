/**
 */

#ifndef __ARDUINO_CUBE_CUBE_TEST_H__
#define __ARDUINO_CUBE_CUBE_TEST_H__ 1

#include <Cube.h>

class CubeTest {
  
public:

  Cube *cube;
  
  CubeTest(Cube *cube);
  
  void run();
  
  void isInRangeTest();
  
  void writeVoxelTest();
  
  void invertVoxelTest();
  
  void writePlaneZTest();
  
  void writePlaneYTest();
  
  void writePlaneXTest();
  
  void flipByteTest();
  
  void mirrorXTest();
  
  void mirrorYTest();
  
  void mirrorZTest();
  
  void filledBoxTest();
  
  void lineTest();
  
  void shiftOnXTest();
  
  void shiftOnYTest();
  
  void shiftOnZTest();
};

#endif /* __ARDUINO_CUBE_CUBE_TEST_H__ */
