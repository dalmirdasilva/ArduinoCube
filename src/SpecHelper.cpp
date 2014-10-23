#include <SpecHelper.h>
#include <stdio.h>

void SpecHelper::assert(bool assertion, const char *msg) {
  if (assertion)
    printf("(*) passed: %s\n", msg);
  else
    printf("(F) failed: %s\n", msg);
}

void SpecHelper::assertEqual(unsigned char a, unsigned char b, const char *msg) {
  if(a == b)
    printf("(*) passed: %s\n", msg, a, b);
  else
    printf("(F) failed: %s (expected %d to be equal %d)\n", msg, a, b);
}

void SpecHelper::assertNotEqual(unsigned char a, unsigned char b, const char *msg) {
  if(a != b)
    printf("(*) passed: %s\n", msg, a, b);
  else
    printf("(F) failed: %s (expected %d to not be equal %d)\n", msg, a, b);
}
