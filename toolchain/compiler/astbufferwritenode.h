#ifndef AST_BUFFER_WRITE_NODE_H
#define AST_BUFFER_WRITE_NODE_H

#include "ast.h"
#include "aststatementnode.h"
#include "astexpressionnode.h"

#include <string>

class ASTBufferWriteNode : public ASTStatementNode {
    std::string variable_name;
    ASTExpressionNode *offset_expression;
    ASTExpressionNode *value_expression;

    public:
        ASTBufferWriteNode(std::string variable_name, ASTExpressionNode *offset_expression, ASTExpressionNode *value_expression);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        ASTExpressionNode *getOffsetExpression();
        ASTExpressionNode *getValueExpression();
        std::string getVariableName();
        ~ASTBufferWriteNode();
};

#endif // AST_BUFFER_WRITE_NODE_H
