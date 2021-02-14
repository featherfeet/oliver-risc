//SD Card, SPI mode, verilog simulation model
//
//Version history:
//1.0        2016.06.13        1st released by tsuhuAI.chan@gmail.com
//                        Most of the Card information is referenced
//                        from Toshiba 2G and 256MB SD card
//

//parsed commands:
// CMD0, CMD8, CMD9, CMD10, CMD12, CMD13, CMD16, CMD17, CMD18,
// CMD24, CMD25, CMD27, CMD55, CMD51, CMD58, ACMD13, ACMD51
//Not parsed command: (still responses based on spec)
// CMD1, CMD6, CMD9, CMD10, CMD30, CMD32, CMD33, CMD42, CMD56,
// CMD59, ACMD22, ACMD23, ACMD41, ACMD42

//Memory size of this model should be 2GB, however only 2MB is
// implemened to reduce system memory required during simulation.
// The initial value of all internal memory is word_address+3.

//Detail command status
// 1. card response of ACMD51: not sure
// 2. lock/unlock: not implemented
// 3. erase: not implemented
// 4. read multiple block: seems verify OK
// 5. write single block: seems verify OK
// 6. write multiple block: not verified
// 7. partial access: not implemented
// 8. misalign: no check
// 9. SDHC address: not verified

`timescale 1ns/1ns
`define UD 1
module spi_sd_model        (rstn, ncs, sclk, miso, mosi);
input        rstn;
input        ncs;
input        sclk;
input        mosi;
output        miso;

parameter        tNCS                = 1;//0 ~
parameter        tNCR                = 1;//1 ~ 8
parameter        tNCX                = 0;//0 ~ 8
parameter        tNAC                = 1;//from CSD
parameter        tNWR                = 1;//1 ~
parameter        tNBR                = 0;//0 ~
parameter        tNDS                = 0;//0 ~
parameter        tNEC                = 0;//0 ~
parameter        tNRC                = 1;//

parameter MEM_SIZE        = 2048*1024;//2M
parameter PowerOff        = 0;
parameter PowerOn        = 1;
parameter IDLE                = 2;
parameter CmdBit47        = 3;
parameter CmdBit46        = 4;
parameter CommandIn        = 5;
parameter CardResponse        = 6;
parameter ReadCycle        = 7;
parameter WriteCycle        = 8;
parameter DataResponse        = 9;
parameter CsdCidScr        = 10;
parameter WriteStop        = 11;
parameter WriteCRC        = 12;

integer i = 0;//counter index
integer j = 0;//counter index
integer k = 0;//for MISO (bit count of a byte)
integer m = 0;//for MOSI (bit count during CMD12)

reg miso;
reg [7:0] flash_mem [0:MEM_SIZE-1];
reg [7:0] token;//captured token during CMD24, CMD25
reg [15:0] crc16_in;
reg [6:0] crc7_in;
reg [7:0] sck_cnt;//74 sclk after power on
reg [31:0] csd_reg;
reg [31:0] block_cnt;
reg init_done;//must be defined before ocr.v
reg [3:0] st;//SD Card internal state
reg app_cmd;//
reg [7:0] datain;
reg [511:0] ascii_command_state;
reg [2:0] ist;//initialization stage
reg [45:0] cmd_in, serial_in;
wire [5:0] cmd_index = cmd_in[45:40];
wire [31:0] argument = cmd_in[39:8];
wire [6:0] crc = cmd_in[7:1];
wire read_single = (cmd_index == 17);
wire read_multi = (cmd_index == 18);
wire write_single = (cmd_index == 24);
wire write_multi = (cmd_index == 25);
wire pgm_csd = (cmd_index == 27);
wire send_csd = (cmd_index == 9);
wire send_cid = (cmd_index == 10);
wire send_scr = (cmd_index == 51) && app_cmd;
wire read_cmd = read_single | read_multi;
wire write_cmd = write_single | write_multi;
wire mem_rw = read_cmd | write_cmd;
reg [31:0] start_addr;
reg [31:0] block_len;
reg [7:0] capture_data;//for debugging
reg [3:0] VHS;//Input VHS through MOSI
reg [7:0] check_pattern;//for CMD8
wire [3:0] CARD_VHS = 4'b0001;//SD card accept voltage range
wire VHS_match = (VHS == CARD_VHS);
reg [1:0] multi_st;//for CMD25
reg [45:0] serial_in1;//for CMD25
wire [5:0] cmd_in1 = serial_in1[45:40];//for CMD25
wire stop_transmission = (cmd_in1 == 12);//for CMD25

