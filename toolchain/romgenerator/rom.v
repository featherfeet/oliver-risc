module rom(input[31:0] address, output reg [7:0] output_byte, output done);
	assign done = (address == 32'd117) ? 1'b1 : 1'b0;
	always @(address)
	begin
		case (address)
			32'd0:
				output_byte = 8'd14;
			32'd1:
				output_byte = 8'd20;
			32'd2:
				output_byte = 8'd15;
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
				output_byte = 8'd20;
			32'd11:
				output_byte = 8'd5;
			32'd12:
				output_byte = 8'd0;
			32'd13:
				output_byte = 8'd0;
			32'd14:
				output_byte = 8'd0;
			32'd15:
				output_byte = 8'd2;
			32'd16:
				output_byte = 8'd0;
			32'd17:
				output_byte = 8'd0;
			32'd18:
				output_byte = 8'd0;
			32'd19:
				output_byte = 8'd22;
			32'd20:
				output_byte = 8'd1;
			32'd21:
				output_byte = 8'd0;
			32'd22:
				output_byte = 8'd0;
			32'd23:
				output_byte = 8'd0;
			32'd24:
				output_byte = 8'd2;
			32'd25:
				output_byte = 8'd0;
			32'd26:
				output_byte = 8'd0;
			32'd27:
				output_byte = 8'd0;
			32'd28:
				output_byte = 8'd20;
			32'd29:
				output_byte = 8'd0;
			32'd30:
				output_byte = 8'd0;
			32'd31:
				output_byte = 8'd0;
			32'd32:
				output_byte = 8'd0;
			32'd33:
				output_byte = 8'd3;
			32'd34:
				output_byte = 8'd0;
			32'd35:
				output_byte = 8'd0;
			32'd36:
				output_byte = 8'd0;
			32'd37:
				output_byte = 8'd5;
			32'd38:
				output_byte = 8'd3;
			32'd39:
				output_byte = 8'd0;
			32'd40:
				output_byte = 8'd0;
			32'd41:
				output_byte = 8'd0;
			32'd42:
				output_byte = 8'd1;
			32'd43:
				output_byte = 8'd0;
			32'd44:
				output_byte = 8'd0;
			32'd45:
				output_byte = 8'd0;
			32'd46:
				output_byte = 8'd20;
			32'd47:
				output_byte = 8'd1;
			32'd48:
				output_byte = 8'd0;
			32'd49:
				output_byte = 8'd0;
			32'd50:
				output_byte = 8'd0;
			32'd51:
				output_byte = 8'd3;
			32'd52:
				output_byte = 8'd0;
			32'd53:
				output_byte = 8'd0;
			32'd54:
				output_byte = 8'd0;
			32'd55:
				output_byte = 8'd5;
			32'd56:
				output_byte = 8'd3;
			32'd57:
				output_byte = 8'd0;
			32'd58:
				output_byte = 8'd0;
			32'd59:
				output_byte = 8'd0;
			32'd60:
				output_byte = 8'd2;
			32'd61:
				output_byte = 8'd0;
			32'd62:
				output_byte = 8'd0;
			32'd63:
				output_byte = 8'd0;
			32'd64:
				output_byte = 8'd20;
			32'd65:
				output_byte = 8'd3;
			32'd66:
				output_byte = 8'd0;
			32'd67:
				output_byte = 8'd0;
			32'd68:
				output_byte = 8'd0;
			32'd69:
				output_byte = 8'd1;
			32'd70:
				output_byte = 8'd0;
			32'd71:
				output_byte = 8'd0;
			32'd72:
				output_byte = 8'd0;
			32'd73:
				output_byte = 8'd20;
			32'd74:
				output_byte = 8'd4;
			32'd75:
				output_byte = 8'd0;
			32'd76:
				output_byte = 8'd0;
			32'd77:
				output_byte = 8'd0;
			32'd78:
				output_byte = 8'd2;
			32'd79:
				output_byte = 8'd0;
			32'd80:
				output_byte = 8'd0;
			32'd81:
				output_byte = 8'd0;
			32'd82:
				output_byte = 8'd21;
			32'd83:
				output_byte = 8'd1;
			32'd84:
				output_byte = 8'd0;
			32'd85:
				output_byte = 8'd0;
			32'd86:
				output_byte = 8'd0;
			32'd87:
				output_byte = 8'd2;
			32'd88:
				output_byte = 8'd0;
			32'd89:
				output_byte = 8'd0;
			32'd90:
				output_byte = 8'd0;
			32'd91:
				output_byte = 8'd20;
			32'd92:
				output_byte = 8'd0;
			32'd93:
				output_byte = 8'd0;
			32'd94:
				output_byte = 8'd0;
			32'd95:
				output_byte = 8'd0;
			32'd96:
				output_byte = 8'd3;
			32'd97:
				output_byte = 8'd0;
			32'd98:
				output_byte = 8'd0;
			32'd99:
				output_byte = 8'd0;
			32'd100:
				output_byte = 8'd5;
			32'd101:
				output_byte = 8'd3;
			32'd102:
				output_byte = 8'd0;
			32'd103:
				output_byte = 8'd0;
			32'd104:
				output_byte = 8'd0;
			32'd105:
				output_byte = 8'd1;
			32'd106:
				output_byte = 8'd0;
			32'd107:
				output_byte = 8'd0;
			32'd108:
				output_byte = 8'd0;
			32'd109:
				output_byte = 8'd13;
			32'd110:
				output_byte = 8'd0;
			32'd111:
				output_byte = 8'd0;
			32'd112:
				output_byte = 8'd0;
			32'd113:
				output_byte = 8'd0;
			32'd114:
				output_byte = 8'd0;
			32'd115:
				output_byte = 8'd0;
			32'd116:
				output_byte = 8'd0;
			32'd117:
				output_byte = 8'd0;
			default:
				output_byte = 8'd0;
		endcase
	end
endmodule