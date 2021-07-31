/**
 * @file Activity1.c
 * @author Vishnu priya P (vishnupvspriya@gmail.com) 
 * @brief // configuration of pins
 * @version 0.1
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include <util/delay.h>
#include "Activity3.h"
#include "Activity4.h"
#include "Activity2.h"



void Activity1()

{


    // Direction of port
    DDRB |= (1 << PB0);
    DDRD &= ~(1 << PD0);
    DDRD &= ~(1 << PD4);

    // PULL-UP configuration
    PORTD |= (1 << PD0);
    PORTD |= (1 << PD4);
    while (1)
    {
        // condition to check if both switches are on
        if (!(PIND&(1<<PD0)) && !(PIND&(1<<PD4)))
        {
            // set LED
            PORTB |= (1 << PB0);
            _delay_ms(200);
            Activity2();
            Activity3();
            Activity4();
        }
        else
        {
            // set off led
            PORTB &= ~(1 << PB0);
            _delay_ms(200);
        }

    }
}
