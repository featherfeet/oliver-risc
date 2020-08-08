`timescale 1ns / 100ps
//`timescale 1ps/1ps

module test();
    // See the verilog-vga-simulator/demo.v file and http://martin.hinner.info/vga/timing.html.
    localparam dots_per_line = 640 + 16 + 96 + 48;
    localparam lines_per_frame = 480 + 11 + 2 + 31;

    integer i;
    reg[3:0] reset = 4'd0;
    reg clk = 1'b1;
    always #5 clk = ~clk;

    wire SDRAM_CLK;
    wire [11:0] DRAM_ADDR;
    wire DRAM_BA_0;
    wire DRAM_BA_1;
    wire DRAM_CAS_N;
    wire DRAM_CKE;
    wire DRAM_CS_N;
    wire [15:0] DRAM_DQ;
    wire DRAM_LDQM;
    wire DRAM_UDQM;
    wire DRAM_RAS_N;
    wire DRAM_WE_N;

    wire[3:0] VGA_R;
    wire[3:0] VGA_G;
    wire[3:0] VGA_B;
    wire VGA_HS;
    wire VGA_VS;
    wire VGA_PIXEL_CLOCK;

    altera_sdram_partner_module sdram_module (
        .clk                            (SDRAM_CLK),
        .zs_addr                        (DRAM_ADDR),
        .zs_ba                          ({DRAM_BA_1, DRAM_BA_0}),
        .zs_cas_n                       (DRAM_CAS_N),
        .zs_cke                         (DRAM_CKE),
        .zs_cs_n                        (DRAM_CS_N),
        .zs_dqm                         ({DRAM_UDQM, DRAM_LDQM}),
        .zs_ras_n                       (DRAM_RAS_N),
        .zs_we_n                        (DRAM_WE_N),
        .zs_dq                          (DRAM_DQ)
    );

    top top_instantiation (
        .KEY(reset),
        .CLOCK_50(clk),
        .DRAM_CLK(SDRAM_CLK),
        .DRAM_ADDR(DRAM_ADDR),
        .DRAM_BA_0(DRAM_BA_0),
        .DRAM_BA_1(DRAM_BA_1),
        .DRAM_CAS_N(DRAM_CAS_N),
        .DRAM_CKE(DRAM_CKE),
        .DRAM_CS_N(DRAM_CS_N),
        .DRAM_LDQM(DRAM_LDQM),
        .DRAM_UDQM(DRAM_UDQM),
        .DRAM_RAS_N(DRAM_RAS_N),
        .DRAM_WE_N(DRAM_WE_N),
        .DRAM_DQ(DRAM_DQ),
        .VGA_R(VGA_R),
        .VGA_G(VGA_G),
        .VGA_B(VGA_B),
        .VGA_HS(VGA_HS),
        .VGA_VS(VGA_VS),
        .VGA_PIXEL_CLOCK(VGA_PIXEL_CLOCK)
    );
    initial begin
        $dumpfile("dump.lxt");
        $dumpvars(0, test);
        for (i = 0; i < `NUM_REGISTERS; i = i + 1)
            $dumpvars(0, top_instantiation.registers[i]);
        $vgasimInit(
            dots_per_line,
            lines_per_frame,
            VGA_R, VGA_G, VGA_B,
            VGA_HS,
            VGA_VS,
            VGA_PIXEL_CLOCK
        );
        reset = 'b0;
        //#80000 reset = 'hF;
        #80 reset = 'hF;
    end
endmodule
