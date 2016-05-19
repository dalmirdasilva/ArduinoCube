/**
 */
 
#ifndef __ARDUINO_CUBE_POINT_H__
#define __ARDUINO_CUBE_POINT_H__ 1

class Point {

public:

  unsigned int x;
  unsigned int y;
  unsigned int z;

  Point();

  Point(unsigned int x, unsigned int y, unsigned int z);

  void randomize(unsigned int maxRange);

  unsigned int distanceOnXTo(Point *p);

  unsigned int distanceOnYTo(Point *p);

  unsigned int distanceOnZTo(Point *p);

  float distance2DTo(Point *p);

  float distance3DTo(Point *p);

private:

  void init(unsigned int x, unsigned int y, unsigned int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
};

#endif /* __ARDUINO_CUBE_POINT_H__ */
