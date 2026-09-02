/*
 * Lab4 Task1.c
 *
 * Created: 2025-05-08 16:57:20
 * Author : JOSS0001
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000

void set_CTC(){
	DDRD = (1<<PIND5);
	TCCR1B = (1<< WGM12) | (1<<CS10) | (1<<CS12); //Timer1 CTC mode and prescaler 1024
	OCR1A = 15625; //Set compare value to give
	
	TIMSK1 = (1<< OCIE1A); //Enable output compare interrupt
}

ISR(TIMER1_COMPA_vect){
	PORTD ^= (1<<PIND5);
}

int main(void)
{
	set_CTC();
	sei();
	while (1);
}
