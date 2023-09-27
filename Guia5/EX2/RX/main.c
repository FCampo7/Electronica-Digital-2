#include <main.h>
#include <16f88.h>
#fuses hs, nowdt, noprotect, noput
#use delay(clock=4M)
#use RS232(baud=9600, rcv=pin_b2, bits=8, parity=N)
#use standard_io(b)

void main() {
   char valor;
   set_tris_b(0x00);
   output_b(0x00);
   set_tris_a(0x00);
   output_a(0x00);
   while(TRUE) {
      valor = getc();
      switch(valor) {
         case '1': output_toggle(pin_a0); break;
         case '2': output_toggle(pin_a1); break;
         case '3': output_toggle(pin_a2); break;
         case '4': output_toggle(pin_a3); break;
      }
   }
}
