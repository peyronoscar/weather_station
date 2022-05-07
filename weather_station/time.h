#ifndef TIME_H_
#define TIME_H_

/* Constants */
#define YEAR			43
#define MONTH			1
#define DAY				2
#define HOUR			3
#define MINUTE			4
#define SECOND			5
#define I2C_READ		0x01
#define I2C_WRITE		0x00
#define RTC_READ		(0xDF)
#define RTC_WRITE		(0xDE)

/* Variables */
volatile int time_set;
volatile int read_year, read_month, read_day, read_hour, read_minute, read_second;
volatile int current_second, current_minute, current_hour, current_day, current_month, current_year;
volatile int time_param_index, time_param_year, time_param_month, time_param_day, time_param_hour, time_param_minute, time_param_second;

/* External Methods */
void clear_display();
void write_str_display(char s[]);
void write_int_display(int i);
void display_line_bottom();
uint8_t i2c_start(uint8_t address);
uint8_t i2c_write(uint8_t data);
void i2c_stop(void);
uint8_t i2c_read_nack(void);
uint8_t i2c_read_ack(void);

/* Methods */
void time_init();
void set_time_param();
void increment_time_param();
void decrement_time_param();
void display_time();
void display_line_bottom();
void get_time();
void set_clock();
int calculate_clock_input(int input);

#endif /* TIME_H_ */