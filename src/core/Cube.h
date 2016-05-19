/**
 * Cube class
 */
 
#ifndef __ARDUINO_CUBE_CUBE_H__
#define __ARDUINO_CUBE_CUBE_H__ 1

#define CUBE_SIZE             0x10
#define CUBE_BYTE_SIZE        CUBE_SIZE * CUBE_SIZE * sizeof(int)
#define CUBE_SIZE_MASK        0x0f
#define CUBE_BYTE_SIZE_MASK   0x3fff

#include <Point.h>
#include <Voxel.h>

class Cube {

  static unsigned int buffer0[CUBE_SIZE][CUBE_SIZE];
  static unsigned int buffer1[CUBE_SIZE][CUBE_SIZE];
  unsigned int **bufferToWrite;

public:

  const static unsigned int SIZE = CUBE_SIZE;
  const static unsigned int BYTE_SIZE = CUBE_BYTE_SIZE;
  unsigned int *frontBuffer;
  unsigned int *backBuffer;

  typedef enum {
    FRONT_BUFFER = 0x00,
    BACK_BUFFER = 0x01
  } Buffer;

  Cube() {
    frontBuffer = &buffer0[0][0];
    backBuffer = &buffer1[0][0];
    bufferToWrite = &frontBuffer;
  }

  /**
   * Set if will use back or front buffer to write to.
   */
  void selectBuffer(Buffer buffer);

  /**
   * Set the buffer to use back buffer.
   */
  void useBackBuffer() {
    selectBuffer(BACK_BUFFER);
  }

  /**
   * Set the buffer to use front buffer.
   */
  void useFrontBuffer() {
    selectBuffer(FRONT_BUFFER);
  }

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
  void fill(unsigned int pattern);
  
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
  void writeVoxel(unsigned int x, unsigned int y, unsigned int z, unsigned int state);

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
  void turnPlaneZOff(unsigned int z);
  
  /**
   * Turn on plane z.
   */
  void turnPlaneZOn(unsigned int z);

  /**
   * Write plane z.
   */
  void writePlaneZ(unsigned int z, Voxel v);
  
  /**
   * Turn off plane y.
   */
  void turnPlaneYOff(unsigned int y);
  
  /**
   * Turn on plane y.
   */
  void turnPlaneYOn(unsigned int y);
  
  /**
   * Write plane y.
   */
  void writePlaneY(unsigned int y, Voxel v);
  
  /**
   * Turn off plane x.
   */
  void turnPlaneXOff(unsigned int x);
  
  /**
   * Turn on plane x.
   */
  void turnPlaneXOn(unsigned int x);
  
  /**
   * Write plane x.
   */
  void writePlaneX(unsigned int x, Voxel v);
  
  /**
   * Turn the p plane.
   */
  void writePlane(Axis axis, unsigned int pos, Voxel v);
  
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
  void writeSubCube(Point *p, Voxel v, unsigned int size);

  /**
   * Swap the buffers. Current buffer becomes backed buffer and vice-versa.
   */
  void swapBuffers();
};

#endif /* __ARDUINO_CUBE_CUBE_H__ */
