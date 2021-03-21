#ifndef AST_VARIABLE_ASSIGNMENT_NODE_H
#define AST_VARIABLE_ASSIGNMENT_NODE_H

#include "ast.h"
#include "aststatementnode.h"
#include "astexpressionnode.h"

#include <string>

class ASTVariableAssignmentNode : public ASTStatementNode {
    std::string variable_name;
    ASTExpressionNode *value;

    public:
        ASTVariableAssignmentNode(std::string variable_name, ASTExpressionNode *value);
        ASTExpressionNode *getExpressionNode();
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::string getVariableName();
        ~ASTVariableAssignmentNode();
};

#endif // AST_VARIABLE_ASSIGNMENT_NODE_H
