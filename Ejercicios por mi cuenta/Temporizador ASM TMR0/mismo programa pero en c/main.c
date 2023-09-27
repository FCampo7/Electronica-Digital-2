#include <main.h>
#BIT RB7=0x06.7

#int_TIMER0
void TIMER0_isr(void){
   if(RB7==0){
      RB7=1;
      set_TIMER0(0x83);
   }
   else{
      RB7=0;
      set_TIMER0(0x83);
   }
}

void main()
{
   set_tris_b(0b01111111);
   RB7=0;
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   set_TIMER0(0x83);
   while(TRUE);
}
