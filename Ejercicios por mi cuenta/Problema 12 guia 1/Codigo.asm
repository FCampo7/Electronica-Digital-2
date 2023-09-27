LIST p=16F88

PB EQU 0x06
st EQU 0x03

ORG 0x000

inicio
	bsf st,5
	movlw 0x0F
	movwf PB
	bcf st,5
	clrf PB
bucle
	btfsc PB,0 ;PB0==1 comprobar; PB0==0 apagar
	goto comprobar
apagar
	bcf PB,4
	goto bucle
comprobar
	btfss PB,1 ;PB1==1 prende; PB1==0 apaga
	goto apagar
	bsf PB,4
	goto bucle
end