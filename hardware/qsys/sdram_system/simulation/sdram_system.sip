set_global_assignment -entity "sdram_system" -library "lib_sdram_system" -name IP_TOOL_NAME "Qsys"
set_global_assignment -entity "sdram_system" -library "lib_sdram_system" -name IP_TOOL_VERSION "13.0sp1"
set_global_assignment -entity "sdram_system" -library "lib_sdram_system" -name IP_TOOL_ENV "Qsys"
set_global_assignment -library "lib_sdram_system" -name SPD_FILE [file join $::quartus(sip_path) "../../sdram_system.spd"]
set_global_assignment -library "lib_sdram_system" -name MISC_FILE [file join $::quartus(sip_path) "../../sdram_system.qsys"]

set_global_assignment -library "lib_sdram_system" -name MISC_FILE [file join $::quartus(sip_path) "sdram_system.v"]
set_global_assignment -library "lib_sdram_system" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_reset_controller.v"]
set_global_assignment -library "lib_sdram_system" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_reset_synchronizer.v"]
set_global_assignment -library "lib_sdram_system" -name MISC_FILE [file join $::quartus(sip_path) "submodules/altera_reset_controller.sdc"]
set_global_assignment -library "lib_sdram_system" -name MISC_FILE [file join $::quartus(sip_path) "submodules/sdram_system_new_sdram_controller_0_test_component.v"]
set_global_assignment -library "lib_sdram_system" -name MISC_FILE [file join $::quartus(sip_path) "submodules/sdram_system_new_sdram_controller_0.v"]
