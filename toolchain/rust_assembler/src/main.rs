extern crate pest;
#[macro_use]
extern crate pest_derive;

use std::fs;
use std::io::Write;
use std::env;
use std::mem;
use std::vec::Vec;
use std::string::String;
use std::collections::HashMap;

use pest::Parser;

#[derive(Parser)]
#[grammar = "assembly.pest"]
struct AssemblyParser;

type RawProcessorOperand = u32;
const OPERATION_SIZE: usize = 1; // bytes
const OPERAND_SIZE: usize = 4; // bytes
const INSTRUCTION_SIZE: usize = OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE; // bytes

#[derive(PartialEq)]
enum AssemblySection {
    DATA,
    CODE
}

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

#[derive(Debug)]
enum Variable {
    IntegerVariable { address: RawProcessorOperand, integer: RawProcessorOperand },
    StringVariable { address: RawProcessorOperand, string: String }
}

#[derive(Debug)]
enum Operand {
    Unused,
    Constant { constant: RawProcessorOperand },
    Register { register: Register },
    Address { address: String }
}

#[derive(Debug)]
struct Instruction {
    operation: Operation,
    operand1: Operand,
    operand2: Operand
}

fn string_to_register(register_string: &str) -> Register {
    match register_string {
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
        _ => panic!("Unknown register.")
    }
}

fn create_operand(operand_pair: Option::<pest::iterators::Pair::<'_, Rule>>) -> Operand {
    match operand_pair {
        Some(operand_pair_unwrapped) => {
            match operand_pair_unwrapped.clone().as_rule() {
                Rule::constant_operand => Operand::Constant { constant: operand_pair_unwrapped.as_str().parse::<RawProcessorOperand>().unwrap() },
                Rule::register_operand => Operand::Register { register: string_to_register(operand_pair_unwrapped.as_str()) },
                Rule::address_operand => Operand::Address { address: operand_pair_unwrapped.as_str().to_string() },
                _ => Operand::Unused
            }
        }
        None => Operand::Unused
    }
}

