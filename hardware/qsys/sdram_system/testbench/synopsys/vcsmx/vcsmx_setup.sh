
# (C) 2001-2019 Altera Corporation. All rights reserved.
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

# ACDS 13.0sp1 232 linux 2019.04.04.00:59:09

# ----------------------------------------
# vcsmx - auto-generated simulation script

# ----------------------------------------
# initialize variables
TOP_LEVEL_NAME="sdram_system_tb"
QSYS_SIMDIR="./../../"
QUARTUS_INSTALL_DIR="/home/oliver/altera/13.0sp1/quartus/"
SKIP_FILE_COPY=0
SKIP_DEV_COM=0
SKIP_COM=0
SKIP_ELAB=0
SKIP_SIM=0
USER_DEFINED_ELAB_OPTIONS=""
USER_DEFINED_SIM_OPTIONS="+vcs+finish+100"

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
mkdir -p ./libraries/crosser/
mkdir -p ./libraries/cmd_xbar_demux/
mkdir -p ./libraries/rst_controller/
mkdir -p ./libraries/id_router/
mkdir -p ./libraries/addr_router/
mkdir -p ./libraries/new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo/
mkdir -p ./libraries/new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent/
mkdir -p ./libraries/bridge_0_avalon_master_translator_avalon_universal_master_0_agent/
mkdir -p ./libraries/new_sdram_controller_0_s1_translator/
mkdir -p ./libraries/bridge_0_avalon_master_translator/
mkdir -p ./libraries/bridge_0/
mkdir -p ./libraries/new_sdram_controller_0/
mkdir -p ./libraries/up_clocks_0/
mkdir -p ./libraries/new_sdram_controller_0_my_partner/
mkdir -p ./libraries/sdram_system_inst_avalon_bridge_bfm/
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
  vlogan +v2k           "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_primitives.v" -work altera_ver      
  vlogan +v2k           "$QUARTUS_INSTALL_DIR/eda/sim_lib/220model.v"          -work lpm_ver         
  vlogan +v2k           "$QUARTUS_INSTALL_DIR/eda/sim_lib/sgate.v"             -work sgate_ver       
  vlogan +v2k           "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_mf.v"         -work altera_mf_ver   
  vlogan +v2k -sverilog "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_lnsim.sv"     -work altera_lnsim_ver
  vlogan +v2k           "$QUARTUS_INSTALL_DIR/eda/sim_lib/cycloneii_atoms.v"   -work cycloneii_ver   
fi

# ----------------------------------------
# compile design files in correct order
if [ $SKIP_COM -eq 0 ]; then
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_st_handshake_clock_crosser.v"           -work crosser                                                                     
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_st_clock_crosser.v"                     -work crosser                                                                     
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_st_pipeline_base.v"                     -work crosser                                                                     
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_cmd_xbar_demux.sv"                       -work cmd_xbar_demux                                                              
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_reset_controller.v"                            -work rst_controller                                                              
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_reset_synchronizer.v"                          -work rst_controller                                                              
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_id_router.sv"                            -work id_router                                                                   
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_addr_router.sv"                          -work addr_router                                                                 
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_sc_fifo.v"                              -work new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_slave_agent.sv"                         -work new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent         
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_burst_uncompressor.sv"                  -work new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent         
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_master_agent.sv"                        -work bridge_0_avalon_master_translator_avalon_universal_master_0_agent           
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_slave_translator.sv"                    -work new_sdram_controller_0_s1_translator                                        
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_master_translator.sv"                   -work bridge_0_avalon_master_translator                                           
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_bridge_0.v"                              -work bridge_0                                                                    
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_new_sdram_controller_0.v"                -work new_sdram_controller_0                                                      
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_new_sdram_controller_0_test_component.v" -work new_sdram_controller_0                                                      
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_up_clocks_0.v"                           -work up_clocks_0                                                                 
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_sdram_partner_module.v"                        -work new_sdram_controller_0_my_partner                                           
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/verbosity_pkg.sv"                                     -work sdram_system_inst_avalon_bridge_bfm                                         
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_conduit_bfm.sv"                                -work sdram_system_inst_avalon_bridge_bfm                                         
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/verbosity_pkg.sv"                                     -work sdram_system_inst_reset_bfm                                                 
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_reset_source.sv"                        -work sdram_system_inst_reset_bfm                                                 
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/verbosity_pkg.sv"                                     -work sdram_system_inst_clk_bfm                                                   
  vlogan +v2k -sverilog "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_clock_source.sv"                        -work sdram_system_inst_clk_bfm                                                   
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system.v"                                       -work sdram_system_inst                                                           
  vlogan +v2k           "$QSYS_SIMDIR/sdram_system_tb/simulation/sdram_system_tb.v"                                                                                                                                 
fi

# ----------------------------------------
# elaborate top level design
if [ $SKIP_ELAB -eq 0 ]; then
  vcs -lca -t ps $USER_DEFINED_ELAB_OPTIONS $TOP_LEVEL_NAME
fi

# ----------------------------------------
# simulate
if [ $SKIP_SIM -eq 0 ]; then
  ./simv $USER_DEFINED_SIM_OPTIONS
fi
