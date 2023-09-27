LIST p=16f88

tmr0_option EQU 0x01
intcon EQU 0x0B
pb_trisb EQU 0x06
status EQU 0x03
toif EQU 2

ORG 0000
goto inicializa
ORG 0004
goto rsi

inicializa
	bsf status,5
	bcf status,6
	movlw b'11000111'
	movwf tmr0_option
	clrf pb_trisb
	bcf status,5
	bcf status,6
	movlw b'10100000'
	movwf intcon
	clrf pb_trisb
	clrf tmr0_option
circulo
	goto circulo

rsi
	btfss intcon,toif
	retfie
	bcf intcon,toif
	movlw b'10000000'
	xorwf pb_trisb,1
	clrf tmr0_option
	retfie
end