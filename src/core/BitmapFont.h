/**
 * Arduino Cube Library
 * 
 * BitmapFont.h
 * 
 * The representation of a font.
 * 
 * Bitmap font is an array which represents the font glyph as a bitmap.
 * 
 * This font has fixed glyph size.
 * 
 * The first bytes specify the font's information and glyph sequences; 
 * 
 * Header example:
 * 
 * <pre>
 * unsigned char info;
 * unsigned char characterWidth;
 * unsigned char characterHeight;
 * unsigned char sequenceCount;
 * 
 * 0x00, 0xww, 0xhh, 0xnn
 *  |     |     |     |___ Sequence count
 *  |     |     |_________ Character height (in bits)
 *  |     |_______________ Character width (in bits)
 *  |_____________________ Into
 * </pre>
 * 
 * The next bytes, after the head, specify the sequences information, each sequence
 * have 3 information:
 * 
 * <pre>
 * unsigned char first;
 * unsigned char last;
 * unsigned char offset[msb];
 * unsigned char offset[lsb];
 * </pre>
 * 
 * The sequence information are followed one by another. Example:
 * Considering a font with 2 sequences, this could be the sequence bytes:
 * 
 * <pre>
 * 0x20, 0x22, 0x00, 0xff,
 * 0x40, 0x43, 0x0d, 0xff,
 * </pre>
 * 
 * which means we have a sequence that starts with the 0x20 char and goes to the
 * 0x22, and the glyph data are stored at the 0x00ff offset. Another sequence 
 * starts with the 0x40 char and goes to the
 * 0x43, and the glyph data are stored at the 0x0dff offset.
 * 
 * 
 * File structure
 * 
 * Header organization:
 * 
 * <pre>
 * +-------------------------+
 * |      Font info          | \
 * +-------------------------+  \   
 * |   Character width       |   \
 * +-------------------------+    } Header
 * |   Character height      |   /
 * +-------------------------+  /
 * |   Sequence count        | /
 * +-------------------------+
 * |   First character       | \
 * +-------------------------+  \
 * |   Last character        |   \
 * +-------------------------+    } Sequence #0
 * |   Offset MSB            |   /
 * +-------------------------+  /
 * |   Offset LSB            | /
 * +-------------------------+
 * |   First character       | \
 * +-------------------------+  \
 * |   Last character        |   \
 * +-------------------------+    } Sequence #n
 * |   Offset MSB            |   /
 * +-------------------------+  /
 * |   Offset LSB            | /
 * +-------------------------+
 * |                         | 0b00000000
 * |                         | 0b00000000
 * |                         | 0b00000000
 * |        FONT DATA        | 0b00000000
 * |     ARRAY OF BYTES      | 0b00000000
 * |                         | 0b00000000
 * |                         | 0b00000000
 * |                         | 0b00000000
 * +-------------------------+
 * </pre>
 * 
 * Font data
 * 
 * Each character could have any multiple by 8 height. For characters which
 * is 8 bits height, they are just made by bytes in sequence, as follows:
 * 
 * <pre>
 *           L    L    L    L    L
 *           i    i    i    i    i
 *           n    n    n    n    n
 *           e    e    e    e    e
 *           0    1    2    3    4    ...
 *         +------------------------...
 *         | b7 | b7 | b7 | b7 | b7 |
 *         | b6 | b6 | b6 | b6 | b6 |
 *         | b5 | b5 | b5 | b5 | b5 |
 *         | b4 | b4 | b4 | b4 | b4 |
 *         | b3 | b3 | b3 | b3 | b3 |
 *         | b2 | b2 | b2 | b2 | b2 |
 *         | b1 | b1 | b1 | b1 | b1 |
 *         | b0 | b0 | b0 | b0 | b0 |
 *         +------------------------...
 * </pre>
 * 
 * Or, this is a character with width equals 5 and height equals 8:
 * (can be the "T" letter)
 * 
 * <pre>
 *         +-+-+-+-+-+-+
 *         |1|1|1|1|1|1| -> the MSB
 *         |1|1|1|1|1|1|
 *         |0|0|1|1|0|0|
 *         |0|0|1|1|0|0|
 *         |0|0|1|1|0|0|
 *         |0|0|1|1|0|0|
 *         |0|0|1|1|0|0|
 *         |0|0|0|0|0|0| -> the LSB
 *         +-+-+-+-+-+-+
 * </pre>        
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_CUBE_BITMAP_FONT_H__
#define __ARDUINO_CUBE_BITMAP_FONT_H__ 1

#include <SeekableInputStream.h>

class BitmapFont {

protected:

    /**
     * Font header.
     */
    struct Header {
        unsigned char info;
        unsigned char characterWidth;
        unsigned char characterHeight;
        unsigned char sequenceCount;
    };
    Header header;

    /**
     * Glyph length.
     */
    unsigned char glyphLength;

    /**
     * Input stream which font data comes from.
     */
    SeekableInputStream* inputStream;

    /**
     * Data offset. It is the point when the header ends.
     */
    unsigned int dataOffset;

public:

    /**
     * Public constructor.
     * 
     * @param inputStream       The associated input stream.
     */
    BitmapFont(SeekableInputStream* inputStream);

    /**
     * Gets the font info.
     * 
     * @return                  Font info entry.
     */
    unsigned char getInfo();

    /**
     * Gets the character width.
     * 
     * @return                  The width of a char.
     */
    unsigned char getCharacterWidth();

    /**
     * Gets the character height.
     * 
     * @return                  The height of a char.
     */
    unsigned char getCharacterHeight();

    /**
     * Gets the sequence count.
     * 
     * @return                  The number of sequences.
     */
    unsigned char getSequenceCount();

    /**
     * Gets the glyph length.
     * 
     * @return                  The length of the glyph.
     */
    unsigned char getGlyphLength();

    /**
     * Gets the array of bytes representing the given character.
     * 
     * @param buf               The buffer.
     * @param c                 The character.
     * @return                  The number of bytes read.
     */
    virtual unsigned char readGlyphData(unsigned char *buf, char c);

protected:

    /**
     * Gets the offset to the given character.
     * 
     * @param c                 The character to be used.
     * @return                  The offset.
     */
    virtual unsigned int getGlyphOffset(char c);
};

#endif /* __ARDUINO_CUBE_BITMAP_FONT_H__ */
