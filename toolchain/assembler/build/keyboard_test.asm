/*
Program to test the PS/2 keyboard by echoing keys to the screen.
*/

.data:
.code:
    CLOAD 0,A
    ISR A,keyboard_interrupt
    CLOAD 1920,B
    CLOAD 26,D // Scancode for Z
    CLOAD 34,E // Scancode for X
    CLOAD 90,F // ASCII for Z
    CLOAD 88,G // ASCII for X

    CMP A,A
    JMPE main_loop

    keyboard_interrupt:
        IN B,C
        CMP C,D
        JMPE scancode_z
        CMP C,E
        JMPE scancode_x
        JMPL end
        JMPG end
        scancode_z:
            CLOAD 0,A
            OUT A,F
            ENDINT
        scancode_x:
            CLOAD 0,A
            OUT A,G
            ENDINT
        end:
            ENDINT

    main_loop:
        JMPE main_loop
