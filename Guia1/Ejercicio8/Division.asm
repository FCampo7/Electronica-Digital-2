LIST p=16f88

corte EQU 0x21
var EQU 0x22
resultado EQU 0x23

ORG 0x000

inicio:
.	movlw 0x01
	movwf corte
	movlw 0x10
	movwf var
	movwf resultado
bucle:
	btfsc corte,3
	goto fin
	rrf resultado,1
	bcf resultado,7
	rlf corte,1
	goto bucle
fin:
	end