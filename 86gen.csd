;**********************************************
; AEDIT-86 Generation                         *
;                                             *
;   Parameters:                               *
;       %0 - V or X version
;                                             *
;**********************************************

assign :F2: to /w0/intel
assign :F1: to :F9:aedit.dir/aedsrc.dir

:F2:CONSOL ,:F1:AEDGEN.LOG

:F2:NOTE PEXN IS IN PROGRESS...
:F2:submit :F1:aedpex

:F2:NOTE COMPILATION IS IN PROGRESS...
:F2:submit :F1:86plm

:F2:NOTE LINK IS IN PROGRESS...
:F2:submit :F1:86lnk(%0)

:F2:CONSOL ,:VO:
