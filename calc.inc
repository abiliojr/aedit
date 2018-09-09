
/*****     USEFUL LITERALS     *****/

DECLARE IS LITERALLY 'LITERALLY';
DECLARE DCL IS   'DECLARE';
DCL PROC    IS   'PROCEDURE';
DCL PROCEND IS   'END';
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

DCL BOOLEAN IS   'BYTE';
DCL WBYTE   IS   'WORD';
DCL controlc IS '3';
DCL CR      IS '13';
DCL tab     IS '09H';
DCL LF      IS '10';
DCL SPACE   IS '20H';

/* TMPMAN.PLM *** UDI *** (a trick to avoid inclusion by TMPMAN which is COMPACT)*/

dq$get$time: PROCEDURE(dt$p, excep$p) EXTERNAL ;
    DCL dt$p WORD, excep$p WORD; END;

/*****     LIT  PUBLIC    *****/

DCL ed_tagb IS '6';
DCL filename_len_plus_1 IS '61';
DCL string_len IS '60';
DCL string_len_plus_1 IS '61';
DCL s_input_file IS 'oa.input_name';
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

DCL aedit_entry LABEL EXTERNAL ;


/*****     PUB.PLM    *****/

DCL oa oa_struc EXTERNAL ;
DCL ob oa_struc EXTERNAL ;

DCL delimiters (*) BYTE EXTERNAL ;
DCL cursor WORD EXTERNAL ;
DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
DCL first_text_line BYTE EXTERNAL ;
DCL message_line BYTE EXTERNAL ;
DCL command BYTE EXTERNAL ;
DCL count WORD EXTERNAL ;
DCL infinite BYTE EXTERNAL ;

DCL radix BYTE EXTERNAL ;
DCL lstfnd BYTE EXTERNAL ;
DCL tab_to (255) BYTE EXTERNAL ;
DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL in_macro_def BYTE EXTERNAL ;
DCL in_other BYTE EXTERNAL ;
DCL macro_exec_level BYTE EXTERNAL ;
DCL macro_suppress BYTE EXTERNAL ;

DCL excep WORD EXTERNAL ;

DCL left$margin BYTE EXTERNAL ;
DCL right$margin BYTE EXTERNAL ;
DCL indent$margin BYTE EXTERNAL ;

DCL null_str BYTE EXTERNAL ;

DCL force_writing BOOLEAN EXTERNAL ;


/*****     BLOCK.PLM     *****/

DCL block_buffer (*) BYTE EXTERNAL ;
DCL in_block_buffer WORD EXTERNAL ;

/*****     COMAND.PLM     *****/

cmd_ci: PROC BYTE EXTERNAL ; END;
upper: PROC(ch) BYTE EXTERNAL ;
    DCL ch BYTE; END;
add_str_special: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
input_line: PROC(prompt,prev_string)  BYTE EXTERNAL ;
    DCL prompt WORD, prev_string WORD; END;

/*****     CONSOL.PLM     *****/

print_message: PROC(line)  EXTERNAL ;
    DCL line WORD; END;
error: PROC (msg) EXTERNAL ;
    DCL msg WORD; END;
clear_message: PROC EXTERNAL ; END;
print_prompt: PROC(line) EXTERNAL ;
    DCL line WORD; END;

/*****    FIND.PLM    *****/

DCL target (*) BYTE EXTERNAL ;
DCL replacement (*) BYTE EXTERNAL ;
DCL cnt_fnd DWORD EXTERNAL ;
DCL cnt_rep DWORD EXTERNAL ;


/*****     IO.PLM     *****/

co_flush: PROC  EXTERNAL ; END;
can_backup_file: PROC BYTE EXTERNAL ; END;
can_forward_file: PROC BYTE EXTERNAL ; END;
forward_file: PROC BYTE  EXTERNAL ; END;
working: PROC EXTERNAL ; END;

/*****     MACROF.PLM     *****/

find$index:PROCEDURE(ch,ch$list$p) BYTE EXTERNAL ;
    DCL ch BYTE, ch$list$p WORD; END;
in_macro_exec: PROCEDURE BYTE EXTERNAL ; END;
DCL cnt_exe (*) DWORD EXTERNAL ;

/*****     SCREEN.PLM     *****/

put_goto: PROCEDURE(goto_col,goto_row) EXTERNAL ;
    DCL (goto_col,goto_row) BYTE; END;

/*****     START.PLM     *****/

DCL block_size WORD EXTERNAL ;

/*****     TAGS.PLM     *****/

set_tag: PROCEDURE(tagn,in_mem)  EXTERNAL ;
    DCL tagn BYTE, in_mem WORD; END;
jump_tag: PROCEDURE(tagn)  EXTERNAL ;
    DCL tagn BYTE; END;

/*****     UTIL.PLM     *****/

size_of_text_in_memory: PROCEDURE WORD EXTERNAL ; END;
word_movb: PROCEDURE(source,destination,len) EXTERNAL ;
    DCL (source,destination,len) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;
print_number: PROCEDURE(d$number,b$width,base) WORD EXTERNAL ;
    DCL d$number DWORD, (b$width, base)  BYTE; END;
init_str: PROCEDURE (str_p, max_len) EXTERNAL ;
    DCL str_p WORD, max_len BYTE ; END;
add_str_char: PROCEDURE (ch) EXTERNAL ;
    DCL ch BYTE; END;
add_str_str: PROCEDURE (str_p) EXTERNAL ;
    DCL str_p WORD; END;
add_str_num: PROCEDURE (num,base) EXTERNAL ;
    DCL num DWORD, base BYTE; END;

/*****     VIEW.PLM     *****/

backup_line: PROCEDURE(num_lines,start,do_move) WORD EXTERNAL ;
    DCL num_lines WORD, start WORD, do_move BYTE; END;
