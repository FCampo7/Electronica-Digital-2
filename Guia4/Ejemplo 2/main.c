#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP
#define use_portb_lcd TRUE
#define use_portb_kbd TRUE
#include <lcd.c>
#include <kbd.c>

void main()
{
	char k;
	int x;
  	
	lcd_init();
	kbd_init();
  	
	port_b_pullups(TRUE);
  	
	lcd_putc("\fListo...\n");
  	
	while(TRUE)
	{
		k=kbd_getc();
		x=k-48;
	  	
		if(k!=0){
			if(k=='*')
				lcd_putc("\f");
			else {
				lcd_putc(k);
				delay_ms(500);
			  	
				printf(lcd_putc,"\fCar=%c",k);
				delay_ms(500);
			  	
				printf(lcd_putc,"\fCar=%u",k);
				delay_ms(500);
			  	
				printf(lcd_putc,"\fNum=%u",x);
				delay_ms(500);
			  	
				lcd_putc("\fListo...\n");
			}
		}
	}

}
