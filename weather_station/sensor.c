/* Header Files Pre Libraries */
#include "f_cpu.h"

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>

/* Header Files Post Libraries */
#include "sensor.h"

/* Constant Post Libraries*/
#define LED_RED			PC7

/* Body */
void sensor_init(){
	temperature_max = -100;
	temperature_min = 100;
	humidity_max = -100;
	humidity_min = 100;
	brightness_max = -10000;
	brightness_min = 10000;
}

void read_temperature(){
	sensor_temperature = read_adc(TEMPERATURE_SENSOR) * 4.88 * 0.1 - 273.15;
	add_temperature(sensor_temperature);
}

void read_humidity(){
	sensor_humidity =  (read_adc(HUMIDITY_SENSOR) * 4.88 * 0.1 - 80) / 3;
	add_humidity(sensor_humidity);
}

void read_brightness(){
	sensor_brightness =  read_adc(BRIGHTNESS_SENSOR) * 4.88 * 0.001 * 851.06383;
	add_brightness(sensor_brightness);
}

void add_temperature(int temperature){
	temperature_sum += temperature;
	temperature_quantity++;
	temperature_average = temperature_sum / temperature_quantity;
	
	if(temperature < temperature_min) temperature_min = temperature;
	if(temperature > temperature_max) temperature_max = temperature;
}

void add_humidity(int humidity){
	humidity_sum += humidity;
	humidity_quantity++;
	humidity_average = humidity_sum / humidity_quantity;
	
	if(humidity < humidity_min) humidity_min = humidity;
	if(humidity > humidity_max) humidity_max = humidity;
}

void add_brightness(int brightness){
	brightness_sum += brightness;
	brightness_quantity++;
	brightness_average = brightness_sum / brightness_quantity;
	
	if(brightness < brightness_min) brightness_min = brightness;
	if(brightness > brightness_max) brightness_max = brightness;
}

void display_temperature(){
	read_temperature();
	
	clear_display();
	
	write_str_display("Temperature: ");
	write_int_display(sensor_temperature);
	write_str_display("C");
	
	display_line_bottom();
	
	write_str_display("Average: ");
	write_int_display(temperature_average);
	write_str_display("C");
	
	_delay_ms(3000);
	clear_display();
	display_line_top();
	
	write_str_display("Max: ");
	write_int_display(temperature_max);
	write_str_display("C");
	
	display_line_bottom();
	
	write_str_display("Min: ");
	write_int_display(temperature_min);
	write_str_display("C");
}

void display_humidity(){
	read_humidity();
	
	clear_display();
	
	write_str_display("Humidity: ");
	write_int_display(sensor_humidity);
	write_str_display("%");
	
	display_line_bottom();
	
	write_str_display("Average: ");
	write_int_display(humidity_average);
	write_str_display("%");
	
	_delay_ms(3000);
	clear_display();
	display_line_top();
	
	write_str_display("Max: ");
	write_int_display(humidity_max);
	write_str_display("%");
	
	display_line_bottom();
	
	write_str_display("Min: ");
	write_int_display(humidity_min);
	write_str_display("%");
}

void display_brightness(){
	read_brightness();
	
	clear_display();
	
	write_str_display("Light: ");
	write_int_display(sensor_brightness);
	write_str_display("Lux");
	
	display_line_bottom();
	
	write_str_display("Average: ");
	write_int_display(brightness_average);
	write_str_display("Lux");
	
	_delay_ms(3000);
	clear_display();
	display_line_top();
	
	write_str_display("Max: ");
	write_int_display(brightness_max);
	write_str_display("Lux");
	
	display_line_bottom();
	
	write_str_display("Min: ");
	write_int_display(brightness_min);
	write_str_display("Lux");
}

void display_warning(){
	warning_active = 0;
	
	read_temperature();
	read_humidity();
	read_brightness();
	
	clear_display();
	
	if(sensor_temperature < 0){
		diod_active();
		write_str_display("Watch out ");
		display_line_bottom();
		write_str_display("for ice!");
		_delay_ms(3000);
		clear_display();
		diod_reset();
		warning_active = 1;
	}
	
	if(sensor_temperature > 30){
		diod_active();
		write_str_display("Too hot ");
		display_line_bottom();
		write_str_display("to handle!");
		_delay_ms(3000);
		clear_display();
		diod_reset();
		warning_active = 1;
	}
	
	if(sensor_brightness > 4200){
		diod_active();
		write_str_display("Watch out ");
		display_line_bottom();
		write_str_display("for glare!");
		_delay_ms(3000);
		clear_display();
		diod_reset();
		warning_active = 1;
	}
	
	if(sensor_brightness < 4000){
		diod_active();
		write_str_display("Too dark ");
		display_line_bottom();
		write_str_display("to see!");
		_delay_ms(3000);
		clear_display();
		diod_reset();
		warning_active = 1;
	}
	
	if(sensor_humidity < 20){
		diod_active();
		write_str_display("Air too ");
		display_line_bottom();
		write_str_display("dry!");
		_delay_ms(3000);
		clear_display();
		diod_reset();
		warning_active = 1;
	}
	
	if(sensor_humidity > 70){
		diod_active();
		write_str_display("Hard to ");
		display_line_bottom();
		write_str_display("breath!");
		_delay_ms(3000);
		clear_display();
		diod_reset();
		warning_active = 1;
	}
	
	if(warning_active == 0){
		write_str_display("No warnings!");
		}else{
		write_str_display("All warnings");
		display_line_bottom();
		write_str_display("displayed!");
	}
	
}