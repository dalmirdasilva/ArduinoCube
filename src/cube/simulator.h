/**
 * 
 */

#ifndef __ARDUINO_CUBE_SIMULATOR_H__
#define __ARDUINO_CUBE_SIMULATOR_H__ 1

extern Cube cube;
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>

#include <Cube.h>
#include <Voxel.h>
#include <Point.h>
#include "simulator.h"

void render();
void special(int key, int x, int y);
void mouse(int button, int pressed, int x, int y);
void mouseMotion(int x, int y);
void *cube_init(void *arg);

#endif /* __ARDUINO_CUBE_SIMULATOR_H__ */
