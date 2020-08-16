#include "ast.h"
#include "processor.h"
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <cstdlib>

void ASTRootNode::addStatement(ASTStatementNode *node) {
    children.push_back(node);
}

std::string ASTRootNode::generateGraphvizCode(int level, int node_id, ASTNode *statement) {
    std::stringstream output;

    std::stringstream my_identifier_sstream;
    my_identifier_sstream << "\"" << level << "_" << node_id << "\"";
    std::string my_identifier = my_identifier_sstream.str();

    if (statement->getNodeType() == ROOT_NODE) {
        output << "digraph ast {" << std::endl;
        output << "    " << my_identifier << " [label=\"" << statement->getHumanReadable() << "\", shape=box];" << std::endl;
        for (int i = 0; i < children.size(); i++) {
            output << generateGraphvizCode(level + 1, i, children[i]);
            output << "    " << my_identifier << " -> \"" << level + 1 << "_" << i << "\"" << std::endl;
        }
        output << "}" << std::endl;
    }
    else if (statement->getNodeType() == VARIABLE_DECLARATION_NODE) {
        output << "    " << my_identifier << " [label=\"" << statement->getHumanReadable() << "\", shape=box];" << std::endl;
    }
    else if (statement->getNodeType() == VARIABLE_ASSIGNMENT_NODE) {
        output << "    " << my_identifier << " [label=\"" << statement->getHumanReadable() << "\", shape=box];" << std::endl;
        ASTVariableAssignmentNode *variable_assignment = (ASTVariableAssignmentNode *) statement;
        output << generateGraphvizCode(level + 1, 0, variable_assignment->getExpressionNode());
        output << "    " << my_identifier << " -> \"" << level + 1 << "_" << 0 << "\";" << std::endl;
    }
    else if (statement->getNodeType() == EXPRESSION_NODE) {
        output << "    " << my_identifier << " [label=\"" << statement->getHumanReadable() << "\", shape=box];" << std::endl;
        ASTExpressionNode *expression = (ASTExpressionNode *) statement;
        std::vector<ASTTermNode*> terms = expression->getTerms();
        for (int i = 0; i < terms.size(); i++) {
            output << generateGraphvizCode(level + 1, i, terms[i]);
            output << "    " << my_identifier << " -> \"" << level + 1 << "_" << i << "\"" << std::endl;
        }
    }
    else if (statement->getNodeType() == TERM_NODE) {
        output << "    " << my_identifier << " [label=\"" << statement->getHumanReadable() << "\", shape=box];" << std::endl;
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
    std::stringstream human_readable;
    human_readable << "Declare `" << variable_name << "` as " << value << ".";
    return human_readable.str();
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
    std::stringstream human_readable;
    human_readable << "Assign variable `" << variable_name << "`.";
    return human_readable.str();
}
