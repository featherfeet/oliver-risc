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
    BEGIN_END_BLOCK_NODE,
    PROCEDURE_CALL_NODE,
    WHILE_LOOP_NODE,
    PROCEDURE_NODE
};

class ASTNode {
    public:
        virtual ASTNodeType getNodeType() = 0;
        virtual std::string getHumanReadable() = 0;
        virtual ~ASTNode() = 0;
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
        ~ASTRootNode();
};

class ASTBeginEndBlockNode : public ASTStatementNode {
    std::vector<ASTStatementNode*> children;
    public:
        ASTNodeType getNodeType();
        void addStatement(ASTStatementNode *node);
        std::string getHumanReadable();
        std::vector<ASTStatementNode*> getChildren();
        ~ASTBeginEndBlockNode();
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

enum TermNodeOperation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULUS
};

enum TermNodeType {
    VARIABLE,
    CONSTANT
};

class ASTTermNode : public ASTNode {
    TermNodeOperation operation;
    TermNodeType type;
    OPERAND_C_TYPE constant_value;
    std::string variable_name;

    public:
        ASTTermNode(TermNodeOperation operation, OPERAND_C_TYPE constant_value);
        ASTTermNode(TermNodeOperation operation, std::string variable_name);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        TermNodeOperation getOperation();
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
        ~ASTExpressionNode();
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
        ~ASTConditionNode();
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
        ~ASTConditionalNode();
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
        ~ASTVariableAssignmentNode();
};

class ASTProcedureCallNode : public ASTStatementNode {
    std::string procedure_name;

    public:
        ASTProcedureCallNode(std::string procedure_name);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
        std::string getProcedureName();
};

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

#endif // AST_H
