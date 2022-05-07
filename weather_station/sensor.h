#ifndef SENSOR_H_
#define SENSOR_H_

/* Constants */
#define TEMPERATURE_SENSOR	0b00000010
#define HUMIDITY_SENSOR		0b00000000
#define BRIGHTNESS_SENSOR	0b00000001

/* Variables */
volatile int sensor_temperature, sensor_humidity, sensor_brightness;
volatile int temperature_sum, temperature_quantity, temperature_average, temperature_min, temperature_max;
volatile int humidity_sum, humidity_quantity, humidity_average, humidity_min, humidity_max;
volatile int brightness_sum, brightness_quantity, brightness_average, brightness_min, brightness_max;
volatile int warning_active;

/* External Methods */
void adc_init(void);
int read_adc(uint8_t channel);
void write_str_display(char s[]);
void write_int_display(int i);
void clear_display();
void display_line_top();
void display_line_bottom();
void diod_active();
void diod_reset();

/* Methods */
void sensor_init();
void read_temperature();
void read_humidity();
void read_brightness();
void display_temperature();
void display_humidity();
void display_brightness();
void display_warning();
void add_temperature(int temperature);
void add_humidity(int humidity);
void add_brightness(int brightniss);


#endif /* SENSOR_H_ */