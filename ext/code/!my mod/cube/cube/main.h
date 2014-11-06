/*
 * Code to controll an 8x8x8 ledcube using avr
 * http://www.instructables.com/id/Led-Cube-8x8x8/
 * See lisence.txt for lisence.
 */

#ifndef MAIN_H
#define MAIN_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "cube.h"

// Define USART stuff
#define FOSC 20000000
//#define FOSC 14745600
#define BAUD 38400
#define MYUBRR (((((FOSC * 10) / (16L * BAUD)) + 5) / 10) - 1)
/* chr interrupt service routine (not compatible to fornax hardware/animations)
#define DATA_BUS PORTA
#define LAYER_SELECT PORTC
#define LATCH_ADDR PORTB
#define LATCH_MASK 0x07
#define LATCH_MASK_INV 0xf8
#define OE_PORT PORTB
#define OE_MASK 0x08
*/
// Red led on D2
#define LED_RED 0x04
// green led on d5
#define LED_GREEN 0x20
/* Green led D3
#define LED_GREEN 0x08
// Program led on D4
//#define LED_PGM 0x10; // not in use
*/
// Leds connected to port D
#define LED_PORT PORTD
// rs232 button on d4
#define RS232_BTN 0x10
/* Rs232 button on D5
#define RS232_BTN 0x20
*/
// main button on d6
#define MAIN_BTN 0x40
/* Main button on B4
#define MAIN_BTN 0x10
*/

void ioinit (void);
void bootmsg (void);
void rs232(void);

unsigned int bootwait (void);
/*
volatile unsigned char current_layer; // chr interrupt service routine
//volatile unsigned char pgm_mode; // not in use
*/

#endif

