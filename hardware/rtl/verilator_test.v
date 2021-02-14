`include "defines.v"
`include "sdram/altera_sdram_partner_module.v"

`timescale 1ns / 100ps

module verilator_test (
    input wire clk,
    input wire reset_n,
    input verilator_only_dram_clk,
    input verilator_only_vga_pixel_clock
);
    integer i;

    reg PS2_CLK = 'b1;
    reg PS2_DAT = 'b1;

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

    wire spi_sclk;
    wire spi_copi;
    wire spi_cs;

    top top_instantiation (
        .KEY(reset_n),
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
        .VGA_PIXEL_CLOCK(VGA_PIXEL_CLOCK),
        .PS2_CLK(PS2_CLK),
        .PS2_DAT(PS2_DAT),
        .verilator_only_dram_clk(verilator_only_dram_clk),
        .verilator_only_vga_pixel_clock(verilator_only_vga_pixel_clock),
        .SD_CLK(spi_sclk),
        .SD_CMD(spi_copi),
        .SD_DAT3(spi_cs)
    );
    initial begin
        $dumpfile("dump.vcd");
        /*
        $dumpvars(0, test);
        for (i = 0; i < `NUM_REGISTERS; i = i + 1)
        begin
            $dumpvars(0, top_instantiation.registers[i]);
            $dumpvars(0, top_instantiation.shadow_registers[i]);
        end
        for (i = 0; i < 5; i = i + 1)
        begin
            $dumpvars(0, top_instantiation.keyboard_scancodes_fifo.items[i]);
        end
        for (i = 0; i < 10; i = i + 1)
        begin
            $dumpvars(0, top_instantiation.interrupt_fifo.items[i]);
            $dumpvars(0, top_instantiation.interrupt_value_fifo.items[i]);
        end
        */
    end
endmodule
