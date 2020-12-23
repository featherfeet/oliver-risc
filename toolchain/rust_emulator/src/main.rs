extern crate ncurses;

use std::fs;
use std::env;
use num_derive::FromPrimitive;
use num_traits::FromPrimitive;
use std::convert::TryInto;
use std::collections::VecDeque;
use ncurses::*;

type RawProcessorOperand = u32;
const OPERATION_SIZE: usize = 1; // bytes
const OPERAND_SIZE: usize = 4; // bytes
const INSTRUCTION_SIZE: usize = OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE; // bytes

const NUM_REGISTERS: usize = 10; // registers
const TOTAL_RAM_SIZE_BYTES: usize = 8_000_000; // bytes
const GPU_TEXT_DISPLAY_ROWS: usize = 67; // rows of text
const GPU_TEXT_DISPLAY_COLUMNS: usize = 240; // columns of text
const GPU_TEXT_BUFFER_LENGTH: usize = GPU_TEXT_DISPLAY_ROWS * GPU_TEXT_DISPLAY_COLUMNS; // characters of text
const INTERRUPT_VALUE_PORT: usize = GPU_TEXT_BUFFER_LENGTH;

const NUM_INTERRUPTS: usize = 8; // interrupts
const INTERRUPT_TYPE_KEY: usize = 0;

#[derive(Debug, Clone, Copy)]
enum Register {
    IP = 0,
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    IE = 8,
    IR = 9
}

