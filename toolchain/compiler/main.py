#!/usr/bin/env python3

import sys
import tokenizer
import syntaxparser
import compiler

# Read in source file.
source = open(sys.argv[1]).read()

# Tokenize source.
tokens = tokenizer.tokenize(source)

# Parse AST.
ast = syntaxparser.makeAST(tokens)

# Display AST.
syntaxparser.printAST(ast, 0)
