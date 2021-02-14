module spi_controller #(parameter CLOCK_DIVISION = 1000) (
    input reset_n,
    input CLOCK_50,

    input transmit_pulse,
    output reg transmit_done,
    input [7:0] byte_to_send,
    output reg [7:0] byte_received,

    output reg SCK,
    output reg COPI,
    input CIPO
);

// Clock divider.
reg spi_clock = 'b0;
reg [$clog2(CLOCK_DIVISION) - 1:0] spi_clock_divider_counter = 'b0;
reg previous_spi_clock = 'b0;
wire spi_clock_falling;
assign spi_clock_falling = (previous_spi_clock == 'b1) && (spi_clock == 'b0);
assign spi_clock_rising = (previous_spi_clock == 'b0) && (spi_clock == 'b1);
always @(posedge CLOCK_50)
begin
    if (reset_n == 'b0)
    begin
        spi_clock <= 'b0;
        previous_spi_clock <= 'b0;
        spi_clock_divider_counter <= 'b0;
    end
    else
    begin
        spi_clock_divider_counter <= spi_clock_divider_counter + 'b1;
        previous_spi_clock <= spi_clock;
        if (spi_clock_divider_counter == (CLOCK_DIVISION / 'd2))
        begin
            spi_clock <= ~spi_clock;
            spi_clock_divider_counter <= 'b0;
        end
    end
end

// Transmit and receive logic.
reg [3:0] bits_to_send = 'b0; // How many bits have yet to be transmitted.
reg [$clog2(CLOCK_DIVISION * 16) - 1:0] ticks_since_transmit_pulse = 'b0;
always @(posedge CLOCK_50)
begin
    if (reset_n == 'b0)
    begin
        bits_to_send <= 'b0;
        byte_received <= 'b0;
        transmit_done <= 'b0;
        ticks_since_transmit_pulse <= 'b0;
        SCK <= 'b0;
        COPI <= 'b0;
    end
    else
    begin
        ticks_since_transmit_pulse <= ticks_since_transmit_pulse + 'b1;
        if (bits_to_send > 'b0)
        begin
            // If the SPI clock is low, then put the bit to be sent on the COPI line.
            if (spi_clock_falling)
            begin
                SCK <= 'b0;
                COPI <= byte_to_send[bits_to_send - 'd1];
            end
            // If the SPI clock edge is rising, then raise the SCK line to cause the peripheral to read the bit that was sent on the COPI line. Also read a bit on the CIPO line.
            else if (spi_clock_rising && (ticks_since_transmit_pulse >= (CLOCK_DIVISION / 'd4))) // Check that at least CLOCK_DIVISION / 4 cycles have happened since the falling edge so that we don't pull SCK high right after latching COPI.
            begin
                SCK <= 'b1;
                byte_received[bits_to_send - 'd1] <= CIPO;
                bits_to_send <= bits_to_send - 'd1;
                if (bits_to_send == 'd1)
                    transmit_done <= 'd1;
            end
        end
        else if (transmit_pulse)
        begin
            bits_to_send <= 'd8;
            ticks_since_transmit_pulse <= 'b0;
            COPI <= byte_to_send[7];
        end
        else if (bits_to_send == 'b0)
        begin
            if (spi_clock_falling)
                SCK <= 'b0;
            transmit_done <= 'b0;
        end
    end
end

endmodule
