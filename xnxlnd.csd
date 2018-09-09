;**************************************
;  LINK XENIX/AEDIT-286
;    + OSIS + new udi + BND286 >= X228  
;**************************************


:F2:RUN :F2:BND286.86 &
  :F1:CCTRAP.OBX, &
  :F1:TMPMAN.OBX, & 
  :F2:XUDIC.LIB   &
      OJ(:F1:COMPC2.LNK) PRINT(:F1:COMPC2.MP1) &
      NOLOAD & 
      NOPUBLICS EXCEPT( &
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
          cc_trap )             ; from cctrap



:F2:RUN :F2:BND286.86 &
  :F1:COMPC2.LNK, &
  :F1:VER%0.OBX, &
  :F1:UTIL.OBX,   :F1:CMNDS.OBX,  :F1:COMAND.OBX, :F1:CONF.OBX,  &
  :F1:AEDIT.OBX,  :F1:AEDPLM.OBX, :F1:BLOCK.OBX,  :F1:CONSOL.OBX,&
  :F1:IO.OBX,     :F1:MACROF.OBX, :F1:SCREEN.OBX, :F1:SETCMD.OBX,&
  :F1:START.OBX,  :F1:TAGS.OBX,   :F1:VIEW.OBX,   :F1:PUB.OBX,   &
  :F1:WORDS.OBX,  :F1:FIND.OBX,   :F1:CALC.OBX,  &
  :F1:AEDDUM.OBX, :F1:XNXSYS.OBX, &
  :F2:OSISL.OBJ, :F2:PLM286.LIB, &
  :F2:XUDIS.LIB, :F2:XNXUDI.LIB, &
  :F2:LLIBC.LIB, :F2:LLIBX.LIB  &
      OJ(:F1:AEDXNX.LNK) PRINT(:F1:AEDXNX.MP1) &
      SEGSIZE( DATA(0800H), STACK(0H)) &
      RENAMESEG(OSIS_CODE TO CODE,OSIS_DATA TO DATA) &
      DEBUG XC

