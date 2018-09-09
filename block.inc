
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL LOOP    IS   'DO; a_begin_loop:DO WHILE';
DCL ENDLOOP IS   'END a_begin_loop;b_end_loop:END;';
DCL REPEAT  IS   'DO; a_begin_loop:DO;';
DCL UNTIL   IS   'IF NOT(';
DCL ENDREPEAT IS ') THEN GOTO a_begin_loop; END a_begin_loop; b_end_loop:END;';
DCL ENDREP  IS   'ENDREPEAT';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
DCL ENDWHILE IS  'END';
DCL THENDO  IS   'THEN DO';
DCL ELSEDO  IS   'END; ELSE DO';
DCL ELSEIF  IS   'END; ELSE IF';
DCL ENDIF   IS   'END';
DCL TRUE    IS   '0FFH';
DCL FALSE   IS   '0';

DCL LOGICAL IS   'BYTE';
DCL BOOLEAN IS   'BYTE';
DCL controlc IS '3';
DCL CR      IS '13';
DCL tab     IS '09H';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL view_only IS '3';
DCL rvid IS '0C7H';

DCL ed_tagi IS '7';
DCL string_len_plus_1 IS '61';
DCL util_file IS '5';
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
DCL high_s_byte BASED oa.high_s BYTE;
DCL cursor WORD EXTERNAL ;
DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
DCL saved_from WORD EXTERNAL ;
DCL line_size (*) BYTE EXTERNAL ;

DCL first_text_line BYTE EXTERNAL ;
DCL last_text_line BYTE EXTERNAL ;
DCL message_line BYTE EXTERNAL ;
DCL command BYTE EXTERNAL ;
DCL last_cmd BYTE EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL infinite BYTE EXTERNAL ;

DCL tab_to (255) BYTE EXTERNAL ;
DCL cc_flag BYTE EXTERNAL ;
DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL invalid_null_name (*) BYTE EXTERNAL ;


/*****     AEDPLM.PLM     *****/

position_in_text:PROC EXTERNAL ; END;
next_line:PROC(ptr) WORD EXTERNAL ;
    DCL ptr WORD; END;

/*****     CALC.PLM     *****/

DCL s_get_file (*) BYTE EXTERNAL ;
DCL s_put_file (*) BYTE EXTERNAL ;

/*****     CMNDS.PLM     *****/

dispatched: PROC(command,table_p) BYTE EXTERNAL ;
    DCL command BYTE, table_p WORD; END;
set_dirty:PROC EXTERNAL ; END;
cr_cmnd: PROC EXTERNAL ; END;
move_cmnd: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
j_cmnd: PROC  EXTERNAL ; END;
v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

input_filename: PROC (prompt,prev_string)  BYTE EXTERNAL ;
    DCL prompt WORD, prev_string WORD; END;
input_yes_no_from_console: PROC(prompt,y_type,in_replace) BYTE EXTERNAL ;
    DCL prompt WORD, y_type BOOLEAN, in_replace BOOLEAN; END;
input_command: PROC(prompt) BYTE  EXTERNAL ;
    DCL prompt WORD; END;

/*****     LIT CONF     *****/

DCL SIIIE   IS '3';
DCL SIIIEO  IS '4';
DCL esc_code IS '0EEH';
DCL macro_exec_code IS '0F4H';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL print_as(*) BYTE EXTERNAL ;

/*****     CONSOL.PLM     *****/

printable: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
text_co: PROC(ch) EXTERNAL ;
    DCL ch BYTE; END;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
illegal_command: PROC EXTERNAL ; END;
rebuild_screen: PROC EXTERNAL ; END;


/*****    FIND.PLM    *****/

fr_cmnd: PROC  EXTERNAL ; END;


/*****     IO.PLM     *****/

test_file_existence:PROC(fnum) BYTE EXTERNAL ;
    DCL fnum BYTE; END;
check_window: PROC(plusplus) EXTERNAL ;
    DCL plusplus WORD; END;
write_block_file: PROC(do_delete) EXTERNAL ;
    DCL do_delete BYTE; END;
write_util_file: PROC EXTERNAL ; END;
read_util_file: PROC  EXTERNAL ; END;
read_block_file: PROC  EXTERNAL ; END;
have_controlc: PROC BYTE EXTERNAL ; END;

/*****     MACROF.PLM     *****/

single_char_macro:PROCEDURE(ch) LOGICAL EXTERNAL ;
    DCL ch BYTE; END;
handle_macro_exec_code: PROC EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;
put_start_row: PROCEDURE(new_row) EXTERNAL ;
    DCL new_row BYTE; END;
put_insert_line: PROCEDURE(num) EXTERNAL ;
    DCL num WORD; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
jump_tagi: PROCEDURE EXTERNAL ; END;
delete_to_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;


/*****     UTIL.PLM     *****/

word_movb: PROCEDURE(source,destination,len) EXTERNAL ;
    DCL (source,destination,len) WORD; END;

/*****     VIEW.PLM     *****/

save_line: PROCEDURE(s_row) EXTERNAL ;
    DCL s_row BYTE; END;
re_view: PROCEDURE EXTERNAL ; END;

