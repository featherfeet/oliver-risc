extern crate ncurses;

use std::fs;
use std::env;
use std::io::Write;
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
const SD_CARD_SPI_PORT: usize = GPU_TEXT_BUFFER_LENGTH + 1;
const SD_CARD_CLOCK_SELECT_PORT: usize = GPU_TEXT_BUFFER_LENGTH + 2;

const NUM_INTERRUPTS: usize = 8; // interrupts
const INTERRUPT_TYPE_KEY: RawProcessorOperand = 0;

const KEY_BACKTICK: i32 = b'`' as i32;
const KEY_1: i32 = b'1' as i32;
const KEY_2: i32 = b'2' as i32;
const KEY_3: i32 = b'3' as i32;
const KEY_4: i32 = b'4' as i32;
const KEY_5: i32 = b'5' as i32;
const KEY_6: i32 = b'6' as i32;
const KEY_7: i32 = b'7' as i32;
const KEY_8: i32 = b'8' as i32;
const KEY_9: i32 = b'9' as i32;
const KEY_0: i32 = b'0' as i32;
const KEY_HYPHEN: i32 = b'-' as i32;
const KEY_EQUALS: i32 = b'=' as i32;
const KEY_TAB: i32 = b'\t' as i32;
const KEY_Q: i32 = b'q' as i32;
const KEY_W: i32 = b'w' as i32;
const KEY_E: i32 = b'e' as i32;
const KEY_R: i32 = b'r' as i32;
const KEY_T: i32 = b't' as i32;
const KEY_Y: i32 = b'y' as i32;
const KEY_U: i32 = b'u' as i32;
const KEY_I: i32 = b'i' as i32;
const KEY_O: i32 = b'o' as i32;
const KEY_P: i32 = b'p' as i32;
const KEY_LEFT_SQUARE_BRACKET: i32 = b'[' as i32;
const KEY_RIGHT_SQUARE_BRACKET: i32 = b']' as i32; 
const KEY_BACKSLASH: i32 = b'\\' as i32;
const KEY_A: i32 = b'a' as i32;
const KEY_S: i32 = b's' as i32;
const KEY_D: i32 = b'd' as i32;
const KEY_F: i32 = b'f' as i32;
const KEY_G: i32 = b'g' as i32;
const KEY_H: i32 = b'h' as i32;
const KEY_J: i32 = b'j' as i32;
const KEY_K: i32 = b'k' as i32;
const KEY_L: i32 = b'l' as i32;
const KEY_SEMICOLON: i32 = b';' as i32;
const KEY_SINGLE_QUOTE: i32 = b'\'' as i32;
const KEY_Z: i32 = b'z' as i32;
const KEY_X: i32 = b'x' as i32;
const KEY_C: i32 = b'c' as i32;
const KEY_V: i32 = b'v' as i32;
const KEY_B: i32 = b'b' as i32;
const KEY_N: i32 = b'n' as i32;
const KEY_M: i32 = b'm' as i32;
const KEY_COMMA: i32 = b',' as i32;
const KEY_PERIOD: i32 = b'.' as i32;
const KEY_SLASH: i32 = b'/' as i32;
const KEY_SPACE: i32 = b' ' as i32;
const KEY_ASTERISK: i32 = b'*' as i32;
const KEY_PLUS: i32 = b'+' as i32;

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

