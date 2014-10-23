/**
 */
 
#ifndef __ARDUINO_CUBE_CUBE_H__
#define __ARDUINO_CUBE_CUBE_H__ 1

#define CUBE_SIZE 8

class Cube {

public:

  static unsigned char SIZE;
  static unsigned char buffer[CUBE_SIZE][CUBE_SIZE];
  static unsigned char cube[CUBE_SIZE][CUBE_SIZE];
};

#endif /* __ARDUINO_CUBE_CUBE_H__ */
