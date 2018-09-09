; Perform a bios calls to the Video driver
; Three entry points are supplied here:
;
; 1. vo_basic
;    Calling sequence from PLM86:
;
;    call vo_basic(ax,bx,cx,dx)
;
;    where each of the parameters is a word.
;    The parameters are each loaded into the corresponding register and an 
;    INT 10H is performed to the Video entry point in the bios.
;
; 2. vo_string
;    Calling sequence from PLM86:
;
;    call vo_string(bx, cx, dx, bp);
;    
;    Where bx, cx, dx are the parameters for the write string function and
;    bp is the pointer to the string.
;    Again each of the parameter is loaded to the corresponding string and
;    INT 10H is performed.
;
; 3. vo_curpos
;    Calling sequence from PLM86:
;
;    curpos = vo_curpos;
;
;    No parameters are supplied. The routine returns the current row number
;    in AH and column number in AL (HOME is 0,0).
; 
; Note - SMALL model is assumed, thus bp is a word and ES is loaded from DS

	name	bios_vo
	
	public	vo_basic, vo_string, vo_curpos

cgroup	group	code
code	segment	public 'CODE'
	assume	cs:cgroup

WRTSTR	equ	1301H
GETPOS	equ	0300H
	
vo_basic	proc	near
	pop	si	;return address
	pop	dx
	pop	cx
	pop	bx
	pop	ax

	push	si	;push back return address
	int	10h
	ret
vo_basic	endp

vo_string	proc	near
	pop	si	;return address
	mov	di, bp	;save bp
	pop	bp	;string pointer
	mov	ax,ds	;set es to ds (SMALL model)
	mov	es,ax
	pop	dx
	pop	cx
	pop	bx
	mov	ax,WRTSTR

	push	si	;push back return addressi
	push	di	;save bp
	int	10h
	pop	bp
	ret
vo_string	endp

vo_curpos	proc	near
	mov	bx, 0	;assume active page is zero!
	mov	ax, GETPOS
	int	10H
	mov	ax,dx	;return position
	ret
vo_curpos	endp

code	ends

	end
