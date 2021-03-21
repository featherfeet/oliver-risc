#ifndef AST_PROCEDURE_CALL_NODE_H
#define AST_PROCEDURE_CALL_NODE_H

#include "ast.h"
#include "aststatementnode.h"

#include <string>

class ASTProcedureCallNode : public ASTStatementNode {
    std::string procedure_name;

    public:
        ASTProcedureCallNode(std::string procedure_name);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::string getProcedureName();
};

#endif // AST_PROCEDURE_CALL_NODE_H
