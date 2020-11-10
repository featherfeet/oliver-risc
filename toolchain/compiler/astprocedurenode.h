#ifndef AST_PROCEDURE_NODE_H
#define AST_PROCEDURE_NODE_H

#include "ast.h"
#include "aststatementnode.h"
#include "astbeginendblocknode.h"

#include <string>

class ASTProcedureNode : public ASTStatementNode {
    std::string procedure_name;
    ASTBeginEndBlockNode *begin_end_block;

    public:
        ASTProcedureNode(std::string procedure_name, ASTBeginEndBlockNode *begin_end_block);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::string getProcedureName();
        ASTBeginEndBlockNode *getBeginEndBlock();
        ~ASTProcedureNode();
};

#endif // AST_PROCEDURE_NODE_H
