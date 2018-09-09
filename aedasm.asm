;/*********************************************************************
;*         INTEL CORPORATION PROPRIETARY INFORMATION                  *
;*   This software is supplied under the terms of a license agreement *
;*   or nondisclosure agreement with Intel Corporation and may not be *
;*   copied or disclosed except in accordance with the terms of that  *
;*   agreement.                                                       *
;*********************************************************************/

        NAME    ALTASM
$TITLE('ALTASM                          ASSEMBLER ROUTINES FOR ALTER')
CGROUP GROUP CODE
DGROUP GROUP CONST,DATA,STACK,MEMORY
ASSUME  CS:CGROUP,DS:DGROUP
CONST SEGMENT PUBLIC 'CONST'
CONST ENDS
STACK SEGMENT STACK 'STACK'
STACK_END LABEL BYTE
STACK ENDS
MEMORY SEGMENT MEMORY 'MEMORY'
MEMORY ENDS

DATA    SEGMENT PUBLIC 'DATA'

LF      EQU     0AH
TAB     EQU     09H

ED_TAGA EQU     5
ED_TAGB EQU     6

        EXTRN   TAB_TO:BYTE
        EXTRN   PRINT_AS:BYTE
        EXTRN   HIGHBIT_FLAG:BYTE
        EXTRN   WRAPPING_COLUMN:BYTE
        EXTRN   IN_BLOCK_MODE:BYTE,CO_BUFFER:BYTE
        EXTRN   LINE_SIZE:BYTE,ROW:BYTE,COL:BYTE,ISA_TEXT_LINE:BYTE



TWO_OF  STRUC
        BLOCK_SIZE      DW      ?
        MORE_INPUT      DB      ?
        FILE_DISPOSITION DB     ?
        WK1_BLOCKS      DW      ?
        WK2_BLOCKS      DW      ?
        LOW_S           DW      ?
        LOW_E           DW      ?
        HIGH_S          DW      ?
        HIGH_E          DW      ?
        INPUT_NAME      DB      61 DUP (?)    ; 61 = string_len_plus_1
        OUTPUT_NAME     DB      61 DUP (?)
        NEW_FILE        DB      ?
        HAVE_EOF        DB      ?
        TBLOCK          DW      9 DUP (?)
        TOFF            DW      9 DUP (?)
        IN_CONN         DW      ?
        DIRTY           DB      ?
        LEFT_COLUMN     DB      ?
        BOL             DW      ?
        WK1_CONN        DB      ?
        WK2_CONN        DB      ?
TWO_OF  ENDS

        EXTRN   OA:TWO_OF

LAST_BYTE       DB      0

DATA    ENDS



CODE    SEGMENT PUBLIC 'CODE'
        EXTRN   SET_TAG:NEAR,JUMP_TAG:NEAR
        EXTRN   CAN_FORWARD_FILE:NEAR,FORWARD_FILE:NEAR
        EXTRN   COCOM:NEAR,CO_FLUSH:NEAR





;       LOCAL PROCEDURE USED BY UNFOLD_TO_SCREEN

SCREEN_DATA:
;                                DX IS ASSUMED TO HAVE THE COMMAND PORT NUMBER IN IT
        MOV     AH,AL   ;SAVE CHAR INTO AH
DATWAIT:
        IN      AL,DX
        AND     AL,2
        JNZ     DATWAIT ;WAIT TO GET READY
        DEC     DX              ;GET THE DATA PORT NUMBER
        MOV     AL,AH   ;RETRIEVE THE CHARACTER
        OUT     DX,AL
        INC     DX              ;CHANGE IT BACK FOR NEXT TIME
        RET




; local proc to save code

