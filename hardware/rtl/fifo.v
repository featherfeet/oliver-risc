module fifo #(parameter ITEM_SIZE_BITS = 32, parameter FIFO_SIZE = 10) (
    input CLOCK_50,
    input RST_N,
    input [ITEM_SIZE_BITS - 1:0] data_in,
    input write,
    output reg [ITEM_SIZE_BITS - 1:0] data_out,
    input read,
    output wire empty,
    output wire full
);

reg [$clog2(FIFO_SIZE) - 1:0] write_pointer;
reg [$clog2(FIFO_SIZE) - 1:0] read_pointer;
reg [ITEM_SIZE_BITS - 1:0] items [FIFO_SIZE - 1:0];

reg [$clog2(FIFO_SIZE) - 1:0] current_fifo_size;

assign full = (current_fifo_size == FIFO_SIZE) ? 1 : 0;
assign empty = (current_fifo_size == 'b0) ? 1 : 0;

integer i;

always @(posedge CLOCK_50)
begin
    if (RST_N == 0)
    begin
        write_pointer <= 'b0;
        read_pointer <= 'b0;
        data_out <= 'b0;
        current_fifo_size <= 'b0;
        for (i = 0; i < FIFO_SIZE; i++)
            items[i] = 'b0;
    end
    else
    begin
        if (write && ~full)
        begin
            current_fifo_size <= current_fifo_size + 'b1;
            items[write_pointer] <= data_in;
            write_pointer <= write_pointer + 'b1;
            if (write_pointer == FIFO_SIZE - 'b1)
                write_pointer <= 'b0;
        end
        if (read && ~empty)
        begin
            current_fifo_size <= current_fifo_size - 'b1;
            data_out <= items[read_pointer];
            read_pointer <= read_pointer + 'b1;
            if (read_pointer == FIFO_SIZE - 'b1)
                read_pointer <= 'b0;
        end
    end
end

endmodule
