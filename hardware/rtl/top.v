module top(
	input [3:0] KEY,
	input [1:0] CLOCK_24,
	input [9:0] SW,
	output [6:0] HEX0,
	output [6:0] HEX1,
	output [6:0] HEX2,
	output [6:0] HEX3,
	output [9:0] LEDR
);

// Register for the number being displayed on the 7-segment display.
wire[3:0] number_to_display;

// Turn off the other 3 seven-segment displays.
assign HEX1 = 7'b1111111;
assign HEX2 = 7'b1111111;
assign HEX3 = 7'b1111111;

// Instantiate module to control the 7-segment display.
seven_segment_display display(.clk(CLOCK_24[0]), .number(number_to_display), .display(HEX0));

// Show the inputted number on the 7-segment display.
assign number_to_display = SW[3:0];

// Display the slide-switch status on the LEDs.
assign LEDR[3:0] = SW[3:0];

endmodule
