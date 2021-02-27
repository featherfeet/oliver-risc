.data:
.code:
    // Test divide.
    CLOAD 15,A
    CLOAD 5,B
    DIV A,B
    CLOAD 0,C
    OUT C,A
    CLOAD 1,C
    OUT C,B
    // Test multiply.
    CLOAD 3,A
    CLOAD 4,B
    MULT A,B
    CLOAD 0,C
    OUT C,A
    // Exit.
    RST
