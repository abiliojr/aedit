
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
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

/* TMPMAN.PLM *** UDI *** (a trick to avoid inclusion by TMPMAN which is COMPACT)*/

DQ$TRAP$CC: PROC(CCPTR,EXCEPP) EXTERNAL ;
   DCL (CCPTR,EXCEPP) WORD;END;
DQ$SPECIAL: PROC(TYPE,CONNP,EXCEPP) EXTERNAL ;
   DCL (TYPE,CONNP,EXCEPP) WORD;END;

/*****     LIT  PUBLIC    *****/

DCL view_only IS '3';
DCL rvid IS '0C7H';

DCL string_len_plus_1 IS '61';
DCL string_len_plus_2 IS '62';

DCL ci_file IS '0';
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
DCL cc_flag BYTE EXTERNAL ;
DCL quit$state BYTE EXTERNAL ;

DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL excep WORD EXTERNAL ;

DCL files(7) STRUCTURE(name WORD,conn WORD) EXTERNAL ;
DCL force_writing BOOLEAN EXTERNAL ;


/*****     CCTRAP.PLM     *****/

cc_trap:PROC EXTERNAL ; END;

/*****     BLOCK.PLM     *****/

b_cmnd: PROC  EXTERNAL ; END;
g_cmnd: PROC  EXTERNAL ; END;

/*****     CALC.PLM     *****/

c_cmnd:PROC EXTERNAL ; END;

/*****     CMNDS.PLM     *****/

dispatched: PROC(command,table_p) BYTE EXTERNAL ;
    DCL command BYTE, table_p WORD; END;
cr_cmnd: PROC EXTERNAL ; END;
DCL prompt_number BYTE EXTERNAL ;
tab_cmnd: PROC EXTERNAL ; END;
delete_cmnd: PROC EXTERNAL ; END;
delete_line_cmnd: PROC EXTERNAL ; END;
delete_left_cmnd: PROC EXTERNAL ; END;
delete_right_cmnd: PROC EXTERNAL ; END;
move_cmnd: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
rubout_cmnd: PROC EXTERNAL ; END;
undo_cmnd: PROC EXTERNAL ; END;
h_cmnd: PROC  EXTERNAL ; END;
i_cmnd: PROC  EXTERNAL ; END;
j_cmnd: PROC  EXTERNAL ; END;
t_cmnd: PROC  EXTERNAL ; END;
x_cmnd: PROC EXTERNAL ; END;
v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

input_line: PROC(prompt,prev_string)  BYTE EXTERNAL ;
    DCL prompt WORD, prev_string WORD; END;
input_command: PROC(prompt) BYTE  EXTERNAL ;
    DCL prompt WORD; END;
hit_space: PROC BYTE EXTERNAL ; END;

/*****     LIT CONF     *****/

DCL delete_code IS '0EDH';
DCL esc_code IS '0EEH';
DCL delete_line_code IS '0EFH';
DCL delete_left_code IS '0F0H';
DCL delete_right_code IS '0F1H';
DCL undo_code IS '0F2H';
DCL rubout_code IS '0F3H';
DCL macro_exec_code IS '0F4H';

/*****     CONF.PLM     *****/

DCL dos_system BOOLEAN EXTERNAL ;

/*****     CONSOL.PLM     *****/

DCL current_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
illegal_command: PROC EXTERNAL ; END;
init_prompt_and_message:PROC EXTERNAL ; END;
print_last_prompt_and_msg: PROC (small_prompt) EXTERNAL ;
    DCL small_prompt BOOLEAN; END;

/*****    FIND.PLM    *****/

fr_cmnd: PROC  EXTERNAL ; END;


/*****     IO.PLM     *****/

DCL input_expected_flag BOOLEAN EXTERNAL ;
set_input_expected: PROC (ch) EXTERNAL ;
    DCL ch BYTE; END;
co_flush: PROC  EXTERNAL ; END;
echeck: PROC  EXTERNAL ; END;
have_controlc: PROC BYTE EXTERNAL ; END;
DCL poll_mode BOOLEAN EXTERNAL ;


/*****     MACROF.PLM     *****/

find$index:PROCEDURE(ch,ch$list$p) BYTE EXTERNAL ;
    DCL ch BYTE, ch$list$p WORD; END;
single_char_macro:PROCEDURE(ch) LOGICAL EXTERNAL ;
    DCL ch BYTE; END;
handle_macro_exec_code: PROC EXTERNAL ; END;
e_cmnd: PROCEDURE EXTERNAL ; END;
m_cmnd: PROCEDURE EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_home: PROCEDURE EXTERNAL ; END;
put_erase_entire_screen: PROCEDURE EXTERNAL ; END;
put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;
put_clear_all_text: PROCEDURE EXTERNAL ; END;
put_scroll_region: PROC (first_row,last_row) EXTERNAL ;
    DCL (first_row,last_row) BYTE; END;
reset_scroll_region: PROC EXTERNAL ; END;


/*****     SETCMD.PLM     *****/

s_cmnd: PROCEDURE  EXTERNAL ; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;
print_banner: PROCEDURE EXTERNAL ; END;
alter_init: PROCEDURE EXTERNAL ; END;
o_cmnd: PROCEDURE  EXTERNAL ; END;
q_cmnd: PROCEDURE  EXTERNAL ; END;

/*****     UTIL.PLM     *****/

max: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;

/*****     VIEW.PLM     *****/

re_view: PROCEDURE EXTERNAL ; END;


/*****     WORDS.PLM     *****/

p_cmnd:PROCEDURE  EXTERNAL ; END;
w_cmnd:PROCEDURE EXTERNAL ; END;
k_cmnd:PROCEDURE EXTERNAL ; END;


/*****   XNXSYS.PLM   *****/

ignore_quit_signal: PROC EXTERNAL ; END;
restore_quit_signal: PROC EXTERNAL ; END;

