#include <Drawer.h>
#include <Util.h>
#include <string.h>

#define AT(y, z) *(t + ((z) * Cube::SIZE) + (y))

bool Drawer::isInRange(Point *p) const {
  if (p->x < 0 || p->y < 0 || p->z < 0 || p->y >= Cube::SIZE || p->x >= Cube::SIZE || p->z >= Cube::SIZE)
    return false;
  return true;
}

void Drawer::fill(unsigned char pattern, unsigned char target) {
  unsigned char z, y, *t;
  t = resolveTarget(target, 0, 0);
  for (z = 0; z < Cube::SIZE; z++)
    for (y = 0; y < Cube::SIZE; y++)
      *(t + (Cube::SIZE * z + y)) = pattern;
}

void Drawer::writeVoxel(unsigned char x, unsigned char y, unsigned char z, unsigned char state, unsigned char target) {
  unsigned char mask, *t;
  mask = 1 << x;
  t = resolveTarget(target, z, y);
  state == VoxelState::ON ? set(t, mask) : clr(t, mask);
}
  
void Drawer::turnOnVoxel(Point *p, unsigned char target) {
  Voxel v = {VoxelState::ON};
  writeVoxel(p, v, target);
}

void Drawer::turnOffVoxel(Point *p, unsigned char target) {
  Voxel v = {VoxelState::OFF};
  writeVoxel(p, v, target);
}

void Drawer::invertVoxel(Point *p, unsigned char target) {
  unsigned char mask, *c = &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[p->z][p->y];
  mask = 0x01 << p->x;
  (*c & mask) ? clr(c, mask) : set(c, mask);
}

void Drawer::turnOffPlaneZ(unsigned char z, unsigned char target) {
  Voxel v = {VoxelState::OFF};
  writePlaneZ(z, v, target);
}

void Drawer::turnOnPlaneZ(unsigned char z, unsigned char target) {
  Voxel v = {VoxelState::ON};
  writePlaneZ(z, v, target);
}

void Drawer::writePlaneZ(unsigned char z, Voxel v, unsigned char target) {
  unsigned char i, *p = &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[0][0];
  if (z >= 0 && z < Cube::SIZE)
    for (i = 0; i < Cube::SIZE; i++)
      *(p + (Cube::SIZE * z + i)) = (v.state == VoxelState::ON) ? 0xff : 0x00;
}

void Drawer::turnOffPlaneY(unsigned char y, unsigned char target) {
  Voxel v = {VoxelState::OFF};
  writePlaneY(y, v, target);
}

void Drawer::turnOnPlaneY(unsigned char y, unsigned char target) {
  Voxel v = {VoxelState::ON};
  writePlaneY(y, v, target);
}

void Drawer::writePlaneY(unsigned char y, Voxel v, unsigned char target) {
  unsigned char i, *t = &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[0][0];
  if (y >= 0 && y < Cube::SIZE)
    for (i = 0; i < Cube::SIZE; i++)
      AT(y, i) = (v.state == VoxelState::ON) ? 0xff : 0x00;
}

void Drawer::turnOffPlaneX(unsigned char x, unsigned char target) {
  Voxel v = {VoxelState::OFF};
  writePlaneX(x, v, target);
}

void Drawer::turnOnPlaneX(unsigned char x, unsigned char target) {
  Voxel v = {VoxelState::ON};
  writePlaneX(x, v, target);
}

void Drawer::writePlaneX(unsigned char x, Voxel v, unsigned char target) {
  unsigned char z, y, mask, *t;
  mask = 1 << x;
  if (x >= 0 && x < Cube::SIZE)
    for (z = 0; z < Cube::SIZE; z++)
      for (y = 0; y < Cube::SIZE; y++) {
        t = resolveTarget(target, z, y);
        v.state == VoxelState::ON ? set(t, mask) : clr(t, mask);
      }
}

void Drawer::writePlane(Axis p, unsigned char pos, Voxel v, unsigned char target) {
  switch(p) {
    case AXIS_X:
      writePlaneX(pos, v, target);
      break;
    case AXIS_Y:
      writePlaneY(pos, v, target);
      break;
    case AXIS_Z:
      writePlaneZ(pos, v, target);
      break;
  }
}

void Drawer::line(Point *from, Point *to, unsigned char target) {
  float ySteps;
  float zSteps;
  Point p;
  if (from->x > to->x) {
	  Point *aux = from;
	  from = to;
	  to = aux;
  }
  if (from->y > to->y)
    ySteps = (float) (from->y - to->y) / (float) (to->x - from->x);
  else
    ySteps = (float) (to->y - from->y) / (float) (to->x - from->x);

  if (from->z > to->z)
    zSteps = (float) (from->z - to->z) / (float) (to->x - from->x);
  else
    zSteps = (float) (to->z - from->z) / (float) (to->x - from->x);

  for (p.x = from->x; p.x <= to->x; p.x++) {
    p.y = (zSteps * (p.x - from->x)) + from->y;
    p.z = (zSteps * (p.x - from->x)) + from->z;
    turnOnVoxel(&p, target);
  }
}

void Drawer::mirrorX(unsigned char target) {
  unsigned char y, z, *t, buf[Cube::SIZE][Cube::SIZE];
  t = resolveTarget(target, 0, 0);
  memcpy(buf, t, Cube::BYTE_SIZE);
  for (z = 0; z < Cube::SIZE; z++)
    for (y = 0; y < Cube::SIZE; y++)
      flipByte(&buf[z][y]);

  memcpy(t, buf, Cube::BYTE_SIZE);
}

