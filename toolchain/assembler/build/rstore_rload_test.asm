// Program to test the RSTORE and RLOAD instructions.

.data:
    address = 157
    value = 119
.code:
    LOAD address,A  // Load the value 157 into register A.
    LOAD value,B    // Load the value 119 into register B.
    RSTORE B,A      // Store the value 119 into memory address 157.
    RLOAD A,C       // Load the value at the memory address stored in register A into register C.
    CLOAD 0,D
    OUT D,C         // Should output 119 to location 0 on-screen. This is a non-printable ASCII character, but it's fine for emulation.
    CLOAD 157,A     // Load the value 157 into register A.
    RLOAD A,A       // Load from the address stored in A (address 157) into register A.
    CLOAD 80,D
    OUT D,A         // Should output 119 to location 80 on-screen.
    CLOAD 4,A
    RSTORE A,A      // Store the value stored in A (value 4) to address 4 in RAM.
    RLOAD A,B       // Load the value at address 4 into register B.
    CLOAD 160,C
    OUT C,B         // Should output 4 to location 160 on-screen.
    HALT
