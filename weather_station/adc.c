/* Libraries */
#include <avr/io.h>

/* Header Files Post Libraries */
#include "adc.h"

/* Body */
void adc_init(void){
	// 16Mhz/128 = 125Khz the ADC reference clock
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
	
	// Voltage reference from Avcc (5v)
	ADMUX |= (1<<REFS0);
	
	// Turn on ADC
	ADCSRA |= (1<<ADEN);
}

int read_adc(uint8_t channel){
	// Clear the older channel that was read
	ADMUX &= 0b11100010;
	
	// Defines the new ADC channel to be read
	ADMUX |= channel;
	
	// Starts a new conversion
	ADCSRA |= (1<<ADSC);
	
	// Wait until the conversion is done
	while(ADCSRA & (1<<ADSC));
	
	// Returns the ADC value of the chosen channel
	return ADC;
}