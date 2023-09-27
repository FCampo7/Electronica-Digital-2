/*
Realice una rutina que, por intermedio del Timer 0, cambie el valor del pin
RB1 cada 500ms. A su vez, el pin RB1 debe estar conectado al pin RB0 de forma que active
la interrupción externa del RB0 y en esta interrupción cambie el estado de un led en el pin
RB7
*/

#include <Problema 1.h>
#fuses XT,NOWDT
#byte PORTB=0x06
#BYTE TRISB=0x86

int cont=10;

#INT_EXT
void ext_isr(){
	output_toggle(PIN_B7);
}

#INT_TIMER0
void TIMER0_isr(){
	cont--;
	if(cont==0){
   	output_toggle(PIN_B1);
		cont=10;
	}
	set_timer0(0x40); //0x40=64=el valor para que sean 50ms => para que sea 500ms hay que interrumpir 10 veces
}
void main()
{
	TRISB=0x01;
	PORTB=0x00;
	port_b_pullups(TRUE);
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
	set_timer0(0x40);
	enable_interrupts(int_ext);
	ext_int_edge (L_TO_H);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);

	while(1);
}
