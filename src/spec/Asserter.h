/**
 */
 
#ifndef __ARDUINO_CUBE_ASSERTER_H__
#define __ARDUINO_CUBE_ASSERTER_H__ 1

class Asserter {

public:

  static const char *ASSERT_PASSED_OUTPUT;
  static const char *ASSERT_FAILED_OUTPUT;
  static const char *ASSERT_EQUAL_FAILED_OUTPUT;
  static const char *ASSERT_NOT_EQUAL_FAILED_OUTPUT;

  typedef struct {
    unsigned int error;
    unsigned int success;
  } Counter;

  static Counter counter;

  static void reset();

  static Counter *getCounter() {
    return &counter;
  }

  static bool assert(bool assertion, const char *msg);
  
  static bool assertEqual(unsigned char a, unsigned char b, const char *msg);
  
  static bool assertNotEqual(unsigned char a, unsigned char b, const char *msg);
};

#endif /* __ARDUINO_CUBE_ASSERTER_H__ */

