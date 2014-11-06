#include <CubeTest.h>
#include <Asserter.h>
#include <Util.h>
#include <stdio.h>
#include <string.h>

CubeTest::CubeTest(Cube *cube) : cube(cube) {
}

void CubeTest::run() {
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
  shiftOnXTest();
  shiftOnYTest();
  shiftOnZTest();
}

void CubeTest::isInRangeTest() {
  Point p = {0, 0, 0};
  Asserter::assertEqual(cube->isInRange(&p), true, "isInRange: Point should be in range.");
  p.y = Cube::SIZE;
  Asserter::assertEqual(cube->isInRange(&p), false, "isInRange: Point with wrong y should not be in range.");
  p.y = 0;
  p.z = Cube::SIZE;
  Asserter::assertEqual(cube->isInRange(&p), false, "isInRange: Point with wrong z should not be in range.");
}
 
void CubeTest::writeVoxelTest() {
  unsigned char x = 5, y = 1, z = 1;
  Point p = {x, y, z};
  Voxel v = {VoxelState::ON};
  Cube::buffer[z][y] = 0x00;
  cube->writeVoxel(&p, v, Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[z][y], (0x01 << x), "writeVoxel: Should write the correct voxel when ON.");
  v.state = VoxelState::OFF;
  cube->writeVoxel(&p, v, Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[z][y], 0x00, "writeVoxel: Should write the correct voxel when OFF.");
  Cube::buffer[z][y] = 0xff;
  Cube::cube[z][y] = 0x01 << x;
  cube->writeVoxel(&p, v, Cube::Target::CUBE);
  Asserter::assertEqual(Cube::cube[z][y], 0x00, "writeVoxel: Should write the correct voxel when writting to the cube.");
}

void CubeTest::invertVoxelTest() {
  unsigned char x = 5, y = 3, z = 1;
  Point p = {x, y, z};
  Cube::buffer[z][y] = 0xff;
  cube->invertVoxel(&p, Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[z][y], ~(0x01 << x), "invertVoxel: should invert the voxel.");
  Cube::cube[z][y] = 0x00;
  cube->invertVoxel(&p, Cube::Target::CUBE);
  Asserter::assertEqual(Cube::cube[z][y], 0x01 << x, "invertVoxel: should invert the voxel when writting to the cube.");
}

void CubeTest::writePlaneZTest() {
  unsigned char i, aux, z = 2;
  Voxel v = {VoxelState::ON};
  for (i = 0; i < Cube::SIZE; i++)
    Cube::buffer[z][i] = 0x00;
    
  cube->writePlaneZ(z, v, Cube::Target::BUFFER);
  aux = 0xff;
  for (i = 0; i < Cube::SIZE; i++)
    aux &= Cube::buffer[z][i];
    
  Asserter::assertEqual(aux, 0xff, "writePlaneZTest: should write all z axis leds.");
}

void CubeTest::writePlaneYTest() {
  unsigned char i, aux, y = 3;
  Voxel v = {VoxelState::ON};
  for (i = 0; i < Cube::SIZE; i++)
    Cube::buffer[i][y] = 0x00;
    
  cube->writePlaneY(y, v, Cube::Target::BUFFER);
  aux = 0xff;
  for (i = 0; i < Cube::SIZE; i++)
    aux &= Cube::buffer[i][y];
    
  Asserter::assertEqual(aux, 0xff, "writePlaneXTest: should write all y axis leds.");
}

void CubeTest::writePlaneXTest() {
  unsigned char i, j, aux, x = 3;
  Voxel v = {VoxelState::ON};
  for (i = 0; i < Cube::SIZE; i++) {
    for (j = 0; j < Cube::SIZE; j++) {
      Cube::buffer[i][j] = 0x00;
    }
  }
  cube->writePlaneX(x, v, Cube::Target::BUFFER);
  aux = 0x01 << x;
  for (i = 0; i < Cube::SIZE; i++)
    for (j = 0; j < Cube::SIZE; j++)
      aux |= Cube::buffer[i][j] & (0x01 << x);
      
  Asserter::assertEqual(aux, (0x01 << x), "writePlaneXTest: should write all x axis leds.");
}

void CubeTest::flipByteTest() {
  unsigned char b = 0xab;
  cube->flipByte(&b);
  Asserter::assertEqual(b, 0xd5, "flipByteTest: should flip the byte.");
}

