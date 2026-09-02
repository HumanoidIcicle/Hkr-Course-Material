/*
 * Lab3 task2.c
 *
 * Created: 2025-05-01 22:06:59
 * Author : JOSS0001
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL  // Must define this first
#define BAUD 9600
#define UBRR (F_CPU/16/BAUD - 1)

void setup_USART(void);
unsigned char Receive(void);
void Transmit(unsigned char character);

int main(void) {
	setup_USART();
	DDRD = 0xff;
	
	char temp[20];
	unsigned char position = 0;
	
	while (1) {
		unsigned char got = Receive();
		if (got != '%') {
			temp[position] = got;
			position += 1;	
		}
		else {
			for (int i = position-1; i >= 0; i--){
				Transmit(temp[i]);
			}
			Transmit('\n');
		}
	}
}

void setup_USART(void) {
	UBRR0H = (unsigned char)(UBRR>>8);
	UBRR0L = (unsigned char)UBRR;
	
	UCSR0B = (1<<TXEN0) | (1<<RXEN0);
	UCSR0C = (1<<USBS0) | (3<<UCSZ00);
}

void Transmit(unsigned char character) {
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = character;
}

unsigned char Receive(void) {
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}
