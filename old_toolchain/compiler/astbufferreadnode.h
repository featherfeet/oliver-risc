#ifndef AST_BUFFER_READ_NODE_H
#define AST_BUFFER_READ_NODE_H

#include "ast.h"
#include "astnode.h"
#include "asttermnode.h"
#include "astexpressionnode.h"

#include <string>

class ASTBufferReadNode : public ASTNode {
    TermNodeOperation operation;
    TermNodeType type;
    std::string variable_name;
    OPERAND_C_TYPE constant_value;
    std::string variable_value;

    public:
        ASTBufferReadNode(TermNodeOperation operation, std::string variable_name, OPERAND_C_TYPE constant_value);
        ASTBufferReadNode(TermNodeOperation operation, std::string variable_name, std::string variable_value);
        ASTNodeType getNodeType();
        TermNodeType getType();
        std::string getHumanReadable();
        std::string getVariableName();
        TermNodeOperation getOperation();
        OPERAND_C_TYPE getConstantValue();
        std::string getVariableValue();
};

#endif // AST_BUFFER_READ_NODE_H
