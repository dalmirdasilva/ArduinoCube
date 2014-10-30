/**
 */
 
#ifndef __ARDUINO_CUBE_DROWER_H__
#define __ARDUINO_CUBE_DROWER_H__ 1

#include <Point.h>
#include <Voxel.h>
#include <Cube.h>
#include <stdbool.h>

class Drawer {
  
public:

  const static unsigned char BUFFER_TARGET = 1;
  const static unsigned char CUBE_TARGET = 0;
  const static unsigned char DEFAULT_TARGET = CUBE_TARGET;
  
  enum Plane {
    AXIS_X = 0x00,
    AXIS_Y = 0x01,
    AXIS_Z = 0x02
  };
  
  
  /**
   * Validates if we the p Point is inside the cube.
   */
  bool isInRange(Point *p) const;
  
  /**
   * See overloaded method.
   */
  void fill() {
    fill(0xff);
  }
  
  /**
   * See overloaded method.
   */
  void fill(unsigned char pattern) {
    fill(pattern, DEFAULT_TARGET);
  }
    
  /**
   * Fill a value into all 64 byts of the cube buffer
   * 
   * Mostly used for clearing. fill(0x00) 
   * or setting all on. fill(0xff)
   */
  void fill(unsigned char pattern, unsigned char target);
  
  /**
   * See overloaded method.
   */
  void clear() {
    clear(DEFAULT_TARGET);
  }
  
  /**
   * See overloaded method.
   */
  void clear(unsigned char target) {
    fill(0x00, target);
  }
  
  /**
   * 
   */ 
  char getBitRange(unsigned char start, unsigned char end);
  
  /**
   * See overloaded method.
   */
  void writeVoxel(Point *p, Voxel v) {
    writeVoxel(p, v, DEFAULT_TARGET);
  }
  
  /**
   * Writes the v Voxel to the cube at p Point. If b == true
   * writes to the backed buffer instead.
   * 
   * @param *p            3D Point pointer
   * @param v             Voxel
   * @param b             Write it to the buffer/cube
   */
  void writeVoxel(Point *p, Voxel v, unsigned char target);
  
  /**
   * See overloaded method.
   */
  void turnOnVoxel(Point *p) {
    turnOnVoxel(p, DEFAULT_TARGET);
  }
  
  /**
   * See overloaded method.
   */
  void turnOffVoxel(Point *p) {
    turnOffVoxel(p, DEFAULT_TARGET);
  }
    
  /**
   * Set voxel to ON
   * 
   * @param p             3D Point pointer
   * @param b             Write it to the buffer/cube
   */
  void turnOnVoxel(Point *p, unsigned char target);
  
  /**
   * Set voxel to OFF
   * 
   * @param p             3D Point pointer
   * @param b             Write it to the buffer/cube
   */
  void turnOffVoxel(Point *p, unsigned char target);
  
  /**
   * See overloaded method
   */
  void invertVoxel(Point *p) {
    invertVoxel(p, DEFAULT_TARGET);
  }
  
  /**
   * Switch volex state
   */
  void invertVoxel(Point *p, unsigned char target);
  
  /**
   * See overloaded method
   */
  void turnOffPlaneZ(unsigned char z) {
    turnOffPlaneZ(z, DEFAULT_TARGET);
  }
  
  /**
   * Turn off plane z.
   */
  void turnOffPlaneZ(unsigned char z, unsigned char target);
  
  /**
   * See overloaded method
   */
  void turnOnPlaneZ(unsigned char z) {
    turnOnPlaneZ(z, DEFAULT_TARGET);
  }
  
  /**
   * Turn on plane z.
   */
  void turnOnPlaneZ(unsigned char z, unsigned char target);
  
  /**
   * See overloaded method.
   */
  void writePlaneZ(unsigned char z, Voxel v) {
    writePlaneZ(z, v, DEFAULT_TARGET);
  }
    
  /**
   * Write plane z.
   */
  void writePlaneZ(unsigned char z, Voxel v, unsigned char target);
  
