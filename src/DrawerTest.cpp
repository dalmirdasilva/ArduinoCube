#include <DrawerTest.h>
#include <stdio.h>

DrawerTest::DrawerTest(Drawer *drawer) : drawer(drawer) {
}

void DrawerTest::run() {
  isInRangeTest();
  writeVoxelTest();
  turnOnVoxelTest();
  turnOffVoxelTest();
  invertVoxelTest();
  turnOnPlaneZTest();
  writePlaneZTest();
}

void DrawerTest::isInRangeTest() {
  Point p = {0, 0, 0};
  SpecHelper::assertEqual(drawer->isInRange(&p), true, "isInRange: Point should be in range.");
  p.y = Cube::SIZE;
  SpecHelper::assertEqual(drawer->isInRange(&p), false, "isInRange: Point with wrong y should not be in range.");
  p.y = 0;
  p.z = Cube::SIZE;
  SpecHelper::assertEqual(drawer->isInRange(&p), false, "isInRange: Point with wrong z should not be in range.");
}
 
void DrawerTest::writeVoxelTest() {
  unsigned char x = 5, y = 1, z = 1;
  Point p = {x, y, z};
  Voxel v = {Voxel::ON};
  Cube::buffer[z][y] = 0x00;
  drawer->writeVoxel(&p, v);
  SpecHelper::assertEqual(Cube::buffer[z][y], (0x01 << x), "writeVoxel: Should write the correct voxel when ON.");
  v.state = Voxel::OFF;
  drawer->writeVoxel(&p, v);
  SpecHelper::assertEqual(Cube::buffer[z][y], 0x00, "writeVoxel: Should write the correct voxel when OFF.");
  Cube::buffer[z][y] = 0xff;
  Cube::cube[z][y] = 0x01 << x;
  drawer->writeVoxel(&p, v, Drawer::WRITE_TO_CUBE);
  SpecHelper::assertEqual(Cube::cube[z][y], 0x00, "writeVoxel: Should write the correct voxel when writting to the cube.");
}

void DrawerTest::turnOnVoxelTest() {
  unsigned char x = 5, y = 1, z = 1;
  Point p = {x, y, z};
  Cube::buffer[z][y] = 0x00;
  drawer->turnOnVoxel(&p);
  SpecHelper::assertEqual(Cube::buffer[z][y], (0x01 << x), "turnOnVoxel: should turn the voxel on.");
  Cube::cube[z][y] = 0x00;
  drawer->turnOnVoxel(&p, Drawer::WRITE_TO_CUBE);
  SpecHelper::assertEqual(Cube::cube[z][y], (0x01 << x), "turnOnVoxel: should turn the voxel on when writting to the cube.");
}

void DrawerTest::turnOffVoxelTest() {
  unsigned char x = 5, y = 1, z = 1;
  Point p = {x, y, z};
  Cube::buffer[z][y] = 0xff;
  drawer->turnOffVoxel(&p);
  SpecHelper::assertEqual(Cube::buffer[z][y], ~(0x01 << x), "turnOffVoxel: should turn the voxel off.");
  Cube::cube[z][y] = 0xff;
  drawer->turnOffVoxel(&p, Drawer::WRITE_TO_CUBE);
  SpecHelper::assertEqual(Cube::cube[z][y], ~(0x01 << x), "turnOffVoxel: should turn the voxel off when writting to the cube.");
}

void DrawerTest::invertVoxelTest() {
  unsigned char x = 5, y = 3, z = 1;
  Point p = {x, y, z};
  Cube::buffer[z][y] = 0xff;
  drawer->invertVoxel(&p);
  SpecHelper::assertEqual(Cube::buffer[z][y], ~(0x01 << x), "invertVoxel: should invert the voxel.");
}

void DrawerTest::turnOnPlaneZTest() {
}

void DrawerTest::writePlaneZTest() {
}

void DrawerTest::writePlaneXTest() {
}
