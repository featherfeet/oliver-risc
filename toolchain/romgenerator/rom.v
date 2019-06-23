module rom(input[31:0] address, output reg [7:0] byte, output done);
	assign done = (address == 32'd53) ? 1 : 0;
	always @(address)
	begin
		case (address)
			32'd0:
				byte = 8'd34;
			32'd1:
				byte = 8'd1;
			32'd2:
				byte = 8'd0;
			32'd3:
				byte = 8'd0;
			32'd4:
				byte = 8'd0;
			32'd5:
				byte = 8'd0;
			32'd6:
				byte = 8'd0;
			32'd7:
				byte = 8'd0;
			32'd8:
				byte = 8'd14;
			32'd9:
				byte = 8'd1;
			32'd10:
				byte = 8'd0;
			32'd11:
				byte = 8'd0;
			32'd12:
				byte = 8'd0;
			32'd13:
				byte = 8'd0;
			32'd14:
				byte = 8'd1;
			32'd15:
				byte = 8'd0;
			32'd16:
				byte = 8'd0;
			32'd17:
				byte = 8'd0;
			32'd18:
				byte = 8'd2;
			32'd19:
				byte = 8'd1;
			32'd20:
				byte = 8'd0;
			32'd21:
				byte = 8'd0;
			32'd22:
				byte = 8'd0;
			32'd23:
				byte = 8'd4;
			32'd24:
				byte = 8'd0;
			32'd25:
				byte = 8'd0;
			32'd26:
				byte = 8'd0;
			32'd27:
				byte = 8'd1;
			32'd28:
				byte = 8'd4;
			32'd29:
				byte = 8'd0;
			32'd30:
				byte = 8'd0;
			32'd31:
				byte = 8'd0;
			32'd32:
				byte = 8'd2;
			32'd33:
				byte = 8'd0;
			32'd34:
				byte = 8'd0;
			32'd35:
				byte = 8'd0;
			32'd36:
				byte = 8'd5;
			32'd37:
				byte = 8'd2;
			32'd38:
				byte = 8'd0;
			32'd39:
				byte = 8'd0;
			32'd40:
				byte = 8'd0;
			32'd41:
				byte = 8'd2;
			32'd42:
				byte = 8'd0;
			32'd43:
				byte = 8'd0;
			32'd44:
				byte = 8'd0;
			32'd45:
				byte = 8'd13;
			32'd46:
				byte = 8'd0;
			32'd47:
				byte = 8'd0;
			32'd48:
				byte = 8'd0;
			32'd49:
				byte = 8'd0;
			32'd50:
				byte = 8'd0;
			32'd51:
				byte = 8'd0;
			32'd52:
				byte = 8'd0;
			32'd53:
				byte = 8'd0;
			default:
				byte = 8'd0;
		endcase
	end
endmodule