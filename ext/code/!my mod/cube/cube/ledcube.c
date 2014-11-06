/*
fornax LED cube V1.2

Copyright (C) 2009 Andreas Fiessler aka fornax

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include "ledcube.h"
#include <stdlib.h>
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <math.h>
#include <avr/interrupt.h>
/*
//#include "ab.h" // not in use
//#include "rotation.h" // not in use
*/

// fornax timer0
// 256-176 = 80 counter value
// 20000000/256/80 = 976,56 interrupts per second
// 976,56/8 = 122 frames per second
void cube_show_init( void )		// timer0 function
{
	TCCR0B/*TCCR0*/ |= (1 << CS02)/* | (0 << CS00)/*useless*/;	// prescaler = 256	// ATmega1284 adapt
	TIMSK0/*TIMSK*/ |= (1 << TOIE0);	// enable timer overflow interrupt	// ATmega1284 adapt
}

ISR( TIMER0_OVF_vect /*TIMER2_COMPA_vect*/ )	// timer0 fornax overflow interrupt handler (timer2 chr compare match interrupt handler)	// ATmega1284 adapt
{
	TCNT0 = 0xB0; /*at least 0xA0 */	// fornax timer	// initial counter value = 176 (160)
	/* cli() not neccessary atm */	// global interrupt disable
	PORTC = 0x0;	// set layer enable off
	static uint8_t cube_show_layer = 0;
	asm volatile("nop"); /* wait longer to avoid unintentionally lighting bottom leds */
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	asm volatile("nop");
	for(uint8_t j = 0; j < 8; j++){
		PORTB = cube[cube_show_layer][j];
		asm volatile("nop");
		PORTA |= (1 << j);
		asm volatile("nop");
		PORTA = 0;
		asm volatile("nop");
	}
	PORTC |= (1 << cube_show_layer);
	asm volatile("nop");
	if (cube_show_layer < 7) {
		cube_show_layer++;
	} else {
		cube_show_layer = 0;
	}
}

/* basic transformations and view functions */

/* all leds off */
void cube_clear ( void )
{
	for (uint8_t i = 0; i < 8; i++){
		for (uint8_t j = 0; j < 8; j++){
			cube[i][j] = 0;
		}
	}
}

/* single layer clear to avoid flickering with auto cube */
void cube_clear_layer(uint8_t layer)
{
	for (uint8_t j = 0; j < 8; j++){
		cube[layer][j] = 0;
	}
}

/* all leds on */
void cube_full ( void )
{
	for (uint8_t i = 0; i < 8; i++){
		for (uint8_t j = 0; j < 8; j++){
			cube[i][j] = 255;
		}
	}
}
/* some test cubes */
void cube_cube_3 ( void )
{	
	cube[0][0] = 7;
	cube[0][1] = 7;
	cube[0][2] = 7;
	cube[1][0] = 7;
	cube[1][1] = 7;
	cube[1][2] = 7;
	cube[2][0] = 7;
	cube[2][1] = 7;
	cube[2][2] = 7;
}

void cube_cube_4_line ( void )
{
	cube[0][0] = 15;
	cube[0][1] = 9;
	cube[0][2] = 9;
	cube[0][3] = 15;
	cube[1][0] = 9;
	cube[1][3] = 9;
	cube[2][0] = 9;
	cube[2][3] = 9;
	cube[3][0] = 15;
	cube[3][1] = 9;
	cube[3][2] = 9;
	cube[3][3] = 15;
}

void cube_random( void )
{
	for ( uint8_t i = 0; i < 8; i++ ){
		for ( uint8_t j= 0; j < 8; j++) {
			cube[i][j] = rand()%255;
		}
	}
}

/* one layer */
void cube_test_z( void )
{
	for (uint8_t i = 0; i < 8; i++){
		for (uint8_t j = 0; j < 8; j++){
			cube[i][j] = 1;
		}
	}
}

void cube_test_y( void )
{
	for (uint8_t i = 0; i < 8; i++){
		cube[0][i] = 255;
	}
}

void cube_test_x( void )
{
	for (uint8_t i = 0; i < 8; i++){
		cube[i][0] = 255;
	}
}

/* show one frame */
void cube_show( void )
{

	asm volatile("nop");
	for (uint8_t i = 0; i < 8; i++){
		for(uint8_t j = 0; j < 8; j++){
			PORTB = cube[i][j];
			asm volatile("nop");
			PORTA |= (1 << j);
			asm volatile("nop");
			PORTA = 0;
			asm volatile("nop");
		}
		PORTC |= (1 << i);
		_delay_ms(1);
		PORTC = 0x00;
		asm volatile("nop");
		asm volatile("nop");
		asm volatile("nop");
		asm volatile("nop");
		asm volatile("nop");
	}
}

/* viewed through ISR by default, so just a delay */
void cube_show_loop( uint8_t cycle )
{
	for (uint16_t i = 0; i < cycle*2; i++){ 
		_delay_ms(8);
	}
}

/* some functions may flicker when the ISR views the cube
 * while transforming something -> use this loop */
void cube_show_loop_wo_int( uint8_t cycle )
{
	for (uint16_t i = 0; i < cycle*2; i++){
		cube_show();
	}
	
}