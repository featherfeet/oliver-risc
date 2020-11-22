#include "astnode.h"
#include "aststatementnode.h"
#include "astrootnode.h"
#include "astvariabledeclarationnode.h"
#include "astexpressionnode.h"
#include "astvariableassignmentnode.h"
#include "astbufferwritenode.h"
#include "asttermnode.h"
#include "astbeginendblocknode.h"
#include "astconditionnode.h"
#include "astconditionalnode.h"
#include "astprocedurecallnode.h"
#include "astwhileloopnode.h"
#include "astprocedurenode.h"
#include "astbufferreadnode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include <fstream>
#include <sstream>

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
    else if (statement->getNodeType() == BUFFER_WRITE_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTBufferWriteNode *buffer_write = (ASTBufferWriteNode *) statement;

        output << generateGraphvizCode(node_id + "_0", buffer_write->getOffsetExpression());
        output << fmt::format("    \"{}\" -> \"{}_0\";", node_id, node_id) << std::endl;

        output << generateGraphvizCode(node_id + "_1", buffer_write->getValueExpression());
        output << fmt::format("    \"{}\" -> \"{}_1\";", node_id, node_id) << std::endl;
    }
    else if (statement->getNodeType() == EXPRESSION_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;

        ASTExpressionNode *expression = (ASTExpressionNode *) statement;

        std::vector<ASTNode*> terms = expression->getTerms();
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
    else if (statement->getNodeType() == BUFFER_READ_NODE) {
        output << fmt::format("    \"{}\" [label=\"{}\", shape=box];", node_id, statement->getHumanReadable()) << std::endl;
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
