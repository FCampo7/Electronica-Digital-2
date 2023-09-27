LIST p=16F88

;variables
indf 	EQU 0x00
fsr 	EQU 0x04
corte 	EQU 0x41

;origen
ORG 0x000

inicio
	movlw 0x10 
	movwf 0x21 ;ponemos un d'16' en estas 3 direcciones de memoria
	movwf 0x30
	movwf 0x3F
	movlw d'32'
	movwf corte ;Ponemos un d'32' en corte
	movlw 0x20
	movwf fsr ;Posicionamos el registro de file select register a la posicion 0x20

bucle
	clrf indf ;Limpiamos la posicion a la que apunta fsr
	incf fsr ;Pasamos a la siguiente posicion de memoria
	decfsz corte ;decrementamos corte y si es 0 terminamos el programa
	goto bucle
	end