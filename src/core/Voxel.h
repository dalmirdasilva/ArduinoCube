/**
 */
 
#ifndef __ARDUINO_CUBE_VOXEL_H__
#define __ARDUINO_CUBE_VOXEL_H__ 1

typedef enum {
  AXIS_X = 0x00,
  AXIS_Y = 0x01,
  AXIS_Z = 0x02
} Axis;

typedef enum {
  UP = 0x00,
  DOWN = 0x01,
  LEFT = 0x02,
  RIGHT = 0x04,
  FRONT = 0x08,
  BACK = 0x10
} Direction;

typedef enum {
  ON = 0xff,
  OFF = 0x00
} State;

typedef struct {
  unsigned char state;
} Voxel;


#endif /* __ARDUINO_CUBE_VOXEL_H__ */
