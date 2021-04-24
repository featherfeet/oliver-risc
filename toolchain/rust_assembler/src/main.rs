extern crate pest;
#[macro_use]
extern crate pest_derive;
#[macro_use]
extern crate bitfield;

use std::fs;
use std::io::Write;
use std::env;
use std::mem;
use std::vec::Vec;
use std::string::String;
use std::collections::HashMap;
use parse_int::parse;

use pest::iterators::Pair;
use pest::Parser;

type RawConstantOperand = u32;
type SignedRawConstantOperand = i32;
const CONSTANT_SIZE: usize = std::mem::size_of::<RawConstantOperand>();
const INSTRUCTION_SIZE: usize = 7;

#[derive(Parser)]
#[grammar = "assembly.pest"]
struct AssemblyParser;

#[derive(Debug, Clone, Copy)]
enum Operation {
    NOP = 0,
    LOAD = 1,
    STORE = 2,
    ADD = 3,
    MULT = 4,
    DIV = 5,
    OUT = 6,
    IN = 7,
    MOV = 8,
    CMP = 9,
    JMP = 10,
    RST = 11,
    HALT = 12,
    ISR = 13,
    INT = 14,
    ENDINT = 15,
    OR = 16,
    AND = 17,
    XOR = 18,
    NOT = 19,
    SHIFT = 20
}

#[derive(Debug)]
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
    IR = 9,
    ZD = 10,
    OF = 11
}

#[derive(Debug, Clone, Copy)]
enum Variant {
}

impl Variant {
    pub const NONE: u8 = 0;
    pub const LOAD_RR: u8 = 0;
    pub const LOAD_CR: u8 = 1;
    pub const STORE_RR: u8 = 0;
    pub const STORE_CR: u8 = 1;
    pub const STORE_RC: u8 = 2;
    pub const ADD_RRR: u8 = 0;
    pub const ADD_RCR: u8 = 1;
    pub const MULT_RRR: u8 = 0;
    pub const MULT_RCR: u8 = 1;
    pub const DIV_RRR: u8 = 0;
    pub const DIV_RCR: u8 = 1;
    pub const DIV_CRR: u8 = 2;
    pub const MOD_RRR: u8 = 3;
    pub const MOD_RCR: u8 = 4;
    pub const MOD_CRR: u8 = 5;
    pub const OUT_RR: u8 = 0;
    pub const OUT_CR: u8 = 1;
    pub const OUT_RC: u8 = 2;
    pub const IN_RR: u8 = 0;
    pub const IN_CR: u8 = 1;
    pub const MOV_RR: u8 = 0;
    pub const MOV_CR: u8 = 1;
    pub const CMP_RRR: u8 = 0;
    pub const CMP_RCR: u8 = 1;
    pub const CMP_CRR: u8 = 2;
    pub const JMP_U: u8 = 0;
    pub const JMP_E: u8 = 1;
    pub const JMP_NE: u8 = 2;
    pub const JMP_L: u8 = 3;
    pub const JMP_G: u8 = 4;
    pub const JMP_LE: u8 = 5;
    pub const JMP_GE: u8 = 6;
    pub const INT_R: u8 = 0;
    pub const INT_C: u8 = 1;
    pub const OR_RRR: u8 = 0;
    pub const OR_RCR: u8 = 1;
    pub const AND_RRR: u8 = 0;
    pub const AND_RCR: u8 = 1;
    pub const XOR_RRR: u8 = 0;
    pub const XOR_RCR: u8 = 1;
    pub const SHIFT_L_RRR: u8 = 0;
    pub const SHIFT_L_RCR: u8 = 1;
    pub const SHIFT_R_RRR: u8 = 2;
    pub const SHIFT_R_RCR: u8 = 3;
    pub const SHIFT_L_CRR: u8 = 4;
    pub const SHIFT_R_CRR: u8 = 5;
}

