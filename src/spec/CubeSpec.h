/**
 */

#ifndef __ARDUINO_CUBE_CUBE_TEST_H__
#define __ARDUINO_CUBE_CUBE_TEST_H__ 1

#include <Cube.h>

class CubeSpec {
  
public:

  Cube *cube;
  
  CubeSpec(Cube *cube);
  
  void run();
  
  void isInRangeSpec();
  
  void writeVoxelSpec();
  
  void invertVoxelSpec();
  
  void writePlaneZSpec();
  
  void writePlaneYSpec();
  
  void writePlaneXSpec();
  
  void flipByteSpec();
  
  void mirrorXSpec();
  
  void mirrorYSpec();
  
  void mirrorZSpec();
  
  void filledBoxSpec();
  
  void lineSpec();
  
  void shiftOnXSpec();
  
  void shiftOnYSpec();
  
  void shiftOnZSpec();
};

#endif /* __ARDUINO_CUBE_CUBE_TEST_H__ */
