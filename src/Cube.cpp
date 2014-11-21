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

void Cube::useBackBuffer(bool use) {
  noInterrupts();
  if (use) {
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
  state == State::ON ? set(&AT(y, z), mask) : clr(&AT(y, z), mask);
}

Voxel Cube::readVoxel(Point *p) {
  Voxel v;
  fitInRange(p);
  v.state =  (AT(p->y, p->z) & (0x01 << p->x)) != 0 ? State::ON : State::OFF;
  return v;
}

void Cube::turnOnVoxel(Point *p) {
  Voxel v = {State::ON};
  writeVoxel(p, v);
}

void Cube::turnOffVoxel(Point *p) {
  Voxel v = {State::OFF};
  writeVoxel(p, v);
}

void Cube::invertVoxel(Point *p) {
  unsigned char mask;
  mask = 0x01 << p->x;
  (AT(p->y, p->z) & mask) ? clr(&AT(p->y, p->z), mask) : set(&AT(p->y, p->z), mask);
}

void Cube::turnOffPlaneZ(unsigned char z) {
  Voxel v = {State::OFF};
  writePlaneZ(z, v);
}

void Cube::turnOnPlaneZ(unsigned char z) {
  Voxel v = {State::ON};
  writePlaneZ(z, v);
}

void Cube::writePlaneZ(unsigned char z, Voxel v) {
  unsigned char pattern;
  z %= Cube::SIZE;
  pattern = (v.state == State::ON) ? 0xff : 0x00;
  memset(&AT(0, z), pattern, Cube::SIZE);
}

void Cube::turnOffPlaneY(unsigned char y) {
  Voxel v = {State::OFF};
  writePlaneY(y, v);
}

void Cube::turnOnPlaneY(unsigned char y) {
  Voxel v = {State::ON};
  writePlaneY(y, v);
}

void Cube::writePlaneY(unsigned char y, Voxel v) {
  unsigned char z;
  y %= Cube::SIZE;
  for (z = 0; z < Cube::SIZE; z++)
    AT(y, z) = (v.state == State::ON) ? 0xff : 0x00;
}

void Cube::turnOffPlaneX(unsigned char x) {
  Voxel v = {State::OFF};
  writePlaneX(x, v);
}

void Cube::turnOnPlaneX(unsigned char x) {
  Voxel v = {State::ON};
  writePlaneX(x, v);
}

void Cube::writePlaneX(unsigned char x, Voxel v) {
  unsigned char z, y, mask;
  mask = 1 << x;
  x %= Cube::SIZE;
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      v.state == State::ON ? set(&AT(y, z), mask) : clr(&AT(y, z), mask);
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
    turnOnVoxel(&p);
  }
}

void Cube::mirrorX() {
  unsigned char y, z, buf[Cube::SIZE][Cube::SIZE];
  memcpy(buf, *bufferToWrite, Cube::BYTE_SIZE);
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      flipByte(&buf[z][y]);
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
  orderArgs(&from->x, &to->x);
  orderArgs(&from->y, &to->y);
  orderArgs(&from->z, &to->z);
  for (z = from->z; z <= to->z; z++) {
    for (y = from->y; y <= to->y; y++) {
      AT(y, z) |= byteLine(from->x, to->x);
    }
  }
}

void Cube::writeSubCube(Point *p, Voxel v, unsigned char size) {
  unsigned char x, y, z;
  x = p->x + size;
  for (z = p->z; z < p->z + size; z++) {
    for (y = p->y; y < p->y + size; y++) {
      AT(z, y) |= byteLine(p->x, x);
    }
  }
}

void Cube::wallBox(Point *from, Point *to) {
  unsigned char z, y, aux;
  orderArgs(&(from->x), &(to->x));
  orderArgs(&(from->y), &(to->y));
  orderArgs(&(from->z), &(to->z));
  for (z = from->z; z <= to->z; z++) {
    for (y = from->y; y <= to->y; y++) {
      if (y == from->y || y == to->y || z == from->z || z == to->z) {
        aux = byteLine(from->x, to->x);
      } else {
        aux |= ((0x01 << from->x) | (0x01 << to->x));
      }
      AT(y, z) = aux;
    }
  }
}

void Cube::wireframeBox(Point *from, Point *to) {
  unsigned char z, y;
  orderArgs(&(from->x), &(to->x));
  orderArgs(&(from->y), &(to->y));
  orderArgs(&(from->z), &(to->z));
  AT(from->y, from->z) = byteLine(from->x, to->x);
  AT(to->y, from->z) = byteLine(from->x, to->x);
  AT(from->y, to->z) = byteLine(from->x, to->x);
  AT(to->y, to->z) = byteLine(from->x, to->x);
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

void Cube::shiftOnX(unsigned char direction) {
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

void Cube::shiftOnY(unsigned char direction) {
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

void Cube::shiftOnZ(unsigned char direction) {
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

void Cube::shift(Axis axis, unsigned char direction) {
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

void Cube::flipByte(unsigned char *p) {
  unsigned char flop = 0x00;
  flop = (flop & 0xfe) | (0x01 & (*p >> 7));
  flop = (flop & 0xfd) | (0x02 & (*p >> 5));
  flop = (flop & 0xfb) | (0x04 & (*p >> 3));
  flop = (flop & 0xf7) | (0x08 & (*p >> 1));
  flop = (flop & 0xef) | (0x10 & (*p << 1));
  flop = (flop & 0xdf) | (0x20 & (*p << 3));
  flop = (flop & 0xbf) | (0x40 & (*p << 5));
  flop = (flop & 0x7f) | (0x80 & (*p << 7));
  *p = flop;
}

void Cube::orderArgs(unsigned char *a, unsigned char *b) {
  if (*a > *b) {
    swapArgs(a, b);
  }
}

void Cube::swapArgs(unsigned char *a, unsigned char *b) {
  unsigned char _ = *b;
  *b = *a;
  *a = _;
}

#endif /* __ARDUINO_CUBE_CUBE_CPP__ */