fn key_to_scancodes(key: i32) -> Vec::<u8> {
    match key {
        27 => vec![0xF0, 0x76], // Escape key.
        KEY_F1 => vec![0xF0, 0x05],
        KEY_F2 => vec![0xF0, 0x06],
        KEY_F3 => vec![0xF0, 0x04],
        KEY_F4 => vec![0xF0, 0x0C],
        KEY_F5 => vec![0xF0, 0x03],
        KEY_F6 => vec![0xF0, 0x0B],
        KEY_F7 => vec![0xF0, 0x83],
        KEY_F8 => vec![0xF0, 0x0A],
        KEY_F9 => vec![0xF0, 0x01],
        KEY_F10 => vec![0xF0, 0x09],
        KEY_F11 => vec![0xF0, 0x78],
        KEY_F12 => vec![0xF0, 0x07],
        KEY_BACKTICK => vec![0xF0, 0x0E],
        KEY_1 => vec![0xF0, 0x16],
        KEY_2 => vec![0xF0, 0x1E],
        KEY_3 => vec![0xF0, 0x26],
        KEY_4 => vec![0xF0, 0x25],
        KEY_5 => vec![0xF0, 0x2E],
        KEY_6 => vec![0xF0, 0x36],
        KEY_7 => vec![0xF0, 0x3D],
        KEY_8 => vec![0xF0, 0x3E],
        KEY_9 => vec![0xF0, 0x46],
        KEY_0 => vec![0xF0, 0x45],
        KEY_HYPHEN => vec![0xF0, 0x4E],
        KEY_EQUALS => vec![0xF0, 0x55],
        KEY_BACKSPACE => vec![0xF0, 0x66],
        KEY_TAB => vec![0xF0, 0x0D],
        KEY_Q => vec![0xF0, 0x15],
        KEY_W => vec![0xF0, 0x1D],
        KEY_E => vec![0xF0, 0x24],
        KEY_R => vec![0xF0, 0x2D],
        KEY_T => vec![0xF0, 0x2C],
        KEY_Y => vec![0xF0, 0x35],
        KEY_U => vec![0xF0, 0x3C],
        KEY_I => vec![0xF0, 0x43],
        KEY_O => vec![0xF0, 0x44],
        KEY_P => vec![0xF0, 0x4D],
        KEY_LEFT_SQUARE_BRACKET => vec![0xF0, 0x54],
        KEY_RIGHT_SQUARE_BRACKET => vec![0xF0, 0x5B],
        KEY_SINGLE_QUOTE => vec![0xF0, 0x5D],
        KEY_A => vec![0xF0, 0x1C],
        KEY_S => vec![0xF0, 0x1B],
        KEY_D => vec![0xF0, 0x23],
        KEY_F => vec![0xF0, 0x2B],
        KEY_G => vec![0xF0, 0x34],
        KEY_H => vec![0xF0, 0x33],
        KEY_J => vec![0xF0, 0x3B],
        KEY_K => vec![0xF0, 0x42],
        KEY_L => vec![0xF0, 0x4B],
        KEY_SEMICOLON => vec![0xF0, 0x4C],
        KEY_SINGLE_QUOTE => vec![0xF0, 0x52],
        10 => vec![0xF0, 0x5A], // Enter key.
        KEY_Z => vec![0xF0, 0x1A],
        KEY_X => vec![0xF0, 0x22],
        KEY_C => vec![0xF0, 0x21],
        KEY_V => vec![0xF0, 0x2A],
        KEY_B => vec![0xF0, 0x32],
        KEY_N => vec![0xF0, 0x31],
        KEY_M => vec![0xF0, 0x3A],
        KEY_COMMA => vec![0xF0, 0x41],
        KEY_PERIOD => vec![0xF0, 0x49],
        KEY_SLASH => vec![0xF0, 0x4A],
        KEY_SPACE => vec![0xF0, 0x29],
        KEY_IC => vec![0xE0, 0xF0, 0x70],
        KEY_HOME => vec![0xE0, 0xF0, 0x6C],
        KEY_PPAGE => vec![0xE0, 0xF0, 0x7D],
        KEY_DC => vec![0xE0, 0xF0, 0x71],
        KEY_END => vec![0xE0, 0xF0, 0x69],
        KEY_NPAGE => vec![0xE0, 0xF0, 0x7A],
        KEY_UP => vec![0xE0, 0xF0, 0x75],
        KEY_LEFT => vec![0xE0, 0xF0, 0x6B],
        KEY_DOWN => vec![0xE0, 0xF0, 0x72],
        KEY_RIGHT => vec![0xE0, 0xF0, 0x74],
        KEY_ASTERISK => vec![0xF0, 0x7C],
        KEY_PLUS => vec![0xF0, 0x79],
        _ => vec![]
    }
}

