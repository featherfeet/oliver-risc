`define STATE_INITIALIZE          0
`define STATE_LOAD_TO_RAM         1
`define STATE_FETCH_OPERATION     2
`define STATE_FETCH_OPERAND1      3
`define STATE_FETCH_OPERAND2      4
`define STATE_EXECUTE_INSTRUCTION 5
`define STATE_RUN_INTERRUPT       6

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
`define OPERATION_CODE            14
`define OPERATION_ISR             15
`define OPERATION_ENDINT          16

`define NUM_REGISTERS             9
`define REGISTER_IP               registers[0]
`define REGISTER_A                registers[1]
`define REGISTER_B                registers[2]
`define REGISTER_C                registers[3]
`define REGISTER_D                registers[4]
`define REGISTER_E                registers[5]
`define REGISTER_F                registers[6]
`define REGISTER_G                registers[7]
`define REGISTER_IE               registers[8]

`define OPERATION_SIZE_BITS            8                                                              // 1 byte
`define OPERAND_SIZE_BITS              32                                                             // 4 bytes
`define INSTRUCTION_SIZE_BITS          (OPERATION_SIZE_BITS + OPERAND_SIZE_BITS + OPERAND_SIZE_BITS)  // 9 bytes
`define OPERATION_SIZE_BYTES           1
`define OPERAND_SIZE_BYTES             4
`define INSTRUCTION_SIZE_BYTES         (`OPERATION_SIZE_BYTES + `OPERAND_SIZE_BYTES + `OPERAND_SIZE_BYTES)

`define NUM_INTERRUPTS            8
