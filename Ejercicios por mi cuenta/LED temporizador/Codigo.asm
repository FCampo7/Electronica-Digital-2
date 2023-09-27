LIST p=16f88

PA		EQU 0x05
PB		EQU	0x06
status	EQU 0x03
ansel 	EQU 0x9B
opt_reg EQU 0x81
intcon 	EQU 0x0B
repet 	EQU 0x20
tmr0 	EQU 0x01

ORG 0x000
goto inicio
ORG 0x004

prendoapago
	movlw d'61'
	movwf tmr0
	call delay_500ms
	bsf PB,0
	movlw d'61'
	movwf tmr0
	call delay_500ms
	bcf PB,0
	retfie

delay_500ms
	movlw d'10'
	movwf repet
bucle_500ms
	call delay_50ms
	decfsz repet
	goto bucle_500ms
	return

delay_50ms
	bcf intcon,2
	movlw d'61'
	movwf tmr0
bucle_50ms
	btfss intcon,2
	goto bucle_50ms
	bcf intcon,2
	return

inicio
	bsf status,5 ;Banco 1
	movlw 0x00
	movwf ansel ;Seteo todos los pines como digitales porque el pic16f88 al encender y al resetear setea los pines como analógicos.
	movlw 0xFF
	movwf PA ;Seteo el puerto A como entrada
	movlw 0x00;
	movwf PB ;Seteo el puerto B como salida
	movlw b'00010111'
	movwf opt_reg
	;bcf opt_reg,7 ;Habilito las resistencias pull-up del puerto B
	;bcf opt_reg,5 ;Seteo el reloj interno para el TMR0
	;bsf opt_reg,4 ;Flanco de bajada
	;bcf opt_reg,3 ;Preescaler para el TMR0
	;bsf opt_reg,0 ;PS0=1
	;bsf opt_reg,1 ;PS1=1
	;bsf opt_reg,2 ;PS2=1 preescaler de 256
	bsf intcon,7 ;Habilito las interrupciones globales
	bsf intcon,5 ;Habilito las interrupciones del TMR0
	bcf intcon,2 ;Limpio la bandera de overflow del TMR0
	bcf status,5 ;Banco 0
	movlw 0x00
	movwf PB
	movwf PA
	movlw d'61'
	movwf tmr0

bucle
	btfss PA,0
	bcf PB,1
	btfsc PA,0
	bsf PB,1
	goto bucle

end