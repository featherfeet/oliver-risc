# Documentation for the PL/0 Compiler for the ORISC System

A program is defined as a series of statements. Each statement must end in a semicolon.

Statements can be any of the following:
    - variable declarations
    - variable assignments
    - conditionals
    - procedures
    - procedure calls
    - while loops

Comments use the C style where single-line comments begin with `//` and multi-line comments are enclosed by `/*` and `*/`.

## Variable Declarations

A variable declaration creates a new variable in the current scope. They look like these:

```
VAR variable_name_1;
VAR variable_name_2 = 57;
```

Variables can be declared with no initializer (default to 0) or with an integer constant.

## Variable Assignments

A variable assignment sets the value of a variable. They look like this:

```
variable_name_1 := 5 + variable_name_2 / 32;
```

Note the use of the `:=` operator instead of the `=` operator. Variables can be assigned to _expressions_ (see below).

### Expressions

An expression is a series of terms (either integer constants or variable names) and operators (`+`, `-`, `*`, `/`, and `%`). No parentheses or order-of-operations are supported right now; operators are applied in simple left-to-right order.

## Conditionals

A conditional is a statement that uses a comparison between two expressions to decide whether to execute a block of code. They look like this:

```
IF variable_name_1 + 17 = variable_name_2 THEN
BEGIN
    // Code to conditionally execute goes here.
END;
```

The comparison between the two expressions may use any of the following operators: `>`, `<`, `>=`, `<=`, `=`, `#`.

`#` means "not equal to." Note that the comparison operator for equality is `=`, not `==`.

## Procedures

A procedure is a series of statements that can be called from elsewhere in the program (with its own variable scope). They look like this:

```
PROCEDURE do_something;
BEGIN
    // Code to execute in the procedure.
END;
```

Arguments and return values are not yet supported. All variables are stored on the stack.

## Procedure Calls

Procedure calls are statements that execute a procedure. They look like this:

```
CALL do_something;
```

Arguments and return values are not yet supported.

## While Loops

While loops are statements that execute repeatedly until a condition becomes false. The condition is checked at the 'top' of the loop. They look like this:

```
WHILE variable_1 <= 5 DO
BEGIN
    // Code to repeatedly execute goes here.
END
```
