#ifndef AST_BUFFER_WRITE_NODE_H
#define AST_BUFFER_WRITE_NODE_H

#include "ast.h"
#include "asttermnode.h"
#include "aststatementnode.h"
#include "astexpressionnode.h"

#include <string>

class ASTBufferWriteNode : public ASTStatementNode {
    std::string variable_name;

    OPERAND_C_TYPE offset_constant_value;
    std::string offset_variable_value;

    ASTExpressionNode *value_expression;

    TermNodeType type;

    public:
        ASTBufferWriteNode(std::string variable_name, OPERAND_C_TYPE offset_constant_value, ASTExpressionNode *value_expression);
        ASTBufferWriteNode(std::string variable_name, std::string offset_variable_value, ASTExpressionNode *value_expression);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        OPERAND_C_TYPE getOffsetConstantValue();
        std::string getOffsetVariableValue();
        ASTExpressionNode *getValueExpression();
        std::string getVariableName();
        TermNodeType getType();
        ~ASTBufferWriteNode();
};

#endif // AST_BUFFER_WRITE_NODE_H
