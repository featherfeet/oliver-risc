// Program to test the RSTORE and RLOAD instructions.

.data:
    address = 57
    value = 19
.code:
    LOAD address,A  // Load the value 57 into register A.
    LOAD value,B    // Load the value 19 into register B.
    RSTORE B,A      // Store the value 19 into memory address 57.
    RLOAD A,C       // Load the value at the memory address stored in register A into register C.
    OUT C           // Should output 19.
