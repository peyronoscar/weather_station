#ifndef BUTTON_H_
#define BUTTON_H_

/* Constants */
#define MASK	0b11110000
#define BTN_11	3
#define BTN_12	2
#define BTN_13	1
#define BTN_14	0
#define BTN_21	7
#define BTN_22	6
#define BTN_23	5
#define BTN_24	4
#define BTN_31	11
#define BTN_32	10
#define BTN_33	9
#define BTN_34	8
#define BTN_41	15
#define BTN_42	14
#define BTN_43	13
#define BTN_44	12

/* Variables */
volatile int btn_val, btn_flag;

/* External Methods */
void start_display();
void set_time_param();
void increment_time_param();
void decrement_time_param();
void display_temperature();
void display_humidity();
void display_brightness();
void display_clothing();
void display_warning();
void clear_data();
void display_time();
void write_str_display(char s[]);
void set_clock();
void clear_display();

/* Methods */
void buttons_init();
void btn_pressed();

#endif /* BUTTON_H_ */