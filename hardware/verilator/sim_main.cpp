#include <verilated.h>          // Defines common routines
#include <iostream>             // Need std::cout
#include "Vtest.h"               // From Verilating "test.v"

Vtest *test;                      // Instantiation of module

vluint64_t main_time = 0;       // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  This is in units of the timeprecision
// used in Verilog (or from --timescale-override)

double sc_time_stamp () {       // Called by $time in Verilog
	return main_time;           // converts to double, to match
								// what SystemC does
}

int main(int argc, char** argv) {
	Verilated::commandArgs(argc, argv);   // Remember args
    Verilated::traceEverOn(true);

	test = new Vtest;             // Create instance

	test->reset = 0;           // Set some inputs
    test->clk = 0;

	while (!Verilated::gotFinish()) {
		if (main_time > 50) {
			test->reset = 1;   // Deassert reset
		}
		if ((main_time % 10000) == 0) { // 50 MHz main clock.
			test->clk = !test->clk;
		}
        if ((main_time + 3000) % 1000 == 0) { // 50 MHz (with -3000 ps shift) SDRAM clock.
            test->dram_clk_supplied = !test->dram_clk_supplied;
        }
        if ((main_time % 3000) == 0) { // 150 MHz VGA pixel clock.
            test->vga_clk_supplied = !test->vga_clk_supplied;
        }
		test->eval();            // Evaluate model
//        std::cout << test->out << std::endl;       // Read a output
		main_time++;            // Time passes...
	}

	test->final();               // Done simulating
	//    // (Though this example doesn't get here)
	delete test;
}
