`timescale 1ns / 100ps

module test();
    // See the verilog-vga-simulator/demo.v file and http://martin.hinner.info/vga/timing.html.
    localparam dots_per_line = 2200;
    localparam lines_per_frame = 1125;

    integer i;
    reg[3:0] reset = 4'd0;
    reg clk = 1'b1;
    always #10 clk = ~clk;

    reg PS2_CLK = 'b1;
    reg PS2_DAT = 'b1;

    task send_ps2_scancode;
        input [7:0] scancode_to_write;
        begin
            // Send start bit.
            #2000 PS2_DAT = 'b0;
            #2000 PS2_CLK = 'b0;
            #2000 PS2_CLK = 'b1;
            for (i = 0; i < 8; i = i + 1)
            begin
                // Send a data bit.
                #2000 PS2_DAT = scancode_to_write[i];
                #2000 PS2_CLK = 'b0;
                #2000 PS2_CLK = 'b1;
            end
            // Send parity bit.
            #2000 PS2_DAT = ~^scancode_to_write;
            #2000 PS2_CLK = 'b0;
            #2000 PS2_CLK = 'b1;
            // Send stop bit.
            #2000 PS2_DAT = 'b0;
            #2000 PS2_CLK = 'b0;
            #2000 PS2_CLK = 'b1;
        end
    endtask

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

    wire SD_DAT3;
    wire SD_CLK;
    wire SD_CMD;
    wire SD_DAT;

    /*
    spi_sd_model spi_sd_model(
        .rstn(reset),
        .ncs(SD_DAT3),
        .sclk(SD_CLK),
        .mosi(SD_CMD),
        .miso(SD_DAT)
    );
    */

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
        .VGA_PIXEL_CLOCK(VGA_PIXEL_CLOCK),
        .PS2_CLK(PS2_CLK),
        .PS2_DAT(PS2_DAT),
        .SD_DAT3(SD_DAT3),
        .SD_CLK(SD_CLK),
        .SD_CMD(SD_CMD),
        .SD_DAT(SD_DAT)
    );
    initial begin
        PS2_CLK = 'b1;
        $dumpfile("dump.lxt");
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
        // TODO: Re-enable GPU.
        /*
        $vgasimInit(
            dots_per_line,
            lines_per_frame,
            VGA_R, VGA_G, VGA_B,
            VGA_HS,
            VGA_VS,
            VGA_PIXEL_CLOCK
        );
        */
        reset = 'b0;
        //#80000 reset = 'hF;
        #80 reset = 'hF;
        // FOR FULL SHELL PROGRAM (wait 2 ms + 123 ns):
        //#2_000_123; // Wait 2 ms for program to start and reach the busy-wait loop, plus some small amount of time to make sure the PS/2 and the main clock aren't exactly in sync.
        // FOR SIMPLE KEYBOARD TEST PROGRAM (wait 200 us + 123 ns):
        /*
        #200_123
        // Send the 1 key.
        send_ps2_scancode('hF0);
        #5000;
        send_ps2_scancode(22);
        #5000;
        // Send the 2 key.
        send_ps2_scancode('hF0);
        #5000;
        send_ps2_scancode(30);
        #5000;
        // Send the 3 key.
        send_ps2_scancode('hF0);
        #5000;
        send_ps2_scancode(38);
        #5000;
        // Send the 1 key.
        send_ps2_scancode('hF0);
        #5000;
        send_ps2_scancode(22);
        #5000;
        */
        /*
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #47_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #43_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #70701;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #42_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #38_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #39_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #1875;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #22_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #44_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #44_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #1308109;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #47_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #38_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #70720;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #1885;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #46_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #44_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #1450734;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #15_000;
        PS2_CLK = 'b0;
        #47_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #18_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #66485;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #42_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #1878;
        PS2_DAT = 'b0;
        #17_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #43_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #46_000;
        PS2_CLK = 'b1;
        #1260707;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #47_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #18_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #74910;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #46_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #19_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #42_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #38_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #1875;
        PS2_DAT = 'b0;
        #15_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b0;
        #25_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #40_000;
        PS2_CLK = 'b1;
        #25_000;
        PS2_DAT = 'b0;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #40_000;
        PS2_CLK = 'b0;
        #42_000;
        PS2_CLK = 'b1;
        #45_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #38_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        #20_000;
        PS2_DAT = 'b1;
        #20_000;
        PS2_CLK = 'b0;
        #45_000;
        PS2_CLK = 'b1;
        */
        //$finish;
    end
endmodule
