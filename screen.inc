
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
DCL FALSE   IS   '0';

DCL LOGICAL IS   'BYTE';
DCL BOOLEAN IS   'BYTE';
DCL WBYTE   IS   'WORD';
DCL LF      IS '10';
DCL ESC     IS '1BH';

/*****     PUB.PLM    *****/

DCL row BYTE EXTERNAL ;
DCL col BYTE EXTERNAL ;
DCL have (*) WORD EXTERNAL ;
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



/*****     CMNDS.PLM     *****/

DCL prompt_number BYTE EXTERNAL ;

/*****     LIT CONF     *****/

DCL UNKNOWN IS '0';
DCL SIV     IS '1';
DCL SIIIE   IS '3';
DCL SIIIEO  IS '4';
DCL SIIIET  IS '5';
DCL ANSI    IS '6';
DCL VT100   IS '7';
DCL col_first IS '0';
DCL up_out_code IS '0';
DCL down_out_code IS '1';
DCL left_out_code IS '2';
DCL right_out_code IS '3';
DCL home_out_code IS '4';
DCL back_out_code IS '5';
DCL erase_screen_out_code IS '6';
DCL erase_entire_screen_out_code IS '7';
DCL erase_line_out_code IS '8';
DCL erase_entire_line_out_code IS '9';
DCL reverse_scroll_out_code IS '10';
DCL goto_out_code IS '11';
DCL offset_index IS '12';
DCL delete_out_code IS '13';
DCL reverse_video_code IS '14';
DCL normal_video_code IS '15';

/*****     CONF.PLM     *****/

DCL config BYTE EXTERNAL ;
DCL wrapper BYTE EXTERNAL ;
DCL print_as(*) BYTE EXTERNAL ;
DCL first_coordinate BYTE EXTERNAL ;
DCL visible_attributes BYTE EXTERNAL ;
DCL OUTPUT_CODES (17) STRUCTURE(code(5) BYTE) EXTERNAL ;
DCL delay_times (17) WORD EXTERNAL ;


/*****     CONSOL.PLM     *****/

DCL current_message (*) BYTE EXTERNAL ;
DCL last_message (*) BYTE EXTERNAL ;
DCL current_prompt (*) BYTE EXTERNAL ;
DCL suppressed_prompt(*) BYTE EXTERNAL ;
gone_prompt: PROC EXTERNAL ; END;

/*****     IO.PLM     *****/

co_flush: PROC  EXTERNAL ; END;
print_string: PROC(string)  EXTERNAL ;
    DCL string WORD; END;

/*****     VIEW.PLM     *****/

print_text_line: PROCEDURE(line) WORD  EXTERNAL ;
    DCL line WORD; END;

/*****   AEDDUM.PLM   *****/

cocom:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
codat:PROCEDURE(ch) EXTERNAL ;             /* AEDASM */
	DECLARE ch BYTE; END;