fn main() {
    // Set up NCurses to emulate the GPU output and keyboard input.
    initscr();
    cbreak();
    nodelay(stdscr(), true);
    keypad(stdscr(), true);
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

    // Open SPI logfile to log bytes sent out over the SD card SPI bus.
    let mut spi_logfile = fs::File::create("spi_logfile.log").expect("ERROR: Failed to open SPI logfile for writing.");

    // Read the first OPERAND_SIZE bytes of the binary, which contain the length of the .data:
    // section of the binary (which is also the offset to the start of the .code: section).
    let start_of_code_section_offset: RawProcessorOperand = RawProcessorOperand::from_le_bytes(raw_binary[0..OPERAND_SIZE].try_into().expect("ERROR: Emulator's OPERAND_SIZE must match the number of bytes in the RawProcessorOperand type.")) + (OPERAND_SIZE as RawProcessorOperand); // We add OPERAND_SIZE to the offset to compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data: section.

    // Start code execution.
    registers[Register::IP as usize] = start_of_code_section_offset;
    loop {
        let register_ip = registers[Register::IP as usize] as usize;
        mvprintw(12, 10, &format!("IP = {}            ", register_ip));
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
                    if character as char != '_' {
                        mvprintw(13, 10, &format!("Outputting {} at address {}.", character, address));
                    }
                    refresh();
                }
                else if registers[operand1 as usize] == INTERRUPT_VALUE_PORT as RawProcessorOperand {
                    println!("ERROR: CPU cannot write to interrupt value port.");
                }
                else if registers[operand1 as usize] == SD_CARD_CLOCK_SELECT_PORT as RawProcessorOperand {
                    if registers[operand2 as usize] == 0 {
                        writeln!(spi_logfile, "CS LOW").expect("Failed to write to spi_logfile.log.");
                    }
                    else {
                        writeln!(spi_logfile, "CS HIGH").expect("Failed to write to spi_logfile.log.");
                    }
                }
                else if registers[operand1 as usize] == SD_CARD_SPI_PORT as RawProcessorOperand {
                    writeln!(spi_logfile, "{:#X}", registers[operand2 as usize].to_le_bytes()[0]).expect("Failed to write to spi_logfile.log.");
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
                else if registers[operand1 as usize] == SD_CARD_SPI_PORT as RawProcessorOperand {
                    registers[operand2 as usize] = 1; // DEBUG
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
//                registers[Register::IP as usize] += INSTRUCTION_SIZE as RawProcessorOperand;
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
        // Handle interrupts.
        if interrupt_fifo.len() > 0 && registers[Register::IR as usize] == 0 {
            let interrupt_number: RawProcessorOperand = interrupt_fifo.pop_back().unwrap();
            interrupt_value_fifo_data_out = interrupt_value_fifo.pop_back().unwrap();
            mvprintw(10, 10, &format!("Interrupt {} triggered!", interrupt_number));
            shadow_registers.copy_from_slice(&registers);
            registers[Register::IP as usize] = start_of_code_section_offset + interrupt_vector_table[interrupt_number as usize];
            mvprintw(11, 10, &format!("Jumping IP to {}.", interrupt_vector_table[interrupt_number as usize]));
            refresh();
            registers[Register::IR as usize] = 1;
        }
        // Add keyboard interrupts.
        let ch: i32 = getch();
        if ch != ERR && ch != 410 {
            let ps2_scancodes = key_to_scancodes(ch);
            for ps2_scancode in ps2_scancodes {
                interrupt_fifo.push_front(INTERRUPT_TYPE_KEY);
                interrupt_value_fifo.push_front(ps2_scancode.into());
            }
        }
    }
}
