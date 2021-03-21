#ifndef AST_WHILE_LOOP_NODE_H
#define AST_WHILE_LOOP_NODE_H

#include "ast.h"
#include "aststatementnode.h"
#include "astconditionnode.h"
#include "astbeginendblocknode.h"

#include <string>

class ASTWhileLoopNode : public ASTStatementNode {
    ASTConditionNode *condition;
    ASTBeginEndBlockNode *begin_end_block;

    public:
        ASTWhileLoopNode(ASTConditionNode *condition, ASTBeginEndBlockNode *begin_end_block);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        ASTConditionNode *getCondition();
        ASTBeginEndBlockNode *getBeginEndBlock();
        ~ASTWhileLoopNode();
};

#endif // AST_WHILE_LOOP_NODE_H