//Do not change the positions of these include files
//Also, ocr.v must be included before csd.v
`include "sdspi/ocr.v"
`include "sdspi/csd.v"
`include "sdspi/cid.v"
`include "sdspi/scr.v"
`include "sdspi/ssr.v"
`include "sdspi/csr.v"
//
task R1;
input [7:0] data;
begin
   $display("   SD R1: 0x%2h at %0t ns",data, $realtime);
   k = 0;
   while (k < 8) begin
      @(negedge sclk) miso = data[7-k];
      k = k + 1;
   end
end
endtask
   
task R1b;
input [7:0] data;
begin
   $display("   SD R1B: 0x%2h at %0t ns",data, $realtime);
   k = 0;
   while (k < 8) begin
      @(negedge sclk) miso = data[7-k];
      k = k + 1;
   end
end
endtask

task R2;
input [15:0] data;
begin
   $display("   SD R2: 0x%2h at %0t ns",data, $realtime);
   k = 0;
   while (k < 16) begin
      @(negedge sclk) miso = data[15-k];
      k = k + 1;
   end
end
endtask

task R3;
input [39:0] data;
begin
   $display("   SD R3: 0x%10h at %0t ns",data, $realtime);
   for (k =0; k < 40; k = k + 1) begin
      @(negedge sclk) ;
          miso = data[39 - k];
   end
end
endtask

task R7;
input [39:0] data;
begin
   $display("   SD R7: 0x%10h at %0t ns",data,$realtime);
   k = 0;
   while (k < 40) begin
      @(negedge sclk) miso = data[39-k];
      k = k + 1;
   end
end
endtask

task DataOut;
input [7:0] data;
begin
   $display("   SD DataOut 0x%2H at %0t ns",data, $realtime);
   k = 0;
   while (k < 8) begin       @(negedge sclk) miso = data[7 - k];       k = k + 1;    end end endtask     task DataIn; begin    for (k = 7; k >= 0; k = k - 1) begin
      @(posedge sclk) capture_data[k] = mosi;
   end
   $display("   SD DataIn: %2h at %0t ns",capture_data, $realtime);
end
endtask

always @(*) begin
   if (pgm_csd) csd_reg = argument;
end

task CRCOut;
input [15:0] data;
begin
   $display("   SD CRC Out 0x%4H at %0t ns",data, $realtime);
   k = 0;
   while (k < 16) begin
      @(negedge sclk) miso = data[15 - k];
      k = k + 1;
   end
end
endtask

task TokenOut;
input [7:0] data;
begin
   $display("   SD TokenOut 0x%2H at %0t ns",data, $realtime);
   k = 0;
   while (k < 8) begin
      @(negedge sclk) miso = data[7 - k];
      k = k + 1;
   end
end
endtask

always @(*) begin
   if (~rstn) app_cmd = 1'b0;
   else if (cmd_index == 55 && st == IDLE) app_cmd = 1;
   else if (cmd_index != 55 && st == IDLE) app_cmd = 0;
end

always @(*) begin
   if (sdsc && mem_rw) start_addr = argument;
   else if (v2sdhc && mem_rw) start_addr = argument * block_len;
end

always @(*) begin
   if (v2sdhc) block_len = 512;
   else if (sdsc && cmd_index == 0) block_len = (READ_BL_LEN == 9) ? 512 : (READ_BL_LEN == 10) ? 1024 : 2048;
   else if (sdsc && cmd_index == 16) block_len = argument[31:0];
end

always @(*) begin
   if (cmd_index == 8) VHS = argument[11:8];
   if (cmd_index == 8) check_pattern = argument[7:0];
end

