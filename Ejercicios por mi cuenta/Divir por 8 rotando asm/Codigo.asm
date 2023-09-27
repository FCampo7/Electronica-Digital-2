LIST p=16F88

var EQU 0x20
nRot EQU 0x21

ORG 0x000

inicio
	movlw d'16'
	movwf var
	movlw d'3'
	movwf nRot

bucle
	rrf var
	decfsz nRot
	goto bucle
	end