#ifndef AST_INLINE_ASSEMBLY_NODE_H
#define AST_INLINE_ASSEMBLY_NODE_H

#include "ast.h"
#include "aststatementnode.h"

#include <string>

class ASTInlineAssemblyNode : public ASTStatementNode {
    std::string inline_assembly;

    public:
        ASTInlineAssemblyNode(std::string inline_assembly);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::string getInlineAssembly();
};

#endif // AST_INLINE_ASSEMBLY_NODE_H
