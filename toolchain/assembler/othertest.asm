.data:
	x = 9
	y = 10
	z = 11
	counter = 1
	step = 1
	end = 5
.code:
	LOAD x,B
	LOAD y,C
	LOAD z,D
	LOAD counter,E
	LOAD step,F
	LOAD end,G
	loop:
		OUT B,
		OUT C,
		OUT D,
		ADD E,F
		MOV A,E
		CMP E,G
		JMPE loop,
		JMPL loop,
		JMPG end,
	end:
		HALT
