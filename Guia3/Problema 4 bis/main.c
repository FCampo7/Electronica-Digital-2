/*
Leyendo el estado de PB alto, mediante interrupciones. Asigne una función distinta para el estado de cada una de las 4 patas.
? Si la pata PB4 cambia de 0-1, prender un led, esperar 500ms y apagarlo.
? Si la pata PB5 cambia de 0-1, Disparar el timer0… de manera que por interrupción 1 segundo más tarde se prenda un led. Y 1 segundo más tarde se apague.
? Si la pata PB6 cambia de 0-1, copiar el estado de PB0-3 a PA0-3.
? Si la pata PB7 cambia de 0-1. Defínalo... Habilitar o deshabilitar el timer1 para que cada 500ms parpadee el led 
*/

#include <main.h>

#BYTE PORTA=0x05
#BYTE TRISA=0x85
#BYTE PORTB=0x06
#BYTE TRISB=0x86

#DEFINE MASKPA 0b11110000 //Mascara para obtener la parte alta de algun puerto
#DEFINE TMR0 0x40 //Seteamos el timer0 en 61 que es aprox 50ms
#DEFINE TMR1 0x0BDC //Este es el valor para 500ms en el timer1 (0,5s=(4/4000000)*8*(65536-TMR1))=>TMR1=3036

int cont=20; //Contamos 20 ciclos de 50ms para obtener 1 segundo
int toggleTimer1=0; //Variable para habilitar o deshabilitar el timer1

#INT_TIMER0
void TIMER0_isr(){
	cont--;
	if(cont<=0){ //Miramos si pasó un segundo
		output_toggle(PIN_B1); //Prendemos o apagamos el led
		cont=20; //Restauramos el contador en 20 para que pase otro segundo
		if(bit_test(PORTB,1)==0){ //Revisamos si el led esta apagado
			disable_interrupts(INT_TIMER0); //Deshabilitamos las interrupciones del timer0 para que no haya mas interrupciones luego de apagar el led
		}
	}
	set_timer0(TMR0); //Cargamos el timer0
}

#INT_TIMER1
void TIMER1_isr(){
	output_toggle(PIN_B1);
	set_timer1(TMR1); //Cargamos el timer1
}

#INT_RB
void RB_isr(){
	if(bit_test(PORTB,4)){ //Revisamos si se activo el pin 4
		output_high(PIN_B1); //Prendemos el led del pin B1
		delay_ms(500); //Esperamos 500ms
		output_low(PIN_B1); //Apagamos el led del pin B1
	}
	if(bit_test(PORTB,5)){ //Revisamos si se activo el pin 5, habilitamos la interrupcion del timer0 y seteamos el timer0 en 61 que es aprox 50ms
		cont=20;
		output_low(PIN_B1); //Apagamos el led, por si esta prendido
		enable_interrupts(INT_TIMER0); //Habilitamos el timer0
		disable_interrupts(INT_TIMER1); //Deshabilitamos el timer1
		toggleTimer1=0; //Seteamos la variable que controla si se habilita o deshabilita el timer1
		set_timer0(TMR0); //Cargamos el timer0 con el valor de TMR0
	}
	if(bit_test(PORTB,6)){ //Revisamos si se activo el pin 6
		/*Nos quedamos con la parte alta de A y llenamos con ceros la parte baja,
		luego obtenemos la parte baja de B y llenamos con cero la parte alta,
		finalmente hacemos un or entre ambos resultados para obtener la parte alta de A y la parte baja de B
		y lo asignamos al puerto A*/
		PORTA=((PORTA & MASKPA) | (PORTB & ~MASKPA));
	}
	if(bit_test(PORTB,7)){ //Revisamos si se activo el pin 7
		if(toggleTimer1==0){
			enable_interrupts(INT_TIMER1);
			toggleTimer1=1;
		}
		else {
			disable_interrupts(INT_TIMER1);
			output_low(PIN_B1);
			toggleTimer1=0;
		}
		set_timer1(TMR1); //Cargamos el timer1 con el valor de TMR1
	}
}

void main()
{
	TRISA=0x00;
	PORTA=0x00;
	TRISB=0xF0;
	PORTB=0x00;
  	
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256); //Inicializamos el timer0
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_8); //Inicializamos el timer1
	enable_interrupts(INT_RB); //Habilitamos las interrupciones de la parte alta del puerto B
	enable_interrupts(GLOBAL); //Habilitamos las interrupciones globales
  	
	while(TRUE);
}
