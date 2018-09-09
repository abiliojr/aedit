;/*********************************************************************
;*         INTEL CORPORATION PROPRIETARY INFORMATION                  *
;*   This software is supplied under the terms of a license agreement *
;*   or nondisclosure agreement with Intel Corporation and may not be *
;*   copied or disclosed except in accordance with the terms of that  *
;*   agreement.                                                       *
;*********************************************************************/
;
;  IOCX86
;  Extended IOC drivers for Series III
;
			name		IOCX86

;
;  These routines implement the console in, out, and status routines
;  on the 86/12 side of the Series III.  They are adaptations of the
;  code in the Series II monitor.  The IOC port values, 0C0H and 0C1H
;  in the 8080/85 world are 0C0C0H and 0C1C1H here because the 86/12
;  designers hardwired port addresses into their OEM board.  Fortunately,
;  the IOC only decodes the low order I/O address and sees 0C0H and 0C1H
;  which the 86/12 would normally trap.
;

IOC_CMD		equ			0C1C1H
IOC_STAT	equ			0C1C1H
IOC_DATA	equ			0C0C0H
IMASK		equ			0FCH

CGROUP		group		CODE
CODE		segment		public 'CODE'

			assume		CS:CGROUP
			public		portCI, portCO, portCSTS, enable_ioc_io,disable_ioc_io
			PUBLIC	CODAT,COCOM,CIDAT,SENDBLOCK

;
; IOCDR2 - IOC DRIVER 2 (OUTPUT)
;          IOCDR2:procedure (CMD_CHR) external;
;          declare
;            CMD_CHR word;
;          end;
;
IOCDR2		proc
			PUSH		BP
			MOV			BP,SP

			PUSH		word ptr [BP+4]		;pass on CMD byte
			CALL		COCOM
			MOV			DX,IOC_STAT
IOCXXX:		IN			AL,DX
			AND			AL,07				;status ready?
			JNZ			IOCXXX
			MOV			AL,[BP+5]			;character is high byte
			MOV			DX,IOC_DATA
			OUT			DX,AL				;write the character
			
			POP			BP
			RET			2
IOCDR2		endp

;
; portCSTS - CONSOLE STATUS
;        portCSTS:procedure byte external;
;        end;
;
portCSTS	proc

			MOV			AL,13H				;get keyboard status command
			PUSH		AX
			CALL		COCOM
			CALL		CIDAT
			AND			AL,01				;strip off unneeded status bits
											;1=char waiting, 0=false
			RET
portCSTS		endp

;
; portci - CONSOLE INPUT
;      portci:procedure byte external;
;      end;
;
portci		proc

WAIT4CHAR:	CALL		portCSTS
			JZ			WAIT4CHAR			;wait till character ready - CSTS
											;must set Z flag
			MOV			AL,12H				;input char command byte
			PUSH		AX
			CALL		COCOM
			JMP			CIDAT

			RET
portci		endp

;
; portCO - CONSOLE OUTPUT
;      portCO:procedure (BYT) external;
;      declare
;        BYT byte;
;      end;
;
portCO		proc
			MOV			AL,010H				;char output command byte
			PUSH		AX
			CALL		COCOM
			JMP			CODAT
portCO		endp

;
;  enable_ioc_io - DISABLE KEYBOARD INTERRUPTS
;               PREVENT:procedure external;
;               end;
;
;  This routine must be called before any console I/O calls are done from
;  the Series III.  RUN programs the IOC to interrupt on keyboard status
;  change.  We must tell it not to.
;
enable_ioc_io:	PUSH		BP
			MOV			BP,SP

			MOV			AL,0AH				;set int mask cmd
			MOV			AH,0				;mask out KB
			PUSH		AX
			CALL		IOCDR2

			POP			BP
			RET

;
;  disable_ioc_io - ENABLE KEYBOARD INTERRUPTS
;             ALLOW:procedure external;
;             end;
;
;  This routine must be called before DQ$EXIT so that RUN will again be
;  able to detect keyboard interrupts.  Here we reprogram the IOC to
;  interrupt on keyboard status change.
;
disable_ioc_io:	PUSH		BP
			MOV			BP,SP

			MOV			AL,0AH				;set int mask cmd
			MOV			AH,02				;allow KB to interrupt
			PUSH		AX
			CALL		IOCDR2

			POP			BP
			
			RET

COCOM:

	POP	CX
	POP	BX
	MOV	DX,0C1C1H
	MOV	AH,7
COCOMWAIT:
	IN	AL,DX
	AND	AL,AH
	JNZ	COCOMWAIT
	MOV	AL,BL
	OUT	DX,AL
	JMP	CX
	
CIDAT:

	MOV	DX,0C1C1H
	MOV	AH,7
CIDATWAIT:
	IN	AL,DX
	AND	AL,AH
	DEC	AL
	JNZ	CIDATWAIT
	DEC	DX
	IN	AL,DX
	RET

CODAT:

	POP	CX
	POP	BX
	MOV	DX,0C1C1H
	MOV	AH,2
CODATWAIT:
	IN	AL,DX
	AND	AL,AH
	JNZ	CODATWAIT
	DEC	DX
	MOV	AL,BL
	OUT	DX,AL
	JMP	CX

SENDBLOCK:

;	SEND A BLOCK OF DATA AS FAST AS POSSIBLE USING CIDAT TYPE CODE
;	WON'T USE A CALL TO CODAT THOUGH TO HELP ELIMINATE OVERHEAD
;

	POP	DX			; RETURN ADDRESS
	POP	BX			; START ADDRESS
	MOV	CL,BYTE PTR[BX]		; GET COUNT
	XOR	CH,CH		; ZERO OUT HIGH ORDER PORTION
	INC	BX			; SET BX TO ADDRESS OF FIRST BYTE
	PUSH	DX		; PUT BACK THE RETURN ADDRESS
	MOV	DX,0FFC1H	; USE DX FOR PORT ADDRESS
	MOV	AH,7		; STATUS MASK
	MOV AL,BYTE PTR[BX]	; GET FIRST DATA BYTE
	MOV SI,AX		; SAVE AX SO WE ARE READY
	AND	CX,CX
	JZ	GOHOME
	
NOT0:
	IN AL,DX		; GET STATUS
	AND	AL,AH		; AND IT WITH THE STATUS MASK
	JNZ NOT0		; WAIT UNTIL READY
	MOV	AX,SI		; GET BACK OUR READY AX FROM SI TEMP STORAGE
	DEC	DX			; PREPARE THE PORT NUMBER
	OUT	DX,AL		; SHOVE OUT THE BYTE
	INC	DX			; RESTORE THE PORT NUMBER FOR STATUS CHECK
	INC	BX			; INCREMENT TO NEXT MEMORY WORD
	MOV	AL,BYTE PTR[BX]		; GET THE DATA BYTE
	MOV SI,AX		; NOW SAVE AX AGAIN INTO 
	LOOP	NOT0		; DECREMENT COUNT AND CONTINUE IF NON-ZERO
GOHOME:
	RET				; ELSE RETURN
CODE		ends
			end
