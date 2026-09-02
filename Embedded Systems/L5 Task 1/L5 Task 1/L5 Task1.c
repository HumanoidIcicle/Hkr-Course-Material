/*
 * L5 Task 1.c
 *
 * Created: 2025-05-19 18:38:36
 * Author : JOSS0001
 */

#include <avr/io.h>

void set_80_PWM() {
	DDRD = (1<<PIND5);
	
	TCCR0A |= (1<<COM0B1); //Non inverting, clear OC0B
	TCCR0A |= (1<<WGM01) | (1<<WGM00); //Fast pwm mode, top is 255
	TCCR0B |= (1<<CS00) | (1<<CS01); //prescalar 64
	OCR0B = (0.8*255);
}
/*
void set_50() {
	DDRD = (1<<PIND6);
	TCCR0A |= (1<<COM0A1); //Non inverting, clear OC0A
	TCCR0A |= (1<<WGM01) | (1<<WGM00); 
	TCCR0B |= (1<<CS02); //prescalar 256

	OCR0A = (0.5*255);
}

void set_40() {
	DDRB = (1<<PINB1);
	TCCR1A |= (1<<COM1A1); //Non inverting
	TCCR1A |= (1<<WGM11); //Fast pwm mode, 9bit
	TCCR0B |= (1<<WGM12); //Top is 511
	TCCR1B |= (1<<CS12); //prescalar 256

	OCR1A = (0.4*511);
}*/

void set_20() {
	DDRB = (1<<PINB2);
	TCCR1A |= (1<<COM1B1);
	TCCR1A |= (1<<WGM11) | (1<<WGM10);
	TCCR0B |= (1<<WGM02);
	TCCR1B |= (1<<CS11) | (1<<CS10); //prescalar 64
	OCR1B = (0.2*511);
}

int main(void)
{
	set_80_PWM();
	// 	set_50();
	// 	set_40();
	set_20();

	while (1);
}