NEXT_BYTE:
        MOV     DI,BX                   ;PUT INDEX ASIDE
        MOV     BL,[SI]                 ;NEXT TEXT BYTE
        XOR     BH,BH                   ;NEED INDEX INTO PRINT_AS
        MOV     AL,PRINT_AS[BX]         ;WAY TO PRINT THE BYTE

        CMP     BL,07FH                 ; IF CH>=80H AND HIGHBIT_FLAG
        JBE     L                       ;    THEN RETURN IT ASIS
        CMP     HIGHBIT_FLAG,0
        JE      L
        MOV     AL,BL
L:
        MOV     BX,DI                   ;PUT INDEX BACK
        INC     SI                      ;INC TEXT POINTER
        RET








;       UNFOLD_TO_SCREEN        GIVEN A POINTER, UNFOLD THE LINE IMAGE AND WRITE IT
;                                               DIRECTLY TO CODAT - THE UNFOLD PROCESS DUPLICATES
;                                               THE CODE IN UNFOLD, EXCEPT THAT INSTEAD OF MOVING
;                                               IT INTO AN ARRAY, WE MOVE IT OUT TO THE SCREEN,
;                                               ALSO, THE ROUTINE ASSUMES IT WILL NEVER BE CALLED
;                                               WHEN MACRO_SUPPRESS IS TRUE

        PUBLIC  UNFOLD_TO_SCREEN
UNFOLD_TO_SCREEN        PROC

;       FIRST SEND COMMAND BYTE

        CMP     CO_BUFFER,0
        JZ      START_BLOCK
        CALL    CO_FLUSH
START_BLOCK:
        CMP     IN_BLOCK_MODE,0
        JNZ     GET_PARMS

        MOV     AL,2FH                  ;BLOCK MODE; WITH COMPRESSED SPACES, START FROM CURRENT
                                                ;LOCATION
        PUSH    AX
        CALL    COCOM
        MOV     IN_BLOCK_MODE,0FFH

;       NOW GET OUR GET PARMS

GET_PARMS:

        POP     DX                      ;RETURN ADDRESS
        POP     SI                      ;TEXT POINTER
        PUSH    DX                      ;PUT RETURN ADDRESS BACK
        PUSH    BP
        MOV     DL,0C1H         ;USE THIS TO STORE THE COMMAND PORT NUMBER
        MOV     DH,WRAPPING_COLUMN      ;MUST BE NON-ZERO
        
;       DROP A LINE FEED AT START OF WINDOW SO WE DONT FALL INTO IT

        MOV     BX,OA.LOW_E
        MOV     BYTE PTR [BX],LF

        MOV     BX,0                    ;USED AS INDEX TO TEXT STRING
        MOV     LAST_BYTE,BH
        MOV     BP,80H

;       USE CL AND CH AS COUNTERS SO COLUMN TO THE LEFT OF LEFT_COLUMN ARE
;       NOT PRINTED

        MOV     AX,OA.HIGH_E
        CMP     SI,AX
        JNZ     UNFOLD_THE_LINE
        JMP     EXIT_UNFOLD

UNFOLD_THE_LINE:

        MOV     CH,OA.LEFT_COLUMN               ;FIRST COLUMN TO PRINT
        XOR     CL,CL                   ;ACTUAL COLUMN NUMBER
        CMP     CH,CL                   ;IS THERE A LEFT_COLUMN?
        JZ      UNFOLD_LOOP
        INC     BX                      ;DEPOSIT '!' IN FIRST COLUMN OF LINE
        CMP     CL,CH                   ;COMPARE TO FIRST NEEDING DISPLAY
        MOV     AL,'!'
        CALL SCREEN_DATA
        INC     CH                      ;DONT DISPLAY CHARACTER ACTUALLY
                                        ;AT THE '!' LOCATION

UNFOLD_LOOP:                           ;PROCESS NEXT TEXT CHARACTER
        CALL    NEXT_BYTE        ;PUTS NEXT BYTE IN AL AND INC SI
        CMP     AL,09H
        JE      TAB_CASE
        CMP     AL,0AH
        JE      JMP_LF_CASE
        CMP     AL,20H
        JNZ     SPACE_LOOP_EXIT