always @(*) begin
   if (ist == 0 && cmd_index == 0) begin
      $display("iCMD0 at %0t ns",$realtime);
      ist <= 1;
   end
   if (ist == 1 && cmd_index == 8) begin
      $display("iCMD8 at %0t ns",$realtime);
      ist <= 2;
   end
   if (ist == 2 && cmd_index == 58) begin
      $display("iCMD58 at %0t ns",$realtime);
      ist <= 3;
   end
   if (ist == 3 && cmd_index == 55) begin
      $display("iCMD55 at %0t ns",$realtime);
      ist <= 4;
   end
   if (ist == 4 && cmd_index == 41) begin
      $display("iACMD41 at %0t ns",$realtime);
      ist <= 5;
   end
   if (ist == 5 && cmd_index == 58 && CSD_VER == 1) begin
      $display("iCMD58 at %0t ns",$realtime);
      ist <= 6;
   end
   else if (ist == 5 && CSD_VER == 0) ist <= 6;
   if (ist == 6 && st == IDLE) begin
      $display("Init Done at %0t ns",$realtime);
      if (v2sdhc) $display("Ver 2, SDHC detected");
      else if (v2sdsc) $display("Ver 2, SDSC detected");
      else if (v1sdsc) $display("Ver 1, SDSC detected");
      init_done = 1;
      ist <= 7;
   end
end

always @(*) begin
   if (st == ReadCycle) begin
      case (multi_st)
        0:
                begin
                   @(posedge sclk) if (~ncs && ~mosi) multi_st = 1; else multi_st = 0;
                end
        1:
                begin
                   @(posedge sclk); if (mosi) multi_st = 2; else multi_st = 1;
                end
        2:
                begin
                   m = 0;
                   while (m < 46) begin
                      @(posedge sclk) serial_in1[45-m] = mosi;
                      #1 m = m + 1;
                   end
                     multi_st = 0;
                end
      endcase
   end
end
   
