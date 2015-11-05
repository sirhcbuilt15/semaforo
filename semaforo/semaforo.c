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

#define RED_Car PB4
#define YELLOW_Car PB3
#define GREEN_Car PB2
#define RED_Human PB1
#define GREEN_Human PB0
#define RED_Time 3000 		// 3 segundos
#define YELLOW_Time 2000	// 2 segundos
#define GREEN_Time 3000		// 3 segundos

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

  while (1) d
  {
		encender(RED_Car);
		encender(GREEN_Human);
		_delay_ms(RED_Time);
		apagar(RED_Car);
		apagar(Green_Human);
		encender(GREEN_Car);
		encender(RED_Human);
		_delay_ms(GREEN_Time);
		apagar(GREEN_Car);
		encender(YELLOW_Car);
		_delay_ms(YELLOW_Time);
		apagar(YELLOW_Car);
		apagar(RED_Human);
  }
  return 0;
}

int encender(int led)
{
	PORTB |= (1 << led);
	return 0;
}

int apagar(int led)
{
	PORTB &= ~(1 << led);
	return 0;
}

