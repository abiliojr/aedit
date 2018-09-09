
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
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
DCL WBYTE   IS   'WORD';
DCL LVARS   IS   'REENTRANT';
DCL controlc IS '3';
DCL CR      IS '13';
DCL LF      IS '10';

/*****     LIT UDI     *****/

DCL E$FEXIST        IS '20H';
DCL e$not$supported IS '23H';

/* TMPMAN.PLM *** UDI *** (a trick to avoid inclusion by TMPMAN which is COMPACT)*/

DQ$CREATE: PROC(PATH,EXCEP$P) WORD EXTERNAL ;
   DCL (PATH,EXCEP$P) WORD;END;
DQ$ATTACH: PROC(PATH,EXCEP$P) WORD EXTERNAL ;
   DCL (PATH,EXCEP$P) WORD;END;
DQ$DETACH: PROC(CONN,EXCEP$P) EXTERNAL ;
   DCL (CONN,EXCEP$P) WORD;END;
DQ$RENAME: PROC(OLDP,NEWP,EXCEP$P) EXTERNAL ;
   DCL (OLDP,NEWP,EXCEPP) WORD;END;
DQ$OPEN: PROC(CONN,MODE,NUM$BUF,EXCEP$P) EXTERNAL ;
   DCL CONN WORD,MODE BYTE,NUM$BUF BYTE, EXCEP$P WORD;END;
DQ$CLOSE: PROC(CONN,EXCEP$P) EXTERNAL ;
   DCL (CONN,EXCEP$P) WORD;END;
DQ$READ: PROC(CONN,BUF$P,COUNT,EXCEP$P) WORD EXTERNAL ;
   DCL (CONN,COUNT,BUF$P,EXCEP$P) WORD;END;
DQ$WRITE: PROC(CONN,BUF$P,COUNT,EXCEP$P) EXTERNAL ;
   DCL (CONN,COUNT,BUF$P,EXCEP$P) WORD;END;
DQ$SEEK: PROC(CONN,SEEK$TYPE,OFFSET$HI,OFFSET$LOW,EXCEP$P) EXTERNAL ;
   DCL CONN WORD,SEEK$TYPE BYTE,OFFSET$HI WORD,OFFSET$LOW WORD,EXCEP$P WORD;END;
DCL abs$mode               IS '2';
DQ$DECODE$EXCEPTION:PROC(ECODE,EPTR,EXCEPP) EXTERNAL ;
   DCL (ECODE,EPTR,EXCEPP) WORD;END;
DQ$SPECIAL: PROC(TYPE,CONNP,EXCEPP) EXTERNAL ;
   DCL (TYPE,CONNP,EXCEPP) WORD;END;
DQ$ATTACH$FIRST: PROC(PATH,EXCEP$P) WORD EXTERNAL ;
   DCL (PATH,EXCEP$P) WORD;END;
DQ$CREATE$CRLF: PROC(PATH,EXCEP$P) WORD EXTERNAL ;
   DCL (PATH,EXCEP$P) WORD;END;

/*****     LIT  PUBLIC    *****/

DCL lose_file IS '1';
DCL lost_file IS '2';
DCL view_only IS '3';
DCL window_minimum IS '512';

DCL rvid IS '0C7H';

DCL ed_taga IS '5';
DCL ed_tagi IS '7';
DCL ed_tagw IS '8';

DCL num_tag IS '8';

DCL string_len_plus_1 IS '61';
DCL ci_file IS '0';
DCL co_file IS '1';
DCL mac_file IS '2';
DCL in_file IS '3';
DCL util_file IS '5';
DCL block_file IS '6';
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
DCL cursor WORD EXTERNAL ;
DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
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

DCL count WORD EXTERNAL ;
DCL cursor_type BYTE EXTERNAL ;

DCL cc_flag BYTE EXTERNAL ;
DCL have_control_c BYTE EXTERNAL ;
DCL quit$state BYTE EXTERNAL ;

DCL co_buffer (255) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_macro_def BYTE EXTERNAL ;
DCL in_other BYTE EXTERNAL ;
DCL w_in_other BYTE EXTERNAL ;

