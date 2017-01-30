/**
 */

#ifndef __ARDUINO_CUBE_POINT_H__
#define __ARDUINO_CUBE_POINT_H__ 1

class Point {

public:

    unsigned char x;
    unsigned char y;
    unsigned char z;

    Point();

    Point(unsigned char x, unsigned char y, unsigned char z);

    void randomize(unsigned char maxRange);

    unsigned char distanceOnXTo(Point *p);

    unsigned char distanceOnYTo(Point *p);

    unsigned char distanceOnZTo(Point *p);

    float distance2DTo(Point *p);

    float distance3DTo(Point *p);

    bool is(Point *p);

private:

    void init(unsigned char x, unsigned char y, unsigned char z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

#endif /* __ARDUINO_CUBE_POINT_H__ */
