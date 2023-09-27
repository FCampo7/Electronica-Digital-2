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
	btfss PB,0
	goto apagaB4
	bsf PB,4
cont
	btfss PB,1
	goto apagaB5
	bsf PB,5
	goto bucle
apagaB4
	bcf PB,4
	goto cont
apagaB5
	bcf PB,5
	goto bucle
end