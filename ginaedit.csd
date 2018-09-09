;
;   *-*-*   INSTAL.CSD   *-*-*
;
;   Submit file to install AEDIT for the iRMX II Operating System.
;
;   Invocation:  submit :logical name:instal(:logical name:)
;
;      Where:   logical name is the logical name by which the flexible
;                  diskette drive is attached.
;
;
copy %0aedit, &
     %0useful.doc, &
     %0useful.mac, &
     %01510e.mac, &
     %01510t.mac, &
     %0adm3a.mac, &
     %0microb.mac, &
     %0qvt102.mac, &
     %0rgi.mac, &
     %0s120.mac, &
     %0tv910p.mac, &
     %0tv925.mac, &
     %0view3a.mac, &
     %0vt100.mac, &
     %0vt52.mac, &
     %0wyse50.mac, &
     %0zentec.mac over /lang286
;
permit /lang286, /lang286/aedit, /lang286/*.mac, /lang286/*.doc nr u=world
;
;*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
;
;  Installation of AEDIT for the iRMX II Operating System complete.
;
