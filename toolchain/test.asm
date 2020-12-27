.data:
    cursor = 0
.code:
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
        LOAD cursor,C
        CLOAD 88,B
        OUT C,B
        CLOAD 1,A
        ADD A,C
        STORE A,cursor
        ENDINT
    HALT
