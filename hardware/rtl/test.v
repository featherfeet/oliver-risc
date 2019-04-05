`timescale 1ns / 100ps

module test();
    reg[3:0] reset = 4'd0;
    reg[1:0] clk = 2'b11;
    always #5 clk = ~clk;
    top top_instantiation(.KEY(reset), .CLOCK_50(clk));
    initial begin
        $dumpfile("dump.lxt");
        $dumpvars(0, top_instantiation);
        reset[0] = 1;
        #17 reset[0] = 0;
        #11 reset[0] = 1;
    end
endmodule
