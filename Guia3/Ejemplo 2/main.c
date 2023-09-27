#include <main.h>
#use delay(clock=4000000)
#fuses XT,NOWDT
#use standard_io(B)
#int_TIMER0
void TIMER0_isr(void) {
	output_toggle(PIN_B0);
	set_timer0 (0x06);
} //Se recarga el timer0

void main() {
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2); //Configuraci�n timer0
	set_timer0 (0x06); //Carga del timer0
	enable_interrupts(INT_TIMER0); //Habilita interrupci�n timer0
	enable_interrupts(global); //Habilita interrupci�n general
	while (1); //bucle infinito
}
