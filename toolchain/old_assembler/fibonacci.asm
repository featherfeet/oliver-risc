.data:
	num_b = 1
	num_c = 1
	iteration_num = 0
	iteration_step = 1
	max_iterations = 17
.code:
	LOAD num_b,B
	LOAD num_c,C
	LOAD iteration_num,D
	LOAD max_iterations,E
	LOAD iteration_step,F
	begin:
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
