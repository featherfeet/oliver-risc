class SExpression:
	"""Represent a Lisp S-expression that can be arbitrarily nested. Children can be a combination of Atoms and SExpressions. returns_into is the name of the variable (memory address) that the s-expression's return value gets stored in."""
	def __init__(self, returns_into, children):
		self.returns_into = returns_into
		self.children = children
	def addChild(self, child):
		self.children.append(child)

class Symbol:
	"""Represents a function/variable/macro name in Lisp code. name is the name of the symbol."""
	def __init__(self, name):
		self.name = name

class Constant:
	"""Represents an atom like 'a' or 5. Value is the atom's value (a or 5), and location is the name of the variable (memory address) that will hold the atom."""
	def __init__(self, value, location):
		self.value = value
		self.location = location

def getTopLevelChildren(tokens):
	"""Get all direct children of the s-expression represented in a list of tokens."""
	tokens.pop(0)
	tokens.pop()
	ret = []
	paren_counter = 0
	for token in tokens:
		if paren_counter == 0:
			ret.append([])
		if token == '(':
			ret[-1].append(token)
			paren_counter += 1
		elif token == ')':
			paren_counter -= 1
			ret[-1].append(token)
		else:
			ret[-1].append(token)
	return ret

def makeAST(tokens):
	"""Recursively parse a list of tokens into an AST consisting of s-expressions, symbols, and constants."""
	if len(tokens) == 1:
		if tokens[0].isdigit():
			return Constant(int(tokens[0]), "")
		else:
			return Symbol(tokens[0])
	else:
		s_expressions = getTopLevelChildren(tokens)
		ret = SExpression("", [])
		for s_expression in s_expressions:
			ret.addChild(makeAST(s_expression))
		return ret

def printAST(ast, recursion_level):
	if ast.__class__.__name__ == "SExpression":
		print("\t" * recursion_level + "s {")
		for child in ast.children:
			printAST(child, recursion_level + 1)
		print("\t" * recursion_level + "}")
	else:
		print("\t" * recursion_level, end = '')
		if ast.__class__.__name__ == "Symbol":
			print(ast.name)
		else:
			print(ast.value)
