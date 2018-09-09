
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

DCL rvid IS '0C7H';

DCL string_len IS '60';
DCL string_len_plus_1 IS '61';

/*****     PUB.PLM    *****/

DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
DCL line_size (*) BYTE EXTERNAL ;

DCL message_line BYTE EXTERNAL ;
DCL command BYTE EXTERNAL ;
DCL last_cmd BYTE EXTERNAL ;
DCL last_main_cmd BYTE EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL infinite BYTE EXTERNAL ;

DCL find_uplow BYTE EXTERNAL ;
DCL show_find BYTE EXTERNAL ;
DCL token_find BYTE EXTERNAL ;
DCL radix BYTE EXTERNAL ;
DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_macro_def BYTE EXTERNAL ;
DCL macro_exec_level BYTE EXTERNAL ;
DCL minus_type BYTE EXTERNAL ;

DCL hex_digits (*) BYTE EXTERNAL ;

DCL batch_mode LOGICAL EXTERNAL ;
DCL null_str BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;


/*****     CALC.PLM     *****/

get_n_var:PROC (radix, add_minus) WORD EXTERNAL ;
    DCL radix BYTE, add_minus BOOLEAN; END;
get_s_var:PROC WORD EXTERNAL ; END;

/*****     LIT CMNDS     *****/

DCL not_hex IS '99';


/*****     CMNDS.PLM     *****/

DCL last_move_command BYTE EXTERNAL ;
DCL invalid_hex (*) BYTE EXTERNAL ;
DCL ubuf (*) BYTE EXTERNAL ;
DCL ubuf_left BYTE EXTERNAL ;
DCL ubuf_used BYTE EXTERNAL ;
DCL u_is_line BYTE EXTERNAL ;

hex_value: PROC(char) BYTE EXTERNAL ;
    DCL char BYTE; END;

/*****     LIT CONF     *****/

DCL SIV     IS '1';
DCL first_code IS '0E8H';
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
DCL ignore_code IS '0F8H';
DCL last_code IS '0F8H';
DCL illegal_code IS '0FFH';


/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL INPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;

DCL character_attributes BYTE EXTERNAL ;


/*****     CONSOL.PLM     *****/

DCL current_prompt (*) BYTE EXTERNAL ;
beep: PROC EXTERNAL ; END;
print_count_message: PROC EXTERNAL ; END;
print_message: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
clear_message: PROC EXTERNAL ; END;
clear_count_message: PROC EXTERNAL ; END;
print_prompt: PROC(line) EXTERNAL ;
    DCL line WORD; END;
print_prompt_and_repos: PROC(line)  EXTERNAL ;
    DCL line WORD; END;

/*****    FIND.PLM    *****/

DCL target (*) BYTE EXTERNAL ;
DCL replacement (*) BYTE EXTERNAL ;

/*****     IO.PLM     *****/

handle_controlc: PROC EXTERNAL ; END;
co_flush: PROC  EXTERNAL ; END;
ci: PROC BYTE  EXTERNAL ; END;
have_controlc: PROC BYTE EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

add_macro_char: PROCEDURE(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
find$index:PROCEDURE(ch,ch$list$p) BYTE EXTERNAL ;
    DCL ch BYTE, ch$list$p WORD; END;
supply_macro_char: PROCEDURE BYTE EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_re_col: PROCEDURE(new_col) EXTERNAL ;
    DCL new_col BYTE; END;
put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;

/*****     UTIL.PLM     *****/

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
