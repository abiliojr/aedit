;**********************************************
;       aedit  generation - plm phase         *
;**********************************************
af $ as f1
af ^obj as obj
af ^lst as lst
;
plm86 :f1:aedit.plm  ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:aedit.obj) pr(:lst:aedit.lst)
plm86 :f1:verx.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:verx.obj) pr(:lst:verx.lst)
plm86 :f1:verv.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:verv.obj) pr(:lst:verv.lst)
plm86 :f1:pub.plm    ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:pub.obj) pr(:lst:pub.lst)
plm86 :f1:cctrap.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:cctrap.obj) pr(:lst:cctrap.lst)
plm86 :f1:aedplm.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:aedplm.obj) pr(:lst:aedplm.lst)
plm86 :f1:block.plm  ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:block.obj) pr(:lst:block.lst)
plm86 :f1:calc.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:calc.obj) pr(:lst:calc.lst)
plm86 :f1:cmnds.plm  ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:cmnds.obj) pr(:lst:cmnds.lst)
plm86 :f1:comand.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:comand.obj) pr(:lst:comand.lst)
plm86 :f1:conf.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:conf.obj) pr(:lst:conf.lst)
plm86 :f1:consol.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:consol.obj) pr(:lst:consol.lst)
plm86 :f1:find.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:find.obj) pr(:lst:find.lst)
plm86 :f1:io.plm     ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:io.obj) pr(:lst:io.lst)
plm86 :f1:macrof.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:macrof.obj) pr(:lst:macrof.lst)
plm86 :f1:screen.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:screen.obj) pr(:lst:screen.lst)
plm86 :f1:setcmd.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:setcmd.obj) pr(:lst:setcmd.lst)
plm86 :f1:start.plm  ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:start.obj) pr(:lst:start.lst)
plm86 :f1:tags.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:tags.obj) pr(:lst:tags.lst)
plm86 :f1:tmpman.plm ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:tmpman.obj) pr(:lst:tmpman.lst)
plm86 :f1:util.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:util.obj) pr(:lst:util.lst)
plm86 :f1:view.plm   ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:view.obj) pr(:lst:view.lst)
plm86 :f1:words.plm  ot(2) pw(90) set(rmx,vt100)  %0 &
          oj(:obj:words.obj) pr(:lst:words.lst)
plm86 :f1:rmxsys.plm ot(2) set(rmx,vt100) &
           oj(:obj:rmxsys.obj) pr(:lst:rmxsys.lst)
;
asm86 :f1:aedasm.asm oj(:obj:aedasm.obj) pr(:lst:aedasm.lst)
asm86 :f1:iocasm.asm oj(:obj:iocasm.obj) pr(:lst:iocasm.lst)
asm86 :f1:dossys.asm oj(:obj:dossys.obj) pr(:lst:dossys.lst)
