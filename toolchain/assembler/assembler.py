#!/usr/bin/env python3

import sys
from variable import Variable
from label import Label
from instruction import Instruction
import assemblyparser
from collections import OrderedDict
from assembler_parameters import *

source_file = open(sys.argv[1])
source_code = source_file.read()
source_file.close()

commands = assemblyparser.parse(source_code)

variable_table = OrderedDict()
instruction_table = []
label_table = []

instruction_index = 0

for command in commands:
    if isinstance(command, Variable):
        variable_table[command.name] = int(command.value)
    elif isinstance(command, Instruction):
        instruction = []
