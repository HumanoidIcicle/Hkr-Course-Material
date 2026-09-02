/*
 * Lab3_task3.c
 *
 * Created: 2025-05-02 10:16:03
 * Author : JOSS0001
 */ 

#include <avr/io.h>
#define FCPU 16000000
#define BASE 15625
#define BAUD 9600
#define UBRR FCPU/BAUD/16 - 1

void setup_USART(unsigned int ubrr);
void  TransmitData(unsigned char data);
unsigned char ReceiveData(void);
void toggle(uint16_t wait);

/*Arduino1 to receive and retransmit a character*/
// int main(void){
// 	setup_USART(UBRR);
// 	DDRD = 0x04;
// 	TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10);
// 	
// 	while (1){
// 		TransmitData(ReceiveData());
// 	}
// }

/*Program for the second arduino connected to a LED.*/
int main(void){
	setup_USART(UBRR);
	DDRD = 0x04;
	TCCR1B |= (1<<CS12) | (0<<CS11) | (1<<CS10);
	unsigned char supreet;
	while (1){
		if (UCSR0A & (1<<RXC0)){ //Keep checking for update in data register
			supreet = UDR0;
		}
		if(supreet == '0'){ //Delay 1s
			toggle(BASE);
		}
		else if(supreet == '1'){ //Delay 4s
			toggle(BASE*4);
		}
	}
}


void setup_USART(unsigned int ubrr){
	UBRR0H = (unsigned char)(ubrr>>8); 
	UBRR0L = (unsigned char)ubrr;  
	
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = (0<<USBS0) | (3<<UCSZ00);
}

void  TransmitData(unsigned char data){
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

unsigned char ReceiveData(void){
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void toggle(uint16_t wait){
	if (TCNT1 == wait){
		TCNT1 = 0;
		PORTD ^= (1 << 0x4);
	}
}

