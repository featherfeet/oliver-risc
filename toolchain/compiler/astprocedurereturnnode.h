#ifndef AST_PROCEDURE_RETURN_NODE_H
#define AST_PROCEDURE_RETURN_NODE_H

#include "ast.h"
#include "aststatementnode.h"

#include <string>

class ASTProcedureReturnNode : public ASTStatementNode {
    public:
        ASTNodeType getNodeType();
        std::string getHumanReadable();
};

#endif // AST_WHILE_LOOP_NODE_H
