#include <Drawer.h>

bool Drawer::isInRange(Point *p) {
  if (p->x >=0 && p->x < Cube::SIZE) {
    return true;
  }
  return false;
}

void Drawer::writeVoxel(Point *p, Voxel v) {
  writeVoxel(p, v, DEFAULT_WRITE_TO);
}
  
void Drawer::writeVoxel(Point *p, Voxel v, unsigned char to) {
  unsigned char mask, *c;
  if (isInRange(p)) {
    mask = 1 << p->x;
    c = &(to == WRITE_TO_BUFFER ? Cube::buffer : Cube::cube)[p->z][p->y];
    v.state == Voxel::ON ? set(c, mask) : clr(c, mask);
  }
}
  
void Drawer::turnOnVoxel(Point *p) {
  turnOnVoxel(p, DEFAULT_WRITE_TO);
}

void Drawer::turnOffVoxel(Point *p) {
  turnOffVoxel(p, DEFAULT_WRITE_TO);
}
  
void Drawer::turnOnVoxel(Point *p, unsigned char to) {
  Voxel v = {Voxel::ON};
  writeVoxel(p, v, to);
}

void Drawer::turnOffVoxel(Point *p, unsigned char to) {
  Voxel v = {Voxel::OFF};
  writeVoxel(p, v, to);
}

void Drawer::invertVoxel(Point *p) {
  invertVoxel(p, DEFAULT_WRITE_TO);
}

void Drawer::invertVoxel(Point *p, unsigned char to) {
}

void Drawer::turnOnPlaneZ(unsigned char z) {
  turnOnPlaneZ(z, DEFAULT_WRITE_TO);
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

void Drawer::set(unsigned char *p, unsigned char mask) {
  *p |= mask;
}

void Drawer::clr(unsigned char *p, unsigned char mask) {
  *p &= ~mask;
}
