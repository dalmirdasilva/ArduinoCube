/**
 */
 
#ifndef __ARDUINO_CUBE_HELPER_H__
#define __ARDUINO_CUBE_HELPER_H__ 1

class SpecHelper {
  
public:

  static void assert(bool assertion, const char *msg);
  
  static void assertEqual(unsigned char a, unsigned char b, const char *msg);
  
  static void assertNotEqual(unsigned char a, unsigned char b, const char *msg);
};

#endif /* __ARDUINO_CUBE_HELPER_H__ */

