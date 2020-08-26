.data:
    // Start variable declaration node.
    myvar_1 = 7
    // End variable declaration node.
    // Start variable declaration node.
    myvar_2 = 15
    // End variable declaration node.
.code:
    // Start root node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 87,B
    ADD A,B
    LOAD myvar_1,B
    ADD A,B
    LOAD myvar_2,B
    ADD A,B
    CLOAD 19,B
    SUB A,B
    // End expression node.
    STORE A,myvar_1
    // End variable assignment node.
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD myvar_1,B
    ADD A,B
    CLOAD 3,B
    SUB A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    LOAD myvar_2,B
    ADD A,B
    // End expression node.
    CMP C,A
    JMPL label0
    // End condition node.
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 12,B
    ADD A,B
    // End expression node.
    STORE A,myvar_1
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 47,B
    ADD A,B
    CLOAD 2,B
    ADD A,B
    // End expression node.
    STORE A,myvar_2
    // End variable assignment node.
    // End begin . . . end block node.
    label0:
    // End conditional node.
    // End root node.
