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
    /* Inse://www.youtube.com/watch?v=bWBlfSRlNC4t DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	unsigned char weightLimit = 0x8C;
	unsigned char totalWeight = 0x00;
	unsigned char balanceWeight = 0x00;
	unsigned char weightDifLimit = 0x50;
    while (1) {
	totalWeight = PINA + PINB + PINC;
	balanceWeight = PINA + PINC;
	PORTD = PORTD | totalWeight;
	if (totalWeight > weightLimit) {
		PORTD = PORTD | 0x01;
	}
	if (balanceWeight > weightDifLimit) {
		PORTD = PORTD | 0x02;
	}
    }
    return 1;
}
