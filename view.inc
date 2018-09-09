
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
DCL CR      IS '13';
DCL LF      IS '10';

/*****     LIT  PUBLIC    *****/

DCL rvid IS '0C7H';

DCL ed_tagb IS '6';
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
DCL cursor WORD EXTERNAL ;
DCL cursor_byte BASED cursor BYTE;

DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
DCL saved_from WORD EXTERNAL ;
DCL saved_bytes (*) BYTE EXTERNAL ;
DCL line_size (*) BYTE EXTERNAL ;

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


DCL count WORD EXTERNAL ;
DCL center_line BYTE EXTERNAL ;
DCL dont_stop_macro_output BYTE EXTERNAL ;
DCL in_other BYTE EXTERNAL ;
DCL w_in_other BYTE EXTERNAL ;

DCL macro_suppress BYTE EXTERNAL ;

DCL isa_text_line LOGICAL EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;


/*****     AEDPLM.PLM     *****/

position_in_text:PROC EXTERNAL ; END;
unfold:PROC(line$p,image$p) WORD EXTERNAL ;
    DCL (line$p,image$p) WORD; END;
next_line:PROC(ptr) WORD EXTERNAL ;
    DCL ptr WORD; END;
prior_line:PROC(ptr) WORD EXTERNAL ;
    DCL ptr WORD; END;


/*****     BLOCK.PLM     *****/

DCL first_at_sign_is_here BOOLEAN EXTERNAL ;


/*****     CMNDS.PLM     *****/

DCL prompt_number BYTE EXTERNAL ;
v_cmnd: PROC EXTERNAL ; END;


/*****     LIT CONF     *****/

DCL SIV     IS '1';
DCL SIIIE   IS '3';
DCL VT100   IS '7';
DCL erase_line_out_code IS '8';
DCL erase_entire_line_out_code IS '9';
DCL reverse_scroll_out_code IS '10';
DCL delete_out_code IS '13';
DCL reverse_video_code IS '14';
DCL normal_video_code IS '15';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL visible_attributes BYTE EXTERNAL ;
DCL character_attributes BYTE EXTERNAL ;

DCL OUTPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;

/*****     CONSOL.PLM     *****/

DCL current_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
print_line: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
kill_prompt_and_message: PROC EXTERNAL ; END;
print_last_prompt_and_msg: PROC (small_prompt) EXTERNAL ;
    DCL small_prompt BOOLEAN; END;

/*****     IO.PLM     *****/

co_flush: PROC  EXTERNAL ; END;
print_update: PROC(cur$column,len,string,rev_vid) EXTERNAL ;
    DCL cur$column BYTE, len BYTE, string WORD, rev_vid BOOLEAN; END;
check_window: PROC(plusplus) EXTERNAL ;
    DCL plusplus WORD; END;
can_backup_file: PROC BYTE EXTERNAL ; END;
backup_file: PROC BYTE  EXTERNAL ; END;
can_forward_file: PROC BYTE EXTERNAL ; END;
forward_file: PROC BYTE  EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

stop_macro: PROCEDURE EXTERNAL ; END;
in_macro_exec: PROCEDURE BYTE EXTERNAL ; END;

/*****     SCREEN.PLM     *****/

put_erase_line: PROCEDURE EXTERNAL ; END;
put_erase_entire_line: PROCEDURE EXTERNAL ; END;
adjust_for_column_80:PROCEDURE EXTERNAL ; END;
put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;
put_normal_video_end:PROCEDURE EXTERNAL ; END;
put_start_row: PROCEDURE(new_row) EXTERNAL ;
    DCL new_row BYTE; END;
put_delete_line: PROCEDURE(num) EXTERNAL ;
    DCL num BYTE; END;
put_scroll: PROCEDURE(num_lines) EXTERNAL ;
    DCL num_lines BYTE; END;
put_reverse_scroll: PROCEDURE EXTERNAL ; END;
put_scroll_region: PROC (first_row,last_row) EXTERNAL ;
    DCL (first_row,last_row) BYTE; END;
reset_scroll_region: PROC EXTERNAL ; END;


/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
jump_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;
clean_tags: PROCEDURE  EXTERNAL ; END;

/*****     UTIL.PLM     *****/

min: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;
max: PROC (a,b) WORD EXTERNAL ;
    DCL (a,b) WORD; END;

/*****   AEDDUM.PLM   *****/

unfold_to_screen: PROCEDURE(line) WORD EXTERNAL ;  /* IOCASM */
    DECLARE line WORD; END;

