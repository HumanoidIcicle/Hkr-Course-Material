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
