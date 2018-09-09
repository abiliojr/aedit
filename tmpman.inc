
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL PROC    IS   'PROCEDURE';
DCL PROCEND IS   'END';
DCL ENDPROC IS   'END';
DCL ENDWHILE IS  'END';
DCL FOR     IS   'DO';
DCL ENDFOR  IS   'END';
DCL THENDO  IS   'THEN DO';
DCL ELSEDO  IS   'END; ELSE DO';
DCL ENDIF   IS   'END';
DCL TRUE    IS   '0FFH';
DCL FALSE   IS   '0';

DCL LOGICAL IS   'BYTE';
DCL BOOLEAN IS   'BYTE';

/*****     LIT UDI     *****/

DCL E$MEM           IS '02H';
DCL E$SIX           IS '10AH';

/*****     LIT  PUBLIC    *****/

DCL keep_file IS '0';
DCL view_only IS '3';
DCL view_only_wk2 IS '5';

DCL string_len_plus_1 IS '61';
DCL work_file IS '6'; /* only for error messages. */

DCL half1 IS 'STRUCTURE (
 block_size WORD,
 more_input BYTE,
 file_disposition BYTE,
 wk1_blocks WORD,
 wk2_blocks WORD,
 low_s WORD,
 low_e WORD,
 high_s WORD,
 high_e WORD,
 input_name(string_len_plus_1) BYTE,
 output_name(string_len_plus_1) BYTE,' ;

DCL half2 IS '
 new_file BYTE,
 have_eof BYTE,
 tblock(9) WORD,
 toff(9) WORD,
 in_conn WORD,
 dirty BYTE,
 left_column BYTE,
 bol WORD,
 wk1_conn BYTE,
 wk2_conn BYTE)' ;

DCL oa_struc IS 'half1 half2';


/*****     AEDIT.PLM     *****/

DCL aedit_entry LABEL EXTERNAL ;


/*****     PUB.PLM    *****/

DCL oa oa_struc EXTERNAL ;
DCL cursor WORD EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL center_line BYTE EXTERNAL ;
DCL in_other BYTE EXTERNAL ;
DCL excep WORD EXTERNAL ;

DCL work_name (*) BYTE EXTERNAL ;
DCL files(7) STRUCTURE(name WORD,conn WORD) EXTERNAL ;
DCL file_num BYTE EXTERNAL ;


/*****     CMNDS.PLM     *****/

v_cmnd: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

echeck: PROC  EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     UTIL.PLM     *****/

size_of_text_in_memory: PROCEDURE WORD EXTERNAL ; END;

/*****     VIEW.PLM     *****/

re_window: PROCEDURE EXTERNAL ; END;
forward_line: PROCEDURE(num_lines) EXTERNAL ;
    DCL num_lines WORD; END;
