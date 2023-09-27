/*
Leer mediante un keypad los valores del 0 al 9 y prender los leds correspondientes.
En el caso del 8 prender el led 1 y 7, en el caso del 9, prender el led 2 y 7. En caso de presionar el * o el #, prender todos los leds.
*/

#include <main.h>
#fuses NOPROTECT,NOLVP,INTRC_IO
#define use_portb_kbd TRUE
#include <kbd.c>

#byte trisa=0x85
#byte porta=0x05
#byte trisb=0x86

void togglepin(int8 pin){
	output_high(pin);
	delay_ms(500);
	output_low(pin);
}

void main()
{
	kbd_init();
	port_b_pullups(0b11111110);

	trisa=0x00;
  	
	char k;
	int x;

	while(TRUE)
	{
		k=kbd_getc();
		x=k-48;
		if(k!=0){
			if(k=='*'||k=='#'){
				trisb&=0b11111110;
				porta=0xff;
				output_high(pin_b0);
				delay_ms(500);
				porta=0x00;
			}
			else {
				switch(x){
					case 0:
						togglepin(pin_a0);
						break;
					case 1:
						togglepin(pin_a1);
						break;
					case 2:
						togglepin(pin_a2);
						break;
					case 3:
						togglepin(pin_a3);
						break;
					case 4:
						togglepin(pin_a4);
						break;
					case 5:
						trisb&=0b11111110;
						porta=0x00;
						output_high(PIN_B0);
						delay_ms(500);
						break;
					case 6:
						togglepin(pin_a6);
						break;
					case 7:
						togglepin(pin_a7);
						break;
					case 8:
						porta=0b10000010;
						delay_ms(500);
						porta=0x00;
						break;
					case 9:
						porta=0b10000100;
						delay_ms(500);
						porta=0x00;
						break;
				}
			}
		}
	}

}
