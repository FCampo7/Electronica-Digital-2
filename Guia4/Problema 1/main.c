/*
Mostrar en la pantalla de un LCD el texto "Hello World", limpiar la
pantalla, y mostrar el texto "Bienvenidos a EDI2". Volver a limpiar la pantalla y mostrar el texto "Contador=" y 
seguido la cantidad de veces que se repitió el bucle.
*/

#include <main.h>
#define use_portb_lcd TRUE
#include <lcd.c>

void main()
{
  	
	unsigned int cont=0;

	lcd_init();
  	
	while(TRUE)
	{
		cont++;
		printf(lcd_putc,"\fHello World\n");
		delay_ms(500);
		printf(lcd_putc,"\fBienvenidos a \nEDI2");
		delay_ms(500);
		printf(lcd_putc,"\fContador=%u",cont);
		delay_ms(500);
	}

}
