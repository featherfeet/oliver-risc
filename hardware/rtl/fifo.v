module fifo #(parameter ITEM_SIZE_BITS = 32, parameter FIFO_SIZE = 10) (
    input CLOCK_50,
    input RST_N,
    input [ITEM_SIZE_BITS - 1:0] data_in,
    input write,
    output reg [ITEM_SIZE_BITS - 1:0] data_out,
    input read,
    output empty,
    output full
);

reg [$clog2(FIFO_SIZE) - 1:0] write_pointer;
reg [$clog2(FIFO_SIZE) - 1:0] read_pointer;
reg [ITEM_SIZE_BITS - 1:0] items [FIFO_SIZE - 1:0];

assign full = ((write_pointer + 1) == read_pointer) ? 1 : 0;
assign empty = (write_pointer == read_pointer) ? 1 : 0;

always @(posedge CLOCK_50)
begin
    if (RST_N == 0)
    begin
        write_pointer <= 'b0;
        read_pointer <= 'b0;
        for (i = 0; i < FIFO_SIZE; i++)
            items[i] = 'b0;
    end
    else if (write_pointer == FIFO_SIZE)
    begin
        write_pointer <= 'b0;
        items[0] <= data_in;
    end
    else if (read_pointer == FIFO_SIZE)
    begin
        read_pointer <= 'b0;
        data_out <= items[0];
    end
    else
    begin
        if (write)
        begin
            items[write_pointer] <= data_in;
            write_pointer <= write_pointer + 'b1;
        end
        if (read)
        begin
            data_out <= items[read_pointer];
            read_pointer <= read_pointer + 'b1;
        end
    end
end

endmodule
