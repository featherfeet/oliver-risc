
# (C) 2001-2020 Altera Corporation. All rights reserved.
# Your use of Altera Corporation's design tools, logic functions and 
# other software and tools, and its AMPP partner logic functions, and 
# any output files any of the foregoing (including device programming 
# or simulation files), and any associated documentation or information 
# are expressly subject to the terms and conditions of the Altera 
# Program License Subscription Agreement, Altera MegaCore Function 
# License Agreement, or other applicable license agreement, including, 
# without limitation, that your use is for the sole purpose of 
# programming logic devices manufactured by Altera and sold by Altera 
# or its authorized distributors. Please refer to the applicable 
# agreement for further details.

# ACDS 13.0sp1 232 linux 2020.11.22.00:37:52

# ----------------------------------------
# ncsim - auto-generated simulation script

# ----------------------------------------
# initialize variables
TOP_LEVEL_NAME="sdram_system_tb"
QSYS_SIMDIR="./../"
QUARTUS_INSTALL_DIR="/home/oliver/altera/13.0sp1/quartus/"
SKIP_FILE_COPY=0
SKIP_DEV_COM=0
SKIP_COM=0
SKIP_ELAB=0
SKIP_SIM=0
USER_DEFINED_ELAB_OPTIONS=""
USER_DEFINED_SIM_OPTIONS="-input \"@run 100; exit\""

# ----------------------------------------
# overwrite variables - DO NOT MODIFY!
# This block evaluates each command line argument, typically used for 
# overwriting variables. An example usage:
#   sh <simulator>_setup.sh SKIP_ELAB=1 SKIP_SIM=1
for expression in "$@"; do
  eval $expression
  if [ $? -ne 0 ]; then
    echo "Error: This command line argument, \"$expression\", is/has an invalid expression." >&2
    exit $?
  fi
done

# ----------------------------------------
# create compilation libraries
mkdir -p ./libraries/work/
mkdir -p ./libraries/rst_controller/
mkdir -p ./libraries/new_sdram_controller_0/
mkdir -p ./libraries/new_sdram_controller_0_my_partner/
mkdir -p ./libraries/sdram_system_inst_reset_bfm/
mkdir -p ./libraries/sdram_system_inst_clk_bfm/
mkdir -p ./libraries/sdram_system_inst/
mkdir -p ./libraries/altera_ver/
mkdir -p ./libraries/lpm_ver/
mkdir -p ./libraries/sgate_ver/
mkdir -p ./libraries/altera_mf_ver/
mkdir -p ./libraries/altera_lnsim_ver/
mkdir -p ./libraries/cycloneii_ver/

# ----------------------------------------
# copy RAM/ROM files to simulation directory

# ----------------------------------------
# compile device library files
if [ $SKIP_DEV_COM -eq 0 ]; then
  ncvlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_primitives.v" -work altera_ver      
  ncvlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/220model.v"          -work lpm_ver         
  ncvlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/sgate.v"             -work sgate_ver       
  ncvlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_mf.v"         -work altera_mf_ver   
  ncvlog -sv "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_lnsim.sv"     -work altera_lnsim_ver
  ncvlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/cycloneii_atoms.v"   -work cycloneii_ver   
fi

# ----------------------------------------
# compile design files in correct order
if [ $SKIP_COM -eq 0 ]; then
  ncvlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_reset_controller.v"                            -work rst_controller                    -cdslib ./cds_libs/rst_controller.cds.lib                   
  ncvlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_reset_synchronizer.v"                          -work rst_controller                    -cdslib ./cds_libs/rst_controller.cds.lib                   
  ncvlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_new_sdram_controller_0_test_component.v" -work new_sdram_controller_0            -cdslib ./cds_libs/new_sdram_controller_0.cds.lib           
  ncvlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_new_sdram_controller_0.v"                -work new_sdram_controller_0            -cdslib ./cds_libs/new_sdram_controller_0.cds.lib           
  ncvlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_sdram_partner_module.v"                        -work new_sdram_controller_0_my_partner -cdslib ./cds_libs/new_sdram_controller_0_my_partner.cds.lib
  ncvlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/verbosity_pkg.sv"                                     -work sdram_system_inst_reset_bfm       -cdslib ./cds_libs/sdram_system_inst_reset_bfm.cds.lib      
  ncvlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_reset_source.sv"                        -work sdram_system_inst_reset_bfm       -cdslib ./cds_libs/sdram_system_inst_reset_bfm.cds.lib      
  ncvlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/verbosity_pkg.sv"                                     -work sdram_system_inst_clk_bfm         -cdslib ./cds_libs/sdram_system_inst_clk_bfm.cds.lib        
  ncvlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_clock_source.sv"                        -work sdram_system_inst_clk_bfm         -cdslib ./cds_libs/sdram_system_inst_clk_bfm.cds.lib        
  ncvlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system.v"                                       -work sdram_system_inst                 -cdslib ./cds_libs/sdram_system_inst.cds.lib                
  ncvlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/sdram_system_tb.v"                                                                                                                                                   
fi

# ----------------------------------------
# elaborate top level design
if [ $SKIP_ELAB -eq 0 ]; then
  ncelab -access +w+r+c -namemap_mixgen $USER_DEFINED_ELAB_OPTIONS $TOP_LEVEL_NAME
fi

# ----------------------------------------
# simulate
if [ $SKIP_SIM -eq 0 ]; then
  eval ncsim -licqueue $USER_DEFINED_SIM_OPTIONS $TOP_LEVEL_NAME
fi