void Drawer::mirrorY(unsigned char target) {
  unsigned char i, j, z, *t, buf[Cube::SIZE][Cube::SIZE];
  t = resolveTarget(target, 0, 0);
  memcpy(buf, t, Cube::BYTE_SIZE);
  clear(target);
  for (z = 0; z < Cube::SIZE; z++)
    for (i = 0, j = Cube::SIZE - 1; i < Cube::SIZE; i++, j--)
      AT(i, z) = buf[z][j];
}

void Drawer::mirrorZ(unsigned char target) {
  unsigned char i, j, y, *t, buf[Cube::SIZE][Cube::SIZE];
  t = resolveTarget(target, 0, 0);
  memcpy(buf, t, Cube::BYTE_SIZE);
  clear(target);
  for (i = 0, j = Cube::SIZE - 1; i < Cube::SIZE; i++, j--)
    for (y = 0; y < Cube::SIZE; y++)
      AT(y, i) = buf[j][y];
}

void Drawer::filledBox(Point *from, Point *to, unsigned char target) {
  unsigned char z, y, *t;
  t = resolveTarget(target, 0, 0);
  orderArgs(&from->x, &to->x);
  orderArgs(&from->y, &to->y);
  orderArgs(&from->z, &to->z);
  for (z = from->z; z <= to->z; z++)
    for (y = from->y; y <= to->y; y++)
      AT(y, z) |= byteLine(from->x, to->x);
}


void Drawer::wallBox(Point *from, Point *to, unsigned char target) {
  unsigned char z, y, aux, *t;
  orderArgs(&(from->x), &(to->x));
  orderArgs(&(from->y), &(to->y));
  orderArgs(&(from->z), &(to->z));
  t = resolveTarget(target, 0, 0);
  for (z = from->z; z <= to->z; z++)
    for (y = from->y; y <= to->y; y++) {
      if (y == from->y || y == to->y || z == from->z || z == to->z)
        aux = byteLine(from->x, to->x);
      else
        aux |= ((0x01 << from->x) | (0x01 << to->x));
      
      AT(y, z) = aux;
    }
}

void Drawer::wireframeBox(Point *from, Point *to, unsigned char target) {
  unsigned char z, y, *t;
  orderArgs(&(from->x), &(to->x));
  orderArgs(&(from->y), &(to->y));
  orderArgs(&(from->z), &(to->z));
  t = resolveTarget(target, 0, 0);
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

void Drawer::shiftOnZ(unsigned char direction) {
  unsigned char y, z, aux, *t;
  t = resolveTarget(target, 0, 0)
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      aux = AT(z, y);
      if (direction == 0) {
        AT(z, y) <<= 1;
        AT(z, y) |= aux >> 7;
      } else {
        AT(z, y) >>= 1;
        AT(z, y) |= aux << 7;
      }
    }
  }
}

void Drawer::shiftOnX(unsigned char direction) {
  unsigned char y, z, aux, *t;
  t = resolveTarget(target, 0, 0)
  for (z = 0; z < Cube::SIZE; z++) {
    for (y = 0; y < Cube::SIZE; y++) {
      aux = AT(z, y);
      if (direction == 0) {
        AT(z, y) <<= 1;
        AT(z, y) |= aux >> 7;
      } else {
        AT(z, y) >>= 1;
        AT(z, y) |= aux << 7;
      }
    }
  }
}

void Drawer::shift(Axis axis, unsigned char direction, unsigned char target) {
  /*
  unsigned char x, y, i, j, k, state, *t;
  t = resolveTarget(target, 0, 0)
  for (i = 0; i < CUBE_SIZE; i++) {
    if (direction == -1) {
      j = i;
    } else {
      j = (7 - i);
    }
    
    for (x = 0; x < CUBE_SIZE; x++) {
      for (y = 0; y < CUBE_SIZE; y++) {
        if (direction == -1) {
          k = j + 1;
        } else {
          k = j - 1;
        }
        if (axis == AXIS_Z) {
          state = (*(t + (k + Cube::SIZE) + y) & (0x01 << x)) != 0;
          *(t + (j + Cube::SIZE) + y) |= state;
        }
        if (axis == AXIS_Y) {
          state = (*(t + (y + Cube::SIZE) + k) & (0x01 << x)) != 0;
          *(t + (y + Cube::SIZE) + j) |= state;
        }
        if (axis == AXIS_X) {
          state = (*(t + (x + Cube::SIZE) + y) & (0x01 << k)) != 0;
          *(t + (x + Cube::SIZE) + y) |= state;

          state = getvoxel(k, y, x);
          altervoxel(j, y, x, state);
        }

        state = (*(t + (k + Cube::SIZE) + y) & (0x01 << x)) != 0;
        *(t + (j + Cube::SIZE) + y) |= state;

      }
    }
    
  }

  if (direction == -1) {
      i = 7;
  } else {
      i = 0;
  }

  for (x = 0; x < CUBE_SIZE; x++) {
      for (y = 0; y < CUBE_SIZE; y++) {
          if (axis == AXIS_Z) {
              clrvoxel(x, y, i);
          }
          if (axis == AXIS_Y) {
              clrvoxel(x, i, y);
          }
          if (axis == AXIS_X) {
              clrvoxel(i, y, x);
          }
      }
  }*/
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

void Drawer::orderArgs(unsigned char *a, unsigned char *b) {
  if (*a > *b) {
	flipArgs(a, b);
  }
}


void Drawer::flipArgs(unsigned char *a, unsigned char *b) {
  unsigned char tmp = *b;
  *b = *a;
  *a = tmp;
}
