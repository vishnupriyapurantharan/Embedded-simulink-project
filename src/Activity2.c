/**
 * @file Activity2.c
 * @author Vishnu priya P (vishnupvspriya@gmail.com)
 * @brief // ADC values of temperature from temperature sensor.
 * @version 0.1
 * @date 2021-07-28
 *
 * @copyright Copyright (c) 2021
 *
 */


#include <avr/io.h>
#include<util/delay.h>
#include "Activity2.h"
#define F_CPU 1600000UL

void InitADC()
{
    ADMUX=(1<<REFS0); //For ARef=Avcc
    ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//enabling ADC
}
uint16_t ReadADC(uint8_t ch)
{
    //Select ADC channel algorithm
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    //Start single conversion
    ADCSRA|=(1<<ADSC);
    //Wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));
    //clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF);
    return(ADC);

}
void Activity2()
{
          InitADC();
          uint16_t temp=0;
          temp=ReadADC(0); //select channel 0
          _delay_ms(200);

}
