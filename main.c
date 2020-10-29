#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

uint8_t number = 0;

void main(void) {
    uart_init();
    timer_init();
    LED_init();

    while (1)
    {
        if (TIFR0 & (1 << OCF0A)) // Here it checks if OCF0A flags then it will increase number by one.
        {
            TIFR0 |= (1 << OCF0A);
            number++;
        }

        if (number >= 10) { // If the increase here goes all the way to ten then it will start from the beginning.
            toggle_LED();
            number = 0;
        }
    }
}