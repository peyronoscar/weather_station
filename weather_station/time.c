/* Libraries */
#include <stdio.h>
#include <string.h>

/* Header Files Post Libraries */
#include "time.h"

/* Body */
void time_init(){
	time_param_index = -1;
	time_param_year = YEAR;
	time_param_month = MONTH;
	time_param_day = DAY;
	time_param_hour = HOUR;
	time_param_minute = MINUTE;
	time_param_second = SECOND;
	
	time_set = 0;
}

void set_time_param(){
	clear_display();
	time_param_index++;
	
	switch (time_param_index){
		case 0:
		write_str_display("Year selected");
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(2000 + time_param_year);
		break;
		case 1:
		write_str_display("Month selected");
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_month);
		break;
		case 2:
		write_str_display("Day selected");
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_day);
		break;
		case 3:
		write_str_display("Hour selected");
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_hour);
		break;
		case 4:
		write_str_display("Minute selected");
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_minute);
		break;
		case 5:
		write_str_display("Second selected");
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_second);
		break;
		default:
		time_param_index = -1;
		set_time_param();
	}
	
}

void increment_time_param(){
	clear_display();
	
	switch (time_param_index){
		case 0:
		write_str_display("Year increased");
		time_param_year++;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(2000 + time_param_year);
		break;
		case 1:
		if(time_param_month == 12){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Month increased");
		time_param_month++;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_month);
		break;
		case 2:
		if(time_param_day == 31){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Day increased");
		time_param_day++;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_day);
		break;
		case 3:
		if(time_param_hour == 23){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Hour increased");
		time_param_hour++;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_hour);
		break;
		case 4:
		if(time_param_minute == 59){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Minute increased");
		time_param_minute++;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_minute);
		break;
		case 5:
		if(time_param_second == 59){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Second increased");
		time_param_second++;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_second);
		break;
		default:
		write_str_display("Wrong time param");
	}
}

void decrement_time_param(){
	clear_display();
	
	switch (time_param_index){
		case 0:
		if(time_param_year == 0){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Year decreased");
		time_param_year--;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(2000 + time_param_year);
		break;
		case 1:
		if(time_param_month == 1){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Month decreased");
		time_param_month--;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_month);
		break;
		case 2:
		if(time_param_day == 1){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Day decreased");
		time_param_day--;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_day);
		break;
		case 3:
		if(time_param_hour == 0){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Hour decreased");
		time_param_hour--;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_hour);
		break;
		case 4:
		if(time_param_minute == 0){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Minute decreased");
		time_param_minute--;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_minute);
		break;
		case 5:
		if(time_param_second == 0){
			write_str_display("Wrong input!");
			return;
		}
		
		write_str_display("Second decreased");
		time_param_second--;
		display_line_bottom();
		write_str_display("Current: ");
		write_int_display(time_param_second);
		break;
		default:
		write_str_display("Wrong time param");
	}
}

void display_time(){
	if(!time_set){
		write_str_display("Time not set!");
		return;
	}
	
	get_time();
	
	clear_display();
	
	write_int_display(2000 + current_year);
	write_str_display("-");
	
	if(current_month < 10) write_int_display(0);
	write_int_display(current_month);
	write_str_display("-");
	
	if(current_day < 10) write_int_display(0);
	write_int_display(current_day);
	
	display_line_bottom();
	
	if(current_hour < 10) write_int_display(0);
	write_int_display(current_hour);
	write_str_display(":");
	
	if(current_minute < 10) write_int_display(0);
	write_int_display(current_minute);
	write_str_display(":");
	
	if(current_second < 10) write_int_display(0);
	write_int_display(current_second);
}

void set_clock(){
	i2c_start(RTC_WRITE);
	i2c_write(0x00);
	i2c_write(calculate_clock_input(time_param_second) | (1 << 7) );
	i2c_write(calculate_clock_input(time_param_minute));
	i2c_write(calculate_clock_input(time_param_hour));
	i2c_write(0x04);
	i2c_write(calculate_clock_input(time_param_day));
	i2c_write(calculate_clock_input(time_param_month));
	i2c_write(calculate_clock_input(time_param_year));
	i2c_stop();
	
	clear_display();
	write_str_display("Time set!");
	time_set = 1;
}int calculate_clock_input(int input){	int input_tens = input / 10;
	int input_ones = input % 10;
	
	return (input_tens << 4) | input_ones;}void get_time(){
	i2c_start(RTC_WRITE);
	i2c_write(0x00);
	i2c_start(RTC_READ);
	read_second = i2c_read_ack();
	current_second = ((read_second & 0b01110000) >> 4) * 10 + (read_second & 0b00001111);
	read_minute = i2c_read_ack();
	current_minute = ((read_minute & 0b01110000) >> 4) * 10 + (read_minute & 0b00001111);
	read_hour = i2c_read_ack();
	current_hour = ((read_hour & 0b00010000) >> 4) * 10 + (read_hour & 0b00001111);
	
	i2c_start(RTC_WRITE);
	i2c_write(0x04);
	i2c_start(RTC_READ);
	read_day = i2c_read_ack();
	current_day = ((read_day & 0b00110000) >> 4) * 10 + (read_day & 0b00001111);
	read_month = i2c_read_ack();
	current_month = ((read_month & 0b00010000) >> 4) * 10 + (read_month & 0b00001111);
	read_year = i2c_read_nack();
	current_year = ((read_year & 0b11110000) >> 4) * 10 + (read_year & 0b00001111);
	
	i2c_stop();
}