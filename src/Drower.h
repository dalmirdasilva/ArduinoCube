#include "Point.h"

class Drower {
  
  /**
   * Validates if we the p Point is inside the cube.
   */
  bool isInRange(Point *p);
  
  /**
   * 
  char getBitRange(unsigned char start, unsigned char end);
  
  /**
   * See overloaded method.
   */
  void writeVoxel(Point *p, Voxel v) {
    writeVoxel(p, v, 0);
  };
  
  /**
   * Writes the v Voxel to the cube at p Point. If b == true
   * writes to the backed buffer instead.
   * 
   * @param *p            3D Point pointer
   * @param v             Voxel
   * @param b             Write it to the buffer/cube
   */
  void writeVoxel(Point *p, Voxel v, bool b);
  
  /**
   * See overloaded method.
   */
  void turnOnVoxel(Point *p) {
    turnOnVoxel(p, 0);
  }
  
  /**
   * See overloaded method.
   */
  void turnOffVoxel(Point *p) {
    turnOffVoxel(p, 0);
  }
  
  /**
   * Set voxel to ON
   * 
   * @param p             3D Point pointer
   * @param b             Write it to the buffer/cube
   */
  void turnOnVoxel(Point *p, bool b) {
    Voxel v = {ON};
    writeVoxel(p, v, b);
  }
  
  /**
   * Set voxel to OFF
   * 
   * @param p             3D Point pointer
   * @param b             Write it to the buffer/cube
   */
  void turnOffVoxel(Point *p, bool b) {
    Voxel v = {OFF};
    writeVoxel(p, v, b);
  }
  
  /**
   * See overloaded method
   */
  void swicthVoxel(Point *p) {
    swicthVoxel(p, 0);
  }
  
  /**
   * Switch volex state
   */
  void swicthVoxel(Point *p, bool b);
  
  /**
   * See overloaded method
   */
  void turnOnPlaneZ(unsigned char z) {
    turnOnPlaneZ(z, 0);
  }
  
  /**
   * Turn on plane z.
   */
  void turnOnPlaneZ(unsigned char z, bool b) {
    Voxel v = {OFF};
    writePlaneZ(z, v, b);
  }
  
  /**
   * Write plane z.
   */
  void writePlaneZ(unsigned char z, Voxel v, bool b) {
    unsigned char i;
    if (z >= 0 && z < Cube::SIZE) {
      for (i = 0; i < Cube::SIZE; i++) {
        cube[z][i] = (v.state == Voxel::ON) ? 0xff : 0x00;
      }
    }
  }
  
  
  
void setplane_x(int x);
void clrplane_x(int x);
void setplane_y(int y);
void clrplane_y(int y);
void setplane(char axis, unsigned char i);
void clrplane(char axis, unsigned char i);
void fill (unsigned char pattern);
void tmpfill (unsigned char pattern);
void box_filled(int x1, int y1, int z1, int x2, int y2, int z2);
void box_walls(int x1, int y1, int z1, int x2, int y2, int z2);
void box_wireframe(int x1, int y1, int z1, int x2, int y2, int z2);
char flipbyte(char byte);
void line(int x1, int y1, int z1, int x2, int y2, int z2);
void tmp2cube();
void shift(char axis, int direction);
void mirror_y();
void mirror_x();
void mirror_z();
private:

  /**
   * 
   */
  void argOrder(unsigned char a, unsigned char b, unsigned char *ap, unsigned char *bp);
