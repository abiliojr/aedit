
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
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
DCL WBYTE   IS   'WORD';
DCL LVARS   IS   'REENTRANT';
DCL controlc IS '3';
DCL CR      IS '13';
DCL LF      IS '10';

/*****     LIT UDI     *****/

DCL E$FNEXIST       IS '21H';

/* TMPMAN.PLM *** UDI *** (a trick to avoid inclusion by TMPMAN which is COMPACT)*/

DQ$EXIT: PROC(EXCEP$CODE) EXTERNAL ;
   DCL EXCEP$CODE WORD;END;
DQ$ATTACH: PROC(PATH,EXCEP$P) WORD EXTERNAL ;
   DCL (PATH,EXCEP$P) WORD;END;
DQ$DETACH: PROC(CONN,EXCEP$P) EXTERNAL ;
   DCL (CONN,EXCEP$P) WORD;END;
DQ$DELETE: PROC(PATH,EXCEP$P) EXTERNAL ;
   DCL (PATH,EXCEP$P) WORD;END;
DQ$RENAME: PROC(OLDP,NEWP,EXCEP$P) EXTERNAL ;
   DCL (OLDP,NEWP,EXCEPP) WORD;END;
DQ$OPEN: PROC(CONN,MODE,NUM$BUF,EXCEP$P) EXTERNAL ;
   DCL CONN WORD,MODE BYTE,NUM$BUF BYTE, EXCEP$P WORD;END;
DQ$GET$ARGUMENT: PROC(ARGUMENT$P,EXCEP$P) BYTE EXTERNAL ;
   DCL (ARGUMENT$P,EXCEP$P) WORD;END;
DQ$SWITCH$BUFFER: PROC(BUFFER$P,EXCEP$P) WORD EXTERNAL ;
   DCL (BUFFER$P,EXCEP$P) WORD;END;
DQ$CHANGE$EXTENSION: PROC(PATH$P,EXTENSION$P,EXCEP$P) EXTERNAL ;
   DCL (PATH$P,EXTENSION$P,EXCEP$P) WORD;END;
DQ$TRAP$CC: PROC(CCPTR,EXCEPP) EXTERNAL ;
   DCL (CCPTR,EXCEPP) WORD;END;
DQ$GET$SYSTEM$ID: PROC(IDP,EXCEPP) EXTERNAL ;
   DCL (IDP,EXCEPP) WORD;END;
DQ$GET$SIZE: PROC(SEGMENT,EXCEP$P) WORD EXTERNAL ;
   DCL(SEGMENT,EXCEP$P) WORD;END;
DQ$SPECIAL: PROC(TYPE,CONNP,EXCEPP) EXTERNAL ;
   DCL (TYPE,CONNP,EXCEPP) WORD;END;
dq$allocate: PROC(size,excep$p) SELECTER EXTERNAL ;
   DCL size WORD, excep$p WORD;END;
dq$free: PROC(segment,excep$p) EXTERNAL ;
   DCL segment SELECTER,excep$p WORD;END;
dq$reserve$io$memory: PROC(num$files,num$buffs,excep$p) EXTERNAL ;
   DCL (num$files,num$buffs) WORD,excep$p WORD;END;
dq$get$connection$status: PROC (conn,info$p,excep$p) EXTERNAL ;
    DCL (conn,info$p,excep$p) WORD; END;
dq$file$info: PROC (conn, mode, info$p, excep$p) EXTERNAL ;
    DCL (conn, info$p, excep$p) WORD, mode BYTE; END;
dq$change$access: PROC (path$p,class,access,excep$p) EXTERNAL ;
    DCL path$p address, class BYTE, access BYTE, excep$p ADDRESS; END;
dq$trap$exception: PROC (ptr_p, excep$p) EXTERNAL ;
    DCL (ptr_p, excep$p) ADDRESS; END;

DQ$SET$DELIMITERS: PROC(DELIMITER$P,EXCEP$P) EXTERNAL ;
   DCL(DELIMITER$P,EXCEP$P) WORD; END;

/*****     LIT  PUBLIC    *****/

