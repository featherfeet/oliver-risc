.data:
    output_address = 0
    output_value = 0
    // Start variable declaration node.
    x = 0
    // End variable declaration node.
    // Start variable declaration node.
    seven = 0
    // End variable declaration node.
.code:
    // Start root node.
    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0).
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_print_variable_x
    start_procedure_print_variable_x:
    // Start begin . . . end block node.
    // Start variable declaration node.
    CLOAD 5,A
    STORE A,x
    // End variable declaration node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 0,B
    ADD A,B
    // End expression node.
    STORE A,output_address
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD x,B
    ADD A,B
    CLOAD 48,B
    ADD A,B
    // End expression node.
    STORE A,output_value
    // End variable assignment node.
    // Start procedure call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End procedure call node.
    // End begin . . . end block node.
    MOV G,B
    CLOAD 2,A
    ADD A,G
    MOV A,G
    RLOAD B,IP
    end_procedure_print_variable_x:
    // End procedure node.
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_square_seven
    start_procedure_square_seven:
    // Start begin . . . end block node.
    // Start variable declaration node.
    CLOAD 7,A
    STORE A,seven
    // End variable declaration node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD seven,B
    ADD A,B
    LOAD seven,B
    MULT A,B
    // End expression node.
    STORE A,output_value
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 80,B
    ADD A,B
    // End expression node.
    STORE A,output_address
    // End variable assignment node.
    // Start procedure call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End procedure call node.
    // Start procedure call node.
    CLOAD 2,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_print_variable_x
    // End procedure call node.
    // End begin . . . end block node.
    MOV G,B
    CLOAD 2,A
    ADD A,G
    MOV A,G
    RLOAD B,IP
    end_procedure_square_seven:
    // End procedure node.
    // Start procedure call node.
    CLOAD 2,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_print_variable_x
    // End procedure call node.
    // Start procedure call node.
    CLOAD 2,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_square_seven
    // End procedure call node.
    // Start procedure call node.
    HALT
    // End procedure call node.
    // End root node.
