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

void setup(){
	DDRD |= (1<<PIND3) | (1<<PIND4) | (1<<PIND5);
	TCCR1B = (1<<CS11) | (1<<CS12);
	OCR1A = 15625*2;
}

void delay(){
	if(TCNT1 == OCR1A){
		TCNT1 = 0;
	}
}

int main(void)
{
	setup();
	while(1){
		PORTD = (1<<PIND3); //4s
		delay();
		
		PORTD = (1<<PIND3) |(1<<PIND4); //2s
		for(int i = 0; i<2; i++){
			delay();
		}
		
		PORTD = (1<<PIND5); //6s
		for(int i = 0; i<3; i++){
			delay();
		}
		
		PORTD = (1<<PIND4); //2s
		for(int i = 0; i<2; i++){
			delay();
		}
	}
	return 0;
}

