/*
 * L4 Task 7.c
 *
 * Created: 2025-05-10 16:12:50
 * Author : JOSS0001
 */ 
// 
// //Main arduino code, connected to PC
// 
// #include <avr/io.h>
// #include <avr/interrupt.h>
// 
// #define F_CPU 16000000
// #define DELAY 15625
// 
// void setup(){
// 	DDRD = (1<<PIND5);
// 	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);
// 	OCR1A = DELAY;
// 	TIMSK1 = (1<<OCIE1A);
// 	sei();
// }
// 
// ISR(TIMER1_COMPA_vect){
// 	PORTD ^= (1<<PIND5);
// }
// 
// int main(void)
// {
// 	setup();
// 	while (1);
// }
// 
// 

//Arduino 2
#include <avr/io.h>
#include <avr/interrupt.h>

void setup(){
	DDRD = (1<<PIND5);
	DDRD &= ~(1<<PIND7);
	
	PCICR = (1<<PCIE2);
	PCMSK2 = (1<<PCINT7);
	sei();
}

ISR(PCINT2_vect)
{
	if(PIND & (1<<PIND7)){
		PORTD &= ~(1<<PIND5);
	}
	else {
		PORTD = (1<<PIND5);
	}
}

int main(void)
{
	setup();
	while(1);
}
*/