;       NORMAL CHARACTER SITUATION - DROP IN TEXT IF AT OR AFTER LEFT_COLUMN

SPACE_LOOP:
        INC     CL               ;VIRTUAL COLUMN NUMBER
        CMP     CL,DH
        JZ      JMP_LF_CASE            ;IF 254, then insert virtual LF
        CMP     CL,CH                  ;COMPARE TO FIRST NEEDING DISPLAY
        JBE     UNFOLD_LOOP            ;SHORT OF LEFT_COLUMN
        INC     BX                     ;ACTUALLY HAVE CHARACTER
        CMP     BX,80                  ;IF PAST END, STUFF TRAILING '!'
        JAE     AT_END
NOT_AT_END:
        INC     BP
        JMP     SHORT UNFOLD_LOOP
LAST_POS1:
        MOV     LAST_BYTE,AL
        JMP     SHORT UNFOLD_LOOP
AT_END:
        JE      LAST_POS1
        DEC     BX                      ;BACK UP TO LAST CHAR
        MOV     LAST_BYTE,'!'                   ;PRINT EXCLAMATION
        JMP     SHORT UNFOLD_LOOP

;       SPECIAL CASES - FOUND A LINE FEED OR A TAB

TAB_CASE:
        MOV     DI,BX                   ;PUT LINE INDEX ASIDE
        MOV     BL,CL                   ;VIRTUAL COLUMN
        XOR     BH,BH                   ;IS AN INDEX TO TAB_TO
        MOV     AL,TAB_TO[BX]           ;NUMBER OF SPACES TO PRINT FOR TAB
        MOV     BX,DI                   ;RESTORE

;       STICK APPROPRIATE NUMBER OF SPACES IN TEXT

        MOV     AH,PRINT_AS[' ']        ;BLANKING CHARACTER
TAB_LOOP:
        OR      AL,AL                   ;TEST IF DONE
        JZ      UNFOLD_LOOP
        DEC     AL                      ;DECREMENT SPACE COUNTER
        INC     CL                      ;VIRTUAL COLUMN NUMBER
        CMP     CL,DH
        JZ      LF_CASE                ;IF 254, then insert virtual LF
        CMP     CL,CH                   ;COMPARE TO FIRST NEEDING DISPLAY
        JBE     TAB_LOOP               ;SHORT OF LEFT_COLUMN
        INC     BX                      ;ACTUALLY HAVE CHARACTER
        CMP     BX,80                   ;IF PAST END, STUFF TRAILING '!'
        JAE     TAB_AT_END
TAB_NOT_AT_END:
        INC     BP
        JMP     SHORT TAB_LOOP
LAST_POS2:
        MOV     LAST_BYTE,AL
        JMP     SHORT TAB_LOOP
TAB_AT_END:
        JE      LAST_POS2
        DEC     BX                      ;BACK UP TO LAST CHAR
        MOV     LAST_BYTE,'!'                   ;PRINT EXCLAMATION
        JMP     SHORT TAB_LOOP

SPACE_LOOP_EXIT:
        CMP     BP,80H
        JZ      NON_SPACE_LOOP
        MOV     DI,AX
        MOV     AX,BP
        CALL    SCREEN_DATA
        MOV     BP,80H
        MOV     AX,DI
        JMP     SHORT   NON_SPACE_LOOP
JMP_LF_CASE:
        JMP     SHORT LF_CASE

        ; NON_SPACE CHARS ONLY

UNFOLD_LOOP_C:                          ;PROCESS NEXT TEXT CHARACTER
        CALL    NEXT_BYTE        ;PUTS NEXT BYTE IN AL AND INC SI
        CMP     AL,09H
        JE      TAB_CASE
        CMP     AL,0AH
        JE      LF_CASE_C

;       NORMAL CHARACTER SITUATION - DROP IN TEXT IF AT OR AFTER LEFT_COLUMN

