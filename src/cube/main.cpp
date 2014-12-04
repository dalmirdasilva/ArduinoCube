#include <GL/glut.h>
#include <pthread.h>

#include <Cube.h>
#include <Blink.h>
#include <Rain.h>
#include "simulator.h"

Cube cube = Cube();

void *effect_runner(void *arg) {
  Blink::BlinkSettings blinkSettings = {750};
  Blink blink = Blink(&cube, &blinkSettings);
  
  Rain::RainSettings rainSettings = {1, 8, 200};
  Rain rain = Rain(&cube, &rainSettings);
  
  while (1) {
    rain.run(1);
    //blink.run(1);
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
