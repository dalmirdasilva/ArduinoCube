#include <CubeTest.h>
#include <Asserter.h>
#include <Util.h>
#include <stdio.h>
#include <string.h>

#define AT(b, y, z) *(b + ((((z) * CUBE_SIZE) + (y))))

CubeTest::CubeTest(Cube *cube) : cube(cube) {
}

unsigned int CubeTest::run() {
  unsigned int errorCount = 0;
  errorCount += isInRangeTest();
  errorCount += writeVoxelTest();
  errorCount += invertVoxelTest();
  errorCount += writePlaneZTest();
  errorCount += writePlaneYTest();
  errorCount += writePlaneXTest();
  errorCount += flipByteTest();
  errorCount += mirrorXTest();
  errorCount += mirrorYTest();
  errorCount += mirrorZTest();
  errorCount += filledBoxTest();
  errorCount += lineTest();
  errorCount += shiftOnXTest();
  errorCount += shiftOnYTest();
  errorCount += shiftOnZTest();
  return errorCount;
}

unsigned int CubeTest::isInRangeTest() {
  unsigned int errorCount = 0;
  Point p = {0, 0, 0};
  errorCount += (unsigned int) Asserter::assertEqual(cube->isInRange(&p), true, "isInRange: Point should be in range.");
  p.y = Cube::SIZE;
  errorCount += (unsigned int) Asserter::assertEqual(cube->isInRange(&p), false, "isInRange: Point with wrong y should not be in range.");
  p.y = 0;
  p.z = Cube::SIZE;
  errorCount += (unsigned int) Asserter::assertEqual(cube->isInRange(&p), false, "isInRange: Point with wrong z should not be in range.");
  return errorCount;
}

unsigned int CubeTest::writeVoxelTest() {
  unsigned int errorCount = 0;
  unsigned char x = 5, y = 1, z = 1;
  Point p = {x, y, z};
  Voxel v = {State::ON};
  AT(cube->frontBuffer, y, z) = 0x00;
  cube->useBackBuffer(true);
  cube->writeVoxel(&p, v);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->backBuffer, y, z), (0x01 << x), "writeVoxel: Should write the correct voxel when ON.");
  v.state = State::OFF;
  cube->writeVoxel(&p, v);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->backBuffer, y, z), 0x00, "writeVoxel: Should write the correct voxel when OFF.");
  cube->useBackBuffer(false);
  cube->writeVoxel(&p, v);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, y, z), 0x00, "writeVoxel: Should write the correct voxel when writing to the front buffer.");
  return errorCount;
}

unsigned int CubeTest::invertVoxelTest() {
  unsigned int errorCount = 0;
  unsigned char x = 5, y = 3, z = 1;
  Point p = {x, y, z};
  AT(cube->frontBuffer, y, z) = 0xff;
  cube->useBackBuffer(false);
  cube->invertVoxel(&p);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, y, z), ~(0x01 << x), "invertVoxel: should invert the voxel.");
  cube->useBackBuffer(true);
  AT(cube->backBuffer, y, z) = 0x00;
  cube->invertVoxel(&p);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->backBuffer, y, z), 0x01 << x, "invertVoxel: should invert the voxel when writing to the back buffer.");
  return errorCount;
}

unsigned int CubeTest::writePlaneZTest() {
  unsigned int errorCount = 0;
  unsigned char i, aux, z = 2;
  Voxel v = {State::ON};
  cube->useBackBuffer(false);
  cube->clear();
  cube->writePlaneZ(z, v);
  aux = 0xff;
  for (i = 0; i < Cube::SIZE; i++) {
    aux &= AT(cube->frontBuffer, i, z);
  }
  errorCount += (unsigned int) Asserter::assertEqual(aux, 0xff, "writePlaneZTest: should write all z axis LEDs.");
  return errorCount;
}

unsigned int CubeTest::writePlaneYTest() {
  unsigned int errorCount = 0;
  unsigned char z, aux, y = 3;
  Voxel v = {State::ON};
  cube->useBackBuffer(false);
  cube->clear();
  cube->writePlaneY(y, v);
  aux = 0xff;
  for (z = 0; z < Cube::SIZE; z++) {
    aux &= AT(cube->frontBuffer, y, z);
  }
  errorCount += (unsigned int) Asserter::assertEqual(aux, 0xff, "writePlaneXTest: should write all y axis LEDs.");
  return errorCount;
}

unsigned int CubeTest::writePlaneXTest() {
  unsigned int errorCount = 0;
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
  errorCount += (unsigned int) Asserter::assertEqual(aux, (0x01 << x), "writePlaneXTest: should write all x axis LEDs.");
  return errorCount;
}

