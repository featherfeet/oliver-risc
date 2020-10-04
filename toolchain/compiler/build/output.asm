.data:
    output_address = 0
    output_value = 0
.code:
    // Start root node.
    CLOAD 4000000,G // Start stack pointer at 4 MB, grows downwards (towards address 0).
    CLOAD 44,A
    SUB G,A
    MOV A,G
    MOV G,F
    CLOAD 4,A
    ADD G,A
    CLOAD 24,B
    RSTORE B,A
    CLOAD 8,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 12,A
    ADD G,A
    CLOAD 2,B
    RSTORE B,A
    CLOAD 16,A
    ADD G,A
    CLOAD 80,B
    RSTORE B,A
    CLOAD 20,A
    ADD G,A
    CLOAD 2,B
    RSTORE B,A
    CLOAD 24,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 28,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start while loop node.
    label0:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    // End expression node.
    MOV C,E
    // Start expression node.
    CLOAD 0,C
    CLOAD 4,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    // End expression node.
    CMP E,C
    // End condition node.
    JMPE label1
    JMPG label1
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 2,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 20,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 28,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start while loop node.
    label2:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 20,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    // End expression node.
    MOV C,E
    // Start expression node.
    CLOAD 0,C
    CLOAD 12,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    // End expression node.
    CMP E,C
    // End condition node.
    JMPE label3
    JMPG label3
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 12,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 20,A
    ADD G,A
    RLOAD A,D

    DIV C,D
    MOV B,C
    // End expression node.
    CLOAD 24,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 24,A
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
    JMPL label4
    JMPG label4
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 12,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 20,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 0,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 28,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // End begin . . . end block node.
    label4:
    // End conditional node.
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 24,A
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
    JMPE label5
    JMPL label5
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 20,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 20,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // End begin . . . end block node.
    label5:
    // End conditional node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label2
    label3:
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 28,A
    ADD G,A
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
    JMPL label6
    JMPG label6
    // Start begin . . . end block node.
    CLOAD 32,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    CLOAD 36,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 12,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start while loop node.
    label7:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
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
    JMPE label8
    JMPL label8
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 10,D
    DIV C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 32,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 32,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label7
    label8:
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 12,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start while loop node.
    label9:
    // Start condition node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
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
    JMPE label10
    JMPL label10
    // Start begin . . . end block node.
    CLOAD 40,A
    ADD G,A
    CLOAD 0,B
    RSTORE B,A
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 10,D
    DIV C,D
    MOV B,C
    // End expression node.
    CLOAD 40,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 8,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 16,A
    ADD G,A
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
    CLOAD 32,A
    ADD G,A
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
    CLOAD 40,A
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
    CLOAD 32,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 1,D
    SUB C,D
    MOV A,C
    // End expression node.
    CLOAD 32,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 36,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 10,D
    DIV C,D
    MOV A,C
    // End expression node.
    CLOAD 36,A
    ADD G,A
    RSTORE C,A

    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label9
    label10:
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
    // End begin . . . end block node.
    label6:
    // End conditional node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,C
    CLOAD 12,A
    ADD G,A
    RLOAD A,D

    ADD C,D
    MOV A,C
    CLOAD 1,D
    ADD C,D
    MOV A,C
    // End expression node.
    CLOAD 12,A
    ADD G,A
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
