/*
Realice una rutina que al leer una entrada por algún pin del RB4 al RB7,
mantenga prendido un led por 500ms en el pin RB2.
*/

#include <main.h>

#BYTE PORTB=0x06
#BYTE TRISB=0x86

#BIT RB2=PORTB.2 //Definimos RB2 como el pin 2 del puerto B

#define TMR0 0x40 //64 En hexa

int cont=10; //Contador para saber cuantos ciclos del timer de 50ms van hechos para llegar a los 500ms

#INT_TIMER0
void TIMER0_isr(){
	cont--; //Decrementamos para saber que ya paso un ciclo de 50ms
	if(cont<=0){ //Revisamos si se cumplen los 500ms
		RB2=0; //Ponemos en 0 el estado del pin B2 para que se apague el led
		cont=10; //Reseteamos el contador, por las dudas
		disable_interrupts(INT_TIMER0); //Deshabilitamos las interrupciones en el timer0 para que no siga entrando despues de los 500ms
	}
	set_timer0(TMR0); //Seteamos el timer0 con el valor de 64 que es aproximadamente 50ms
}

#INT_RB
void RB_isr(){
	RB2=1; //Ponemos en 1 el estado del pin B2 para que se prenda el led
	cont=10; //Inicializamos el contador en 10 para que haga (10 ciclos de 50ms) = 500ms
	set_timer0(TMR0); //Seteamos el timer0 con el valor de 64 que es aproximadamente 50ms
	enable_interrupts(INT_TIMER0); //Habilitamos las interrupciones del timer0 para que empiece a contar
}

void main()
{
	TRISB=0xF0; //Seteamos la parte alta del puerto B como entrada y la baja como salida
	PORTB=0x00; //Setemaos todos los pines del puerto B con 0;
  	
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256); //seteamos el timer 0 como interno y con un prescaler de 256
	set_timer0(TMR0); //seteamos el timer0 con el valor de 64 que es aproximadamente 50ms
	enable_interrupts(INT_RB); //habilitamos las interrupciones de los pines B7:B4
	enable_interrupts(GLOBAL); //Habilitamos las interrupciones globales

	while(TRUE);

}
