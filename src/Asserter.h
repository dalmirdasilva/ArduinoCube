/**
 */
 
#ifndef __ARDUINO_CUBE_ASSERTER_H__
#define __ARDUINO_CUBE_ASSERTER_H__ 1

class Asserter {
  
public:

  static bool assert(bool assertion, const char *msg);
  
  static bool assertEqual(unsigned char a, unsigned char b, const char *msg);
  
  static bool assertNotEqual(unsigned char a, unsigned char b, const char *msg);
};

#endif /* __ARDUINO_CUBE_ASSERTER_H__ */

