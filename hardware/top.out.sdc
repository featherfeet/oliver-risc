## Generated SDC file "top.out.sdc"

## Copyright (C) 1991-2013 Altera Corporation
## Your use of Altera Corporation's design tools, logic functions 
## and other software and tools, and its AMPP partner logic 
## functions, and any output files from any of the foregoing 
## (including device programming or simulation files), and any 
## associated documentation or information are expressly subject 
## to the terms and conditions of the Altera Program License 
## Subscription Agreement, Altera MegaCore Function License 
## Agreement, or other applicable license agreement, including, 
## without limitation, that your use is for the sole purpose of 
## programming logic devices manufactured by Altera and sold by 
## Altera or its authorized distributors.  Please refer to the 
## applicable agreement for further details.


## VENDOR  "Altera"
## PROGRAM "Quartus II"
## VERSION "Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"

## DATE    "Tue Jul 28 16:53:40 2020"

##
## DEVICE  "EP2C20F484C7"
##


#**************************************************************
# Time Information
#**************************************************************

set_time_format -unit ns -decimal_places 3



#**************************************************************
# Create Clock
#**************************************************************

create_clock -name {CLOCK_50} -period 20.000 -waveform { 0.000 10.000 } [get_ports {CLOCK_50}]


#**************************************************************
# Create Generated Clock
#**************************************************************

create_generated_clock -name {up_clocks_0|DE_Clock_Generator_System|pll|clk[1]} -source [get_pins {up_clocks_0|DE_Clock_Generator_System|pll|inclk[0]}] -duty_cycle 50.000 -multiply_by 1 -phase -54.000 -master_clock {CLOCK_50} [get_pins {up_clocks_0|DE_Clock_Generator_System|pll|clk[1]}] 
create_generated_clock -name {up_clocks_0|DE_Clock_Generator_System|pll|clk[2]} -source [get_pins {up_clocks_0|DE_Clock_Generator_System|pll|inclk[0]}] -duty_cycle 50.000 -multiply_by 1 -divide_by 2 -phase 180.000 -master_clock {CLOCK_50} [get_pins {up_clocks_0|DE_Clock_Generator_System|pll|clk[2]}] 


#**************************************************************
# Set Clock Latency
#**************************************************************



#**************************************************************
# Set Clock Uncertainty
#**************************************************************



#**************************************************************
# Set Input Delay
#**************************************************************



#**************************************************************
# Set Output Delay
#**************************************************************



#**************************************************************
# Set Clock Groups
#**************************************************************



#**************************************************************
# Set False Path
#**************************************************************



#**************************************************************
# Set Multicycle Path
#**************************************************************



#**************************************************************
# Set Maximum Delay
#**************************************************************



#**************************************************************
# Set Minimum Delay
#**************************************************************



#**************************************************************
# Set Input Transition
#**************************************************************

