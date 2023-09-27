LIST p=16f88

PA    EQU   0x05
PB    EQU   0x06
ansel EQU	0x9b
ESTADO EQU	0x03

ORG 0x000

inicio    bsf ESTADO,5
        movlw 0xFF
		movwf PA
		movlw 0x00
		movwf PB
		bcf ESTADO,5
bucle 	movf PA,0
		nop
		movwf PB
		goto bucle
		end