#ifndef AST_NODE_H
#define AST_NODE_H

#include "ast.h"

#include <string>

class ASTNode {
    public:
        virtual ASTNodeType getNodeType() = 0;
        virtual std::string getHumanReadable() = 0;
        virtual ~ASTNode() = 0;
};

#endif // AST_NODE_H
