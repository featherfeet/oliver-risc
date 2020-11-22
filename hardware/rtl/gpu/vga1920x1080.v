// Author: https://timetoexplore.net/blog/arty-fpga-vga-verilog-01
module vga1920x1080(
    input wire i_clk,           // base clock (50.0 MHz)
    input wire i_rst,           // reset: restarts frame
    output wire o_hs,           // horizontal sync
    output wire o_vs,           // vertical sync
    output wire o_blanking,     // high during blanking interval
    output wire o_active,       // high during active pixel drawing
    output wire o_screenend,    // high for one tick at the end of screen
    output wire o_animate,      // high for one tick at end of active drawing
    output wire [11:0] o_x,      // current pixel x position
    output wire [10:0] o_y       // current pixel y position
    );

    // VGA timings https://timetoexplore.net/blog/video-timings-vga-720p-1080p
    localparam HS_STA = 88;              // horizontal sync start (Horiz. "Front porch")
    localparam HS_END = 88 + 44;         // horizontal sync end (Horiz. "Front porch" + "Sync pulse")
    localparam HA_STA = 88 + 44 + 148;    // horizontal active pixel start (Horiz. "Front porch" + "Sync pulse" + "Back porch")
    localparam VS_STA = 1080 + 4;        // vertical sync start (Vert. "visible area" + "Front porch")
    localparam VS_END = 1080 + 4 + 5;    // vertical sync end (Vert. "visible area" + "front porch" + "sync pulse")
    localparam VA_END = 1080;             // vertical active pixel end (Vert. "visible area")
    localparam LINE   = 2200;             // complete line (pixels) (Horiz. "Whole line")
    localparam SCREEN = 1125;             // complete screen (lines) (Vert. "Whole frame")

    reg [12:0] h_count;  // line position
    reg [11:0] v_count;  // screen position

    // generate sync signals (active low for 640x480)
    assign o_hs = ~((h_count >= HS_STA) & (h_count < HS_END));
    assign o_vs = ~((v_count >= VS_STA) & (v_count < VS_END));

    // keep x and y bound within the active pixels
    assign o_x = (h_count < HA_STA) ? 0 : (h_count - HA_STA);
    assign o_y = (v_count >= VA_END) ? (VA_END - 1) : (v_count);

    // blanking: high within the blanking period
    assign o_blanking = ((h_count < HA_STA) | (v_count > VA_END - 1));

    // active: high during active pixel drawing
    assign o_active = ~((h_count < HA_STA) | (v_count > VA_END - 1)); 

    // screenend: high for one tick at the end of the screen
    assign o_screenend = ((v_count == SCREEN - 1) & (h_count == LINE));

    // animate: high for one tick at the end of the final active pixel line
    assign o_animate = ((v_count == VA_END - 1) & (h_count == LINE));

    always @(posedge i_clk or negedge i_rst)
    begin
        if (i_rst == 0)  // reset to start of frame
        begin
            $display("Resetting...");
            h_count <= 'b0;
            v_count <= 'b0;
        end
        // once per pixel
        else
        begin
            if (h_count == LINE)  // end of line
            begin
                h_count <= 'b0;
                v_count <= v_count + 'b1;
            end
            else 
                h_count <= h_count + 'b1;

            if (v_count == SCREEN)  // end of screen
                v_count <= 'b0;
        end
    end
endmodule
