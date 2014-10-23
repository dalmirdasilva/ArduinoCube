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
  void turnOnVoxelTest();
  void turnOffVoxelTest();
  void invertVoxelTest();
  void turnOnPlaneZTest();
  void writePlaneZTest();
  void writePlaneXTest();
};

#endif /* __ARDUINO_CUBE_DROWER_TEST_H__ */
