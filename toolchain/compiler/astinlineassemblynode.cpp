#include "astinlineassemblynode.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

ASTInlineAssemblyNode::ASTInlineAssemblyNode(std::string inline_assembly) {
    this->inline_assembly = inline_assembly;
}

ASTNodeType ASTInlineAssemblyNode::getNodeType() {
    return INLINE_ASSEMBLY_NODE;
}

std::string ASTInlineAssemblyNode::getHumanReadable() {
    return fmt::format("Inline assembly: `{}`", inline_assembly);
}

std::string ASTInlineAssemblyNode::getInlineAssembly() {
    return inline_assembly;
}
