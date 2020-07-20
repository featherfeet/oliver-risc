module gpu(
    input CLOCK_50,
    input reset,
    output reg [3:0] VGA_R,
    output reg [3:0] VGA_G,
    output reg [3:0] VGA_B,
    output wire VGA_HS,
    output wire VGA_VS,
);

// Size of the text display.
parameter text_display_rows = 5'd24;
parameter text_display_columns = 7'd80;

integer i;

// Buffer holding the text that is being displayed on-screen.
reg[$clog2(text_display_rows) - 1:0] text_buffer[$clog2(text_display_columns) - 1:0];

// Create a VGA controller with 25 MHz clock.
reg[1:0] clock_divider;
wire blanking;
vga640x480 vga(.i_clk(CLOCK_50),
               .i_pix_stb(clock_divider[0]),
               .i_rst(~reset),
               .o_hs(VGA_HS),
               .o_vs(VGA_VS),
               .o_blanking(blanking)
               .o_x()
               .o_y());

always @(posedge CLOCK_50)
begin
    if (reset)
        clock_divider <= 0;
        text_buffer <= '{default: 'h0};
    else
    begin
        clock_divider <= clock_divider + 1;
        if (blanking)
        begin
            VGA_R <= 4'b0000;
            VGA_G <= 4'b0000;
            VGA_B <= 4'b0000;
        end
        else
        begin
            // Set pixel colors based on text.
        end
    end
end

endmodule
