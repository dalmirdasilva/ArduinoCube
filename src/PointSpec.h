/**
 */

#ifndef __ARDUINO_CUBE_POINT_TEST_H__
#define __ARDUINO_CUBE_POINT_TEST_H__ 1

class PointSpec {
  
public:
  
  PointSpec();
  
  unsigned int run();

  unsigned int randomizeSpec();
  
  unsigned int distanceOnXToSpec();

  unsigned int distanceOnYToSpec();

  unsigned int distanceOnZToSpec();

  unsigned int distance2DToSpec();

  unsigned int distance3DSpec();
};

#endif /* __ARDUINO_CUBE_POINT_TEST_H__ */
