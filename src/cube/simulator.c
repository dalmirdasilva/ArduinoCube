#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>

#include <Cube.h>
#include <Voxel.h>
#include <Point.h>

#include "simulator.h"

#define ROTATE_STEP 5
#define SPACE 0.14

double rotateOnY, rotateOnX;
int isClicked, previousX, previousY, deltaX, deltaY;

void render() {
  Voxel v;
  Point p;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glLoadIdentity();
  glRotatef(rotateOnX, 1.0, 0.0, 0.0);
  glRotatef(rotateOnY, 0.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  for(p.x = 0; p.x < 8; p.x++) {
    for(p.y = 0; p.y < 8; p.y++) {
      for(p.z = 0; p.z < 8; p.z++) {
        cube.readVoxel(&p, &v);
        glPushMatrix();
        glTranslatef(SPACE * (p.x - Cube::SIZE / 2), SPACE * (p.y - Cube::SIZE / 2), -SPACE * (p.z - Cube::SIZE / 2));
        if (v.state == ON) {
          glColor4f(1.0, 0.0, 0.0, 1.0f);
          glutSolidSphere(0.018, 25, 5);
        } else {
          glColor4f(1.0, 1.0, 1.0, 0.1f);
          glutSolidSphere(0.015, 25, 5);
        }
        glPopMatrix();
      }
    }
  }

  glFlush();
  glutSwapBuffers();
}

void special(int key, int x, int y) {
  switch(key) {
    case GLUT_KEY_RIGHT:
      rotateOnY += ROTATE_STEP;
      break;
    case GLUT_KEY_LEFT:
      rotateOnY -= ROTATE_STEP;
      break;
    case GLUT_KEY_UP:
      rotateOnX += ROTATE_STEP;
      break;
    case GLUT_KEY_DOWN:
      rotateOnX -= ROTATE_STEP;
      break;
    case '8':
      cube.shiftOnY(UP);
      break;
    case '2':
      cube.shiftOnY(DOWN);
      break;
    case '6':
      cube.shiftOnX(RIGHT);
      break;
    case '4':
      cube.shiftOnX(LEFT);
      break;
  }
  glutPostRedisplay();
}

void mouse(int button, int pressed, int x, int y) {
  if (button == 0 && pressed == 0) {
    previousX = x;
    previousY = y;
    isClicked = 1;
  } else if (button == 0 && pressed == 1) {
    if (isClicked) {
      isClicked = 0;
    }
  }
}

void mouseMotion(int x, int y) {
  if (isClicked) {
    if (previousX || previousY) {
      deltaX = previousX - x;
      deltaY = previousY - y;
      rotateOnX += deltaY;
      rotateOnY += deltaX;
      previousX = x;
      previousY = y;
    } else{
      previousX = x;
      previousY = y;
    }
  }
}

void *cube_init(void *arg) {
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(800, 800);
  glutCreateWindow("ArduinoCube");
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(render);
  glutIdleFunc(render);
  glutSpecialFunc(special);
  glutMouseFunc(mouse);
  glutMotionFunc(mouseMotion);
  glutMainLoop();
  return NULL;
}
