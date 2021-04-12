/*	Author: ehsu027
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab 2  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char cntavail = 0x00;
    while (1) {
	cntavail = 0x04;

	if (PINA & 0x08) {
		cntavail--;
	}
	if (PINA & 0x04) {
		cntavail--;
	}
	if (PINA & 0x02) {
		cntavail--;
	}
	if (PINA & 0x01) {
		cntavail--;
	}
	PORTC = cntavail;
	if (cntavail == 0x00) {
		PORTC = 0x80;
	}
    }
    return 1;
}
