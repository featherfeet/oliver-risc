.data:
    output_address = 0
    output_value = 0
    string0 = "Hello World!"
.code:
    // Start root node.
    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0).
    CLOAD 12,A
    SUB G,A
    MOV A,G
    MOV G,F
    CLOAD 4,A
    ADD G,A
    CLOAD [string0],B
    RSTORE B,A
    CLOAD 8,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 8,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start procedure call node.
    HALT
    // End procedure call node.
    // End root node.
