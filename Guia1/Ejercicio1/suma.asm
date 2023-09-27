;PRIMERO.ASM: Este programa suma el contenido de las posiciones 0x0c y 0x0d
;de memoria y almacena el resultado en la posicion 0x0e.

	LIST p=16f88 ;Indica el modelo PIC que se usa Es una directiva del ensamblador.
;-----------------------------
;Zona para etiquetas.
	
	OPERANDO1 EQU 0x0c	;Define la posicion del operando1.
	OPERANDO2 EQU 0x0d	;Define la posicion del operando2.
	RESULTADO EQU 0x0e	;
	
			ORG 0x000 ;Comando que indica al ensamblador la direccion de la memoria de programa donde situar la siguiente instruccion.

			movlw 0x05
			movwf OPERANDO1
			movlw 0x02
			movwf OPERANDO2
			movfw OPERANDO1
			addwf OPERANDO2,0
			movwf RESULTADO
			end