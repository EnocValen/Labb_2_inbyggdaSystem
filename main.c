#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"





int main(void) {
    uart_init();
    timer_init();
    LED_init();
    uint8_t i = 0;

    while (1) {     // Eternal while loop

        while (i <= 255) {       //This while loop incremenst all the way to 255 and then breaks out of it,
            OCR0A = i;          // inbetween those increments is a delay of 3 ms.
            _delay_ms(3);
            i++;
            if (i == 255)
                break;
        }

        while (i >= 0) {        //This while loop decrements all the way from 255 to 0 and then breaks out of it,
            OCR0A = i;          // inbetween those decrements is a delay of 3 ms.
            _delay_ms(3);
            i--;
            if (i == 0)
                break;
        }

    }
    return 0;
}