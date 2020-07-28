/*
Program to test interrupts by slowly counting 1 to 5.
*/

.data:
    counter = 1
    increment = 1
    max_count = 5
    delay_timer = 500000
    //delay_timer = 10
.code:
    // Load the counter and other variables.
    LOAD counter,B
    LOAD increment,C
    LOAD max_count,D
    // Set up the interrupt routine 1.
    ISR B,delay_routine
    // Main loop.
    counter_loop:
        // Output the counter.
        OUT B
        // Increment the counter (B).
        ADD B,C
        MOV A,B
        // Call the delay routine (interrupt routine 1).
        INT C
        // Check if counter has maxed out.
        CMP B,D
        // If the counter has maxed out, exit.
        JMPG finish
        // If the counter hasn't maxed out, keep looping.
        JMPL counter_loop
        JMPE counter_loop
    // Interrupt routine used to delay.
    delay_routine:
        // Setup for delay loop.
        LOAD delay_timer,E
        // Delay loop.
        delay_loop:
            // Decrement the delay timer (E).
            SUB E,C
            MOV A,E
            // Check if the delay timer is equal to 1.
            CMP E,C
            // If the delay timer is equal to 1, exit the delay loop.
            JMPE exit_delay_loop
            // If it wasn't, keep looping.
            JMPG delay_loop
        exit_delay_loop:
            ENDINT
    // Stops the program when jumped to.
    finish:
        HALT
