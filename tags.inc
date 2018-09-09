
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
DCL FOR     IS   'DO';
DCL ENDFOR  IS   'END';
DCL THENDO  IS   'THEN DO';
DCL ELSEDO  IS   'END; ELSE DO';
DCL ELSEIF  IS   'END; ELSE IF';
DCL ENDIF   IS   'END';
DCL WBYTE   IS   'WORD';

/*****     LIT  PUBLIC    *****/

DCL ed_tagi IS '7';
DCL ed_tagw IS '8';

DCL num_tag IS '8';

DCL string_len_plus_1 IS '61';
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


/*****     PUB.PLM    *****/

DCL oa oa_struc EXTERNAL ;
DCL cursor WORD EXTERNAL ;
DCL row BYTE EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
DCL first_text_line BYTE EXTERNAL ;
DCL in_other BYTE EXTERNAL ;
DCL w_in_other BYTE EXTERNAL ;

DCL file_num BYTE EXTERNAL ;


/*****     CMNDS.PLM     *****/

dont_scroll: PROC EXTERNAL ; END;
v_cmnd: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

backup_file: PROC BYTE  EXTERNAL ; END;
forward_file: PROC BYTE  EXTERNAL ; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****    TMPMAN.PLM    *****/

backup_temp: PROCEDURE(file_num) EXTERNAL ;
    DCL file_num BYTE; END;

/*****     VIEW.PLM     *****/

re_window: PROCEDURE EXTERNAL ; END;
save_line: PROCEDURE(s_row) EXTERNAL ;
    DCL s_row BYTE; END;
