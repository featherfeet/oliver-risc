.data:
    i = 0
.code:
    LOAD i,A
    CLOAD 1,B
    ADD A,B
    STORE A,i
    LOAD i,C
    CLOAD 0,A
    OUT A,C
    HALT
