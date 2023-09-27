LIST p=16f88

corte EQU 0x21
var EQU 0x22
resultado EQU 0x23

ORG 0x000

inicio:
	movlw 0x01
	movwf corte
	movlw 0x02
	movwf var
	movwf resultado
bucle:
	btfsc corte,4
	goto fin
	rlf resultado,1
	bcf resultado,0
	rlf corte,1
	goto bucle
fin:
	end
	