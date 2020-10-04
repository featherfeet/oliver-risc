.data:
    output_address = 0
    output_value = 0
.code:
    // Start root node.
    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0).
    CLOAD 12,A
    SUB G,A
    MOV A,G
    MOV G,F
    CLOAD 4,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 8,A
    ADD G,A
    CLOAD 10,B
    RSTORE B,A
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_prodc
    start_procedure_prodc:
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD F,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 48,D
    ADD C,D
    MOV A,C
    // End expression node.
    STORE C,output_value

    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 80,D
    ADD C,D
    MOV A,C
    // End expression node.
    STORE C,output_address

    // End variable assignment node.
    // Start procedure call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End procedure call node.
    // End begin . . . end block node.
    MOV G,B
    CLOAD 4,A
    ADD A,G
    MOV A,G
    RLOAD B,IP
    end_procedure_prodc:
    // End procedure node.
    // Start procedure call node.
    CLOAD 4,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_prodc
    // End procedure call node.
    // Start procedure call node.
    HALT
    // End procedure call node.
    // End root node.
