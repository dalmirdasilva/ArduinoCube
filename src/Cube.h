/**
 * Cube class
 */
 
#ifndef __ARDUINO_CUBE_CUBE_H__
#define __ARDUINO_CUBE_CUBE_H__ 1

#define CUBE_SIZE 0x08
#define CUBE_BYTE_SIZE CUBE_SIZE * CUBE_SIZE
#define CUBE_SIZE_MASK 0x07
#define CUBE_BYTE_SIZE_MASK 0x3f

#include <Point.h>
#include <Voxel.h>

class Cube {

  static unsigned char buffer0[CUBE_SIZE][CUBE_SIZE];
  static unsigned char buffer1[CUBE_SIZE][CUBE_SIZE];
  unsigned char **bufferToWrite;

public:

  const static unsigned char SIZE = CUBE_SIZE;
  const static unsigned char BYTE_SIZE = CUBE_BYTE_SIZE;
  unsigned char *frontBuffer;
  unsigned char *backBuffer;

  Cube() {
    frontBuffer = &buffer0[0][0];
    backBuffer = &buffer1[0][0];
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
  void turnVoxelOn(Point *p);

  /**
   * Get Voxel
   *
   * @param p             3D Point pointer
   */
  void readVoxel(Point *p, Voxel *v);
  
  /**
   * Set voxel to OFF
   * 
   * @param p             3D Point pointer
   */
  void turnVoxelOff(Point *p);
  
  /**
   * Switch volex state
   */
  void invertVoxel(Point *p);

  /**
   * Turn off plane z.
   */
  void turnPlaneZOff(unsigned char z);
  
  /**
   * Turn on plane z.
   */
  void turnPlaneZOn(unsigned char z);

  /**
   * Write plane z.
   */
  void writePlaneZ(unsigned char z, Voxel v);
  
  /**
   * Turn off plane y.
   */
  void turnPlaneYOff(unsigned char y);
  
  /**
   * Turn on plane y.
   */
  void turnPlaneYOn(unsigned char y);
  
  /**
   * Write plane y.
   */
  void writePlaneY(unsigned char y, Voxel v);
  
  /**
   * Turn off plane x.
   */
  void turnPlaneXOff(unsigned char x);
  
  /**
   * Turn on plane x.
   */
  void turnPlaneXOn(unsigned char x);
  
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
  void shift(Axis axis, Direction direction);

  /**
   *
   */
  void shiftOnX(Direction direction);

  /**
   *
   */
  void shiftOnY(Direction direction);
  
  /**
   *
   */
  void shiftOnZ(Direction direction);
  
  /**
   * 
   */
  void writeSubCube(Point *p, Voxel v, unsigned char size);

  /**
   * Swap the buffers. Current buffer becomes backed buffer and vice-versa.
   */
  void swapBuffers();
};

#endif /* __ARDUINO_CUBE_CUBE_H__ */
