import std.stdio;
import std.getopt;

void main(string[] args) {
	// Open the input Lisp source.
	string input_filename = args[0];
	auto file = File(input_filename, "r");
	// Tokenize the source.
	// Recursively parse the S-expressions into an AST.
}
