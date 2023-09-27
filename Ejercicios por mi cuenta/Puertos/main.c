#include <main.h>

#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06
#BIT RA1=PORTA.1
#BIT RA2=PORTA.2
#BIT RB1=PORTB.1
#BIT RB2=PORTB.2

void main()
{

   TRISA=0xFF;
   PORTA=0x00;
   TRISB=0x00;
   PORTB=0x00;

   while(TRUE)
   {
      if(bit_test(PORTA, 1)==1)
         RB1=1;
      else
         RB1=0;
      if(bit_test(PORTA, 2)==1)
         RB2=1;
      else
         RB2=0;
      //TODO: User Code
   }

}
