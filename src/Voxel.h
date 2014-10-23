/**
 */
 
#ifndef __ARDUINO_CUBE_VOXEL_H__
#define __ARDUINO_CUBE_VOXEL_H__ 1

class Voxel {

public:

  typedef enum {
    ON = 0xff,
    OFF = 0x00
  } State;

  State state;
};

#endif /* __ARDUINO_CUBE_VOXEL_H__ */
