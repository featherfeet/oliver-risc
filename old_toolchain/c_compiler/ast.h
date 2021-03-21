#ifndef AST_H
#define AST_H

#include <stdbool.h>
#include <glib.h>

enum ASTNodeType {
    Root,
    VariableDeclaration,
    TypeSpecifier,
    Expression,
    Term
};

struct ASTNode {
    ASTNodeType node_type;
    union {
        struct ASTRoot root;
        struct ASTVariableDeclaration variable_declaration;
        struct ASTTypeSpecificer type_specifier;
        struct ASTExpression expression;
        struct ASTTerm term;
    }
};

struct ASTRoot {

};

#endif // AST_H
