.data:
    output_address = 0
    output_value = 0
    temp0 = 0 // General-purpose temporary storage location.
.code:
    // Start root node.
    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0).
    CLOAD 40,A
    SUB G,A
    MOV A,G
    MOV G,F
    CLOAD 4,A
    ADD F,A
    CLOAD 240,B
    RSTORE B,A
    CLOAD 8,A
    ADD F,A
    CLOAD 67,B
    RSTORE B,A
    CLOAD 12,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 16,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_get_integer_length
    start_procedure_get_integer_length:
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 0,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 16,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    CLOAD 4,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 12,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // Start while loop node.
    label0:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
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
    JMPL label1
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 10,D
    DIV C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 16,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 16,A
    ADD F,A
    RSTORE C,A
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
    end_procedure_get_integer_length:
    // End procedure node.
    CLOAD 20,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 24,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_print_integer
    start_procedure_print_integer:
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 20,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 12,A
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
    JMPE start_procedure_get_integer_length
    // End procedure call node.
    CLOAD 4,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 20,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // Start while loop node.
    label2:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
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
    JMPE label3
    JMPL label3
    // Start begin . . . end block node.
    CLOAD 8,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 10,D
    DIV C,D
    MOV B,C
    // End expression node.
    CLOAD 8,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 24,A
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
    STORE C,output_address
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    LOAD output_address,D
    ADD C,D
    MOV A,C
    CLOAD 16,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    SUB C,D
    MOV A,C
    // End expression node.
    STORE C,output_address
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD G,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 48,D
    ADD C,D
    MOV A,C
    // End expression node.
    STORE C,output_value
    // End variable assignment node.
    // Start procedure call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End procedure call node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 16,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    SUB C,D
    MOV A,C
    // End expression node.
    CLOAD 16,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 10,D
    DIV C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label2
    label3:
    // End begin . . . end block node.
    MOV G,B
    CLOAD 12,A
    ADD A,G
    MOV A,G
    RLOAD B,IP
    end_procedure_print_integer:
    // End procedure node.
    CLOAD 28,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 32,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_is_prime
    start_procedure_is_prime:
    // Start begin . . . end block node.
    CLOAD 4,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
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
    CLOAD 2,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // Start while loop node.
    label4:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    MOV C,E
    // Start expression node.
    CLOAD 0,C
    CLOAD 28,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CMP E,C
    // End condition node.
    JMPE label5
    JMPG label5
    // Start begin . . . end block node.
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 28,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
    DIV C,D
    MOV B,C
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
    JMPL label6
    JMPG label6
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 0,D
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
    CLOAD 28,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // End begin . . . end block node.
    label6:
    // End conditional node.
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
    // End begin . . . end block node.
    CMP A,A
    JMPE label4
    label5:
    // End begin . . . end block node.
    MOV G,B
    CLOAD 8,A
    ADD A,G
    MOV A,G
    RLOAD B,IP
    end_procedure_is_prime:
    // End procedure node.
    CLOAD 36,A
    ADD F,A
    CLOAD 0,B
    RSTORE B,A
    // Start procedure node.
    CMP A,A
    JMPE end_procedure_primes
    start_procedure_primes:
    // Start begin . . . end block node.
    CLOAD 4,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 2,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 28,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start while loop node.
    label7:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D
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
    JMPL label8
    JMPG label8
    // Start begin . . . end block node.
    // Start procedure call node.
    CLOAD 8,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_is_prime
    // End procedure call node.
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 32,A
    ADD F,A
    RLOAD A,D
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
    JMPL label9
    JMPG label9
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 28,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 20,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 24,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start procedure call node.
    CLOAD 12,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_print_integer
    // End procedure call node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    MOV C,E
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    // End expression node.
    CMP E,C
    // End condition node.
    JMPL label10
    JMPG label10
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 4,A
    ADD G,A
    RSTORE C,A
    // End variable assignment node.
    // End begin . . . end block node.
    label10:
    // End conditional node.
    // End begin . . . end block node.
    label9:
    // End conditional node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 28,A
    ADD F,A
    RLOAD A,D
    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 28,A
    ADD F,A
    RSTORE C,A
    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label7
    label8:
    // End begin . . . end block node.
    MOV G,B
    CLOAD 8,A
    ADD A,G
    MOV A,G
    RLOAD B,IP
    end_procedure_primes:
    // End procedure node.
    // Start procedure call node.
    CLOAD 8,A
    SUB G,A
    MOV A,G
    CLOAD 18,A
    ADD IP,A
    RSTORE A,G
    CMP A,A
    JMPE start_procedure_primes
    // End procedure call node.
    // Start procedure call node.
    HALT
    // End procedure call node.
    // End root node.
