.data:
    output_address = 0
    output_value = 0
    temp0 = 0 // General-purpose temporary storage location.
    string0 = "Hello world!!!"
.code:
    // Start root node.
    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0).
    CLOAD 12,A
    SUB G,A
    MOV A,G
    MOV G,F
    CLOAD 4,A
    ADD F,A
    CLOAD [string0],B
    RSTORE B,A
    CLOAD 8,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 0,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 8,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    STORE C,output_address
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    // Start buffer read node.
    LOAD output_address,E
    CLOAD 4,A
    ADD F,A
    RLOAD A,B
    ADD B,E
    RLOAD A,D
    CLOAD 255,A
    AND A,D
    MOV A,D
    ADD C,D
    MOV A,C
    // End buffer read node.
    // End expression node.
    STORE C,output_value
    // End variable assignment node.
    // Start while loop node.
    label0:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    LOAD output_value,D
    ADD C,D
    MOV A,C
    // End expression node.
    MOV C,E
    // Start expression node.
    CLOAD 0,C
    CLOAD 0,D
    ADD C,D
    MOV A,C
    // End expression node.
    CMP E,C
    // End condition node.
    JMPE label1
    // Start begin . . . end block node.
    // Start procedure call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End procedure call node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    STORE C,output_address
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    // Start buffer read node.
    LOAD output_address,E
    CLOAD 4,A
    ADD F,A
    RLOAD A,B
    ADD B,E
    RLOAD A,D
    CLOAD 255,A
    AND A,D
    MOV A,D
    ADD C,D
    MOV A,C
    // End buffer read node.
    // End expression node.
    STORE C,output_value
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 8,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label0
    label1:
    // Start procedure call node.
    HALT
    // End procedure call node.
    // End root node.
