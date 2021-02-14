wire [1:0] DAT_BUS_WIDTH = 2'b00;//1bit
wire SECURE_MODE = 1'b0;//not in secure mode
wire [15:0] SD_CARD_TYPE = 16'h0000;//regular SD
wire [31:0] SIZE_OF_PROTECTED_AREA = 32'd2048;//
//protected area = SIZE_OF_PROTECTED_AREA * MULT * BLOCK_LEN
wire [7:0] SPEED_CLASS = 8'h4;//class 10
wire [7:0] PERFORMANCE_MOVE = 8'd100;//100MB/sec
wire [3:0] AU_SIZE = 7;//1MB
wire [15:0] ERASE_SIZE = 16'd100;//Erase 100 AU
wire [5:0] ERASE_TIMEOUT = 16'd50;//50 sec
wire [1:0] ERASE_OFFSET = 0;//0 sec

wire [511:0] SSR = {DAT_BUS_WIDTH, SECURE_MODE, 6'b0, 6'b0, SD_CARD_TYPE, SIZE_OF_PROTECTED_AREA, SPEED_CLASS, PERFORMANCE_MOVE, AU_SIZE, 4'b0, ERASE_SIZE, ERASE_TIMEOUT, ERASE_OFFSET, 400'b0};
