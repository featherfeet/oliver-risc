#include "astconditionnode.h"

ASTConditionNode::ASTConditionNode(ConditionNodeComparison comparison, ASTExpressionNode *expression1, ASTExpressionNode *expression2) {
    this->comparison = comparison;
    this->expression1 = expression1;
    this->expression2 = expression2;
}

ASTNodeType ASTConditionNode::getNodeType() {
    return CONDITION_NODE;
}

std::string ASTConditionNode::getHumanReadable() {
    if (comparison == NOT_EQUALS) {
        return "Condition: #";
    }
    else if (comparison == EQUALS) {
        return "Condition: =";
    }
    else if (comparison == LESS_THAN) {
        return "Condition: <";
    }
    else if (comparison == LESS_THAN_OR_EQUAL_TO) {
        return "Condition: <=";
    }
    else if (comparison == GREATER_THAN) {
        return "Condition: >";
    }
    else if (comparison == GREATER_THAN_OR_EQUAL_TO) {
        return "Condition: >=";
    }
    return "Condition: unknown";
}

ConditionNodeComparison ASTConditionNode::getComparison() {
    return comparison;
}

ASTConditionNode::~ASTConditionNode() {
    delete expression1;
    delete expression2;
}

ASTExpressionNode *ASTConditionNode::getExpression1() {
    return expression1;
}

ASTExpressionNode *ASTConditionNode::getExpression2() {
    return expression2;
}
