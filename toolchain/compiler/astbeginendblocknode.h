#ifndef AST_BEGIN_END_BLOCK_NODE_H
#define AST_BEGIN_END_BLOCK_NODE_H

#include "ast.h"
#include "aststatementnode.h"

#include <string>
#include <vector>

class ASTBeginEndBlockNode : public ASTStatementNode {
    std::vector<ASTStatementNode*> children;
    public:
        ASTNodeType getNodeType();
        void addStatement(ASTStatementNode *node);
        std::string getHumanReadable();
        std::vector<ASTStatementNode*> getChildren();
        ~ASTBeginEndBlockNode();
};

#endif // AST_BEGIN_END_BLOCK_NODE_H
