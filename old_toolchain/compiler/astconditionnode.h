#ifndef AST_CONDITION_NODE_H
#define AST_CONDITION_NODE_H

#include "ast.h"
#include "astnode.h"
#include "astexpressionnode.h"

#include <string>

enum ConditionNodeComparison {
    NOT_EQUALS,
    EQUALS,
    LESS_THAN,
    LESS_THAN_OR_EQUAL_TO,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL_TO
};

class ASTConditionNode : public ASTNode {
    ConditionNodeComparison comparison;
    ASTExpressionNode *expression1;
    ASTExpressionNode *expression2;

    public:
        ASTConditionNode(ConditionNodeComparison comparison, ASTExpressionNode *expression1, ASTExpressionNode *expression2);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        ConditionNodeComparison getComparison();
        ASTExpressionNode *getExpression1();
        ASTExpressionNode *getExpression2();
        ~ASTConditionNode();
};

#endif // AST_CONDITION_NODE_H