fn binarize_operand(variables_table: &HashMap::<String, Variable>, labels_table: &HashMap::<String, RawProcessorOperand>, operand: &Operand) -> [u8; mem::size_of::<RawProcessorOperand>()] {
    match operand {
        Operand::Unused => [0; mem::size_of::<RawProcessorOperand>()],
        Operand::Constant { constant } => constant.to_le_bytes(),
        Operand::Register { register } => (*register as RawProcessorOperand).to_le_bytes(),
        Operand::Address { address } => {
            let address_trimmed = address.trim_start_matches('[').trim_end_matches(']');
            if address_trimmed.starts_with(char::is_numeric) {
                address_trimmed.parse::<RawProcessorOperand>().unwrap().to_le_bytes()
            }
            else if variables_table.contains_key(address_trimmed) {
                match variables_table.get(address_trimmed).unwrap() {
                    Variable::IntegerVariable { address, integer: _ } => address.to_le_bytes(),
                    Variable::StringVariable { address, string: _ } => address.to_le_bytes()
                }
            }
            else if labels_table.contains_key(address_trimmed) {
                labels_table.get(address_trimmed).unwrap().to_le_bytes()
            }
            else {
                [0; mem::size_of::<RawProcessorOperand>()]
            }
        }
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

    // Parse the assembly file.
    let parsed_assembly = AssemblyParser::parse(Rule::program, &raw_assembly);
    //pest_ascii_tree::print_ascii_tree(parsed_assembly);
    let program = parsed_assembly.expect("Failed to parse assembly!").next().expect("No program found.").into_inner();

    // Declare data structures for storing the parsed assembly into.
    // Hash table where keys are the names of variables (String) and values are Variable structures.
    let mut variables_table = HashMap::<String, Variable>::new();
    // Resizable array of Instruction structures.
    let mut instructions_table = Vec::<Instruction>::new();
    // Hash table where keys are the names of labels (String) and values are their addresses (RawProcessorOperand).
    let mut labels_table = HashMap::<String, RawProcessorOperand>::new();

    let mut variables_address_counter: RawProcessorOperand = OPERAND_SIZE as RawProcessorOperand; // The first OPERAND_SIZE bytes of the final binary are taken up by an unsigned integer that holds the length of the .data: section in bytes, so we start the variable addresses at OPERAND_SIZE.
    let mut current_assembly_section = AssemblySection::DATA;
    for line in program {
        let mut inner = line.clone().into_inner();
        match line.as_rule() {
            Rule::section_declaration => {
                let inner_rule = inner.next().unwrap().as_rule();
                if inner_rule == Rule::data_section_declaration {
                    println!("Start data section.");
                    current_assembly_section = AssemblySection::DATA;
                }
                else {
                    println!("Start code section.");
                    current_assembly_section = AssemblySection::CODE;
                }
            }
            Rule::variable_declaration => {
                if current_assembly_section != AssemblySection::DATA {
                    panic!("ERROR: Variable declaration outside of `.data:` section. All variable declarations must be in the `.data:` section of the assembly file.");
                }
                let pair = inner.next().unwrap();
                let rule = pair.as_rule();
                let mut inner = pair.into_inner();
                let variable_name = inner.next().unwrap().as_str();
                let variable_value = inner.last().unwrap();
                if rule == Rule::integer_declaration {
                    println!("Integer decl.");
                    let integer_variable = Variable::IntegerVariable { address: variables_address_counter, integer: variable_value.as_str().parse::<RawProcessorOperand>().unwrap() };
                    variables_table.insert(variable_name.to_string(), integer_variable);
                    variables_address_counter += OPERAND_SIZE as RawProcessorOperand;
                }
                else {
                    println!("String decl.");
                    let string_value = variable_value.into_inner().next().unwrap().as_str().to_string();
                    let string_variable = Variable::StringVariable { address: variables_address_counter, string: string_value.clone() };
                    variables_address_counter += (string_value.len() + 1) as RawProcessorOperand;
                    variables_table.insert(variable_name.to_string(), string_variable);
                }
            }
            Rule::label => {
                if current_assembly_section != AssemblySection::CODE {
                    panic!("ERROR: Label outside of the `.code:` section. All labels must be in the `.code:` section of the assembly file.");
                }
                let identifier = inner.next().unwrap().as_str();
                labels_table.insert(identifier.to_string(), (instructions_table.len() * INSTRUCTION_SIZE) as RawProcessorOperand);
                println!("Added label `{}`.", identifier);
            }
            Rule::instruction => {
                if current_assembly_section != AssemblySection::CODE {
                    panic!("ERROR: Instruction outside of the `.code:` section. All instructions must be in the `.code:` section of the assembly file.");
                }
                let instruction_pair = inner.next().unwrap();
                let instruction_rule = instruction_pair.as_rule();
                let instruction_operation = match instruction_rule {
                                        Rule::nop_instruction => Operation::NOP,
                                        Rule::load_instruction => Operation::LOAD,
                                        Rule::store_instruction => Operation::STORE,
                                        Rule::add_instruction => Operation::ADD,
                                        Rule::sub_instruction => Operation::SUB,
                                        Rule::out_instruction => Operation::OUT,
                                        Rule::in_instruction => Operation::IN,
                                        Rule::mov_instruction => Operation::MOV,
                                        Rule::cmp_instruction => Operation::CMP,
                                        Rule::jmpl_instruction => Operation::JMPL,
                                        Rule::jmpe_instruction => Operation::JMPE,
                                        Rule::jmpg_instruction => Operation::JMPG,
                                        Rule::rload_instruction => Operation::RLOAD,
                                        Rule::rstore_instruction => Operation::RSTORE,
                                        Rule::rst_instruction => Operation::RST,
                                        Rule::halt_instruction => Operation::HALT,
                                        Rule::isr_instruction => Operation::ISR,
                                        Rule::int_instruction => Operation::INT,
                                        Rule::endint_instruction => Operation::ENDINT,
                                        Rule::cload_instruction => Operation::CLOAD,
                                        Rule::mult_instruction => Operation::MULT,
                                        Rule::div_instruction => Operation::DIV,
                                        Rule::or_instruction => Operation::OR,
                                        Rule::and_instruction => Operation::AND,
                                        Rule::xor_instruction => Operation::XOR,
                                        Rule::not_instruction => Operation::NOT,
                                        _ => Operation::NOP
                                    };
                let mut instruction_pair_inner = instruction_pair.into_inner();
                let instruction_operand1_pair_option = instruction_pair_inner.next();
                let instruction_operand2_pair_option = instruction_pair_inner.last();
                let operand1 = create_operand(instruction_operand1_pair_option);
                let operand2 = create_operand(instruction_operand2_pair_option);
                /*
                println!("instruction_operation: {:#?}", instruction_operation);
                println!("operand1: {:#?}", operand1);
                println!("operand2: {:#?}", operand2);
                */
                instructions_table.push(Instruction { operation: instruction_operation, operand1: operand1, operand2: operand2 });
            }
            Rule::EOI => {
                println!("End of assembly file.");
            }
            _ => {
                println!("Unknown parsing rule {:?}.", line.as_rule());
            }
        }
    }

    /*
    println!("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    println!("labels_table: {:#?}", labels_table);
    println!("variables_table: {:#?}", variables_table);
    println!("instructions_table: {:#?}", instructions_table);
    println!("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    */

    // Create final binary format of .data: section (variables).
    let variables_binary_size: usize = (variables_address_counter as usize) - OPERAND_SIZE; // Subtract OPERAND_SIZE because the address counter is started at OPERAND_SIZE due to the first OPERAND_SIZE bytes of the final binary output being used to store the length of the .data: section.
    let mut variables_binary: Vec::<u8> = vec![0; variables_binary_size];
    for (variable_name, variable) in &variables_table {
        match variable {
            Variable::IntegerVariable { address, integer } => {
                let address_usize = (*address as usize) - OPERAND_SIZE; // Subtract OPERAND_SIZE to compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
                let integer_bytes = integer.to_le_bytes();
                variables_binary[address_usize .. address_usize + integer_bytes.len()].copy_from_slice(&integer_bytes);
                println!("Variable `{}` at address `{}`.", variable_name, *address);
            }
            Variable::StringVariable { address, string } => {
                let address_usize = (*address as usize) - OPERAND_SIZE; // Subtract OPERAND_SIZE to compensate for the first OPERAND_SIZE bytes of the file being used to store the length of the .data section.
                let string_bytes = string.as_bytes();
                variables_binary[address_usize .. address_usize + string_bytes.len()].copy_from_slice(&string_bytes);
                println!("Variable `{}` at address `{}`.", variable_name, *address);
            }
        }
    }

    // Create final binary format of .code: section (instructions):
    let mut instructions_binary: Vec::<u8> = vec![0; instructions_table.len() * INSTRUCTION_SIZE];
    for (i, instruction) in instructions_table.iter().enumerate() {
        let operation = (instruction.operation as u8).to_le_bytes();
        instructions_binary[i * INSTRUCTION_SIZE .. i * INSTRUCTION_SIZE + OPERATION_SIZE].copy_from_slice(&operation);
        instructions_binary[i * INSTRUCTION_SIZE + OPERATION_SIZE .. i * INSTRUCTION_SIZE + OPERATION_SIZE + OPERAND_SIZE].copy_from_slice(&binarize_operand(&variables_table, &labels_table, &instruction.operand1));
        instructions_binary[i * INSTRUCTION_SIZE + OPERATION_SIZE + OPERAND_SIZE .. i * INSTRUCTION_SIZE + OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE].copy_from_slice(&binarize_operand(&variables_table, &labels_table, &instruction.operand2));
    }

    // Write out final binary.
    let mut output_file = fs::File::create(output_file_name).expect("ERROR: Failed to open binary output file for writing.");
    output_file.write_all(&(variables_binary_size as RawProcessorOperand).to_le_bytes()).expect("ERROR: Failed to write initial .data: section length to binary file.");
    output_file.write_all(&variables_binary).expect("ERROR: Failed to write .data: section to binary file.");
    output_file.write_all(&instructions_binary).expect("ERROR: Failed to write .code: section to binary file.");
}
