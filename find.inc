
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL LOOP    IS   'DO; a_begin_loop:DO WHILE';
DCL RELOOP  IS   'GOTO A_begin_loop';
DCL OUTLOOP IS   'GOTO B_end_loop';
DCL ENDLOOP IS   'END a_begin_loop;b_end_loop:END;';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
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
DCL controlc IS '3';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL ed_taga IS '5';
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
DCL low_e_byte BASED oa.low_e BYTE;
DCL cursor WORD EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
DCL saved_bytes (*) BYTE EXTERNAL ;
DCL first_text_line BYTE EXTERNAL ;
DCL last_text_line BYTE EXTERNAL ;
DCL message_line BYTE EXTERNAL ;
DCL command BYTE EXTERNAL ;
DCL last_cmd BYTE EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL infinite BYTE EXTERNAL ;

DCL find_uplow BYTE EXTERNAL ;
DCL show_find BYTE EXTERNAL ;
DCL token_find BYTE EXTERNAL ;
DCL lstfnd BYTE EXTERNAL ;
DCL cc_flag BYTE EXTERNAL ;
DCL tmp_str(81) BYTE EXTERNAL ;

DCL macro_exec_level BYTE EXTERNAL ;
DCL minus_type BYTE EXTERNAL ;

DCL null_str BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;


/*****     AEDPLM.PLM     *****/

unfold:PROC(line$p,image$p) WORD EXTERNAL ;
    DCL (line$p,image$p) WORD; END;
next_line:PROC(ptr) WORD EXTERNAL ;
    DCL ptr WORD; END;

/*****     CMNDS.PLM     *****/

set_dirty:PROC EXTERNAL ; END;
v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

add_str_special: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
input_yes_no_from_console: PROC(prompt,y_type,in_replace) BYTE EXTERNAL ;
    DCL prompt WORD, y_type BOOLEAN, in_replace BOOLEAN; END;
input_fr: PROC  BYTE EXTERNAL ; END;
hit_space: PROC BYTE EXTERNAL ; END;

/*****     CONSOL.PLM     *****/

print_line: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
print_message: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
kill_message: PROC EXTERNAL ; END;
print_prompt: PROC(line) EXTERNAL ;
    DCL line WORD; END;
rebuild_screen: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

co_flush: PROC  EXTERNAL ; END;
check$for$keys:PROC  EXTERNAL ; END;
check_window: PROC(plusplus) EXTERNAL ;
    DCL plusplus WORD; END;
backup_file: PROC BYTE  EXTERNAL ; END;
can_forward_file: PROC BYTE EXTERNAL ; END;
forward_file: PROC BYTE  EXTERNAL ; END;
have_controlc: PROC BYTE EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

stop_macro: PROCEDURE EXTERNAL ; END;
in_macro_exec: PROCEDURE BYTE EXTERNAL ; END;
DCL go_flag (*) BOOLEAN EXTERNAL ;


/*****     SCREEN.PLM     *****/

put_start_row: PROCEDURE(new_row) EXTERNAL ;
    DCL new_row BYTE; END;
put_clear_all_text: PROCEDURE EXTERNAL ; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
jump_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;
clean_tags: PROCEDURE  EXTERNAL ; END;

/*****     UTIL.PLM     *****/

move_name: PROCEDURE(fromp,top) EXTERNAL ;
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

DCL saved_line BYTE EXTERNAL ;
re_window: PROCEDURE EXTERNAL ; END;
save_line: PROCEDURE(s_row) EXTERNAL ;
    DCL s_row BYTE; END;
backup_line: PROCEDURE(num_lines,start,do_move) WORD EXTERNAL ;
    DCL num_lines WORD, start WORD, do_move BYTE; END;
re_view: PROCEDURE EXTERNAL ; END;

