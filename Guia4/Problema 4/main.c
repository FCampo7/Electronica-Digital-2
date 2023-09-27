/*
Mostrar por 3 segundos un mensaje en el LCD que diga "Rotando mensaje en LCD 16x2". Luego mostrar el mensaje "EDI2" y moverlo 
hacia la derecha hasta llegar al final de la línea. Luego mostrar el mensaje en la línea inferior y moverlo 
hacia la derecha hasta llegar al final de la línea. Volver a mostrar el mensaje en la primer línea y volver a comenzar el ciclo.
*/

#include <main.h>
#define use_portb_lcd TRUE
#include <lcd.c>
#fuses XT,NOWDT,NOMCLR

#define TMR0 0x40 //0x40 = 64 ~= 50ms

unsigned int cont=60; //Contador para saber cuantos ciclos de 50ms pasaron //60 porque 50ms por 60 son 3000ms = 3s
unsigned int ciclo; //Para controlar en que estado estamos
signed int x; //Para manejar la posicion del texto

#INT_TIMER0
void TIMER0_isr(){
	cont--;
	if(cont==0){ //Controlamos si pasaron los 3s
		cont=60; //Reseteamos el contador, no es necesario hacerlo en el resto del programa
		lcd_putc("\f"); //limpiamos la pantalla LCD
		ciclo=1; //cambiamos el estado
		x=0; //ponemos x=0 para cuando se muestre el mensaje " EDI2" se muestre la E en la primera posicion del LCD
		disable_interrupts(INT_TIMER0); //Deshabilitamos la interrupcion despues de los 3 segundos
	}
	set_timer0(TMR0); //Reseteamos el timer0
}

void init_cicloLCD(){ //Funcion para inicializar el programa
	x=1; //Primera posicion del LCD
	cont=60; //Explicado en la declaracion
	ciclo=0; //Primer estado
	lcd_init(); //Inicilizamos el LCD
  	
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256); //Setup del timer0 como temporizador y con un preescaler de 256
	enable_interrupts(INT_TIMER0); // Habilitamos las interrupciones del timer0
	enable_interrupts(GLOBAL); // Habilitamos las interrupciones globales
	set_timer0(TMR0); //Seteamos el timer0
}

void mde_cicloLCD(){ //Funcion para controlar los ciclos del LCD
	switch(ciclo){
		case 0: //Muestra el mensaje "Rotando mensaje en LCD 16x2" utilizando las dos lineas del LCD
			lcd_gotoxy(x,1);
			printf(lcd_putc,"Rotando mensaje\nen LCD 16x2");
			break;
		case 1:
			lcd_gotoxy(x,1); //Arranca en el (0,1) para que no se vea el espacio
			printf(lcd_putc," EDI2"); //El espacio delante es para que no se repita la E hasta el final
			x++; //Incrementamos el valor de x para mover el texto hacia la derecha.
			delay_ms(100); //Esperamos 100ms
			if(x>12){ //Controlamos si se llegó al final de la linea 16-4=12 //-4 es por la cantidad de letras del string sin contar el espacio porque arrancamos desde 0
				ciclo=2; //Cambiamos al estado siguiente
				x=0; //Ponemos x en 0 para que no se vea el espacio
				lcd_putc('\f'); //Limpiamos el LCD
			}
			break;
		case 2: //Lo mismo que el anterior pero en la fila 2
			lcd_gotoxy(x,2);
			printf(lcd_putc," EDI2");
			x++;
			delay_ms(100);
			if(x>12){
				ciclo=3;
				x=1; //Ponemos x en 1 para mostrar la letra E ya que no hay espacio al inicio de la cadena
			}
			break;
		case 3: //Mostramos el mensaje "EDI2" en la primera linea, esparamos 500ms, habilitamos la interrupcion del timer0 y volvemos a comenzar el ciclo
			ciclo=0;
			lcd_gotoxy(x,1);
			printf(lcd_putc,"\fEDI2");
			delay_ms(500);
			lcd_putc('\f');
			enable_interrupts(INT_TIMER0);
			set_timer0(TMR0);
			break;
		default: //Encaso de que falle por algun motivo reinicializamos el la maquina de estado.
			init_cicloLCD();
			break;
	}
}

void main()
{
	init_cicloLCD();
	while(TRUE)
	{
		mde_cicloLCD();
	}
}
