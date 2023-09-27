#include <main.h>
#define use_portb_lcd TRUE
#fuses XT,NOWDT,NOMCLR
#include <lcd.c>
#use standard_io(B)
#use standard_io(A)

enum funciones{med,cal,ini};

void medir(void){
	output_toggle(PIN_A2);
	output_low(PIN_A3);
	output_low(PIN_A4);
}

void calcular(void){
	output_toggle(PIN_A3);
	output_low(PIN_A2);
	output_low(PIN_A4);
}

void inicializar(void){
	output_toggle(PIN_A4);
	output_low(PIN_A3);
	output_low(PIN_A2);
}

void run_func(int numfunc){
	switch(numfunc){
		case med:
			medir();
			break;
		case cal:
			calcular();
			break;
		case ini:
			inicializar();
			break;
	}
}

void main()
{
  	
	char item=0;
	char n_menus = 3;
  	
	lcd_init();
  	
	printf(lcd_putc,"1) Medir");
  	
	while(TRUE)
	{
		if(input(PIN_A0)==1){
			item++;
			delay_ms(300);
			lcd_putc('\f');
		  	
			if(item>(n_menus-1)){
				item=0;
			}
			  	
			switch(item){
				case med:
					printf(lcd_putc,"1) Medir");
					break;
				case cal:
					printf(lcd_putc,"2) Calcular");
					break;
				case ini:
					printf(lcd_putc,"3) Inicializar");
					break;
			}
		}
		if(input(PIN_A1)==1)
		{
			delay_ms(300);
			run_func(item);
		}
	}

}
