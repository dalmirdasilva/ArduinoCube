/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__
#define __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ 1

#include <Effect.h>
#include <Cube.h>

class BoxShrinkGrow : public Effect {

public:

  typedef enum {
    WIREFRAME = 0x00,
    FILLED = 0x01,
    WALL = 0x02
  } BoxType;

  typedef struct {
    unsigned int delay;
    BoxType boxType;
  } BoxShrinkGrowSettings;

  BoxShrinkGrowSettings *settings;

  BoxShrinkGrow(Cube *cube, BoxShrinkGrowSettings *settings);

  virtual void run(unsigned int iterations);

  void shrink();

  void grow();

  void drawFrame(char size);

  virtual void draw(char size);
};

#endif /* __ARDUINO_CUBE_EFFECTS_BOX_SHRINK_GROW_H__ */
