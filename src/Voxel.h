/**
 */
 
#ifndef __ARDUINO_CUBE_VOXEL_H__
#define __ARDUINO_CUBE_VOXEL_H__ 1

typedef enum {
  ON = 0xff,
  OFF = 0x00
} State;

typedef union {
  State state;
  unsigned char color;
} Voxel;

#endif /* __ARDUINO_CUBE_VOXEL_H__ */
