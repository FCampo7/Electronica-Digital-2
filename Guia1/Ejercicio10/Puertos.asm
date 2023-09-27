LIST p=16F88

PB EQU 0x06
status EQU 0x03

ORG 0x000

inicio:
	bsf status,5
	movlw 0xf0  ; Seteamos la parte alta del PB como entrada y la parte baja como salida
	movwf PB
	bcf status,5
	clrf PB ; apagamos todos los puertos;
bucle:
	bsf PB,0 ; Prendemos el b0 y b1
	bsf PB,1
	goto bucle
	end
	
	