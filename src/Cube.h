/**
 * Cube class
 */
 
#ifndef __ARDUINO_CUBE_CUBE_H__
#define __ARDUINO_CUBE_CUBE_H__ 1

#define CUBE_SIZE 8
#define CUBE_BYTE_SIZE CUBE_SIZE * CUBE_SIZE
#define CUBE_SIZE_MASK 7

#include <Point.h>
#include <Voxel.h>

class Cube {

  static unsigned char buffer0[CUBE_SIZE][CUBE_SIZE];
  static unsigned char buffer1[CUBE_SIZE][CUBE_SIZE];
  unsigned char **bufferToWrite;

public:
  
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
  static unsigned char *frontBuffer;
  static unsigned char *backBuffer;

  Cube() {
    bufferToWrite = &frontBuffer;
  }

  /**
   * Set if will use back or front buffer to write.
   */
  void useBackBuffer(bool use);

  /**
   * Validates if we the p Point is inside the cube.
   */
  bool isInRange(Point *p) const;

  /**
   * Fits the point in cube range
   */
  void fitInRange(Point *p);

  /**
   * Fills the current buffer.
   */
  void fill() {
    fill(0xff);
  }

  /**
   * Cleans the current buffer.
   */
  void clear() {
    fill(0x00);
  }
    
  /**
   * Fill a value into all 64 bytes of the cube buffer
   * 
   * Mostly used for clearing. fill(0x00) 
   * or setting all on. fill(0xff)
   */
  void fill(unsigned char pattern);
  
  /**
   * Writes the v Voxel to the cube at p Point. If b == true
   * writes to the backed buffer instead.
   * 
   * @param *p            3D Point pointer
   * @param v             Voxel
   * @param b             Write it to the buffer/cube
   */
  void writeVoxel(Point *p, Voxel v) {
    writeVoxel(p->x, p->y, p->z, v.state);
  }
  
  /**
   * 
   */
  void writeVoxel(unsigned char x, unsigned char y, unsigned char z, unsigned char state);

  /**
   * Set voxel to ON
   * 
   * @param p             3D Point pointer
   */
  void turnOnVoxel(Point *p);
  
  /**
   * Set voxel to OFF
   * 
   * @param p             3D Point pointer
   */
  void turnOffVoxel(Point *p);
  
  /**
   * Switch volex state
   */
  void invertVoxel(Point *p);

  /**
   * Turn off plane z.
   */
  void turnOffPlaneZ(unsigned char z);
  
  /**
   * Turn on plane z.
   */
  void turnOnPlaneZ(unsigned char z);

  /**
   * Write plane z.
   */
  void writePlaneZ(unsigned char z, Voxel v);
  
  /**
   * Turn off plane y.
   */
  void turnOffPlaneY(unsigned char y);
  
  /**
   * Turn on plane y.
   */
  void turnOnPlaneY(unsigned char y);
  
  /**
   * Write plane y.
   */
  void writePlaneY(unsigned char y, Voxel v);
  
  /**
   * Turn off plane x.
   */
  void turnOffPlaneX(unsigned char x);
  
  /**
   * Turn on plane x.
   */
  void turnOnPlaneX(unsigned char x);
  
  /**
   * Write plane x.
   */
  void writePlaneX(unsigned char x, Voxel v);
  
  /**
   * Turn the p plane.
   */
  void writePlane(Axis axis, unsigned char pos, Voxel v);
  
  /**
   * Flip the cube 180 degrees along the x axis.
   */
  void mirrorX();

  /**
   * Flip the cube 180 degrees along the y axis.
   */
  void mirrorY();
  
  /**
   * Flip the cube 180 degrees along the z axis.
   */
  void mirrorZ();
  
  /**
   * Flip a byte
   */
  void flipByte(unsigned char *p);
 
 /**
  * Draw a 3d line
  */
 void line(Point *from, Point *to);
 
  /**
   * Draws a filled cube.
   */
  void filledBox(Point *from, Point *to);
  
  /**
   *
   */
  void wallBox(Point *from, Point *to);
 
  /**
   *
   */
  void wireframeBox(Point *from, Point *to);

  /**
   *
   */
  void shift(Axis axis, unsigned char direction);

  /**
   *
   */
  void shiftOnX(unsigned char direction);

  /**
   *
   */
  void shiftOnY(unsigned char direction);
  
  /**
   *
   */
  void shiftOnZ(unsigned char direction);
  
  /**
   * 
   */
  void writeSubCube(Point *p, Voxel v, unsigned char size);

  /**
   * Swap the buffers. Current buffer becomes backed buffer and vice-versa.
   */
  void swapBuffers();

private:

  /**
   * Returns a byte with a row of 1's drawn in it.
   * byteLine(2, 5) gives 0b00111100
   */
  unsigned char byteLine(unsigned char start, unsigned char end) {
    return ((0xff << start) & ~(0xff << (end + 1)));
  }

  void set(unsigned char *p, unsigned char mask) {
    *p |= mask;
  }
  
  void clr(unsigned char *p, unsigned char mask) {
    *p &= ~mask;
  }

  void orderArgs(unsigned char *a, unsigned char *b);

  /**
   * Swap args
   */
  void swapArgs(unsigned char *a, unsigned char *b);
};

#endif /* __ARDUINO_CUBE_CUBE_H__ */
