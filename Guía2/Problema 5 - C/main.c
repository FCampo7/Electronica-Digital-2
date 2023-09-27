#include <main.h>

#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06
#BIT RA0=PORTA.0

void main()
{
   TRISA=0xFF;
   PORTA=0x00;
   TRISB=0x00;
   PORTB=0x00;
   unsigned int cont=0;
   int v[10]={63,6,91,79,102,109,125,7,127,103};
   
   while(TRUE)
   {
      if(RA0==0){
         delay_ms(300);
         cont=cont+1;
         if(cont>9)
            cont=0;
      }
      PORTB=v[cont];
   }

}
