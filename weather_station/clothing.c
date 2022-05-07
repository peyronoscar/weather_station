/* Header Files Pre Libraries */
#include "f_cpu.h"

/* Libraries */
#include <util/delay.h>
#include <stdio.h>
#include <string.h>

/* Header Files Post Libraries */
#include "sensor.h"
#include "clothing.h"

/* Body */
void display_clothing(){
	clear_display();
	
	read_temperature();
	read_humidity();
	read_brightness();
	
	calculate_clothing_top();
	calculate_clothing_middle();
	calculate_clothing_bottom();
	
	write_str_display("Top:");
	display_line_bottom();
	write_str_display(clothing_top);
	
	_delay_ms(3000);
	clear_display();
	
	write_str_display("Middle:");
	display_line_bottom();
	write_str_display(clothing_middle);
	
	_delay_ms(3000);
	clear_display();
	
	write_str_display("Bottom:");
	display_line_bottom();
	write_str_display(clothing_bottom);
	
}

void calculate_clothing_top(){
	if(sensor_temperature < 10){
		strncpy ( clothing_top, "Beanie", sizeof(clothing_top) );
		return;
	}
	
	if(sensor_temperature >= 10 && sensor_brightness > 4000){
		strncpy ( clothing_top, "Sun Hat", sizeof(clothing_top) );
		return;
	}
	
	strncpy ( clothing_top, "Cap", sizeof(clothing_top) );
}

void calculate_clothing_middle(){
	if(sensor_temperature < 15){
		strncpy ( clothing_middle, "Jacket", sizeof(clothing_middle) );
		return;
	}
	
	if(sensor_temperature >= 15 && sensor_humidity > 50){
		strncpy ( clothing_middle, "T-shirt", sizeof(clothing_middle) );
		return;
	}
	
	strncpy ( clothing_middle, "Cardigan", sizeof(clothing_middle) );
}

void calculate_clothing_bottom(){
	if(sensor_temperature >= 10 && sensor_brightness > 4000){
		strncpy ( clothing_bottom, "Shorts", sizeof(clothing_bottom) );
		return;
	}
	
	strncpy ( clothing_bottom, "Pants", sizeof(clothing_bottom) );
}