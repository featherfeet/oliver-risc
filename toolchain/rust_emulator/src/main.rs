use std::fs;
use std::env;
use std::io::Write;
use std::convert::TryInto;
use num_traits::FromPrimitive;

use cpu::cpu::*;

#[derive(Debug)]
enum Operands {
    N,
    R,
    C,
    RR,
    CR,
    RC,
    RRR,
    CRR,
    RCR
}

fn main() {
    // Read in binary file.
    let args: Vec<String> = env::args().collect();
    let binary_file_path = args.get(1).expect("No binary file path provided!");
    let mut raw_binary = fs::read(binary_file_path).expect("Failed to read input binary file.");
    raw_binary.resize(TOTAL_RAM_SIZE_BYTES, 0_u8);

    // Read in the offset to the .code section.
    let header: [u8; CONSTANT_SIZE] = raw_binary[0 .. CONSTANT_SIZE].try_into().expect("Error: Unable to read first CONSTANT_SIZE bytes in the binary.");
    let code_section_offset: RawConstantOperand = RawConstantOperand::from_le_bytes(header);

    // Declare registers and other internal data structures of the CPU.
    let mut registers: Vec::<RawConstantOperand> = vec![0; NUM_REGISTERS];
    //let mut shadow_registers: Vec::<RawConstantOperand> = vec![0; NUM_REGISTERS];
    let mut gpu_text_buffer: Vec::<u8> = vec![' ' as u8; GPU_TEXT_BUFFER_LENGTH];
    //let mut interrupt_vector_table: Vec::<RawConstantOperand> = vec![0; NUM_INTERRUPTS];

    // Start the instruction pointer at the start of the .code section.
    registers[REGISTER_IP] = code_section_offset;

    println!("code_section_offset: {}", code_section_offset);

    // Main emulation loop.
    loop {
        // Load instruction.
        let instruction = InstructionBitfield(&mut raw_binary[registers[REGISTER_IP] as usize .. (registers[REGISTER_IP] + INSTRUCTION_SIZE as RawConstantOperand) as usize]);
        // Calculate the size of the operation (possible sizes are byte, word, doubleword, and quadword).
        // byte = 8 bits (1 byte)
        // word = 16 bits (2 bytes)
        // doubleword = 32 bits (4 bytes)
        // quadword = 64 bits (8 bytes)
        let operation_size: usize = match instruction.get_size() {
            0 => 1,
            1 => 2,
            2 => 4,
            3 => 8,
            _ => {
                println!("Invalid operation size, defaulting to 1 byte.");
                1
            }
        };
        // Decode instruction.
        let operation: u8 = instruction.get_operation();
        let variant: u8 = instruction.get_variant();
        let operands = match FromPrimitive::from_u8(operation) {
            Some(Operation::NOP) => Operands::N,
            Some(Operation::LOAD) => {
                match variant {
                    Variant::LOAD_RR => Operands::RR,
                    Variant::LOAD_CR => Operands::CR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::STORE) => {
                match variant {
                    Variant::STORE_RR => Operands::RR,
                    Variant::STORE_CR => Operands::CR,
                    Variant::STORE_RC => Operands::RC,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::ADD) => {
                match variant {
                    Variant::ADD_RRR => Operands::RRR,
                    Variant::ADD_RCR => Operands::RCR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::MULT) => {
                match variant {
                    Variant::MULT_RRR => Operands::RRR,
                    Variant::MULT_RCR => Operands::RCR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::DIV) => {
                match variant {
                    Variant::DIV_RRR => Operands::RRR,
                    Variant::DIV_RCR => Operands::RCR,
                    Variant::DIV_CRR => Operands::CRR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::OUT) => {
                match variant {
                    Variant::OUT_RR => Operands::RR,
                    Variant::OUT_CR => Operands::CR,
                    Variant::OUT_RC => Operands::RC,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::IN) => {
                match variant {
                    Variant::IN_RR => Operands::RR,
                    Variant::IN_CR => Operands::CR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::MOV) => {
                match variant {
                    Variant::MOV_RR => Operands::RR,
                    Variant::MOV_CR => Operands::CR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::CMP) => {
                match variant {
                    Variant::CMP_RRR => Operands::RRR,
                    Variant::CMP_RCR => Operands::RCR,
                    Variant::CMP_CRR => Operands::CRR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::JMP) => {
                match variant {
                    Variant::JMP_U => Operands::RC,
                    Variant::JMP_E => Operands::RC,
                    Variant::JMP_NE => Operands::RC,
                    Variant::JMP_L => Operands::RC,
                    Variant::JMP_G => Operands::RC,
                    Variant::JMP_LE => Operands::RC,
                    Variant::JMP_GE => Operands::RC,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::RST) => Operands::N,
            Some(Operation::HALT) => Operands::N,
            Some(Operation::ISR) => Operands::RR,
            Some(Operation::INT) => {
                match variant {
                    Variant::INT_R => Operands::R,
                    Variant::INT_C => Operands::C,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::ENDINT) => Operands::N,
            Some(Operation::OR) => {
                match variant {
                    Variant::OR_RRR => Operands::RRR,
                    Variant::OR_RCR => Operands::RCR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::AND) => {
                match variant {
                    Variant::AND_RRR => Operands::RRR,
                    Variant::AND_RCR => Operands::RCR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::XOR) => {
                match variant {
                    Variant::XOR_RRR => Operands::RRR,
                    Variant::XOR_RCR => Operands::RCR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            Some(Operation::NOT) => Operands::RR,
            Some(Operation::SHIFT) => {
                match variant {
                    Variant::SHIFT_L_RRR => Operands::RRR,
                    Variant::SHIFT_L_RCR => Operands::RCR,
                    Variant::SHIFT_R_RRR => Operands::RRR,
                    Variant::SHIFT_R_RCR => Operands::RCR,
                    Variant::SHIFT_L_CRR => Operands::CRR,
                    Variant::SHIFT_R_CRR => Operands::CRR,
                    _ => {
                        println!("Invalid variant!");
                        Operands::N
                    }
                }
            }
            None => Operands::N
        };
        let mut operand1: RawConstantOperand = 0;
        let mut operand2: RawConstantOperand = 0;
        let mut destination_register: usize = 0;
        match operands {
            Operands::N => {}
            Operands::R => {
                operand1 = registers[instruction.get_register_operand_1() as usize];
            }
            Operands::C => {
                operand1 = instruction.get_constant_operand();
            }
            Operands::RR => {
                operand1 = registers[instruction.get_register_operand_1() as usize];
                destination_register = instruction.get_register_operand_2().into();
            }
            Operands::CR => {
                operand1 = instruction.get_constant_operand();
                destination_register = instruction.get_register_operand_1().into();
            },
            Operands::RC => {
                operand1 = registers[instruction.get_register_operand_1() as usize];
                operand2 = instruction.get_constant_operand();
            },
            Operands::RRR => {
                operand1 = registers[instruction.get_register_operand_1() as usize];
                operand2 = registers[instruction.get_register_operand_2() as usize];
                destination_register = instruction.get_register_operand_3().into();
            },
            Operands::CRR => {
                operand1 = instruction.get_constant_operand();
                operand2 = registers[instruction.get_register_operand_1() as usize];
                destination_register = instruction.get_register_operand_2().into();
            },
            Operands::RCR => {
                operand1 = registers[instruction.get_register_operand_1() as usize];
                operand2 = instruction.get_constant_operand();
                destination_register = instruction.get_register_operand_2().into();
            }
        }
        // Execute instruction.
        match FromPrimitive::from_u8(operation) {
            Some(Operation::NOP) => {
                println!("NOP");
            }
            Some(Operation::LOAD) => {
                println!("LOAD");
                let mut source_bytes: [u8; CONSTANT_SIZE] = [0_u8; CONSTANT_SIZE];
                &source_bytes.copy_from_slice(&registers[destination_register].to_le_bytes());
                source_bytes[.. operation_size].copy_from_slice(&raw_binary[(operand1 + registers[REGISTER_OF]) as usize .. (((operand1 + registers[REGISTER_OF]) as usize) + operation_size)]); // Copy in the bytes that need to be loaded into the register.
                registers[destination_register] = RawConstantOperand::from_le_bytes(source_bytes);
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::STORE) => {
                println!("STORE");
                raw_binary[(operand2 + registers[REGISTER_OF]) as usize .. (((operand2 + registers[REGISTER_OF]) as usize) + operation_size)].copy_from_slice(&operand1.to_le_bytes()[.. operation_size]);
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::ADD) => {
                println!("ADD");
                registers[destination_register] = (operand1 as SignedRawConstantOperand + operand2 as SignedRawConstantOperand) as RawConstantOperand;
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::MULT) => {
                println!("MULT");
                registers[destination_register] = (operand1 as SignedRawConstantOperand * operand2 as SignedRawConstantOperand) as RawConstantOperand;
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::DIV) => {
                println!("DIV");
                if instruction.get_variant() == Variant::DIV_RRR || instruction.get_variant() == Variant::DIV_RCR || instruction.get_variant() == Variant::DIV_CRR {
                    registers[destination_register] = (operand1 as SignedRawConstantOperand / operand2 as SignedRawConstantOperand) as RawConstantOperand;
                }
                else if instruction.get_variant() == Variant::MOD_RRR || instruction.get_variant() == Variant::MOD_RCR || instruction.get_variant() == Variant::MOD_CRR {
                    registers[destination_register] = (operand1 as SignedRawConstantOperand % operand2 as SignedRawConstantOperand) as RawConstantOperand;
                }
                else {
                    println!("Invalid DIV variant!");
                }
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::OUT) => {
                println!("OUT ({} at port {})", operand1, registers[destination_register]);
                if (registers[destination_register] as usize) >= GPU_TEXT_BUFFER_PORT && (registers[destination_register] as usize) < GPU_TEXT_BUFFER_PORT + GPU_TEXT_BUFFER_LENGTH {
                    gpu_text_buffer[registers[destination_register] as usize - GPU_TEXT_BUFFER_PORT] = operand1 as u8;
                }
                else if registers[destination_register] as usize == INTERRUPT_VALUE_PORT {
                    println!("Cannot output to interrupt value port!");
                }
                else if registers[destination_register] as usize == SD_CARD_SPI_PORT {
                    println!("Unimplemented write to SD card SPI port.");
                }
                else if registers[destination_register] as usize == SD_CARD_CLOCK_SELECT_PORT {
                    println!("Unimplemented write to SD card SPI CS port.");
                }
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::IN) => {
                println!("IN");
                if (operand1 as usize) >= GPU_TEXT_BUFFER_PORT && (operand1 as usize) < GPU_TEXT_BUFFER_PORT + GPU_TEXT_BUFFER_LENGTH {
                    registers[destination_register] = gpu_text_buffer[operand1 as usize - GPU_TEXT_BUFFER_PORT].into();
                }
                else {
                    println!("Unimplemented IN port!");
                }
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::MOV) => {
                println!("MOV");
                registers[destination_register] = operand1;
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::CMP) => {
                println!("CMP");
                if operand1 < operand2 {
                    registers[destination_register] = 0;
                }
                else if operand1 == operand2 {
                    registers[destination_register] = 1;
                }
                else {
                    registers[destination_register] = 2;
                }
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::JMP) => {
                println!("JMP");
                match instruction.get_variant() {
                    Variant::JMP_U => {
                        registers[REGISTER_IP] = operand2;
                    }
                    Variant::JMP_E => {
                        if operand1 == 1 {
                            registers[REGISTER_IP] = operand2;
                        }
                        else {
                            registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
                        }
                    }
                    Variant::JMP_NE => {
                        if operand1 != 1 {
                            registers[REGISTER_IP] = operand2;
                        }
                        else {
                            registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
                        }
                    }
                    Variant::JMP_L => {
                        if operand1 == 0 {
                            registers[REGISTER_IP] = operand2;
                        }
                        else {
                            registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
                        }
                    }
                    Variant::JMP_G => {
                        if operand1 == 2 {
                            registers[REGISTER_IP] = operand2;
                        }
                        else {
                            registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
                        }
                    }
                    Variant::JMP_LE => {
                        if operand1 == 0 || operand1 == 1 {
                            registers[REGISTER_IP] = operand2;
                        }
                        else {
                            registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
                        }
                    }
                    Variant::JMP_GE => {
                        if operand1 == 1 || operand1 == 2 {
                            registers[REGISTER_IP] = operand2;
                        }
                        else {
                            registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
                        }
                    }
                    _ => println!("Invalid JMP variant!")
                }
            }
            Some(Operation::RST) => {
                println!("RST");
                registers.resize(0, 0);
                registers.resize(NUM_REGISTERS as usize, 0);
                registers[REGISTER_IP] = code_section_offset;
            }
            Some(Operation::HALT) => {
                println!("HALT");
                std::thread::sleep(std::time::Duration::from_millis(10 * 1000));
                let mut ram_dumpfile = fs::File::create("ram_dumpfile.bin").unwrap();
                ram_dumpfile.write(&raw_binary).unwrap();
                for (register_number, register) in registers.iter().enumerate() {
                    println!("{}: {}", register_number, register);
                }
                break;
            }
            Some(Operation::ISR) => {
                println!("ISR unimplemented!");
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::INT) => {
                println!("INT unimplemented!");
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::ENDINT) => {
                println!("ENDINT unimplemented!");
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::OR) => {
                println!("OR");
                registers[destination_register] = operand1 | operand2;
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::AND) => {
                println!("AND");
                registers[destination_register] = operand1 & operand2;
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::XOR) => {
                println!("XOR");
                registers[destination_register] = operand1 ^ operand2;
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::NOT) => {
                println!("NOT");
                registers[destination_register] = !registers[operand1 as usize];
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            Some(Operation::SHIFT) => {
                println!("SHIFT");
                match instruction.get_variant() {
                    Variant::SHIFT_L_RRR | Variant::SHIFT_L_RCR | Variant::SHIFT_L_CRR => {
                        registers[destination_register] = operand1 << operand2;
                    }
                    Variant::SHIFT_R_RRR | Variant::SHIFT_R_RCR | Variant::SHIFT_R_CRR => {
                        registers[destination_register] = operand1 >> operand2;
                    }
                    _ => {
                        println!("Invalid SHIFT variant!");
                    }
                }
                registers[REGISTER_IP] += INSTRUCTION_SIZE as RawConstantOperand; // Next instruction.
            }
            None => {
                println!("Invalid operation!");
            }
        }
    }
}