DCL macro_exec_level BYTE EXTERNAL ;
DCL macro_suppress BYTE EXTERNAL ;

DCL excep WORD EXTERNAL ;

DCL in_block_mode LOGICAL EXTERNAL ;

DCL batch_mode LOGICAL EXTERNAL ;
DCL submit_mode LOGICAL EXTERNAL ;

DCL files(7) STRUCTURE(name WORD,conn WORD) EXTERNAL ;
DCL file_num BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;

DCL do_type_ahead BOOLEAN EXTERNAL ;

DCL delay_after_each_char WORD EXTERNAL ;


/*****     CMNDS.PLM     *****/

DCL prompt_number BYTE EXTERNAL ;
v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

upper: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
add_str_special: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
input_yes_no_from_console: PROC(prompt,y_type,in_replace) BYTE EXTERNAL ;
    DCL prompt WORD, y_type BOOLEAN, in_replace BOOLEAN; END;

/*****     LIT CONF     *****/

DCL SIIIE   IS '3';
DCL SIIIEO  IS '4';
DCL IBMPC   IS '8';


DCL first_code IS '0E8H';
DCL esc_code IS '0EEH';
DCL reverse_video_code IS '14';
DCL normal_video_code IS '15';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL INPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;

DCL visible_attributes BYTE EXTERNAL ;
DCL character_attributes BYTE EXTERNAL ;

DCL OUTPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;

/*****     CONSOL.PLM     *****/

DCL error_status STRUCTURE (
         in_invocation   BOOLEAN,
         from_macro_file BOOLEAN,
         key_was_space   BOOLEAN) EXTERNAL ;
DCL current_message (*) BYTE EXTERNAL ;
DCL next_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
kill_message: PROC EXTERNAL ; END;
rebuild_screen: PROC EXTERNAL ; END;


/*****     SCREEN.PLM     *****/

put_reverse_video:PROCEDURE EXTERNAL ; END;
put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;
put_normal_video_end:PROCEDURE EXTERNAL ; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;
add_eof: PROCEDURE EXTERNAL ; END;
subtract_eof: PROCEDURE EXTERNAL ; END;
quit_exit: PROCEDURE (status) EXTERNAL ;
    DCL status BYTE; END;


/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
set_tagi_at_lowe: PROCEDURE EXTERNAL ; END;
jump_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;
jump_tagi: PROCEDURE EXTERNAL ; END;
clean_tags: PROCEDURE  EXTERNAL ; END;

/*****    TMPMAN.PLM    *****/

handle_aftn_full: PROCEDURE BOOLEAN EXTERNAL ; END;

read_previous_block: PROCEDURE(file_num, buf_addr,keep) LOGICAL EXTERNAL ;
    DCL file_num BYTE, buf_addr ADDRESS, keep LOGICAL; END;
write_temp: PROCEDURE(file_num, buf_addr) EXTERNAL ;
    DCL file_num BYTE, buf_addr ADDRESS; END;

/*****     UTIL.PLM     *****/

min: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
max: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
size_of_text_in_memory: PROCEDURE WORD EXTERNAL ; END;
init_str: PROCEDURE (str_p, max_len) EXTERNAL ;
    DCL str_p WORD, max_len BYTE ; END;
add_str_char: PROCEDURE (ch) EXTERNAL ;
    DCL ch BYTE; END;
add_str_str: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;

/*****     VIEW.PLM     *****/

movmem:PROCEDURE(from_word,to_word,len) EXTERNAL ;
    DCL (from_word,to_word,len) WORD; END;
re_window: PROCEDURE EXTERNAL ; END;

/*****   AEDDUM.PLM   *****/

cocom:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
codat:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
send$block:PROCEDURE(string) EXTERNAL ;    /* AEDASM */
	DECLARE string WORD; END;
port$co:PROCEDURE(ch) EXTERNAL ;           /* AEDASM */
	DECLARE ch BYTE; END;
port$ci:PROCEDURE BYTE EXTERNAL ; END;     /* AEDASM */
port$csts:PROCEDURE BYTE EXTERNAL ; END;   /* AEDASM */

