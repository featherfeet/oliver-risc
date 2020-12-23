.data:
.code:
    // Set up cursor.
    CLOAD 0,C
    // Set up ISR.
    CLOAD 0,A
    CLOAD key_handler,B
    ISR A,B
    // Busy-wait loop.
    loop_start:
        CMP A,A
        JMPE loop_start
    // Key interrupt handler.
    key_handler:
        CLOAD 88,B
        OUT C,B
        CLOAD 1,A
        ADD A,C
        MOV A,C
        ENDINT
    HALT
