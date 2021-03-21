#include "astbeginendblocknode.h"

void ASTBeginEndBlockNode::addStatement(ASTStatementNode *statement) {
    children.push_back(statement);
}

ASTBeginEndBlockNode::~ASTBeginEndBlockNode() {
    for (auto statement_node : children) {
        delete statement_node;
    }
}

ASTNodeType ASTBeginEndBlockNode::getNodeType() {
    return BEGIN_END_BLOCK_NODE;
}

std::string ASTBeginEndBlockNode::getHumanReadable() {
    return "begin . . . end block";
}

std::vector<ASTStatementNode*> ASTBeginEndBlockNode::getChildren() {
    return children;
}
