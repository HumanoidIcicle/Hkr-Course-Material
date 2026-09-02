/*
 * L4 Task 5.c
 *
 * Created: 2025-05-09 16:22:13
 * Author : JOSS0001
 */ 

/*
int main(void)
{
	DDRD |= 0xff;
	
	while (1){
		PORTD = (1<<PIND3);
		_delay_ms(4000);
		
		PORTD = (1<<PIND3) | (1<<PIND4);
		_delay_ms(2000);
		
		PORTD = (1<<PIND5);
		_delay_ms(6000);
		
		PORTD = (1<<PIND4);
		_delay_ms(2000);
		
	}
}
**/

#include <avr/io.h>
#define F_CPU 16000000
#define COMP_1s 1560

void setup(){
	DDRD |= (1<<PIND3) | (1<<PIND4) | (1<<PIND5);
	TCCR1B = (1<<CS10) | (1<<CS12);
}

void delay(uint8_t count){
	for(uint8_t i= 0; i<count; i++){
		TCNT1 = 0;
		while (TCNT1 < COMP_1s); //Run empty long as counter less than 1s
	}
}

int main(void)
{
	setup();
	while(1){
		PORTD = (1<<PIND3); //4s
		delay(4);
		
		PORTD = (1<<PIND3) |(1<<PIND4); //2s
		delay(2);
		
		PORTD = (1<<PIND5); //6s
		delay(6);
		
		PORTD = (1<<PIND4); //2s
		delay(2);
	}
}
