#ifndef DISPLAY_H_
#define DISPLAY_H_

/* Constants */
#define DISPLAY_RS		(1 << PD0)
#define DISPLAY_RW		(1 << PD1)
#define DISPLAY_E		(1 << PD4)

/* Methods */
void write_c_display(char c);
void write_str_display(char s[]);
void write_int_display(int i);
void set_command(char c);
void clear_display();
void start_display();
void display_line_top();
void display_line_bottom();

#endif /* DISPLAY_H_ */