.data:
    temp_var_0 = 4
    temp_var_1 = -17
    myvarx = 0b110
    myvary = -0x67_12
    mystr = "Hello world!"
    mych = 'a'
.code:
    NOP
    LOAD temp_var_0,A
    LOAD A,B
    STORE 167,C
    STORE C,A
    STORE C,0x4
    bongle:
        ADD A,B,C
        ADD A,-0x578,A
        MULT A,B,C
        MULT A,0x92,B
        DIV A,B,C
        DIV A,0x9,A
        DIV 0x9,A,A
        CMP A,B,A
        JMP A,bongle
        INT A
