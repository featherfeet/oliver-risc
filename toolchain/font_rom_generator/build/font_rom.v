module font_rom(input[7:0] character, input[$clog2(8) - 1:0] character_cell_x, input[$clog2(20) - 1:0] character_cell_y, output wire pixel_value);
reg[0:127] font_storage[0:256 - 1];
	initial begin
		$readmemh("rtl/gpu/font_rom.mem", font_storage);
	end
	assign pixel_value = font_storage[character][character_cell_y * 8 + character_cell_x];
endmodule