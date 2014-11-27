#include <PointSpec.h>
#include <Asserter.h>
#include <Point.h>
#include <Util.h>

PointSpec::PointSpec() {
}

void PointSpec::run() {
  randomizeSpec();
  distanceOnXToSpec();
  distanceOnYToSpec();
  distanceOnZToSpec();
  distance2DToSpec();
  distance3DSpec();
}

void PointSpec::randomizeSpec() {
  Point p;
  p.randomize(1);
  Asserter::assertEqual(true, (p.x == 0), "randomizeSpec: should randomize X dim.");
  Asserter::assertEqual(true, (p.y == 0), "randomizeSpec: should randomize Y dim.");
  Asserter::assertEqual(true, (p.z == 0), "randomizeSpec: should randomize Z dim.");
}

void PointSpec::distanceOnXToSpec() {
  unsigned char distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(10, 20, 30);
  distance = p0.distanceOnXTo(&p1);
  Asserter::assertEqual(distance, 10, "distanceOnXToSpec: should get right distance when the second point is ahead.");
  distance = p1.distanceOnXTo(&p0);
  Asserter::assertEqual(distance, 10, "distanceOnXToSpec: should get right distance when the second point is behind.");
}

void PointSpec::distanceOnYToSpec() {
  unsigned char distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(10, 20, 30);
  distance = p0.distanceOnYTo(&p1);
  Asserter::assertEqual(distance, 20, "distanceOnYToSpec: should get right distance when the second point is ahead.");
  distance = p1.distanceOnYTo(&p0);
  Asserter::assertEqual(distance, 20, "distanceOnYToSpec: should get right distance when the second point is behind.");
}

void PointSpec::distanceOnZToSpec() {
  unsigned char distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(10, 20, 30);
  distance = p0.distanceOnZTo(&p1);
  Asserter::assertEqual(distance, 30, "distanceOnZToSpec: should get right distance when the second point is ahead.");
  distance = p1.distanceOnZTo(&p0);
  Asserter::assertEqual(distance, 30, "distanceOnZToSpec: should get right distance when the second point is behind.");
}

void PointSpec::distance2DToSpec() {
  float distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(3, 4, 0);
  distance = p0.distance2DTo(&p1);
  Asserter::assertEqual(distance, 5, "distance2DToSpec: should get right 2D distance when the second point is ahead.");
  distance = p1.distance2DTo(&p0);
  Asserter::assertEqual(distance, 5, "distance2DToSpec: should get right 2D distance when the second point is behind.");
}

void PointSpec::distance3DSpec() {
  float distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(3, 4, 5);
  distance = p0.distance3DTo(&p1);
  Asserter::assertEqual(distance, 7, "distance2DToSpec: should get right 3D distance when the second point is ahead.");
  distance = p1.distance3DTo(&p0);
  Asserter::assertEqual(distance, 7, "distance2DToSpec: should get right 3D distance when the second point is behind.");
}