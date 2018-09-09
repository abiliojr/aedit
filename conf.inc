
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
DCL CR      IS '13';
DCL tab     IS '09H';
DCL LF      IS '10';
DCL ESC     IS '1BH';

/* TMPMAN.PLM *** UDI *** (a trick to avoid inclusion by TMPMAN which is COMPACT)*/

DQ$GET$SYSTEM$ID: PROC(IDP,EXCEPP) EXTERNAL ;
   DCL (IDP,EXCEPP) WORD;END;
DQ$SPECIAL: PROC(TYPE,CONNP,EXCEPP) EXTERNAL ;
   DCL (TYPE,CONNP,EXCEPP) WORD;END;

/*****     LIT  PUBLIC    *****/

DCL string_len_plus_1 IS '61';

/*****     PUB.PLM    *****/

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
DCL cursor_type BYTE EXTERNAL ;

DCL input_buffer (string_len_plus_1) BYTE EXTERNAL ;

DCL tmp_str(81) BYTE EXTERNAL ;

DCL excep WORD EXTERNAL ;

DCL in_block_mode LOGICAL EXTERNAL ;

DCL batch_mode LOGICAL EXTERNAL ;
DCL submit_mode LOGICAL EXTERNAL ;


/*****     CMNDS.PLM     *****/

DCL prompt_number BYTE EXTERNAL ;

/*****     COMAND.PLM     *****/

DCL strip_parity BOOLEAN EXTERNAL ;

/*****     LIT CONF     *****/

DCL UNKNOWN IS '0';
DCL SIV     IS '1';
DCL SIII    IS '2';
DCL SIIIE   IS '3';
DCL SIIIEO  IS '4';
DCL SIIIET  IS '5';
DCL ANSI    IS '6';
DCL VT100   IS '7';
DCL IBMPC   IS '8';


DCL first_code IS '0E8H';
DCL home_code IS '0ECH';
DCL esc_code IS '0EEH';
DCL rubout_code IS '0F3H';
DCL col_first IS '0';
DCL row_first IS '1';
DCL ansi_rc IS '2';

DCL up_out_code IS '0';
DCL down_out_code IS '1';
DCL left_out_code IS '2';
DCL right_out_code IS '3';
DCL home_out_code IS '4';
DCL back_out_code IS '5';
DCL reverse_scroll_out_code IS '10';
DCL goto_out_code IS '11';
DCL delete_out_code IS '13';
DCL reverse_video_code IS '14';
DCL normal_video_code IS '15';

/*****     CONSOL.PLM     *****/

DCL current_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
early_error: PROC (msg_p) EXTERNAL ;
    DCL msg_p ADDRESS; END;

/*****     IO.PLM     *****/

print_unconditionally: PROC (string) EXTERNAL ;
    DCL string WORD; END;
co_flush: PROC  EXTERNAL ; END;
check$for$keys:PROC  EXTERNAL ; END;
set_cursor:PROC(new$val) EXTERNAL ;
    DCL new$val BYTE; END;

/*****     MACROF.PLM     *****/

DCL check$for$run$keys LOGICAL EXTERNAL ;
macro_file_error: PROCEDURE(string) EXTERNAL ;
    DCL string WORD; END;

/*****     UTIL.PLM     *****/

word_movb: PROCEDURE(source,destination,len) EXTERNAL ;
    DCL (source,destination,len) WORD; END;
move_name: PROCEDURE(fromp,top) EXTERNAL ;
    DCL (fromp,top) WORD; END;
cmp_name: PROCEDURE(fromp,top) BYTE  EXTERNAL ;
    DCL (fromp,top) WORD; END;

/*****   AEDDUM.PLM   *****/

cocom:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
codat:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
cidat:PROCEDURE BYTE EXTERNAL ; END;       /* AEDASM */
send$block:PROCEDURE(string) EXTERNAL ;    /* AEDASM */
	DECLARE string WORD; END;
enable_ioc_io:PROCEDURE EXTERNAL ; END;    /* AEDASM */
disable_ioc_io:PROCEDURE EXTERNAL ; END;   /* AEDASM */
