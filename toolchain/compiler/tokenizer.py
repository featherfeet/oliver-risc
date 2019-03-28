def tokenize(source):
	tokens = []
	for ch in source:
		if ch == "(" or ch == ")":
			tokens.append("")
			tokens[-1] += ch
			tokens.append("")
		elif ch.isspace():
			tokens.append("")
		else:
			tokens[-1] += ch
	while "" in tokens:
		tokens.remove("")
	return tokens
