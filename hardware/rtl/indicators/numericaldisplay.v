module numericaldisplay(
	input CLOCK_50,
	input RST_N,
    input [31:0] number_to_show,
	output wire[6:0] HEX0,
	output wire[6:0] HEX1,
	output wire[6:0] HEX2,
	output wire[6:0] HEX3
);

    reg[3:0] display_numbers[3:0]; // Digits that are shown on the four 7-segment displays.
    reg[3:0] display_numbers_buffer[3:0]; // This buffers 4 digits before they are copied to display_numbers.
    reg[3:0] display_number_index; // Which digit of the 4 available 7-segment displays should be written to.
	seven_segment_display disp0(.clk(CLOCK_50), .number(display_numbers[0]), .display(HEX0));
	seven_segment_display disp1(.clk(CLOCK_50), .number(display_numbers[1]), .display(HEX1));
	seven_segment_display disp2(.clk(CLOCK_50), .number(display_numbers[2]), .display(HEX2));
	seven_segment_display disp3(.clk(CLOCK_50), .number(display_numbers[3]), .display(HEX3));

    wire[31:0] divider_quotient;
    wire[31:0] divider_remainder;

    reg [31:0] number_to_show_reg;

    lpm_divide divider (
        .clock(CLOCK_50),
        .clken('b1),
        .aclr('b0),
        .numer(number_to_show_reg),
        .denom(4'd10),
        .quotient(divider_quotient),
        .remain(divider_remainder)
    );
    defparam divider.lpm_widthn = 32;
    defparam divider.lpm_widthd = 4;

    reg[7:0] state;
    parameter STATE_DIVIDE = 'd0;
    parameter STATE_WAIT = 'd1;
    integer i;

	always @(posedge CLOCK_50)
	begin
		if (RST_N == 0)
		begin
            state <= STATE_WAIT;
            for (i = 0; i < 4; i = i + 1)
            begin
                display_numbers[i] <= 'b0;
                display_numbers_buffer[i] <= 'b0;
            end
            display_number_index <= 'b0;
            number_to_show_reg <= 'b0;
		end
        else
        begin
            case (state)
                STATE_DIVIDE:
                begin
                    state <= STATE_WAIT;
                end
                STATE_WAIT:
                begin
                    if (display_number_index < 'd4)
                    begin
                        number_to_show_reg <= divider_quotient;
                        display_numbers_buffer[display_number_index] <= divider_remainder;
                        display_number_index <= display_number_index + 'b1;
                        state <= STATE_DIVIDE;
                    end
                    else if (display_number_index == 'd4)
                    begin
                        for (i = 0; i < 4; i = i + 1)
                            display_numbers[i] = display_numbers_buffer[i];
                        display_number_index <= 'b0;
                        number_to_show_reg <= number_to_show;
                        state <= STATE_WAIT;
                    end
                end
            endcase
        end
	end
endmodule
