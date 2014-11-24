#include <PointSpec.h>
#include <Asserter.h>
#include <Point.h>
#include <Util.h>

PointSpec::PointSpec() {
}

unsigned int PointSpec::run() {
  unsigned int errorCount = 0;
  errorCount += randomizeSpec();
  errorCount += distanceOnXToSpec();
  errorCount += distanceOnYToSpec();
  errorCount += distanceOnZToSpec();
  errorCount += distance2DToSpec();
  errorCount += distance3DSpec();
  return errorCount;
}

unsigned int PointSpec::randomizeSpec() {
  unsigned int errorCount = 0;
  Point p;
  p.randomize(1);
  errorCount += (unsigned int) Asserter::assertEqual(true, (p.x == 0), "randomizeSpec: should randomize X dim.");
  errorCount += (unsigned int) Asserter::assertEqual(true, (p.y == 0), "randomizeSpec: should randomize Y dim.");
  errorCount += (unsigned int) Asserter::assertEqual(true, (p.z == 0), "randomizeSpec: should randomize Z dim.");
  return errorCount;
}

unsigned int PointSpec::distanceOnXToSpec() {
  unsigned int errorCount = 0;
  unsigned char distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(10, 20, 30);
  distance = p0.distanceOnXTo(&p1);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 10, "distanceOnXToSpec: should get right distance when the second point is ahead.");
  distance = p1.distanceOnXTo(&p0);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 10, "distanceOnXToSpec: should get right distance when the second point is behind.");
  return errorCount;
}

unsigned int PointSpec::distanceOnYToSpec() {
  unsigned int errorCount = 0;
  unsigned char distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(10, 20, 30);
  distance = p0.distanceOnYTo(&p1);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 20, "distanceOnYToSpec: should get right distance when the second point is ahead.");
  distance = p1.distanceOnYTo(&p0);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 20, "distanceOnYToSpec: should get right distance when the second point is behind.");
  return errorCount;
}

unsigned int PointSpec::distanceOnZToSpec() {
  unsigned int errorCount = 0;
  unsigned char distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(10, 20, 30);
  distance = p0.distanceOnZTo(&p1);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 30, "distanceOnZToSpec: should get right distance when the second point is ahead.");
  distance = p1.distanceOnZTo(&p0);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 30, "distanceOnZToSpec: should get right distance when the second point is behind.");
  return errorCount;
}

unsigned int PointSpec::distance2DToSpec() {
  unsigned int errorCount = 0;
  float distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(3, 4, 0);
  distance = p0.distance2DTo(&p1);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 5, "distance2DToSpec: should get right 2D distance when the second point is ahead.");
  distance = p1.distance2DTo(&p0);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 5, "distance2DToSpec: should get right 2D distance when the second point is behind.");
  return errorCount;
}

unsigned int PointSpec::distance3DSpec() {
  unsigned int errorCount = 0;
  float distance;
  Point p0 = Point(0, 0, 0);
  Point p1 = Point(3, 4, 5);
  distance = p0.distance3DTo(&p1);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 7, "distance2DToSpec: should get right 3D distance when the second point is ahead.");
  distance = p1.distance3DTo(&p0);
  errorCount += (unsigned int) Asserter::assertEqual(distance, 7, "distance2DToSpec: should get right 3D distance when the second point is behind.");
  return errorCount;
}