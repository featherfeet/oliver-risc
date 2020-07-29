module rom(input[31:0] address, output reg [7:0] output_byte, output done);
	assign done = (address == 32'd27) ? 1'b1 : 1'b0;
	always @(address)
	begin
		case (address)
			32'd0:
				output_byte = 8'd14;
			32'd1:
				output_byte = 8'd20;
			32'd2:
				output_byte = 8'd57;
			32'd3:
				output_byte = 8'd0;
			32'd4:
				output_byte = 8'd0;
			32'd5:
				output_byte = 8'd0;
			32'd6:
				output_byte = 8'd1;
			32'd7:
				output_byte = 8'd0;
			32'd8:
				output_byte = 8'd0;
			32'd9:
				output_byte = 8'd0;
			32'd10:
				output_byte = 8'd5;
			32'd11:
				output_byte = 8'd1;
			32'd12:
				output_byte = 8'd0;
			32'd13:
				output_byte = 8'd0;
			32'd14:
				output_byte = 8'd0;
			32'd15:
				output_byte = 8'd0;
			32'd16:
				output_byte = 8'd0;
			32'd17:
				output_byte = 8'd0;
			32'd18:
				output_byte = 8'd0;
			32'd19:
				output_byte = 8'd13;
			32'd20:
				output_byte = 8'd0;
			32'd21:
				output_byte = 8'd0;
			32'd22:
				output_byte = 8'd0;
			32'd23:
				output_byte = 8'd0;
			32'd24:
				output_byte = 8'd0;
			32'd25:
				output_byte = 8'd0;
			32'd26:
				output_byte = 8'd0;
			32'd27:
				output_byte = 8'd0;
			default:
				output_byte = 8'd0;
		endcase
	end
endmodule