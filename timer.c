#include <avr/io.h>

#include "timer.h"

void timer_init() {
	TCCR0A |= (1 << WGM00) | (1 << WGM01); // This is to make fast PWM mode
	TCCR0A |= (1 << COM0A1); // This is for non inverting mode
	TCCR0B |= (1 << CS01) | (1 << CS00); // This is for prescaler 64

}

