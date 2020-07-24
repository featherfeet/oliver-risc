#!/bin/bash

quartus_map top --64bit --parallel=12
quartus_fit top --64bit --parallel=12
quartus_asm top --64bit
