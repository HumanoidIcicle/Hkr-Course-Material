/*
 * L4 Task 6.c
 *
 * Created: 2025-05-10 14:29:55
 * Author : JOSS0001
 */ 
#include <avr/io.h>
#define F_CPU 16000000
#define WAIT_2s 1500

void set_Timer(){
	DDRD = (1<<PIND5);
	PORTD &= ~(1<<PIND5);
	
	TCCR1B = (1<<CS10) | (1<<CS12);
}

void delay(){
	while(TCNT1 < WAIT_2s);
	TCNT1 = 0;
}

int main(void){
	set_Timer();
	while(1){
		if (PIND & (1<<PIND2)){
			PORTD ^= (1<<PIND5);
			delay();
		}
	}
}
