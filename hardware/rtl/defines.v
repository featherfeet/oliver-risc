`define STATE_INITIALIZE          0
`define STATE_LOAD_TO_RAM         1
`define STATE_FETCH_OPERATION     2
`define STATE_FETCH_OPERAND1      3
`define STATE_FETCH_OPERAND2      4
`define STATE_EXECUTE_INSTRUCTION 5
`define STATE_RUN_INTERRUPT       6
`define STATE_ADD_INTERRUPTS      7

`define PROGRAM_ROM_READ_STATE_SETUP 0
`define PROGRAM_ROM_READ_STATE_FINISH 1

`define GPU_ACCESS_STATE_SETUP    0
`define GPU_ACCESS_STATE_FINISH   1

`define INTERRUPT_FIFO_ACCESS_STATE_SETUP 0
`define INTERRUPT_FIFO_ACCESS_STATE_WAIT 1
`define INTERRUPT_FIFO_ACCESS_STATE_FINISH 2

`define DIVISION_CYCLES           15

`define KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_START  0
`define KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_READ_END    1
`define KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_START 2
`define KEYBOARD_SCANCODE_FIFO_ACCESS_STATE_WRITE_END   3

`define SD_CARD_SPI_ACCESS_STATE_WRITE 0
`define SD_CARD_SPI_ACCESS_STATE_WAIT  1

`define OPERATION_NOP             0
`define OPERATION_LOAD            1
`define OPERATION_STORE           2
`define OPERATION_ADD             3
`define OPERATION_SUB             4
`define OPERATION_OUT             5
`define OPERATION_IN              6
`define OPERATION_MOV             7
`define OPERATION_CMP             8
`define OPERATION_JMPL            9
`define OPERATION_JMPE            10
`define OPERATION_JMPG            11
`define OPERATION_RST             12
`define OPERATION_HALT            13
`define OPERATION_ISR             14
`define OPERATION_INT             15
`define OPERATION_ENDINT          16
`define OPERATION_RLOAD           17
`define OPERATION_RSTORE          18
`define OPERATION_CLOAD           19
`define OPERATION_MULT            20
`define OPERATION_DIV             21
`define OPERATION_OR              22
`define OPERATION_AND             23
`define OPERATION_XOR             24
`define OPERATION_NOT             25

`define NUM_REGISTERS             10
`define REGISTER_IP               registers[0]
`define REGISTER_A                registers[1]
`define REGISTER_B                registers[2]
`define REGISTER_C                registers[3]
`define REGISTER_D                registers[4]
`define REGISTER_E                registers[5]
`define REGISTER_F                registers[6]
`define REGISTER_G                registers[7]
`define REGISTER_IE               registers[8]
`define REGISTER_IR               registers[9]

`define OPERATION_SIZE_BITS            8                                                              // 1 byte
`define OPERAND_SIZE_BITS              32                                                             // 4 bytes
`define INSTRUCTION_SIZE_BITS          (OPERATION_SIZE_BITS + OPERAND_SIZE_BITS + OPERAND_SIZE_BITS)  // 9 bytes
`define OPERATION_SIZE_BYTES           1
`define OPERAND_SIZE_BYTES             4
`define INSTRUCTION_SIZE_BYTES         (`OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES + `OPERAND_SIZE_BYTES)

`define NUM_INTERRUPTS            8
`define INTERRUPT_TYPE_KEY        'b0

`define INTERRUPT_VALUE_PORT      `GPU_TEXT_BUFFER_LENGTH  // The I/O port for interrupt value is right after the GPU port-mapped I/O.
`define SD_CARD_SPI_PORT          (`GPU_TEXT_BUFFER_LENGTH + 'd1) // The I/O port for reading and writing to the SPI bus that communicates with the SD card.
`define SD_CARD_CLOCK_SELECT_PORT (`GPU_TEXT_BUFFER_LENGTH + 'd2) // The I/O port for controlling the CS line of the SPI bus that communicates with the SD card.
