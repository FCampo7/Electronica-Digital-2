
;Manejo de dos interrupciones a la vez TMR0 y INT_EXT

LIST p=16f88

PA EQU 0x05
PB EQU 0x06
st EQU 0x03 ;Controla el registro status
TMR0 EQU 0x01 ;Controla el registro tmr0 y option
INTCON EQU 0x0B ;Controla el registro INTCON
ansel EQU 0x9B ;Controla el registro analogico
ciclos EQU 0x20 ;Almacenamos los ciclos

ORG 0x000

goto inicio ;Arrancamos en inicio

ORG 0x004

btfsc INTCON,2 ;INTCON2==1 vamos a la rutina tmr0_int
goto tmr0_int2
btfsc INTCON,1 ;INTCON1==1 vamos a la rutina ext_int
goto ext_int
retfie ;Por las dudas retornamos de la interrupcion

tmr0_int2
	bcf INTCON,2
	movlw d'61'
	movwf TMR0
	decfsz ciclos
	retfie
	movlw d'10'
	movwf ciclos
	movlw b'00000010'
	xorwf PB
	retfie

tmr0_int ;Rutina de la interrupcion del tmr0
	call delay_600ms
	bsf PB,1
	call delay_600ms
	bcf PB,1
	retfie
delay_600ms
	movlw d'10'
	movwf ciclos
bucle_delay600ms
	call delay_50ms
	decfsz ciclos
	goto bucle_delay600ms
	return
delay_50ms
	bcf INTCON,2
	movlw d'61'
	movwf TMR0
bucle_delay50ms
	btfss INTCON,2
	goto bucle_delay50ms
	bcf INTCON,2
	return

ext_int ;Rutina de la interrupcion externa del RB0
	movlw b'00000100'
	xorwf PB ;Prende apaga el pin
	bcf INTCON,1
	retfie

inicio ;Seteo del pic
	bsf st,5 ;Banco 1
	clrf ansel ;Seteamos los pines como digitales
	movlw 0xFF
	movwf PA
	movlw 0x01
	movwf PB
	movlw b'00010111' ;RBPU=ACT, INTEDG=HTOL, T0CS=INTERNAL, T0SE=HTOL, PSA=TMR0, PS<0-2>=256
	movwf TMR0
	bsf INTCON,7 ;int globales act
	bsf INTCON,5 ;int tmr0 act
	bsf INTCON,4 ;int RB0 act
	bcf INTCON,2 ;flag TMR0 CLEAR
	bcf	INTCON,1 ;flar RB0 CLEAR
	bcf st,5 ;Banco 0
	clrf PB ;Limpiamos PB
	movlw d'10'
	movwf ciclos
bucle ;Programa principal
	btfss PA,0
	bcf PB,3
	btfsc PA,0
	bsf PB,3
	goto bucle
end