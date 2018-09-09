;
;  *-*-*  gcraedit.csd  *-*-*
;
;  Submit file to create AEDIT Diskette for iRMX I.
;
;  invocation :  submit gcraedit (device, part number, source, format)
;
;  where: device       is the physical device name of the floppy.
;         part number  is the assigned part number for the diskette.
;         source       is the pathname for the master object directory.
;         format       use a semicolon surrounded by apostrophes to
;                         disable attach and format. (for development)
;
;
%3attachdevice %0 as f d
;
; Use the latest format command
;
%3%2hi/format :F:%1 files=19 ext=41 ms=0
;
copy %2config/cmd/ginaedit86.csd over :f:instal.csd
;
copy %2aedit/src/aeditx.r86 over :f:aedit

copy %2aedit/src/useful.doc, &
     %2aedit/src/useful.mac, &
     %2aedit/src/1510e.mac, &
     %2aedit/src/1510t.mac, &
     %2aedit/src/adm3a.mac, &
     %2aedit/src/microb.mac, &
     %2aedit/src/qvt102.mac, &
     %2aedit/src/rgi.mac, &
     %2aedit/src/s120.mac, &
     %2aedit/src/tv910p.mac, &
     %2aedit/src/tv925.mac, &
     %2aedit/src/view3a.mac, &
     %2aedit/src/vt100.mac, &
     %2aedit/src/vt52.mac, &
     %2aedit/src/wyse50.mac, &
     %2aedit/src/zentec.mac over :f:
;
permit :f:, :f:* nr u=world
permit :f:instal.csd n u=world
;
%3dir :F: free
%3detachdevice f
