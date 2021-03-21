#include "astexpressionnode.h"

void ASTExpressionNode::addTerm(ASTNode *term) {
    terms.push_back(term);
}

ASTNodeType ASTExpressionNode::getNodeType() {
    return EXPRESSION_NODE;
}

std::string ASTExpressionNode::getHumanReadable() {
    return "Expression";
}

std::vector<ASTNode*> ASTExpressionNode::getTerms() {
    return terms;
}

ASTExpressionNode::~ASTExpressionNode() {
    for (auto term : terms) {
        delete term;
    }
}
