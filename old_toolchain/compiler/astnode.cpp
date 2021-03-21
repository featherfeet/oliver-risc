#include "astnode.h"

ASTNode::~ASTNode() {
    // Even though the destructor for the base ASTNode class is a pure virtual destructor, we have to define it as an empty function here to prevent a linker error.
}
