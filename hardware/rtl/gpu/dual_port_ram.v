module dual_port_ram(
    input CLOCK_50,
    input[$clog2(`GPU_TEXT_BUFFER_LENGTH) - 1:0] port_a_address,
    input[$clog2(`GPU_TEXT_BUFFER_LENGTH) - 1:0] port_b_address,
    input[7:0] port_a_data_in,
    input[7:0] port_b_data_in,
    input port_a_write_enable,
    input port_b_write_enable,
    output reg [7:0] port_a_data_out,
    output reg [7:0] port_b_data_out
);

    reg[7:0] ram_buffer[`GPU_TEXT_BUFFER_LENGTH - 1:0];

    always @(posedge CLOCK_50)
    begin
        if (port_a_write_enable)
        begin
            ram_buffer[port_a_address] <= port_a_data_in;
            port_a_data_out <= port_a_data_in;
        end
        else
            port_a_data_out <= ram_buffer[port_a_address];
    end

    always @(posedge CLOCK_50)
    begin
        if (port_b_write_enable)
        begin
            ram_buffer[port_b_address] <= port_b_data_in;
            port_b_data_out <= port_b_data_in;
        end
        else
            port_b_data_out <= ram_buffer[port_b_address];
    end

endmodule