#[derive(Debug)]
enum Variable {
    IntegerVariable { address: RawConstantOperand, value: RawConstantOperand },
    StringVariable { address: RawConstantOperand, value: String }
}

#[derive(Debug)]
enum ConstantOperand {
    Symbol { symbol: String },
    Literal { value: RawConstantOperand }
}

impl ConstantOperand {
    fn evaluate(&self, labels_table: &HashMap::<String, RawConstantOperand>, variables_table: &HashMap::<String, Variable>) -> RawConstantOperand {
        match self {
            ConstantOperand::Symbol { symbol } => {
                match labels_table.get(symbol) {
                    Some(symbol_address) => *symbol_address,
                    None => {
                        match variables_table.get(symbol) {
                            Some(variable) => {
                                match variable {
                                    Variable::IntegerVariable { address, .. } => *address,
                                    Variable::StringVariable { address, .. } => *address
                                }
                            }
                            None => {
                                println!("Error: No such label `{}`, defaulting to address 0.", symbol);
                                0
                            }
                        }
                    }
                }
            }
            ConstantOperand::Literal { value } => *value
        }
    }
}

#[derive(Debug)]
enum Operands {
    N,
    R { operand1: Register },
    C { operand1: ConstantOperand },
    RR { operand1: Register, operand2: Register },
    CR { operand1: ConstantOperand, operand2: Register },
    RC { operand1: Register, operand2: ConstantOperand },
    RRR { operand1: Register, operand2: Register, operand3: Register },
    CRR { operand1: ConstantOperand, operand2: Register, operand3: Register },
    RCR { operand1: Register, operand2: ConstantOperand, operand3: Register }
}

#[derive(Debug)]
struct Instruction {
    address: RawConstantOperand,
    operation: Operation,
    variant: u8,
    operands: Operands
}

bitfield! {
    struct InstructionBitfield([u8]); // Bit order is least-significant-bit-first.
    impl Debug;
    u8;
    get_operation, set_operation: 4, 0;
    get_variant, set_variant: 7, 5;
    get_size, set_size: 9, 8;
    get_register_operand_1, set_register_operand_1: 13, 10;
    get_register_operand_2, set_register_operand_2: 17, 14;
    get_register_operand_3, set_register_operand_3: 21, 18;
    RawConstantOperand, get_constant_operand, set_constant_operand: 49, 18;
}

fn evaluate_constant_literal(constant_literal: &str) -> RawConstantOperand {
    if constant_literal.starts_with("'") {
        return constant_literal.bytes().nth(1).unwrap() as RawConstantOperand;
    }
    else if constant_literal.starts_with("-") {
        return (-parse::<SignedRawConstantOperand>(&constant_literal[1..]).unwrap().abs()) as RawConstantOperand;
    }
    else {
        return parse::<SignedRawConstantOperand>(constant_literal).unwrap().abs() as RawConstantOperand;
    }
}

