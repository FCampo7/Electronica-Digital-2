#include <main.h>
#FUSES XT, NOWDT
#use rs232(baud=9600, xmit=pin_b5, rcv=pin_b2, bits=8, parity=N)
//#include <LCD.c>

void main() {   
   int16 q;
   float p;
   
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   for(;;){
      set_adc_channel(0);
      delay_us(10);
      q=read_adc();
      p=5.0*q/1024.0;
      printf ("\fADC = %4ld", q);
      printf ("\n\nVoltage = %01.2fV", p);
      delay_ms(100);
   }
}
