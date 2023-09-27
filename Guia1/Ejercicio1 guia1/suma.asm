LIST P=16F88

OP1 EQU 0x0b
OP2 EQU 0x0c
RESUL EQU 0x0e

ORG 0x000

movlw 0x05
movwf OP1
movlw 0x03
movwf OP2
movfw OP1
addwf OP2,0
movwf RESUL
end