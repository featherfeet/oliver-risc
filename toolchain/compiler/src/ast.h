#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <ostream>
#include "processor.h"

enum ASTNodeType {
    ROOT_NODE,
    VARIABLE_DECLARATION_NODE,
    VARIABLE_ASSIGNMENT_NODE,
    EXPRESSION_NODE,
    TERM_NODE,
    CONDITION_NODE,
    CONDITIONAL_NODE,
    BEGIN_END_BLOCK_NODE
};

class ASTNode {
    public:
        virtual ASTNodeType getNodeType() = 0;
        virtual std::string getHumanReadable() = 0;
};

class ASTStatementNode : public ASTNode {
};

class ASTRootNode : public ASTNode {
    std::string generateGraphvizCode(std::string node_id, ASTNode *statement);

    std::vector<ASTStatementNode*> children;
    public:
        void addStatement(ASTStatementNode *node);
        void showGraph();
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::vector<ASTStatementNode*> getChildren();
};

class ASTBeginEndBlockNode : public ASTStatementNode {
    std::vector<ASTStatementNode*> children;
    public:
        ASTNodeType getNodeType();
        void addStatement(ASTStatementNode *node);
        std::string getHumanReadable();
        std::vector<ASTStatementNode*> getChildren();
};

class ASTVariableDeclarationNode : public ASTStatementNode {
    std::string variable_name;
    OPERAND_C_TYPE value;

    public:
        ASTVariableDeclarationNode(std::string variable_name);
        ASTVariableDeclarationNode(std::string variable_name, OPERAND_C_TYPE value);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::string getVariableName();
        OPERAND_C_TYPE getValue();
};

enum TermNodeSign {
    POSITIVE,
    NEGATIVE
};

enum TermNodeType {
    VARIABLE,
    CONSTANT
};

class ASTTermNode : public ASTNode {
    TermNodeSign sign;
    TermNodeType type;
    OPERAND_C_TYPE constant_value;
    std::string variable_name;

    public:
        ASTTermNode(TermNodeSign sign, OPERAND_C_TYPE constant_value);
        ASTTermNode(TermNodeSign sign, std::string variable_name);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        TermNodeSign getSign();
        TermNodeType getType();
        OPERAND_C_TYPE getConstantValue();
        std::string getVariableName();
};

class ASTExpressionNode : public ASTNode {
    std::vector<ASTTermNode*> terms;

    public:
        void addTerm(ASTTermNode *term);
        ASTNodeType getNodeType();
        std::vector<ASTTermNode*> getTerms();
        std::string getHumanReadable();
};

enum ConditionNodeComparison {
    NOT_EQUALS,
    EQUALS,
    LESS_THAN,
    LESS_THAN_OR_EQUAL_TO,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL_TO
};

class ASTConditionNode : public ASTNode {
    ConditionNodeComparison comparison;
    ASTExpressionNode *expression1;
    ASTExpressionNode *expression2;

    public:
        ASTConditionNode(ConditionNodeComparison comparison, ASTExpressionNode *expression1, ASTExpressionNode *expression2);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        ConditionNodeComparison getComparison();
        ASTExpressionNode *getExpression1();
        ASTExpressionNode *getExpression2();
};

class ASTConditionalNode : public ASTStatementNode {
    ASTConditionNode *condition;
    ASTBeginEndBlockNode *begin_end_block;

    public:
        ASTConditionalNode(ASTConditionNode *condition, ASTBeginEndBlockNode *begin_end_block);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        ASTConditionNode *getCondition();
        ASTBeginEndBlockNode *getBeginEndBlock();
};

class ASTVariableAssignmentNode : public ASTStatementNode {
    std::string variable_name;
    ASTExpressionNode *value;

    public:
        ASTVariableAssignmentNode(std::string variable_name, ASTExpressionNode *value);
        ASTExpressionNode *getExpressionNode();
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::string getVariableName();
};

#endif // AST_H
