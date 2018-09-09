
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
DCL FOREVER IS   'WHILE 1';
DCL ENDWHILE IS  'END';
DCL ENDCASE IS   'END';
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
DCL WBYTE   IS   'WORD';
DCL LVARS   IS   'REENTRANT';
DCL controlc IS '3';
DCL CR      IS '13';
DCL tab     IS '09H';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL view_only IS '3';
DCL rvid IS '0C7H';

DCL string_len_plus_1 IS '61';
DCL rmx_string  IS  '16';

DCL mac_file IS '2';
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
DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
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
DCL command BYTE EXTERNAL ;
DCL last_main_cmd BYTE EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL infinite BYTE EXTERNAL ;

DCL cc_flag BYTE EXTERNAL ;
DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_macro_def BYTE EXTERNAL ;
DCL macro_exec_level BYTE EXTERNAL ;
DCL excep WORD EXTERNAL ;

DCL hex_digits (*) BYTE EXTERNAL ;

DCL batch_mode LOGICAL EXTERNAL ;
DCL no_such_macro (*) BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;

DCL do_type_ahead BOOLEAN EXTERNAL ;

DCL delay_after_each_char WORD EXTERNAL ;


/*****     AEDPLM.PLM     *****/

position_in_text:PROC EXTERNAL ; END;

/*****     CALC.PLM     *****/

DCL s_macro_file (*) BYTE EXTERNAL ;
DCL s_macro_name (*) BYTE EXTERNAL ;


/*****     LIT CMNDS     *****/

DCL not_hex IS '99';


/*****     CMNDS.PLM     *****/

dispatched: PROC(command,table_p) BYTE EXTERNAL ;
    DCL command BYTE, table_p WORD; END;
set_dirty:PROC EXTERNAL ; END;
test_crlf: PROC EXTERNAL ; END;
insert$a$char: PROC(ch) EXTERNAL ;
    DCL ch BYTE; END;
insert_crlf: PROC EXTERNAL ; END;
DCL prompt_number BYTE EXTERNAL ;
hex_value: PROC(char) BYTE EXTERNAL ;
    DCL char BYTE; END;

/*****     COMAND.PLM     *****/

DCL strip_parity BOOLEAN EXTERNAL ;
cmd_ci: PROC BYTE EXTERNAL ; END;
upper: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
is_illegal: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
add_str_special: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
input_filename: PROC (prompt,prev_string)  BYTE EXTERNAL ;
    DCL prompt WORD, prev_string WORD; END;
input_command: PROC(prompt) BYTE  EXTERNAL ;
    DCL prompt WORD; END;
hit_space: PROC BYTE EXTERNAL ; END;

/*****     LIT CONF     *****/

DCL SIV     IS '1';
DCL first_code IS '0E8H';
DCL esc_code IS '0EEH';
DCL rubout_code IS '0F3H';
DCL last_code IS '0F8H';
DCL col_first IS '0';
DCL row_first IS '1';
DCL offset_index IS '12';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL wrapper BYTE EXTERNAL ;
DCL print_as(*) BYTE EXTERNAL ;
DCL input_code_names (17) WORD EXTERNAL ;
DCL INPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;

DCL first_coordinate BYTE EXTERNAL ;
DCL visible_attributes BYTE EXTERNAL ;
DCL character_attributes BYTE EXTERNAL ;

DCL output_code_names (17) WORD EXTERNAL ;
DCL OUTPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;
DCL delay_times (17) WORD EXTERNAL ;

insert_long_config: PROC (new_str_p, entry_p) EXTERNAL ;
    DCL (new_str_p, entry_p) ADDRESS; END;
SIV_setup: PROC EXTERNAL ; END;
SIII_setup: PROC EXTERNAL ; END;
SIIIE_setup: PROC EXTERNAL ; END;
SIIIET_setup: PROC EXTERNAL ; END;
PCDOS_setup: PROCEDURE EXTERNAL ; END;
VT100_setup: PROC EXTERNAL ; END;
ANSI_setup: PROC EXTERNAL ; END;
ibm_pc_setup: PROC EXTERNAL ; END;
reset_config: PROC EXTERNAL ; END;
DCL exit_config_list (41) BYTE EXTERNAL ;

/*****     CONSOL.PLM     *****/

DCL error_status STRUCTURE (
         in_invocation   BOOLEAN,
         from_macro_file BOOLEAN,
         key_was_space   BOOLEAN) EXTERNAL ;
DCL current_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
DCL bell_on BOOLEAN EXTERNAL ;
print_message: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
illegal_command: PROC EXTERNAL ; END;
kill_message: PROC EXTERNAL ; END;
clear_message: PROC EXTERNAL ; END;
print_prompt_and_repos: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
rebuild_screen: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

DCL input_expected_flag BOOLEAN EXTERNAL ;
set_input_expected: PROC (ch) EXTERNAL ;
    DCL ch BYTE; END;
print_unconditionally: PROC (string) EXTERNAL ;
    DCL string WORD; END;
co_flush: PROC  EXTERNAL ; END;
DCL cc_code_buf (*) BYTE EXTERNAL ;
check$for$keys:PROC  EXTERNAL ; END;
echeck: PROC  EXTERNAL ; END;
openi: PROC(fnum,nbuf)  EXTERNAL ;
    DCL (fnum,nbuf) BYTE; END;
detach: PROC(fnum) EXTERNAL ;
    DCL fnum BYTE; END;
macro_file_read: PROC WORD  EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     SETCMD.PLM     *****/

set_from_macro: PROCEDURE BYTE EXTERNAL ; END;


/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;
print_banner: PROCEDURE EXTERNAL ; END;
DCL debug$option$list (30) BYTE EXTERNAL ;

/*****    TMPMAN.PLM    *****/

DCL max_tmpman_mem WORD EXTERNAL ;


/*****     UTIL.PLM     *****/

word_movb: PROCEDURE(source,destination,len) EXTERNAL ;
    DCL (source,destination,len) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;
cmp_name: PROCEDURE(fromp,top) BYTE  EXTERNAL ;
    DCL (fromp,top) WORD; END;
init_str: PROCEDURE (str_p, max_len) EXTERNAL ;
    DCL str_p WORD, max_len BYTE ; END;
add_str_char: PROCEDURE (ch) EXTERNAL ;
    DCL ch BYTE; END;
add_str_str: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
add_str_num: PROCEDURE (num,base) EXTERNAL ;
    DCL num DWORD, base BYTE; END;

/*****     VIEW.PLM     *****/

save_line: PROCEDURE(s_row) EXTERNAL ;
    DCL s_row BYTE; END;
re_view: PROCEDURE EXTERNAL ; END;


/*****   LIT AEDDUM   *****/

DCL memory_leng IS '48000';

