wire CCS = 1'b0;
wire [31:0] OCR = {init_done, CCS, 5'b0, 1'b0, 6'b111111, 3'b000, 12'h000};//3.0~3.6V, no S18A
