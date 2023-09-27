LIST p=16F88

PB EQU 0x06
status EQU 0x03
ansel EQU 0x9B

ORG 0x000

inicio
	bsf status,5
	clrf ansel ;Seteamos los puertos como digitales
	movlw b'11110000'
	movwf PB
	bcf status,5
	clrf PB
bucle
	movlw b'00000011'
	movwf PB
	goto bucle
end