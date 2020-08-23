#include "ast.h"
#include <string>
#include <sstream>

class AssemblyGenerator {
    std::stringstream data_section;
    std::stringstream code_section;

    public:
        AssemblyGenerator();
        void generateAsm(ASTNode *node);
        std::string getGeneratedAssembly();
};
