#include <avr/io.h>
#include "led.h"

void LED_init() {

	DDRD |= (1 << 6); // This is because expansionport is 6
}

