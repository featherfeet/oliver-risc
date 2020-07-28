
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

# ACDS 13.0sp1 232 linux 2020.07.27.22:31:21

# ----------------------------------------
# Auto-generated simulation script

# ----------------------------------------
# Initialize the variable
if ![info exists SYSTEM_INSTANCE_NAME] { 
  set SYSTEM_INSTANCE_NAME ""
} elseif { ![ string match "" $SYSTEM_INSTANCE_NAME ] } { 
  set SYSTEM_INSTANCE_NAME "/$SYSTEM_INSTANCE_NAME"
} 

if ![info exists TOP_LEVEL_NAME] { 
  set TOP_LEVEL_NAME "sdram_system_tb"
} 

if ![info exists QSYS_SIMDIR] { 
  set QSYS_SIMDIR "./../"
} 

if ![info exists QUARTUS_INSTALL_DIR] { 
  set QUARTUS_INSTALL_DIR "/home/oliver/altera/13.0sp1/quartus/"
} 


# ----------------------------------------
# Copy ROM/RAM files to simulation directory
alias file_copy {
  echo "\[exec\] file_copy"
}

# ----------------------------------------
# Create compilation libraries
proc ensure_lib { lib } { if ![file isdirectory $lib] { vlib $lib } }
ensure_lib          ./libraries/     
ensure_lib          ./libraries/work/
vmap       work     ./libraries/work/
vmap       work_lib ./libraries/work/
if { ![ string match "*ModelSim ALTERA*" [ vsim -version ] ] } {
  ensure_lib                  ./libraries/altera_ver/      
  vmap       altera_ver       ./libraries/altera_ver/      
  ensure_lib                  ./libraries/lpm_ver/         
  vmap       lpm_ver          ./libraries/lpm_ver/         
  ensure_lib                  ./libraries/sgate_ver/       
  vmap       sgate_ver        ./libraries/sgate_ver/       
  ensure_lib                  ./libraries/altera_mf_ver/   
  vmap       altera_mf_ver    ./libraries/altera_mf_ver/   
  ensure_lib                  ./libraries/altera_lnsim_ver/
  vmap       altera_lnsim_ver ./libraries/altera_lnsim_ver/
  ensure_lib                  ./libraries/cycloneii_ver/   
  vmap       cycloneii_ver    ./libraries/cycloneii_ver/   
}
ensure_lib                                                                              ./libraries/altera_avalon_vip_pkgs_lib/                                                  
vmap       altera_avalon_vip_pkgs_lib                                                   ./libraries/altera_avalon_vip_pkgs_lib/                                                  
ensure_lib                                                                              ./libraries/crosser/                                                                     
vmap       crosser                                                                      ./libraries/crosser/                                                                     
ensure_lib                                                                              ./libraries/cmd_xbar_demux/                                                              
vmap       cmd_xbar_demux                                                               ./libraries/cmd_xbar_demux/                                                              
ensure_lib                                                                              ./libraries/rst_controller/                                                              
vmap       rst_controller                                                               ./libraries/rst_controller/                                                              
ensure_lib                                                                              ./libraries/id_router/                                                                   
vmap       id_router                                                                    ./libraries/id_router/                                                                   
ensure_lib                                                                              ./libraries/addr_router/                                                                 
vmap       addr_router                                                                  ./libraries/addr_router/                                                                 
ensure_lib                                                                              ./libraries/new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo/
vmap       new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo ./libraries/new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo/
ensure_lib                                                                              ./libraries/new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent/         
vmap       new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent          ./libraries/new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent/         
ensure_lib                                                                              ./libraries/bridge_0_avalon_master_translator_avalon_universal_master_0_agent/           
vmap       bridge_0_avalon_master_translator_avalon_universal_master_0_agent            ./libraries/bridge_0_avalon_master_translator_avalon_universal_master_0_agent/           
ensure_lib                                                                              ./libraries/new_sdram_controller_0_s1_translator/                                        
vmap       new_sdram_controller_0_s1_translator                                         ./libraries/new_sdram_controller_0_s1_translator/                                        
ensure_lib                                                                              ./libraries/bridge_0_avalon_master_translator/                                           
vmap       bridge_0_avalon_master_translator                                            ./libraries/bridge_0_avalon_master_translator/                                           
ensure_lib                                                                              ./libraries/bridge_0/                                                                    
vmap       bridge_0                                                                     ./libraries/bridge_0/                                                                    
ensure_lib                                                                              ./libraries/new_sdram_controller_0/                                                      
vmap       new_sdram_controller_0                                                       ./libraries/new_sdram_controller_0/                                                      
ensure_lib                                                                              ./libraries/up_clocks_0/                                                                 
vmap       up_clocks_0                                                                  ./libraries/up_clocks_0/                                                                 
ensure_lib                                                                              ./libraries/new_sdram_controller_0_my_partner/                                           
vmap       new_sdram_controller_0_my_partner                                            ./libraries/new_sdram_controller_0_my_partner/                                           
ensure_lib                                                                              ./libraries/sdram_system_inst_avalon_bridge_bfm/                                         
vmap       sdram_system_inst_avalon_bridge_bfm                                          ./libraries/sdram_system_inst_avalon_bridge_bfm/                                         
ensure_lib                                                                              ./libraries/sdram_system_inst_reset_bfm/                                                 
vmap       sdram_system_inst_reset_bfm                                                  ./libraries/sdram_system_inst_reset_bfm/                                                 
ensure_lib                                                                              ./libraries/sdram_system_inst_clk_bfm/                                                   
vmap       sdram_system_inst_clk_bfm                                                    ./libraries/sdram_system_inst_clk_bfm/                                                   
ensure_lib                                                                              ./libraries/sdram_system_inst/                                                           
vmap       sdram_system_inst                                                            ./libraries/sdram_system_inst/                                                           