fn parse_instruction(instruction_pair: Pair<'_, Rule>) -> (Operation, u8) {
    let rule = instruction_pair.as_rule();
    let arguments = instruction_pair.into_inner().next();
    match rule {
        Rule::nop => (Operation::NOP, Variant::NONE),
        Rule::load => {
            match arguments.unwrap().as_rule() {
                Rule::args_constant_register => (Operation::LOAD, Variant::LOAD_CR),
                Rule::args_register_register => (Operation::LOAD, Variant::LOAD_RR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::store => {
            match arguments.unwrap().as_rule() {
                Rule::args_constant_register => (Operation::STORE, Variant::STORE_CR),
                Rule::args_register_register => (Operation::STORE, Variant::STORE_RR),
                Rule::args_register_constant => (Operation::STORE, Variant::STORE_RC),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::add => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register_register => (Operation::ADD, Variant::ADD_RRR),
                Rule::args_register_constant_register => (Operation::ADD, Variant::ADD_RCR),
                Rule::args_constant_register_register => (Operation::ADD, Variant::ADD_RCR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::mult => {
            match arguments.unwrap().as_rule() {
               Rule::args_register_register_register => (Operation::MULT, Variant::MULT_RRR),
               Rule::args_register_constant_register => (Operation::MULT, Variant::MULT_RCR),
               Rule::args_constant_register_register => (Operation::MULT, Variant::MULT_RCR),
               _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::div => {
            match arguments.unwrap().as_rule() {
               Rule::args_register_register_register => (Operation::DIV, Variant::DIV_RRR),
               Rule::args_register_constant_register => (Operation::DIV, Variant::DIV_RCR),
               Rule::args_constant_register_register => (Operation::DIV, Variant::DIV_CRR),
               _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::mod_ => {
            match arguments.unwrap().as_rule() {
               Rule::args_register_register_register => (Operation::DIV, Variant::MOD_RRR),
               Rule::args_register_constant_register => (Operation::DIV, Variant::MOD_RCR),
               Rule::args_constant_register_register => (Operation::DIV, Variant::MOD_CRR),
               _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::out => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register => (Operation::OUT, Variant::OUT_RR),
                Rule::args_constant_register => (Operation::OUT, Variant::OUT_CR),
                Rule::args_register_constant => (Operation::OUT, Variant::OUT_RC),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::in_ => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register => (Operation::IN, Variant::IN_RR),
                Rule::args_constant_register => (Operation::IN, Variant::IN_CR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::mov => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register => (Operation::MOV, Variant::MOV_RR),
                Rule::args_constant_register => (Operation::MOV, Variant::MOV_CR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::cmp => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register_register => (Operation::CMP, Variant::CMP_RRR),
                Rule::args_constant_register_register => (Operation::CMP, Variant::CMP_CRR),
                Rule::args_register_constant_register => (Operation::CMP, Variant::CMP_RCR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::jmp => (Operation::JMP, Variant::JMP_U),
        Rule::jmpe => (Operation::JMP, Variant::JMP_E),
        Rule::jmpne => (Operation::JMP, Variant::JMP_NE),
        Rule::jmpl => (Operation::JMP, Variant::JMP_L),
        Rule::jmpg => (Operation::JMP, Variant::JMP_G),
        Rule::jmple => (Operation::JMP, Variant::JMP_LE),
        Rule::jmpge => (Operation::JMP, Variant::JMP_GE),
        Rule::rst => (Operation::RST, Variant::NONE),
        Rule::halt => (Operation::HALT, Variant::NONE),
        Rule::isr => (Operation::ISR, Variant::NONE),
        Rule::int => {
            match arguments.unwrap().as_rule() {
                Rule::args_register => (Operation::INT, Variant::INT_R),
                Rule::args_constant => (Operation::INT, Variant::INT_C),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::endint => (Operation::ENDINT, Variant::NONE),
        Rule::or => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register_register => (Operation::OR, Variant::OR_RRR),
                Rule::args_register_constant_register => (Operation::OR, Variant::OR_RCR),
                Rule::args_constant_register_register => (Operation::OR, Variant::OR_RCR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::and => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register_register => (Operation::AND, Variant::AND_RRR),
                Rule::args_register_constant_register => (Operation::AND, Variant::AND_RCR),
                Rule::args_constant_register_register => (Operation::AND, Variant::AND_RCR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::xor => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register_register => (Operation::XOR, Variant::XOR_RRR),
                Rule::args_register_constant_register => (Operation::XOR, Variant::XOR_RCR),
                Rule::args_constant_register_register => (Operation::XOR, Variant::XOR_RCR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::not => (Operation::NOT, Variant::NONE),
        Rule::shiftl => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register_register => (Operation::SHIFT, Variant::SHIFT_L_RRR),
                Rule::args_register_constant_register => (Operation::SHIFT, Variant::SHIFT_L_RCR),
                Rule::args_constant_register_register => (Operation::SHIFT, Variant::SHIFT_L_CRR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        Rule::shiftr => {
            match arguments.unwrap().as_rule() {
                Rule::args_register_register_register => (Operation::SHIFT, Variant::SHIFT_R_RRR),
                Rule::args_register_constant_register => (Operation::SHIFT, Variant::SHIFT_R_RCR),
                Rule::args_constant_register_register => (Operation::SHIFT, Variant::SHIFT_R_CRR),
                _ => (Operation::NOP, Variant::NONE)
            }
        }
        _ => {
            println!("Error: Invalid operation. Converting to NOP.");
            (Operation::NOP, Variant::NONE)
        }
    }
}

fn parse_register_operand(register_operand: Pair<'_, Rule>) -> Register {
    match register_operand.as_str() {
        "IP" => Register::IP,
        "A" => Register::A,
        "B" => Register::B,
        "C" => Register::C,
        "D" => Register::D,
        "E" => Register::E,
        "F" => Register::F,
        "G" => Register::G,
        "IE" => Register::IE,
        "IR" => Register::IR,
        "ZD" => Register::ZD,
        "OF" => Register::OF,
        _ => {
            println!("Error: Invalid register, defaulting to A.");
            Register::A
        }
    }
}

fn parse_constant_operand(constant_operand: Pair<'_, Rule>) -> ConstantOperand {
    let constant_operand_contents = constant_operand.into_inner().next().unwrap();
    match constant_operand_contents.as_rule() {
        Rule::identifier => ConstantOperand::Symbol { symbol: constant_operand_contents.as_str().to_string() },
        Rule::constant_literal => ConstantOperand::Literal { value: evaluate_constant_literal(constant_operand_contents.as_str()) },
        _ => {
            println!("Invalid constant operand `{}`. Defaulting to constant 0.", constant_operand_contents.as_str());
            ConstantOperand::Literal { value: 0 }
        }
    }
}

fn parse_operands(instruction_pair: Pair<'_, Rule>) -> Operands {
    let arguments_option = instruction_pair.into_inner().next();
    match arguments_option {
        Some(arguments) => {
            match arguments.as_rule() {
                Rule::args_register => Operands::R { operand1: parse_register_operand(arguments.into_inner().next().unwrap()) },
                Rule::args_constant => Operands::C { operand1: parse_constant_operand(arguments.into_inner().next().unwrap()) },
                Rule::args_register_register => {
                    let mut arguments_list = arguments.into_inner();
                    let operand1 = parse_register_operand(arguments_list.next().unwrap());
                    let operand2 = parse_register_operand(arguments_list.next().unwrap());
                    Operands::RR { operand1: operand1, operand2: operand2 }
                }
                Rule::args_constant_register => {
                    let mut arguments_list = arguments.into_inner();
                    let operand1 = parse_constant_operand(arguments_list.next().unwrap());
                    let operand2 = parse_register_operand(arguments_list.next().unwrap());
                    Operands::CR { operand1: operand1, operand2: operand2 }
                }
                Rule::args_register_constant => {
                    let mut arguments_list = arguments.into_inner();
                    let operand1 = parse_register_operand(arguments_list.next().unwrap());
                    let operand2 = parse_constant_operand(arguments_list.next().unwrap());
                    Operands::RC { operand1: operand1, operand2: operand2 }
                }
                Rule::args_register_register_register => {
                    let mut arguments_list = arguments.into_inner();
                    let operand1 = parse_register_operand(arguments_list.next().unwrap());
                    let operand2 = parse_register_operand(arguments_list.next().unwrap());
                    let operand3 = parse_register_operand(arguments_list.next().unwrap());
                    Operands::RRR { operand1: operand1, operand2: operand2, operand3: operand3 }
                }
                Rule::args_constant_register_register => {
                    let mut arguments_list = arguments.into_inner();
                    let operand1 = parse_constant_operand(arguments_list.next().unwrap());
                    let operand2 = parse_register_operand(arguments_list.next().unwrap());
                    let operand3 = parse_register_operand(arguments_list.next().unwrap());
                    Operands::CRR { operand1: operand1, operand2: operand2, operand3: operand3 }
                }
                Rule::args_register_constant_register => {
                    let mut arguments_list = arguments.into_inner();
                    let operand1 = parse_register_operand(arguments_list.next().unwrap());
                    let operand2 = parse_constant_operand(arguments_list.next().unwrap());
                    let operand3 = parse_register_operand(arguments_list.next().unwrap());
                    Operands::RCR { operand1: operand1, operand2: operand2, operand3: operand3 }
                }
                _ => Operands::N
            }
        }
        None => Operands::N
    }
}

fn main() {
    // Read in the assembly file.
    let args: Vec<String> = env::args().collect();
    let assembly_file_path = args.get(1).expect("No assembly file path provided!");
    let raw_assembly = fs::read_to_string(assembly_file_path).expect("Failed to read input assembly file.");

    // Get the name of the output binary file.
    let output_file_name: String = match args.get(2) {
        Some(arg) => arg.to_string(),
        None => "out.bin".to_string()
    };

    // Open the output file.
    let mut output_file = fs::File::create(output_file_name).expect("Could not open output file.");

    // Parse the assembly file.
    let parsed_assembly = AssemblyParser::parse(Rule::program, &raw_assembly);
    pest_ascii_tree::print_ascii_tree(parsed_assembly.clone());
    let program = parsed_assembly.expect("Failed to parse assembly!").next().expect("No program found.").into_inner();

    // Declare data structures for storing the parsed assembly into.
    // Hash table where keys are the names of variables (String) and values are Variable structures.
    let mut variables_table = HashMap::<String, Variable>::new();
    // Resizable array of Instruction structures.
    let mut instructions_table = Vec::<Instruction>::new();
    // Hash table where keys are the names of labels (String) and values are their addresses (RawAddressOperand).
    let mut labels_table = HashMap::<String, RawConstantOperand>::new();

    // Turn AST into data structures.
    let mut address_counter: RawConstantOperand = CONSTANT_SIZE as RawConstantOperand; // The first CONSTANT_SIZE bytes of the binary are used to store the offset to the start of the .code section, so addresses are offset by that amount.
    let mut current_section = Rule::data_section_declaration;
    let mut code_section_offset: RawConstantOperand = 0; // Memory address in the final binary at which the .code section starts.
    for line in program {
        match line.clone().as_rule() {
            Rule::code_section_declaration => {
                current_section = Rule::code_section_declaration;
                code_section_offset = address_counter;
            }
            Rule::variable_declaration => {
                // Check section.
                if current_section == Rule::code_section_declaration {
                    panic!("Error: Variable declaration in .code section. Exiting.");
                }

                // Turn AST into Variable objects in the variables_table.
                let mut variable = line.into_inner().next().unwrap().into_inner();
                let variable_name = variable.next().unwrap().as_str().to_string();
                if variables_table.contains_key(&variable_name) {
                    println!("Error: Multiple variables with the name `{}`.", variable_name);
                }
                let variable_value = variable.next().unwrap();
                match variable_value.as_rule() {
                    Rule::constant_operand => {
                        let constant_literal = variable_value.as_str();
                        let constant_value = evaluate_constant_literal(constant_literal);
                        variables_table.insert(variable_name, Variable::IntegerVariable { address: address_counter, value: constant_value });
                        address_counter += mem::size_of::<RawConstantOperand>() as RawConstantOperand;
                    }
                    Rule::string_literal => {
                        let string_contents = variable_value.into_inner().next().unwrap().as_str().to_string();
                        let string_length = string_contents.len() as RawConstantOperand;
                        variables_table.insert(variable_name, Variable::StringVariable { address: address_counter, value: string_contents });
                        address_counter += string_length + 1;
                    }
                    _ => {
                    }
                }
            }
            Rule::instruction => {
                // Check section.
                if current_section == Rule::data_section_declaration {
                    panic!("Error: Instruction in .data section. Exiting.");
                }

                // Turn AST into Instruction objects in the instructions_table.
                let instruction_pair = line.into_inner().next().unwrap();
                let instruction = parse_instruction(instruction_pair.clone());
                let operands = parse_operands(instruction_pair);
                instructions_table.push(Instruction { address: address_counter, operation: instruction.0, variant: instruction.1, operands: operands });
                address_counter += INSTRUCTION_SIZE as RawConstantOperand;
            }
            Rule::label => {
                // Check section.
                if current_section == Rule::data_section_declaration {
                    panic!("Error: Label in .data section. Exiting.");
                }

                // Add to labels_table.
                labels_table.insert(line.into_inner().next().unwrap().as_str().to_string(), address_counter);
            }
            _ => {
            }
        }
    }

    // Create final binary output using variables_table, instructions_table, and labels_table.
    let mut binary_output: Vec::<u8> = vec![0; address_counter as usize];
    
    // The first ADDRESS_SIZE bytes of the binary store offset to the start of the .code section.
    binary_output[0 .. CONSTANT_SIZE].copy_from_slice(&code_section_offset.to_le_bytes());

    // Write the binary's .data section.
    for variable in variables_table.values() {
        match variable {
            Variable::IntegerVariable { address, value } => {
                binary_output[*address as usize .. *address as usize + CONSTANT_SIZE].copy_from_slice(&value.to_le_bytes());
            }
            Variable::StringVariable { address, value } => {
                binary_output[*address as usize .. *address as usize + value.len()].copy_from_slice(&value.as_bytes());
            }
        }
    }

    // Write the binary's .code section.
    for instruction in instructions_table {
        let mut instruction_bitfield = InstructionBitfield(&mut binary_output[instruction.address as usize .. instruction.address as usize + INSTRUCTION_SIZE]);
        instruction_bitfield.set_operation(instruction.operation as u8);
        instruction_bitfield.set_variant(instruction.variant);
        match instruction.operands {
            Operands::R { operand1 } => {
                instruction_bitfield.set_register_operand_1(operand1 as u8);
            }
            Operands::C { operand1 } => {
                instruction_bitfield.set_constant_operand(operand1.evaluate(&labels_table, &variables_table));
            }
            Operands::RR { operand1, operand2 } => {
                instruction_bitfield.set_register_operand_1(operand1 as u8);
                instruction_bitfield.set_register_operand_2(operand2 as u8);
            }
            Operands::CR { operand1, operand2 } => {
                instruction_bitfield.set_constant_operand(operand1.evaluate(&labels_table, &variables_table));
                instruction_bitfield.set_register_operand_2(operand2 as u8);
            }
            Operands::RC { operand1, operand2 } => {
                instruction_bitfield.set_register_operand_1(operand1 as u8);
                instruction_bitfield.set_constant_operand(operand2.evaluate(&labels_table, &variables_table));
            }
            Operands::RRR { operand1, operand2, operand3 } => {
                instruction_bitfield.set_register_operand_1(operand1 as u8);
                instruction_bitfield.set_register_operand_2(operand2 as u8);
                instruction_bitfield.set_register_operand_3(operand3 as u8);
            }
            Operands::CRR { operand1, operand2, operand3 } => {
                instruction_bitfield.set_constant_operand(operand1.evaluate(&labels_table, &variables_table));
                instruction_bitfield.set_register_operand_2(operand2 as u8);
                instruction_bitfield.set_register_operand_3(operand3 as u8);
            }
            Operands::RCR { operand1, operand2, operand3 } => {
                instruction_bitfield.set_register_operand_1(operand1 as u8);
                instruction_bitfield.set_constant_operand(operand2.evaluate(&labels_table, &variables_table));
                instruction_bitfield.set_register_operand_3(operand3 as u8);
            }
            _ => {}
        }
    }

    output_file.write_all(&binary_output).expect("Failed to write final binary output to file.");
}
