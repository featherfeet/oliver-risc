#include "ast.h"
#include "processor.h"
#include <sstream>
#include <fstream>

#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include <string>
#include <memory>
#include <cstdlib>

#include <iostream> // TODO: REMOVE

ASTNode::~ASTNode() {
    // Even though the destructor for the base ASTNode class is a pure virtual destructor, we have to define it as an empty function here to prevent a linker error.
}

void ASTRootNode::addStatement(ASTStatementNode *node) {
    children.push_back(node);
}

std::string ASTRootNode::generateGraphvizCode(std::string node_id, ASTNode *statement) {
    std::stringstream output;

    if (statement->getNodeType() == ROOT_NODE) {
        output << "digraph ast {" << std::endl;
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;
        for (int i = 0; i < children.size(); i++) {
            output << generateGraphvizCode(fmt::format("{}_{}", node_id, i), children[i]);
            output << fmt::format("    \"{}\" -> \"{}_{}\";", node_id, node_id, i) << std::endl;
        }
        output << "}" << std::endl;
    }
    else if (statement->getNodeType() == VARIABLE_DECLARATION_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;
    }
    else if (statement->getNodeType() == VARIABLE_ASSIGNMENT_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTVariableAssignmentNode *variable_assignment = (ASTVariableAssignmentNode *) statement;

        output << generateGraphvizCode(node_id + "_0", variable_assignment->getExpressionNode());
        output << fmt::format("    \"{}\" -> \"{}_0\";", node_id, node_id) << std::endl;
    }
    else if (statement->getNodeType() == EXPRESSION_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTExpressionNode *expression = (ASTExpressionNode *) statement;

        std::vector<ASTTermNode*> terms = expression->getTerms();
        for (int i = 0; i < terms.size(); i++) {
            output << generateGraphvizCode(fmt::format("{}_{}", node_id, i), terms[i]);
            output << fmt::format("    \"{}\" -> \"{}_{}\";", node_id, node_id, i) << std::endl;
        }
    }
    else if (statement->getNodeType() == TERM_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;
    }
    else if (statement->getNodeType() == CONDITIONAL_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTConditionalNode *conditional = (ASTConditionalNode *) statement;

        output << generateGraphvizCode(node_id + "_0", conditional->getCondition());
        output << fmt::format("    \"{}\" -> \"{}_0\";", node_id, node_id) << std::endl;
        output << generateGraphvizCode(node_id + "_1", conditional->getBeginEndBlock());
        output << fmt::format("    \"{}\" -> \"{}_1\";", node_id, node_id) << std::endl;
    }
    else if (statement->getNodeType() == CONDITION_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTConditionNode *condition = (ASTConditionNode *) statement;

        output << generateGraphvizCode(node_id + "_0", condition->getExpression1());
        output << fmt::format("    \"{}\" -> \"{}_0\";", node_id, node_id) << std::endl;
        output << generateGraphvizCode(node_id + "_1", condition->getExpression2());
        output << fmt::format("    \"{}\" -> \"{}_1\";", node_id, node_id) << std::endl;
    }
    else if (statement->getNodeType() == BEGIN_END_BLOCK_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTBeginEndBlockNode *begin_end_block = (ASTBeginEndBlockNode *) statement;
        std::vector<ASTStatementNode*> children = begin_end_block->getChildren();

        for (int i = 0; i < children.size(); i++) {
            output << generateGraphvizCode(fmt::format("{}_{}", node_id, i), children[i]);
            output << fmt::format("    \"{}\" -> \"{}_{}\";", node_id, node_id, i) << std::endl;
        }
    }
    else if (statement->getNodeType() == PROCEDURE_CALL_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;
    }
    else if (statement->getNodeType() == WHILE_LOOP_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTWhileLoopNode *while_loop = (ASTWhileLoopNode *) statement;

        output << generateGraphvizCode(node_id + "_0", while_loop->getCondition());
        output << fmt::format("    \"{}\" -> \"{}_0\";", node_id, node_id) << std::endl;
        output << generateGraphvizCode(node_id + "_1", while_loop->getBeginEndBlock());
        output << fmt::format("    \"{}\" -> \"{}_1\";", node_id, node_id) << std::endl;
    }
    else if (statement->getNodeType() == PROCEDURE_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTProcedureNode *procedure = (ASTProcedureNode *) statement;

        output << generateGraphvizCode(node_id + "_0", procedure->getBeginEndBlock());
        output << fmt::format("    \"{}\" -> \"{}_0\";", node_id, node_id) << std::endl;
    }

    return output.str();
}