# ----------------------------------------
# Compile device library files
alias dev_com {
  echo "\[exec\] dev_com"
  if { ![ string match "*ModelSim ALTERA*" [ vsim -version ] ] } {
    vlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_primitives.v" -work altera_ver      
    vlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/220model.v"          -work lpm_ver         
    vlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/sgate.v"             -work sgate_ver       
    vlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_mf.v"         -work altera_mf_ver   
    vlog -sv "$QUARTUS_INSTALL_DIR/eda/sim_lib/altera_lnsim.sv"     -work altera_lnsim_ver
    vlog     "$QUARTUS_INSTALL_DIR/eda/sim_lib/cycloneii_atoms.v"   -work cycloneii_ver   
  }
}

# ----------------------------------------
# Compile the design files in correct order
alias com {
  echo "\[exec\] com"
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/verbosity_pkg.sv"                                                                   -work altera_avalon_vip_pkgs_lib                                                  
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_st_handshake_clock_crosser.v"                                         -work crosser                                                                     
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_st_clock_crosser.v"                                                   -work crosser                                                                     
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_st_pipeline_base.v"                                                   -work crosser                                                                     
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_cmd_xbar_demux.sv"                                                     -work cmd_xbar_demux                                                              
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_reset_controller.v"                                                          -work rst_controller                                                              
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_reset_synchronizer.v"                                                        -work rst_controller                                                              
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_id_router.sv"                                                          -work id_router                                                                   
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_addr_router.sv"                                                        -work addr_router                                                                 
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_sc_fifo.v"                                                            -work new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_slave_agent.sv"                                                       -work new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent         
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_burst_uncompressor.sv"                                                -work new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent         
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_master_agent.sv"                                                      -work bridge_0_avalon_master_translator_avalon_universal_master_0_agent           
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_slave_translator.sv"                                                  -work new_sdram_controller_0_s1_translator                                        
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_merlin_master_translator.sv"                                                 -work bridge_0_avalon_master_translator                                           
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_bridge_0.v"                                                            -work bridge_0                                                                    
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_new_sdram_controller_0_test_component.v"                               -work new_sdram_controller_0                                                      
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_new_sdram_controller_0.v"                                              -work new_sdram_controller_0                                                      
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system_up_clocks_0.v"                                                         -work up_clocks_0                                                                 
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_sdram_partner_module.v"                                                      -work new_sdram_controller_0_my_partner                                           
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_conduit_bfm.sv"                                -L altera_avalon_vip_pkgs_lib -work sdram_system_inst_avalon_bridge_bfm                                         
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_reset_source.sv"                        -L altera_avalon_vip_pkgs_lib -work sdram_system_inst_reset_bfm                                                 
  vlog -sv "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/altera_avalon_clock_source.sv"                        -L altera_avalon_vip_pkgs_lib -work sdram_system_inst_clk_bfm                                                   
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/submodules/sdram_system.v"                                                                     -work sdram_system_inst                                                           
  vlog     "$QSYS_SIMDIR/sdram_system_tb/simulation/sdram_system_tb.v"                                                                                                                                                               
}

