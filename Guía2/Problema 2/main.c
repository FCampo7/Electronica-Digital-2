#include <main.h>

#FUSES NOMCLR
#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BIT RA4=PORTA.4

void main()
{
   TRISA=0xEF;//Configuramos el pin RA4 como salida en lugar del RA5 porque RA5 es solo de entrada;
   PORTA=0x00;
   while(1)
   {
      if(bit_test(PORTA,4) == 1)
         RA4=0;
      else 
         RA4=1;
      delay_ms(500);
      //TODO: User Code
   }

}
