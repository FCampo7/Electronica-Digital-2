#include <main.h>

#BYTE PORTB=0x06
#BYTE TRISB=0x86


void main()
{
   TRISB=0xF0;
   PORTB=0x00;

   while(TRUE)
   {
      bit_set(PORTB,0);
      bit_set(PORTB,1);
      //TODO: User Code
   }

}
