#include <main.h>

#BYTE TRISB=0x86
#BYTE PORTB=0x06

void main()
{
   TRISB=0x00;
   PORTB=0x00;
   unsigned int cont=0;
   int v[10]={63,6,91,79,102,109,125,7,127,103};
   
   while(TRUE)
   {
         PORTB=v[cont++];
         delay_ms(300);
         if(cont>9)
            cont=0;
   }

}
