#include <avr/io.h>
#include "led.h"

void LED_init() {

	DDRB |= (1 << PB0);
}

void toggle_LED() {
	PORTB ^= (1 << PB0); // This is a oneliner that changes the condition of the LED 
						//regardless if the LED is on or off
}
