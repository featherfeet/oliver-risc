wire [7:0] MID = 8'd02;
wire [15:0] OID = 16'h544D;
wire [39:0] PNM = "SD02G";
wire [7:0] PRV = 8'h00;
wire [31:0] PSN = 32'h6543a238;
wire [11:0] MDT = {4'd15,8'h12};
wire [6:0] CID_CRC = 7'b1100001;//dummy
wire [127:0] CID = {MID, OID, PNM, PRV, PSN, 4'b0, MDT, CID_CRC, 1'b1};
