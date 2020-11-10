#include "astconditionalnode.h"

ASTConditionalNode::ASTConditionalNode(ASTConditionNode *condition, ASTBeginEndBlockNode *begin_end_block) {
    this->condition = condition;
    this->begin_end_block = begin_end_block;
}

ASTNodeType ASTConditionalNode::getNodeType() {
    return CONDITIONAL_NODE;
}

std::string ASTConditionalNode::getHumanReadable() {
    return "Conditional";
}

ASTConditionNode *ASTConditionalNode::getCondition() {
    return condition;
}

ASTBeginEndBlockNode *ASTConditionalNode::getBeginEndBlock() {
    return begin_end_block;
}

ASTConditionalNode::~ASTConditionalNode() {
    delete condition;
    delete begin_end_block;
}
