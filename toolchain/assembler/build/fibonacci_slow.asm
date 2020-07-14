/*
This is a program that displays Fibonacci numbers on the 7-segment display slowly, with a delay between each number.
*/

// Declare variables.
.data:
	num_b = 1                // num_b and num_c are the numbers being added together again and again to calculate the Fibonacci numbers.
	num_c = 1
	iteration_num = 0        // Used to count how many iterations of the algorithm should be performed.
	iteration_step = 1       // Used to increment the iteration counter.
	max_iterations = 17      // The maximum number of iterations of the algorithm to perform. Due to the 4-digit size of the 7-segment display, you cannot go higher than this.
    delay_timer = 500000     // How many iterations of the delay loop to perform in between iterations of the Fibonacci calculation.
// Instructions.
.code:
    // Load variables into registers. Leave the A (result) register empty. Since we only have 6 variables, we can allocate one per register and not have to do lots of LOAD/STOREing after the initial LOADs.
	LOAD num_b,B /* this
    is
    a
    multiline
    comment
    */
	LOAD num_c,C
	LOAD iteration_num,D
	LOAD max_iterations,E
	LOAD iteration_step,F
    LOAD delay_timer,G
    // Main loop.
	begin:
        // Delay loop.
        start_delay_loop:
            SUB G,F                  // Subtract 1 (F) from the delay timer (G), placing the result in A.
            MOV A,G                  // Copy A to G, resulting in the delay timer (G) being decremented by 1.
            CMP G,F                  // Compare the delay timer to the number 1.
            JMPE end_delay_loop,     // If the delay timer was equal to 1, then exit the delay loop.
            JMPG start_delay_loop,   // If the delay timer was greater than 1, then go back to the start of the delay loop.
        end_delay_loop:
        // Reset the delay timer (G) back to its starting value for use in the next delay loop.
        LOAD delay_timer,G
        // Add together two terms of the Fibonacci sequence.
		ADD B,C
        // Make the second term the first term.
        MOV C,B
        // Make the sum of the two terms into the second term.
		MOV A,C
        // Output a term.
		OUT C,
        // Increment the iteration counter (D) by 1.
		ADD D,F
		MOV A,D
        // Compare the iteration counter to the maximum number of iterations allowed.
		CMP D,E
        // If the iteration counter was less than or equal to max_iterations, go back to the start of the loop.
		JMPL begin,
		JMPE begin,
        // If the iteration counter was greater than max_iterations, end the loop.
		JMPG finish,
	finish:
        // If the loop has ended, put the processor into a HALT state so that it doesn't try to load any more instructions.
		HALT
