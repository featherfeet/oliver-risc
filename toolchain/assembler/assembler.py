#!/usr/bin/env python3

import sys
import assemblyparser

source_file = open(sys.argv[1])
source_code = source_file.read()
source_file.close()

commands = assemblyparser.parse(source_code)
