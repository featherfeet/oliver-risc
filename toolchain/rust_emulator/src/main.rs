use std::fs;
use std::env;
use std::convert::TryInto;

type RawProcessorOperand = u32;
const OPERATION_SIZE: usize = 1; // bytes
const OPERAND_SIZE: usize = 4; // bytes
const INSTRUCTION_SIZE: usize = OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE; // bytes

const NUM_REGISTERS: usize = 8; // registers
const TOTAL_RAM_SIZE_BYTES: usize = 8_000_000; // bytes
const GPU_TEXT_DISPLAY_ROWS: usize = 67; // rows of text
const GPU_TEXT_DISPLAY_COLUMNS: usize = 240; // columns of text
const GPU_TEXT_BUFFER_LENGTH: usize = GPU_TEXT_DISPLAY_ROWS * GPU_TEXT_DISPLAY_COLUMNS; // characters of text

#[derive(Debug, Clone, Copy)]
enum Register {
    IP = 0,
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7
}

#[derive(Debug, Clone, Copy)]
enum Operation {
	NOP = 0,
	LOAD = 1,
	STORE = 2,
	ADD = 3,
	SUB = 4,
	OUT = 5,
	IN = 6,
	MOV = 7,
	CMP = 8,
	JMPL = 9,
	JMPE = 10,
	JMPG = 11,
	RST = 12,
	HALT = 13,
    ISR = 14,
    INT = 15,
    ENDINT = 16,
    RLOAD = 17,
    RSTORE = 18,
    CLOAD = 19,
    MULT = 20,
    DIV = 21,
    OR = 22,
    AND = 23,
    XOR = 24,
    NOT = 25
}

fn main() {
    // Read in binary file.
    let args: Vec<String> = env::args().collect();
    let raw_binary_file_path = args.get(1).expect("No binary file provided!");
    let mut raw_binary: Vec::<u8> = fs::read(raw_binary_file_path).unwrap();
    raw_binary.resize(TOTAL_RAM_SIZE_BYTES, 0_u8);

    // Define registers.
    let mut registers: Vec<RawProcessorOperand> = vec![0; NUM_REGISTERS];

    // Allocate memory to simulate the text buffer of the GPU.
    let mut gpu_text_buffer: Vec<u8> = vec![' ' as u8; GPU_TEXT_BUFFER_LENGTH];

    // Read the first OPERAND_SIZE bytes of the binary, which contain the length of the .data:
    // section of the binary (which is also the offset to the start of the .code: section).
    let start_of_code_section_offset: RawProcessorOperand = RawProcessorOperand::from_le_bytes(raw_binary[0..OPERAND_SIZE].try_into().expect("ERROR: Emulator's OPERAND_SIZE must match the number of bytes in the RawProcessorOperand type.")) + (OPERAND_SIZE as RawProcessorOperand); // We add OPERAND_SIZE to the offset to compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data: section.

    // Start code execution.
    registers[Register::IP as usize] = start_of_code_section_offset;
    loop {
        let register_ip = registers[Register::IP as usize] as usize;
        // Fetch operation and operands.
        let operation: u8 = raw_binary[register_ip];
        let operand1_bytes: [u8; OPERAND_SIZE] = raw_binary[register_ip + OPERATION_SIZE .. register_ip + OPERATION_SIZE + OPERAND_SIZE].try_into().expect("ERROR: Emulator's OPERAND_SIZE must match the number of bytes in the RawProcessorOperand type.");
        let operand1: RawProcessorOperand = RawProcessorOperand::from_le_bytes(operand1_bytes);
        let operand2_bytes: [u8; OPERAND_SIZE] = raw_binary[register_ip + OPERATION_SIZE + OPERAND_SIZE .. register_ip + OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE].try_into().expect("ERROR: Emulator's OPERAND_SIZE must match the number of bytes in the RawProcessorOperand type.");
        let operand2: RawProcessorOperand = RawProcessorOperand::from_le_bytes(operand2_bytes);
        // Execute operation.
        match operation {
            NOP {
                println!("NOP");
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
            }
            LOAD {
                println!("LOAD");
                registers[operand2 as usize] = RawProcessorOperand::from_le_bytes(raw_binary[operand1 as usize .. ((operand1 as usize) + OPERAND_SIZE)]);
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
            }
            STORE {
                println!("STORE");
                raw_binary[operand2 as usize .. ((operand2 as usize) + OPERAND_SIZE)].copy_from_slice(&registers[operand1 as usize].to_le_bytes());
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
            }
            ADD {
                println!("ADD");
                registers[Register::A as usize] = registers[operand1 as usize] + registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
            }
            SUB {
                println!("SUB");
                registers[Register::A as usize] = registers[operand1 as usize] - registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
            }
            OUT {

            }
            IN {

            }
            MOV {
                println!("MOV");
                registers[operand2 as usize] = registers[operand1 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
            }
            CMP {
                println!("CMP");
                if registers[operand1 as usize] < registers[operand2 as usize] {
                    registers[Register::A as usize] = 0;
                }
                else if registers[operand1 as usize] == registers[operand2 as usize] {
                    registers[Register::A as usize] = 1;
                }
                else {
                    registers[Register::A as usize] = 2;
                }
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
            }
            JMPL {
                println!("JMPL");
                if registers[Register::A as usize] == 0 {
                    registers[Register::IP as usize] = start_of_code_section_offset + operand1;
                }
                else {
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
                }
            }
            JMPE {
                println!("JMPE");
                if registers[Register::A as usize] == 1 {
                    registers[Register::IP as usize] = start_of_code_section_offset + operand1;
                }
                else {
                registers[Register::IP as usize] += INSTRUCTION_SIZE;
                }
            }
            JMPG {
                println!("JMPG");
                if registers[Register::A as usize] == 2 {
                    registers[Register::IP as usize] = start_of_code_section_offset + operand1;
                }
                else {
                    registers[Register::IP as usize] += INSTRUCTION_SIZE;
                }
            }
            RST {
                println!("RST");
                registers.resize(0, 0);
                registers.resize(0, NUM_REGISTERS);
            }
            HALT {
                println!("HALT");
                break;
            }
            ISR
            INT
            ENDINT
            RLOAD
            RSTORE
            CLOAD
            MULT
            DIV
            OR
            AND
            XOR
            NOT
        }
    }
}
