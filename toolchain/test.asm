.data:
.code:
    // Store value 0b11111111 at address 1.
    CLOAD 1,A
    CLOAD 255,B
    RSTORE B,A
    // Store value 0b11111111 at address 2.
    CLOAD 2,A
    CLOAD 255,B
    RSTORE B,A
    // Read value at 1 into register B.
    CLOAD 1,A
    RLOAD A,B
    // Output value in register B to location 0 on-screen.
    CLOAD 0,A
    OUT A,B
    // Exit.
    HALT
