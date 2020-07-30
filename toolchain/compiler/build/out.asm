.data:
    // Declaring variable `myvar_1`.
    myvar_1 = 7
    // Declaring variable `myvar_2`.
    myvar_2 = 15
.code:
// Evaluate expression:
CLOAD 0,A
CLOAD 87,B
ADD A,B
LOAD myvar_1,B
ADD A,B
LOAD myvar_2,B
ADD A,B
CLOAD 19,B
SUB A,B
STORE A,myvar_1
