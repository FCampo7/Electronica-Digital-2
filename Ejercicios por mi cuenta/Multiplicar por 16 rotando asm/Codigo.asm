LIST p=16F88

var EQU 0x20
nRot EQU 0x21

ORG 0x000

inicio
	movlw d'2'
	movwf var
	movlw d'4'
	movwf nRot
	
bucle
	rlf var,1
	decfsz nRot
	goto bucle
	end