#include <CubeTest.h>
#include <Asserter.h>
#include <Util.h>
#include <stdio.h>
#include <string.h>

#define AT(b, y, z) *(b + ((((z) * CUBE_SIZE) + (y))))

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
  Voxel v = {State::ON};
  AT(cube->frontBuffer, y, z) = 0x00;
  cube->useBackBuffer(true);
  cube->writeVoxel(&p, v);
  Asserter::assertEqual(AT(cube->backBuffer, y, z), (0x01 << x), "writeVoxel: Should write the correct voxel when ON.");
  v.state = State::OFF;
  cube->writeVoxel(&p, v);
  Asserter::assertEqual(AT(cube->backBuffer, y, z), 0x00, "writeVoxel: Should write the correct voxel when OFF.");
  cube->useBackBuffer(false);
  cube->writeVoxel(&p, v);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), 0x00, "writeVoxel: Should write the correct voxel when writing to the front buffer.");
}

void CubeTest::invertVoxelTest() {
  unsigned char x = 5, y = 3, z = 1;
  Point p = {x, y, z};
  AT(cube->frontBuffer, y, z) = 0xff;
  cube->useBackBuffer(false);
  cube->invertVoxel(&p);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), ~(0x01 << x), "invertVoxel: should invert the voxel.");
  cube->useBackBuffer(true);
  AT(cube->backBuffer, y, z) = 0x00;
  cube->invertVoxel(&p);
  Asserter::assertEqual(AT(cube->backBuffer, y, z), 0x01 << x, "invertVoxel: should invert the voxel when writing to the back buffer.");
}

void CubeTest::writePlaneZTest() {
  unsigned char i, aux, z = 2;
  Voxel v = {State::ON};
  cube->useBackBuffer(false);
  cube->clear();
  cube->writePlaneZ(z, v);
  aux = 0xff;
  for (i = 0; i < Cube::SIZE; i++) {
    aux &= AT(cube->frontBuffer, i, z);
  }
  Asserter::assertEqual(aux, 0xff, "writePlaneZTest: should write all z axis LEDs.");
}

void CubeTest::writePlaneYTest() {
  unsigned char z, aux, y = 3;
  Voxel v = {State::ON};
  cube->useBackBuffer(false);
  cube->clear();
  cube->writePlaneY(y, v);
  aux = 0xff;
  for (z = 0; z < Cube::SIZE; z++) {
    aux &= AT(cube->frontBuffer, y, z);
  }
  Asserter::assertEqual(aux, 0xff, "writePlaneXTest: should write all y axis LEDs.");
}

void CubeTest::writePlaneXTest() {
  unsigned char z, y, aux, x = 3;
  Voxel v = {State::ON};
  cube->useBackBuffer(false);
  cube->clear();
  cube->writePlaneX(x, v);
  aux = 0x01 << x;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      aux |= AT(cube->frontBuffer, y, z) & (0x01 << x);
    }
  }
  Asserter::assertEqual(aux, (0x01 << x), "writePlaneXTest: should write all x axis LEDs.");
}

void CubeTest::flipByteTest() {
  unsigned char b = 0xab;
  cube->flipByte(&b);
  Asserter::assertEqual(b, 0xd5, "flipByteTest: should flip the byte.");
}

void CubeTest::mirrorXTest() {
  unsigned char aux, z, y;
  cube->useBackBuffer(false);
  cube->fill(0xd5);
  cube->mirrorX();
  aux = 0xab;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      aux &= AT(cube->frontBuffer, y, z);
    }
  }
  Asserter::assertEqual(aux, 0xab, "mirrorX: should mirror X.");
}

void CubeTest::mirrorYTest() {
  unsigned char aux = 0xaa;
  cube->useBackBuffer(false);
  cube->clear();
  AT(cube->frontBuffer, 0, 0) = aux;
  cube->mirrorY();
  Asserter::assertEqual(AT(cube->frontBuffer, Cube::SIZE - 1, 0), aux, "mirrorY: should mirror Y.");
}