void CubeTest::mirrorXTest() {
  unsigned char aux, i, j;
  for (i = 0; i < Cube::SIZE; i++)
    for (j = 0; j < Cube::SIZE; j++)
      Cube::buffer[i][j] = 0xd5;
      
  cube->mirrorX(Cube::Target::BUFFER);
  aux = 0xab;
  for (i = 0; i < Cube::SIZE; i++)
    for (j = 0; j < Cube::SIZE; j++)
      aux &= Cube::buffer[i][j];
      
  Asserter::assertEqual(aux, 0xab, "mirrorX: should mirror X.");
}

void CubeTest::mirrorYTest() {
  unsigned char aux = 0xaa;
  cube->clear(Cube::Target::BUFFER);
  Cube::buffer[0][0] = aux;
  cube->mirrorY(Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[0][Cube::SIZE - 1], aux, "mirrorY: should mirror Y.");
}

void CubeTest::mirrorZTest() {
  unsigned char aux = 0xaa;
  cube->clear(Cube::Target::BUFFER);
  Cube::buffer[0][0] = aux;
  cube->mirrorZ(Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[Cube::SIZE - 1][0], aux, "mirrorZ: should mirror Z.");
}

void CubeTest::filledBoxTest() {
  unsigned char z, y, aux = 0xff;
  Point p0 = {0, 0, 0};
  Point p1 = {2, 5, 5};
  cube->clear(Cube::Target::BUFFER);
  cube->filledBox(&p0, &p1, Cube::Target::BUFFER);
  for (z = 0; z < 6; z++)
    for (y = 0; y < 6; y++)
      aux &= Cube::buffer[z][y];
  
  Asserter::assertEqual(aux, 0x07, "filledBox: test#1 should draw a filled box.");
  p0.x = 1;
  p1.z = 2;
  aux = 0xff;
  cube->clear(Cube::Target::BUFFER);
  cube->filledBox(&p0, &p1, Cube::Target::BUFFER);
  for (z = 0; z < 3; z++)
    for (y = 0; y < 6; y++)
      aux &= Cube::buffer[z][y];
      
  Asserter::assertEqual(aux, 0x06, "filledBox: test#2 should draw a filled box.");
}

void CubeTest::lineTest() {
  unsigned char z, y, sum = 0;
  Point from = {0, 0, 0}, to = {7, 7, 7};
  cube->clear(Cube::Target::BUFFER);
  cube->line(&from, &to, Cube::Target::BUFFER);
  for (z = 0; z < Cube::SIZE; z++)
    for (y = 0; y < Cube::SIZE; y++)
      sum += Cube::buffer[z][y];

  Asserter::assertEqual(sum, 0xff, "line: should draw a line.");
}

void CubeTest::shiftOnXTest() {
  unsigned char x = 0, y = 0, z = 7, aux;
  Point p = {x, y, z};
  cube->clear(Cube::Target::BUFFER);
  cube->turnOnVoxel(&p, Cube::Target::BUFFER);
  aux = Cube::buffer[z][y];
  cube->shiftOnX(Cube::RIGHT, Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[z][y], Util::shift(aux, false), "shiftOnXTest: should shiftOnXTest RIGHT.");
  aux = Cube::buffer[z][y];
  cube->shiftOnX(Cube::LEFT, Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[z][y], Util::shift(aux, true), "shiftOnXTest: should shiftOnXTest LEFT.");
}

void CubeTest::shiftOnYTest() {
  //Util::dumpCube(&Cube::buffer[0][0]);
  Asserter::assertEqual(1, 0, "shiftOnYTest: should shiftOnYTest.");
}

void CubeTest::shiftOnZTest() {
  unsigned char x = 0, y = 0, z = 7;
  Point p = {x, y, z};
  cube->clear(Cube::Target::BUFFER);
  cube->turnOnVoxel(&p, Cube::Target::BUFFER);
  cube->shiftOnZ(Cube::UP, Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[(z + 1) % Cube::SIZE][y], 0x01 << x, "shiftOnZTest: should shiftOnZTest UP.");
  cube->shiftOnZ(Cube::DOWN, Cube::Target::BUFFER);
  Asserter::assertEqual(Cube::buffer[z][y], 0x01 << x, "shiftOnZTest: should shiftOnZTest UP.");
}













