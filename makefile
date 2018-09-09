# AEDIT makefile
# Copyright 1999 RadiSys Corporation. All rights reserved. 
# $Header: x:/src/rmx/aedit/src/rcs/makefile 1.1 2002/10/10 19:33:06Z Chris Work $

.INCLUDE: //rsys2/eso/tools/swengenv/imacros.wnt
.INCLUDE: //rsys2/eso/tools/swengenv/rmxmacros.wnt

COMPONENT :=    AEDIT_Basic_Text_Editor
VERSION :=      230
NAME :=			$(COMPONENT)_$(VERSION)


PROJECT      :=	aedit
SUB_PROJECTS :=	$(NULL)
TARG_DIR     :=	$(NULL)
TARG_TYPE    :=	$(NULL)


SRCPATH = rmx/rmxiii/aedit/src
LIBRARY_DEPS = 
PROJECT_DEPS = 

EXEC_TARGS := aedit.r28
SRC_TARGS := 
TARGETS  :=	$(EXEC_TARGS)
LOGFILE  :=	$(PROJECT).txt
MAKEFILE :=	makefile
ASM      :=
C        :=
CPP      :=
SRCS     :=
HDRS     :=
OBJ      :=
DEBRIS   :=	$(LOGFILE) $(EXEC_TARGS) *.obj *.lst *.mp1 *.bak *~

f1=./
f2=../../lib/
f3=../../hi/src/
inc=./
sysinc=../../inc/

DEBUG=nodb
LI=
AEDFLAGS=ot(2) set(p286,rmx,vt100)
PLMFLAGS3=cp rom ot(3) db

.PROLOG=1
.GROUPPROLOG:
[@
@echo off
set :F1:=$(f1)
set :F2:=$(f2)
set :F3:=$(f3)
set :inc:=$(inc)
set :sysinc:=$(sysinc)
echo $%
]

%.obj: %.plm
[@
$(PLM286) $< oj($@) $(AEDFLAGS)
]

OBJS=aeddum.obj aedit.obj aedplm.obj block.obj calc.obj cctrap.obj cmnds.obj \
	comand.obj conf.obj consol.obj find.obj halias.obj io.obj macrof.obj \
	pub.obj screen.obj setcmd.obj start.obj tags.obj tmpman.obj util.obj \
	verv.obj verx.obj view.obj words.obj rmxsys.obj
LIBS=$(f2)udiifs.lib $(f2)rmxifc.lib $(lang)plm286.lib
LNKLIBS=$(f2)udiifs.lib $(f2)rmxifc.lib
LNKOBJS=cctrap.obj tmpman.obj rmxsys.obj $(f2)udiifc.lib

aedit.r28: compac.ln2 $(OBJS) $(LIBS) makefile
[@
$(BND286) cf(<+&
		compac.ln2,verv.obj,util.obj,cmnds.obj,comand.obj,conf.obj,aedit.obj,&
		aedplm.obj,block.obj,consol.obj,io.obj,macrof.obj,screen.obj,&
		setcmd.obj,start.obj,tags.obj,view.obj,pub.obj,words.obj,find.obj,&
		calc.obj,aeddum.obj,halias.obj,&
		$(f2)udiifs.lib,$(f2)rmxifc.lib,$(lang)plm286.lib &
		oj(aedit.r28) pr($(lst)aeditIIv.mp1) &
		ss(data(0c00h),stack(0)) nopublics nodb rc(dm(8000h,07ffffh))
+>)
]

compac.ln2: $(LNKOBJS) $(LNKLIBS) makefile
[@
$(BND286) cf(<+
		cctrap.obj,tmpman.obj,rmxsys.obj,$(f2)udiifc.lib,$(f2)rmxifc.lib &
		oj(compac.ln2) pr($(lst)compac.mp1) noload & sys escape
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
			cc_trap)              ; from cctrap
+>)
]

aeddum.obj: aeddum.plm aeddum.inc
aedit.obj: aedit.plm aedit.inc
aedplm.obj: aedplm.plm aedplm.inc
block.obj: block.plm block.inc
calc.obj: calc.plm calc.inc
cctrap.obj: cctrap.plm cctrap.inc
cmnds.obj: cmnds.plm cmnds.inc
comand.obj: comand.plm comand.inc
conf.obj: conf.plm conf.inc
consol.obj: consol.plm consol.inc
find.obj: find.plm find.inc
halias.ext: ../../hicusps/src/halias.ext
	$(MKSBIN)/cp -f $^ $@
halias.obj: halias.plm sbltin.lit $(sysinc)nuclus.ext $(sysinc)eios.ext \
			$(sysinc)hi.ext
[@
$(PLM286) $*.plm oj($@) $(PLMFLAGS3)
]
halias.plm: ../../hicusps/src/halias.p28
	$(MKSBIN)/cp -f $^ $@
io.obj: io.plm io.inc
macrof.obj: macrof.plm macrof.inc
pub.obj: pub.plm pub.inc
rmxsys.obj: rmxsys.plm rmxsys.inc halias.ext
sbltin.lit: ../../hicusps/src/sbltin.lit
	$(MKSBIN)/cp -f $^ $@
screen.obj: screen.plm screen.inc
setcmd.obj: setcmd.plm setcmd.inc
start.obj: start.plm start.inc
tags.obj: tags.plm tags.inc
tmpman.obj: tmpman.plm tmpman.inc
util.obj: util.plm util.inc
verv.obj: verv.plm
verx.obj: verx.plm
view.obj: view.plm view.inc
words.obj: words.plm words.inc
xnxsy1.obj: xnxsy1.plm
xnxsys.obj: xnxsys.plm
