
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL PROC    IS   'PROCEDURE';
DCL ENDPROC IS   'END';
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

/* TMPMAN.PLM *** UDI *** (a trick to avoid inclusion by TMPMAN which is COMPACT)*/

DQ$EXIT: PROC(EXCEP$CODE) EXTERNAL ;
   DCL EXCEP$CODE WORD;END;

/*****     LIT  PUBLIC    *****/

DCL lose_file IS '1';
DCL lost_file IS '2';
DCL view_only IS '3';
DCL lower_window IS '1';

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
DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
DCL line_size (*) BYTE EXTERNAL ;

DCL first_text_line BYTE EXTERNAL ;
DCL last_text_line BYTE EXTERNAL ;
DCL message_line BYTE EXTERNAL ;
DCL prompt_line BYTE EXTERNAL ;

DCL window_present BYTE EXTERNAL ;
DCL window_num BYTE EXTERNAL ;


DCL last_cmd BYTE EXTERNAL ;
DCL highbit_flag BOOLEAN EXTERNAL ;

DCL co_buffer (255) BYTE EXTERNAL ;

DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_macro_def BYTE EXTERNAL ;
DCL in_other BYTE EXTERNAL ;
DCL macro_exec_level BYTE EXTERNAL ;
DCL macro_suppress BYTE EXTERNAL ;

DCL isa_text_line LOGICAL EXTERNAL ;

DCL in_block_mode LOGICAL EXTERNAL ;

DCL batch_mode LOGICAL EXTERNAL ;
DCL force_writing BOOLEAN EXTERNAL ;


/*****     CMNDS.PLM     *****/

v_cmnd: PROC EXTERNAL ; END;


/*****     COMAND.PLM     *****/

DCL in_input_line BOOLEAN EXTERNAL ;
print_input_line: PROC EXTERNAL ; END;
not_cursor_movement: PROC (cmd) BYTE EXTERNAL ;
    DCL cmd BYTE; END;
hit_space: PROC BYTE EXTERNAL ; END;

/*****     LIT CONF     *****/

DCL SIV     IS '1';
DCL SIIIE   IS '3';
DCL VT100   IS '7';
DCL erase_screen_out_code IS '6';
DCL erase_line_out_code IS '8';
DCL erase_entire_line_out_code IS '9';
DCL goto_out_code IS '11';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL wrapper BYTE EXTERNAL ;
DCL print_as(*) BYTE EXTERNAL ;
DCL OUTPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;
close_ioc: PROC EXTERNAL ; END;


/*****     IO.PLM     *****/

print_unconditionally: PROC (string) EXTERNAL ;
    DCL string WORD; END;
print_unconditionally_crlf: PROC EXTERNAL ; END;
co_flush: PROC  EXTERNAL ; END;
print_string: PROC(string)  EXTERNAL ;
    DCL string WORD; END;
check$for$keys:PROC  EXTERNAL ; END;
ci: PROC BYTE  EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_home: PROCEDURE EXTERNAL ; END;
put_left: PROCEDURE EXTERNAL ; END;
put_erase_screen: PROCEDURE EXTERNAL ; END;
put_erase_line: PROCEDURE EXTERNAL ; END;
put_erase_entire_line: PROCEDURE EXTERNAL ; END;
adjust_for_column_80:PROCEDURE EXTERNAL ; END;
put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;
put_start_row: PROCEDURE(new_row) EXTERNAL ;
    DCL new_row BYTE; END;
put_clear_all: PROCEDURE EXTERNAL ; END;
put_clear_all_text: PROCEDURE EXTERNAL ; END;
put_scroll_region: PROC (first_row,last_row) EXTERNAL ;
    DCL (first_row,last_row) BYTE; END;
reset_scroll_region: PROC EXTERNAL ; END;


/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;
build_banner: PROCEDURE EXTERNAL ; END;

/*****     UTIL.PLM     *****/

word_movb: PROCEDURE(source,destination,len) EXTERNAL ;
    DCL (source,destination,len) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;

/*****     VIEW.PLM     *****/

rebuild: PROCEDURE (r_row,newp,oldp) EXTERNAL ;
    DCL r_row BYTE, (newp,oldp) WORD; END;
re_view: PROCEDURE EXTERNAL ; END;


/*****     WORDS.PLM     *****/

w_cmnd:PROCEDURE EXTERNAL ; END;

/*****   AEDDUM.PLM   *****/

cocom:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
codat:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
send$block:PROCEDURE(string) EXTERNAL ;    /* AEDASM */
	DECLARE string WORD; END;
