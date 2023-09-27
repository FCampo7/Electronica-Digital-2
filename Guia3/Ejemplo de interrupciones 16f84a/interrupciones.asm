; Electronica Digital II
; Guia 6
; Ejercicio 1
;
; ------------------------------------------------------------------------------
; tmr0_time = (256-n) * 4 * t_osc * prescaler
; ------------------------------------------------------------------------------
; si 4*t_osc = t_ins = 1us (fosc=4mhz)
;    prescaler = 2:4:8:16:32:64:128:256 (3 bits)
;    
;	 => tmr0_time(n=0) = tmr0_time_max
;					   = 256 * 1us * 256
;					   = 2^16 ms
;					   ~ 65 ms
;-------------------------------------------------------------------------------
; n = 256 - tmr0_time/t_ins*prescaler
;-------------------------------------------------------------------------------
; n(delay _50_ms) = 256 - 50ms / 1 us*256 
;				  = 256 - 50*E-3 / E-6*0.26E+3
;				  = 256 - 50 / 0.26
;				  ~ 256 - 192
;				  = 64
;-------------------------------------------------------------------------------
    list        p=16f84a
    #include    p16f84a.inc
    __config     _WDT_OFF & _XT_OSC & _PWRTE_OFF 
;-------------------------------------------------------------------------------
    STATUS		EQU 0x03
	PB		EQU 0x06
	OPTION_REG	EQU 0x81
	REPET           EQU 0x0c
;-------------------------------------------------------------------------------
	org         0x000
	goto	    inicio
	org	    0x005
;-------------------------------------------------------------------------------

inicio
	bsf     STATUS,5            ; -> Banco 1
	movlw   0x00                ; 0x00 -> W
	movwf   PB                  ; W -> PB
	
	bcf	OPTION_REG,7		; PB Pull-up = 0
	bcf     OPTION_REG,5		; T0CS = 0
	bsf     OPTION_REG,4		; T0SE = 1
	bcf     OPTION_REG,3		; PSA = 0
	bsf     OPTION_REG,0		; PS0 = 1
	bsf     OPTION_REG,1		; PS1 = 1
	bsf     OPTION_REG,2		; PS2 = 1
	bcf     INTCON,2		; T0IF = 0
	bcf     STATUS,5                ; -> Banco 0
	
prendoapago	
	call    delay_500ms
	bsf     PB,0             	; PB_0 = 1
	call    delay_500ms           
	bcf     PB,0             	; PB_0 = 0
	goto    prendoapago

delay_500ms
        movlw   d'10'			 ; 10 -> W (n? de repeticiones)
        movwf   REPET			 ; W -> REPET
bucle_500ms
	call	delay_50ms
	decfsz	REPET
	goto 	bucle_500ms
	return	

delay_50ms	
        bcf     INTCON,2	    ; T0IF = 0
	movlw   d'64'		    ; 64 -> W
	movwf   TMR0		    ; W -> TMR0, arranca a contar
bucle_50ms	
        btfss   INTCON,2	    ; T0IF = ?
	goto    bucle_50ms	    ; if T0IF == 0
	return			    ; if T0IF == 1
    
end