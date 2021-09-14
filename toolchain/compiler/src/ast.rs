use crate::intermediaterepresentation::IRAction;
use core::fmt::Debug;

pub trait ASTNode {
    fn describe(&self) -> String;
    fn compile(&self) -> Vec<IRAction>;
}

pub trait ASTStatement : ASTNode + std::fmt::Debug {
}

#[derive(Debug)]
pub struct ASTVariableDeclaration {
    datatype: ASTType,
    name: String,
    value: ASTExpression
}

impl ASTVariableDeclaration {
    pub fn new(datatype: ASTType, name: String, value: ASTExpression) -> ASTVariableDeclaration {
        ASTVariableDeclaration { datatype, name, value }
    }
}

impl ASTNode for ASTVariableDeclaration {
    fn describe(&self) -> String {
        format!("Declaration: {}", self.name)
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

impl ASTStatement for ASTVariableDeclaration {
}

#[derive(Debug)]
pub struct ASTRoot {
    pub statements: Vec<Box<dyn ASTStatement>>
}

impl ASTNode for ASTRoot {
    fn describe(&self) -> String {
        format!("Root node")
    }
    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

impl ASTRoot {
    pub fn new(statements: Vec<Box<dyn ASTStatement>>) -> ASTRoot {
        ASTRoot {
            statements
        }
    }
}

#[derive(Debug)]
pub enum ASTBaseType {
    Integer,
    Character
}

impl ASTNode for ASTBaseType {
    fn describe(&self) -> String {
        format!("Base type")
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

#[derive(Debug)]
pub struct ASTType {
    basetype: ASTBaseType,
    pointers: usize
}

impl ASTType {
    pub fn new(basetype: ASTBaseType, pointers: usize) -> ASTType {
        ASTType { basetype, pointers }
    }
}

impl ASTNode for ASTType {
    fn describe(&self) -> String {
        format!("Type {}{}", "*".repeat(self.pointers), self.basetype.describe())
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

#[derive(Debug)]
pub enum ASTExpression {
    Addition { lhs: Box<ASTExpression>, rhs: Box<ASTExpression> },
    Subtraction { lhs: Box<ASTExpression>, rhs: Box<ASTExpression> },
    Division { lhs: Box<ASTExpression>, rhs: Box<ASTExpression> },
    Multiplication { lhs: Box<ASTExpression>, rhs: Box<ASTExpression> },
    Modulus { lhs: Box<ASTExpression>, rhs: Box<ASTExpression> },
    Value { value: ASTValue }
}

impl ASTNode for ASTExpression {
    fn describe(&self) -> String {
        format!("Expression")
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

#[derive(Debug)]
pub enum ASTValue {
    Constant { constant: ASTConstant },
    Variable { name: String }
    /*
    Function
    FunctionCall
    */
}

impl ASTNode for ASTValue {
    fn describe(&self) -> String {
        format!("Value")
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

#[derive(Debug)]
pub enum ASTConstant {
    Integer { value: i32 },
    Character { value: u8 }
}

impl ASTNode for ASTConstant {
    fn describe(&self) -> String {
        format!("Constant")
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}
