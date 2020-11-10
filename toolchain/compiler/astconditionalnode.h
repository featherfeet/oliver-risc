#ifndef AST_CONDITIONAL_NODE_H
#define AST_CONDITIONAL_NODE_H

#include "ast.h"
#include "astconditionnode.h"
#include "aststatementnode.h"
#include "astbeginendblocknode.h"

#include <string>

class ASTConditionalNode : public ASTStatementNode {
    ASTConditionNode *condition;
    ASTBeginEndBlockNode *begin_end_block;

    public:
        ASTConditionalNode(ASTConditionNode *condition, ASTBeginEndBlockNode *begin_end_block);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        ASTConditionNode *getCondition();
        ASTBeginEndBlockNode *getBeginEndBlock();
        ~ASTConditionalNode();
};

#endif // AST_CONDITIONAL_NODE_H
