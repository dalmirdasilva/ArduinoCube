#include <DrawerTest.h>
#include <stdio.h>
#include <string.h>

DrawerTest::DrawerTest(Drawer *drawer) : drawer(drawer) {
}

void DrawerTest::run() {
  isInRangeTest();
  writeVoxelTest();
  invertVoxelTest();
  writePlaneZTest();
  writePlaneYTest();
  writePlaneXTest();
  flipByteTest();
  mirrorXTest();
  mirrorYTest();
  mirrorZTest();
  filledBoxTest();
  lineTest();
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
  Voxel v = {VoxelState::ON};
  Cube::buffer[z][y] = 0x00;
  drawer->writeVoxel(&p, v, Drawer::BUFFER_TARGET);
  SpecHelper::assertEqual(Cube::buffer[z][y], (0x01 << x), "writeVoxel: Should write the correct voxel when ON.");
  v.state = VoxelState::OFF;
  drawer->writeVoxel(&p, v, Drawer::BUFFER_TARGET);
  SpecHelper::assertEqual(Cube::buffer[z][y], 0x00, "writeVoxel: Should write the correct voxel when OFF.");
  Cube::buffer[z][y] = 0xff;
  Cube::cube[z][y] = 0x01 << x;
  drawer->writeVoxel(&p, v, Drawer::CUBE_TARGET);
  SpecHelper::assertEqual(Cube::cube[z][y], 0x00, "writeVoxel: Should write the correct voxel when writting to the cube.");
}

void DrawerTest::invertVoxelTest() {
  unsigned char x = 5, y = 3, z = 1;
  Point p = {x, y, z};
  Cube::buffer[z][y] = 0xff;
  drawer->invertVoxel(&p, Drawer::BUFFER_TARGET);
  SpecHelper::assertEqual(Cube::buffer[z][y], ~(0x01 << x), "invertVoxel: should invert the voxel.");
  Cube::cube[z][y] = 0x00;
  drawer->invertVoxel(&p, Drawer::CUBE_TARGET);
  SpecHelper::assertEqual(Cube::cube[z][y], 0x01 << x, "invertVoxel: should invert the voxel when writting to the cube.");
}

void DrawerTest::writePlaneZTest() {
  unsigned char i, aux, z = 2;
  Voxel v = {VoxelState::ON};
  for (i = 0; i < Cube::SIZE; i++)
    Cube::buffer[z][i] = 0x00;
    
  drawer->writePlaneZ(z, v, Drawer::BUFFER_TARGET);
  aux = 0xff;
  for (i = 0; i < Cube::SIZE; i++)
    aux &= Cube::buffer[z][i];
    
  SpecHelper::assertEqual(aux, 0xff, "writePlaneZTest: should write all z axis leds.");
}

void DrawerTest::writePlaneYTest() {
  unsigned char i, aux, y = 3;
  Voxel v = {VoxelState::ON};
  for (i = 0; i < Cube::SIZE; i++)
    Cube::buffer[i][y] = 0x00;
    
  drawer->writePlaneY(y, v, Drawer::BUFFER_TARGET);
  aux = 0xff;
  for (i = 0; i < Cube::SIZE; i++)
    aux &= Cube::buffer[i][y];
    
  SpecHelper::assertEqual(aux, 0xff, "writePlaneXTest: should write all y axis leds.");
}

void DrawerTest::writePlaneXTest() {
  unsigned char i, j, aux, x = 3;
  Voxel v = {VoxelState::ON};
  for (i = 0; i < Cube::SIZE; i++) {
    for (j = 0; j < Cube::SIZE; j++) {
      Cube::buffer[i][j] = 0x00;
    }
  }
  drawer->writePlaneX(x, v, Drawer::BUFFER_TARGET);
  aux = 0x01 << x;
  for (i = 0; i < Cube::SIZE; i++)
    for (j = 0; j < Cube::SIZE; j++)
      aux |= Cube::buffer[i][j] & (0x01 << x);
      
  SpecHelper::assertEqual(aux, (0x01 << x), "writePlaneXTest: should write all x axis leds.");
}

void DrawerTest::flipByteTest() {
  unsigned char b = 0xab;
  drawer->flipByte(&b);
  SpecHelper::assertEqual(b, 0xd5, "flipByteTest: should flip the byte.");
}

void DrawerTest::mirrorXTest() {
  unsigned char aux, i, j;
  for (i = 0; i < Cube::SIZE; i++)
    for (j = 0; j < Cube::SIZE; j++)
      Cube::buffer[i][j] = 0xd5;
      
  drawer->mirrorX(Drawer::BUFFER_TARGET);
  aux = 0xab;
  for (i = 0; i < Cube::SIZE; i++)
    for (j = 0; j < Cube::SIZE; j++)
      aux &= Cube::buffer[i][j];
      
  SpecHelper::assertEqual(aux, 0xab, "mirrorX: should mirror X.");
}

void DrawerTest::mirrorYTest() {
  unsigned char aux = 0xaa;
  drawer->clear(Drawer::BUFFER_TARGET);
  Cube::buffer[0][0] = aux;
  drawer->mirrorY(Drawer::BUFFER_TARGET);
  SpecHelper::assertEqual(Cube::buffer[0][Cube::SIZE - 1], aux, "mirrorY: should mirror Y.");
}

void DrawerTest::mirrorZTest() {
  unsigned char aux = 0xaa;
  drawer->clear(Drawer::BUFFER_TARGET);
  Cube::buffer[0][0] = aux;
  drawer->mirrorZ(Drawer::BUFFER_TARGET);
  SpecHelper::assertEqual(Cube::buffer[Cube::SIZE - 1][0], aux, "mirrorZ: should mirror Z.");
}

void DrawerTest::filledBoxTest() {
  unsigned char z, y, aux = 0xff;
  Point p0 = {0, 0, 0};
  Point p1 = {2, 5, 5};
  drawer->clear(Drawer::BUFFER_TARGET);
  drawer->filledBox(&p0, &p1, Drawer::BUFFER_TARGET);
  for (z = 0; z < 6; z++)
    for (y = 0; y < 6; y++)
      aux &= Cube::buffer[z][y];
  
  SpecHelper::assertEqual(aux, 0x07, "filledBox: test#1 should draw a filled box.");
  p0.x = 1;
  p1.z = 2;
  aux = 0xff;
  drawer->clear(Drawer::BUFFER_TARGET);
  drawer->filledBox(&p0, &p1, Drawer::BUFFER_TARGET);
  for (z = 0; z < 3; z++)
    for (y = 0; y < 6; y++)
      aux &= Cube::buffer[z][y];
      
  SpecHelper::assertEqual(aux, 0x06, "filledBox: test#2 should draw a filled box.");
}

void DrawerTest::lineTest() {
  unsigned char z, y, sum = 0;
  Point from = {0, 0, 0}, to = {7, 7, 7};
  drawer->clear(Drawer::BUFFER_TARGET);
  drawer->line(&from, &to, Drawer::BUFFER_TARGET);
  for (z = 0; z < Cube::SIZE; z++)
    for (y = 0; y < Cube::SIZE; y++)
      sum += Cube::buffer[z][y];
  SpecHelper::assertEqual(sum, 0xff, "line: should draw a line.");
}











