module keyboard(
    input rst_n,
    input CLOCK_50,
    input PS2_CLK,
    input PS2_DAT,
    output reg [7:0] scancode,
    output reg ready
);

reg[7:0] ps2_clk_buffer;

reg ps2_clk_filtered_state;
reg previous_ps2_clk_filtered_state;

wire ps2_clk_falling;
assign ps2_clk_falling = (previous_ps2_clk_filtered_state == 'b1 && ps2_clk_filtered_state == 'b0);

reg [10:0] shift_register;
reg[$clog2(11) - 1:0] bits_counter; // PS/2 has 11 bits per byte transmitted.

always @(posedge CLOCK_50)
begin
    if (~rst_n)
    begin
        ps2_clk_buffer <= 8'b11111111;
        ps2_clk_filtered_state <= 1'b1;
        previous_ps2_clk_filtered_state <= 1'b1;
        shift_register <= 'b0;
        bits_counter <= 'b0;
    end
    else
    begin
        ps2_clk_buffer <= {PS2_CLK, ps2_clk_buffer[7:1]};
        if (ps2_clk_buffer == 8'b11111111)
        begin
            previous_ps2_clk_filtered_state <= ps2_clk_filtered_state;
            ps2_clk_filtered_state <= 'b1;
        end
        else if (ps2_clk_buffer == 8'b00000000)
        begin
            previous_ps2_clk_filtered_state <= ps2_clk_filtered_state;
            ps2_clk_filtered_state <= 'b0;
        end
        if (ps2_clk_falling)
        begin
            shift_register <= shift_register >> 1;
            shift_register[9] <= PS2_DAT;
            bits_counter <= bits_counter + 'b1;
            if (bits_counter == 'd10)
            begin
                if (~^shift_register[9:1] == shift_register[10])
                begin
                    ready <= 'b1;
                    scancode <= shift_register[9:1];
                end
                bits_counter <= 'b0;
            end
        end
        else
        begin
            ready <= 'b0;
        end
    end
end

endmodule
