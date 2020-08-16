#include "ast.h"
#include "processor.h"
#include <sstream>
#include <fstream>

#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include <string>
#include <memory>
#include <cstdlib>

void ASTRootNode::addStatement(ASTStatementNode *node) {
    children.push_back(node);
}

std::string ASTRootNode::generateGraphvizCode(int level, int node_id, ASTNode *statement) {
    std::stringstream output;

    std::string my_identifier = fmt::format("\"{}_{}\"", level, node_id);

    if (statement->getNodeType() == ROOT_NODE) {
        output << "digraph ast {" << std::endl;
        output << fmt::format("    {} [label=\"{}\", shape=box];\n", my_identifier, statement->getHumanReadable());
        for (int i = 0; i < children.size(); i++) {
            output << generateGraphvizCode(level + 1, i, children[i]);
            output << fmt::format("    {} -> \"{}_{}\";\n", my_identifier, level + 1, i);
        }
        output << "}" << std::endl;
    }
    else if (statement->getNodeType() == VARIABLE_DECLARATION_NODE) {
        output << fmt::format("    {} [label=\"{}\", shape=box];\n", my_identifier, statement->getHumanReadable());
    }
    else if (statement->getNodeType() == VARIABLE_ASSIGNMENT_NODE) {
        output << fmt::format("    {} [label=\"{}\", shape=box];\n", my_identifier, statement->getHumanReadable());
        ASTVariableAssignmentNode *variable_assignment = (ASTVariableAssignmentNode *) statement;
        output << generateGraphvizCode(level + 1, 0, variable_assignment->getExpressionNode());
        output << fmt::format("    {} -> \"{}_0\";\n", my_identifier, level + 1);
    }
    else if (statement->getNodeType() == EXPRESSION_NODE) {
        output << fmt::format("    {} [label=\"{}\", shape=box];\n", my_identifier, statement->getHumanReadable());
        ASTExpressionNode *expression = (ASTExpressionNode *) statement;
        std::vector<ASTTermNode*> terms = expression->getTerms();
        for (int i = 0; i < terms.size(); i++) {
            output << generateGraphvizCode(level + 1, i, terms[i]);
            output << fmt::format("    {} -> \"{}_{}\";\n", my_identifier, level + 1, i);
        }
    }
    else if (statement->getNodeType() == TERM_NODE) {
        output << fmt::format("    {} [label=\"{}\", shape=box];\n", my_identifier, statement->getHumanReadable());
    }

    return output.str();
}

ASTNodeType ASTRootNode::getNodeType() {
    return ROOT_NODE;
}

std::string ASTRootNode::getHumanReadable() {
    return "Root";
}

void ASTRootNode::showGraph() {
    std::ofstream graphviz_file;
    graphviz_file.open("graph_temp.dot");
    graphviz_file << generateGraphvizCode(0, 0, this);
    graphviz_file.close();
    std::system("dot -Tpdf graph_temp.dot -o graph_temp.pdf");
    std::system("xdg-open graph_temp.pdf");
}

ASTVariableDeclarationNode::ASTVariableDeclarationNode(std::string variable_name) {
    this->variable_name = variable_name;
    this->value = 0;
}

ASTVariableDeclarationNode::ASTVariableDeclarationNode(std::string variable_name, OPERAND_C_TYPE value) {
    this->variable_name = variable_name;
    this->value = value;
}

ASTNodeType ASTVariableDeclarationNode::getNodeType() {
    return VARIABLE_DECLARATION_NODE;
}

std::string ASTVariableDeclarationNode::getHumanReadable() {
    return fmt::format("Declare `{}` as {}.", variable_name, value);
}

ASTTermNode::ASTTermNode(TermNodeSign sign, OPERAND_C_TYPE constant_value) {
    this->sign = sign;
    this->constant_value = constant_value;
    this->type = CONSTANT;
}

ASTTermNode::ASTTermNode(TermNodeSign sign, std::string variable_name) {
    this->sign = sign;
    this->variable_name = variable_name;
    this->type = VARIABLE;
}

ASTNodeType ASTTermNode::getNodeType() {
    return TERM_NODE;
}

std::string ASTTermNode::getHumanReadable() {
    std::stringstream human_readable;
    if (sign == POSITIVE) {
        human_readable << "+ ";
    }
    else {
        human_readable << "- ";
    }
    if (type == VARIABLE) {
        human_readable << variable_name;
    }
    else {
        human_readable << constant_value;
    }
    return human_readable.str();
}

void ASTExpressionNode::addTerm(ASTTermNode *term) {
    terms.push_back(term);
}

ASTNodeType ASTExpressionNode::getNodeType() {
    return EXPRESSION_NODE;
}

std::string ASTExpressionNode::getHumanReadable() {
    return "Expression";
}

std::vector<ASTTermNode*> ASTExpressionNode::getTerms() {
    return terms;
}

ASTVariableAssignmentNode::ASTVariableAssignmentNode(std::string variable_name, ASTExpressionNode *value) {
    this->variable_name = variable_name;
    this->value = value;
}

ASTNodeType ASTVariableAssignmentNode::getNodeType() {
    return VARIABLE_ASSIGNMENT_NODE;
}

ASTExpressionNode *ASTVariableAssignmentNode::getExpressionNode() {
    return value;
}

std::string ASTVariableAssignmentNode::getHumanReadable() {
    return fmt::format("Assign variable `{}`.", variable_name);
}