DCL keep_file IS '0';
DCL lose_file IS '1';
DCL lost_file IS '2';
DCL view_only IS '3';
DCL view_only_wk1 IS '4';
DCL view_only_wk2 IS '5';

DCL window_minimum IS '512';

DCL rvid IS '0C7H';

DCL ed_tagi IS '7';
DCL ed_tagw IS '8';

DCL num_tag IS '8';

DCL string_len IS '60';
DCL string_len_plus_1 IS '61';
DCL rmx_string  IS  '16';

DCL s_input_file IS 'oa.input_name';
DCL s_output_file IS 'oa.output_name';

DCL mac_file IS '2';
DCL in_file IS '3';
DCL out_file IS '4';
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


/*****     VERV.PLM    *****/

DCL copy$right (*) BYTE EXTERNAL ;
DCL title (*) BYTE EXTERNAL ;
DCL version (*) BYTE EXTERNAL ;


/*****     PUB.PLM    *****/

DCL oa oa_struc EXTERNAL ;
DCL ob oa_struc EXTERNAL ;

DCL w_dirty BYTE EXTERNAL ;
DCL low_s_byte BASED oa.low_s BYTE;
DCL high_e_byte BASED oa.high_e BYTE;
DCL cursor WORD EXTERNAL ;
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

DCL command BYTE EXTERNAL ;
DCL backup_files BYTE EXTERNAL ;
DCL center_line BYTE EXTERNAL ;
DCL quit$state BYTE EXTERNAL ;

DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_other BYTE EXTERNAL ;
DCL w_in_other BYTE EXTERNAL ;

DCL macro_suppress BYTE EXTERNAL ;

DCL excep WORD EXTERNAL ;

DCL batch_mode LOGICAL EXTERNAL ;
DCL files(7) STRUCTURE(name WORD,conn WORD) EXTERNAL ;
DCL input_conn WORD EXTERNAL ;
DCL file_num BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;

DCL do_type_ahead BOOLEAN EXTERNAL ;

DCL invalid_null_name (*) BYTE EXTERNAL ;


/*****     CCTRAP.PLM     *****/

cc_trap:PROC EXTERNAL ; END;
DCL excep_handler_p POINTER EXTERNAL ; /* the type doesn't matter, only the address is taken */


/*****     CALC.PLM     *****/

DCL s_write_file (*) BYTE EXTERNAL ;
DCL s_macro_file (*) BYTE EXTERNAL ;

/*****     CMNDS.PLM     *****/

set_dirty:PROC EXTERNAL ; END;
DCL prompt_number BYTE EXTERNAL ;
v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

upper: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
add_str_special: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
input_filename: PROC (prompt,prev_string)  BYTE EXTERNAL ;
    DCL prompt WORD, prev_string WORD; END;
input_yes_no_from_console: PROC(prompt,y_type,in_replace) BYTE EXTERNAL ;
    DCL prompt WORD, y_type BOOLEAN, in_replace BOOLEAN; END;
input_command: PROC(prompt) BYTE  EXTERNAL ;
    DCL prompt WORD; END;

/*****     LIT CONF     *****/

DCL SIV     IS '1';
DCL esc_code IS '0EEH';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL visible_attributes BYTE EXTERNAL ;
DCL character_attributes BYTE EXTERNAL ;

setup_terminal: PROC EXTERNAL ; END;
check_minimal_codes_set: PROC EXTERNAL ; END;
restore_system_config: PROC EXTERNAL ; END;
close_ioc: PROC EXTERNAL ; END;


/*****     CONSOL.PLM     *****/

DCL error_status STRUCTURE (
         in_invocation   BOOLEAN,
         from_macro_file BOOLEAN,
         key_was_space   BOOLEAN) EXTERNAL ;
DCL current_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
print_message: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
early_error: PROC (msg_p) EXTERNAL ;
    DCL msg_p ADDRESS; END;
illegal_command: PROC EXTERNAL ; END;
kill_message: PROC EXTERNAL ; END;
print_prompt: PROC(line) EXTERNAL ;
    DCL line WORD; END;
rebuild_screen: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

