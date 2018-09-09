;
;   *-*-*   AEDGEN.CSD   *-*-*
;
;   This submit file generates AEDIT for iRMX II.
;
;   Invocation:  submit aedgen(sys_dir, version_char)
;
;     where: sys_dir is the pathname to the directory of system libraries.
;            version_char is 'x' if an internal version is to be generated or
;                         is 'v' if a release version is to be generated.
;
;
af $ as f1
af :lang: as f2
af %0lib as f3
af ^obj as obj
af ^lst as lst

submit :F1:aedpex

submit :F1:aedplm

submit :F1:aedbnd(%0, %1)

;
;   AEDIT for iRMX II is generated.
;
