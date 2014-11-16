/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_RIPPLES_H__
#define __ARDUINO_CUBE_EFFECTS_RIPPLES_H__ 1

#include <Effect.h>
#include <Cube.h>

class Ripples : public Effect {

public:

  typedef struct {
    unsigned char iterations;
  } RipplesParameters;

  RipplesParameters *parameters;

  Ripples(Cube *cube, RipplesParameters *parameters);

  virtual void run();
};

#endif /* __ARDUINO_CUBE_EFFECTS_RIPPLES_H__ */
