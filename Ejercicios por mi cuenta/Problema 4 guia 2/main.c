#include <main.h>

#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0x86
#BYTE PORTB=0x06

void ParpadeoInicial(){
   delay_ms(500);
   PORTB=0x00;
   delay_ms(300);
   PORTB=0xFF;
   delay_ms(200);
   PORTB=0x00;
   delay_ms(200);
   PORTB=0xFF;
   delay_ms(200);
   PORTB=0x00;
   delay_ms(400);
}

void main()
{
   TRISA=0xFF;
   PORTA=0x00;
   TRISB=0x00;
   PORTB=0xFF;
   unsigned int cont=0;
   
   ParpadeoInicial();
   
   while(TRUE)
   {
      if(PORTA==0x01){
         delay_ms(200);
         cont=cont+1;
         PORTB=cont;
      }
      if(cont==255){
         ParpadeoInicial();
         cont=0; //No es necesario pero por las dudas, para no perder la costumbre
      }
   }

}
