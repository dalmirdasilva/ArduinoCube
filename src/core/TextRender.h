/**
 * Arduino Graphic LCD Library
 * 
 * TextRender.h
 * 
 * The functions to draw text in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_TEXT_H__
#define __ARDUINO_LIBRARY_GLCD_TEXT_H__ 1

#include <GlcdRectangle.h>
#include <GlcdBitmapFont.h>
#include <GlcdGraphicState.h>

class TextRender {
protected:
    
    /**
     * The Glcd driver.
     */
    Glcd *glcd;
    
    /**
     * The used font.
     */
    GlcdBitmapFont *font;
    
    /**
     * The used graphic state.
     */
    GlcdGraphicState *graphicState;

public:

    /**
     * Public constructor.
     * 
     * @param glcd                  The glcd driver.
     * @param font                  The font to be used.
     * @param graphicState          The graphic state instance.
     */
    TextRender(Glcd *glcd, GlcdBitmapFont *font, GlcdGraphicState *graphicState);

    /**
     * Sets the driver.
     * 
     * @param glcd                  The glcd driver.
     */
    void setGlcd(Glcd *glcd);

    /**
     * Sets the font.
     * 
     * @param font                  The font to be used.
     */
    void setFont(GlcdBitmapFont *font);

    /**
     * Sets the graphic state.
     * 
     * @param graphicState          The graphic state instance.
     */
    void setGraphicState(GlcdGraphicState *graphicState);

    /**
     * Gets the glcd driver.
     * 
     * @return                      The glcd driver.
     */
    Glcd *getGlcd();

    /**
     * Gets the font.
     * 
     * @return                      The font.
     */
    GlcdBitmapFont *getFont();

    /**
     * Gets the graphic state.
     * 
     * @return                          The graphic state instance.
     */
    GlcdGraphicState *getGraphicState();

    /**
     * Write a char on a graphic lcd
     * 
     * NOTE: (x,y) is the upper left coordinate of the first letter
     * 
     * @param x                         The X position.
     * @param y                         The Y position.
     * @param c                         The char.
     * @param size                      The size.
     */
    virtual void printChar(unsigned char x, unsigned char y, const unsigned char c, unsigned char size);

    /**
     * Write a char on a graphic lcd.
     * 
     * @param x                         The X position.
     * @param y                         The Y position.
     * @param c                         The char.
     */
    inline void printChar(unsigned char x, unsigned char y, const unsigned char c) {
        printChar(x, y, c, 1);
    }

    /**
     * Write a char on a graphic lcd.
     * 
     * @param p                         The point where the text char will be printed.
     * @param c                         The char.
     * @param size                      The size.
     */
    inline void printChar(GlcdPoint *p, const unsigned char c, unsigned char size) {
        printChar(p->getX(), p->getY(), c, size);
    }

    /**
     * Write a char on a graphic lcd.
     * 
     * @param p                         The point where the text char will be printed.
     * @param c                         The char.
     */
    inline void printChar(GlcdPoint *p, const unsigned char c) {
        printChar(p->getX(), p->getY(), c, 1);
    }
    
    /**
     * Write a text on a graphic lcd.
     * 
     * NOTE: (x,y) is the upper left coordinate of the first letter
     * 
     * @param left                      The rectangle left position.
     * @param top                       The rectangle top position.
     * @param right                     The rectangle right position.
     * @param bottom                    The rectangle bottom position.
     * @param text                      The text to be printed.
     * @param count                     The maximum number of chars to print.
     * @param size                      The text size.
     * @return                          The number of printed chars.
     */
    virtual unsigned char printString(unsigned char left, unsigned char top, unsigned char right, unsigned char bottom, const unsigned char *text, unsigned char count, unsigned char size);

    /**
     * Write a text on a graphic lcd.
     * 
     * NOTE: (x,y) is the upper left coordinate of the first letter
     * 
     * @param left                      The rectangle left position.
     * @param top                       The rectangle top position.
     * @param right                     The rectangle right position.
     * @param bottom                    The rectangle bottom position.
     * @param text                      The text to be printed.
     * @param count                     The maximum number of chars to print.
     * @return                          The number of printed chars.
     */
    inline unsigned char printString(unsigned char left, unsigned char top, unsigned char right, unsigned char bottom, const unsigned char *text, unsigned char count) {
        return printString(left, top, right, bottom, text, count, 1);
    }
    
    /**
     * Write a text on a graphic lcd.
     * 
     * NOTE: (x,y) is the upper left coordinate of the first letter
     * 
     * @param area                      The rectangle rectangle.
     * @param text                      The text, must has the '\0' terminator.
     * @param count                     The count.
     * @param size                      The size.
     * @return                          The number of printed characters.
     */
    inline unsigned char printString(GlcdRectangle *area, const unsigned char *text, unsigned char count, unsigned char size) {
        return printString(area->getLeft(), area->getTop(), area->getRight(), area->getBottom(), text, count, size);
    }
    
    /**
     * Write a text on a graphic lcd.
     * 
     * NOTE: (x,y) is the upper left coordinate of the first letter
     * 
     * @param area                      The rectangle rectangle.
     * @param text                      The text, must has the '\0' terminator.
     * @param count                     The count.
     * @return                          The number of printed characters.
     */
    inline unsigned char printString(GlcdRectangle *area, const unsigned char *text, unsigned char count) {
        return printString(area, text, count, 1);
    }
};

#endif /* __SDCC_LIBRARY_GLCD_TEXT_H__ */
