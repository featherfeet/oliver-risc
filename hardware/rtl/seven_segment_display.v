module seven_segment_display(
	input clk,
	input [3:0] number,
	output reg [6:0] display
);
	always @(clk)
	begin
		case (number)
			4'd0:
				display <= 7'b1000000;
			4'd1:
				display <= 7'b1111001;
			4'd2:
				display <= 7'b0100100;
			4'd3:
				display <= 7'b0110000;
			4'd4:
				display <= 7'b0011001;
			4'd5:
				display <= 7'b0010010;
			4'd6:
				display <= 7'b0000010;
			4'd7:
				display <= 7'b1111000;
			4'd8:
				display <= 7'b0000000;
			4'd9:
				display <= 7'b0011000;
			4'd10:
				display <= 7'b0001000;
			4'd11:
				display <= 7'b0000011;
			4'd12:
				display <= 7'b1000110;
			4'd13:
				display <= 7'b0100001;
			4'd14:
				display <= 7'b0000110;
			4'd15:
				display <= 7'b0001110;
		endcase
	end
endmodule // seven_segment_display
