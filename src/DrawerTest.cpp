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
  drawer->writeVoxel(&p, v, Drawer::BUFFER_TARGET);
  SpecHelper::assertEqual(Cube::buffer[z][y], (0x01 << x), "writeVoxel: Should write the correct voxel when ON.");
  v.state = Voxel::OFF;
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
  Voxel v = {Voxel::ON};
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
  Voxel v = {Voxel::ON};
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
  Voxel v = {Voxel::ON};
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
  unsigned char aux, i, j, y = 4, buf[Cube::SIZE][Cube::SIZE];
  for (i = 0; i < Cube::SIZE; i++)
    Cube::buffer[i][y] = i;
    
  memcpy(buf, Cube::buffer, Cube::BYTE_SIZE);
  drawer->mirrorY(Drawer::BUFFER_TARGET);
  aux = 0;
  for (i = 0, j = Cube::SIZE - 1; i < Cube::SIZE; i++, j--)
    aux += (Cube::buffer[i][y] == buf[j][y] ? 1 : 0);
    
  SpecHelper::assertEqual(aux, 8, "mirrorY: should mirror Y.");
}

void DrawerTest::mirrorZTest() {
  SpecHelper::assertEqual(1, 0, "mirrorY: should mirror Y.");
}
