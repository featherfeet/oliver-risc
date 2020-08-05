module keyboard(
    input PS2_CLK,
    input PS2_DAT,
    output wire [7:0] scancode
);

reg [10:0] shift_register = 'b0;
assign scancode = shift_register[8:0];

always @(negedge PS2_CLK)
begin
    shift_register <= shift_register >> 1;
    shift_register[9] <= PS2_DAT;
end

endmodule
