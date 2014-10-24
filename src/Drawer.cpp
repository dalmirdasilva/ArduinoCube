#include <Drawer.h>

bool Drawer::isInRange(Point *p) const {
  if (p->x < 0 || p->y < 0 || p->z < 0 || p->y >= Cube::SIZE || p->x >= Cube::SIZE || p->z >= Cube::SIZE) {
    return false;
  }
  return true;
}

void Drawer::writeVoxel(Point *p, Voxel v, unsigned char to) {
  unsigned char mask, *c;
  if (isInRange(p)) {
    mask = 1 << p->x;
    c = &(to == WRITE_TO_BUFFER ? Cube::buffer : Cube::cube)[p->z][p->y];
    v.state == Voxel::ON ? set(c, mask) : clr(c, mask);
  }
}
  
void Drawer::turnOnVoxel(Point *p, unsigned char to) {
  Voxel v = {Voxel::ON};
  writeVoxel(p, v, to);
}

void Drawer::turnOffVoxel(Point *p, unsigned char to) {
  Voxel v = {Voxel::OFF};
  writeVoxel(p, v, to);
}

void Drawer::invertVoxel(Point *p, unsigned char to) {
  unsigned char mask, *c = &(to == WRITE_TO_BUFFER ? Cube::buffer : Cube::cube)[p->z][p->y];
  mask = 0x01 << p->x;
  if (*c & mask) {
    *c &= ~mask;
  } else {
    *c |= mask;
  }
}

void Drawer::turnOffPlaneZ(unsigned char z, unsigned char to) {
  Voxel v = {Voxel::OFF};
  writePlaneZ(z, v, to);
}

void Drawer::turnOnPlaneZ(unsigned char z, unsigned char to) {
  Voxel v = {Voxel::ON};
  writePlaneZ(z, v, to);
}

void Drawer::writePlaneZ(unsigned char z, Voxel v, unsigned char to) {
  unsigned char i, *p = &(to == WRITE_TO_BUFFER ? Cube::buffer : Cube::cube)[0][0];
  if (z >= 0 && z < Cube::SIZE) {
    for (i = 0; i < Cube::SIZE; i++) {
      *(p + (Cube::SIZE * z + i)) = (v.state == Voxel::ON) ? 0xff : 0x00;
    }
  }
}

void Drawer::turnOffPlaneY(unsigned char y, unsigned char to) {
  Voxel v = {Voxel::OFF};
  writePlaneY(y, v, to);
}

void Drawer::turnOnPlaneY(unsigned char y, unsigned char to) {
  Voxel v = {Voxel::ON};
  writePlaneY(y, v, to);
}

void Drawer::writePlaneY(unsigned char y, Voxel v, unsigned char to) {
  unsigned char i, *p = &(to == WRITE_TO_BUFFER ? Cube::buffer : Cube::cube)[0][0];
  if (y >= 0 && y < Cube::SIZE) {
    for (i = 0; i < Cube::SIZE; i++) {
      *(p + (Cube::SIZE * i + y)) = (v.state == Voxel::ON) ? 0xff : 0x00;
    }
  }
}

void Drawer::turnOffPlaneX(unsigned char x, unsigned char to) {
  Voxel v = {Voxel::OFF};
  writePlaneX(x, v, to);
}

void Drawer::turnOnPlaneX(unsigned char x, unsigned char to) {
  Voxel v = {Voxel::ON};
  writePlaneX(x, v, to);
}

void Drawer::writePlaneX(unsigned char x, Voxel v, unsigned char to) {
  unsigned char z, y, mask, *p;
  mask = 1 << x;
  if (x >= 0 && x < Cube::SIZE) {
    for (z = 0; z < Cube::SIZE; z++) {
      for (y = 0; y < Cube::SIZE; y++) {
        p = &(to == WRITE_TO_BUFFER ? Cube::buffer : Cube::cube)[z][y];
        v.state == Voxel::ON ? set(p, mask) : clr(p, mask);
      }
    }
  }
}

void Drawer::mirrorX(unsigned char to) {
  unsigned char y, z, *p = &(to == WRITE_TO_BUFFER ? Cube::buffer : Cube::cube)[0][0];
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      flipByte(p + (Cube::SIZE * z + y));
    }
  }
}

void Drawer::mirrorY(unsigned char to) {
}

void Drawer::mirrorZ(unsigned char to) {
}

void Drawer::flipByte(unsigned char *p) {
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
