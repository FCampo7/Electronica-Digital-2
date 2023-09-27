/*
Realizar un programa y el esquemático en proteus para leer el estado de dos botones. Al presionar uno, se debe mostrar en el 
LCD el texto "Prendiendo". Y al presionar el otro, se debe mostrar en el LCD el texto "Apagando".
*/
#include <main.h>
#define use_portb_lcd TRUE
#include <lcd.c>

#BYTE PORTA=0x05
#BYTE TRISA=0x85

void prenderLcd(){
	lcd_putc('\f');
	output_high(pin_b0);
	output_b(0x00);
	output_high(pin_b0);
	output_b(0xC0);
	output_low(pin_b0);
}

void apagarLcd(){
	output_high(pin_b0);
	output_b(0x00);
	output_high(pin_b0);
	output_b(0x80);
	output_low(pin_b0);
}

void main()
{
	TRISA=0xFF;
	PORTA=0x00;
  	
	lcd_init();
  	
	lcd_putc("\f");

	while(TRUE)
	{
		if(input(PIN_A1)==1){
			delay_ms(300);
			prenderLcd();
			printf(lcd_putc,"\fPrendiendo");
		}
		if(input(PIN_A0)==1){
			delay_ms(300);
			printf(lcd_putc,"\fApagando");
			delay_ms(500);
			apagarLcd();
		}
	}

}
