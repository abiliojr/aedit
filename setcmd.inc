
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
DCL FOREVER IS   'WHILE 1';
DCL ENDWHILE IS  'END';
DCL FOR     IS   'DO';
DCL THENDO  IS   'THEN DO';
DCL ELSEDO  IS   'END; ELSE DO';
DCL ELSEIF  IS   'END; ELSE IF';
DCL ENDIF   IS   'END';
DCL TRUE    IS   '0FFH';
DCL FALSE   IS   '0';

DCL BOOLEAN IS   'BYTE';
DCL controlc IS '3';
DCL CR      IS '13';
DCL tab     IS '09H';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL rvid IS '0C7H';

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
DCL delimiters (*) BYTE EXTERNAL ;
DCL w_dirty BYTE EXTERNAL ;
DCL first_text_line BYTE EXTERNAL ;
DCL last_text_line BYTE EXTERNAL ;
DCL message_line BYTE EXTERNAL ;
DCL prompt_line BYTE EXTERNAL ;

DCL window STRUCTURE(
        first_text_line BYTE,
        last_text_line BYTE,
        message_line BYTE,
        prompt_line BYTE,
        prompt_number BYTE,
        current_message (81) BYTE,    /* CONTENTS OF WINDOW MESSAGE LINE */
        last_message (81) BYTE,
        current_prompt (81) BYTE,     /*CONTENTS OF WINDOW PROMPT LINE*/
        suppressed_prompt (81) BYTE
                                      ) EXTERNAL ;

DCL command BYTE EXTERNAL ;
DCL auto_indent BYTE EXTERNAL ;
DCL backup_files BYTE EXTERNAL ;
DCL blank_for_tab BYTE EXTERNAL ;
DCL crlf_insert BYTE EXTERNAL ;
DCL find_uplow BYTE EXTERNAL ;
DCL show_find BYTE EXTERNAL ;
DCL token_find BYTE EXTERNAL ;
DCL center_line BYTE EXTERNAL ;
DCL dont_stop_macro_output BYTE EXTERNAL ;
DCL radix BYTE EXTERNAL ;
DCL highbit_flag BOOLEAN EXTERNAL ;

DCL tab_to (255) BYTE EXTERNAL ;
DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_other BYTE EXTERNAL ;
DCL w_in_other BYTE EXTERNAL ;

DCL macro_exec_level BYTE EXTERNAL ;
DCL left$margin BYTE EXTERNAL ;
DCL right$margin BYTE EXTERNAL ;
DCL indent$margin BYTE EXTERNAL ;


/*****     CMNDS.PLM     *****/

dispatched: PROC(command,table_p) BYTE EXTERNAL ;
    DCL command BYTE, table_p WORD; END;
DCL prompt_number BYTE EXTERNAL ;
v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

DCL pause BOOLEAN EXTERNAL ;
is_illegal: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
input_line: PROC(prompt,prev_string)  BYTE EXTERNAL ;
    DCL prompt WORD, prev_string WORD; END;
input_yes_no: PROC(prompt,y_type) BYTE EXTERNAL ;
    DCL prompt WORD, y_type BYTE; END;
input_command: PROC(prompt) BYTE  EXTERNAL ;
    DCL prompt WORD; END;

/*****     LIT CONF     *****/

DCL esc_code IS '0EEH';

/*****     CONSOL.PLM     *****/

DCL current_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
print_message: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
illegal_command: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

macro_file_error: PROCEDURE(string) EXTERNAL ;
    DCL string WORD; END;
macro_byte: PROCEDURE BYTE EXTERNAL ; END;
macro_not_blank: PROCEDURE BYTE EXTERNAL ; END;
find$index:PROCEDURE(ch,ch$list$p) BYTE EXTERNAL ;
    DCL ch BYTE, ch$list$p WORD; END;
stop_macro: PROCEDURE EXTERNAL ; END;
DCL go_flag (*) BOOLEAN EXTERNAL ;


/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     UTIL.PLM     *****/

min: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
init_str: PROCEDURE (str_p, max_len) EXTERNAL ;
    DCL str_p WORD, max_len BYTE ; END;
add_str_char: PROCEDURE (ch) EXTERNAL ;
    DCL ch BYTE; END;
add_str_str: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
add_str_num: PROCEDURE (num,base) EXTERNAL ;
    DCL num DWORD, base BYTE; END;
init_scan: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
skip_char: PROCEDURE (ch) BOOLEAN EXTERNAL ;
    DCL ch BYTE; END;
num_in: PROCEDURE (err_p) WORD EXTERNAL ;
    DCL err_p ADDRESS; END;

