            JMPE end_delay_loop,
            JMPG start_delay_loop,
        end_delay_loop:
        LOAD delay_timer,G
		ADD B,C
        MOV C,B
		MOV A,C
		OUT C,
		ADD D,F
		MOV A,D
		CMP D,E
		JMPL begin,
		JMPE begin,
		JMPG finish,
	finish:
		HALT
