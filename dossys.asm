;/*********************************************************************
;*         INTEL CORPORATION PROPRIETARY INFORMATION                  *
;*   This software is supplied under the terms of a license agreement *
;*   or nondisclosure agreement with Intel Corporation and may not be *
;*   copied or disclosed except in accordance with the terms of that  *
;*   agreement.                                                       *
;*********************************************************************/

;   The module is an ASM86 rewrite of a PLM86-compatible version of exec.asm
;   (which is the MS-MACRO86 written Lattice-compatible version).
;
;   The module provides the following PLM entry points
;
;   1. exec - execute a DOS command line.
;   
;        exec: procedure(str) word;
;
;   ... where str is a pointer to zero terminated string containing the
;   command line to be executed.
;
;   If exec terminates successfully it return zero. Else it return the
;   DOS error code in AL and error class in AH.
;   IMPORTANT - realloc() must be called prior to exec() in order to release
;   memory for the newly executed program.
;
;   Example:
;   exc = exec(@('dir',0));
;
;   2. realloc - reallocates program memory
;
;        realloc: procedure (hiseg) word;
;
;   ... where hiseg is the highest segment/selector used by the current
;   program. The rest of the memory above hiseg:0FFFFH is released.
;   realloc() returns zero if completed sucessfully. Else it return the DOS
;   error code in AL and error class in AH.
;   IMPORTANT - if hiseg is not the highest segment used, program memory will
;   be rewritten with unpredictable consequences.
;
;   Notes:
;   - The segmentation model is SMALL
;   - Segment naming convention follows PLM86

    name        exec_m
    public      system
dgroup  group   data
cgroup  group   code
    assume ds:dgroup, es:nothing, ss:dgroup, cs:cgroup
    
data segment para public 'DATA'


comm    db  0           ;Full command line. Starts with lenth byte
        db  ' /C '      ;Must start with this ??
actual  db  130 dup(0)  ;Actual requested command line.


pblk        dw  0
commo   dw  0
commb   dw  0
        dw  5ch     ;fcb 1
        dw  0
        dw  6ch     ;fcb 2
        dw  0

cdir    db  30 dup(0)

comsps  db  'COMSPEC='
comspl  equ 8        

data ends

EXE     equ 4bh
GETPSP  equ 62h
GETERR  equ 59h
SETBLK  equ 4ah
ALLOC   equ 48h
code    segment para public 'CODE'
    
system proc near
    push    bp
    mov     bp, sp
    mov     ah, GETPSP              ;Setup parameter block
    int     21h                     ;DOS call
    mov     es, bx                  ;copy info from current PSP

    lea     ax, comm                ;Setup comm address in pblk
    mov     commo, ax               ;"
    mov     ax, ds                  ;"
    mov     commb, ax               ;"

    mov     pblk+8, bx              ;Use same FCB's
    mov     pblk+12, bx             ;"
    mov     bx, es: word ptr 2ch    ;Use same environment
    mov     pblk, bx                ;"

    push    ds              ;Search for command processor name (COMPSPEC=)
    pop     es              ;"
    mov     ds, bx          ;"
    call    findcom         ;Set SI to point to command processor name
    jc      error1          ;Indicated by Carry set
    lea     di, cdir        ;Move command processor name to cdir
move1:
    cmp     byte ptr[si], 0 ;loop until 0 byte moved
    movsb                   ;"
    jnz     move1           ;"
    push    es              ;restore ds
    pop     ds              ;"
    lea     dx, cdir        ;Set ds:dx to point to command processor name
    
    lea     bx, pblk        ;Set es:bx to pblk

    mov     si, [bp+4]      ;Move command line to actual
    lea     di, actual      ;"
    mov     comm, 4         ;(set length to 4)
    cmp     byte ptr[si], 0 ;check if null line
    jz      putcr           ;"
move2:
    movsb                   ;"
    inc     comm
    cmp     byte ptr[si], 0 ;loop until 0 byte detected
    jnz     move2           ;"
putcr:
    mov     byte ptr[di], 13;end with CR
    push    ds              ;Save critical state
    mov     al, 00h         ;Load and exec sub code
    mov     ah, EXE
    int     21h             ;DOS call
    pop     ds
    mov     ax, 0           ;Assume no error
    jnc     exit1
error:
    mov     bx,0
    mov     ah, GETERR
    int     21h             ;DOS call
    mov     ah, bh
exit1:
    pop     bp
    ret     2               ;discard parameter

error1:
    push    es
    pop     ds
    mov     ax, 1
    jmp     exit1

system endp

findcom proc    near        ;DS points to start of environment
                            ;ES to standard data segment.
    mov     si, 0           ;DS,SI points to first environment string
    cld                     ;Search forward
nextstring:
    cmp     byte ptr[si],0  ;environment ends by a null string
    jz      notfound        ;"    
    lea     di, comsps      ;ES,DI points to "COMSPEC="
    mov     cx, comspl      ;CX = strlen("COMSPEC=")
    repe    cmpsb           ;repeat loop
    jcxz    found           ;(86 does not have jcxnz)
    dec     si              ;Unget last char
nextchar:
    lodsb                   ;Find end of string
    cmp     al, 0           ;"
    jnz     nextchar        ;"
    jmp     nextstring      ;"
found:
    clc                     ;ok, si points to COMSPEC string
    ret
notfound:
    stc                     ;no COMSPEC string
    ret
findcom endp

code ends

    end