#[derive(Debug, Clone, Copy, FromPrimitive)]
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
    // Set up NCurses to emulate the GPU output and keyboard input.
    initscr();
    cbreak();
    noecho();
    curs_set(CURSOR_VISIBILITY::CURSOR_INVISIBLE);
    resizeterm(GPU_TEXT_DISPLAY_ROWS as i32, GPU_TEXT_DISPLAY_COLUMNS as i32);

    // Read in binary file.
    let args: Vec<String> = env::args().collect();
    let raw_binary_file_path = args.get(1).expect("No binary file provided!");
    let mut raw_binary: Vec::<u8> = fs::read(raw_binary_file_path).unwrap();
    raw_binary.resize(TOTAL_RAM_SIZE_BYTES, 0_u8);

    // Define registers.
    let mut registers: Vec::<RawProcessorOperand> = vec![0; NUM_REGISTERS];

    // Define shadow registers (used to store the registers' values from before an ISR triggered
    // so that the program can return to that state.
    let mut shadow_registers: Vec::<RawProcessorOperand> = vec![0; NUM_REGISTERS];

    // Allocate memory to emulate the text buffer of the GPU.
    let mut gpu_text_buffer: Vec::<u8> = vec![' ' as u8; GPU_TEXT_BUFFER_LENGTH];
   
    // Create an array to emulate the Interrupt Vector Table (IVT) that sets which Interrupt
    // Service Routines are called by each interrupt.
    let mut interrupt_vector_table: Vec::<RawProcessorOperand> = vec![0; NUM_INTERRUPTS];

    // Create FIFOs to emulate the interrupt FIFO and the interrupt value FIFO of the CPU.
    let mut interrupt_fifo = VecDeque::<RawProcessorOperand>::new();
    let mut interrupt_value_fifo = VecDeque::<RawProcessorOperand>::new();
    let mut interrupt_value_fifo_data_out: RawProcessorOperand = 0; // Emulates the register in the CPU that stores the data read out of the interrupt-value FIFO. Used by the IN instruction to get the value of an interrupt (like the scancode of a keypress).

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
        match FromPrimitive::from_u8(operation) {
            Some(Operation::NOP) => {
                //println!("NOP");
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::LOAD) => {
                //println!("LOAD");
                registers[operand2 as usize] = RawProcessorOperand::from_le_bytes(raw_binary[operand1 as usize .. ((operand1 as usize) + OPERAND_SIZE)].try_into().expect("ERROR: Emulator's OPERAND_SIZE must match the number of bytes in the RawProcessorOperand type."));
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::STORE) => {
                //println!("STORE");
                raw_binary[operand2 as usize .. ((operand2 as usize) + OPERAND_SIZE)].copy_from_slice(&registers[operand1 as usize].to_le_bytes());
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::ADD) => {
                //println!("ADD");
                registers[Register::A as usize] = registers[operand1 as usize] + registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::SUB) => {
                //println!("SUB");
                registers[Register::A as usize] = registers[operand1 as usize] - registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::OUT) => {
                //println!("OUT");
                if registers[operand1 as usize] < GPU_TEXT_BUFFER_LENGTH as RawProcessorOperand {
                    let address: usize = registers[operand1 as usize] as usize;
                    let character: u8 = registers[operand2 as usize].to_le_bytes()[0];
                    gpu_text_buffer[address] = character;
                    mvaddch((address / GPU_TEXT_DISPLAY_COLUMNS) as i32, (address % GPU_TEXT_DISPLAY_COLUMNS) as i32, character.into());
                    refresh();
                }
                else if registers[operand1 as usize] == INTERRUPT_VALUE_PORT as RawProcessorOperand {
                    println!("ERROR: CPU cannot write to interrupt value port.");
                }
                else {
                    println!("ERROR: Invalid OUT instruction.");
                }
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::IN) => {
                //println!("IN");
                if registers[operand1 as usize] < GPU_TEXT_BUFFER_LENGTH as RawProcessorOperand {
                    registers[operand2 as usize] = gpu_text_buffer[registers[operand1 as usize] as usize].into();
                }
                else if registers[operand1 as usize] == INTERRUPT_VALUE_PORT as RawProcessorOperand {
                    registers[operand2 as usize] = interrupt_value_fifo_data_out;
                }
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::MOV) => {
                //println!("MOV");
                registers[operand2 as usize] = registers[operand1 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::CMP) => {
                //println!("CMP");
                if registers[operand1 as usize] < registers[operand2 as usize] {
                    registers[Register::A as usize] = 0;
                }
                else if registers[operand1 as usize] == registers[operand2 as usize] {
                    registers[Register::A as usize] = 1;
                }
                else {
                    registers[Register::A as usize] = 2;
                }
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::JMPL) => {
                //println!("JMPL");
                if registers[Register::A as usize] == 0 {
                    registers[Register::IP as usize] = start_of_code_section_offset + operand1;
                }
                else {
                    registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
                }
            }
            Some(Operation::JMPE) => {
                //println!("JMPE");
                if registers[Register::A as usize] == 1 {
                    registers[Register::IP as usize] = start_of_code_section_offset + operand1;
                }
                else {
                    registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
                }
            }
            Some(Operation::JMPG) => {
                //println!("JMPG");
                if registers[Register::A as usize] == 2 {
                    registers[Register::IP as usize] = start_of_code_section_offset + operand1;
                }
                else {
                    registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
                }
            }
            Some(Operation::RST) => {
                //println!("RST");
                registers.resize(0, 0);
                registers.resize(NUM_REGISTERS as usize, 0);
            }
            Some(Operation::HALT) => {
                std::thread::sleep(std::time::Duration::from_millis(10 * 1000));
                endwin();
                //println!("HALT");
                break;
            }
            Some(Operation::ISR) => {
                //println!("ISR");
                interrupt_vector_table[registers[operand1 as usize] as usize] = registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::INT) => {
                //println!("INT");
                interrupt_fifo.push_front(registers[operand1 as usize]);
                interrupt_value_fifo.push_front(0);
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::ENDINT) => {
                //println!("ENDINT");
                registers.copy_from_slice(&shadow_registers);
            }
            Some(Operation::RLOAD) => {
                //println!("RLOAD");
                registers[operand2 as usize] = RawProcessorOperand::from_le_bytes(raw_binary[registers[operand1 as usize] as usize .. ((registers[operand1 as usize] as usize) + OPERAND_SIZE)].try_into().expect("ERROR: Emulator's OPERAND_SIZE must match the number of bytes in the RawProcessorOperand type."));
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::RSTORE) => {
                //println!("RSTORE");
                raw_binary[registers[operand2 as usize] as usize .. ((registers[operand2 as usize] as usize) + OPERAND_SIZE)].copy_from_slice(&registers[operand1 as usize].to_le_bytes());
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::CLOAD) => {
                //println!("CLOAD");
                registers[operand2 as usize] = operand1;
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::MULT) => {
                //println!("MULT");
                registers[Register::A as usize] = registers[operand1 as usize] * registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::DIV) => {
                //println!("DIV");
                registers[Register::A as usize] = registers[operand1 as usize] / registers[operand2 as usize];
                registers[Register::B as usize] = registers[operand1 as usize] % registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::OR) => {
                //println!("OR");
                registers[Register::A as usize] = registers[operand1 as usize] | registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::AND) => {
                //println!("AND");
                registers[Register::A as usize] = registers[operand1 as usize] & registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::XOR) => {
                //println!("XOR");
                registers[Register::A as usize] = registers[operand1 as usize] ^ registers[operand2 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            Some(Operation::NOT) => {
                //println!("NOT");
                registers[operand1 as usize] = !registers[operand1 as usize];
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
            None => {
                //println!("ERROR: Invalid instruction.");
                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
            }
        }
    }
}
