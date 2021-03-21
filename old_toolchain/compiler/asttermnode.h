#ifndef AST_TERM_NODE_H
#define AST_TERM_NODE_H

#include "processor.h"
#include "ast.h"
#include "astnode.h"
#include "asttermnode.h"

#include <string>

enum TermNodeOperation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULUS
};

enum TermNodeType {
    VARIABLE,
    CONSTANT
};

class ASTTermNode : public ASTNode {
    TermNodeOperation operation;
    TermNodeType type;
    OPERAND_C_TYPE constant_value;
    std::string variable_name;
    public:
        ASTTermNode(TermNodeOperation operation, OPERAND_C_TYPE constant_value);
        ASTTermNode(TermNodeOperation operation, std::string variable_name);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        TermNodeOperation getOperation();
        TermNodeType getType();
        OPERAND_C_TYPE getConstantValue();
        std::string getVariableName();
};

#endif // AST_TERM_NODE_H
