
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
DCL THENDO  IS   'THEN DO';
DCL ELSEDO  IS   'END; ELSE DO';
DCL ENDIF   IS   'END';

/*****     LIT  PUBLIC    *****/

DCL rmx_string  IS  '16';

DCL ci_file IS '0';
DCL co_file IS '1';

/*****     PUB.PLM    *****/

DCL excep WORD EXTERNAL ;

DCL files(7) STRUCTURE(name WORD,conn WORD) EXTERNAL ;

/*****     COMAND.PLM     *****/

upper: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;

/*****     CONSOL.PLM     *****/

error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;

/*****     IO.PLM     *****/

echeck_no_file: PROC EXTERNAL ; END;
