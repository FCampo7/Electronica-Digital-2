LIST p=16F88

indf EQU 0x00
fsr EQU 0X04
corte EQU 0x41

ORG 0x000

inicio
	movlw d'10'
	movwf 0x20
	movwf 0x21
	movwf 0x30
	movwf 0x40
	movlw 0x20
	movwf fsr
	movlw d'33'
	movwf corte

bucle
	clrf indf
	incf fsr
	decfsz corte
	goto bucle
	end