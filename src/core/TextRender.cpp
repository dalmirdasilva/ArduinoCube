/**
 */

#ifndef __ARDUINO_CUBE_EFFECTS_TEXT_RENDER_CPP__
#define __ARDUINO_CUBE_EFFECTS_TEXT_RENDER_CPP__ 1

#include <TextRender.h>

TextRender::TextRender(Glcd *glcd, GlcdBitmapFont *font, GlcdGraphicState *graphicState) : glcd(glcd), font(font), graphicState(graphicState) {
}

void TextRender::setGlcd(Glcd *glcd) {
    this->glcd = glcd;
}

void TextRender::setFont(GlcdBitmapFont *font) {
    this->font = font;
}

void TextRender::setGraphicState(GlcdGraphicState *graphicState) {
    this->graphicState = graphicState;
}

Glcd *TextRender::getGlcd() {
    return this->glcd;
}

GlcdBitmapFont *TextRender::getFont() {
    return this->font;
}

GlcdGraphicState *TextRender::getGraphicState() {
    return this->graphicState;
}

void TextRender::printChar(unsigned char x, unsigned char y, const unsigned char c, unsigned char size) {

    unsigned char glyphBuf[font->getGlyphLength()];
    unsigned char rows, column = 0;

    // Read char data
    font->readGlyphData(glyphBuf, c);

    // Loop through character byte data
    for (unsigned char i = 0; i < font->getCharacterWidth(); i++, x += size) {

        rows = font->getCharacterHeight() / 8;

        // Loop for all rows.
        for (unsigned char r = 0; r < rows; r++) {

            // Column
            column = glyphBuf[r * font->getCharacterWidth() + i];

            // Loop through the vertical pixels
            for (unsigned char j = 0; j < font->getCharacterHeight() * size; j++) {

                unsigned char newY = y + (j * size) + (8 * r * size);

                // Check if the pixel should be plotted
                if ((column & (1 << j)) != 0) {

                    // The next two loops change the character's size
                    for (unsigned char k = 0; k < size; k++) {

                        for (unsigned char z = 0; z < size; z++) {

                            // Draws the pixel
                            glcd->plot(x + z, newY + k, graphicState->getColor());
                        }
                    }
                }
            }
        }
    }
}

unsigned char TextRender::printString(unsigned char left, unsigned char top, unsigned char right, unsigned char bottom, const unsigned char *text, unsigned char count, unsigned char size) {

    unsigned char x = left, y = top;
    unsigned char i;

    // Loop through the passed string
    for (i = 0; (i < count) && (text[i] != '\0'); i++) {

        // Performs character wrapping
        if (x + (font->getCharacterWidth() * size) > right || text[i] == '\n') {

            // Set x at left position
            x = left;

            // Set y at next position down
            y += (font->getCharacterHeight() * size) + graphicState->getLeading();

            // Do not print a space as first character of the line or new line.
            if (text[i] == ' ' || text[i] == '\n') {
                continue;
            }
        }

        // Out of printable area
        if (y + (font->getCharacterHeight() * size) >= bottom) {
            break;
        }

        // Print he char
        printChar(x, y, text[i], size);

        // Move the x position to the next char
        x += (font->getCharacterWidth() * size) + graphicState->getSpace();
    }
    return i;
}

#endif /* __ARDUINO_LIBRARY_GLCD_TEXT_CPP__ */
