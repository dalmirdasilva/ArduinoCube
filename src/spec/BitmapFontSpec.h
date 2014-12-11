/**
 */

#ifndef __ARDUINO_CUBE_BITMAP_FONT_TEST_H__
#define __ARDUINO_CUBE_BITMAP_FONT_TEST_H__ 1

class BitmapFontSpec {

public:

  BitmapFontSpec();

  void run();

  void getInfoSpec();

  void getCharacterWidthSpec();

  void getCharacterHeightSpec();

  void getSequenceCountSpec();

  void getGlyphLengthSpec();

  void readGlyphDataSpec();

  void getGlyphOffsetSpec();
};

#endif /* __ARDUINO_CUBE_BITMAP_FONT_TEST_H__ */