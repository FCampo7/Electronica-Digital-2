LIST p=16f88

indf EQU 0x00
fsr EQU 0x04
corte EQU 0x41

ORG 0x000

inicio:
	movlw 0x10
	movwf 0x29
	movwf 0x40
	movlw 0x01
	movwf corte
	movlw 0x20
	movwf fsr
	movwf indf
bucle:
	btfsc corte,5
	goto comp2
bucle2:
	clrf indf
	incf fsr
	incf corte,1
	goto bucle
comp2:
	btfsc corte,1
	goto fin
	goto bucle2
fin:
	end