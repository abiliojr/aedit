;**********************************************
; XENIX/AEDIT-286 Generation                  *
;                                             *
;   Parameters:                               *
;       %0 - V or X version
;                                             *
;**********************************************

assign :F2: to /w0/intel
assign :F1: to :F9:aedit.dir/aedsrc.dir

:F2:CONSOL ,:F1:AEDGEN.LOG

:F2:NOTE PEXN IS IN PROGRESS...
; :F2:submit :F1:aedpex

:F2:NOTE COMPILATION IS IN PROGRESS...
:F2:submit :F1:xnxplm

:F2:NOTE BIND IS IN PROGRESS...
:F2:submit :F1:xnxlnk(%0)

:F2:CONSOL ,:VO:
