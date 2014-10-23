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

  const static unsigned char WRITE_TO_BUFFER = 1;
  const static unsigned char WRITE_TO_CUBE = 0;
  const static unsigned char DEFAULT_WRITE_TO = WRITE_TO_BUFFER;
  
  /**
   * Validates if we the p Point is inside the cube.
   */
  bool isInRange(Point *p);
  
  /**
   *
   */ 
  char getBitRange(unsigned char start, unsigned char end);
  
  /**
   * See overloaded method.
   */
  void writeVoxel(Point *p, Voxel v);
  
  /**
   * Writes the v Voxel to the cube at p Point. If b == true
   * writes to the backed buffer instead.
   * 
   * @param *p            3D Point pointer
   * @param v             Voxel
   * @param b             Write it to the buffer/cube
   */
  void writeVoxel(Point *p, Voxel v, unsigned char to);
  
  /**
   * See overloaded method.
   */
  void turnOnVoxel(Point *p);
  
  /**
   * See overloaded method.
   */
  void turnOffVoxel(Point *p);
  
  /**
   * Set voxel to ON
   * 
   * @param p             3D Point pointer
   * @param b             Write it to the buffer/cube
   */
  void turnOnVoxel(Point *p, unsigned char to);
  
  /**
   * Set voxel to OFF
   * 
   * @param p             3D Point pointer
   * @param b             Write it to the buffer/cube
   */
  void turnOffVoxel(Point *p, unsigned char to);
  
  /**
   * See overloaded method
   */
  void invertVoxel(Point *p);
  
  /**
   * Switch volex state
   */
  void invertVoxel(Point *p, unsigned char to);
  
  /**
   * See overloaded method
   */
  void turnOnPlaneZ(unsigned char z);
  
  /**
   * Turn on plane z.
   */
  void turnOnPlaneZ(unsigned char z, unsigned char to);
  
  /**
   * Write plane z.
   */
  void writePlaneZ(unsigned char z, Voxel v, unsigned char to);
  
  /**
   * Write plane z.
   */
  void writePlaneX(unsigned char x, Voxel v, unsigned char to);
  
  /*
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
* */

private:

  void set(unsigned char *p, unsigned char mask);
  
  void clr(unsigned char *p, unsigned char mask);

  void argOrder(unsigned char a, unsigned char b, unsigned char *ap, unsigned char *bp);
};

#endif /* __ARDUINO_CUBE_DROWER_H__ */
