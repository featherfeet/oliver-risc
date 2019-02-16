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

// Register to slow down the clock to human-readable speeds.
reg[23:0] clock_division_counter;
// Register for the number being displayed on the 7-segment display.
reg[3:0] number_to_display;

// Turn off the other 3 seven-segment displays.
assign HEX1 = 7'b1111111;
assign HEX2 = 7'b1111111;
assign HEX3 = 7'b1111111;

// Instantiate module to control the 7-segment display.
seven_segment_display display(.clk(CLOCK_24[0]), .number(number_to_display), .display(HEX0));

// Divide the clock down to human-readable speeds.
always @(posedge CLOCK_24[0])
begin
	if (KEY[0] == 0)
	begin
		clock_division_counter <= 0;
	end
	else
	begin
		clock_division_counter <= clock_division_counter + 1;
	end
end

// Cycle the 7-segment display through digits 0-9 and letters A-F.
always @(posedge clock_division_counter[23])
begin
		if (KEY[0] == 0)
			number_to_display <= 0;
		number_to_display <= number_to_display + 1;
		if (number_to_display == 4'd15)
			number_to_display <= 0;
end

// Test the slide-switches and LEDs.
assign LEDR = SW;

endmodule
