LIST p=16f88

PA EQU 0x05
PB EQU 0x06
status EQU 0x03

ORG 0x000

inicio
	bsf status,5
	movlw 0x80 ;Para que funcione hay que poner el registro ANSEL en 0x00
			   ;para que sea la entrada digital
	movwf 0x1B ;Registro ANSEL es el 9B, como el banco seleccionado es el 1
			   ;entonces ponemos el registro 1B
	movlw 0xFF
	movwf PA
	clrf PB
	bcf status,5
	clrf PA
	clrf PB
bucle 
	BTFSS PA,0
	goto apagar
	BTFSS PA,1
	goto apagar
	bsf PB,0
	goto bucle
apagar
	bcf PB,0
	goto bucle
end