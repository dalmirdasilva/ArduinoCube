/**
 */
 
#ifndef __ARDUINO_CUBE_VOXEL_H__
#define __ARDUINO_CUBE_VOXEL_H__ 1

typedef enum {
  AXIS_X,
  AXIS_Y,
  AXIS_Z
} Axis;

typedef enum {
  ON = 0xff,
  OFF = 0x00
} VoxelState;

typedef struct {
  unsigned char state;
} Voxel;


#endif /* __ARDUINO_CUBE_VOXEL_H__ */
