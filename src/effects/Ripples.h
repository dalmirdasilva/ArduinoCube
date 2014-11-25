/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RIPPLES_H__
#define __ARDUINO_CUBE_EFFECTS_RIPPLES_H__ 1

#include <Effect.h>
#include <Cube.h>

class Ripples : public Effect {

public:

  typedef struct {
  } RipplesSettings;

  RipplesSettings *settings;

  Ripples(Cube *cube, RipplesSettings *settings);

  virtual void run(unsigned int iterations);
};

#endif /* __ARDUINO_CUBE_EFFECTS_RIPPLES_H__ */