DCL input_expected_flag BOOLEAN EXTERNAL ;
co_flush: PROC  EXTERNAL ; END;
echeck: PROC  EXTERNAL ; END;
openi: PROC(fnum,nbuf)  EXTERNAL ;
    DCL (fnum,nbuf) BYTE; END;
test_file_existence:PROC(fnum) BYTE EXTERNAL ;
    DCL fnum BYTE; END;
openo: PROC(fnum,mode,nbuf)  EXTERNAL ;
    DCL (fnum,mode,nbuf) BYTE; END;
open_cico: PROC EXTERNAL ; END;
detach: PROC(fnum) EXTERNAL ;
    DCL fnum BYTE; END;
detach_input: PROC EXTERNAL ; END;
read: PROC(fnum) WORD  EXTERNAL ;
    DCL fnum BYTE; END;
check_window: PROC(plusplus) EXTERNAL ;
    DCL plusplus WORD; END;
forward_file: PROC BYTE  EXTERNAL ; END;
write: PROC(nfile,buf,len) EXTERNAL ;
    DCL nfile BYTE, (buf,len) WORD; END;
working: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

DCL macro_buf_size WORD EXTERNAL ;
macro_file_process: PROCEDURE  EXTERNAL ; END;
exec_init_macro:PROCEDURE EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_erase_entire_line: PROCEDURE EXTERNAL ; END;
put_normal_video:PROCEDURE EXTERNAL ; END;
put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;
put_start_row: PROCEDURE(new_row) EXTERNAL ;
    DCL new_row BYTE; END;
put_clear_all: PROCEDURE EXTERNAL ; END;
put_scroll_region: PROC (first_row,last_row) EXTERNAL ;
    DCL (first_row,last_row) BYTE; END;
reset_scroll_region: PROC EXTERNAL ; END;


/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
jump_tagi: PROCEDURE EXTERNAL ; END;

/*****    TMPMAN.PLM    *****/

tmpman_init: PROC EXTERNAL ; END;
  /* initializes pointers for the 286 */

reinit_temp: PROCEDURE(file_num) EXTERNAL ;
    DCL file_num BYTE; END;
set_temp_viewonly: PROCEDURE(file_num,mode,conn) EXTERNAL ;
    DCL file_num BYTE, mode BYTE, conn WORD; END;
read_temp: PROCEDURE(file_num, buf_addr) EXTERNAL ;
    DCL file_num BYTE, buf_addr ADDRESS; END;
read_previous_block: PROCEDURE(file_num, buf_addr,keep) LOGICAL EXTERNAL ;
    DCL file_num BYTE, buf_addr ADDRESS, keep LOGICAL; END;
skip_to_end: PROCEDURE(file_num) EXTERNAL ;
    DCL file_num BYTE; END;
rewind_temp: PROCEDURE(file_num) EXTERNAL ;
    DCL file_num BYTE; END;
restore_temp_state: PROCEDURE (file_num) EXTERNAL ;
    DCL file_num BYTE; END;

/*****     UTIL.PLM     *****/

min: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
max: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;
cmp_name: PROCEDURE(fromp,top) BYTE  EXTERNAL ;
    DCL (fromp,top) WORD; END;
init_str: PROCEDURE (str_p, max_len) EXTERNAL ;
    DCL str_p WORD, max_len BYTE ; END;
reuse_str: PROCEDURE (str_p, max_len) EXTERNAL ;
    DCL str_p WORD, max_len BYTE ; END;
add_str_char: PROCEDURE (ch) EXTERNAL ;
    DCL ch BYTE; END;
add_str_str: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;

/*****     VIEW.PLM     *****/

movmem:PROCEDURE(from_word,to_word,len) EXTERNAL ;
    DCL (from_word,to_word,len) WORD; END;
re_window: PROCEDURE EXTERNAL ; END;
re_view: PROCEDURE EXTERNAL ; END;


/*****   LIT AEDDUM   *****/

DCL memory_leng IS '48000';


/*****   XNXSYS.PLM   *****/

getenv: PROC (symbol_p) ADDRESS EXTERNAL ;
    DCL symbol_p ADDRESS; END;
ignore_quit_signal: PROC EXTERNAL ; END;
