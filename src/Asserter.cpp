#include <Asserter.h>
#include <stdio.h>

void Asserter::assert(bool assertion, const char *msg) {
 if (assertion) {
    printf("\e[32m(*) passed: %s\e[0m\n", msg);
  } else {
    printf("e[31m(F) failed: %s\e[0m\n", msg);
  }
}

void Asserter::assertEqual(unsigned char a, unsigned char b, const char *msg) {
  if(a == b) {
    printf("\e[32m(*) passed: %s\e[0m\n", msg);
  } else {
    printf("\e[31m(F) failed: %s (expected %d to be equal %d)\e[0m\n", msg, a, b);
  }
}

void Asserter::assertNotEqual(unsigned char a, unsigned char b, const char *msg) {
  if(a != b) {
    printf("\e[32m(*) passed: %s\e[0m\n", msg);
  } else {
    printf("e[31m(F) failed: %s (expected %d to not be equal %d)\e[0m\n", msg, a, b);
  }
}
