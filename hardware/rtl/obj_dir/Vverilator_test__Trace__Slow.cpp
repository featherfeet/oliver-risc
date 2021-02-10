// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vverilator_test__Syms.h"


//======================

void Vverilator_test::_traceDump() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumperp->dump(VL_TIME_Q());
}
void Vverilator_test::_traceDumpOpen() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    if (VL_UNLIKELY(!__VlSymsp->__Vm_dumperp)) {
        __VlSymsp->__Vm_dumperp = new VerilatedVcdC();
        const char* cp = vl_dumpctl_filenamep();
        trace(__VlSymsp->__Vm_dumperp, 0, 0);
        __VlSymsp->__Vm_dumperp->open(vl_dumpctl_filenamep());
        __VlSymsp->__Vm_dumperp->changeThread();
        __VlSymsp->__Vm_dumping = true;
    }
}
void Vverilator_test::_traceDumpClose() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumping = false;
    VL_DO_CLEAR(delete __VlSymsp->__Vm_dumperp, __VlSymsp->__Vm_dumperp = nullptr);
}
void Vverilator_test::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vverilator_test::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vverilator_test::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vverilator_test::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    Vverilator_test* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vverilator_test::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    Vverilator_test* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+282,"clk", false,-1);
        tracep->declBit(c+283,"reset_n", false,-1);
        tracep->declBit(c+284,"verilator_only_dram_clk", false,-1);
        tracep->declBit(c+285,"verilator_only_vga_pixel_clock", false,-1);
        tracep->declBit(c+282,"verilator_test clk", false,-1);
        tracep->declBit(c+283,"verilator_test reset_n", false,-1);
        tracep->declBit(c+284,"verilator_test verilator_only_dram_clk", false,-1);
        tracep->declBit(c+285,"verilator_test verilator_only_vga_pixel_clock", false,-1);
        tracep->declBus(c+1,"verilator_test i", false,-1, 31,0);
        tracep->declBit(c+294,"verilator_test PS2_CLK", false,-1);
        tracep->declBit(c+294,"verilator_test PS2_DAT", false,-1);
        tracep->declBit(c+284,"verilator_test SDRAM_CLK", false,-1);
        tracep->declBus(c+214,"verilator_test DRAM_ADDR", false,-1, 11,0);
        tracep->declBit(c+215,"verilator_test DRAM_BA_0", false,-1);
        tracep->declBit(c+216,"verilator_test DRAM_BA_1", false,-1);
        tracep->declBit(c+217,"verilator_test DRAM_CAS_N", false,-1);
        tracep->declBit(c+294,"verilator_test DRAM_CKE", false,-1);
        tracep->declBit(c+218,"verilator_test DRAM_CS_N", false,-1);
        tracep->declBus(c+219,"verilator_test DRAM_DQ", false,-1, 15,0);
        tracep->declBit(c+220,"verilator_test DRAM_LDQM", false,-1);
        tracep->declBit(c+221,"verilator_test DRAM_UDQM", false,-1);
        tracep->declBit(c+222,"verilator_test DRAM_RAS_N", false,-1);
        tracep->declBit(c+223,"verilator_test DRAM_WE_N", false,-1);
        tracep->declBus(c+173,"verilator_test VGA_R", false,-1, 3,0);
        tracep->declBus(c+174,"verilator_test VGA_G", false,-1, 3,0);
        tracep->declBus(c+175,"verilator_test VGA_B", false,-1, 3,0);
        tracep->declBit(c+183,"verilator_test VGA_HS", false,-1);
        tracep->declBit(c+184,"verilator_test VGA_VS", false,-1);
        tracep->declBit(c+285,"verilator_test VGA_PIXEL_CLOCK", false,-1);
        tracep->declArray(c+295,"verilator_test sdram_module INIT_FILE", false,-1, 247,0);
        tracep->declBus(c+219,"verilator_test sdram_module zs_dq", false,-1, 15,0);
        tracep->declBit(c+284,"verilator_test sdram_module clk", false,-1);
        tracep->declBus(c+214,"verilator_test sdram_module zs_addr", false,-1, 11,0);
        tracep->declBus(c+224,"verilator_test sdram_module zs_ba", false,-1, 1,0);
        tracep->declBit(c+217,"verilator_test sdram_module zs_cas_n", false,-1);
        tracep->declBit(c+294,"verilator_test sdram_module zs_cke", false,-1);
        tracep->declBit(c+218,"verilator_test sdram_module zs_cs_n", false,-1);
        tracep->declBus(c+225,"verilator_test sdram_module zs_dqm", false,-1, 1,0);
        tracep->declBit(c+222,"verilator_test sdram_module zs_ras_n", false,-1);
        tracep->declBit(c+223,"verilator_test sdram_module zs_we_n", false,-1);
        tracep->declBus(c+226,"verilator_test sdram_module CODE", false,-1, 23,0);
        tracep->declBus(c+214,"verilator_test sdram_module a", false,-1, 11,0);
        tracep->declBus(c+227,"verilator_test sdram_module addr_col", false,-1, 7,0);
        tracep->declBus(c+197,"verilator_test sdram_module addr_crb", false,-1, 13,0);
        tracep->declBus(c+224,"verilator_test sdram_module ba", false,-1, 1,0);
        tracep->declBit(c+217,"verilator_test sdram_module cas_n", false,-1);
        tracep->declBit(c+294,"verilator_test sdram_module cke", false,-1);
        tracep->declBus(c+228,"verilator_test sdram_module cmd_code", false,-1, 2,0);
        tracep->declBit(c+218,"verilator_test sdram_module cs_n", false,-1);
        tracep->declBus(c+225,"verilator_test sdram_module dqm", false,-1, 1,0);
        tracep->declBus(c+198,"verilator_test sdram_module index", false,-1, 2,0);
        tracep->declBus(c+199,"verilator_test sdram_module latency", false,-1, 2,0);
        tracep->declBus(c+200,"verilator_test sdram_module mask", false,-1, 1,0);
        tracep->declBus(c+229,"verilator_test sdram_module mem_bytes", false,-1, 15,0);
        tracep->declBit(c+222,"verilator_test sdram_module ras_n", false,-1);
        tracep->declBus(c+201,"verilator_test sdram_module rd_addr_pipe_0", false,-1, 21,0);
        tracep->declBus(c+202,"verilator_test sdram_module rd_addr_pipe_1", false,-1, 21,0);
        tracep->declBus(c+203,"verilator_test sdram_module rd_addr_pipe_2", false,-1, 21,0);
        tracep->declBus(c+204,"verilator_test sdram_module rd_mask_pipe_0", false,-1, 1,0);
        tracep->declBus(c+205,"verilator_test sdram_module rd_mask_pipe_1", false,-1, 1,0);
        tracep->declBus(c+206,"verilator_test sdram_module rd_mask_pipe_2", false,-1, 1,0);
        tracep->declBus(c+207,"verilator_test sdram_module rd_valid_pipe", false,-1, 2,0);
        tracep->declBus(c+286,"verilator_test sdram_module rdaddress", false,-1, 21,0);
        tracep->declBus(c+208,"verilator_test sdram_module read_addr", false,-1, 21,0);
        tracep->declBus(c+286,"verilator_test sdram_module read_address", false,-1, 21,0);
        tracep->declBus(c+229,"verilator_test sdram_module read_data", false,-1, 15,0);
        tracep->declBus(c+200,"verilator_test sdram_module read_mask", false,-1, 1,0);
        tracep->declBus(c+287,"verilator_test sdram_module read_temp", false,-1, 15,0);
        tracep->declBit(c+209,"verilator_test sdram_module read_valid", false,-1);
        tracep->declBus(c+230,"verilator_test sdram_module rmw_temp", false,-1, 15,0);
        tracep->declBus(c+231,"verilator_test sdram_module test_addr", false,-1, 21,0);
        tracep->declBus(c+232,"verilator_test sdram_module txt_code", false,-1, 23,0);
        tracep->declBit(c+223,"verilator_test sdram_module we_n", false,-1);
        tracep->declBit(c+233,"verilator_test sdram_module wren", false,-1);
        tracep->declBus(c+2,"verilator_test sdram_module i", false,-1, 31,0);
        tracep->declBus(c+288,"verilator_test top_instantiation KEY", false,-1, 3,0);
        tracep->declBit(c+282,"verilator_test top_instantiation CLOCK_50", false,-1);
        tracep->declBit(c+284,"verilator_test top_instantiation DRAM_CLK", false,-1);
        tracep->declBus(c+214,"verilator_test top_instantiation DRAM_ADDR", false,-1, 11,0);
        tracep->declBit(c+215,"verilator_test top_instantiation DRAM_BA_0", false,-1);
        tracep->declBit(c+216,"verilator_test top_instantiation DRAM_BA_1", false,-1);
        tracep->declBit(c+217,"verilator_test top_instantiation DRAM_CAS_N", false,-1);
        tracep->declBit(c+294,"verilator_test top_instantiation DRAM_CKE", false,-1);
        tracep->declBit(c+218,"verilator_test top_instantiation DRAM_CS_N", false,-1);
        tracep->declBit(c+220,"verilator_test top_instantiation DRAM_LDQM", false,-1);
        tracep->declBit(c+221,"verilator_test top_instantiation DRAM_UDQM", false,-1);
        tracep->declBit(c+222,"verilator_test top_instantiation DRAM_RAS_N", false,-1);
        tracep->declBit(c+223,"verilator_test top_instantiation DRAM_WE_N", false,-1);
        tracep->declBus(c+219,"verilator_test top_instantiation DRAM_DQ", false,-1, 15,0);
        tracep->declBus(c+173,"verilator_test top_instantiation VGA_R", false,-1, 3,0);
        tracep->declBus(c+174,"verilator_test top_instantiation VGA_G", false,-1, 3,0);
        tracep->declBus(c+175,"verilator_test top_instantiation VGA_B", false,-1, 3,0);
        tracep->declBit(c+183,"verilator_test top_instantiation VGA_HS", false,-1);
        tracep->declBit(c+184,"verilator_test top_instantiation VGA_VS", false,-1);
        tracep->declBit(c+285,"verilator_test top_instantiation VGA_PIXEL_CLOCK", false,-1);
        tracep->declBit(c+294,"verilator_test top_instantiation PS2_CLK", false,-1);
        tracep->declBit(c+294,"verilator_test top_instantiation PS2_DAT", false,-1);
        tracep->declBus(c+6,"verilator_test top_instantiation LEDG", false,-1, 7,0);
        tracep->declQuad(c+303,"verilator_test top_instantiation GPIO_0", false,-1, 35,0);
        tracep->declBit(c+284,"verilator_test top_instantiation verilator_only_dram_clk", false,-1);
        tracep->declBit(c+285,"verilator_test top_instantiation verilator_only_vga_pixel_clock", false,-1);
        tracep->declBus(c+7,"verilator_test top_instantiation i", false,-1, 31,0);
        tracep->declBus(c+8,"verilator_test top_instantiation operation", false,-1, 7,0);
        tracep->declBus(c+9,"verilator_test top_instantiation operand1", false,-1, 31,0);
        tracep->declBus(c+10,"verilator_test top_instantiation operand2", false,-1, 31,0);
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+11+i*1,"verilator_test top_instantiation registers", true,(i+0), 31,0);}}
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+21+i*1,"verilator_test top_instantiation shadow_registers", true,(i+0), 31,0);}}
        tracep->declBus(c+31,"verilator_test top_instantiation code_section_start_address", false,-1, 31,0);
        tracep->declBus(c+32,"verilator_test top_instantiation program_end_address", false,-1, 31,0);
        tracep->declBus(c+33,"verilator_test top_instantiation temp_address", false,-1, 31,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+34+i*1,"verilator_test top_instantiation interrupt_vector_table", true,(i+0), 31,0);}}
        tracep->declBus(c+42,"verilator_test top_instantiation interrupt_fifo_data_in", false,-1, 31,0);
        tracep->declBit(c+43,"verilator_test top_instantiation interrupt_fifo_write", false,-1);
        tracep->declBit(c+44,"verilator_test top_instantiation interrupt_fifo_empty", false,-1);
        tracep->declBit(c+45,"verilator_test top_instantiation interrupt_fifo_full", false,-1);
        tracep->declBus(c+46,"verilator_test top_instantiation interrupt_fifo_data_out", false,-1, 31,0);
        tracep->declBit(c+47,"verilator_test top_instantiation interrupt_fifo_read", false,-1);
        tracep->declBus(c+48,"verilator_test top_instantiation interrupt_fifo_access_state", false,-1, 1,0);
        tracep->declBus(c+49,"verilator_test top_instantiation interrupt_value_fifo_data_in", false,-1, 31,0);
        tracep->declBit(c+50,"verilator_test top_instantiation interrupt_value_fifo_write", false,-1);
        tracep->declBus(c+51,"verilator_test top_instantiation interrupt_value_fifo_data_out", false,-1, 31,0);
        tracep->declBit(c+52,"verilator_test top_instantiation interrupt_value_fifo_read", false,-1);
        tracep->declBus(c+6,"verilator_test top_instantiation keyboard_scancode", false,-1, 7,0);
        tracep->declBit(c+53,"verilator_test top_instantiation keyboard_scancode_ready", false,-1);
        tracep->declBus(c+54,"verilator_test top_instantiation keyboard_scancode_fifo_data_out", false,-1, 7,0);
        tracep->declBit(c+55,"verilator_test top_instantiation keyboard_scancode_fifo_read", false,-1);
        tracep->declBit(c+56,"verilator_test top_instantiation keyboard_scancode_fifo_empty", false,-1);
        tracep->declBit(c+57,"verilator_test top_instantiation keyboard_scancode_fifo_full", false,-1);
        tracep->declBus(c+58,"verilator_test top_instantiation keyboard_scancode_fifo_access_state", false,-1, 2,0);
        tracep->declBus(c+59,"verilator_test top_instantiation gpu_cell_to_access", false,-1, 13,0);
        tracep->declBit(c+60,"verilator_test top_instantiation gpu_write_enable", false,-1);
        tracep->declBus(c+61,"verilator_test top_instantiation gpu_character_to_write", false,-1, 7,0);
        tracep->declBus(c+62,"verilator_test top_instantiation gpu_character_read", false,-1, 7,0);
        tracep->declBit(c+63,"verilator_test top_instantiation gpu_access_state", false,-1);
        tracep->declBus(c+64,"verilator_test top_instantiation program_rom_address", false,-1, 31,0);
        tracep->declBus(c+65,"verilator_test top_instantiation program_rom_byte", false,-1, 7,0);
        tracep->declBit(c+66,"verilator_test top_instantiation program_rom_done", false,-1);
        tracep->declBit(c+67,"verilator_test top_instantiation program_rom_read_state", false,-1);
        tracep->declBus(c+68,"verilator_test top_instantiation sdram_controller_address_i", false,-1, 21,0);
        tracep->declBus(c+69,"verilator_test top_instantiation sdram_controller_be_n_i", false,-1, 1,0);
        tracep->declBit(c+70,"verilator_test top_instantiation sdram_controller_cs_i", false,-1);
        tracep->declBus(c+71,"verilator_test top_instantiation sdram_controller_data_i", false,-1, 15,0);
        tracep->declBit(c+72,"verilator_test top_instantiation sdram_controller_rd_n_i", false,-1);
        tracep->declBit(c+73,"verilator_test top_instantiation sdram_controller_wr_n_i", false,-1);
        tracep->declBus(c+178,"verilator_test top_instantiation sdram_controller_data_o", false,-1, 15,0);
        tracep->declBit(c+179,"verilator_test top_instantiation sdram_controller_valid_o", false,-1);
        tracep->declBit(c+234,"verilator_test top_instantiation sdram_controller_waitrequest_o", false,-1);
        tracep->declBit(c+235,"verilator_test top_instantiation sdram_controller_init_done", false,-1);
        tracep->declBus(c+74,"verilator_test top_instantiation ram_write_state", false,-1, 7,0);
        tracep->declBus(c+305,"verilator_test top_instantiation WAIT_FOR_RAM_WRITE", false,-1, 7,0);
        tracep->declBus(c+306,"verilator_test top_instantiation WRITE_TO_RAM", false,-1, 7,0);
        tracep->declBus(c+307,"verilator_test top_instantiation RAM_WRITE_DONE", false,-1, 7,0);
        tracep->declBit(c+75,"verilator_test top_instantiation ram_write_complete", false,-1);
        tracep->declBus(c+76,"verilator_test top_instantiation ram_read_state", false,-1, 7,0);
        tracep->declBus(c+305,"verilator_test top_instantiation LATCH_RAM_READ_ADDRESS", false,-1, 7,0);
        tracep->declBus(c+306,"verilator_test top_instantiation START_READ_FROM_RAM", false,-1, 7,0);
        tracep->declBus(c+307,"verilator_test top_instantiation WAIT_FOR_RAM_READ", false,-1, 7,0);
        tracep->declBit(c+77,"verilator_test top_instantiation ram_read_complete", false,-1);
        tracep->declBus(c+78,"verilator_test top_instantiation ram_read_data", false,-1, 15,0);
        tracep->declBus(c+79,"verilator_test top_instantiation ram_stabilization_counter", false,-1, 7,0);
        tracep->declBus(c+80,"verilator_test top_instantiation operand_byte_index", false,-1, 7,0);
        tracep->declBus(c+81,"verilator_test top_instantiation state", false,-1, 7,0);
        tracep->declBus(c+82,"verilator_test top_instantiation division_delay_counter", false,-1, 4,0);
        tracep->declBus(c+83,"verilator_test top_instantiation divider_numerator", false,-1, 31,0);
        tracep->declBus(c+84,"verilator_test top_instantiation divider_denominator", false,-1, 31,0);
        tracep->declBus(c+85,"verilator_test top_instantiation divider_quotient", false,-1, 31,0);
        tracep->declBus(c+86,"verilator_test top_instantiation divider_remainder", false,-1, 31,0);
        tracep->declBus(c+308,"verilator_test top_instantiation interrupt_fifo ITEM_SIZE_BITS", false,-1, 31,0);
        tracep->declBus(c+309,"verilator_test top_instantiation interrupt_fifo FIFO_SIZE", false,-1, 31,0);
        tracep->declBit(c+282,"verilator_test top_instantiation interrupt_fifo CLOCK_50", false,-1);
        tracep->declBit(c+283,"verilator_test top_instantiation interrupt_fifo RST_N", false,-1);
        tracep->declBus(c+42,"verilator_test top_instantiation interrupt_fifo data_in", false,-1, 31,0);
        tracep->declBit(c+43,"verilator_test top_instantiation interrupt_fifo write", false,-1);
        tracep->declBus(c+46,"verilator_test top_instantiation interrupt_fifo data_out", false,-1, 31,0);
        tracep->declBit(c+47,"verilator_test top_instantiation interrupt_fifo read", false,-1);
        tracep->declBit(c+44,"verilator_test top_instantiation interrupt_fifo empty", false,-1);
        tracep->declBit(c+45,"verilator_test top_instantiation interrupt_fifo full", false,-1);
        tracep->declBus(c+87,"verilator_test top_instantiation interrupt_fifo write_pointer", false,-1, 3,0);
        tracep->declBus(c+88,"verilator_test top_instantiation interrupt_fifo read_pointer", false,-1, 3,0);
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+89+i*1,"verilator_test top_instantiation interrupt_fifo items", true,(i+0), 31,0);}}
        tracep->declBus(c+99,"verilator_test top_instantiation interrupt_fifo current_fifo_size", false,-1, 3,0);
        tracep->declBus(c+100,"verilator_test top_instantiation interrupt_fifo i", false,-1, 31,0);
        tracep->declBus(c+308,"verilator_test top_instantiation interrupt_value_fifo ITEM_SIZE_BITS", false,-1, 31,0);
        tracep->declBus(c+309,"verilator_test top_instantiation interrupt_value_fifo FIFO_SIZE", false,-1, 31,0);
        tracep->declBit(c+282,"verilator_test top_instantiation interrupt_value_fifo CLOCK_50", false,-1);
        tracep->declBit(c+283,"verilator_test top_instantiation interrupt_value_fifo RST_N", false,-1);
        tracep->declBus(c+49,"verilator_test top_instantiation interrupt_value_fifo data_in", false,-1, 31,0);
        tracep->declBit(c+50,"verilator_test top_instantiation interrupt_value_fifo write", false,-1);
        tracep->declBus(c+51,"verilator_test top_instantiation interrupt_value_fifo data_out", false,-1, 31,0);
        tracep->declBit(c+52,"verilator_test top_instantiation interrupt_value_fifo read", false,-1);
        tracep->declBit(c+101,"verilator_test top_instantiation interrupt_value_fifo empty", false,-1);
        tracep->declBit(c+102,"verilator_test top_instantiation interrupt_value_fifo full", false,-1);
        tracep->declBus(c+103,"verilator_test top_instantiation interrupt_value_fifo write_pointer", false,-1, 3,0);
        tracep->declBus(c+104,"verilator_test top_instantiation interrupt_value_fifo read_pointer", false,-1, 3,0);
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+105+i*1,"verilator_test top_instantiation interrupt_value_fifo items", true,(i+0), 31,0);}}
        tracep->declBus(c+115,"verilator_test top_instantiation interrupt_value_fifo current_fifo_size", false,-1, 3,0);
        tracep->declBus(c+116,"verilator_test top_instantiation interrupt_value_fifo i", false,-1, 31,0);
        tracep->declBit(c+283,"verilator_test top_instantiation ps2_keyboard rst_n", false,-1);
        tracep->declBit(c+282,"verilator_test top_instantiation ps2_keyboard CLOCK_50", false,-1);
        tracep->declBit(c+294,"verilator_test top_instantiation ps2_keyboard PS2_CLK", false,-1);
        tracep->declBit(c+294,"verilator_test top_instantiation ps2_keyboard PS2_DAT", false,-1);
        tracep->declBus(c+6,"verilator_test top_instantiation ps2_keyboard scancode", false,-1, 7,0);
        tracep->declBit(c+53,"verilator_test top_instantiation ps2_keyboard ready", false,-1);
        tracep->declBus(c+117,"verilator_test top_instantiation ps2_keyboard ps2_clk_buffer", false,-1, 7,0);
        tracep->declBit(c+118,"verilator_test top_instantiation ps2_keyboard ps2_clk_filtered_state", false,-1);
        tracep->declBit(c+119,"verilator_test top_instantiation ps2_keyboard previous_ps2_clk_filtered_state", false,-1);
        tracep->declBit(c+120,"verilator_test top_instantiation ps2_keyboard ps2_clk_falling", false,-1);
        tracep->declBus(c+121,"verilator_test top_instantiation ps2_keyboard shift_register", false,-1, 10,0);
        tracep->declBus(c+122,"verilator_test top_instantiation ps2_keyboard bits_counter", false,-1, 3,0);
        tracep->declBus(c+310,"verilator_test top_instantiation keyboard_scancodes_fifo ITEM_SIZE_BITS", false,-1, 31,0);
        tracep->declBus(c+311,"verilator_test top_instantiation keyboard_scancodes_fifo FIFO_SIZE", false,-1, 31,0);
        tracep->declBit(c+282,"verilator_test top_instantiation keyboard_scancodes_fifo CLOCK_50", false,-1);
        tracep->declBit(c+283,"verilator_test top_instantiation keyboard_scancodes_fifo RST_N", false,-1);
        tracep->declBus(c+6,"verilator_test top_instantiation keyboard_scancodes_fifo data_in", false,-1, 7,0);
        tracep->declBit(c+53,"verilator_test top_instantiation keyboard_scancodes_fifo write", false,-1);
        tracep->declBus(c+54,"verilator_test top_instantiation keyboard_scancodes_fifo data_out", false,-1, 7,0);
        tracep->declBit(c+55,"verilator_test top_instantiation keyboard_scancodes_fifo read", false,-1);
        tracep->declBit(c+56,"verilator_test top_instantiation keyboard_scancodes_fifo empty", false,-1);
        tracep->declBit(c+57,"verilator_test top_instantiation keyboard_scancodes_fifo full", false,-1);
        tracep->declBus(c+123,"verilator_test top_instantiation keyboard_scancodes_fifo write_pointer", false,-1, 2,0);
        tracep->declBus(c+124,"verilator_test top_instantiation keyboard_scancodes_fifo read_pointer", false,-1, 2,0);
        {int i; for (i=0; i<5; i++) {
                tracep->declBus(c+125+i*1,"verilator_test top_instantiation keyboard_scancodes_fifo items", true,(i+0), 7,0);}}
        tracep->declBus(c+130,"verilator_test top_instantiation keyboard_scancodes_fifo current_fifo_size", false,-1, 2,0);
        tracep->declBus(c+131,"verilator_test top_instantiation keyboard_scancodes_fifo i", false,-1, 31,0);
        tracep->declBit(c+282,"verilator_test top_instantiation integrated_graphics CLOCK_50", false,-1);
        tracep->declBit(c+289,"verilator_test top_instantiation integrated_graphics reset", false,-1);
        tracep->declBit(c+285,"verilator_test top_instantiation integrated_graphics CLOCK_150", false,-1);
        tracep->declBus(c+173,"verilator_test top_instantiation integrated_graphics VGA_R", false,-1, 3,0);
        tracep->declBus(c+174,"verilator_test top_instantiation integrated_graphics VGA_G", false,-1, 3,0);
        tracep->declBus(c+175,"verilator_test top_instantiation integrated_graphics VGA_B", false,-1, 3,0);
        tracep->declBit(c+183,"verilator_test top_instantiation integrated_graphics VGA_HS", false,-1);
        tracep->declBit(c+184,"verilator_test top_instantiation integrated_graphics VGA_VS", false,-1);
        tracep->declBus(c+59,"verilator_test top_instantiation integrated_graphics cell_to_access", false,-1, 13,0);
        tracep->declBit(c+60,"verilator_test top_instantiation integrated_graphics write_enable", false,-1);
        tracep->declBus(c+61,"verilator_test top_instantiation integrated_graphics character_to_write", false,-1, 7,0);
        tracep->declBus(c+62,"verilator_test top_instantiation integrated_graphics character_read", false,-1, 7,0);
        tracep->declBit(c+185,"verilator_test top_instantiation integrated_graphics blanking", false,-1);
        tracep->declBus(c+186,"verilator_test top_instantiation integrated_graphics pixel_x", false,-1, 11,0);
        tracep->declBus(c+187,"verilator_test top_instantiation integrated_graphics pixel_y", false,-1, 10,0);
        tracep->declBus(c+188,"verilator_test top_instantiation integrated_graphics character_cell_x", false,-1, 2,0);
        tracep->declBus(c+189,"verilator_test top_instantiation integrated_graphics character_cell_y", false,-1, 3,0);
        tracep->declBus(c+190,"verilator_test top_instantiation integrated_graphics current_character_cell", false,-1, 13,0);
        tracep->declBus(c+191,"verilator_test top_instantiation integrated_graphics current_column", false,-1, 7,0);
        tracep->declBus(c+176,"verilator_test top_instantiation integrated_graphics current_character", false,-1, 7,0);
        tracep->declBit(c+177,"verilator_test top_instantiation integrated_graphics current_pixel_value", false,-1);
        tracep->declBit(c+282,"verilator_test top_instantiation integrated_graphics text_buffer port_a_clock", false,-1);
        tracep->declBit(c+285,"verilator_test top_instantiation integrated_graphics text_buffer port_b_clock", false,-1);
        tracep->declBus(c+59,"verilator_test top_instantiation integrated_graphics text_buffer port_a_address", false,-1, 13,0);
        tracep->declBus(c+190,"verilator_test top_instantiation integrated_graphics text_buffer port_b_address", false,-1, 13,0);
        tracep->declBus(c+61,"verilator_test top_instantiation integrated_graphics text_buffer port_a_data_in", false,-1, 7,0);
        tracep->declBit(c+60,"verilator_test top_instantiation integrated_graphics text_buffer port_a_write_enable", false,-1);
        tracep->declBus(c+62,"verilator_test top_instantiation integrated_graphics text_buffer port_a_data_out", false,-1, 7,0);
        tracep->declBus(c+176,"verilator_test top_instantiation integrated_graphics text_buffer port_b_data_out", false,-1, 7,0);
        tracep->declBit(c+285,"verilator_test top_instantiation integrated_graphics vga i_clk", false,-1);
        tracep->declBit(c+283,"verilator_test top_instantiation integrated_graphics vga i_rst", false,-1);
        tracep->declBit(c+183,"verilator_test top_instantiation integrated_graphics vga o_hs", false,-1);
        tracep->declBit(c+184,"verilator_test top_instantiation integrated_graphics vga o_vs", false,-1);
        tracep->declBit(c+185,"verilator_test top_instantiation integrated_graphics vga o_blanking", false,-1);
        tracep->declBit(c+192,"verilator_test top_instantiation integrated_graphics vga o_active", false,-1);
        tracep->declBit(c+193,"verilator_test top_instantiation integrated_graphics vga o_screenend", false,-1);
        tracep->declBit(c+194,"verilator_test top_instantiation integrated_graphics vga o_animate", false,-1);
        tracep->declBus(c+186,"verilator_test top_instantiation integrated_graphics vga o_x", false,-1, 11,0);
        tracep->declBus(c+187,"verilator_test top_instantiation integrated_graphics vga o_y", false,-1, 10,0);
        tracep->declBus(c+312,"verilator_test top_instantiation integrated_graphics vga HS_STA", false,-1, 31,0);
        tracep->declBus(c+313,"verilator_test top_instantiation integrated_graphics vga HS_END", false,-1, 31,0);
        tracep->declBus(c+314,"verilator_test top_instantiation integrated_graphics vga HA_STA", false,-1, 31,0);
        tracep->declBus(c+315,"verilator_test top_instantiation integrated_graphics vga VS_STA", false,-1, 31,0);
        tracep->declBus(c+316,"verilator_test top_instantiation integrated_graphics vga VS_END", false,-1, 31,0);
        tracep->declBus(c+317,"verilator_test top_instantiation integrated_graphics vga VA_END", false,-1, 31,0);
        tracep->declBus(c+318,"verilator_test top_instantiation integrated_graphics vga LINE", false,-1, 31,0);
        tracep->declBus(c+319,"verilator_test top_instantiation integrated_graphics vga SCREEN", false,-1, 31,0);
        tracep->declBus(c+195,"verilator_test top_instantiation integrated_graphics vga h_count", false,-1, 12,0);
        tracep->declBus(c+196,"verilator_test top_instantiation integrated_graphics vga v_count", false,-1, 11,0);
        tracep->declBit(c+285,"verilator_test top_instantiation integrated_graphics font_glyphs CLOCK_150", false,-1);
        tracep->declBus(c+176,"verilator_test top_instantiation integrated_graphics font_glyphs character", false,-1, 7,0);
        tracep->declBus(c+188,"verilator_test top_instantiation integrated_graphics font_glyphs character_cell_x", false,-1, 2,0);
        tracep->declBus(c+189,"verilator_test top_instantiation integrated_graphics font_glyphs character_cell_y", false,-1, 3,0);
        tracep->declBit(c+177,"verilator_test top_instantiation integrated_graphics font_glyphs pixel_value", false,-1);
        tracep->declBit(c+282,"verilator_test top_instantiation program_rom CLOCK_50", false,-1);
        tracep->declBus(c+64,"verilator_test top_instantiation program_rom address", false,-1, 31,0);
        tracep->declBus(c+65,"verilator_test top_instantiation program_rom output_byte", false,-1, 7,0);
        tracep->declBit(c+66,"verilator_test top_instantiation program_rom done", false,-1);
        tracep->declBus(c+178,"verilator_test top_instantiation sdram_controller za_data", false,-1, 15,0);
        tracep->declBit(c+179,"verilator_test top_instantiation sdram_controller za_valid", false,-1);
        tracep->declBit(c+234,"verilator_test top_instantiation sdram_controller za_waitrequest", false,-1);
        tracep->declBus(c+214,"verilator_test top_instantiation sdram_controller zs_addr", false,-1, 11,0);
        tracep->declBus(c+224,"verilator_test top_instantiation sdram_controller zs_ba", false,-1, 1,0);
        tracep->declBit(c+217,"verilator_test top_instantiation sdram_controller zs_cas_n", false,-1);
        tracep->declBit(c+294,"verilator_test top_instantiation sdram_controller zs_cke", false,-1);
        tracep->declBit(c+218,"verilator_test top_instantiation sdram_controller zs_cs_n", false,-1);
        tracep->declBus(c+219,"verilator_test top_instantiation sdram_controller zs_dq", false,-1, 15,0);
        tracep->declBus(c+225,"verilator_test top_instantiation sdram_controller zs_dqm", false,-1, 1,0);
        tracep->declBit(c+222,"verilator_test top_instantiation sdram_controller zs_ras_n", false,-1);
        tracep->declBit(c+223,"verilator_test top_instantiation sdram_controller zs_we_n", false,-1);
        tracep->declBus(c+68,"verilator_test top_instantiation sdram_controller az_addr", false,-1, 21,0);
        tracep->declBus(c+69,"verilator_test top_instantiation sdram_controller az_be_n", false,-1, 1,0);
        tracep->declBit(c+70,"verilator_test top_instantiation sdram_controller az_cs", false,-1);
        tracep->declBus(c+71,"verilator_test top_instantiation sdram_controller az_data", false,-1, 15,0);
        tracep->declBit(c+72,"verilator_test top_instantiation sdram_controller az_rd_n", false,-1);
        tracep->declBit(c+73,"verilator_test top_instantiation sdram_controller az_wr_n", false,-1);
        tracep->declBit(c+284,"verilator_test top_instantiation sdram_controller clk", false,-1);
        tracep->declBit(c+283,"verilator_test top_instantiation sdram_controller reset_n", false,-1);
        tracep->declBus(c+236,"verilator_test top_instantiation sdram_controller CODE", false,-1, 23,0);
        tracep->declBit(c+237,"verilator_test top_instantiation sdram_controller ack_refresh_request", false,-1);
        tracep->declBus(c+238,"verilator_test top_instantiation sdram_controller active_addr", false,-1, 21,0);
        tracep->declBus(c+239,"verilator_test top_instantiation sdram_controller active_bank", false,-1, 1,0);
        tracep->declBit(c+240,"verilator_test top_instantiation sdram_controller active_cs_n", false,-1);
        tracep->declBus(c+241,"verilator_test top_instantiation sdram_controller active_data", false,-1, 15,0);
        tracep->declBus(c+242,"verilator_test top_instantiation sdram_controller active_dqm", false,-1, 1,0);
        tracep->declBit(c+243,"verilator_test top_instantiation sdram_controller active_rnw", false,-1);
        tracep->declBit(c+244,"verilator_test top_instantiation sdram_controller almost_empty", false,-1);
        tracep->declBit(c+245,"verilator_test top_instantiation sdram_controller almost_full", false,-1);
        tracep->declBit(c+246,"verilator_test top_instantiation sdram_controller bank_match", false,-1);
        tracep->declBus(c+247,"verilator_test top_instantiation sdram_controller cas_addr", false,-1, 7,0);
        tracep->declBit(c+294,"verilator_test top_instantiation sdram_controller clk_en", false,-1);
        tracep->declBus(c+248,"verilator_test top_instantiation sdram_controller cmd_all", false,-1, 3,0);
        tracep->declBus(c+249,"verilator_test top_instantiation sdram_controller cmd_code", false,-1, 2,0);
        tracep->declBit(c+250,"verilator_test top_instantiation sdram_controller cs_n", false,-1);
        tracep->declBit(c+250,"verilator_test top_instantiation sdram_controller csn_decode", false,-1);
        tracep->declBit(c+251,"verilator_test top_instantiation sdram_controller csn_match", false,-1);
        tracep->declBus(c+252,"verilator_test top_instantiation sdram_controller f_addr", false,-1, 21,0);
        tracep->declBus(c+253,"verilator_test top_instantiation sdram_controller f_bank", false,-1, 1,0);
        tracep->declBit(c+320,"verilator_test top_instantiation sdram_controller f_cs_n", false,-1);
        tracep->declBus(c+254,"verilator_test top_instantiation sdram_controller f_data", false,-1, 15,0);
        tracep->declBus(c+255,"verilator_test top_instantiation sdram_controller f_dqm", false,-1, 1,0);
        tracep->declBit(c+256,"verilator_test top_instantiation sdram_controller f_empty", false,-1);
        tracep->declBit(c+257,"verilator_test top_instantiation sdram_controller f_pop", false,-1);
        tracep->declBit(c+258,"verilator_test top_instantiation sdram_controller f_rnw", false,-1);
        tracep->declBit(c+259,"verilator_test top_instantiation sdram_controller f_select", false,-1);
        tracep->declQuad(c+260,"verilator_test top_instantiation sdram_controller fifo_read_data", false,-1, 40,0);
        tracep->declBus(c+262,"verilator_test top_instantiation sdram_controller i_addr", false,-1, 11,0);
        tracep->declBus(c+263,"verilator_test top_instantiation sdram_controller i_cmd", false,-1, 3,0);
        tracep->declBus(c+264,"verilator_test top_instantiation sdram_controller i_count", false,-1, 2,0);
        tracep->declBus(c+265,"verilator_test top_instantiation sdram_controller i_next", false,-1, 2,0);
        tracep->declBus(c+266,"verilator_test top_instantiation sdram_controller i_refs", false,-1, 2,0);
        tracep->declBus(c+267,"verilator_test top_instantiation sdram_controller i_state", false,-1, 2,0);
        tracep->declBit(c+235,"verilator_test top_instantiation sdram_controller init_done", false,-1);
        tracep->declBus(c+214,"verilator_test top_instantiation sdram_controller m_addr", false,-1, 11,0);
        tracep->declBus(c+224,"verilator_test top_instantiation sdram_controller m_bank", false,-1, 1,0);
        tracep->declBus(c+248,"verilator_test top_instantiation sdram_controller m_cmd", false,-1, 3,0);
        tracep->declBus(c+268,"verilator_test top_instantiation sdram_controller m_count", false,-1, 2,0);
        tracep->declBus(c+269,"verilator_test top_instantiation sdram_controller m_data", false,-1, 15,0);
        tracep->declBus(c+225,"verilator_test top_instantiation sdram_controller m_dqm", false,-1, 1,0);
        tracep->declBus(c+270,"verilator_test top_instantiation sdram_controller m_next", false,-1, 8,0);
        tracep->declBus(c+271,"verilator_test top_instantiation sdram_controller m_state", false,-1, 8,0);
        tracep->declBit(c+272,"verilator_test top_instantiation sdram_controller oe", false,-1);
        tracep->declBit(c+273,"verilator_test top_instantiation sdram_controller pending", false,-1);
        tracep->declBit(c+274,"verilator_test top_instantiation sdram_controller rd_strobe", false,-1);
        tracep->declBus(c+180,"verilator_test top_instantiation sdram_controller rd_valid", false,-1, 2,0);
        tracep->declBus(c+275,"verilator_test top_instantiation sdram_controller refresh_counter", false,-1, 12,0);
        tracep->declBit(c+276,"verilator_test top_instantiation sdram_controller refresh_request", false,-1);
        tracep->declBit(c+277,"verilator_test top_instantiation sdram_controller rnw_match", false,-1);
        tracep->declBit(c+278,"verilator_test top_instantiation sdram_controller row_match", false,-1);
        tracep->declBus(c+279,"verilator_test top_instantiation sdram_controller txt_code", false,-1, 23,0);
        tracep->declBit(c+181,"verilator_test top_instantiation sdram_controller za_cannotrefresh", false,-1);
        tracep->declBit(c+244,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module almost_empty", false,-1);
        tracep->declBit(c+245,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module almost_full", false,-1);
        tracep->declBit(c+256,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module empty", false,-1);
        tracep->declBit(c+234,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module full", false,-1);
        tracep->declQuad(c+260,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rd_data", false,-1, 40,0);
        tracep->declBit(c+284,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module clk", false,-1);
        tracep->declBit(c+259,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rd", false,-1);
        tracep->declBit(c+283,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module reset_n", false,-1);
        tracep->declBit(c+290,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module wr", false,-1);
        tracep->declQuad(c+291,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module wr_data", false,-1, 40,0);
        tracep->declBus(c+280,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module entries", false,-1, 1,0);
        tracep->declQuad(c+210,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module entry_0", false,-1, 40,0);
        tracep->declQuad(c+212,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module entry_1", false,-1, 40,0);
        tracep->declBit(c+182,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rd_address", false,-1);
        tracep->declBus(c+293,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rdwr", false,-1, 1,0);
        tracep->declBit(c+281,"verilator_test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module wr_address", false,-1);
        tracep->declBus(c+308,"verilator_test top_instantiation divider lpm_widthn", false,-1, 31,0);
        tracep->declBus(c+308,"verilator_test top_instantiation divider lpm_widthd", false,-1, 31,0);
        tracep->declQuad(c+321,"verilator_test top_instantiation divider lpm_nrepresentation", false,-1, 63,0);
        tracep->declQuad(c+321,"verilator_test top_instantiation divider lpm_drepresentation", false,-1, 63,0);
        tracep->declBus(c+323,"verilator_test top_instantiation divider lpm_pipeline", false,-1, 31,0);
        tracep->declArray(c+324,"verilator_test top_instantiation divider lpm_type", false,-1, 79,0);
        tracep->declArray(c+327,"verilator_test top_instantiation divider lpm_hint", false,-1, 207,0);
        tracep->declBus(c+83,"verilator_test top_instantiation divider numer", false,-1, 31,0);
        tracep->declBus(c+84,"verilator_test top_instantiation divider denom", false,-1, 31,0);
        tracep->declBit(c+282,"verilator_test top_instantiation divider clock", false,-1);
        tracep->declBit(c+334,"verilator_test top_instantiation divider aclr", false,-1);
        tracep->declBit(c+335,"verilator_test top_instantiation divider clken", false,-1);
        tracep->declBus(c+85,"verilator_test top_instantiation divider quotient", false,-1, 31,0);
        tracep->declBus(c+86,"verilator_test top_instantiation divider remain", false,-1, 31,0);
        {int i; for (i=0; i<17; i++) {
                tracep->declBus(c+132+i*1,"verilator_test top_instantiation divider quotient_pipe", true,(i+0), 31,0);}}
        {int i; for (i=0; i<17; i++) {
                tracep->declBus(c+149+i*1,"verilator_test top_instantiation divider remain_pipe", true,(i+0), 31,0);}}
        tracep->declBus(c+166,"verilator_test top_instantiation divider tmp_quotient", false,-1, 31,0);
        tracep->declBus(c+167,"verilator_test top_instantiation divider tmp_remain", false,-1, 31,0);
        tracep->declBus(c+336,"verilator_test top_instantiation divider not_numer", false,-1, 31,0);
        tracep->declBus(c+337,"verilator_test top_instantiation divider int_numer", false,-1, 31,0);
        tracep->declBus(c+338,"verilator_test top_instantiation divider not_denom", false,-1, 31,0);
        tracep->declBus(c+339,"verilator_test top_instantiation divider int_denom", false,-1, 31,0);
        tracep->declBus(c+168,"verilator_test top_instantiation divider t_numer", false,-1, 31,0);
        tracep->declBus(c+169,"verilator_test top_instantiation divider t_q", false,-1, 31,0);
        tracep->declBus(c+170,"verilator_test top_instantiation divider t_denom", false,-1, 31,0);
        tracep->declBus(c+171,"verilator_test top_instantiation divider t_r", false,-1, 31,0);
        tracep->declBit(c+320,"verilator_test top_instantiation divider sign_q", false,-1);
        tracep->declBit(c+320,"verilator_test top_instantiation divider sign_r", false,-1);
        tracep->declBit(c+320,"verilator_test top_instantiation divider sign_n", false,-1);
        tracep->declBit(c+320,"verilator_test top_instantiation divider sign_d", false,-1);
        tracep->declQuad(c+3,"verilator_test top_instantiation divider lpm_remainderpositive", false,-1, 40,1);
        tracep->declBus(c+5,"verilator_test top_instantiation divider i", false,-1, 31,0);
        tracep->declBus(c+340,"verilator_test top_instantiation divider rsig", false,-1, 31,0);
        tracep->declBus(c+172,"verilator_test top_instantiation divider pipe_ptr", false,-1, 31,0);
        tracep->declBit(c+320,"verilator_test top_instantiation divider i_aclr", false,-1);
        tracep->declBit(c+282,"verilator_test top_instantiation divider i_clock", false,-1);
        tracep->declBit(c+294,"verilator_test top_instantiation divider i_clken", false,-1);
    }
}

void Vverilator_test::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vverilator_test::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    Vverilator_test* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vverilator_test::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    Vverilator_test* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*255:0*/ __Vtemp38[8];
    WData/*95:0*/ __Vtemp39[3];
    WData/*223:0*/ __Vtemp40[7];
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->verilator_test__DOT__i),32);
        tracep->fullIData(oldp+2,(vlTOPp->verilator_test__DOT__sdram_module__DOT__i),32);
        tracep->fullQData(oldp+3,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__lpm_remainderpositive),40);
        tracep->fullIData(oldp+5,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__i),32);
        tracep->fullCData(oldp+6,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode),8);
        tracep->fullIData(oldp+7,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__i),32);
        tracep->fullCData(oldp+8,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operation),8);
        tracep->fullIData(oldp+9,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operand1),32);
        tracep->fullIData(oldp+10,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operand2),32);
        tracep->fullIData(oldp+11,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[0]),32);
        tracep->fullIData(oldp+12,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[1]),32);
        tracep->fullIData(oldp+13,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[2]),32);
        tracep->fullIData(oldp+14,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[3]),32);
        tracep->fullIData(oldp+15,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[4]),32);
        tracep->fullIData(oldp+16,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[5]),32);
        tracep->fullIData(oldp+17,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[6]),32);
        tracep->fullIData(oldp+18,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[7]),32);
        tracep->fullIData(oldp+19,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[8]),32);
        tracep->fullIData(oldp+20,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[9]),32);
        tracep->fullIData(oldp+21,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[0]),32);
        tracep->fullIData(oldp+22,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[1]),32);
        tracep->fullIData(oldp+23,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[2]),32);
        tracep->fullIData(oldp+24,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[3]),32);
        tracep->fullIData(oldp+25,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[4]),32);
        tracep->fullIData(oldp+26,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[5]),32);
        tracep->fullIData(oldp+27,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[6]),32);
        tracep->fullIData(oldp+28,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[7]),32);
        tracep->fullIData(oldp+29,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[8]),32);
        tracep->fullIData(oldp+30,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[9]),32);
        tracep->fullIData(oldp+31,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__code_section_start_address),32);
        tracep->fullIData(oldp+32,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_end_address),32);
        tracep->fullIData(oldp+33,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__temp_address),32);
        tracep->fullIData(oldp+34,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[0]),32);
        tracep->fullIData(oldp+35,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[1]),32);
        tracep->fullIData(oldp+36,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[2]),32);
        tracep->fullIData(oldp+37,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[3]),32);
        tracep->fullIData(oldp+38,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[4]),32);
        tracep->fullIData(oldp+39,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[5]),32);
        tracep->fullIData(oldp+40,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[6]),32);
        tracep->fullIData(oldp+41,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[7]),32);
        tracep->fullIData(oldp+42,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in),32);
        tracep->fullBit(oldp+43,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write));
        tracep->fullBit(oldp+44,(((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+45,(((0xaU == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullIData(oldp+46,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out),32);
        tracep->fullBit(oldp+47,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read));
        tracep->fullCData(oldp+48,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state),2);
        tracep->fullIData(oldp+49,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in),32);
        tracep->fullBit(oldp+50,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write));
        tracep->fullIData(oldp+51,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out),32);
        tracep->fullBit(oldp+52,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read));
        tracep->fullBit(oldp+53,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready));
        tracep->fullCData(oldp+54,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out),8);
        tracep->fullBit(oldp+55,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read));
        tracep->fullBit(oldp+56,(((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+57,(((5U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullCData(oldp+58,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state),3);
        tracep->fullSData(oldp+59,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access),14);
        tracep->fullBit(oldp+60,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_write_enable));
        tracep->fullCData(oldp+61,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write),8);
        tracep->fullCData(oldp+62,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_character_read),8);
        tracep->fullBit(oldp+63,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_access_state));
        tracep->fullIData(oldp+64,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_address),32);
        tracep->fullCData(oldp+65,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_byte),8);
        tracep->fullBit(oldp+66,((0x17f1U == vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_address)));
        tracep->fullBit(oldp+67,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_read_state));
        tracep->fullIData(oldp+68,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i),22);
        tracep->fullCData(oldp+69,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i),2);
        tracep->fullBit(oldp+70,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_cs_i));
        tracep->fullSData(oldp+71,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i),16);
        tracep->fullBit(oldp+72,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i));
        tracep->fullBit(oldp+73,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i));
        tracep->fullCData(oldp+74,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_write_state),8);
        tracep->fullBit(oldp+75,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_write_complete));
        tracep->fullCData(oldp+76,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_read_state),8);
        tracep->fullBit(oldp+77,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_read_complete));
        tracep->fullSData(oldp+78,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_read_data),16);
        tracep->fullCData(oldp+79,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter),8);
        tracep->fullCData(oldp+80,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operand_byte_index),8);
        tracep->fullCData(oldp+81,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__state),8);
        tracep->fullCData(oldp+82,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__division_delay_counter),5);
        tracep->fullIData(oldp+83,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider_numerator),32);
        tracep->fullIData(oldp+84,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider_denominator),32);
        tracep->fullIData(oldp+85,(((0x10U >= (0x1fU 
                                               & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                     ? vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe
                                    [(0x1fU & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                     : 0U)),32);
        tracep->fullIData(oldp+86,(((0x10U >= (0x1fU 
                                               & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                     ? vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe
                                    [(0x1fU & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                     : 0U)),32);
        tracep->fullCData(oldp+87,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer),4);
        tracep->fullCData(oldp+88,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer),4);
        tracep->fullIData(oldp+89,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[0]),32);
        tracep->fullIData(oldp+90,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[1]),32);
        tracep->fullIData(oldp+91,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[2]),32);
        tracep->fullIData(oldp+92,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[3]),32);
        tracep->fullIData(oldp+93,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[4]),32);
        tracep->fullIData(oldp+94,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[5]),32);
        tracep->fullIData(oldp+95,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[6]),32);
        tracep->fullIData(oldp+96,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[7]),32);
        tracep->fullIData(oldp+97,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[8]),32);
        tracep->fullIData(oldp+98,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[9]),32);
        tracep->fullCData(oldp+99,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size),4);
        tracep->fullIData(oldp+100,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__i),32);
        tracep->fullBit(oldp+101,(((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                                    ? 1U : 0U)));
        tracep->fullBit(oldp+102,(((0xaU == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                                    ? 1U : 0U)));
        tracep->fullCData(oldp+103,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer),4);
        tracep->fullCData(oldp+104,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer),4);
        tracep->fullIData(oldp+105,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[0]),32);
        tracep->fullIData(oldp+106,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[1]),32);
        tracep->fullIData(oldp+107,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[2]),32);
        tracep->fullIData(oldp+108,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[3]),32);
        tracep->fullIData(oldp+109,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[4]),32);
        tracep->fullIData(oldp+110,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[5]),32);
        tracep->fullIData(oldp+111,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[6]),32);
        tracep->fullIData(oldp+112,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[7]),32);
        tracep->fullIData(oldp+113,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[8]),32);
        tracep->fullIData(oldp+114,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[9]),32);
        tracep->fullCData(oldp+115,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size),4);
        tracep->fullIData(oldp+116,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__i),32);
        tracep->fullCData(oldp+117,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer),8);
        tracep->fullBit(oldp+118,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state));
        tracep->fullBit(oldp+119,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state));
        tracep->fullBit(oldp+120,(((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state) 
                                   & (~ (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state)))));
        tracep->fullSData(oldp+121,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register),11);
        tracep->fullCData(oldp+122,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter),4);
        tracep->fullCData(oldp+123,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer),3);
        tracep->fullCData(oldp+124,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer),3);
        tracep->fullCData(oldp+125,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[0]),8);
        tracep->fullCData(oldp+126,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[1]),8);
        tracep->fullCData(oldp+127,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[2]),8);
        tracep->fullCData(oldp+128,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[3]),8);
        tracep->fullCData(oldp+129,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[4]),8);
        tracep->fullCData(oldp+130,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size),3);
        tracep->fullIData(oldp+131,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__i),32);
        tracep->fullIData(oldp+132,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[0]),32);
        tracep->fullIData(oldp+133,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[1]),32);
        tracep->fullIData(oldp+134,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[2]),32);
        tracep->fullIData(oldp+135,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[3]),32);
        tracep->fullIData(oldp+136,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[4]),32);
        tracep->fullIData(oldp+137,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[5]),32);
        tracep->fullIData(oldp+138,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[6]),32);
        tracep->fullIData(oldp+139,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[7]),32);
        tracep->fullIData(oldp+140,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[8]),32);
        tracep->fullIData(oldp+141,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[9]),32);
        tracep->fullIData(oldp+142,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[10]),32);
        tracep->fullIData(oldp+143,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[11]),32);
        tracep->fullIData(oldp+144,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[12]),32);
        tracep->fullIData(oldp+145,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[13]),32);
        tracep->fullIData(oldp+146,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[14]),32);
        tracep->fullIData(oldp+147,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[15]),32);
        tracep->fullIData(oldp+148,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[16]),32);
        tracep->fullIData(oldp+149,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[0]),32);
        tracep->fullIData(oldp+150,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[1]),32);
        tracep->fullIData(oldp+151,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[2]),32);
        tracep->fullIData(oldp+152,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[3]),32);
        tracep->fullIData(oldp+153,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[4]),32);
        tracep->fullIData(oldp+154,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[5]),32);
        tracep->fullIData(oldp+155,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[6]),32);
        tracep->fullIData(oldp+156,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[7]),32);
        tracep->fullIData(oldp+157,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[8]),32);
        tracep->fullIData(oldp+158,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[9]),32);
        tracep->fullIData(oldp+159,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[10]),32);
        tracep->fullIData(oldp+160,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[11]),32);
        tracep->fullIData(oldp+161,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[12]),32);
        tracep->fullIData(oldp+162,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[13]),32);
        tracep->fullIData(oldp+163,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[14]),32);
        tracep->fullIData(oldp+164,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[15]),32);
        tracep->fullIData(oldp+165,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[16]),32);
        tracep->fullIData(oldp+166,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient),32);
        tracep->fullIData(oldp+167,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain),32);
        tracep->fullIData(oldp+168,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer),32);
        tracep->fullIData(oldp+169,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q),32);
        tracep->fullIData(oldp+170,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom),32);
        tracep->fullIData(oldp+171,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r),32);
        tracep->fullIData(oldp+172,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr),32);
        tracep->fullCData(oldp+173,(vlTOPp->verilator_test__DOT__VGA_R),4);
        tracep->fullCData(oldp+174,(vlTOPp->verilator_test__DOT__VGA_G),4);
        tracep->fullCData(oldp+175,(vlTOPp->verilator_test__DOT__VGA_B),4);
        tracep->fullCData(oldp+176,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character),8);
        tracep->fullBit(oldp+177,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value));
        tracep->fullSData(oldp+178,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o),16);
        tracep->fullBit(oldp+179,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o));
        tracep->fullCData(oldp+180,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid),3);
        tracep->fullBit(oldp+181,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__za_cannotrefresh));
        tracep->fullBit(oldp+182,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address));
        tracep->fullBit(oldp+183,((1U & (~ ((0x58U 
                                             <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                            & (0x84U 
                                               > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))))));
        tracep->fullBit(oldp+184,((1U & (~ ((0x43cU 
                                             <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                            & (0x441U 
                                               > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
        tracep->fullBit(oldp+185,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking));
        tracep->fullSData(oldp+186,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x),12);
        tracep->fullSData(oldp+187,(((0x438U <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count))
                                      ? 0x437U : (0x7ffU 
                                                  & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))),11);
        tracep->fullCData(oldp+188,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x),3);
        tracep->fullCData(oldp+189,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y),4);
        tracep->fullSData(oldp+190,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell),14);
        tracep->fullCData(oldp+191,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column),8);
        tracep->fullBit(oldp+192,((1U & (~ ((0x118U 
                                             > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                            | (0x437U 
                                               < (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
        tracep->fullBit(oldp+193,(((0x464U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                   & (0x898U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))));
        tracep->fullBit(oldp+194,(((0x437U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                   & (0x898U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))));
        tracep->fullSData(oldp+195,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count),13);
        tracep->fullSData(oldp+196,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count),12);
        tracep->fullSData(oldp+197,(vlTOPp->verilator_test__DOT__sdram_module__DOT__addr_crb),14);
        tracep->fullCData(oldp+198,((7U & ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                           - (IData)(1U)))),3);
        tracep->fullCData(oldp+199,(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency),3);
        tracep->fullCData(oldp+200,(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_mask),2);
        tracep->fullIData(oldp+201,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0),22);
        tracep->fullIData(oldp+202,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1),22);
        tracep->fullIData(oldp+203,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2),22);
        tracep->fullCData(oldp+204,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0),2);
        tracep->fullCData(oldp+205,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1),2);
        tracep->fullCData(oldp+206,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_2),2);
        tracep->fullCData(oldp+207,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe),3);
        tracep->fullIData(oldp+208,(((0U == (7U & ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                                   - (IData)(1U))))
                                      ? vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0
                                      : ((1U == (7U 
                                                 & ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                                    - (IData)(1U))))
                                          ? vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1
                                          : vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2))),22);
        tracep->fullBit(oldp+209,(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_valid));
        tracep->fullQData(oldp+210,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0),41);
        tracep->fullQData(oldp+212,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1),41);
        tracep->fullSData(oldp+214,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr),12);
        tracep->fullBit(oldp+215,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
        tracep->fullBit(oldp+216,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                                         >> 1U))));
        tracep->fullBit(oldp+217,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                         >> 1U))));
        tracep->fullBit(oldp+218,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                         >> 3U))));
        tracep->fullSData(oldp+219,(vlTOPp->verilator_test__DOT__DRAM_DQ),16);
        tracep->fullBit(oldp+220,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))));
        tracep->fullBit(oldp+221,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm) 
                                         >> 1U))));
        tracep->fullBit(oldp+222,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                         >> 2U))));
        tracep->fullBit(oldp+223,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))));
        tracep->fullCData(oldp+224,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank),2);
        tracep->fullCData(oldp+225,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm),2);
        tracep->fullIData(oldp+226,(vlTOPp->verilator_test__DOT__sdram_module__DOT__CODE),24);
        tracep->fullCData(oldp+227,((0xffU & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr))),8);
        tracep->fullCData(oldp+228,((7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))),3);
        tracep->fullSData(oldp+229,(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_data),16);
        tracep->fullSData(oldp+230,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rmw_temp),16);
        tracep->fullIData(oldp+231,(vlTOPp->verilator_test__DOT__sdram_module__DOT__test_addr),22);
        tracep->fullIData(oldp+232,(((0U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                      ? 0x4c4d52U : 
                                     ((1U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                       ? 0x415246U : 
                                      ((2U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                        ? 0x505245U
                                        : ((3U == (7U 
                                                   & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x414354U
                                            : ((4U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x205752U
                                                : (
                                                   (5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x205244U
                                                    : 
                                                   ((6U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x425354U
                                                     : 
                                                    ((7U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x4e4f50U
                                                      : 0x424144U))))))))),24);
        tracep->fullBit(oldp+233,((0x205752U == vlTOPp->verilator_test__DOT__sdram_module__DOT__CODE)));
        tracep->fullBit(oldp+234,((2U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+235,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done));
        tracep->fullIData(oldp+236,(((0xfU == (7U | (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                      ? 0x494e48U : 
                                     ((0U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                       ? 0x4c4d52U : 
                                      ((1U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                        ? 0x415246U
                                        : ((2U == (7U 
                                                   & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x505245U
                                            : ((3U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x414354U
                                                : (
                                                   (4U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x205752U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x205244U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x425354U
                                                      : 
                                                     ((7U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                       ? 0x4e4f50U
                                                       : 0x424144U)))))))))),24);
        tracep->fullBit(oldp+237,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request));
        tracep->fullIData(oldp+238,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr),22);
        tracep->fullCData(oldp+239,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank),2);
        tracep->fullBit(oldp+240,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n));
        tracep->fullSData(oldp+241,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data),16);
        tracep->fullCData(oldp+242,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm),2);
        tracep->fullBit(oldp+243,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw));
        tracep->fullBit(oldp+244,((1U >= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+245,((1U <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+246,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match));
        tracep->fullCData(oldp+247,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr),8);
        tracep->fullCData(oldp+248,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd),4);
        tracep->fullCData(oldp+249,((7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))),3);
        tracep->fullBit(oldp+250,(((~ (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)) 
                                   & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n))));
        tracep->fullBit(oldp+251,((1U & (~ (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)))));
        tracep->fullIData(oldp+252,((0x3fffffU & (IData)(
                                                         (vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                          >> 0x12U)))),22);
        tracep->fullCData(oldp+253,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank),2);
        tracep->fullSData(oldp+254,((0xffffU & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data))),16);
        tracep->fullCData(oldp+255,((3U & (IData)((vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                   >> 0x10U)))),2);
        tracep->fullBit(oldp+256,((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+257,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop));
        tracep->fullBit(oldp+258,((1U & (IData)((vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x28U)))));
        tracep->fullBit(oldp+259,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select));
        tracep->fullQData(oldp+260,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data),41);
        tracep->fullSData(oldp+262,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr),12);
        tracep->fullCData(oldp+263,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd),4);
        tracep->fullCData(oldp+264,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count),3);
        tracep->fullCData(oldp+265,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next),3);
        tracep->fullCData(oldp+266,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs),3);
        tracep->fullCData(oldp+267,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state),3);
        tracep->fullCData(oldp+268,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count),3);
        tracep->fullSData(oldp+269,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data),16);
        tracep->fullSData(oldp+270,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next),9);
        tracep->fullSData(oldp+271,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state),9);
        tracep->fullBit(oldp+272,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe));
        tracep->fullBit(oldp+273,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending));
        tracep->fullBit(oldp+274,((5U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))));
        tracep->fullSData(oldp+275,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter),13);
        tracep->fullBit(oldp+276,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request));
        tracep->fullBit(oldp+277,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match));
        tracep->fullBit(oldp+278,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match));
        tracep->fullIData(oldp+279,(((0U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                      ? 0x4c4d52U : 
                                     ((1U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                       ? 0x415246U : 
                                      ((2U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                        ? 0x505245U
                                        : ((3U == (7U 
                                                   & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x414354U
                                            : ((4U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x205752U
                                                : (
                                                   (5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x205244U
                                                    : 
                                                   ((6U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x425354U
                                                     : 
                                                    ((7U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x4e4f50U
                                                      : 0x424144U))))))))),24);
        tracep->fullCData(oldp+280,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries),2);
        tracep->fullBit(oldp+281,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address));
        tracep->fullBit(oldp+282,(vlTOPp->clk));
        tracep->fullBit(oldp+283,(vlTOPp->reset_n));
        tracep->fullBit(oldp+284,(vlTOPp->verilator_only_dram_clk));
        tracep->fullBit(oldp+285,(vlTOPp->verilator_only_vga_pixel_clock));
        tracep->fullIData(oldp+286,(((0x205752U == vlTOPp->verilator_test__DOT__sdram_module__DOT__CODE)
                                      ? vlTOPp->verilator_test__DOT__sdram_module__DOT__test_addr
                                      : ((0U == (7U 
                                                 & ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                                    - (IData)(1U))))
                                          ? vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0
                                          : ((1U == 
                                              (7U & 
                                               ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                                - (IData)(1U))))
                                              ? vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1
                                              : vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2)))),22);
        tracep->fullSData(oldp+287,((((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_temp__out1) 
                                      & ((1U & (IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_mask))
                                          ? 0U : 0xffU)) 
                                     | ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_temp__out2) 
                                        & (((2U & (IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_mask))
                                             ? 0U : 0xffU) 
                                           << 8U)))),16);
        tracep->fullCData(oldp+288,(vlTOPp->reset_n),4);
        tracep->fullBit(oldp+289,((1U & (~ (IData)(vlTOPp->reset_n)))));
        tracep->fullBit(oldp+290,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr));
        tracep->fullQData(oldp+291,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data),41);
        tracep->fullCData(oldp+293,((((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) 
                                      << 1U) | (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr))),2);
        tracep->fullBit(oldp+294,(1U));
        __Vtemp38[0U] = 0x2e646174U;
        __Vtemp38[1U] = 0x64756c65U;
        __Vtemp38[2U] = 0x725f6d6fU;
        __Vtemp38[3U] = 0x72746e65U;
        __Vtemp38[4U] = 0x6d5f7061U;
        __Vtemp38[5U] = 0x73647261U;
        __Vtemp38[6U] = 0x6572615fU;
        __Vtemp38[7U] = 0x616c74U;
        tracep->fullWData(oldp+295,(__Vtemp38),248);
        tracep->fullQData(oldp+303,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__GPIO_0),36);
        tracep->fullCData(oldp+305,(0U),8);
        tracep->fullCData(oldp+306,(1U),8);
        tracep->fullCData(oldp+307,(2U),8);
        tracep->fullIData(oldp+308,(0x20U),32);
        tracep->fullIData(oldp+309,(0xaU),32);
        tracep->fullIData(oldp+310,(8U),32);
        tracep->fullIData(oldp+311,(5U),32);
        tracep->fullIData(oldp+312,(0x58U),32);
        tracep->fullIData(oldp+313,(0x84U),32);
        tracep->fullIData(oldp+314,(0x118U),32);
        tracep->fullIData(oldp+315,(0x43cU),32);
        tracep->fullIData(oldp+316,(0x441U),32);
        tracep->fullIData(oldp+317,(0x438U),32);
        tracep->fullIData(oldp+318,(0x898U),32);
        tracep->fullIData(oldp+319,(0x465U),32);
        tracep->fullBit(oldp+320,(0U));
        tracep->fullQData(oldp+321,(0x554e5349474e4544ULL),64);
        tracep->fullIData(oldp+323,(0xfU),32);
        __Vtemp39[0U] = 0x76696465U;
        __Vtemp39[1U] = 0x6d5f6469U;
        __Vtemp39[2U] = 0x6c70U;
        tracep->fullWData(oldp+324,(__Vtemp39),80);
        __Vtemp40[0U] = 0x54525545U;
        __Vtemp40[1U] = 0x4956453dU;
        __Vtemp40[2U] = 0x4f534954U;
        __Vtemp40[3U] = 0x44455250U;
        __Vtemp40[4U] = 0x4d41494eU;
        __Vtemp40[5U] = 0x4d5f5245U;
        __Vtemp40[6U] = 0x4c50U;
        tracep->fullWData(oldp+327,(__Vtemp40),208);
        tracep->fullBit(oldp+334,(0U));
        tracep->fullBit(oldp+335,(1U));
        tracep->fullIData(oldp+336,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__not_numer),32);
        tracep->fullIData(oldp+337,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__int_numer),32);
        tracep->fullIData(oldp+338,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__not_denom),32);
        tracep->fullIData(oldp+339,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__int_denom),32);
        tracep->fullIData(oldp+340,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__rsig),32);
    }
}
