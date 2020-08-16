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
    TERM_NODE
};

class ASTNode {
    public:
        virtual ASTNodeType getNodeType() = 0;
        virtual std::string getHumanReadable() = 0;
};

class ASTStatementNode : public ASTNode {
};

class ASTRootNode : ASTNode {
    std::string generateGraphvizCode(int level, int node_id, ASTNode *statement);

    std::vector<ASTStatementNode*> children;
    public:
        void addStatement(ASTStatementNode *node);
        void showGraph();
        ASTNodeType getNodeType();
        std::string getHumanReadable();
};

class ASTVariableDeclarationNode : public ASTStatementNode {
    std::string variable_name;
    OPERAND_C_TYPE value;

    public:
        ASTVariableDeclarationNode(std::string variable_name);
        ASTVariableDeclarationNode(std::string variable_name, OPERAND_C_TYPE value);
        ASTNodeType getNodeType();
        std::string getHumanReadable();
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
};

class ASTExpressionNode : public ASTNode {
    std::vector<ASTTermNode*> terms;

    public:
        void addTerm(ASTTermNode *term);
        ASTNodeType getNodeType();
        std::vector<ASTTermNode*> getTerms();
        std::string getHumanReadable();
};

class ASTVariableAssignmentNode : public ASTStatementNode {
    std::string variable_name;
    ASTExpressionNode *value;

    public:
        ASTVariableAssignmentNode(std::string variable_name, ASTExpressionNode *value);
        ASTExpressionNode *getExpressionNode();
        ASTNodeType getNodeType();
        std::string getHumanReadable();
};

#endif // AST_H
