
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL LOOP    IS   'DO; a_begin_loop:DO WHILE';
DCL RELOOP  IS   'GOTO A_begin_loop';
DCL ENDLOOP IS   'END a_begin_loop;b_end_loop:END;';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
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
DCL controlc IS '3';
DCL CR      IS '13';
DCL tab     IS '09H';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL view_only IS '3';
DCL rvid IS '0C7H';

DCL ed_taga IS '5';
DCL ed_tagb IS '6';
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
DCL w_dirty BYTE EXTERNAL ;
DCL low_e_byte BASED oa.low_e BYTE;
DCL high_s_byte BASED oa.high_s BYTE;
DCL cursor WORD EXTERNAL ;
DCL cursor_byte BASED cursor BYTE;

DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
DCL virtual_col BYTE EXTERNAL ;

DCL have (*) WORD EXTERNAL ;
DCL saved_from WORD EXTERNAL ;
DCL first_text_line BYTE EXTERNAL ;
DCL last_text_line BYTE EXTERNAL ;
DCL message_line BYTE EXTERNAL ;
DCL force_column BYTE EXTERNAL ;

DCL command BYTE EXTERNAL ;
DCL last_cmd BYTE EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL infinite BYTE EXTERNAL ;

DCL auto_indent BYTE EXTERNAL ;
DCL blank_for_tab BYTE EXTERNAL ;
DCL crlf_insert BYTE EXTERNAL ;
DCL radix BYTE EXTERNAL ;
DCL tab_to (255) BYTE EXTERNAL ;
DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_other BYTE EXTERNAL ;
DCL w_in_other BYTE EXTERNAL ;

DCL macro_exec_level BYTE EXTERNAL ;
DCL hex_digits (*) BYTE EXTERNAL ;

DCL right$margin BYTE EXTERNAL ;
DCL force_writing BOOLEAN EXTERNAL ;


/*****     AEDPLM.PLM     *****/

position_in_text:PROC EXTERNAL ; END;

/*****     BLOCK.PLM     *****/

DCL first_at_sign_is_here BOOLEAN EXTERNAL ;


/*****     CALC.PLM     *****/

get_n_var:PROC (radix, add_minus) WORD EXTERNAL ;
    DCL radix BYTE, add_minus BOOLEAN; END;
get_s_var:PROC WORD EXTERNAL ; END;

/*****     LIT CMNDS     *****/

DCL ubuf_size IS '100';
DCL not_hex IS '99';


/*****     COMAND.PLM     *****/

cmd_ci: PROC BYTE EXTERNAL ; END;
is_illegal: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
input_line: PROC(prompt,prev_string)  BYTE EXTERNAL ;
    DCL prompt WORD, prev_string WORD; END;
input_command: PROC(prompt) BYTE  EXTERNAL ;
    DCL prompt WORD; END;
hit_space: PROC BYTE EXTERNAL ; END;
get_hexin: PROC (err_p) BYTE EXTERNAL ;
    DCL err_p ADDRESS; END;


/*****     LIT CONF     *****/

DCL up_code IS '0E8H';
DCL down_code IS '0E9H';
DCL left_code IS '0EAH';
DCL right_code IS '0EBH';
DCL home_code IS '0ECH';
DCL delete_code IS '0EDH';
DCL esc_code IS '0EEH';
DCL delete_line_code IS '0EFH';
DCL delete_left_code IS '0F0H';
DCL delete_right_code IS '0F1H';
DCL undo_code IS '0F2H';
DCL rubout_code IS '0F3H';
DCL macro_exec_code IS '0F4H';
DCL s_var_code IS '0F5H';
DCL n_var_code IS '0F6H';
DCL hexin_code IS '0F7H';

/*****     CONSOL.PLM     *****/

beep: PROC EXTERNAL ; END;
print_message: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
illegal_command: PROC EXTERNAL ; END;
clear_message: PROC EXTERNAL ; END;
print_prompt_and_repos: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
rebuild_screen: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

co_flush: PROC  EXTERNAL ; END;
check_window: PROC(plusplus) EXTERNAL ;
    DCL plusplus WORD; END;
backup_file: PROC BYTE  EXTERNAL ; END;
can_forward_file: PROC BYTE EXTERNAL ; END;
forward_file: PROC BYTE  EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

stop_macro: PROCEDURE EXTERNAL ; END;
single_char_macro:PROCEDURE(ch) LOGICAL EXTERNAL ;
    DCL ch BYTE; END;
handle_macro_exec_code: PROC EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_clear_all_text: PROCEDURE EXTERNAL ; END;
put_insert_line: PROCEDURE(num) EXTERNAL ;
    DCL num WORD; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
set_tagi_at_lowe: PROCEDURE EXTERNAL ; END;
jump_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;
clean_tags: PROCEDURE  EXTERNAL ; END;
delete_to_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;


/*****     UTIL.PLM     *****/

min: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
word_movb: PROCEDURE(source,destination,len) EXTERNAL ;
    DCL (source,destination,len) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;
init_str: PROCEDURE (str_p, max_len) EXTERNAL ;
    DCL str_p WORD, max_len BYTE ; END;
add_str_char: PROCEDURE (ch) EXTERNAL ;
    DCL ch BYTE; END;
add_str_str: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
DCL scan_p WORD EXTERNAL ;
DCL scan_byte BASED scan_p BYTE;
init_scan: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
skip_char: PROCEDURE (ch) BOOLEAN EXTERNAL ;
    DCL ch BYTE; END;
num_in: PROCEDURE (err_p) WORD EXTERNAL ;
    DCL err_p ADDRESS; END;


/*****     VIEW.PLM     *****/

DCL saved_line BYTE EXTERNAL ;
re_window: PROCEDURE EXTERNAL ; END;
save_line: PROCEDURE(s_row) EXTERNAL ;
    DCL s_row BYTE; END;
forward_char: PROCEDURE(num_chars,delete_flag) EXTERNAL ;
    DCL num_chars WORD, delete_flag BYTE; END;
forward_line: PROCEDURE(num_lines) EXTERNAL ;
    DCL num_lines WORD; END;
backup_char: PROCEDURE(num_chars,delete_flag) EXTERNAL ;
    DCL num_chars WORD, delete_flag BYTE; END;
backup_line: PROCEDURE(num_lines,start,do_move) WORD EXTERNAL ;
    DCL num_lines WORD, start WORD, do_move BYTE; END;
re_write: PROCEDURE(start) EXTERNAL ;
    DCL start WORD; END;
re_view: PROCEDURE EXTERNAL ; END;

