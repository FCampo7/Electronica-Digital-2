#include <main.h>

#FUSES NOWDT

#BYTE PORTA=0x05
#BYTE TRISA=0x85
#BYTE PORTB=0x06
#BYTE TRISB=0x86


void intermitencia(int pa, int16 ms){
   if(bit_test(PORTA, pa)==1)
      bit_clear(PORTA, pa);
   else
      bit_set(PORTA, pa);
   delay_ms(ms);
}

void main()
{

   TRISA=0xEF;
   PORTA=0x00;
   TRISB=0x18;
   PORTB=0x00;

   while(1)
   {

      if(bit_test(PORTB, 3)==bit_test(PORTB, 4)){
         intermitencia(4, 500);
      }
      else
         bit_clear(PORTA, 4);
   }

}
