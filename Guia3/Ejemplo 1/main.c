#include <main.h>
#fuses XT, NOWDT, PUT, NOWRT
#use delay (clock = 4000000)
#use fast_io(B)

int1 cambio = 0; // variable de cambio

#INT_EXT // Atención a interrupción por cambio en RB0

ext_isr(){ //Función de interrupción
	output_toggle(PIN_B7);
}
void main(){
	set_tris_B(0x01); // B0 como entrada, B7 como salida
	output_low(PIN_B7); // apaga LED
	port_b_pullups(TRUE); //pull-up para RB0
	enable_interrupts(int_ext); // Habilita int. RB0
	ext_int_edge (L_TO_H); // por flanco de subida
	enable_interrupts(GLOBAL); // Habilita int. general
	while(1) { // Bucle infinito de espera
	}
}
