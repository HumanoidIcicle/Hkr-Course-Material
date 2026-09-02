/*
 * L5 Task 4.c
 *
 * Created: 2025-05-21 11:01:20
 * Author : JOSS0001
 */ 

/***** Include section ****************************************************/

#include <avr/io.h>
#include "lcd.h"
#include <util/delay.h>
#include <stdlib.h>

void set_Potentialmeter(){
	ADMUX |= (1<<MUX0);
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN) | (1<<ADSC);
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}

int main(void){
	lcd_init();
	set_Potentialmeter();
	
   while (1) {
	   while (ADCSRA & (1<<ADSC));  // Wait for completion
	   float read = (ADC * 5.0) / 1023; 
	   uint8_t adc[10];
	   dtostrf(read,6, 3, adc);
	   
	   lcd_putcmd(LCD_SET_CURSOR | FIRST_ROW);
	   lcd_puts(adc);
	   lcd_puts(" mV");
	   _delay_ms(50);
	   ADCSRA |= (1<<ADSC);  // Start conversion
	   
   }
}

