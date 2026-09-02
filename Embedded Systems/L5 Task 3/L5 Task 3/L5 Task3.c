/*
 * L5 Task 3.c
 *
 * Created: 2025-05-19 22:12:08
 * Author : JOSS0001
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>

void set_PWM() {
	TCCR1A |= (1<<COM1A1); //Non inverting
	TCCR1A |= (1<<WGM10) | (1<<WGM11); //Fast pwm mode, 10bit
	
	TCCR1B |= (1<<WGM12); //Top is 511
	TCCR1B |= (1<<CS11) | (1<<CS10); //prescalar 64
}

void set_ADC(){
	DDRB = (1<<PINB5);
	ADMUX |= (1<<MUX1); //D2
	ADMUX |= (1<<REFS0); 
	
	ADCSRA |= (1<<ADEN) | (1<<ADSC) | (1<<ADIE); 
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2); 
	sei();
}

// ISR(ADC_vect){
// 	OCR1A = ADC;//ADC 10bits
// 	ADCSRA |= (1<<ADSC);
// }

int main(void){
	set_ADC();
	set_PWM();
	while (1){
		if(!(ADCSRA & (1<<ADSC))){
			OCR1A = ADC; //ADC 10bits to 8bit equivalent
			ADCSRA |= (1<<ADSC);
		}
	}
}