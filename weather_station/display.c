/* Header Files Pre Libraries */
#include "f_cpu.h"

/* Libraries */
#include <util/delay.h>
#include <avr/io.h>

/* Header Files Post Libraries */
#include "display.h"

/* Body */
void set_command(char c) {
	_delay_ms(100);
	
	PORTB = c;
	PORTD |= DISPLAY_E;
	PORTD &= ~DISPLAY_RS;
	PORTD &= ~DISPLAY_RW;
	PORTD &= ~DISPLAY_E;
	PORTD |= DISPLAY_E;
}

void clear_display(){
	set_command(0x01);
	_delay_ms(10);
}

void display_line_top(){
	set_command(0x80);
}

void display_line_bottom(){
	set_command(0xC0);
}

void start_display(){
	set_command(0x3C);
	set_command(0x0F);
	
	_delay_ms(10);
	clear_display();
	_delay_ms(10);
	
	write_str_display("Welcome! Select ");
	display_line_bottom();
	write_str_display("time, please!");
}

void write_c_display(char c){
	_delay_us(100);
	
	PORTB = c;
	PORTD |= DISPLAY_E;
	PORTD |= DISPLAY_RS;
	PORTD &= ~DISPLAY_RW;
	PORTD &= ~DISPLAY_E;
	PORTD |= DISPLAY_E;
}

void write_str_display(char s[]){
	uint8_t i = 0;
	
	while(s[i]){
		write_c_display(s[i]);
		i++;
	}
}

void write_int_display(int i){
	if(i/10 == 0){
		write_c_display('0' + i%10);
	}else{
		write_int_display(i/10);
		write_int_display(i%10);
	}
}
