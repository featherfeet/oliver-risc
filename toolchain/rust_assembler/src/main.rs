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
    pest_ascii_tree::print_ascii_tree(parsed_assembly.clone());
    let program = parsed_assembly.expect("Failed to parse assembly!").next().expect("No program found.").into_inner();
}
