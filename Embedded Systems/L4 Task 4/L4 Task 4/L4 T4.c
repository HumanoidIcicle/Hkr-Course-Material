/*
 * L4 Task 4.c
 *
 * Created: 2025-05-09 14:43:07
 * Author : JOSS0001
 */ 

//Kinda works, but not quite. Bouncing sometimes
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void set_Rising(){
	DDRD |= (1<<PIND5);
	EICRA |= (3<<ISC00);//Rising edge to gen int req
	EIMSK = (1<<INT0);
}

ISR(INT0_vect){
	_delay_ms(20);
	PORTD ^= (1<<PIND5);
}

int main(void)
{
	set_Rising();
	sei();
	while(1);
}


