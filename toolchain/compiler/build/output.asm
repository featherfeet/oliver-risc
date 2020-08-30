.data:
    // Start variable declaration node.
    i = 0
    // End variable declaration node.
.code:
    // Start root node.
    // Start while loop node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD i,B
    ADD A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    CLOAD 5,B
    ADD A,B
    // End expression node.
    CMP C,A
    // End condition node.
    label0:
    JMPG label1
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD i,B
    ADD A,B
    CLOAD 49,B
    ADD A,B
    // End expression node.
    MOV A,B
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 0,B
    ADD A,B
    // End expression node.
    // End variable assignment node.
    // Start function call node.
    OUT A,B
    // End function call node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD i,B
    ADD A,B
    CLOAD 1,B
    ADD A,B
    // End expression node.
    STORE A,i
    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label0
    label1:
    // End root node.
