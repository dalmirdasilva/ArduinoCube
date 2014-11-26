/**
 */
 
#ifndef __ARDUINO_CUBE_DUMPER_H__
#define __ARDUINO_CUBE_DUMPER_H__ 1

#include <Point.h>
#include <Cube.h>
#include <stdio.h>

class Dumper {

public:

  static void dumpPoint(Point *point);

  static void dumpCube(Cube *cube);
};

#endif /* __ARDUINO_CUBE_DUMPER_H__ */
