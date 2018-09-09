
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL REPEAT  IS   'DO; a_begin_loop:DO;';
DCL UNTIL   IS   'IF NOT(';
DCL ENDREPEAT IS ') THEN GOTO a_begin_loop; END a_begin_loop; b_end_loop:END;';
DCL ENDREP  IS   'ENDREPEAT';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
DCL FOREVER IS   'WHILE 1';
DCL ENDWHILE IS  'END';
DCL FOR     IS   'DO';
DCL ENDFOR  IS   'END';
DCL THENDO  IS   'THEN DO';
DCL ELSEDO  IS   'END; ELSE DO';
DCL ELSEIF  IS   'END; ELSE IF';
DCL ENDIF   IS   'END';
DCL TRUE    IS   '0FFH';
DCL FALSE   IS   '0';

DCL LOGICAL IS   'BYTE';
DCL BOOLEAN IS   'BYTE';
DCL LVARS   IS   'REENTRANT';
DCL controlc IS '3';
DCL CR      IS '13';
DCL tab     IS '09H';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL rvid IS '0C7H';

DCL ed_taga IS '5';
DCL ed_tagb IS '6';
DCL ed_tagw IS '8';

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


/*****     AEDIT.PLM     *****/

DCL prompts (*) WORD EXTERNAL ;

/*****     PUB.PLM    *****/

DCL oa oa_struc EXTERNAL ;
DCL ob oa_struc EXTERNAL ;

DCL w_dirty BYTE EXTERNAL ;
DCL low_e_byte BASED oa.low_e BYTE;
DCL high_s_byte BASED oa.high_s BYTE;
DCL cursor WORD EXTERNAL ;
DCL row BYTE EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
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

DCL window_present BYTE EXTERNAL ;
DCL window_num BYTE EXTERNAL ;


DCL command BYTE EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL infinite BYTE EXTERNAL ;

DCL center_line BYTE EXTERNAL ;
DCL cc_flag BYTE EXTERNAL ;
DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_macro_def BYTE EXTERNAL ;
DCL in_other BYTE EXTERNAL ;
DCL w_in_other BYTE EXTERNAL ;

DCL macro_suppress BYTE EXTERNAL ;

DCL left$margin BYTE EXTERNAL ;
DCL right$margin BYTE EXTERNAL ;
DCL indent$margin BYTE EXTERNAL ;

DCL null_str BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;


/*****     CMNDS.PLM     *****/

set_dirty:PROC EXTERNAL ; END;
insert_crlf: PROC EXTERNAL ; END;
jump_start: PROC EXTERNAL ; END;
DCL prompt_number BYTE EXTERNAL ;
v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

input_command: PROC(prompt) BYTE  EXTERNAL ;
    DCL prompt WORD; END;

/*****     LIT CONF     *****/

DCL ANSI    IS '6';
DCL VT100   IS '7';
DCL esc_code IS '0EEH';
DCL erase_line_out_code IS '8';
DCL erase_entire_line_out_code IS '9';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL OUTPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;

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
init_prompt_and_message:PROC EXTERNAL ; END;
print_prompt: PROC(line) EXTERNAL ;
    DCL line WORD; END;
rebuild_screen: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

DCL input_expected_flag BOOLEAN EXTERNAL ;
set_input_expected: PROC (ch) EXTERNAL ;
    DCL ch BYTE; END;
co_flush: PROC  EXTERNAL ; END;
check$for$keys:PROC  EXTERNAL ; END;
backup_file: PROC BYTE  EXTERNAL ; END;
can_forward_file: PROC BYTE EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

stop_macro: PROCEDURE EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_scroll_region: PROC (first_row,last_row) EXTERNAL ;
    DCL (first_row,last_row) BYTE; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;
flip_pointers: PROCEDURE  EXTERNAL ; END;

/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
jump_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;

/*****     UTIL.PLM     *****/

max: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;

/*****     VIEW.PLM     *****/

DCL psaved_line BYTE EXTERNAL ;
re_window: PROCEDURE EXTERNAL ; END;
save_line: PROCEDURE(s_row) EXTERNAL ;
    DCL s_row BYTE; END;
forward_char: PROCEDURE(num_chars,delete_flag) EXTERNAL ;
    DCL num_chars WORD, delete_flag BYTE; END;
backup_char: PROCEDURE(num_chars,delete_flag) EXTERNAL ;
    DCL num_chars WORD, delete_flag BYTE; END;
re_view: PROCEDURE EXTERNAL ; END;

