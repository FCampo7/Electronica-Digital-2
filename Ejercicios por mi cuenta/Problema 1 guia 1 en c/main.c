#include <main.h>

#byte porta=0x05
#byte portb=0x06

void main()
{
	set_tris_a(0xFF);
	set_tris_b(0x00);
  	
	porta=0x00;
	portb=0x00;
  	
	while(TRUE)
	{
		if(bit_test(porta,0)==1 && bit_test(porta,1)==1){
			bit_set(portb,0);
		}
		else
			bit_clear(portb,0);
	}

}
