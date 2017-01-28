/**
 */

#ifndef __ARDUINO_CUBE_CUBE_CPP__
#define __ARDUINO_CUBE_CUBE_CPP__ 1

#include <Cube.h>
#include <Util.h>
#include <Arduino.h>
#include <string.h>

#define AT(y, z) *(*bufferToWrite + ((z * CUBE_SIZE + y) & CUBE_BYTE_SIZE_MASK))

unsigned char Cube::buffer0[CUBE_SIZE][CUBE_SIZE] = {};
unsigned char Cube::buffer1[CUBE_SIZE][CUBE_SIZE] = {};

void Cube::selectBuffer(Buffer buffer) {
  noInterrupts();
  if (buffer == BACK_BUFFER) {
    bufferToWrite = &backBuffer;
  } else {
    bufferToWrite = &frontBuffer;
  }
  interrupts();
}

void Cube::swapBuffers() {
  unsigned char *buf;
  noInterrupts();
  buf = backBuffer;
  backBuffer = frontBuffer;
  frontBuffer = buf;
  interrupts();
}

bool Cube::isInRange(Point *p) const {
  if (p->x < 0 || p->y < 0 || p->z < 0 || p->y >= Cube::SIZE || p->x >= Cube::SIZE || p->z >= Cube::SIZE) {
    return false;
  }
  return true;
}

void Cube::fitInRange(Point *p) {
  p->x &= CUBE_SIZE_MASK;
  p->y &= CUBE_SIZE_MASK;
  p->z &= CUBE_SIZE_MASK;
}

void Cube::fill(unsigned char pattern) {
  memset(*bufferToWrite, pattern, Cube::BYTE_SIZE);
}

void Cube::writeVoxel(unsigned char x, unsigned char y, unsigned char z, unsigned char state) {
  unsigned char mask;
  mask = 1 << x;
  state == ON ? Util::set(&AT(y, z), mask) : Util::clr(&AT(y, z), mask);
}

void Cube::readVoxel(Point *p, Voxel *v) {
  fitInRange(p);
  v->state =  (AT(p->y, p->z) & (0x01 << p->x)) != 0 ? ON : OFF;
}

void Cube::turnVoxelOn(Point *p) {
  Voxel v = {ON};
  writeVoxel(p, v);
}

void Cube::turnVoxelOff(Point *p) {
  Voxel v = {OFF};
  writeVoxel(p, v);
}

void Cube::invertVoxel(Point *p) {
  unsigned char mask;
  mask = 0x01 << p->x;
  (AT(p->y, p->z) & mask) ? Util::clr(&AT(p->y, p->z), mask) : Util::set(&AT(p->y, p->z), mask);
}

void Cube::turnPlaneZOff(unsigned char z) {
  Voxel v = {OFF};
  writePlaneZ(z, v);
}

void Cube::turnPlaneZOn(unsigned char z) {
  Voxel v = {ON};
  writePlaneZ(z, v);
}

void Cube::writePlaneZ(unsigned char z, Voxel v) {
  unsigned char pattern;
  z %= Cube::SIZE;
  pattern = (v.state == ON) ? 0xff : 0x00;
  memset(&AT(0, z), pattern, Cube::SIZE);
}

void Cube::turnPlaneYOff(unsigned char y) {
  Voxel v = {OFF};
  writePlaneY(y, v);
}

void Cube::turnPlaneYOn(unsigned char y) {
  Voxel v = {ON};
  writePlaneY(y, v);
}

void Cube::writePlaneY(unsigned char y, Voxel v) {
  unsigned char z;
  y %= Cube::SIZE;
  for (z = 0; z < Cube::SIZE; z++)
    AT(y, z) = (v.state == ON) ? 0xff : 0x00;
}

void Cube::turnPlaneXOff(unsigned char x) {
  Voxel v = {OFF};
  writePlaneX(x, v);
}