unsigned int CubeTest::flipByteTest() {
  unsigned int errorCount = 0;
  unsigned char b = 0xab;
  cube->flipByte(&b);
  errorCount += (unsigned int) Asserter::assertEqual(b, 0xd5, "flipByteTest: should flip the byte.");
  return errorCount;
}

unsigned int CubeTest::mirrorXTest() {
  unsigned int errorCount = 0;
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
  errorCount += (unsigned int) Asserter::assertEqual(aux, 0xab, "mirrorX: should mirror X.");
  return errorCount;
}

unsigned int CubeTest::mirrorYTest() {
  unsigned int errorCount = 0;
  unsigned char aux = 0xaa;
  cube->useBackBuffer(false);
  cube->clear();
  AT(cube->frontBuffer, 0, 0) = aux;
  cube->mirrorY();
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, Cube::SIZE - 1, 0), aux, "mirrorY: should mirror Y.");
  return errorCount;
}

unsigned int CubeTest::mirrorZTest() {
  unsigned int errorCount = 0;
  unsigned char aux = 0xaa;
  cube->useBackBuffer(false);
  cube->clear();
  AT(cube->frontBuffer, 0, 0) = aux;
  cube->mirrorZ();
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, 0, Cube::SIZE - 1), aux, "mirrorZ: should mirror Z.");
  cube->clear();
  cube->useBackBuffer(true);
  cube->clear();
  AT(cube->backBuffer, 0, 0) = aux;
  cube->mirrorZ();
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, 0, Cube::SIZE - 1), 0, "mirrorZ: should keep frontBuffer empty when using backBuffer when mirroring Z.");
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->backBuffer, 0, Cube::SIZE - 1), aux, "mirrorZ: should keep frontBuffer empty when using backBuffer when mirroring Z.");
  return errorCount;
}

unsigned int CubeTest::filledBoxTest() {
  unsigned int errorCount = 0;
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
  errorCount += (unsigned int) Asserter::assertEqual(aux, 0x07, "filledBox: test#1 should draw a filled box.");
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
  errorCount += (unsigned int) Asserter::assertEqual(aux, 0x06, "filledBox: test#2 should draw a filled box.");
  return errorCount;
}

unsigned int CubeTest::lineTest() {
  unsigned int errorCount = 0;
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
  errorCount += (unsigned int) Asserter::assertEqual(sum, 0xff, "line: should draw a line.");
  return errorCount;
}

unsigned int CubeTest::shiftOnXTest() {
  unsigned int errorCount = 0;
  unsigned char x = 0, y = 0, z = 7, aux;
  Point p = {x, y, z};
  cube->useBackBuffer(false);
  cube->clear();
  cube->turnVoxelOn(&p);
  aux = AT(cube->frontBuffer, y, z);
  cube->shiftOnX(Direction::RIGHT);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, y, z), Util::shift(aux, false), "shiftOnXTest: should shiftOnXTest RIGHT.");
  aux = AT(cube->frontBuffer, y, z);
  cube->shiftOnX(Direction::LEFT);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, y, z), Util::shift(aux, true), "shiftOnXTest: should shiftOnXTest LEFT.");
  return errorCount;
}

unsigned int CubeTest::shiftOnYTest() {
  unsigned int errorCount = 0;
  cube->useBackBuffer(false);
  cube->clear();
  AT(cube->frontBuffer, 7, 0) = 0xff;
  cube->shiftOnY(Direction::BACK);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, 7, 0), 0x00, "shiftOnYTest: should shiftOnYTest case 1.");
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, 6, 0), 0xff, "shiftOnYTest: should shiftOnYTest case 2.");
  cube->shiftOnY(Direction::FRONT);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, 7, 0), 0xff, "shiftOnYTest: should shiftOnYTest case 3.");
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, 6, 0), 0x00, "shiftOnYTest: should shiftOnYTest case 4.");
  return errorCount;
}

unsigned int CubeTest::shiftOnZTest() {
  unsigned int errorCount = 0;
  unsigned char x = 0, y = 0, z = 7;
  Point p = {x, y, z};
  cube->useBackBuffer(false);
  cube->clear();
  cube->turnVoxelOn(&p);
  cube->shiftOnZ(Direction::UP);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, y, (z + 1) % Cube::SIZE), 0x01 << x, "shiftOnZTest: should shiftOnZTest UP.");
  cube->shiftOnZ(Direction::DOWN);
  errorCount += (unsigned int) Asserter::assertEqual(AT(cube->frontBuffer, y, z), 0x01 << x, "shiftOnZTest: should shiftOnZTest UP.");
  return errorCount;
}
