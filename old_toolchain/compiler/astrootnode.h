#ifndef AST_ROOT_NODE_H
#define AST_ROOT_NODE_H

#include "ast.h"
#include "astnode.h"
#include "aststatementnode.h"

#include <string>
#include <vector>

class ASTRootNode : public ASTNode {
    std::string generateGraphvizCode(std::string node_id, ASTNode *statement);

    std::vector<ASTStatementNode*> children;
    public:
        void addStatement(ASTStatementNode *node);
        void showGraph();
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::vector<ASTStatementNode*> getChildren();
        ~ASTRootNode();
};

#endif // AST_ROOT_NODE_H