always @(*) begin
   case (st)
        PowerOff:
                begin
                   @(posedge rstn) st <= PowerOn;
                end
        PowerOn:
                begin
                   if (sck_cnt < 73) begin
                      @(posedge sclk) sck_cnt = sck_cnt + 1;
                   end
                   if (sck_cnt == 73) st <= IDLE; else st <= PowerOn;
                end
        IDLE:
                begin
                   @(posedge sclk) if (~ncs && ~mosi) st <= CmdBit46; else st <= IDLE;
                end
        CmdBit46:
                begin
                   @(posedge sclk); if (mosi) st <= CommandIn; else st <= CmdBit46;                 end         CommandIn://capture command input -> NCR
                begin
                  for (i = 0; i < 46; i = i + 1)  begin
                     @(posedge sclk) ;serial_in[45-i] = mosi;
                  end
                  cmd_in = serial_in;
                  repeat (tNCR*8) @(posedge sclk);
                  st <= CardResponse;                 end         CardResponse://CardResponse -> delay
                begin
                   if (~app_cmd) begin
                      case (cmd_index)
                      6'd0:        R1(8'b0000_0001);
                      6'd1,
                      6'd6,
                      6'd16,
                      6'd17,
                      6'd18,
                      6'd24,
                      6'd25,
                      6'd27,
                      6'd30,
                      6'd32,
                      6'd33,
                      6'd42,
                      6'd55,
                      6'd56,
                      6'd59:         R1(8'b0110_1010);
                      6'd9,
                      6'd10:    if (init_done) R1(8'b1010_0001); else R1(0000_0100);
                      6'd12,
                      6'd28,
                      6'd29,
                      6'd38:         R1b(8'b0011_1010);
                      6'd8:         if (VHS_match) begin
                                   $display("   VHS match");
                                   R7({8'h01 | (VHS_match ? 8'h04 : 8'h00), 20'h00000, VHS, check_pattern});
                                end
                                else begin
                                   $display("   VHS not match");
                                   R7({8'h01 | (VHS_match ? 8'h04 : 8'h00), 20'h00000, 4'b0, check_pattern});
                                end
                      6'd13:         R2({1'b0, OUT_OF_RANGE, ADDRESS_ERROR, ERASE_SEQ_ERROR, COM_CRC_ERROR,
                                    ILLEGAL_COMMAND, ERASE_RESET, IN_IDLE_ST, OUT_OF_RANGE | CSD_OVERWRITE,
                                    ERASE_PARAM, WP_VIOLATION, CARD_ECC_FAILED, CC_ERROR, ERROR,
                                    WP_ERASE_SKIP | LOCK_UNLOCK_FAILED, CARD_IS_LOCKED});
                      6'd58:         R3({8'b0000_0000, OCR});
                      default:        R1(8'b0000_0100);//illegal command
                      endcase
                   end
                   else if (~read_multi) begin
                      case (cmd_index)
                      6'd22,
                      5'd23,
                      6'd41,
                      6'd42,
                      6'd51:        R1(8'b0000_0000);
                      6'd13:        R2({1'b0, OUT_OF_RANGE, ADDRESS_ERROR, ERASE_SEQ_ERROR, COM_CRC_ERROR,
                                   ILLEGAL_COMMAND, ERASE_RESET, IN_IDLE_ST, OUT_OF_RANGE | CSD_OVERWRITE,
                                   ERASE_PARAM, WP_VIOLATION, CARD_ECC_FAILED, CC_ERROR, ERROR,
                                   WP_ERASE_SKIP | LOCK_UNLOCK_FAILED, CARD_IS_LOCKED});
                      default:        R1(8'b0000_0100);//illegal command
                      endcase
                   end
                   @(posedge sclk);
                   if (read_cmd && init_done && ~stop_transmission) begin
                      miso = 1;
                      repeat (tNAC*8) @(posedge sclk);
                      st <= ReadCycle;
                   end
                   else if (read_cmd && init_done && stop_transmission) begin
                      miso = 1;
                      repeat (tNEC*8) @(posedge sclk);
                      st <= IDLE;
                   end
                   else if ((send_csd || send_cid || send_scr) && init_done) begin
                      miso = 1;
                      repeat (tNCX*8) @(posedge sclk);
                      st <= CsdCidScr;
                   end
                   else if (write_cmd && init_done) begin
                      miso = 1;
                      repeat (tNWR*8) @(posedge sclk);
                      st <= WriteCycle;
                   end
                   else begin
                      repeat (tNEC*8) @(posedge sclk);
                      st <= IDLE;
                   end
                end
        CsdCidScr:
                begin
                   if (send_csd) begin
                      DataOut(CSD[127:120]);
                      DataOut(CSD[119:112]);
                      DataOut(CSD[111:104]);
                      DataOut(CSD[103:96]);
                      DataOut(CSD[95:88]);
                      DataOut(CSD[87:80]);
                      DataOut(CSD[79:72]);
                      DataOut(CSD[71:64]);
                      DataOut(CSD[63:56]);
                      DataOut(CSD[55:48]);
                      DataOut(CSD[47:40]);
                      DataOut(CSD[39:32]);
                      DataOut(CSD[31:24]);
                      DataOut(CSD[23:16]);
                      DataOut(CSD[15:8]);
                      DataOut(CSD[7:0]);
                   end
                   else if (send_cid) begin
                      DataOut(CID[127:120]);
                      DataOut(CID[119:112]);
                      DataOut(CID[111:104]);
                      DataOut(CID[103:96]);
                      DataOut(CID[95:88]);
                      DataOut(CID[87:80]);
                      DataOut(CID[79:72]);
                      DataOut(CID[71:64]);
                      DataOut(CID[63:56]);
                      DataOut(CID[55:48]);
                      DataOut(CID[47:40]);
                      DataOut(CID[39:32]);
                      DataOut(CID[31:24]);
                      DataOut(CID[23:16]);
                      DataOut(CID[15:8]);
                      DataOut(CID[7:0]);
                   end
                   else if (send_scr) begin
                      DataOut(SCR[63:56]);
                      DataOut(SCR[55:48]);
                      DataOut(SCR[47:40]);
                      DataOut(SCR[39:32]);
                      DataOut(SCR[31:24]);
                      DataOut(SCR[23:16]);
                      DataOut(SCR[15:8]);
                      DataOut(SCR[7:0]);
                   end
                   @(posedge sclk);
                   repeat (tNEC*8) @(posedge sclk);
                   st <= IDLE;                 end         ReadCycle://Start Token -> Data -> CRC(stucked at 16'hAAAA) -> NEC(or NAC)  
                begin
                   if (read_single) begin
                      TokenOut(8'hFE);//Start Token
                      for (i = 0; i < block_len; i = i + 1) begin
                         DataOut(flash_mem[start_addr+i]);
                      end
                      CRCOut(16'haaaa);//CRC[15:0]
                      @(posedge sclk);
                      repeat (tNEC*8) @(negedge sclk);
                      st <= IDLE;
                   end
                   else if (read_multi) begin:loop_1
                      for (j = 0; 1 ; j  = j + 1) begin
                         TokenOut(8'hFE);//Start Token
                         i = 0;
                         while (i < block_len) begin
                            DataOut(flash_mem[start_addr+i+block_len*j]);
                            i = i + 1;
                         end
                         CRCOut(16'haaaa);
                         if (stop_transmission) begin//check stop_tx at end of each data block?
                            repeat (tNEC*8) @(posedge sclk);
                            $display("STOP transmission");
                            @(posedge sclk) begin
                                  R1(8'b0000_0000);
                                  repeat (tNEC*8) @(posedge sclk);
                                  st <= IDLE;
                                  disable loop_1;
                            end
                         end
                         else repeat (tNAC*8) @(negedge sclk);
                      end
                      repeat (tNEC*8) @(posedge sclk);
                      st <= IDLE;                    end                                     end         WriteCycle://Start Token -> Data
                begin
                   i = 0;
                   while (i < 8) begin
                      @(posedge sclk)  token[7-i] = mosi;
                      i = i + 1;
                   end
                   if (token == 8'hfe && write_single) $display("Single Write Start Token OK");
                   else if (token != 8'hfe && write_single) $display("Single Write Start Token NG");
                   if (token == 8'hfc && write_multi)  $display("Multiblock Write Start Token OK");
                   else if ((token != 8'hfc && token != 8'hfd) && write_multi)  $display("Multiblock Write Start Token NG");
                   if (token == 8'hfd && write_multi) begin
                      $display("Multiblock Write Stop Token");
                      st <= WriteStop;
                   end
                   i = 0;
                   while (i < block_len) begin
                      DataIn;
                      flash_mem[start_addr + i] = capture_data;
                      i = i + 1;
                     end
                   st <= WriteCRC;
                end
        WriteCRC://Capture incoming CRC of data
                begin
                   i = 0;
                   while (i < 16) begin
                      @(posedge sclk) crc16_in[15-i] = mosi;
                      i = i + 1;
                   end
                   st <= DataResponse;
                end
        DataResponse://All clock after data response CRC
                begin
                   DataOut(8'b00000101);
                   @(negedge sclk); miso = 0;
                   repeat (tNEC*8) @(negedge sclk);

                   repeat  (tNDS*8) @(negedge sclk);
                   miso = 1'bz;
                   @(negedge sclk);
                   miso = 1'b0;
                   repeat (100) @(negedge sclk);
                   miso = 1;
                   @(negedge sclk);
                   miso = 1;
                   repeat (5) @(posedge sclk);
                   if (write_single) st <= IDLE;
                   else if (write_multi) st <= WriteCycle;
                end
        WriteStop:
                begin
                   repeat (tNBR*8) @(posedge sclk);
                   miso = 0;
                   repeat (tNEC*8) @(posedge sclk);
                   repeat (tNDS*8) @(posedge sclk) miso = 1'bz;
                   @(posedge sclk) miso = 1'b0;
                   #1000000;//1ms processing time for each block programming
                   @(posedge sclk) miso = 1'b1;
                   repeat (tNEC*8) @(posedge sclk);
                   @(posedge sclk);
                   st <= IDLE;
                end
        default: st <= IDLE;
   endcase
end
       
always @(st) begin
   case (st)
        PowerOff:        ascii_command_state = "PowerOff";
        PowerOn:        ascii_command_state = "PowerOn";
        IDLE:                ascii_command_state = "IDLE";
        CmdBit47:        ascii_command_state = "CmdBit47";
        CmdBit46:        ascii_command_state = "CmdBit46";
        CommandIn:        ascii_command_state = "CommandIn";
        CardResponse:        ascii_command_state = "CardResponse";
        ReadCycle:        ascii_command_state = "ReadCycle";
        WriteCycle:        ascii_command_state = "WriteCycle";
        DataResponse:        ascii_command_state = "DataResponse";
        CsdCidScr:        ascii_command_state = "CsdCidScr";
        WriteStop:        ascii_command_state = "WriteStop";
        WriteCRC:        ascii_command_state = "WriteCRC";
        default:          ascii_command_state = "ERROR";
   endcase
end

initial
   begin
      sck_cnt = 0;
      cmd_in = 46'h3fffffffffff;
      serial_in = 46'h3f0f0f0f0f0e;
      crc16_in = 16'h0;
      crc7_in = 7'h0;
      token = 8'h0;
      st <= PowerOff;
      miso = 1'b1;
      init_done = 0;
      ist = 0;
      capture_data = 8'hff;
      start_addr = 32'h0;
      VHS = 4'h0;
      serial_in1 = 46'h0;
      multi_st = 0;
      block_len = 0;
      for (i = 0; i < MEM_SIZE - 1; i = i + 1) begin
         flash_mem[i] = i[7:0]+3;
      end
   end

endmodule