NON_SPACE_LOOP:
        INC     CL                      ;VIRTUAL COLUMN NUMBER
        CMP     CL,DH
        JZ      LF_CASE                        ;IF 254, then insert virtual LF
        CMP     CL,CH                   ;COMPARE TO FIRST NEEDING DISPLAY
        JBE     UNFOLD_LOOP_C           ;SHORT OF LEFT_COLUMN
        INC     BX                      ;ACTUALLY HAVE CHARACTER
        CMP     BX,80                   ;IF PAST END, STUFF TRAILING '!'
        JAE     AT_END_C
NOT_AT_END_C:
;                                DX IS ASSUMED TO HAVE THE COMMAND PORT NUMBER IN IT
        MOV     AH,AL   ;SAVE CHAR INTO AH
DATWAIT0:
        IN      AL,DX
        AND     AL,2
        JNZ     DATWAIT0        ;WAIT TO GET READY
        DEC     DX              ;GET THE DATA PORT NUMBER
        MOV     AL,AH   ;RETRIEVE THE CHARACTER
        OUT     DX,AL
        INC     DX              ;CHANGE IT BACK FOR NEXT TIME
        JMP     SHORT UNFOLD_LOOP_C
LAST_POS1C:
        MOV     LAST_BYTE,AL
        JMP     SHORT UNFOLD_LOOP_C
AT_END_C:
        JE      LAST_POS1C
        DEC     BX                      ;BACK UP TO LAST CHAR
        MOV     LAST_BYTE,'!'                   ;PRINT EXCLAMATION
        JMP     SHORT UNFOLD_LOOP_C

;       SPECIAL CASES - FOUND A LINE FEED OR A TAB

;       FOUND A LF. COULD BE LF AT WINDOW OR LF AT END OF MEMORY (REQUIRING
;       FORWARDING THE FILE) OR LF AT ACTUAL END OF TEXT OR THE END
;       OF THE LINE.

LF_CASE:
        CMP     BP,80H          ;CHECK FOR ANY SPACES
        JZ      NO_NEED_TO_DUMP
        MOV     DI,AX
        MOV     AX,BP
        CALL    SCREEN_DATA
        MOV     BP,80H
        MOV     AX,DI
NO_NEED_TO_DUMP:
LF_CASE_C:
        DEC     SI                      ;GET THE INDEX USED TO FETCH LINE FEED
        CMP     SI,OA.LOW_E             ;AT WINDOW?
        JNZ     NOT_WINDOW
        MOV     SI,OA.HIGH_S            ;SET TEXT POINTER TO HIGH_S
        JMP     UNFOLD_LOOP            ;AND CONTINUE
NOT_WINDOW:
        CMP     SI,OA.HIGH_E            ;AT END OF TEXT IN MEMORY?
        JB      ACTUAL_LF              ;NO, FOUND END OF LINE

;       SEE IF WE CAN MOVE THE FILE FORWARD

        PUSH    BX                      ;PRESERVE REGISTERS FROM PL/M
        PUSH    CX
        PUSH    SI

        MOV     COL,BL                  ; UPDATE COL BEFORE FORWARD_FILE CALLS "WORKING"

        CALL    CAN_FORWARD_FILE        ;RETURNS TRUE IF CAN READ MORE TEXT
        MOV     DL,0C1H         ;USE THIS TO STORE THE COMMAND PORT NUMBER
        MOV     DH,WRAPPING_COLUMN      ;MUST BE NON-ZERO
        OR      AL,AL
        JZ      END_OF_TEXT            ;ZERO=NO MORE TEXT
        MOV     AL,ED_TAGB              ;SET TAG SO CAN RETURN
        PUSH    AX
        MOV     AX,OA.HIGH_S            ;TO SAME HIGH_S
        PUSH    AX
        CALL    SET_TAG                 ;SET B TAG
        CALL    FORWARD_FILE            ;READ NEXT BLOCK
        PUSH    OA.HIGH_S                       ;PRESERVE START OF TEXT READ IN
        MOV     AL,ED_TAGB              ;AND REWINDOW BACK AT START
        PUSH    AX
        CALL    JUMP_TAG                ;JUMP TO STARTING OFFSET
        POP     SI                      ;NEW TEXT LOCATION
        POP     AX                      ;IGNORE OLD TEXT LOCATION
        POP     CX                      ;OLD COLUMN COUNT
        POP     BX                      ;OLD LINE INDEX
        MOV     DL,0C1H         ;USE THIS TO STORE THE COMMAND PORT NUMBER
        MOV     DH,WRAPPING_COLUMN      ;MUST BE NON-ZERO
        JMP     UNFOLD_LOOP            ;CONTINUE WITH NEW TEXT

