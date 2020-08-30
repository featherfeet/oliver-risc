.data:
    output_address = 0
    output_value = 0
    // Start variable declaration node.
    PRIMES_TO_FIND = 4
    // End variable declaration node.
    // Start variable declaration node.
    primes_found = 0
    // End variable declaration node.
    // Start variable declaration node.
    number_to_check = 2
    // End variable declaration node.
    // Start variable declaration node.
    divisor = 2
    // End variable declaration node.
    // Start variable declaration node.
    remainder = 0
    // End variable declaration node.
    // Start variable declaration node.
    prime = 0
    // End variable declaration node.
.code:
    // Start root node.
    // Start while loop node.
    label0:
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD primes_found,B
    ADD A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    LOAD PRIMES_TO_FIND,B
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
    CLOAD 2,B
    ADD A,B
    // End expression node.
    STORE A,divisor
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 1,B
    ADD A,B
    // End expression node.
    STORE A,prime
    // End variable assignment node.
    // Start while loop node.
    label2:
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD divisor,B
    ADD A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    LOAD number_to_check,B
    ADD A,B
    // End expression node.
    CMP C,A
    // End condition node.
    JMPE label3
    JMPG label3
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD number_to_check,B
    ADD A,B
    // End expression node.
    STORE A,remainder
    // End variable assignment node.
    // Start while loop node.
    label4:
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD remainder,B
    ADD A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    LOAD divisor,B
    ADD A,B
    // End expression node.
    CMP C,A
    // End condition node.
    JMPL label5
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD remainder,B
    ADD A,B
    LOAD divisor,B
    SUB A,B
    // End expression node.
    STORE A,remainder
    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label4
    label5:
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD remainder,B
    ADD A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    CLOAD 0,B
    ADD A,B
    // End expression node.
    CMP C,A
    // End condition node.
    JMPL label6
    JMPG label6
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD number_to_check,B
    ADD A,B
    // End expression node.
    STORE A,divisor
    // End variable assignment node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    CLOAD 0,B
    ADD A,B
    // End expression node.
    STORE A,prime
    // End variable assignment node.
    // End begin . . . end block node.
    label6:
    // End conditional node.
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD remainder,B
    ADD A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    CLOAD 0,B
    ADD A,B
    // End expression node.
    CMP C,A
    // End condition node.
    JMPE label7
    JMPL label7
    // Start begin . . . end block node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD divisor,B
    ADD A,B
    CLOAD 1,B
    ADD A,B
    // End expression node.
    STORE A,divisor
    // End variable assignment node.
    // End begin . . . end block node.
    label7:
    // End conditional node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label2
    label3:
    // Start conditional node.
    // Start condition node.
    // Start expression node.
    CLOAD 0,A
    LOAD prime,B
    ADD A,B
    // End expression node.
    MOV A,C
    // Start expression node.
    CLOAD 0,A
    CLOAD 1,B
    ADD A,B
    // End expression node.
    CMP C,A
    // End condition node.
    JMPL label8
    JMPG label8
    // Start begin . . . end block node.
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
    LOAD number_to_check,B
    ADD A,B
    CLOAD 48,B
    ADD A,B
    // End expression node.
    STORE A,output_value
    // End variable assignment node.
    // Start function call node.
    LOAD output_address,A
    LOAD output_value,B
    OUT A,B
    // End function call node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD primes_found,B
    ADD A,B
    CLOAD 1,B
    ADD A,B
    // End expression node.
    STORE A,primes_found
    // End variable assignment node.
    // End begin . . . end block node.
    label8:
    // End conditional node.
    // Start variable assignment node.
    // Start expression node.
    CLOAD 0,A
    LOAD number_to_check,B
    ADD A,B
    CLOAD 1,B
    ADD A,B
    // End expression node.
    STORE A,number_to_check
    // End variable assignment node.
    // End begin . . . end block node.
    CMP A,A
    JMPE label0
    label1:
    // Start function call node.
    HALT
    // End function call node.
    // End root node.
