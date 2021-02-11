# Documentation for the PL/0 Compiler for the ORISC System

A program is defined as a series of statements. Each statement must end in a semicolon.

Statements can be any of the following:

    - variable declarations
    - variable assignments
    - buffer writes
    - conditionals
    - procedures
    - procedure calls
    - while loops
    - inline assembly
    - returns

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

An expression is a series of terms (integer constants, variable names, or buffer reads) and operators (`+`, `-`, `*`, `/`, and `%`). No parentheses or order-of-operations are supported right now; operators are applied in simple left-to-right order.

Expressions can contain buffer reads, which read a single byte from a buffer, often a string. For example:

```
my_variable := 49 + buffer[i];
```

Note that the _index_ of a buffer read (the token between the square brackets that sets the offset of the byte to be read) cannot be expressions; they must be either constants or variables.

## Buffer Writes

A buffer write is a special kind of variable assignment used to change a single byte of a buffer (often a string). They look like this:

```
my_string[0] := 7 + variable_name_2;
```

Or this:

```
my_string[index] := 29 % variable_name_2;
```

Note that the _index_ (the number between the square brackets that sets the offset in the buffer to be written) cannot be an expression. It must be either a constant or a variable.

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

If a procedure is intended to be used as an ISR (Interrupt Service Routine), then you must mark it as an ISR like so:

```
PROCEDURE ISR key_pressed;
BEGIN
    // Code to execute in the procedure.
END;
```

The compiler will mark the start of a procedure with the label `start_procedure_{}` where `{}` should be replaced with the name of the procedure. For example, a procedure called `hello_world` would be given the label `start_procedure_hello_world`. This means that the following code could be used to set up an ISR with that procedure (assuming that the procedure was marked as an ISR):

```
__ASM__("CLOAD 0,A");
__ASM__("CLOAD start_procedure_hello_world,B");
__ASM__("ISR A,B");
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

## Inline Assembly

Inline assembly statements allow directly inserting assembly into the final output of the compiler. They look like this:

```
__ASM__("CLOAD 0,A");
```

Be careful not to corrupt the G and F registers, as these are used for stack pointers. Manipulating the IP register can also be dangerous, as it will change the expected flow of the program.

## Returns

A RETURN statement causes the current procedure to immediately exit and return to the calling stack. If the current procedure was marked as an `ISR`, then this will call the `ENDINT` instruction. Otherwise, it simply deallocates the local stack variables and jumps back to where the procedure was called from. Return values are not yet supported.
