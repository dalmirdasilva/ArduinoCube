#include <GL/glut.h>
#include <pthread.h>

#include <Cube.h>
#include <Blink.h>
#include <Rain.h>
#include <BoxShrinkGrow.h>
#include <MovingBoxShrinkGrow.h>
#include <GameOfLife.h>
#include "simulator.h"

Cube cube = Cube();

void *effect_runner(void *arg) {
  Blink blink = Blink(&cube, 10, 750);
  Rain rain = Rain(&cube, 10, 300, 4, 8);
  BoxShrinkGrow boxShrinkGrow = BoxShrinkGrow(&cube, 10, 750, BoxShrinkGrow::WIREFRAME);
  MovingBoxShrinkGrow movingBoxShrinkGrow = MovingBoxShrinkGrow(&cube, 100, 70, BoxShrinkGrow::WIREFRAME);
  GameOfLife gol = GameOfLife(&cube, 10, 750, 5);


  while (1) {
    movingBoxShrinkGrow.run();
  }
  return NULL;
}

int main (int argc, char* argv[]) {
  int arg = 0;
  void *exit_status;

  glutInit(&argc,argv);
  pthread_t cube_thread, effect_runner_thread;

  pthread_create(&cube_thread, NULL, cube_init, &arg);
  pthread_create(&effect_runner_thread, NULL, effect_runner, &arg);

  pthread_join(cube_thread, &exit_status);
  pthread_join(effect_runner_thread, &exit_status);

  return 0;
}
