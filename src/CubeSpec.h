/**
 */

#ifndef __ARDUINO_CUBE_CUBE_TEST_H__
#define __ARDUINO_CUBE_CUBE_TEST_H__ 1

#include <Cube.h>

class CubeSpec {
  
public:

  Cube *cube;
  
  CubeSpec(Cube *cube);
  
  unsigned int run();
  
  unsigned int isInRangeSpec();
  
  unsigned int writeVoxelSpec();
  
  unsigned int invertVoxelSpec();
  
  unsigned int writePlaneZSpec();
  
  unsigned int writePlaneYSpec();
  
  unsigned int writePlaneXSpec();
  
  unsigned int flipByteSpec();
  
  unsigned int mirrorXSpec();
  
  unsigned int mirrorYSpec();
  
  unsigned int mirrorZSpec();
  
  unsigned int filledBoxSpec();
  
  unsigned int lineSpec();
  
  unsigned int shiftOnXSpec();
  
  unsigned int shiftOnYSpec();
  
  unsigned int shiftOnZSpec();
};

#endif /* __ARDUINO_CUBE_CUBE_TEST_H__ */
