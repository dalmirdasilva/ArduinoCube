#include <CubeSpec.h>
#include <Asserter.h>
#include <Voxel.h>
#include <Util.h>
#include <stdio.h>
#include <string.h>

#define AT(b, y, z) *(b + ((((z) * CUBE_SIZE) + (y))))

CubeSpec::CubeSpec(Cube *cube) : cube(cube) {
}

void CubeSpec::run() {
  isInRangeSpec();
  writeVoxelSpec();
  invertVoxelSpec();
  writePlaneZSpec();
  writePlaneYSpec();
  writePlaneXSpec();
  flipByteSpec();
  mirrorXSpec();
  mirrorYSpec();
  mirrorZSpec();
  filledBoxSpec();
  lineSpec();
  shiftOnXSpec();
  shiftOnYSpec();
  shiftOnZSpec();
}

void CubeSpec::isInRangeSpec() {
  Point p = Point();
  Asserter::assertEqual(cube->isInRange(&p), true, "isInRange: Point should be in range.");
  p.y = Cube::SIZE;
  Asserter::assertEqual(cube->isInRange(&p), false, "isInRange: Point with wrong y should not be in range.");
  p.y = 0;
  p.z = Cube::SIZE;
  Asserter::assertEqual(cube->isInRange(&p), false, "isInRange: Point with wrong z should not be in range.");
}

void CubeSpec::writeVoxelSpec() {
  unsigned char x = 5, y = 1, z = 1;
  Point p = Point(x, y, z);
  Voxel v = {ON};
  AT(cube->frontBuffer, y, z) = 0x00;
  cube->useBackBuffer();
  cube->writeVoxel(&p, v);
  Asserter::assertEqual(AT(cube->backBuffer, y, z), (0x01 << x), "writeVoxel: Should write the correct voxel when ON.");
  v.state = OFF;
  cube->writeVoxel(&p, v);
  Asserter::assertEqual(AT(cube->backBuffer, y, z), 0x00, "writeVoxel: Should write the correct voxel when OFF.");
  cube->useFrontBuffer();
  cube->writeVoxel(&p, v);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), 0x00, "writeVoxel: Should write the correct voxel when writing to the front buffer.");
}

void CubeSpec::invertVoxelSpec() {
  unsigned char x = 5, y = 3, z = 1;
  Point p = Point(x, y, z);
  AT(cube->frontBuffer, y, z) = 0xff;
  cube->useFrontBuffer();
  cube->invertVoxel(&p);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), ~(0x01 << x), "invertVoxel: should invert the voxel.");
  cube->useBackBuffer();
  AT(cube->backBuffer, y, z) = 0x00;
  cube->invertVoxel(&p);
  Asserter::assertEqual(AT(cube->backBuffer, y, z), 0x01 << x, "invertVoxel: should invert the voxel when writing to the back buffer.");
}

void CubeSpec::writePlaneZSpec() {
  unsigned char i, aux, z = 2;
  Voxel v = {ON};
  cube->useFrontBuffer();
  cube->clear();
  cube->writePlaneZ(z, v);
  aux = 0xff;
  for (i = 0; i < Cube::SIZE; i++) {
    aux &= AT(cube->frontBuffer, i, z);
  }
  Asserter::assertEqual(aux, 0xff, "writePlaneZSpec: should write all z axis LEDs.");
}

void CubeSpec::writePlaneYSpec() {
  unsigned char z, aux, y = 3;
  Voxel v = {ON};
  cube->useFrontBuffer();
  cube->clear();
  cube->writePlaneY(y, v);
  aux = 0xff;
  for (z = 0; z < Cube::SIZE; z++) {
    aux &= AT(cube->frontBuffer, y, z);
  }
  Asserter::assertEqual(aux, 0xff, "writePlaneXSpec: should write all y axis LEDs.");
}

void CubeSpec::writePlaneXSpec() {
  unsigned char z, y, aux, x = 3;
  Voxel v = {ON};
  cube->useFrontBuffer();
  cube->clear();
  cube->writePlaneX(x, v);
  aux = 0x01 << x;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      aux |= AT(cube->frontBuffer, y, z) & (0x01 << x);
    }
  }
  Asserter::assertEqual(aux, (0x01 << x), "writePlaneXSpec: should write all x axis LEDs.");
}

void CubeSpec::flipByteSpec() {
  unsigned char b = 0xab;
  Util::flipByte(&b);
  Asserter::assertEqual(b, 0xd5, "flipByteSpec: should flip the byte.");
}

