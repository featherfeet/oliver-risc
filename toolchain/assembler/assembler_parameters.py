"""
Assembly code format (curly braces are replacements) (each line in the .code section is an instruction):
.data:
	{variable1 name} = {variable1 value}
	{variable2 name} = {variable2 value}
	{variable3 name} = {variable3 value}
.code:
	{label1 name}:
			{Operation} {Operand1},{Operand2}
	{label2 name}:
			{Operation} {Operand1},{Operand2}
			{Operation} {Operand1},{Operand2}
"""

OPERATION_SIZE = 1
OPERAND_SIZE = 4
INSTRUCTION_SIZE = OPERATION_SIZE + OPERAND_SIZE + OPERAND_SIZE

operations = {
    "NOP": 0,
    "LOAD": 1,
    "STORE": 2,
    "ADD": 3,
    "SUB": 4,
    "OUT": 5,
    "IN": 6,
    "MOV": 7,
    "CMP": 8,
    "JMPL": 9,
    "JMPE": 10,
    "JMPG": 11,
    "RST": 12,
    "HALT": 13,
    "CODE": 14,
}

registers = {
    "IP": 0,
    "A": 1,
    "B": 2,
    "C": 3,
    "D": 4,
    "E": 5,
    "F": 6,
    "G": 7,
    "IE": 8,
}
