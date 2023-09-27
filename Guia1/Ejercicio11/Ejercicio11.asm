LIST p=16f88

status EQU 0x03
PA EQU 0x05
PB EQU 0x06

ORG 0x000

inicio
	bsf status,5
	movlw 0x00 ;Decimos que el puerto A es digital
	movwf 0x1B
	movlw 0xff
	movwf PA
	clrf PB
	bcf status,5
	clrf PA
	clrf PB
bucle
	btfsc PA,2
	goto prenderb0
	bcf PB,0
bucle2
	btfsc PA,3
	goto prenderb1
	bcf PB,1
	goto bucle
prenderb0
	bsf PB,0
	goto bucle2
prenderb1
	bsf PB,1
	goto bucle
fin
	end