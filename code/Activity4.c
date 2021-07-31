#include <avr/io.h>
#include<util/delay.h>
int main()

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

int Activity3()
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
void USARTInit(uint16_t ubrr_value)
{
    //Set Baud Rate
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)& 0x00ff;
    //8 bit size
    UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);
    //Enable transmitter and reciever
    UCSR0B=(1<<RXCIE0)|(1<<TXCIE0)|(1<<TXEN0)|(1<<RXEN0);

}
char USARTReadChar()
{
    while(!(UCSR0A &(1<<RXC0))) //waiting till data is received
    {
        //do nothing
    }
    return UDR0;
}
void USARTWriteChar(char data)

{
    while (!(UCSR0A & (1<<UDRE0))) //waiting till data transmitted
    {
        //do nothing
    }
    UDR0=data;

}

void Activity4()
{

     USARTInit(103); //UBRR Value =(F_CPU/(16* 9600))-1(formula from lecture)

     char temp=0;
     temp = Activity3();

        if(temp==20)
        {
            USARTWriteChar(temp); // temperature=20 transmitted by microcontroller to serial monitor
            _delay_ms(200);
        }
         if(temp==25)
        {
            USARTWriteChar(temp); // temperature=25 transmitted by microcontroller to serial monitor
            _delay_ms(200);
        }
         if(temp==29)
        {
            USARTWriteChar(temp);//temperature=29 transmitted by microcontroller to serial monitor
            _delay_ms(200);
        }
         if(temp==33)
        {
            USARTWriteChar(temp);//temperature=33 transmitted by microcontroller to serial monitor
            _delay_ms(200);
        }

}