void CubeTest::mirrorZTest() {
  unsigned char aux = 0xaa;
  cube->useBackBuffer(false);
  cube->clear();
  AT(cube->frontBuffer, 0, 0) = aux;
  cube->mirrorZ();
  Asserter::assertEqual(AT(cube->frontBuffer, 0, Cube::SIZE - 1), aux, "mirrorZ: should mirror Z.");
  cube->clear();
  cube->useBackBuffer(true);
  cube->clear();
  AT(cube->backBuffer, 0, 0) = aux;
  cube->mirrorZ();
  Asserter::assertEqual(AT(cube->frontBuffer, 0, Cube::SIZE - 1), 0, "mirrorZ: should keep frontBuffer empty when using backBuffer when mirroring Z.");
  Asserter::assertEqual(AT(cube->backBuffer, 0, Cube::SIZE - 1), aux, "mirrorZ: should keep frontBuffer empty when using backBuffer when mirroring Z.");
}

void CubeTest::filledBoxTest() {
  unsigned char z, y, aux = 0xff;
  Point p0 = {0, 0, 0};
  Point p1 = {2, 5, 5};
  cube->useBackBuffer(false);
  cube->clear();
  cube->filledBox(&p0, &p1);
  for (z = 0; z < 6; z++) {
    for (y = 0; y < 6; y++) {
      aux &= AT(cube->frontBuffer, y, z);
    }
  }
  Asserter::assertEqual(aux, 0x07, "filledBox: test#1 should draw a filled box.");
  p0.x = 1;
  p1.z = 2;
  aux = 0xff;
  cube->clear();
  cube->filledBox(&p0, &p1);
  for (z = 0; z < 3; z++) {
    for (y = 0; y < 6; y++) {
      aux &= AT(cube->frontBuffer, y, z);
    }
  }
  Asserter::assertEqual(aux, 0x06, "filledBox: test#2 should draw a filled box.");
}

void CubeTest::lineTest() {
  unsigned char z, y, sum = 0;
  Point from = {0, 0, 0}, to = {7, 7, 7};
  cube->useBackBuffer(false);
  cube->clear();
  cube->line(&from, &to);
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      sum += AT(cube->frontBuffer, y, z);
    }
  }
  Asserter::assertEqual(sum, 0xff, "line: should draw a line.");
}

void CubeTest::shiftOnXTest() {
  unsigned char x = 0, y = 0, z = 7, aux;
  Point p = {x, y, z};
  cube->useBackBuffer(false);
  cube->clear();
  cube->turnVoxelOn(&p);
  aux = AT(cube->frontBuffer, y, z);
  cube->shiftOnX(Direction::RIGHT);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), Util::shift(aux, false), "shiftOnXTest: should shiftOnXTest RIGHT.");
  aux = AT(cube->frontBuffer, y, z);
  cube->shiftOnX(Direction::LEFT);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), Util::shift(aux, true), "shiftOnXTest: should shiftOnXTest LEFT.");
}

void CubeTest::shiftOnYTest() {
  cube->useBackBuffer(false);
  cube->clear();
  AT(cube->frontBuffer, 7, 0) = 0xff;
  cube->shiftOnY(Direction::BACK);
  Asserter::assertEqual(AT(cube->frontBuffer, 7, 0), 0x00, "shiftOnYTest: should shiftOnYTest case 1.");
  Asserter::assertEqual(AT(cube->frontBuffer, 6, 0), 0xff, "shiftOnYTest: should shiftOnYTest case 2.");
  cube->shiftOnY(Direction::FRONT);
  Asserter::assertEqual(AT(cube->frontBuffer, 7, 0), 0xff, "shiftOnYTest: should shiftOnYTest case 3.");
  Asserter::assertEqual(AT(cube->frontBuffer, 6, 0), 0x00, "shiftOnYTest: should shiftOnYTest case 4.");
}

void CubeTest::shiftOnZTest() {
  unsigned char x = 0, y = 0, z = 7;
  Point p = {x, y, z};
  cube->useBackBuffer(false);
  cube->clear();
  cube->turnVoxelOn(&p);
  cube->shiftOnZ(Direction::UP);
  Asserter::assertEqual(AT(cube->frontBuffer, y, (z + 1) % Cube::SIZE), 0x01 << x, "shiftOnZTest: should shiftOnZTest UP.");
  cube->shiftOnZ(Direction::DOWN);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), 0x01 << x, "shiftOnZTest: should shiftOnZTest UP.");
}
