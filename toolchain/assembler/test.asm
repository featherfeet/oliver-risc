.data:
	start = 1
	step  = 1
	end   = 5
.code:
	LOAD start,B
	LOAD step,C
	LOAD end,D
	begin:
		OUT B,
		ADD B,C
		MOV A,B
		CMP B,D
		JMPL begin,
		JMPE begin,
		JMPG finish,
	finish:
		HALT
