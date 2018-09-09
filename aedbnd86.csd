;
;   *-*-*   AEDBND86.CSD   *-*-*
;
;    Submit file to bind Aedit for iRMX I.
;
;    Invocation:  submit aedbnd86(start_dir, version_char)
;
;     where: start_dir is the pathname to the workspace directory.
;            version_char is 'x' if an internal version is to be generated or
;                         is 'v' if a release version is to be generated.
;
;
af $ as f1
af %0lib as f2
af ^obj as obj
af ^lst as lst

link86 &
     :obj:cctrap.obj, &
     :obj:tmpman.obj, & 
     :obj:rmxsys.obj, & 
     :f2:rpifc.lib,   &
     :f2:hpifc.lib,   &
     :f2:compac.lib   &
     to  :obj:compc1.lnk    &
     printcontrols(  nolines, comments, nosymbols, publics, type) &
     objectcontrols(   lines, comments,   symbols,          type, &
     nopublics except( &
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
                   system,             & ; from rmxsys
                   find_term_type,     & ; from rmxsys
                   excep_handler_p,    & ; from cctrap
                   cc_trap ) )         & ; from cctrap
    nobind 

link86 &
    :obj:ver%1.obj,  :obj:aedit.obj,  :obj:compc1.lnk, &
    :obj:util.obj,   :obj:cmnds.obj,  :obj:comand.obj, :obj:conf.obj, & 
    :obj:aedplm.obj, :obj:block.obj,  :obj:consol.obj,&
    :obj:io.obj,     :obj:macrof.obj, :obj:screen.obj, :obj:setcmd.obj,&
    :obj:start.obj,  :obj:tags.obj,   :obj:view.obj,   :obj:pub.obj,   &
    :obj:words.obj,  :obj:find.obj,   :obj:calc.obj, &
    :obj:aedasm.obj, :obj:iocasm.obj, &
    :f2:small.lib,   :lang:plm86.lib  &
    to  :f1:aedit%1.r86 print(:f1:aeditI%1.mp1) &
    segsize( stack(700h) , memory(1000h,0fffah))   mempool(0,0ffffah) &
    printcontrols(  nolines, comments, nosymbols, publics, type) &
    objectcontrols( lines, comments, symbols, publics, type)     &
    order( dgroup(stack,const,data,memory)) &
    bind  name(aedit)
;
;  what does this thing do?
;run :f2:crush :f1:aedit.lnk to :f1:aedit%0.86