# ----------------------------------------
# Elaborate top level design
alias elab {
  echo "\[exec\] elab"
  vsim -t ps -L work -L work_lib -L altera_avalon_vip_pkgs_lib -L crosser -L cmd_xbar_demux -L rst_controller -L id_router -L addr_router -L new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo -L new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent -L bridge_0_avalon_master_translator_avalon_universal_master_0_agent -L new_sdram_controller_0_s1_translator -L bridge_0_avalon_master_translator -L bridge_0 -L new_sdram_controller_0 -L up_clocks_0 -L new_sdram_controller_0_my_partner -L sdram_system_inst_avalon_bridge_bfm -L sdram_system_inst_reset_bfm -L sdram_system_inst_clk_bfm -L sdram_system_inst -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneii_ver $TOP_LEVEL_NAME
}

# ----------------------------------------
# Elaborate the top level design with novopt option
alias elab_debug {
  echo "\[exec\] elab_debug"
  vsim -novopt -t ps -L work -L work_lib -L altera_avalon_vip_pkgs_lib -L crosser -L cmd_xbar_demux -L rst_controller -L id_router -L addr_router -L new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent_rsp_fifo -L new_sdram_controller_0_s1_translator_avalon_universal_slave_0_agent -L bridge_0_avalon_master_translator_avalon_universal_master_0_agent -L new_sdram_controller_0_s1_translator -L bridge_0_avalon_master_translator -L bridge_0 -L new_sdram_controller_0 -L up_clocks_0 -L new_sdram_controller_0_my_partner -L sdram_system_inst_avalon_bridge_bfm -L sdram_system_inst_reset_bfm -L sdram_system_inst_clk_bfm -L sdram_system_inst -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneii_ver $TOP_LEVEL_NAME
}

# ----------------------------------------
# Compile all the design files and elaborate the top level design
alias ld "
  dev_com
  com
  elab
"

# ----------------------------------------
# Compile all the design files and elaborate the top level design with -novopt
alias ld_debug "
  dev_com
  com
  elab_debug
"

# ----------------------------------------
# Print out user commmand line aliases
alias h {
  echo "List Of Command Line Aliases"
  echo
  echo "file_copy                     -- Copy ROM/RAM files to simulation directory"
  echo
  echo "dev_com                       -- Compile device library files"
  echo
  echo "com                           -- Compile the design files in correct order"
  echo
  echo "elab                          -- Elaborate top level design"
  echo
  echo "elab_debug                    -- Elaborate the top level design with novopt option"
  echo
  echo "ld                            -- Compile all the design files and elaborate the top level design"
  echo
  echo "ld_debug                      -- Compile all the design files and elaborate the top level design with -novopt"
  echo
  echo 
  echo
  echo "List Of Variables"
  echo
  echo "TOP_LEVEL_NAME                -- Top level module name."
  echo
  echo "SYSTEM_INSTANCE_NAME          -- Instantiated system module name inside top level module."
  echo
  echo "QSYS_SIMDIR                   -- Qsys base simulation directory."
  echo
  echo "QUARTUS_INSTALL_DIR           -- Quartus installation directory."
}
file_copy
h
