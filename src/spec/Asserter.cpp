#include <Asserter.h>
#include <stdio.h>

bool Asserter::assert(bool assertion, const char *msg) {
  bool failure = false;
  if (assertion) {
    printf("\e[32m(*) passed: %s\e[0m\n", msg);
  } else {
    failure = true;
    printf("\e[31m(F) failed: %s\e[0m\n", msg);
  }
  return failure;
}

bool Asserter::assertEqual(unsigned char a, unsigned char b, const char *msg) {
  bool failure = false;
  if(a == b) {
    printf("\e[32m(*) passed: %s\e[0m\n", msg);
  } else {
    failure = true;
    printf("\e[31m(F) failed: %s (expected %d to be equal %d)\e[0m\n", msg, a, b);
  }
  return failure;
}

bool Asserter::assertNotEqual(unsigned char a, unsigned char b, const char *msg) {
  bool failure = false;
  if(a != b) {
    printf("\e[32m(*) passed: %s\e[0m\n", msg);
  } else {
    failure = true;
    printf("\e[31m(F) failed: %s (expected %d to not be equal %d)\e[0m\n", msg, a, b);
  }
  return failure;
}
