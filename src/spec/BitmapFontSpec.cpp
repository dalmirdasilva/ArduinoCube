/**
 */

#ifndef __ARDUINO_CUBE_BITMAP_FONT_TEST_CPP__
#define __ARDUINO_CUBE_BITMAP_FONT_TEST_CPP__ 1

#include <BitmapFontSpec.h>
#include <Asserter.h>
#include <Util.h>

BitmapFontSpec::BitmapFontSpec() {
}

void BitmapFontSpec::run() {
  getInfoSpec();
  getCharacterWidthSpec();
  getCharacterHeightSpec();
  getSequenceCountSpec();
  getGlyphLengthSpec();
  readGlyphDataSpec();
  getGlyphOffsetSpec();
}

void BitmapFontSpec::getInfoSpec() {
  Asserter::assertEqual(0, 0, "getInfoSpec: Should pass.");
}

void BitmapFontSpec::getCharacterWidthSpec() {
  Asserter::assertEqual(0, 0, "getCharacterWidthSpec: Should pass.");
}

void BitmapFontSpec::getCharacterHeightSpec() {
  Asserter::assertEqual(0, 0, "getCharacterHeightSpec: Should pass.");
}

void BitmapFontSpec::getSequenceCountSpec() {
  Asserter::assertEqual(0, 0, "getSequenceCountSpec: Should pass.");
}

void BitmapFontSpec::getGlyphLengthSpec() {
  Asserter::assertEqual(0, 0, "getGlyphLengthSpec: Should pass.");
}

void BitmapFontSpec::readGlyphDataSpec() {
  Asserter::assertEqual(0, 0, "readGlyphDataSpec: Should pass.");
}

void BitmapFontSpec::getGlyphOffsetSpec() {
  Asserter::assertEqual(0, 0, "getGlyphOffsetSpec: Should pass.");
}

#endif /* __ARDUINO_CUBE_BITMAP_FONT_TEST_CPP__ */