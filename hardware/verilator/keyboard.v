`timescale 1ns / 100ps
module keyboard(
    input CLOCK_50,
    input PS2_CLK,
    input PS2_DAT,
    output wire [7:0] scancode,
    output wire ready
);

reg [10:0] shift_register;
assign scancode = shift_register[8:0]; // The first bit of PS/2 is a start bit, the second-to-last is a parity bit, and the last is a stop bit.

reg[$clog2(11) - 1:0] bits_counter; // PS/2 has 11 bits per byte transmitted.
reg done;
reg other_done;

initial begin
    shift_register <= 'b0;
    bits_counter <= 'b0;
    done <= 'b0;
    other_done <= 'b0;
end

assign ready = done & other_done;

always @(negedge PS2_CLK)
begin
    shift_register <= shift_register >> 1;
    shift_register[9] <= PS2_DAT;
    bits_counter <= bits_counter + 'b1;
    if (bits_counter == 'd10)
    begin
        bits_counter <= 'b0;
        done <= 'b1;
    end
    else
        done <= 'b0;
end

assign bits_counter_finished = (bits_counter == 'd10);

always @(posedge bits_counter_finished or posedge PS2_CLK or posedge CLOCK_50)
begin
    if (bits_counter_finished)
        other_done <= 'b1;
    else
    begin
        if (CLOCK_50 == 'b1)
            other_done <= 'b0;
    end
end

endmodule
