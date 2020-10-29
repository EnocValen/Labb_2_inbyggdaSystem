#include <avr/io.h>

#include "timer.h"

void timer_init() {
	TCNT0 = 0;
	OCR0A = 156 - 1; // OCR0A =  [ (clock_speed(16000000) / Prescaler_value(1024)) * Desired_time_in_Seconds(0,01) ] - 1
	TCCR0A |= (1 << WGM01); // this puts this on CTC mode
	TCCR0B |= (1 << CS02) | (1 << CS00); // This line puts the prescaler on 1024

}