  /**
   * See overloaded method
   */
  void turnOffPlaneY(unsigned char y) {
    turnOffPlaneY(y, DEFAULT_TARGET);
  }
  
  /**
   * Turn off plane y.
   */
  void turnOffPlaneY(unsigned char y, unsigned char target);
  
  /**
   * See overloaded method
   */
  void turnOnPlaneY(unsigned char y) {
    turnOnPlaneY(y, DEFAULT_TARGET);
  }
  
  /**
   * Turn on plane y.
   */
  void turnOnPlaneY(unsigned char y, unsigned char target);
  
  /**
   * See overloaded method.
   */
  void writePlaneY(unsigned char y, Voxel v) {
    writePlaneY(y, v, DEFAULT_TARGET);
  }
  
  /**
   * Write plane y.
   */
  void writePlaneY(unsigned char y, Voxel v, unsigned char target);
  
  /**
   * See overloaded method
   */
  void turnOffPlaneX(unsigned char x) {
    turnOffPlaneX(x, DEFAULT_TARGET);
  }
  
  /**
   * Turn off plane x.
   */
  void turnOffPlaneX(unsigned char x, unsigned char target);
  
  /**
   * See overloaded method
   */
  void turnOnPlaneX(unsigned char x) {
    turnOnPlaneX(x, DEFAULT_TARGET);
  }
  
  /**
   * Turn on plane x.
   */
  void turnOnPlaneX(unsigned char x, unsigned char target);
  
  /**
   * See overloaded method.
   */
  void writePlaneX(unsigned char x, Voxel v) {
    writePlaneX(x, v, DEFAULT_TARGET);
  }
  
  /**
   * Write plane z.
   */
  void writePlaneX(unsigned char x, Voxel v, unsigned char target);
  
  /**
   * Turn the p plane.
   */
  void writePlane(Plane p, unsigned char pos, Voxel v, unsigned char target);
  
  /**
   * See overloaded method.
   */
  void mirrorX();
  
  /**
   * Flip the cube 180 degrees along the x axis.
   */
  void mirrorX(unsigned char target);
  
  /**
   * See overloaded method.
   */
  void mirrorY();
  
  /**
   * Flip the cube 180 degrees along the y axis.
   */
  void mirrorY(unsigned char target);
  
  /**
   * See overloaded method.
   */
  void mirrorZ();
  
  /**
   * Flip the cube 180 degrees along the z axis.
   */
  void mirrorZ(unsigned char target);
  
  /**
   * Flip a byte
   */
  void flipByte(unsigned char *p);
  
  /**
   * Draw a 3d line
   */
  void line(Point *from, Point *to); 
  
  /**
   * See overloaded method.
   */
  void filledBox(Point *tl, Point *br) {
    filledBox(tl, br, DEFAULT_TARGET);
  }
  
  /**
   * Draws a filled cube.
   */
  void filledBox(Point *tl, Point *br, unsigned char target);
  
  /*
void box_filled(int x1, int y1, int z1, int x2, int y2, int z2);
void box_walls(int x1, int y1, int z1, int x2, int y2, int z2);
void box_wireframe(int x1, int y1, int z1, int x2, int y2, int z2);

void line(int x1, int y1, int z1, int x2, int y2, int z2);
void tmp2cube();
void shift(char axis, int direction);
* */

private:

  /**
   *  Returns a byte with a row of 1's drawn in it.
   * byteLine(2, 5) gives 0b00111100
   */
  unsigned char byteLine(unsigned char start, unsigned char end) {
    return ((0xff << start) & ~(0xff << (end + 1)));
  }

  unsigned char *resolveTarget(unsigned char target, unsigned char x, unsigned char y) {
    return &(target == BUFFER_TARGET ? Cube::buffer : Cube::cube)[x][y];
  }

  void set(unsigned char *p, unsigned char mask) {
    *p |= mask;
  }
  
  void clr(unsigned char *p, unsigned char mask) {
    *p &= ~mask;
  }

  void argOrder(unsigned char *ap, unsigned char *bp);
};

#endif /* __ARDUINO_CUBE_DROWER_H__ */
