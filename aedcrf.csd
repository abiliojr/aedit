;**********************************************
;       AEDIT V2.0 Generation -               *
;       Intermodule Cross Reference Phase     *
;                                             *
;**********************************************

RUN :F2:CREF86 &
      :F1:AEDIT.OBJ,  :F1:CCTRAP.OBJ, :F1:AEDPLM.OBJ, :F1:BLOCK.OBJ, &
      :F1:CALC.OBJ,   :F1:CMNDS.OBJ,  :F1:COMAND.OBJ, :F1:CONF.OBJ,  & 
      :F1:CONSOL.OBJ, :F1:IO.OBJ,     :F1:MACROF.OBJ, :F1:SCREEN.OBJ,& 
      :F1:SETCMD.OBJ, :F1:START.OBJ,  :F1:TAGS.OBJ,   :F1:TMPMAN.OBJ,& 
      :F1:UTIL.OBJ,   :F1:VIEW.OBJ,   :F1:WORDS.OBJ,  :F1:FIND.OBJ,  &
      :F1:AEDASM.OBJ, :F1:IOCASM.OBJ, :F1:PUB.OBJ,    :F1:VERX.OBJ,  &
   & !!!!!!!!!  :F1:RMXSYS.OBJ, :F1:INFACE.OBJ, :F1:TRMCAP.OBJ, &
      :F2:SMALL.LIB , :F2:PLM86.LIB &
   PW(80) PRINT(:F1:AEDIT.CRF)

