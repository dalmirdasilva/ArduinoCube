/**
 */
 
#ifndef __ARDUINO_CUBE_CUBE_H__
#define __ARDUINO_CUBE_CUBE_H__ 1

#define CUBE_SIZE 8
#define CUBE_BYTE_SIZE CUBE_SIZE * CUBE_SIZE
#define LOG2_CUBE_SIZE 7

#include <Point.h>
#include <Voxel.h>

class Cube {

public:
  
  enum Target {
    BUFFER = 0x00,
    CUBE = 0x01
  };
  
  enum Axis {
    AXIS_X = 0x00,
    AXIS_Y = 0x01,
    AXIS_Z = 0x02
  };
  
  enum Direction {
    UP = 0x00,
    DOWN = 0x01,
    LEFT = 0x02,
    RIGHT = 0x04,
    FRONT = 0x08,
    BACK = 0x10
  };
  
  const static unsigned char SIZE = CUBE_SIZE;
  const static unsigned char BYTE_SIZE = CUBE_BYTE_SIZE;
  const static unsigned char DEFAULT_TARGET = Target::CUBE;
  static unsigned char buffer[CUBE_SIZE][CUBE_SIZE];
  static unsigned char cube[CUBE_SIZE][CUBE_SIZE];
  
  /**
   * Validates if we the p Point is inside the cube.
   */
  bool isInRange(Point *p) const;

  /**
   * Fits the point in cube range
   */
  bool fitInRange(Point *p);

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
  void writeVoxel(Point *p, Voxel v, unsigned char target) {
    writeVoxel(p->x, p->y, p->z, v.state, target);
  }
  
  /**
   * 
   */
  void writeVoxel(unsigned char x, unsigned char y, unsigned char z, unsigned char state) {
    writeVoxel(x, y, z, state, DEFAULT_TARGET);
  }
 
  /**
   * 
   */
  void writeVoxel(unsigned char x, unsigned char y, unsigned char z, unsigned char state, unsigned char target);

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
  void writePlane(Axis axis, unsigned char pos, Voxel v, unsigned char target);
  
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
 void line(Point *from, Point *to, unsigned char target); 

  /**
   * Draw a 3d line
   */
  void line(Point *from, Point *to) {
    line(from, to, DEFAULT_TARGET);
  } 
 
  /**
   * See overloaded method.
   */
  void filledBox(Point *from, Point *to) {
    filledBox(from, to, DEFAULT_TARGET);
  }
  
  /**
   * Draws a filled cube.
   */
  void filledBox(Point *from, Point *to, unsigned char target);
  
  /**
   * See overloaded method.
   */
  void wallBox(Point *from, Point *to) {
    wallBox(from, to, DEFAULT_TARGET);
  }

  /**
   *
   */
  void wallBox(Point *from, Point *to, unsigned char target);
 
  /**
   * See overloaded method.
   */
  void wireframeBox(Point *from, Point *to) {
    wireframeBox(from, to, DEFAULT_TARGET);
  }
  
  /**
   *
   */
  void wireframeBox(Point *from, Point *to, unsigned char target);

  /**
   *
   */
  void shift(Axis axis, unsigned char direction, unsigned char target);
  
  /**
   *
   */
  void shiftOnX(unsigned char direction, unsigned char target);
  
  /**
   *
   */
  void shiftOnY(unsigned char direction, unsigned char target); 
  
  /**
   *
   */
  void shiftOnZ(unsigned char direction, unsigned char target);
  
  /**
   * 
   */
  void writeSubCube(Point *p, Voxel v, unsigned char size, unsigned char target);

private:

  /**
   *  Returns a byte with a row of 1's drawn in it.
   * byteLine(2, 5) gives 0b00111100
   */
  unsigned char byteLine(unsigned char start, unsigned char end) {
    return ((0xff << start) & ~(0xff << (end + 1)));
  }

  unsigned char *resolveTarget(unsigned char target, unsigned char z, unsigned char y) {
    return &(target == Target::BUFFER ? Cube::buffer : Cube::cube)[z][y];
  }

  void set(unsigned char *p, unsigned char mask) {
    *p |= mask;
  }
  
  void clr(unsigned char *p, unsigned char mask) {
    *p &= ~mask;
  }

  void orderArgs(unsigned char *a, unsigned char *b);

  void flipArgs(unsigned char *a, unsigned char *b);
};

#endif /* __ARDUINO_CUBE_CUBE_H__ */