void Cube::turnPlaneXOn(unsigned char x) {
  Voxel v = {ON};
  writePlaneX(x, v);
}

void Cube::writePlaneX(unsigned char x, Voxel v) {
  unsigned char z, y, mask;
  mask = 1 << x;
  x %= Cube::SIZE;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      v.state == ON ? Util::set(&AT(y, z), mask) : Util::clr(&AT(y, z), mask);
    }
  }
}

void Cube::writePlane(Axis axis, unsigned char pos, Voxel v) {
  switch(axis) {
    case AXIS_X:
      writePlaneX(pos, v);
      break;
    case AXIS_Y:
      writePlaneY(pos, v);
      break;
    case AXIS_Z:
      writePlaneZ(pos, v);
      break;
  }
}

void Cube::line(Point *from, Point *to) {
  float ySteps, zSteps;
  Point p;
  if (from->x > to->x) {
	  Point *aux = from;
	  from = to;
	  to = aux;
  }
  if (from->y > to->y) {
    ySteps = (float) (from->y - to->y) / (float) (to->x - from->x);
  } else {
    ySteps = (float) (to->y - from->y) / (float) (to->x - from->x);
  }
  if (from->z > to->z) {
    zSteps = (float) (from->z - to->z) / (float) (to->x - from->x);
  } else {
    zSteps = (float) (to->z - from->z) / (float) (to->x - from->x);
  }
  for (p.x = from->x; p.x <= to->x; p.x++) {
    p.y = (ySteps * (p.x - from->x)) + from->y;
    p.z = (zSteps * (p.x - from->x)) + from->z;
    turnVoxelOn(&p);
  }
}

void Cube::mirrorX() {
  unsigned char y, z, buf[Cube::SIZE][Cube::SIZE];
  memcpy(buf, *bufferToWrite, Cube::BYTE_SIZE);
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      Util::flipByte(&buf[z][y]);
    }
  }
  memcpy(*bufferToWrite, buf, Cube::BYTE_SIZE);
}

void Cube::mirrorY() {
  unsigned char i, j, z, buf[Cube::SIZE][Cube::SIZE];
  memcpy(buf, *bufferToWrite, Cube::BYTE_SIZE);
  clear();
  for (z = 0; z < Cube::SIZE; z++) {
    for (i = 0, j = Cube::SIZE - 1; i < Cube::SIZE; i++, j--) {
      AT(i, z) = buf[z][j];
    }
  }
}

void Cube::mirrorZ() {
  unsigned char i, j, y, buf[Cube::SIZE][Cube::SIZE];
  memcpy(buf, *bufferToWrite, Cube::BYTE_SIZE);
  clear();
  for (i = 0, j = Cube::SIZE - 1; i < Cube::SIZE; i++, j--) {
    for (y = 0; y < Cube::SIZE; y++) {
      AT(y, i) = buf[j][y];
    }
  }
}

void Cube::filledBox(Point *from, Point *to) {
  unsigned char z, y;
  Util::orderArgs(&from->x, &to->x);
  Util::orderArgs(&from->y, &to->y);
  Util::orderArgs(&from->z, &to->z);
  for (z = from->z; z <= to->z; z++) {
    for (y = from->y; y <= to->y; y++) {
      AT(y, z) |= Util::byteLine(from->x, to->x);
    }
  }
}

void Cube::writeSubCube(Point *p, Voxel v, unsigned char size) {
  unsigned char x, y, z;
  x = p->x + size;
  for (z = p->z; z < p->z + size; z++) {
    for (y = p->y; y < p->y + size; y++) {
      AT(z, y) |= Util::byteLine(p->x, x);
    }
  }
}

