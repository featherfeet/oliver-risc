wire [1:0] CSD_VER = 2'b00;//Ver1.0
wire [7:0] TAAC = {1'b0, 4'd7, 3'd2};//3.0*100ns
wire [7:0] NSAC = 8'd101;
wire [7:0] TRAN_SPEED = 8'h32;
wire [3:0] READ_BL_LEN = 4'd11;//2^READ_BL_LEN, 2048bytes
wire READ_BL_PARTIAL = 1'b1;//always 1 in SD card
wire WRITE_BLK_MISALIGN = 1'b0;//crossing physical blocak boundaries is invalid
wire READ_BLK_MISALIGN = 1'b0;//crossing physical blocak boundaries is invalid
wire DSR_IMP = 1'b0;//no DSR implemented
wire [11:0] C_SIZE = 2047;
wire [2:0] VDD_R_CURR_MIN = 3'd1;//1mA
wire [2:0] VDD_R_CURR_MAX = 3'd2;//10mA
wire [2:0] VDD_W_CURR_MIN = 3'd1;//1mA
wire [2:0] VDD_W_CURR_MAX = 3'd2;//10mA
wire [2:0] C_SIZE_MULT = 3'd7;//MULT=512
wire ERASE_BLK_EN = 1'b0;//Erase in unit of SECTOR_SIZE
wire [6:0] SECTOR_SIZE = 7'd127;//128 WRITE BLOCK
wire [6:0] WP_GRP_SIZE = 7'd127;//128
wire WP_GRP_ENABLE = 1'b0;//no GROUP WP
wire [2:0] R2W_FACTOR = 3'd0;
wire [3:0] WRITE_BL_LEN = READ_BL_LEN;
wire WRITE_BL_PARTIAL = 1'b0;//
wire iFILE_FORMAT_GRP = 1'b0;
wire iCOPY = 1'b0;
wire iPERM_WRITE_PROTECT = 1'b0;//DISABLE PERMENTAL WRITE PROTECT
wire iTMP_WRITE_PROTECT = 1'b0;//
wire [1:0] iFILE_FORMAT = 1'b0;//
wire [6:0] iCSD_CRC = 7'b1010001;//dummy

reg FILE_FORMAT_GRP;
reg COPY;
reg PERM_WRITE_PROTECT;
reg TMP_WRITE_PROTECT;
reg [1:0] FILE_FORMAT;
reg [6:0] CSD_CRC;

wire v1sdsc = (CSD_VER == 0) & ~CCS;//Ver 1, SDSC
wire v2sdsc = (CSD_VER == 1) & ~CCS;//Ver 2, SDSC
wire v2sdhc = (CSD_VER == 1) & CCS;//Ver 2, SDHC
wire sdsc = ~CCS;

always @(*) begin
   if (~pgm_csd) begin
      FILE_FORMAT_GRP = iFILE_FORMAT_GRP;
      COPY = iCOPY; 
      PERM_WRITE_PROTECT = iPERM_WRITE_PROTECT ;
      TMP_WRITE_PROTECT = iTMP_WRITE_PROTECT;
      FILE_FORMAT = iFILE_FORMAT;
      CSD_CRC = iCSD_CRC;
   end
   else begin
      FILE_FORMAT_GRP = argument[15];
      COPY = argument[14];
      PERM_WRITE_PROTECT = argument[13];
      TMP_WRITE_PROTECT = argument[12];
      FILE_FORMAT = argument[11:10];
      CSD_CRC = argument[7:1];
   end
end
      
wire [127:0] CSD = {CSD_VER, 6'b0, TAAC, NSAC, TRAN_SPEED, 12'b0101_1011_0101, READ_BL_LEN,
             READ_BL_PARTIAL, WRITE_BLK_MISALIGN, READ_BLK_MISALIGN, DSR_IMP,
             2'b0, C_SIZE, VDD_R_CURR_MIN, VDD_R_CURR_MAX, VDD_W_CURR_MIN, 
             VDD_W_CURR_MAX, C_SIZE_MULT, ERASE_BLK_EN, SECTOR_SIZE,
             WP_GRP_SIZE, WP_GRP_ENABLE, 2'b00, R2W_FACTOR, WRITE_BL_LEN, 
             WRITE_BL_PARTIAL, 5'b0, FILE_FORMAT_GRP, COPY, PERM_WRITE_PROTECT, 
             TMP_WRITE_PROTECT, FILE_FORMAT, 2'b0, CSD_CRC, 1'b1};
