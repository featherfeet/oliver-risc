.data:
    output_address = 0
    output_value = 0
    // Start variable declaration node.
    i = 0
    // End variable declaration node.
    // Start variable declaration node.
    j = 0
    // End variable declaration node.
.code:
    // Start root node.
    // Start variable declaration node.
    CLOAD 1,A
    STORE A,i
    // End variable declaration node.
    // Start variable declaration node.
    CLOAD 0,A
    STORE A,j
    // End variable declaration node.
    // Start while loop node.
    label0:
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
    JMPE label1
    JMPG label1
    // Start begin . . . end block node.
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
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD i,B
    ADD A,B
    CLOAD 48,B
    ADD A,B
    // End expression node.
    STORE A,output_value
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 0,B
    ADD A,B
    // End expression node.
    STORE A,output_address
    // End variable assignment node.
    // Start function call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End function call node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD i,B
    ADD A,B
    LOAD i,B
    MULT A,B
    // End expression node.
    STORE A,j
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD j,B
    ADD A,B
    CLOAD 48,B
    ADD A,B
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
    // Start function call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End function call node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label0
    label1:
    // Start function call node.
    HALT
    // End function call node.
    // End root node.
