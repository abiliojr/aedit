af $ as f1
af :lang: as f2
af obj as obj
af lst as lst

delete :obj:*.obj, :lst:*.lst

submit :F1:86plm

;**********************************************
;       AEDIT  Generation - Link Phase        *
;                                             *
; Parameters:                                 *
;   %0   -   X-version or V-version           *
;**********************************************
;
:F2:LINK86 &
           :F1:CCTRAP.OBJ, &
           :F1:TMPMAN.OBJ, & 
           :F2:COMPAC.LIB  &
     TO  :F1:COMPC1.LNK    &
          PRINTCONTROLS(  NOLINES, COMMENTS, NOSYMBOLS, PUBLICS, TYPE) &
          OBJECTCONTROLS(   LINES, COMMENTS,   SYMBOLS,          TYPE, &
             NOPUBLICS EXCEPT( &
                   max_tmpman_mem,     & ; from tmpman
                   tmpman_init,        & ; from tmpman
                   handle_aftn_full,   & ; from tmpman
                   reinit_temp,        & ; from tmpman
                   set_temp_viewonly,  & ; from tmpman
                   read_temp,          & ; from tmpman
                   read_previous_block,& ; from tmpman 
                   backup_temp,        & ; from tmpman
                   skip_to_end,        & ; from tmpman
                   rewind_temp,        & ; from tmpman
                   restore_temp_state, & ; from tmpman 
                   write_temp,         & ; from tmpman
                   cc_trap ) )         & ; from cctrap
              NOBIND 
       

:F2:LINK86 &
           :F1:VERX.OBJ,  :F1:AEDIT.OBJ,  :F1:COMPC1.LNK, &
           :F1:UTIL.OBJ,   :F1:CMNDS.OBJ,  :F1:COMAND.OBJ, :F1:CONF.OBJ,  & 
           :F1:AEDPLM.OBJ, :F1:BLOCK.OBJ,  :F1:CONSOL.OBJ,&
           :F1:IO.OBJ,     :F1:MACROF.OBJ, :F1:SCREEN.OBJ, :F1:SETCMD.OBJ,&
           :F1:START.OBJ,  :F1:TAGS.OBJ,   :F1:VIEW.OBJ,   :F1:PUB.OBJ,   &
           :F1:WORDS.OBJ,  :F1:FIND.OBJ,   :F1:CALC.OBJ, &
           :F1:AEDASM.OBJ, :F1:IOCASM.OBJ, :F1:DOSSYS.OBJ,  &
           :F2:SMALL.LIB,  :F2:PLM86.LIB       &
    TO  :F1:AEDIT.LNK                         &
      SEGSIZE( STACK(700H) , MEMORY(1000H,0FFFFH))   MEMPOOL(0,0FFFFAH) &
      PRINTCONTROLS(  NOLINES, COMMENTS, NOSYMBOLS, PUBLICS, TYPE) &
      OBJECTCONTROLS( LINES, COMMENTS, SYMBOLS, PUBLICS, TYPE)     &
      ORDER( DGROUP(STACK,CONST,DATA,MEMORY)) &
      BIND  NAME(AEDIT)


