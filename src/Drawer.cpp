#include <Drawer.h>
#include <string.h>

bool Drawer::isInRange(Point *p) const {
  if (p->x < 0 || p->y < 0 || p->z < 0 || p->y >= Cube::SIZE || p->x >= Cube::SIZE || p->z >= Cube::SIZE) {
    return false;
  }
  return true;
}

void Drawer::fill(unsigned char pattern, unsigned char target) {
  unsigned char z, y, *t;
  t = resolveTarget(target, 0, 0);
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      *(t + (Cube::SIZE * z + y)) = pattern;
    }
  }
}

void Drawer::writeVoxel(Point *p, Voxel v, unsigned char target) {
  unsigned char mask, *c;
  if (isInRange(p)) {
    mask = 1 << p->x;
    c = &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[p->z][p->y];
    v.state == Voxel::ON ? set(c, mask) : clr(c, mask);
  }
}
  
void Drawer::turnOnVoxel(Point *p, unsigned char target) {
  Voxel v = {Voxel::ON};
  writeVoxel(p, v, target);
}

void Drawer::turnOffVoxel(Point *p, unsigned char target) {
  Voxel v = {Voxel::OFF};
  writeVoxel(p, v, target);
}

void Drawer::invertVoxel(Point *p, unsigned char target) {
  unsigned char mask, *c = &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[p->z][p->y];
  mask = 0x01 << p->x;
  (*c & mask) ? clr(c, mask) : set(c, mask);
}

void Drawer::turnOffPlaneZ(unsigned char z, unsigned char target) {
  Voxel v = {Voxel::OFF};
  writePlaneZ(z, v, target);
}

void Drawer::turnOnPlaneZ(unsigned char z, unsigned char target) {
  Voxel v = {Voxel::ON};
  writePlaneZ(z, v, target);
}

void Drawer::writePlaneZ(unsigned char z, Voxel v, unsigned char target) {
  unsigned char i, *p = &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[0][0];
  if (z >= 0 && z < Cube::SIZE) {
    for (i = 0; i < Cube::SIZE; i++) {
      *(p + (Cube::SIZE * z + i)) = (v.state == Voxel::ON) ? 0xff : 0x00;
    }
  }
}

void Drawer::turnOffPlaneY(unsigned char y, unsigned char target) {
  Voxel v = {Voxel::OFF};
  writePlaneY(y, v, target);
}

void Drawer::turnOnPlaneY(unsigned char y, unsigned char target) {
  Voxel v = {Voxel::ON};
  writePlaneY(y, v, target);
}

void Drawer::writePlaneY(unsigned char y, Voxel v, unsigned char target) {
  unsigned char i, *p = &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[0][0];
  if (y >= 0 && y < Cube::SIZE) {
    for (i = 0; i < Cube::SIZE; i++) {
      *(p + (Cube::SIZE * i + y)) = (v.state == Voxel::ON) ? 0xff : 0x00;
    }
  }
}

void Drawer::turnOffPlaneX(unsigned char x, unsigned char target) {
  Voxel v = {Voxel::OFF};
  writePlaneX(x, v, target);
}

void Drawer::turnOnPlaneX(unsigned char x, unsigned char target) {
  Voxel v = {Voxel::ON};
  writePlaneX(x, v, target);
}

void Drawer::writePlaneX(unsigned char x, Voxel v, unsigned char target) {
  unsigned char z, y, mask, *t;
  mask = 1 << x;
  if (x >= 0 && x < Cube::SIZE) {
    for (z = 0; z < Cube::SIZE; z++) {
      for (y = 0; y < Cube::SIZE; y++) {
        t = resolveTarget(target, z, y);
        v.state == Voxel::ON ? set(t, mask) : clr(t, mask);
      }
    }
  }
}

void Drawer::mirrorX(unsigned char target) {
  unsigned char y, z, *t, buf[Cube::SIZE][Cube::SIZE];
  t = resolveTarget(target, 0, 0);
  memcpy(buf, t, Cube::BYTE_SIZE);
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      flipByte(&buf[z][y]);
    }
  }
  memcpy(t, buf, Cube::BYTE_SIZE);
}

void Drawer::mirrorY(unsigned char target) {
  unsigned char x, y, z, *t, buf[Cube::SIZE][Cube::SIZE];
  Point p;
  t = resolveTarget(target, 0, 0);
  memcpy(buf, t, Cube::BYTE_SIZE);
  clear(target);
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      for (x = 0; x < Cube::SIZE; x++) {
        if (buf[z][y] & (0x01 << x)) {
          p.x = x;
          p.y = Cube::SIZE - 1 - y;
          p.z = z;
          turnOnVoxel(&p, target);
        }
      }
    }
  }
}

void Drawer::mirrorZ(unsigned char target) {
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
