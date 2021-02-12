module rom(input CLOCK_50, input[31:0] address, output reg [7:0] output_byte, output done);
	assign done = (address == 32'd6138);
	reg[0:7] rom_memory[0:6139 - 1];
	initial begin
		$readmemh("rtl/rom.mem", rom_memory);
	end
	always @(posedge CLOCK_50)
	begin
		output_byte <= rom_memory[address];
	end
endmodule