/**
 * @file Activity3.c
 * @author Vishnu priya P
 * @brief // Generating PWM (Pulse width modulation) pulses with different Duty cycles.
 * @version 0.1
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
#include<util/delay.h>
#include "../inc/Activity2.h"

#define F_CPU 1600000UL

char Activity3()
{
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);//choosing 64 as prescalar as a function oc clock
    DDRB|=(1<<PB1); //set portB
    char t=0;
    Activity2();
    
    if((ADC>=0) && (ADC<=209))
    {
        OCR1A=205;      //20% PWM
        t=20;      
        _delay_ms(20);
    }


        else if ((ADC>=210) && (ADC<=509))
        {

        OCR1A=410;    //40% PWM
        t=25; 
        _delay_ms(200);

        }

        else if((ADC>=510) && (ADC<=709))
        {
            
         OCR1A=717;   //70% PWM
        t=29;
        _delay_ms(200);

        }

        else if((ADC>=710) && (ADC<=1024))
        {
            
        OCR1A=974;   //95% PWM
        t=33;
        _delay_ms(200);
            
        }

return t;  

}
