/**
 */
 
#ifndef __ARDUINO_CUBE_UTIL_H__
#define __ARDUINO_CUBE_UTIL_H__ 1

#include <Point.h>
#include <Cube.h>
#include <stdio.h>

class Util {

public:

  static void dumpPoint(Point *p);

  static void dumpCube(unsigned char *buffer);
  
  static unsigned char shift(unsigned char v, unsigned char isLeft);
};

#endif /* __ARDUINO_CUBE_UTIL_H__ */
