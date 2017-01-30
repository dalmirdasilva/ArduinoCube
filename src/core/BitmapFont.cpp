/**
 * Arduino Cube Library
 * 
 * BitmapFont.cpp
 * 
 * The representation of a glcd font.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_CUBE_BITMAP_FONT_CPP__
#define __ARDUINO_CUBE_BITMAP_FONT_CPP__ 1

#include "BitmapFont.h"

BitmapFont::BitmapFont(SeekableInputStream* inputStream)
        : inputStream(inputStream) {
    dataOffset = sizeof(Header);
    inputStream->seek(0);
    header.info = inputStream->read();
    header.characterWidth = inputStream->read();
    header.characterHeight = inputStream->read();
    header.sequenceCount = inputStream->read();
    glyphLength = header.characterWidth * (header.characterHeight / 8);
}

unsigned char BitmapFont::getInfo() {
    return header.info;
}

unsigned char BitmapFont::getCharacterWidth() {
    return header.characterWidth;
}

unsigned char BitmapFont::getCharacterHeight() {
    return header.characterHeight;
}

unsigned char BitmapFont::getSequenceCount() {
    return header.sequenceCount;
}

unsigned char BitmapFont::getGlyphLength() {
    return glyphLength;
}

unsigned char BitmapFont::readGlyphData(unsigned char *buf, char c) {
    unsigned int offset = getGlyphOffset(c);
    if (offset == 0) {
        return 0;
    }
    inputStream->seek(offset);
    return (unsigned char) inputStream->read(buf, 0, getGlyphLength());
}

unsigned int BitmapFont::getGlyphOffset(char c) {
    unsigned char i, first, last;
    unsigned int offset = 0;
    inputStream->seek(dataOffset);
    for (i = 0; i < getSequenceCount(); i++) {
        first = inputStream->read();
        last = inputStream->read();
        if (c >= first && c <= last) {
            offset = inputStream->read();
            offset <<= 8;
            offset |= inputStream->read();
            offset += (c - first) * getGlyphLength();
            break;
        } else {
            inputStream->skip(2);
        }
    }
    return offset;
}

#endif /* __ARDUINO_CUBE_BITMAP_FONT_CPP__ */
