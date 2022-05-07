/* Header Files Pre Libraries */
#include "button.h"

/* Libraries */
#include <avr/io.h>

/* Body */
void buttons_init(void){
	// Enable interrupt INT1
	
	GICR |= (1 << INT1);
	// Rising edge of INT1
	MCUCR |= (1 << ISC11) | (1 << ISC10);
}

void btn_pressed(){
	switch(btn_val){
		case BTN_11:
		start_display();
		break;
		case BTN_12:
		set_time_param();
		break;
		case BTN_13:
		increment_time_param();
		break;
		case BTN_14:
		decrement_time_param();
		break;
		case BTN_21:
		display_temperature();
		break;
		case BTN_22:
		display_humidity();
		break;
		case BTN_23:
		display_brightness();
		break;
		case BTN_31:
		display_clothing();
		break;
		case BTN_32:
		display_warning();
		break;
		case BTN_33:
		set_clock();
		break;
		case BTN_34:
		display_time();
		break;
		case BTN_44:
		clear_data();
		break;
		default:
		clear_display();
		write_str_display("Wrong button!");
	}
}