;       RAN INTO THE END OF TEXT

END_OF_TEXT:
        POP     SI                      ;RESTORE REGISTERS
        POP     CX
        POP     BX

;       IF NO CHARACTERS AT ALL, DO NOT PRINT LEADING '!'

        CMP     CL,BH                   ;TRUE IF EMPTY LINE
        JNZ     NOT_EMPTY
        MOV     BL,BH                   ;FORCE NULL STRING
        MOV     LAST_BYTE,BH
NOT_EMPTY:
        MOV     AX,OA.HIGH_E            ;NEXT LINE IS END OF TEXT
        JMP     SHORT EXIT_UNFOLD

;       FOUND AN ACTUAL END OF LINE

ACTUAL_LF:
        CMP     AL,LF
        JZ      REAL_LF
        CMP     CL,DH
        JNZ     REAL_LF
        MOV     LAST_BYTE,'+'
        MOV     BL,80                   ;MAKE SURE WE KNOW WE ARE IN THE LAST COLUMN
REAL_LF:
        CMP     BYTE PTR[SI],LF
        JNZ     NEXT_LOC
        INC     SI
NEXT_LOC:
        LEA     AX,[SI]                 ;NEED TO RETURN NEXT LINE LOCATION
        CMP     AX,OA.LOW_E             ;DONT RETURN POINTING TO LOW_E
        JNZ     EXIT_UNFOLD
        MOV     AX,OA.HIGH_S
EXIT_UNFOLD:
        CMP     LAST_BYTE,BH
        JZ      NOTHING_THERE
        MOV     DI,AX                   ;SAVE OFF NEXT LINE ADDRESS
        MOV     AL,LAST_BYTE    ;SEND OFF LAST BYTE TO SCREEN
        CALL    SCREEN_DATA
        MOV     AX,DI                   ;RESTORE NEXT LINE ADDRESS
NOTHING_THERE:
        MOV     DH,80                   ;FOR FASTER COMPARES AND STORES LATER
        MOV     CX,BX
        MOV     CH,ROW
        CMP     ISA_TEXT_LINE,BH
        JNZ     ERASE_REST_OF_LINE
        CMP     LINE_SIZE[BX],BL
        JBE     STORE_COL
ERASE_REST_OF_LINE:
        MOV     DI,AX                   ;SAVE AX
        MOV     AL,DH
        SUB     AL,BL                           ;GET NUMBER OF SPACES TILL END OF SCREEN
        JZ      SEND_NOTHING
        OR      AX,80H                          ;CONVERT TO COMPRESSED SPACE
        CALL    SCREEN_DATA             ;SEND IT OUT
SEND_NOTHING:
        MOV     AX,DI                           ;RESTORE AX
        MOV     BL,DH                           ;SET COLUMN AT MAX
        MOV     ISA_TEXT_LINE,BH
STORE_COL:
        CMP     BL,DH
        JNZ     STO_COL
        MOV     BL,BH
        INC     ROW
STO_COL:
        MOV     COL,BL
        MOV     BL,CH                           ;
        MOV     LINE_SIZE[BX],CL
        POP     BP
        RET                             ;ALL DONE
UNFOLD_TO_SCREEN        ENDP




CODE    ENDS
        END
