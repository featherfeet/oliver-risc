#ifndef AST_BUFFER_READ_NODE_H
#define AST_BUFFER_READ_NODE_H

#include "ast.h"
#include "astnode.h"
#include "asttermnode.h"
#include "astexpressionnode.h"

#include <string>

class ASTBufferReadNode : public ASTNode {
    TermNodeOperation operation;
    std::string variable_name;
    ASTExpressionNode *offset_expression;

    public:
        ASTBufferReadNode(TermNodeOperation operation, std::string variable_name, ASTExpressionNode *offset_expression);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        ASTExpressionNode *getOffsetExpression();
        std::string getVariableName();
        TermNodeOperation getOperation();
        ~ASTBufferReadNode();
};

#endif // AST_BUFFER_READ_NODE_H
