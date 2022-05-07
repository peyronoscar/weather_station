#ifndef CLOTHING_H_
#define CLOTHING_H_

/* Variables */
char clothing_top[20], clothing_middle[20], clothing_bottom[20];

/* Methods */
void display_clothing();
void calculate_clothing_top();
void calculate_clothing_middle();
void calculate_clothing_bottom();
void clear_display();
void display_line_bottom();
void write_str_display(char s[]);
void read_temperature();
void read_humidity();
void read_brightness();

#endif /* CLOTHING_H_ */