#ifndef AST_EXPRESSION_NODE_H
#define AST_EXPRESSION_NODE_H

#include "ast.h"
#include "astnode.h"

#include <string>
#include <vector>

class ASTExpressionNode : public ASTNode {
    std::vector<ASTNode*> terms;

    public:
        void addTerm(ASTNode *term);
        ASTNodeType getNodeType();
        std::vector<ASTNode*> getTerms();
        std::string getHumanReadable();
        ~ASTExpressionNode();
};

#endif // AST_EXPRESSION_NODE_H
