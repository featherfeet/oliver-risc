module rom(input[31:0] address, output reg [7:0] byte, output done);
	assign done = (address == 32'd111) ? 1 : 0;
	always @(address)
	begin
		case (address)
			32'd0:
				byte = 8'd1;
			32'd1:
				byte = 8'd0;
			32'd2:
				byte = 8'd0;
			32'd3:
				byte = 8'd0;
			32'd4:
				byte = 8'd1;
			32'd5:
				byte = 8'd0;
			32'd6:
				byte = 8'd0;
			32'd7:
				byte = 8'd0;
			32'd8:
				byte = 8'd5;
			32'd9:
				byte = 8'd0;
			32'd10:
				byte = 8'd0;
			32'd11:
				byte = 8'd0;
			32'd12:
				byte = 8'd14;
			32'd13:
				byte = 8'd1;
			32'd14:
				byte = 8'd0;
			32'd15:
				byte = 8'd0;
			32'd16:
				byte = 8'd0;
			32'd17:
				byte = 8'd0;
			32'd18:
				byte = 8'd2;
			32'd19:
				byte = 8'd0;
			32'd20:
				byte = 8'd0;
			32'd21:
				byte = 8'd0;
			32'd22:
				byte = 8'd1;
			32'd23:
				byte = 8'd4;
			32'd24:
				byte = 8'd0;
			32'd25:
				byte = 8'd0;
			32'd26:
				byte = 8'd0;
			32'd27:
				byte = 8'd3;
			32'd28:
				byte = 8'd0;
			32'd29:
				byte = 8'd0;
			32'd30:
				byte = 8'd0;
			32'd31:
				byte = 8'd1;
			32'd32:
				byte = 8'd8;
			32'd33:
				byte = 8'd0;
			32'd34:
				byte = 8'd0;
			32'd35:
				byte = 8'd0;
			32'd36:
				byte = 8'd4;
			32'd37:
				byte = 8'd0;
			32'd38:
				byte = 8'd0;
			32'd39:
				byte = 8'd0;
			32'd40:
				byte = 8'd5;
			32'd41:
				byte = 8'd2;
			32'd42:
				byte = 8'd0;
			32'd43:
				byte = 8'd0;
			32'd44:
				byte = 8'd0;
			32'd45:
				byte = 8'd1;
			32'd46:
				byte = 8'd0;
			32'd47:
				byte = 8'd0;
			32'd48:
				byte = 8'd0;
			32'd49:
				byte = 8'd3;
			32'd50:
				byte = 8'd2;
			32'd51:
				byte = 8'd0;
			32'd52:
				byte = 8'd0;
			32'd53:
				byte = 8'd0;
			32'd54:
				byte = 8'd3;
			32'd55:
				byte = 8'd0;
			32'd56:
				byte = 8'd0;
			32'd57:
				byte = 8'd0;
			32'd58:
				byte = 8'd7;
			32'd59:
				byte = 8'd1;
			32'd60:
				byte = 8'd0;
			32'd61:
				byte = 8'd0;
			32'd62:
				byte = 8'd0;
			32'd63:
				byte = 8'd2;
			32'd64:
				byte = 8'd0;
			32'd65:
				byte = 8'd0;
			32'd66:
				byte = 8'd0;
			32'd67:
				byte = 8'd8;
			32'd68:
				byte = 8'd2;
			32'd69:
				byte = 8'd0;
			32'd70:
				byte = 8'd0;
			32'd71:
				byte = 8'd0;
			32'd72:
				byte = 8'd4;
			32'd73:
				byte = 8'd0;
			32'd74:
				byte = 8'd0;
			32'd75:
				byte = 8'd0;
			32'd76:
				byte = 8'd9;
			32'd77:
				byte = 8'd27;
			32'd78:
				byte = 8'd0;
			32'd79:
				byte = 8'd0;
			32'd80:
				byte = 8'd0;
			32'd81:
				byte = 8'd0;
			32'd82:
				byte = 8'd0;
			32'd83:
				byte = 8'd0;
			32'd84:
				byte = 8'd0;
			32'd85:
				byte = 8'd10;
			32'd86:
				byte = 8'd27;
			32'd87:
				byte = 8'd0;
			32'd88:
				byte = 8'd0;
			32'd89:
				byte = 8'd0;
			32'd90:
				byte = 8'd0;
			32'd91:
				byte = 8'd0;
			32'd92:
				byte = 8'd0;
			32'd93:
				byte = 8'd144;
			32'd94:
				byte = 8'd11;
			32'd95:
				byte = 8'd90;
			32'd96:
				byte = 8'd0;
			32'd97:
				byte = 8'd0;
			32'd98:
				byte = 8'd0;
			32'd99:
				byte = 8'd0;
			32'd100:
				byte = 8'd0;
			32'd101:
				byte = 8'd0;
			32'd102:
				byte = 8'd0;
			32'd103:
				byte = 8'd13;
			32'd104:
				byte = 8'd0;
			32'd105:
				byte = 8'd0;
			32'd106:
				byte = 8'd0;
			32'd107:
				byte = 8'd0;
			32'd108:
				byte = 8'd0;
			32'd109:
				byte = 8'd0;
			32'd110:
				byte = 8'd0;
			32'd111:
				byte = 8'd0;
			default:
				byte = 8'd0;
		endcase
	end
endmodule