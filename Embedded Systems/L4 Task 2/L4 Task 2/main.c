/*
 * L4 Task 2.c
 *
 * Created: 2025-05-08 18:59:26
 * Author : JOSS0001
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#define CPU 16000000
#define BAUD 9600
#define ubrr (CPU/16/BAUD) - 1

volatile uint8_t sent = 0;

void set_USART(){
	DDRD = (1<<PIND5);
	UBRR0H = (uint8_t) (ubrr>>8);
	UBRR0L = (uint8_t) ubrr;
	
	UCSR0B = (1<<RXEN0) | (1<<RXCIE0);
	UCSR0C = (0<<USBS0) | (3<<UCSZ00);
}

void set_CTC(){
	DDRD = (1<<PIND5);
	OCR1A = 15624; //Set compare value to give

	TCCR1B = (1<< WGM12) | (1<<CS10) | (1<<CS12); //Timer1 CTC mode and prescaler 1024
	TIMSK1 = (1<< OCIE1A); //Enable output compare interrupt
}

ISR(TIMER1_COMPA_vect){
	if (sent){
		PORTD ^= (1<<PIND5);
	}
}

ISR(USART_RX_vect){
	unsigned char received = UDR0;
	if (received == '1'){
		sent = 1;
	}
	if (received == '0'){
		sent = 0;
		PORTD &= ~(1<<PIND5);
	}
}

// ISR(TIMER0_OVF_vect)

int main(void)
{
	set_USART();
	set_CTC();
	sei();
	while (1);
}

