; * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; *                                                     *
; *     Universidad  Nacional  Autonoma  de  Mexico     *
; *      Facultad de Estudios  Superiores Aragon        *
; *                                                     *
; *       Microprocesadores y Microcontroladores        *
; *                                                     *
; *         Práctica 1 Ver 				*
; *         Replica de puertos                   	*
; *                                                     *
; * 	 TEMAS:                                         *
; *             Manejo del juego de instruciones        *
; *             Configuracion de Puertos como E/S       *
; *             Manipulacion de datos                   *
; *                                                     *
; *             Microcontrolador: PIC16F887             *
; *             Oscilador: 8 MHz interno                *
; *                                                     *
; * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;
; * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; * Este programa enciende y apaga los leds en puerto D *
; * dependiendo del estado del dipswitch en puerto B    *
; *                                                     *
; * Seccion CONFIGURACION:                              *
; *  El puerto B es configurado como entrada digital    *
; *  El puerto D es configurado como salida digital     *
; *                                                     *
; * Seccion PRINCIPAL:                                  *
; *  Se realiza una lectura del puerto B al registro w  *
; *  Se escribe en el puerto D el valor del registro w  *
; * * * * * * * * * * * * * * * * * * * * * * * * * * * *


#include <P16F887.INC>

	__CONFIG _CONFIG1, _INTOSCIO & _MCLRE_OFF & _WDT_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF &  _BOR_OFF & _PWRTE_ON & _FCMEN_OFF & _IESO_OFF


	ORG 00h
CONFIGURACION
	BCF		STATUS,RP1        	; Cambio al banco 1
	BSF 	STATUS,RP0
	MOVLW	b'11111111'			; Configurar puerto A como entrada
	MOVWF 	TRISA
	MOVLW	b'11111111'			; Configurar puerto C como entrada
	MOVWF 	TRISC	
	MOVLW 	b'00000000'     	; Configurar puerto B como salida
	MOVWF 	TRISB
	BSF 	STATUS, RP1	        ; Cambio al banco 3
	BSF 	STATUS, RP0
	CLRF 	ANSEL	        	; Inicializar ANSEL para que Puerto A sea configurado como digital
	BCF 	STATUS, RP1	        ; Cambio al Banco 0
	BCF 	STATUS, RP0
	CLRF 	PORTB           	; Inicializa el Registro del Puerto B

PRINCIPAL
	MOVF	PORTC,W				; SE MUEVE PORT C A W
	SUBWF	PORTA 				;PORTA - W
	BTFSS	STATUS,C			; PREGUNTA POR UN BIT C=1, SALTA LA INTRUCCION SUCESORA: COMPRUEBA SI A > C
	GOTO 	ESMENOR				;NO SALTA PORQUE C=0, A ES MENOR QUE C
	BTFSS	STATUS,Z			;SALTA C=1 POR QUE C=1, NO ES MENOR QUE C
	GOTO	ESMAYOR				;NO SALTA POR QUE Z = 0, A>C
	GOTO	ESIGUAL				;SALTA SI Z = 1, POR LO TANTO A = C

ESMAYOR							;SON SUBRUTINAS Y SE IDENTIFICAN CON ETIQUETAS
	MOVLW	b'11110000'			;SE MEVE LA LITERAL A W
	MOVWF	PORTB				; SE MEVE LA LITERAL A PUERTO B
	GOTO 	PRINCIPAL
ESMENOR
	MOVLW	b'00001111'			;SE MEVE LA LITERAL A W
	MOVWF	PORTB				; SE MEVE LA LITERAL A PUERTO B
	GOTO 	PRINCIPAL

ESIGUAL
	MOVLW	b'10101010'			;SE MEVE LA LITERAL A W
	MOVWF	PORTB				; SE MEVE LA LITERAL A PUERTO B
	GOTO 	PRINCIPAL
	END