void CubeSpec::mirrorXSpec() {
  unsigned char aux, z, y;
  cube->useFrontBuffer();
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

void CubeSpec::mirrorYSpec() {
  unsigned char aux = 0xaa;
  cube->useFrontBuffer();
  cube->clear();
  AT(cube->frontBuffer, 0, 0) = aux;
  cube->mirrorY();
  Asserter::assertEqual(AT(cube->frontBuffer, Cube::SIZE - 1, 0), aux, "mirrorY: should mirror Y.");
}

void CubeSpec::mirrorZSpec() {
  unsigned char aux = 0xaa;
  cube->useFrontBuffer();
  cube->clear();
  AT(cube->frontBuffer, 0, 0) = aux;
  cube->mirrorZ();
  Asserter::assertEqual(AT(cube->frontBuffer, 0, Cube::SIZE - 1), aux, "mirrorZ: should mirror Z.");
  cube->clear();
  cube->useBackBuffer();
  cube->clear();
  AT(cube->backBuffer, 0, 0) = aux;
  cube->mirrorZ();
  Asserter::assertEqual(AT(cube->frontBuffer, 0, Cube::SIZE - 1), 0, "mirrorZ: should keep frontBuffer empty when using backBuffer when mirroring Z.");
  Asserter::assertEqual(AT(cube->backBuffer, 0, Cube::SIZE - 1), aux, "mirrorZ: should keep frontBuffer empty when using backBuffer when mirroring Z.");
}

void CubeSpec::filledBoxSpec() {
  unsigned char z, y, aux = 0xff;
  Point p0 = Point(0, 0, 0);
  Point p1  = Point(2, 5, 5);
  cube->useFrontBuffer();
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

void CubeSpec::lineSpec() {
  unsigned char z, y, sum = 0;
  Point from = Point(0, 0, 0);
  Point to = Point(7, 7, 7);
  cube->useFrontBuffer();
  cube->clear();
  cube->line(&from, &to);
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      sum += AT(cube->frontBuffer, y, z);
    }
  }
  Asserter::assertEqual(sum, 0xff, "line: should draw a line.");
}

void CubeSpec::shiftOnXSpec() {
  unsigned char x = 0, y = 0, z = 7, aux;
  Point p = Point(x, y, z);
  cube->useFrontBuffer();
  cube->clear();
  cube->turnVoxelOn(&p);
  aux = AT(cube->frontBuffer, y, z);
  cube->shiftOnX(RIGHT);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), Util::rotatingShift(aux, false), "shiftOnXSpec: should shiftOnXSpec RIGHT.");
  aux = AT(cube->frontBuffer, y, z);
  cube->shiftOnX(LEFT);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), Util::rotatingShift(aux, true), "shiftOnXSpec: should shiftOnXSpec LEFT.");
}

void CubeSpec::shiftOnYSpec() {
  cube->useFrontBuffer();
  cube->clear();
  AT(cube->frontBuffer, 7, 0) = 0xff;
  cube->shiftOnY(BACK);
  Asserter::assertEqual(AT(cube->frontBuffer, 7, 0), 0x00, "shiftOnYSpec: should shiftOnYSpec case 1.");
  Asserter::assertEqual(AT(cube->frontBuffer, 6, 0), 0xff, "shiftOnYSpec: should shiftOnYSpec case 2.");
  cube->shiftOnY(FRONT);
  Asserter::assertEqual(AT(cube->frontBuffer, 7, 0), 0xff, "shiftOnYSpec: should shiftOnYSpec case 3.");
  Asserter::assertEqual(AT(cube->frontBuffer, 6, 0), 0x00, "shiftOnYSpec: should shiftOnYSpec case 4.");
}

void CubeSpec::shiftOnZSpec() {
  unsigned char x = 0, y = 0, z = 7;
  Point p = Point(x, y, z);
  cube->useFrontBuffer();
  cube->clear();
  cube->turnVoxelOn(&p);
  cube->shiftOnZ(UP);
  Asserter::assertEqual(AT(cube->frontBuffer, y, (z + 1) % Cube::SIZE), 0x01 << x, "shiftOnZSpec: should shiftOnZSpec UP.");
  cube->shiftOnZ(DOWN);
  Asserter::assertEqual(AT(cube->frontBuffer, y, z), 0x01 << x, "shiftOnZSpec: should shiftOnZSpec UP.");
}
