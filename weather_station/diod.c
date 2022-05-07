/* Libraries */
#include <avr/io.h>

/* Header Files Post Libraries */
#include "diod.h"

/* Body */
void diod_active(){
	PORTC ^= (1 << LED_RED);
}

void diod_reset(){
	PORTC &= ~(1 << LED_RED);
}