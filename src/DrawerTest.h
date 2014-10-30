/**
 */

#ifndef __ARDUINO_CUBE_DROWER_TEST_H__
#define __ARDUINO_CUBE_DROWER_TEST_H__ 1

#include <Drawer.h>
#include <SpecHelper.h>

class DrawerTest {
  
public:

  Drawer *drawer;
  
  DrawerTest(Drawer *drawer);
  
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
};

#endif /* __ARDUINO_CUBE_DROWER_TEST_H__ */
