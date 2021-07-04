mod intermediaterepresentation;

extern crate pest;
#[macro_use]
extern crate pest_derive;

use std::env;
use std::fs;
use pest::iterators::Pair;
use pest::Parser;

mod ast;

#[derive(Parser)]
#[grammar = "language.pest"]
struct LanguageParser;

fn main() {
    // Read in the input  file.
    let args: Vec<String> = env::args().collect();
    let input_file_path = args.get(1).expect("No file path provided!");
    let raw_input = fs::read_to_string(input_file_path).expect("Failed to read input file.");

    // Parse the input file.
    let parsed_input = LanguageParser::parse(Rule::program, &raw_input);
    pest_ascii_tree::print_ascii_tree(parsed_input.clone());
    let program = parsed_input.expect("Failed to parse input!").next().expect("No program found.").into_inner();
}
