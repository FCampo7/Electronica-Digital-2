#include <main.h>

#FUSES NOWDT
#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06

void intermitenciaPA(int bit, int16 ms){
   if(bit_test(PORTA, bit) == 1)
      bit_clear(PORTA, bit);
   else 
      bit_set(PORTA, bit);
   delay_ms(ms);
}

void main()
{
   TRISA=0xEF; //Configuramos el pin RA4 como salida en lugar del RA5 porque RA5 es solo de entrada;
   PORTA=0x00;
   
   TRISB=0x18;
   PORTB=0x00;
   
   while(1)
   {
      if(bit_test(PORTB, 3)==bit_test(PORTB, 4))
         intermitenciaPA(4, 500);
      else
         bit_clear(PORTA, 4);
   }

}
