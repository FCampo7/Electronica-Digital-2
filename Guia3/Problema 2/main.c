/*
Realice una rutina que genere por intermedio del Timer 0 una señal cuadrada
de 0,4Khz en el pin RB0 y se conecte a un osciloscopio

T=1/f=1/400Hz=0,0025s => semiperiodo=0,00125s

=> x=100=0x64 con un prescaler de 8

*/
#include <main.h>

#BYTE PORTB=0x06
#BYTE TRISB=0x86

#INT_TIMER0
void TIMER0_isr(){
	output_toggle(PIN_B0);
	set_timer0(0x64);
}

void main(){

	TRISB=0x00;
	PORTB=0x00;
  	
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8); //Configuración timer0
	set_timer0(0x64);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);

	while(TRUE){}

}
