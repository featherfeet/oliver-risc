module font_rom(input CLOCK_150, input[7:0] character, input[$clog2(8) - 1:0] character_cell_x, input[$clog2(16) - 1:0] character_cell_y, output reg pixel_value);
	reg[0:127] font_storage[0:256 - 1];
	initial begin
		$readmemh("rtl/gpu/font_rom.mem", font_storage);
	end
	always @(posedge CLOCK_150)
	begin
		if ((character_cell_y * 'd8 + character_cell_x) > 'd127)
			pixel_value <= 'b0;
		else
			pixel_value <= font_storage[character][character_cell_y * 'd8 + character_cell_x];
	end
endmodule