ASTNodeType ASTRootNode::getNodeType() {
    return ROOT_NODE;
}

std::string ASTRootNode::getHumanReadable() {
    return "Root";
}

std::vector<ASTStatementNode*> ASTRootNode::getChildren() {
    return children;
}

void ASTRootNode::showGraph() {
    std::ofstream graphviz_file;
    graphviz_file.open("graph_temp.dot");
    graphviz_file << generateGraphvizCode("0", this);
    graphviz_file.close();
    std::system("dot -Tpdf graph_temp.dot -o graph_temp.pdf");
    std::system("xdg-open graph_temp.pdf");
}

ASTRootNode::~ASTRootNode() {
    for (auto statement_node : children) {
        delete statement_node;
    }
}

void ASTBeginEndBlockNode::addStatement(ASTStatementNode *statement) {
    children.push_back(statement);
}

ASTBeginEndBlockNode::~ASTBeginEndBlockNode() {
    for (auto statement_node : children) {
        delete statement_node;
    }
}

ASTNodeType ASTBeginEndBlockNode::getNodeType() {
    return BEGIN_END_BLOCK_NODE;
}

std::string ASTBeginEndBlockNode::getHumanReadable() {
    return "begin . . . end block";
}

std::vector<ASTStatementNode*> ASTBeginEndBlockNode::getChildren() {
    return children;
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

std::string ASTVariableDeclarationNode::getVariableName() {
    return variable_name;
}

OPERAND_C_TYPE ASTVariableDeclarationNode::getValue() {
    return value;
}

ASTConditionNode::ASTConditionNode(ConditionNodeComparison comparison, ASTExpressionNode *expression1, ASTExpressionNode *expression2) {
    this->comparison = comparison;
    this->expression1 = expression1;
    this->expression2 = expression2;
}

ASTNodeType ASTConditionNode::getNodeType() {
    return CONDITION_NODE;
}

std::string ASTConditionNode::getHumanReadable() {
    if (comparison == NOT_EQUALS) {
        return "Condition: #";
    }
    else if (comparison == EQUALS) {
        return "Condition: =";
    }
    else if (comparison == LESS_THAN) {
        return "Condition: <";
    }
    else if (comparison == LESS_THAN_OR_EQUAL_TO) {
        return "Condition: <=";
    }
    else if (comparison == GREATER_THAN) {
        return "Condition: >";
    }
    else if (comparison == GREATER_THAN_OR_EQUAL_TO) {
        return "Condition: >=";
    }
    return "Condition: unknown";
}

ConditionNodeComparison ASTConditionNode::getComparison() {
    return comparison;
}

ASTConditionNode::~ASTConditionNode() {
    delete expression1;
    delete expression2;
}

ASTExpressionNode *ASTConditionNode::getExpression1() {
    return expression1;
}

ASTExpressionNode *ASTConditionNode::getExpression2() {
    return expression2;
}

ASTConditionalNode::ASTConditionalNode(ASTConditionNode *condition, ASTBeginEndBlockNode *begin_end_block) {
    this->condition = condition;
    this->begin_end_block = begin_end_block;
}

ASTNodeType ASTConditionalNode::getNodeType() {
    return CONDITIONAL_NODE;
}

std::string ASTConditionalNode::getHumanReadable() {
    return "Conditional";
}

ASTConditionNode *ASTConditionalNode::getCondition() {
    return condition;
}

ASTConditionalNode::~ASTConditionalNode() {
    delete condition;
    delete begin_end_block;
}

ASTBeginEndBlockNode *ASTConditionalNode::getBeginEndBlock() {
    return begin_end_block;
}

ASTTermNode::ASTTermNode(TermNodeOperation operation, OPERAND_C_TYPE constant_value) {
    this->operation = operation;
    this->constant_value = constant_value;
    this->type = CONSTANT;
}

ASTTermNode::ASTTermNode(TermNodeOperation operation, std::string variable_name) {
    this->operation = operation;
    this->variable_name = variable_name;
    this->type = VARIABLE;
}

ASTNodeType ASTTermNode::getNodeType() {
    return TERM_NODE;
}

std::string ASTTermNode::getHumanReadable() {
    std::stringstream human_readable;
    if (operation == ADDITION) {
        human_readable << "+ ";
    }
    else if (operation == SUBTRACTION) {
        human_readable << "- ";
    }
    else if (operation == MULTIPLICATION) {
        human_readable << "* ";
    }
    else if (operation == DIVISION) {
        human_readable << "/ ";
    }
    else if (operation == MODULUS) {
        human_readable << "% ";
    }
    if (type == VARIABLE) {
        human_readable << variable_name;
    }
    else {
        human_readable << constant_value;
    }
    return human_readable.str();
}

TermNodeOperation ASTTermNode::getOperation() {
    return operation;
}

TermNodeType ASTTermNode::getType() {
    return type;
}

OPERAND_C_TYPE ASTTermNode::getConstantValue() {
    return constant_value;
}

std::string ASTTermNode::getVariableName() {
    return variable_name;
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

ASTExpressionNode::~ASTExpressionNode() {
    for (auto term : terms) {
        std::cout << "DELETING TERM" << std::endl;
        delete term;
    }
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

std::string ASTVariableAssignmentNode::getVariableName() {
    return variable_name;
}

ASTProcedureCallNode::ASTProcedureCallNode(std::string procedure_name) {
    this->procedure_name = procedure_name;
}

ASTNodeType ASTProcedureCallNode::getNodeType() {
    return PROCEDURE_CALL_NODE;
}

std::string ASTProcedureCallNode::getHumanReadable() {
    return fmt::format("Call procedure `{}`.", procedure_name);
}

std::string ASTProcedureCallNode::getProcedureName() {
    return procedure_name;
}

ASTWhileLoopNode::ASTWhileLoopNode(ASTConditionNode *condition, ASTBeginEndBlockNode *begin_end_block) {
    this->condition = condition;
    this->begin_end_block = begin_end_block;
}

ASTNodeType ASTWhileLoopNode::getNodeType() {
    return WHILE_LOOP_NODE;
}

std::string ASTWhileLoopNode::getHumanReadable() {
    return "While Loop";
}

ASTConditionNode *ASTWhileLoopNode::getCondition() {
    return condition;
}

ASTBeginEndBlockNode *ASTWhileLoopNode::getBeginEndBlock() {
    return begin_end_block;
}

ASTWhileLoopNode::~ASTWhileLoopNode() {
    delete condition;
    delete begin_end_block;
}

ASTProcedureNode::ASTProcedureNode(std::string procedure_name, ASTBeginEndBlockNode *begin_end_block) {
    this->procedure_name = procedure_name;
    this->begin_end_block = begin_end_block;
}

ASTNodeType ASTProcedureNode::getNodeType() {
    return PROCEDURE_NODE;
}

std::string ASTProcedureNode::getHumanReadable() {
    return fmt::format("Procedure `{}`.", procedure_name);
}

std::string ASTProcedureNode::getProcedureName() {
    return procedure_name;
}

ASTBeginEndBlockNode *ASTProcedureNode::getBeginEndBlock() {
    return begin_end_block;
}

ASTProcedureNode::~ASTProcedureNode() {
    delete begin_end_block;
}
