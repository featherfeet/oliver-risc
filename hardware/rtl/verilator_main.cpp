#include <verilated.h>          // Defines common routines
#include <iostream>             // Need std::cout
#include "Vverilator_test.h"    // From Verilating "test.v"

Vverilator_test *test;          // Instantiation of module

vluint64_t main_time = 0;       // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  This is in units of the timeprecision
// used in Verilog (or from --timescale-override)

double sc_time_stamp() {       // Called by $time in Verilog
	return main_time;           // converts to double, to match
								// what SystemC does
}

int main(int argc, char** argv) {
	Verilated::commandArgs(argc, argv);   // Remember args
    Verilated::traceEverOn(true);

	test = new Vverilator_test;             // Create instance

	test->reset_n = 0;           // Set some inputs
    test->clk = 0;
    test->verilator_only_dram_clk = 0;
    test->verilator_only_vga_pixel_clock = 0;
    test->eval();
    main_time++;

	while (!Verilated::gotFinish()) {
		if (main_time > 25000) {
			test->reset_n = 1;   // Deassert reset
		}
		if ((main_time % 10000) == 0) { // 50 MHz main clock.
			test->clk = !test->clk;
		}
        if ((main_time + 3000) % 10000 == 0) { // 50 MHz (with -3000 ps shift) SDRAM clock.
            test->verilator_only_dram_clk = !test->verilator_only_dram_clk;
        }
        if ((main_time % 3000) == 0) { // 150 MHz VGA pixel clock.
            test->verilator_only_vga_pixel_clock = !test->verilator_only_vga_pixel_clock;
        }
		test->eval();            // Evaluate model
		main_time++;            // Time passes...
	}

	test->final();               // Done simulating
	//    // (Though this example doesn't get here)
	delete test;
}
