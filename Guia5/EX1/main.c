#include <16f88.h>
#device adc=10
#FUSES XT, NOWDT
#FUSES
#use delay(clock=4000000)
#include <LCD.c>

void main() {   
   int16 q;
   float p;

   setup_port_a(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL);
   lcd_init();
   
   for(;;){
      set_adc_channel(0);
      delay_us(20);
      q=read_adc();
      p=5.0*q/1024.0;
      printf (lcd_putc, "\fADC = %4ld", q);
      printf (lcd_putc, "\nVoltage = %01.2fV", p);
      delay_ms(100);
   }
}
