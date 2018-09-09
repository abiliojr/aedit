
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL LOOP    IS   'DO; a_begin_loop:DO WHILE';
DCL RELOOP  IS   'GOTO A_begin_loop';
DCL ENDLOOP IS   'END a_begin_loop;b_end_loop:END;';
DCL PROC    IS   'PROCEDURE';
DCL ENDWHILE IS  'END';
DCL THENDO  IS   'THEN DO';
DCL ELSEDO  IS   'END; ELSE DO';
DCL ENDIF   IS   'END';
DCL TRUE    IS   '0FFH';
DCL BOOLEAN IS   'BYTE';
DCL tab     IS '09H';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL ed_tagb IS '6';
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
DCL low_e_byte BASED oa.low_e BYTE;
DCL cursor WORD EXTERNAL ;
DCL row BYTE EXTERNAL ;
DCL virtual_col BYTE EXTERNAL ;

DCL wrapping_column BYTE EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
DCL first_text_line BYTE EXTERNAL ;
DCL message_line BYTE EXTERNAL ;
DCL force_column BYTE EXTERNAL ;

DCL count WORD EXTERNAL ;
DCL tab_to (255) BYTE EXTERNAL ;
DCL macro_suppress BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;


/*****     CONF.PLM     *****/

DCL print_as(*) BYTE EXTERNAL ;

/*****     CONSOL.PLM     *****/

printable: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;

/*****     IO.PLM     *****/

can_forward_file: PROC BYTE EXTERNAL ; END;
forward_file: PROC BYTE  EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
jump_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;
