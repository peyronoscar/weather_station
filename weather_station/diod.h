/* Libraries */
/* Header Files */
/* Constants */
/* Variables */
/* External Methods */
/* Methods */

#ifndef DIOD_H_
#define DIOD_H_

/* Libraries */
#include <avr/io.h>

/* Constants */
#define LED_RED			PC7

/* Methods */
void diod_active();
void diod_reset();

#endif /* DIOD_H_ */