import re
from variable import Variable
from label import Label
from instruction import Instruction

variable_regex = re.compile("\s*(\w+)\s+=\s+(\d+)")
instruction_regex = re.compile("\s*([A-Z]+)\s*(\w*),*(\w*)")
empty_line = re.compile("\s*")

def parse(source_code):
    # All variable declarations, labels, and instructions go into this.
    commands = []

    # Sets which section of the program (.data or .code) the parser is in.
    current_section = "data"

    # For each line of the program...
    for line in source_code.split('\n'):
        # Ignore whitespace/empty lines.
        if empty_line.fullmatch(line) != None:
            continue
        # Detect when the code changes to a new section.
        if ".data" in line:
            current_section = "data"
            continue
        elif ".code" in line:
            current_section = "code"
            continue
        # If we're in the data section, then parse variable declarations such as "varname = 21".
        if current_section == "data":
            match = variable_regex.match(line)
            variable_name = match.group(1)
            variable_value = match.group(2)
            variable = Variable(variable_name, variable_value)
            commands.append(variable)
        # If we're in the code section, parse for either instructions or jump labels.
        elif current_section == "code":
            # If there's a colon in the line, it's a jump label.
            if ':' in line:
                line = line.strip()
                label_name = line.replace(':', '')
                label = Label(label_name)
                commands.append(label)
            # Otherwise, it's an instruction.
            else:
                match = instruction_regex.match(line)
                operation = match.group(1)
                operand1 = match.group(2)
                operand2 = match.group(3)
                instruction = Instruction(operation, operand1, operand2)
                commands.append(instruction)
    return commands
