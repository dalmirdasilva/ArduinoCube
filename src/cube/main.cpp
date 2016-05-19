#include <GL/glut.h>
#include <pthread.h>

#include <Cube.h>
#include <Blink.h>
#include <Rain.h>
#include <BoxShrinkGrow.h>
#include <MovingBoxShrinkGrow.h>
#include <GameOfLife.h>

#include <ByteArraySeekableInputStream.h>
#include <BitmapFont.h>
#include <TextRender.h>
#include <ShiftingText.h>

#include "simulator.h"

Cube cube = Cube();

void *effect_runner(void *arg) {
  /*
  Blink blink = Blink(&cube, 10, 750);
  Rain rain = Rain(&cube, 10, 300, 4, 8);
  BoxShrinkGrow boxShrinkGrow = BoxShrinkGrow(&cube, 10, 750, BoxShrinkGrow::WIREFRAME);
  GameOfLife gameOfLife = GameOfLife(&cube, 1000, 750, 15);
  unsigned char fontStream[] = {
    0, 5, 8, 1, 32, 126, 0, 8,0, 0, 0, 0, 0, 0, 6, 95, 6, 0, 7, 3, 0, 7, 3, 36, 126, 36, 126, 36, 36, 43, 106, 18, 0, 99, 19, 8, 100, 99, 54, 73, 86, 32, 80, 0, 7, 3, 0, 0, 0, 62, 65, 0, 0, 0, 65, 62, 0, 0, 8, 62, 28, 62, 8, 8, 8, 62, 8, 8, 0, 224, 96, 0, 0, 8, 8, 8, 8, 8, 0, 96, 96, 0, 0, 32, 16, 8, 4, 2, 62, 81, 73, 69, 62, 0, 66, 127, 64, 0, 98, 81, 73, 73, 70, 34, 73, 73, 73, 54, 24, 20, 18, 127, 16, 47, 73, 73, 73, 49, 60, 74, 73, 73, 48, 1, 113, 9, 5, 3, 54, 73, 73, 73, 54, 6, 73, 73, 41, 30, 0, 108, 108, 0, 0, 0, 236, 108, 0, 0, 8, 20, 34, 65, 0, 36, 36, 36, 36, 36, 0, 65, 34, 20, 8, 2, 1, 89, 9, 6, 62, 65, 93, 85, 30, 126, 9, 9, 9, 126, 127, 73, 73, 73, 54, 62, 65, 65, 65, 34, 127, 65, 65, 65, 62, 127, 73, 73, 73, 65, 127, 9, 9, 9, 1, 62, 65, 73, 73, 122, 127, 127, 24, 127, 127, 0, 65, 127, 65, 0, 48, 64, 64, 64, 63, 127, 8, 20, 34, 65, 127, 64, 64, 64, 64, 127, 2, 4, 2, 127, 127, 2, 4, 8, 127, 62, 65, 65, 65, 62, 127, 127, 27, 31, 14, 62, 65, 81, 33, 94, 127, 9, 9, 25, 102, 38, 73, 73, 73, 50, 1, 1, 127, 1, 1, 63, 64, 64, 64, 63, 31, 32, 64, 32, 31, 63, 64, 60, 64, 63, 99, 20, 8, 20, 99, 7, 8, 112, 8, 7, 113, 73, 69, 67, 0, 0, 127, 65, 65, 0, 2, 4, 8, 16, 32, 0, 65, 65, 127, 0, 4, 2, 1, 2, 4, 128, 128, 128, 128, 128, 0, 3, 7, 0, 0, 32, 84, 84, 84, 120, 127, 68, 68, 68, 56, 56, 68, 68, 68, 40, 56, 68, 68, 68, 127, 56, 84, 84, 84, 24, 8, 126, 9, 9, 0, 24, 164, 164, 164, 124, 127, 4, 4, 120, 0, 0, 0, 125, 0, 0, 64, 128, 132, 125, 0, 127, 16, 40, 68, 0, 0, 0, 127, 64, 0, 124, 4, 24, 4, 120, 124, 4, 4, 120, 0, 56, 68, 68, 68, 56, 252, 68, 68, 68, 56, 56, 68, 68, 68, 252, 68, 120, 68, 4, 8, 8, 84, 84, 84, 32, 4, 62, 68, 36, 0, 60, 64, 32, 124, 0, 28, 32, 64, 32, 28, 60, 96, 48, 96, 60, 108, 16, 16, 108, 0, 156, 160, 96, 60, 0, 100, 84, 84, 76, 0, 8, 62, 65, 65, 0, 0, 0, 127, 0, 0, 0, 65, 65, 62, 8, 2, 1, 2, 1, 0
  };
  ByteArraySeekableInputStream is = ByteArraySeekableInputStream(&fontStream[0], (unsigned int) sizeof(fontStream));
  BitmapFont font = BitmapFont(&is);
  TextRender render = TextRender(&cube, &font);
  Point p = Point(3, 0, 7);
  ShiftingText::ShiftingTextSettings settings = {&render, (const char *) "HP is the best company to work at", 1, TextRender::ZYX, &p};
  ShiftingText shiftingText = ShiftingText(&cube, 10, 1000, &settings);
  MovingBoxShrinkGrow movingBoxShrinkGrow = MovingBoxShrinkGrow(&cube, 100, 70, BoxShrinkGrow::WIREFRAME);
  GameOfLife gol = GameOfLife(&cube, 10, 750, 5);
  while (1) {
    rain.run();
  }
  */
  
  return NULL;
}

int main(int argc, char* argv[]) {
  int arg = 0;
  void *exit_status;
  
  glutInit(&argc,argv);
  pthread_t cube_thread, effect_runner_thread;

  pthread_create(&cube_thread, NULL, cubeInit, &arg);
  pthread_create(&effect_runner_thread, NULL, effect_runner, &arg);

  pthread_join(cube_thread, &exit_status);
  pthread_join(effect_runner_thread, &exit_status);

  return 0;
}
