LIST p=16F88

var EQU 0x20
multi EQU 0x21

ORG 0x000

inicio
	movlw d'2'
	movwf var
	movlw d'4'
	movwf multi
bucle
	rlf var,1
	decfsz multi
	goto bucle
	end