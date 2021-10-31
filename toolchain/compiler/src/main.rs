mod intermediaterepresentation;

extern crate pest;
#[macro_use]
extern crate pest_derive;

use std::env;
use std::fs;
use pest::iterators::{ Pair, Pairs };
use pest::Parser;
use crate::ast::*;

mod ast;

#[derive(Parser)]
#[grammar = "language.pest"]
struct LanguageParser;

fn parse_ast_root(program: Pairs<'_, Rule>) -> Result<ASTRoot, &'static str> {
    let mut statements = Vec::<Box<dyn ASTStatement>>::new();

    for statement_outer in program {
        let statement_option = statement_outer.into_inner().next();

        match statement_option {
            Some(statement) => {
                match statement.clone().as_rule() {
                    Rule::variable_declaration => {
                        println!("Variable declaration found.");
                        statements.push(Box::new(parse_ast_variable_declaration(statement)?));
                    }
                    _ => println!("Unimplemented.")
                }
            }
            None => {}
        }
    }

    Ok(ASTRoot::new(statements))
}

fn parse_ast_datatype(pair: Pair<'_, Rule>) -> Result<ASTType, &'static str> {
    let mut inner = pair.into_inner();
    let basetype_pair = inner.next().ok_or("Failed to parse AST datatype base type.")?.into_inner().next().ok_or("Failed to parse AST datatype base type.")?;
    let pointers = inner.next().ok_or("Failed to parse AST datatype pointers.")?.as_span().as_str().matches("*").count();
    let basetype = match basetype_pair.as_rule() {
        Rule::integer_type => ASTBaseType::Integer,
        Rule::character_type => ASTBaseType::Character,
        _ => {
            println!("Warning: Unrecognized base datatype, defaulting to integer type.");
            ASTBaseType::Integer
        }
    };
    Ok(ASTType::new(basetype, pointers))
}

fn parse_ast_expression(pair: Pair<'_, Rule>) -> Result<ASTExpression, &'static str> {
    println!("{:#?}", pair);
    Ok(ASTExpression::Value { value: ASTValue::Variable { name: "UNIMPLEMENTED".to_string() } })
}

fn parse_ast_variable_declaration(statement: Pair<'_, Rule>) -> Result<ASTVariableDeclaration, &'static str> {
    let mut inner = statement.into_inner();
    let datatype = parse_ast_datatype(inner.next().ok_or("Failed to parse AST datatype.")?)?;
    let name = inner.next().ok_or("Failed to get AST variable name.")?.as_span().as_str().to_string();
    let value = parse_ast_expression(inner.next().ok_or("Failed to parse AST expression.")?)?;
    Ok(ASTVariableDeclaration::new(datatype, name, value))
}

fn main() {
    // Read in the input  file.
    let args: Vec<String> = env::args().collect();
    let input_file_path = args.get(1).expect("No file path provided!");
    let raw_input = fs::read_to_string(input_file_path).expect("Failed to read input file.");

    // Parse the input file.
    let parsed_input = LanguageParser::parse(Rule::program, &raw_input);
    pest_ascii_tree::print_ascii_tree(parsed_input.clone());
    let program = parsed_input.expect("Failed to parse input!").next().expect("No program found.").into_inner();

    // Generate an AST.
    let ast = parse_ast_root(program).unwrap();

    println!("{:#?}", ast);
}
