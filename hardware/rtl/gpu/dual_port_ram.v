`include "gpu_defines.v"

module dual_port_ram(
    input port_a_clock,
    input port_b_clock,
    input[$clog2(`GPU_TEXT_BUFFER_LENGTH) - 1:0] port_a_address,
    input[$clog2(`GPU_TEXT_BUFFER_LENGTH) - 1:0] port_b_address,
    input[7:0] port_a_data_in,
    input port_a_write_enable,
    output reg [7:0] port_a_data_out,
    output reg [7:0] port_b_data_out
);

    reg[0:7] ram_buffer[0:`GPU_TEXT_BUFFER_LENGTH - 1];

    initial begin
        $display("Loading boot screen...");
		$readmemh("rtl/gpu/boot_screen.mem", ram_buffer);
    end

    always @(posedge port_a_clock)
    begin
        if (port_a_write_enable)
        begin
            ram_buffer[port_a_address] <= port_a_data_in;
            port_a_data_out <= port_a_data_in;
        end
        else
            port_a_data_out <= ram_buffer[port_a_address];
    end

    always @(posedge port_b_clock)
    begin
        port_b_data_out <= ram_buffer[port_b_address];
    end

endmodule
