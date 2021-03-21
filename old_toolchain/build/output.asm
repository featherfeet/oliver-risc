.data:
    output_address = 0
    output_value = 0
    temp0 = 0 // General-purpose temporary storage location.
    string0 = "ORISC> "
    string1 = "_"
    string2 = "                                   "
    string3 = " "
.code:
    // Start root node.
    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0).
    CLOAD 40,A
    SUB G,A
    MOV A,G
    MOV G,F
    CLOAD 4,A
    ADD F,A
    CLOAD 67,B
    RSTORE B,A
    CLOAD 8,A
    ADD F,A
    CLOAD 240,B
    RSTORE B,A
    CLOAD 12,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 4,A
    ADD F,A
    RLOAD A,D
    MULT C,D
    MOV A,C
    // End expression node.
    CLOAD 12,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    CLOAD 16,A
    ADD F,A
    CLOAD [string0],B
    RSTORE B,A
    CLOAD 20,A
    ADD F,A
    CLOAD [string1],B
    RSTORE B,A
    CLOAD 24,A
    ADD F,A
    CLOAD [string2],B
    RSTORE B,A
    CLOAD 28,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 32,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 36,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_print
    start_procedure_print:
    // Start begin . . . end block node.
    CLOAD 4,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 28,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 8,A
    ADD F,A
    RLOAD A,D
    MULT C,D
    MOV A,C
    CLOAD 32,A
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
    CLOAD 0,E
    CLOAD 36,A
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
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 32,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 32,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    LOAD output_address,D
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
    CLOAD 4,A
    ADD G,A
    RLOAD A,E
    CLOAD 36,A
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
    // End begin . . . end block node.
    CMP A,A
    JMPE label0
    label1:
    // End begin . . . end block node.
    MOV G,B
    CLOAD 8,A
    ADD A,G
    MOV A,G
    RLOAD B,IP
    end_procedure_print:
    // End procedure node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 16,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start procedure call node.
    CLOAD 8,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_print
    // End procedure call node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 20,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start procedure call node.
    CLOAD 8,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_print
    // End procedure call node.
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_key_pressed
    start_procedure_key_pressed:
    // Start begin . . . end block node.
    // Start inline assembly node.
    CLOAD 16080,B
    // End inline assembly node.
    // Start inline assembly node.
    IN B,C
    // End inline assembly node.
    // Start inline assembly node.
    STORE C,output_value
    // End inline assembly node.
    CLOAD 4,A
    ADD G,A
    CLOAD [string3],B
    RSTORE B,A
    // Start buffer write node.
    // Start expression node.
    CLOAD 0,C
    LOAD output_value,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 0,E
    MOV C,D
    CLOAD 4,A
    ADD G,A
    RLOAD A,B
    ADD B,E
    MOV A,E
    RLOAD E,A
    CLOAD 4294967040,B
    AND A,B
    OR A,D
    RSTORE A,E
    // End buffer write node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start procedure call node.
    CLOAD 8,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_print
    // End procedure call node.
    // End begin . . . end block node.
    ENDINT
    end_procedure_key_pressed:
    // End procedure node.
    // Start inline assembly node.
    CLOAD 0,A
    // End inline assembly node.
    // Start inline assembly node.
    CLOAD start_procedure_key_pressed,B
    // End inline assembly node.
    // Start inline assembly node.
    ISR A,B
    // End inline assembly node.
    // Start while loop node.
    label2:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    MOV C,E
    // Start expression node.
    CLOAD 0,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CMP E,C
    // End condition node.
    JMPL label3
    JMPG label3
    // Start begin . . . end block node.
    // Start inline assembly node.
    NOP
    // End inline assembly node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label2
    label3:
    // Start procedure call node.
    HALT
    // End procedure call node.
    // End root node.
