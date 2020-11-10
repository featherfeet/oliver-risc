#include "astwhileloopnode.h"

ASTWhileLoopNode::ASTWhileLoopNode(ASTConditionNode *condition, ASTBeginEndBlockNode *begin_end_block) {
    this->condition = condition;
    this->begin_end_block = begin_end_block;
}

ASTNodeType ASTWhileLoopNode::getNodeType() {
    return WHILE_LOOP_NODE;
}

std::string ASTWhileLoopNode::getHumanReadable() {
    return "While Loop";
}

ASTConditionNode *ASTWhileLoopNode::getCondition() {
    return condition;
}

ASTBeginEndBlockNode *ASTWhileLoopNode::getBeginEndBlock() {
    return begin_end_block;
}

ASTWhileLoopNode::~ASTWhileLoopNode() {
    delete condition;
    delete begin_end_block;
}
