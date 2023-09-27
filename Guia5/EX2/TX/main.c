#include <main.h>
#include <16f88.h>
#fuses hs, nowdt, noprotect, noput
#use delay(clock=4M)
#use RS232(baud=9600, xmit=pin_b5, bits=8, parity=N)
#use standard_io(b)

void main(){
    set_tris_a(0b11111111);
    while(TRUE){
        if(input(pin_a0)==0){
            putc('1');
            while(input(pin_a0)==0);
        }
        if(input(pin_a1)==0){
            putc('2');
            while(input(pin_a1)==0);
        }
        if(input(pin_a2)==0){
            putc('3');
            while(input(pin_a2)==0);
        }
        if(input(pin_a3)==0){
            putc('4');
            while(input(pin_a3)==0);
        }
    }
}
