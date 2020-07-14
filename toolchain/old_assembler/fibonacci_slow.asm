.data:
	num_b = 1
	num_c = 1
	iteration_num = 0
	iteration_step = 1
	max_iterations = 17
    delay_timer = 500000
.code:
	LOAD num_b,B
	LOAD num_c,C
	LOAD iteration_num,D
	LOAD max_iterations,E
	LOAD iteration_step,F
    LOAD delay_timer,G
	begin:
        start_delay_loop:
            SUB G,F
            MOV A,G
            CMP G,F
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
