use crate::intermediaterepresentation::IRAction;

pub trait ASTNode {
    fn describe(&self) -> String;
    fn compile(&self) -> Vec<IRAction>;
}

pub trait ASTStatement : ASTNode {
}

pub struct ASTVariableDeclaration {
    datatype: ASTType,
    name: String,
    value: ASTExpression
}

impl ASTNode for ASTVariableDeclaration {
    fn describe(&self) -> String {
        format!("Declaration: {}", self.name)
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

pub struct ASTRoot {
    statements: Vec<Box<dyn ASTStatement>>
}

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

pub struct ASTType {
    basetype: ASTBaseType,
    pointers: usize
}

impl ASTNode for ASTType {
    fn describe(&self) -> String {
        format!("Type {}{}", "*".repeat(self.pointers), self.basetype.describe())
    }

    fn compile(&self) -> Vec<IRAction> {
        vec![]
    }
}

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
