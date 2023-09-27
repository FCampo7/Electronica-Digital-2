LIST p=16f88

indf EQU 0x00
fsr EQU 0x04
var EQU 0x20
nRot EQU 0x21

ORG 0x000

inicio
	movlw 0x02
	movwf var
	movlw 0x03
	movwf nRot
	movlw 0x22
	movwf fsr

bucle
	rlf var,0
	movwf var
	movwf indf
	incf fsr
	decfsz nRot
	goto bucle
	end