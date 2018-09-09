;
;   *-*-*   AEDBND.CSD   *-*-*
;
;    Submit file to bind Aedit for iRMX II.
;
;    Invocation:  submit aedbnd(start_dir, version_char)
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

bnd286 &
    :obj:cctrap.obj,     &
    :obj:tmpman.obj,     & 
    :obj:rmxsys.obj,     & 
    :f2:udiifc.lib,      &
    :f2:rmxifc.lib       &   sys escape
    object(:obj:compac.lnk)   &
    print (:obj:compac.mp1)   &
    noload                    & 
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
              cc_trap )             ; from cctrap
  
bnd286    &
    :obj:compac.lnk, :obj:ver%1.obj, &
    :obj:util.obj,   :obj:cmnds.obj,  :obj:comand.obj, :obj:conf.obj,  &
    :obj:aedit.obj,  :obj:aedplm.obj, :obj:block.obj,  :obj:consol.obj,&
    :obj:io.obj,     :obj:macrof.obj, :obj:screen.obj, :obj:setcmd.obj,&
    :obj:start.obj,  :obj:tags.obj,   :obj:view.obj,   :obj:pub.obj,   &
    :obj:words.obj,  :obj:find.obj,   :obj:calc.obj,   :obj:aeddum.obj, &
    :f2:udiifs.lib, :f2:rmxifc.lib, :lang:plm286.lib &
     object(:f1:aedit.r28) print (:f1:aeditII%1.mp1)   &
     segsize(data(0c00h),stack(0))  &
     nopublics nodebug     &
     rconfigure(dm(8000h,07ffffh))
