#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdbool.h>

#define F_CPU 16000000
#define BAUD 9600
#define ubrr (F_CPU/16/BAUD - 1)

#define MAX_VALUES 10

void set_ADC(){
    ADMUX |= (1<<MUX1); //D2
    ADMUX |= (1<<REFS0); //Select reference vcc
    ADCSRA |= (1<<ADEN) | (1<<ADSC); //Enable and start
    ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2); //Prescaler
}
void set_USART(){
    UBRR0H = (ubrr>>8);
    UBRR0L = ubrr;
    UCSR0B = (1<<TXEN0);
    UCSR0C =  (1<<UCSZ00) | (1<<UCSZ01);
}
void transmit(char* value){
    while(*value){
        while(!(UCSR0A & (1<<UDRE0)));
        UDR0 = *value++;
    }
}

uint8_t readValues[MAX_VALUES];
int place = 0;
bool setFull = false;

int main(void)
{
    set_ADC();
    set_USART();
    while (1){
        if (!(ADCSRA & (1<<ADSC))){
            uint8_t read = (ADC>>2); //conversion result

            if (place < MAX_VALUES)
            {
                readValues[place] = read;
                place++;
            }
            else {
                setFull = true;
            }

            ADCSRA |= (1<<ADSC);
            _delay_ms(1000);
        }
        if (setFull){
            char stringed[10];

            for (int i = 0; i < MAX_VALUES; i++ )
            {
                itoa(readValues[i], stringed, 10);
                transmit(stringed);
                transmit("\n");
                _delay_ms(500);

            }
            place = 0;
            setFull = false;
        }

    }
}
