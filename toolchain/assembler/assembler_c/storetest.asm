.data:
	value = 290
	storage = 0
.code:
	LOAD value,A
	STORE A,storage
	LOAD storage,B
	OUT B,
    HALT
