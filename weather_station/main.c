/* Header Files Pre Libraries */
#include "f_cpu.h"

/* Constant Pre Libraries*/
#define BUTTON_MASK		0b11110000

/* Libraries */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>

/* Header Files Post Libraries */
#include "main.h"
#include "sensor.h"
#include "adc.h"
#include "display.h"
#include "button.h"
#include "time.h"
#include "diod.h"
#include "i2c.h"

/* Constant Post Libraries*/
#define KEY_ENCODER		PD3
#define LED_RED			PC7

/* Body */
int main(void){
	set_data_direction();
	buttons_init();
	diod_reset();
	clear_display();
	adc_init();
	time_init();
	sensor_init();
	i2c_init();
	
	sei();
	
	while (1){
		if(btn_flag){
			btn_flag = 0;
			btn_pressed();
		}
	}
}


void set_data_direction(){
	// Port A: Key encoder and sensor input
	DDRA = 0b00000000;
	
	// Port B: Display output
	DDRB = 0b11111111;
	
	// Port C: Diod output and clock input
	DDRC |= (1 << LED_RED);
	
	// Port D: Display output, clock interrupt input and key encoder interrupt input.
	DDRD |= DISPLAY_E;
	DDRD |= DISPLAY_RS;
	DDRD |= DISPLAY_RW;
	DDRD &= ~(1 << KEY_ENCODER);
}

void clear_data(){
	time_param_year = YEAR;
	time_param_month = MONTH;
	time_param_day = DAY;
	time_param_hour = HOUR;
	time_param_minute = MINUTE;
	time_param_second = SECOND;
	time_param_index = -1;
	
	sensor_temperature = 0;
	sensor_brightness = 0;
	sensor_humidity = 0;
	
	temperature_sum = 0;
	temperature_average = 0;
	humidity_sum = 0;
	humidity_average = 0;
	brightness_sum = 0;
	brightness_average = 0;
	
	temperature_max = -100;
	temperature_min = 100;
	humidity_max = -100;
	humidity_min = 100;
	brightness_max = -10000;
	brightness_min = 10000;
	
	temperature_quantity = 0;
	humidity_quantity = 0;
	brightness_quantity = 0;
	
	clear_display();
	write_str_display("Data cleared!");
}

ISR(INT1_vect){
	// Button interrupt
	btn_val = (PINA & BUTTON_MASK) >> 4;
	btn_flag = 1;
}