void Cube::wallBox(Point *from, Point *to) {
  unsigned char z, y, aux = 0;
  Util::orderArgs(&(from->x), &(to->x));
  Util::orderArgs(&(from->y), &(to->y));
  Util::orderArgs(&(from->z), &(to->z));
  for (z = from->z; z <= to->z; z++) {
    for (y = from->y; y <= to->y; y++) {
      if (y == from->y || y == to->y || z == from->z || z == to->z) {
        aux = Util::byteLine(from->x, to->x);
      } else {
        aux |= ((0x01 << from->x) | (0x01 << to->x));
      }
      AT(y, z) = aux;
    }
  }
}

void Cube::wireframeBox(Point *from, Point *to) {
  unsigned char z, y;
  Util::orderArgs(&(from->x), &(to->x));
  Util::orderArgs(&(from->y), &(to->y));
  Util::orderArgs(&(from->z), &(to->z));
  AT(from->y, from->z) = Util::byteLine(from->x, to->x);
  AT(to->y, from->z) = Util::byteLine(from->x, to->x);
  AT(from->y, to->z) = Util::byteLine(from->x, to->x);
  AT(to->y, to->z) = Util::byteLine(from->x, to->x);
  for (y = from->y; y <= to->y; y++) {
    writeVoxel(from->x, y, from->z, ON);
    writeVoxel(from->x, y, to->z, ON);
    writeVoxel(to->x, y, from->z, ON);
    writeVoxel(to->x, y, to->z, ON);
  }
  for (z = from->z; z <= to->z; z++) {
    writeVoxel(from->x, from->y, z, ON);
    writeVoxel(from->x, to->y, z, ON);
    writeVoxel(to->x, from->y, z, ON);
    writeVoxel(to->x, to->y, z, ON);
  }
}

void Cube::shiftOnX(Direction direction) {
  unsigned char y, z, aux;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      aux = AT(z, y);
      if (direction == LEFT) {
        AT(z, y) <<= 1;
        AT(z, y) |= aux >> 7;
      } else {
        AT(z, y) >>= 1;
        AT(z, y) |= aux << 7;
      }
    }
  }
}

void Cube::shiftOnY(Direction direction) {
  unsigned char z, *b, buf[Cube::SIZE][Cube::SIZE];
  bool isFront;
  isFront = (direction == FRONT);
  b = &(buf[0][0]);
  memcpy(b, *bufferToWrite, Cube::BYTE_SIZE);
  for (z = 0; z < Cube::SIZE; z++) {
    AT((isFront ? 0 : Cube::SIZE - 1), z) = buf[z][(isFront ? Cube::SIZE - 1 : 0)];
    memcpy(
      *bufferToWrite + (z * Cube::SIZE) + (isFront ? 1 : 0),
      b + (z * Cube::SIZE) + (isFront ? 0 : 1),
      Cube::SIZE - 1
    );
  }
}

void Cube::shiftOnZ(Direction direction) {
  unsigned char z, k, *p, *first, *last, *src, *dst, aux[Cube::SIZE];
  first = *bufferToWrite;
  last = *bufferToWrite + (Cube::BYTE_SIZE - Cube::SIZE);
  p = (direction == UP) ? last : first;
  memcpy(aux, p, Cube::SIZE);
  for (z = 0, k = Cube::SIZE - 1; z < Cube::SIZE - 1; z++, k--) {
    dst = (direction == UP) ? (*bufferToWrite + Cube::SIZE * k) : (*bufferToWrite + Cube::SIZE * z);
    src = (direction == UP) ? dst - Cube::SIZE : dst + Cube::SIZE;
    memcpy(dst, src, Cube::SIZE);
  }
  p = (direction == UP) ? first : last;
  memcpy(p, aux, Cube::SIZE);
}

void Cube::shift(Axis axis, Direction direction) {
  switch(axis) {
    case AXIS_X:
      shiftOnX(direction);
      break;
    case AXIS_Y:
      shiftOnY(direction);
      break;
    case AXIS_Z:
      shiftOnZ(direction);
      break;
  }
}

#endif /* __ARDUINO_CUBE_CUBE_CPP__ */
