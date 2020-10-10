.data:
    var1 = 15
.code:
    LOAD var1,A
    STORE A,[0xFF]
    LOAD [0xFF],B
    OUT B
    HALT
