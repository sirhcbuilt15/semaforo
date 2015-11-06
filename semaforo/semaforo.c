#include <avr/io.h>
#include <util/delay.h>

/*
  Atmega8 ports & Arduino pins:
  port B -> digital pins 8-13
  port C -> analog input pins 0-5
  port D -> digital pins 0-7

  Connect a LED between pin 13 and GND.

	Pin 13 as output -> The system is ready
	Pin 12 as output -> RED Light
	Pin 11 as output -> YELLOW Light
	Pin 10 as output -> GREEN Light
	Pin  9 as output -> RED Light for 'peaton'
	Pin  8 as output -> GREEN Light for 'peaton'
	Pin  7 as input	 -> Peaton esperando pasar, llamada. 
 */

#define RED_C PB4
#define YELLOW_C PB3
#define GREEN_C PB2
#define RED_H PB1
#define GREEN_H PB0
#define RED_T 3000 		// 5 segundos
#define YELLOW_T 2000		// 3 segundos
#define GREEN_T 3000		// 5 segundos
#define SHORT_T 400		// 0.2 segundos

int on(int led);
int off(int led);

int main(void)
{
  /* Initialization, set PB5 (arduino digital pin 13) as output */
  	DDRB |= (1<<PB5);		//output
	DDRB |= (1<<PB4);		//output
	DDRB |= (1<<PB3);		//output
	DDRB |= (1<<PB2);		//output
	DDRB |= (1<<PB1);		//output
	DDRB |= (1<<PB0);		//output

	//	DDRB = (1<<PB5) | (1<<PB4) | (1<<PB3) | (1<<PB2) | (1<<PB1) | (1<<PB0)  PROBAR ESTA CONFIGURACION
	
	DDRB |= (0<<PB7);		//input

  while (1) 
  {
		// SECUENCIA NORMAL		
		/*on(RED_C);
		on(GREEN_H);
		_delay_ms(RED_T);
		off(RED_C);
		off(GREEN_H);
		on(GREEN_C);
		on(RED_H);
		_delay_ms(GREEN_T);
		off(GREEN_C);
		on(YELLOW_C);
		_delay_ms(YELLOW_T);
		off(YELLOW_C);
		off(RED_H);*/

	on(RED_C);
	_delay_ms(SHORT_T);
	off(RED_H);
	on(GREEN_H);
	_delay_ms(GREEN_T);
	off(GREEN_H);
	_delay_ms(SHORT_T);
	on(GREEN_H);
	_delay_ms(SHORT_T);
	off(GREEN_H);
	_delay_ms(SHORT_T);
	on(GREEN_H);
	_delay_ms(SHORT_T);
	off(GREEN_H);
	_delay_ms(SHORT_T);
	on(GREEN_H);
	_delay_ms(SHORT_T);
	off(GREEN_H);
	_delay_ms(SHORT_T);
	on(GREEN_H);
	_delay_ms(SHORT_T);
	

	off(GREEN_H);
	on(RED_H);
	_delay_ms(SHORT_T);
	off(RED_C);

	on(GREEN_C);
	_delay_ms(GREEN_T);
	off(GREEN_C);
	on(YELLOW_C);
	_delay_ms(YELLOW_T);
	off(YELLOW_C);
	_delay_ms(SHORT_T);
	on(YELLOW_C);
	_delay_ms(SHORT_T);
	off(YELLOW_C);
	_delay_ms(SHORT_T);
	on(YELLOW_C);
	_delay_ms(SHORT_T);
	off(YELLOW_C);
	_delay_ms(SHORT_T);
	on(YELLOW_C);
	_delay_ms(SHORT_T);
	off(YELLOW_C);
	_delay_ms(SHORT_T);

	off(YELLOW_C);

  }
  return 0;
}

int on(int led)
{
	PORTB |= (1 << led);
	return 0;
}

int off(int led)
{
	PORTB &= ~(1 << led);
	return 0;
}

