/*
 * Lab3 Task 1.c
 *
 * Created: 2025-05-01 18:17:03
 * Author : JOSS0001
 */ 

#include <avr/io.h>
#define FCPU 16000000 //Clock frequency
#define BAUD 9600 //Desired bps
#define UBRR FCPU/BAUD/16 - 1 //For normal asynch mode

void setup_USART(unsigned int ubrr);
void  TransmitData(unsigned char data);
void delay(void);
unsigned char ReceiveData(void);

int main(void){
	setup_USART(UBRR);
	DDRD = 0x04;
	TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10); //Prescaler 1024
	
    while (1){
		unsigned char got = ReceiveData();
		if (got == '1'){
			delay();
		}
    }
}

void setup_USART(unsigned int ubrr){
	UBRR0H = (unsigned char)(ubrr>>8); //Move most sig byte of baud rate here
	UBRR0L = (unsigned char)ubrr; //Move least sig byte of baud rate here
	
	UCSR0B = (1<<RXEN0) | (1<<TXEN0); //*Enable receiver and transmitter
	UCSR0C = (0<<USBS0) | (3<<UCSZ00); //Set frame format: 8data, 1stop bit
}
void  TransmitData(unsigned char data){
	while (!(UCSR0A & (1<<UDRE0))); //Wait for empty transmit buffer
	UDR0 = data; //Put data into buffer, sends the data 
}
unsigned char ReceiveData(void)
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}
void delay(void){
	while (1){
		if (UCSR0A & (1<<RXC0)){ //Keep checking for new received data
			if (ReceiveData() == '0'){ //If new input is 0, turn off LED
				PORTD &= ~(1<<0x04);
				return;
			}
		}
		if (TCNT1 == 15625){ //Compare value for 1second
			TCNT1 = 0; //Reset counter
			PORTD ^= (1 << 0x4); //Toggle
		}
	}
}

