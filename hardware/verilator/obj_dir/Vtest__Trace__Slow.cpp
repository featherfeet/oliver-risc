// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtest__Syms.h"


//======================

void Vtest::_traceDump() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumperp->dump(VL_TIME_Q());
}
void Vtest::_traceDumpOpen() {
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
void Vtest::_traceDumpClose() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumping = false;
    VL_DO_CLEAR(delete __VlSymsp->__Vm_dumperp, __VlSymsp->__Vm_dumperp = nullptr);
}
void Vtest::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtest::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtest__Syms* __restrict vlSymsp = static_cast<Vtest__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtest::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtest::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtest__Syms* __restrict vlSymsp = static_cast<Vtest__Syms*>(userp);
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtest::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtest__Syms* __restrict vlSymsp = static_cast<Vtest__Syms*>(userp);
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+282,"clk", false,-1);
        tracep->declBit(c+283,"reset", false,-1);
        tracep->declBit(c+284,"dram_clk_supplied", false,-1);
        tracep->declBit(c+285,"vga_clk_supplied", false,-1);
        tracep->declBit(c+282,"test clk", false,-1);
        tracep->declBit(c+283,"test reset", false,-1);
        tracep->declBit(c+284,"test dram_clk_supplied", false,-1);
        tracep->declBit(c+285,"test vga_clk_supplied", false,-1);
        tracep->declBus(c+296,"test dots_per_line", false,-1, 31,0);
        tracep->declBus(c+297,"test lines_per_frame", false,-1, 31,0);
        tracep->declBus(c+1,"test i", false,-1, 31,0);
        tracep->declBit(c+2,"test PS2_CLK", false,-1);
        tracep->declBit(c+298,"test PS2_DAT", false,-1);
        tracep->declBit(c+284,"test SDRAM_CLK", false,-1);
        tracep->declBus(c+214,"test DRAM_ADDR", false,-1, 11,0);
        tracep->declBit(c+215,"test DRAM_BA_0", false,-1);
        tracep->declBit(c+216,"test DRAM_BA_1", false,-1);
        tracep->declBit(c+217,"test DRAM_CAS_N", false,-1);
        tracep->declBit(c+298,"test DRAM_CKE", false,-1);
        tracep->declBit(c+218,"test DRAM_CS_N", false,-1);
        tracep->declBus(c+219,"test DRAM_DQ", false,-1, 15,0);
        tracep->declBit(c+220,"test DRAM_LDQM", false,-1);
        tracep->declBit(c+221,"test DRAM_UDQM", false,-1);
        tracep->declBit(c+222,"test DRAM_RAS_N", false,-1);
        tracep->declBit(c+223,"test DRAM_WE_N", false,-1);
        tracep->declBus(c+168,"test VGA_R", false,-1, 3,0);
        tracep->declBus(c+169,"test VGA_G", false,-1, 3,0);
        tracep->declBus(c+170,"test VGA_B", false,-1, 3,0);
        tracep->declBit(c+178,"test VGA_HS", false,-1);
        tracep->declBit(c+179,"test VGA_VS", false,-1);
        tracep->declBit(c+285,"test VGA_PIXEL_CLOCK", false,-1);
        tracep->declArray(c+299,"test sdram_module INIT_FILE", false,-1, 247,0);
        tracep->declBus(c+219,"test sdram_module zs_dq", false,-1, 15,0);
        tracep->declBit(c+284,"test sdram_module clk", false,-1);
        tracep->declBus(c+214,"test sdram_module zs_addr", false,-1, 11,0);
        tracep->declBus(c+224,"test sdram_module zs_ba", false,-1, 1,0);
        tracep->declBit(c+217,"test sdram_module zs_cas_n", false,-1);
        tracep->declBit(c+298,"test sdram_module zs_cke", false,-1);
        tracep->declBit(c+218,"test sdram_module zs_cs_n", false,-1);
        tracep->declBus(c+225,"test sdram_module zs_dqm", false,-1, 1,0);
        tracep->declBit(c+222,"test sdram_module zs_ras_n", false,-1);
        tracep->declBit(c+223,"test sdram_module zs_we_n", false,-1);
        tracep->declBus(c+226,"test sdram_module CODE", false,-1, 23,0);
        tracep->declBus(c+214,"test sdram_module a", false,-1, 11,0);
        tracep->declBus(c+227,"test sdram_module addr_col", false,-1, 7,0);
        tracep->declBus(c+192,"test sdram_module addr_crb", false,-1, 13,0);
        tracep->declBus(c+224,"test sdram_module ba", false,-1, 1,0);
        tracep->declBit(c+217,"test sdram_module cas_n", false,-1);
        tracep->declBit(c+298,"test sdram_module cke", false,-1);
        tracep->declBus(c+228,"test sdram_module cmd_code", false,-1, 2,0);
        tracep->declBit(c+218,"test sdram_module cs_n", false,-1);
        tracep->declBus(c+225,"test sdram_module dqm", false,-1, 1,0);
        tracep->declBus(c+193,"test sdram_module index", false,-1, 2,0);
        tracep->declBus(c+194,"test sdram_module latency", false,-1, 2,0);
        tracep->declBus(c+195,"test sdram_module mask", false,-1, 1,0);
        tracep->declBus(c+229,"test sdram_module mem_bytes", false,-1, 15,0);
        tracep->declBit(c+222,"test sdram_module ras_n", false,-1);
        tracep->declBus(c+196,"test sdram_module rd_addr_pipe_0", false,-1, 21,0);
        tracep->declBus(c+197,"test sdram_module rd_addr_pipe_1", false,-1, 21,0);
        tracep->declBus(c+198,"test sdram_module rd_addr_pipe_2", false,-1, 21,0);
        tracep->declBus(c+199,"test sdram_module rd_mask_pipe_0", false,-1, 1,0);
        tracep->declBus(c+200,"test sdram_module rd_mask_pipe_1", false,-1, 1,0);
        tracep->declBus(c+201,"test sdram_module rd_mask_pipe_2", false,-1, 1,0);
        tracep->declBus(c+202,"test sdram_module rd_valid_pipe", false,-1, 2,0);
        tracep->declBus(c+286,"test sdram_module rdaddress", false,-1, 21,0);
        tracep->declBus(c+203,"test sdram_module read_addr", false,-1, 21,0);
        tracep->declBus(c+286,"test sdram_module read_address", false,-1, 21,0);
        tracep->declBus(c+229,"test sdram_module read_data", false,-1, 15,0);
        tracep->declBus(c+195,"test sdram_module read_mask", false,-1, 1,0);
        tracep->declBus(c+287,"test sdram_module read_temp", false,-1, 15,0);
        tracep->declBit(c+204,"test sdram_module read_valid", false,-1);
        tracep->declBus(c+230,"test sdram_module rmw_temp", false,-1, 15,0);
        tracep->declBus(c+231,"test sdram_module test_addr", false,-1, 21,0);
        tracep->declBus(c+232,"test sdram_module txt_code", false,-1, 23,0);
        tracep->declBit(c+223,"test sdram_module we_n", false,-1);
        tracep->declBit(c+233,"test sdram_module wren", false,-1);
        tracep->declBus(c+3,"test sdram_module i", false,-1, 31,0);
        tracep->declBit(c+284,"test top_instantiation dram_clk_supplied", false,-1);
        tracep->declBit(c+285,"test top_instantiation vga_clk_supplied", false,-1);
        tracep->declBus(c+288,"test top_instantiation KEY", false,-1, 3,0);
        tracep->declBit(c+282,"test top_instantiation CLOCK_50", false,-1);
        tracep->declBit(c+284,"test top_instantiation DRAM_CLK", false,-1);
        tracep->declBus(c+214,"test top_instantiation DRAM_ADDR", false,-1, 11,0);
        tracep->declBit(c+215,"test top_instantiation DRAM_BA_0", false,-1);
        tracep->declBit(c+216,"test top_instantiation DRAM_BA_1", false,-1);
        tracep->declBit(c+217,"test top_instantiation DRAM_CAS_N", false,-1);
        tracep->declBit(c+298,"test top_instantiation DRAM_CKE", false,-1);
        tracep->declBit(c+218,"test top_instantiation DRAM_CS_N", false,-1);
        tracep->declBit(c+220,"test top_instantiation DRAM_LDQM", false,-1);
        tracep->declBit(c+221,"test top_instantiation DRAM_UDQM", false,-1);
        tracep->declBit(c+222,"test top_instantiation DRAM_RAS_N", false,-1);
        tracep->declBit(c+223,"test top_instantiation DRAM_WE_N", false,-1);
        tracep->declBus(c+219,"test top_instantiation DRAM_DQ", false,-1, 15,0);
        tracep->declBus(c+168,"test top_instantiation VGA_R", false,-1, 3,0);
        tracep->declBus(c+169,"test top_instantiation VGA_G", false,-1, 3,0);
        tracep->declBus(c+170,"test top_instantiation VGA_B", false,-1, 3,0);
        tracep->declBit(c+178,"test top_instantiation VGA_HS", false,-1);
        tracep->declBit(c+179,"test top_instantiation VGA_VS", false,-1);
        tracep->declBit(c+285,"test top_instantiation VGA_PIXEL_CLOCK", false,-1);
        tracep->declBit(c+2,"test top_instantiation PS2_CLK", false,-1);
        tracep->declBit(c+298,"test top_instantiation PS2_DAT", false,-1);
        tracep->declBus(c+209,"test top_instantiation LEDG", false,-1, 7,0);
        tracep->declQuad(c+7,"test top_instantiation GPIO_0", false,-1, 35,0);
        tracep->declBus(c+9,"test top_instantiation i", false,-1, 31,0);
        tracep->declBus(c+10,"test top_instantiation operation", false,-1, 7,0);
        tracep->declBus(c+11,"test top_instantiation operand1", false,-1, 31,0);
        tracep->declBus(c+12,"test top_instantiation operand2", false,-1, 31,0);
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+13+i*1,"test top_instantiation registers", true,(i+0), 31,0);}}
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+23+i*1,"test top_instantiation shadow_registers", true,(i+0), 31,0);}}
        tracep->declBus(c+33,"test top_instantiation code_section_start_address", false,-1, 31,0);
        tracep->declBus(c+34,"test top_instantiation program_end_address", false,-1, 31,0);
        tracep->declBus(c+35,"test top_instantiation temp_address", false,-1, 31,0);
        {int i; for (i=0; i<8; i++) {
                tracep->declBus(c+36+i*1,"test top_instantiation interrupt_vector_table", true,(i+0), 31,0);}}
        tracep->declBus(c+44,"test top_instantiation interrupt_fifo_data_in", false,-1, 31,0);
        tracep->declBit(c+45,"test top_instantiation interrupt_fifo_write", false,-1);
        tracep->declBit(c+46,"test top_instantiation interrupt_fifo_empty", false,-1);
        tracep->declBit(c+47,"test top_instantiation interrupt_fifo_full", false,-1);
        tracep->declBus(c+48,"test top_instantiation interrupt_fifo_data_out", false,-1, 31,0);
        tracep->declBit(c+49,"test top_instantiation interrupt_fifo_read", false,-1);
        tracep->declBus(c+50,"test top_instantiation interrupt_fifo_access_state", false,-1, 1,0);
        tracep->declBus(c+51,"test top_instantiation interrupt_value_fifo_data_in", false,-1, 31,0);
        tracep->declBit(c+52,"test top_instantiation interrupt_value_fifo_write", false,-1);
        tracep->declBus(c+53,"test top_instantiation interrupt_value_fifo_data_out", false,-1, 31,0);
        tracep->declBit(c+54,"test top_instantiation interrupt_value_fifo_read", false,-1);
        tracep->declBus(c+209,"test top_instantiation keyboard_scancode", false,-1, 7,0);
        tracep->declBit(c+289,"test top_instantiation keyboard_scancode_ready", false,-1);
        tracep->declBus(c+55,"test top_instantiation keyboard_scancode_fifo_data_out", false,-1, 7,0);
        tracep->declBit(c+56,"test top_instantiation keyboard_scancode_fifo_read", false,-1);
        tracep->declBit(c+57,"test top_instantiation keyboard_scancode_fifo_empty", false,-1);
        tracep->declBit(c+58,"test top_instantiation keyboard_scancode_fifo_full", false,-1);
        tracep->declBus(c+59,"test top_instantiation keyboard_scancode_fifo_access_state", false,-1, 2,0);
        tracep->declBus(c+60,"test top_instantiation gpu_cell_to_access", false,-1, 13,0);
        tracep->declBit(c+61,"test top_instantiation gpu_write_enable", false,-1);
        tracep->declBus(c+62,"test top_instantiation gpu_character_to_write", false,-1, 7,0);
        tracep->declBus(c+63,"test top_instantiation gpu_character_read", false,-1, 7,0);
        tracep->declBit(c+64,"test top_instantiation gpu_access_state", false,-1);
        tracep->declBus(c+65,"test top_instantiation program_rom_address", false,-1, 31,0);
        tracep->declBus(c+66,"test top_instantiation program_rom_byte", false,-1, 7,0);
        tracep->declBit(c+67,"test top_instantiation program_rom_done", false,-1);
        tracep->declBit(c+68,"test top_instantiation program_rom_read_state", false,-1);
        tracep->declBus(c+69,"test top_instantiation sdram_controller_address_i", false,-1, 21,0);
        tracep->declBus(c+70,"test top_instantiation sdram_controller_be_n_i", false,-1, 1,0);
        tracep->declBit(c+71,"test top_instantiation sdram_controller_cs_i", false,-1);
        tracep->declBus(c+72,"test top_instantiation sdram_controller_data_i", false,-1, 15,0);
        tracep->declBit(c+73,"test top_instantiation sdram_controller_rd_n_i", false,-1);
        tracep->declBit(c+74,"test top_instantiation sdram_controller_wr_n_i", false,-1);
        tracep->declBus(c+173,"test top_instantiation sdram_controller_data_o", false,-1, 15,0);
        tracep->declBit(c+174,"test top_instantiation sdram_controller_valid_o", false,-1);
        tracep->declBit(c+234,"test top_instantiation sdram_controller_waitrequest_o", false,-1);
        tracep->declBit(c+235,"test top_instantiation sdram_controller_init_done", false,-1);
        tracep->declBus(c+75,"test top_instantiation ram_write_state", false,-1, 7,0);
        tracep->declBus(c+307,"test top_instantiation WAIT_FOR_RAM_WRITE", false,-1, 7,0);
        tracep->declBus(c+308,"test top_instantiation WRITE_TO_RAM", false,-1, 7,0);
        tracep->declBus(c+309,"test top_instantiation RAM_WRITE_DONE", false,-1, 7,0);
        tracep->declBit(c+76,"test top_instantiation ram_write_complete", false,-1);
        tracep->declBus(c+77,"test top_instantiation ram_read_state", false,-1, 7,0);
        tracep->declBus(c+307,"test top_instantiation LATCH_RAM_READ_ADDRESS", false,-1, 7,0);
        tracep->declBus(c+308,"test top_instantiation START_READ_FROM_RAM", false,-1, 7,0);
        tracep->declBus(c+309,"test top_instantiation WAIT_FOR_RAM_READ", false,-1, 7,0);
        tracep->declBit(c+78,"test top_instantiation ram_read_complete", false,-1);
        tracep->declBus(c+79,"test top_instantiation ram_read_data", false,-1, 15,0);
        tracep->declBus(c+80,"test top_instantiation ram_stabilization_counter", false,-1, 7,0);
        tracep->declBus(c+81,"test top_instantiation operand_byte_index", false,-1, 7,0);
        tracep->declBus(c+82,"test top_instantiation state", false,-1, 7,0);
        tracep->declBus(c+83,"test top_instantiation division_delay_counter", false,-1, 4,0);
        tracep->declBus(c+84,"test top_instantiation divider_numerator", false,-1, 31,0);
        tracep->declBus(c+85,"test top_instantiation divider_denominator", false,-1, 31,0);
        tracep->declBus(c+86,"test top_instantiation divider_quotient", false,-1, 31,0);
        tracep->declBus(c+87,"test top_instantiation divider_remainder", false,-1, 31,0);
        tracep->declBus(c+310,"test top_instantiation interrupt_fifo ITEM_SIZE_BITS", false,-1, 31,0);
        tracep->declBus(c+311,"test top_instantiation interrupt_fifo FIFO_SIZE", false,-1, 31,0);
        tracep->declBit(c+282,"test top_instantiation interrupt_fifo CLOCK_50", false,-1);
        tracep->declBit(c+283,"test top_instantiation interrupt_fifo RST_N", false,-1);
        tracep->declBus(c+44,"test top_instantiation interrupt_fifo data_in", false,-1, 31,0);
        tracep->declBit(c+45,"test top_instantiation interrupt_fifo write", false,-1);
        tracep->declBus(c+48,"test top_instantiation interrupt_fifo data_out", false,-1, 31,0);
        tracep->declBit(c+49,"test top_instantiation interrupt_fifo read", false,-1);
        tracep->declBit(c+46,"test top_instantiation interrupt_fifo empty", false,-1);
        tracep->declBit(c+47,"test top_instantiation interrupt_fifo full", false,-1);
        tracep->declBus(c+88,"test top_instantiation interrupt_fifo write_pointer", false,-1, 3,0);
        tracep->declBus(c+89,"test top_instantiation interrupt_fifo read_pointer", false,-1, 3,0);
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+90+i*1,"test top_instantiation interrupt_fifo items", true,(i+0), 31,0);}}
        tracep->declBus(c+100,"test top_instantiation interrupt_fifo current_fifo_size", false,-1, 3,0);
        tracep->declBus(c+101,"test top_instantiation interrupt_fifo i", false,-1, 31,0);
        tracep->declBus(c+310,"test top_instantiation interrupt_value_fifo ITEM_SIZE_BITS", false,-1, 31,0);
        tracep->declBus(c+311,"test top_instantiation interrupt_value_fifo FIFO_SIZE", false,-1, 31,0);
        tracep->declBit(c+282,"test top_instantiation interrupt_value_fifo CLOCK_50", false,-1);
        tracep->declBit(c+283,"test top_instantiation interrupt_value_fifo RST_N", false,-1);
        tracep->declBus(c+51,"test top_instantiation interrupt_value_fifo data_in", false,-1, 31,0);
        tracep->declBit(c+52,"test top_instantiation interrupt_value_fifo write", false,-1);
        tracep->declBus(c+53,"test top_instantiation interrupt_value_fifo data_out", false,-1, 31,0);
        tracep->declBit(c+54,"test top_instantiation interrupt_value_fifo read", false,-1);
        tracep->declBit(c+102,"test top_instantiation interrupt_value_fifo empty", false,-1);
        tracep->declBit(c+103,"test top_instantiation interrupt_value_fifo full", false,-1);
        tracep->declBus(c+104,"test top_instantiation interrupt_value_fifo write_pointer", false,-1, 3,0);
        tracep->declBus(c+105,"test top_instantiation interrupt_value_fifo read_pointer", false,-1, 3,0);
        {int i; for (i=0; i<10; i++) {
                tracep->declBus(c+106+i*1,"test top_instantiation interrupt_value_fifo items", true,(i+0), 31,0);}}
        tracep->declBus(c+116,"test top_instantiation interrupt_value_fifo current_fifo_size", false,-1, 3,0);
        tracep->declBus(c+117,"test top_instantiation interrupt_value_fifo i", false,-1, 31,0);
        tracep->declBit(c+282,"test top_instantiation ps2_keyboard CLOCK_50", false,-1);
        tracep->declBit(c+2,"test top_instantiation ps2_keyboard PS2_CLK", false,-1);
        tracep->declBit(c+298,"test top_instantiation ps2_keyboard PS2_DAT", false,-1);
        tracep->declBus(c+209,"test top_instantiation ps2_keyboard scancode", false,-1, 7,0);
        tracep->declBit(c+289,"test top_instantiation ps2_keyboard ready", false,-1);
        tracep->declBus(c+210,"test top_instantiation ps2_keyboard shift_register", false,-1, 10,0);
        tracep->declBus(c+211,"test top_instantiation ps2_keyboard bits_counter", false,-1, 3,0);
        tracep->declBit(c+212,"test top_instantiation ps2_keyboard done", false,-1);
        tracep->declBit(c+290,"test top_instantiation ps2_keyboard other_done", false,-1);
        tracep->declBit(c+213,"test top_instantiation ps2_keyboard bits_counter_finished", false,-1);
        tracep->declBus(c+312,"test top_instantiation keyboard_scancodes_fifo ITEM_SIZE_BITS", false,-1, 31,0);
        tracep->declBus(c+313,"test top_instantiation keyboard_scancodes_fifo FIFO_SIZE", false,-1, 31,0);
        tracep->declBit(c+282,"test top_instantiation keyboard_scancodes_fifo CLOCK_50", false,-1);
        tracep->declBit(c+283,"test top_instantiation keyboard_scancodes_fifo RST_N", false,-1);
        tracep->declBus(c+209,"test top_instantiation keyboard_scancodes_fifo data_in", false,-1, 7,0);
        tracep->declBit(c+289,"test top_instantiation keyboard_scancodes_fifo write", false,-1);
        tracep->declBus(c+55,"test top_instantiation keyboard_scancodes_fifo data_out", false,-1, 7,0);
        tracep->declBit(c+56,"test top_instantiation keyboard_scancodes_fifo read", false,-1);
        tracep->declBit(c+57,"test top_instantiation keyboard_scancodes_fifo empty", false,-1);
        tracep->declBit(c+58,"test top_instantiation keyboard_scancodes_fifo full", false,-1);
        tracep->declBus(c+118,"test top_instantiation keyboard_scancodes_fifo write_pointer", false,-1, 2,0);
        tracep->declBus(c+119,"test top_instantiation keyboard_scancodes_fifo read_pointer", false,-1, 2,0);
        {int i; for (i=0; i<5; i++) {
                tracep->declBus(c+120+i*1,"test top_instantiation keyboard_scancodes_fifo items", true,(i+0), 7,0);}}
        tracep->declBus(c+125,"test top_instantiation keyboard_scancodes_fifo current_fifo_size", false,-1, 2,0);
        tracep->declBus(c+126,"test top_instantiation keyboard_scancodes_fifo i", false,-1, 31,0);
        tracep->declBit(c+282,"test top_instantiation integrated_graphics CLOCK_50", false,-1);
        tracep->declBit(c+291,"test top_instantiation integrated_graphics reset", false,-1);
        tracep->declBit(c+285,"test top_instantiation integrated_graphics CLOCK_150", false,-1);
        tracep->declBus(c+168,"test top_instantiation integrated_graphics VGA_R", false,-1, 3,0);
        tracep->declBus(c+169,"test top_instantiation integrated_graphics VGA_G", false,-1, 3,0);
        tracep->declBus(c+170,"test top_instantiation integrated_graphics VGA_B", false,-1, 3,0);
        tracep->declBit(c+178,"test top_instantiation integrated_graphics VGA_HS", false,-1);
        tracep->declBit(c+179,"test top_instantiation integrated_graphics VGA_VS", false,-1);
        tracep->declBus(c+60,"test top_instantiation integrated_graphics cell_to_access", false,-1, 13,0);
        tracep->declBit(c+61,"test top_instantiation integrated_graphics write_enable", false,-1);
        tracep->declBus(c+62,"test top_instantiation integrated_graphics character_to_write", false,-1, 7,0);
        tracep->declBus(c+63,"test top_instantiation integrated_graphics character_read", false,-1, 7,0);
        tracep->declBit(c+180,"test top_instantiation integrated_graphics blanking", false,-1);
        tracep->declBus(c+181,"test top_instantiation integrated_graphics pixel_x", false,-1, 11,0);
        tracep->declBus(c+182,"test top_instantiation integrated_graphics pixel_y", false,-1, 10,0);
        tracep->declBus(c+183,"test top_instantiation integrated_graphics character_cell_x", false,-1, 2,0);
        tracep->declBus(c+184,"test top_instantiation integrated_graphics character_cell_y", false,-1, 3,0);
        tracep->declBus(c+185,"test top_instantiation integrated_graphics current_character_cell", false,-1, 13,0);
        tracep->declBus(c+186,"test top_instantiation integrated_graphics current_column", false,-1, 7,0);
        tracep->declBus(c+171,"test top_instantiation integrated_graphics current_character", false,-1, 7,0);
        tracep->declBit(c+172,"test top_instantiation integrated_graphics current_pixel_value", false,-1);
        tracep->declBit(c+282,"test top_instantiation integrated_graphics text_buffer port_a_clock", false,-1);
        tracep->declBit(c+285,"test top_instantiation integrated_graphics text_buffer port_b_clock", false,-1);
        tracep->declBus(c+60,"test top_instantiation integrated_graphics text_buffer port_a_address", false,-1, 13,0);
        tracep->declBus(c+185,"test top_instantiation integrated_graphics text_buffer port_b_address", false,-1, 13,0);
        tracep->declBus(c+62,"test top_instantiation integrated_graphics text_buffer port_a_data_in", false,-1, 7,0);
        tracep->declBit(c+61,"test top_instantiation integrated_graphics text_buffer port_a_write_enable", false,-1);
        tracep->declBus(c+63,"test top_instantiation integrated_graphics text_buffer port_a_data_out", false,-1, 7,0);
        tracep->declBus(c+171,"test top_instantiation integrated_graphics text_buffer port_b_data_out", false,-1, 7,0);
        tracep->declBit(c+285,"test top_instantiation integrated_graphics vga i_clk", false,-1);
        tracep->declBit(c+283,"test top_instantiation integrated_graphics vga i_rst", false,-1);
        tracep->declBit(c+178,"test top_instantiation integrated_graphics vga o_hs", false,-1);
        tracep->declBit(c+179,"test top_instantiation integrated_graphics vga o_vs", false,-1);
        tracep->declBit(c+180,"test top_instantiation integrated_graphics vga o_blanking", false,-1);
        tracep->declBit(c+187,"test top_instantiation integrated_graphics vga o_active", false,-1);
        tracep->declBit(c+188,"test top_instantiation integrated_graphics vga o_screenend", false,-1);
        tracep->declBit(c+189,"test top_instantiation integrated_graphics vga o_animate", false,-1);
        tracep->declBus(c+181,"test top_instantiation integrated_graphics vga o_x", false,-1, 11,0);
        tracep->declBus(c+182,"test top_instantiation integrated_graphics vga o_y", false,-1, 10,0);
        tracep->declBus(c+314,"test top_instantiation integrated_graphics vga HS_STA", false,-1, 31,0);
        tracep->declBus(c+315,"test top_instantiation integrated_graphics vga HS_END", false,-1, 31,0);
        tracep->declBus(c+316,"test top_instantiation integrated_graphics vga HA_STA", false,-1, 31,0);
        tracep->declBus(c+317,"test top_instantiation integrated_graphics vga VS_STA", false,-1, 31,0);
        tracep->declBus(c+318,"test top_instantiation integrated_graphics vga VS_END", false,-1, 31,0);
        tracep->declBus(c+319,"test top_instantiation integrated_graphics vga VA_END", false,-1, 31,0);
        tracep->declBus(c+296,"test top_instantiation integrated_graphics vga LINE", false,-1, 31,0);
        tracep->declBus(c+297,"test top_instantiation integrated_graphics vga SCREEN", false,-1, 31,0);
        tracep->declBus(c+190,"test top_instantiation integrated_graphics vga h_count", false,-1, 12,0);
        tracep->declBus(c+191,"test top_instantiation integrated_graphics vga v_count", false,-1, 11,0);
        tracep->declBit(c+285,"test top_instantiation integrated_graphics font_glyphs CLOCK_150", false,-1);
        tracep->declBus(c+171,"test top_instantiation integrated_graphics font_glyphs character", false,-1, 7,0);
        tracep->declBus(c+183,"test top_instantiation integrated_graphics font_glyphs character_cell_x", false,-1, 2,0);
        tracep->declBus(c+184,"test top_instantiation integrated_graphics font_glyphs character_cell_y", false,-1, 3,0);
        tracep->declBit(c+172,"test top_instantiation integrated_graphics font_glyphs pixel_value", false,-1);
        tracep->declBit(c+282,"test top_instantiation program_rom CLOCK_50", false,-1);
        tracep->declBus(c+65,"test top_instantiation program_rom address", false,-1, 31,0);
        tracep->declBus(c+66,"test top_instantiation program_rom output_byte", false,-1, 7,0);
        tracep->declBit(c+67,"test top_instantiation program_rom done", false,-1);
        tracep->declBus(c+173,"test top_instantiation sdram_controller za_data", false,-1, 15,0);
        tracep->declBit(c+174,"test top_instantiation sdram_controller za_valid", false,-1);
        tracep->declBit(c+234,"test top_instantiation sdram_controller za_waitrequest", false,-1);
        tracep->declBus(c+214,"test top_instantiation sdram_controller zs_addr", false,-1, 11,0);
        tracep->declBus(c+224,"test top_instantiation sdram_controller zs_ba", false,-1, 1,0);
        tracep->declBit(c+217,"test top_instantiation sdram_controller zs_cas_n", false,-1);
        tracep->declBit(c+298,"test top_instantiation sdram_controller zs_cke", false,-1);
        tracep->declBit(c+218,"test top_instantiation sdram_controller zs_cs_n", false,-1);
        tracep->declBus(c+219,"test top_instantiation sdram_controller zs_dq", false,-1, 15,0);
        tracep->declBus(c+225,"test top_instantiation sdram_controller zs_dqm", false,-1, 1,0);
        tracep->declBit(c+222,"test top_instantiation sdram_controller zs_ras_n", false,-1);
        tracep->declBit(c+223,"test top_instantiation sdram_controller zs_we_n", false,-1);
        tracep->declBus(c+69,"test top_instantiation sdram_controller az_addr", false,-1, 21,0);
        tracep->declBus(c+70,"test top_instantiation sdram_controller az_be_n", false,-1, 1,0);
        tracep->declBit(c+71,"test top_instantiation sdram_controller az_cs", false,-1);
        tracep->declBus(c+72,"test top_instantiation sdram_controller az_data", false,-1, 15,0);
        tracep->declBit(c+73,"test top_instantiation sdram_controller az_rd_n", false,-1);
        tracep->declBit(c+74,"test top_instantiation sdram_controller az_wr_n", false,-1);
        tracep->declBit(c+284,"test top_instantiation sdram_controller clk", false,-1);
        tracep->declBit(c+283,"test top_instantiation sdram_controller reset_n", false,-1);
        tracep->declBus(c+236,"test top_instantiation sdram_controller CODE", false,-1, 23,0);
        tracep->declBit(c+237,"test top_instantiation sdram_controller ack_refresh_request", false,-1);
        tracep->declBus(c+238,"test top_instantiation sdram_controller active_addr", false,-1, 21,0);
        tracep->declBus(c+239,"test top_instantiation sdram_controller active_bank", false,-1, 1,0);
        tracep->declBit(c+240,"test top_instantiation sdram_controller active_cs_n", false,-1);
        tracep->declBus(c+241,"test top_instantiation sdram_controller active_data", false,-1, 15,0);
        tracep->declBus(c+242,"test top_instantiation sdram_controller active_dqm", false,-1, 1,0);
        tracep->declBit(c+243,"test top_instantiation sdram_controller active_rnw", false,-1);
        tracep->declBit(c+244,"test top_instantiation sdram_controller almost_empty", false,-1);
        tracep->declBit(c+245,"test top_instantiation sdram_controller almost_full", false,-1);
        tracep->declBit(c+246,"test top_instantiation sdram_controller bank_match", false,-1);
        tracep->declBus(c+247,"test top_instantiation sdram_controller cas_addr", false,-1, 7,0);
        tracep->declBit(c+298,"test top_instantiation sdram_controller clk_en", false,-1);
        tracep->declBus(c+248,"test top_instantiation sdram_controller cmd_all", false,-1, 3,0);
        tracep->declBus(c+249,"test top_instantiation sdram_controller cmd_code", false,-1, 2,0);
        tracep->declBit(c+250,"test top_instantiation sdram_controller cs_n", false,-1);
        tracep->declBit(c+250,"test top_instantiation sdram_controller csn_decode", false,-1);
        tracep->declBit(c+251,"test top_instantiation sdram_controller csn_match", false,-1);
        tracep->declBus(c+252,"test top_instantiation sdram_controller f_addr", false,-1, 21,0);
        tracep->declBus(c+253,"test top_instantiation sdram_controller f_bank", false,-1, 1,0);
        tracep->declBit(c+320,"test top_instantiation sdram_controller f_cs_n", false,-1);
        tracep->declBus(c+254,"test top_instantiation sdram_controller f_data", false,-1, 15,0);
        tracep->declBus(c+255,"test top_instantiation sdram_controller f_dqm", false,-1, 1,0);
        tracep->declBit(c+256,"test top_instantiation sdram_controller f_empty", false,-1);
        tracep->declBit(c+257,"test top_instantiation sdram_controller f_pop", false,-1);
        tracep->declBit(c+258,"test top_instantiation sdram_controller f_rnw", false,-1);
        tracep->declBit(c+259,"test top_instantiation sdram_controller f_select", false,-1);
        tracep->declQuad(c+260,"test top_instantiation sdram_controller fifo_read_data", false,-1, 40,0);
        tracep->declBus(c+262,"test top_instantiation sdram_controller i_addr", false,-1, 11,0);
        tracep->declBus(c+263,"test top_instantiation sdram_controller i_cmd", false,-1, 3,0);
        tracep->declBus(c+264,"test top_instantiation sdram_controller i_count", false,-1, 2,0);
        tracep->declBus(c+265,"test top_instantiation sdram_controller i_next", false,-1, 2,0);
        tracep->declBus(c+266,"test top_instantiation sdram_controller i_refs", false,-1, 2,0);
        tracep->declBus(c+267,"test top_instantiation sdram_controller i_state", false,-1, 2,0);
        tracep->declBit(c+235,"test top_instantiation sdram_controller init_done", false,-1);
        tracep->declBus(c+214,"test top_instantiation sdram_controller m_addr", false,-1, 11,0);
        tracep->declBus(c+224,"test top_instantiation sdram_controller m_bank", false,-1, 1,0);
        tracep->declBus(c+248,"test top_instantiation sdram_controller m_cmd", false,-1, 3,0);
        tracep->declBus(c+268,"test top_instantiation sdram_controller m_count", false,-1, 2,0);
        tracep->declBus(c+269,"test top_instantiation sdram_controller m_data", false,-1, 15,0);
        tracep->declBus(c+225,"test top_instantiation sdram_controller m_dqm", false,-1, 1,0);
        tracep->declBus(c+270,"test top_instantiation sdram_controller m_next", false,-1, 8,0);
        tracep->declBus(c+271,"test top_instantiation sdram_controller m_state", false,-1, 8,0);
        tracep->declBit(c+272,"test top_instantiation sdram_controller oe", false,-1);
        tracep->declBit(c+273,"test top_instantiation sdram_controller pending", false,-1);
        tracep->declBit(c+274,"test top_instantiation sdram_controller rd_strobe", false,-1);
        tracep->declBus(c+175,"test top_instantiation sdram_controller rd_valid", false,-1, 2,0);
        tracep->declBus(c+275,"test top_instantiation sdram_controller refresh_counter", false,-1, 12,0);
        tracep->declBit(c+276,"test top_instantiation sdram_controller refresh_request", false,-1);
        tracep->declBit(c+277,"test top_instantiation sdram_controller rnw_match", false,-1);
        tracep->declBit(c+278,"test top_instantiation sdram_controller row_match", false,-1);
        tracep->declBus(c+279,"test top_instantiation sdram_controller txt_code", false,-1, 23,0);
        tracep->declBit(c+176,"test top_instantiation sdram_controller za_cannotrefresh", false,-1);
        tracep->declBit(c+244,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module almost_empty", false,-1);
        tracep->declBit(c+245,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module almost_full", false,-1);
        tracep->declBit(c+256,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module empty", false,-1);
        tracep->declBit(c+234,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module full", false,-1);
        tracep->declQuad(c+260,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rd_data", false,-1, 40,0);
        tracep->declBit(c+284,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module clk", false,-1);
        tracep->declBit(c+259,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rd", false,-1);
        tracep->declBit(c+283,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module reset_n", false,-1);
        tracep->declBit(c+292,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module wr", false,-1);
        tracep->declQuad(c+293,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module wr_data", false,-1, 40,0);
        tracep->declBus(c+280,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module entries", false,-1, 1,0);
        tracep->declQuad(c+205,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module entry_0", false,-1, 40,0);
        tracep->declQuad(c+207,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module entry_1", false,-1, 40,0);
        tracep->declBit(c+177,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rd_address", false,-1);
        tracep->declBus(c+295,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module rdwr", false,-1, 1,0);
        tracep->declBit(c+281,"test top_instantiation sdram_controller the_sdram_system_new_sdram_controller_0_input_efifo_module wr_address", false,-1);
        tracep->declBus(c+310,"test top_instantiation divider lpm_widthn", false,-1, 31,0);
        tracep->declBus(c+310,"test top_instantiation divider lpm_widthd", false,-1, 31,0);
        tracep->declQuad(c+321,"test top_instantiation divider lpm_nrepresentation", false,-1, 63,0);
        tracep->declQuad(c+321,"test top_instantiation divider lpm_drepresentation", false,-1, 63,0);
        tracep->declBus(c+323,"test top_instantiation divider lpm_pipeline", false,-1, 31,0);
        tracep->declArray(c+324,"test top_instantiation divider lpm_type", false,-1, 79,0);
        tracep->declArray(c+327,"test top_instantiation divider lpm_hint", false,-1, 207,0);
        tracep->declBus(c+84,"test top_instantiation divider numer", false,-1, 31,0);
        tracep->declBus(c+85,"test top_instantiation divider denom", false,-1, 31,0);
        tracep->declBit(c+282,"test top_instantiation divider clock", false,-1);
        tracep->declBit(c+334,"test top_instantiation divider aclr", false,-1);
        tracep->declBit(c+335,"test top_instantiation divider clken", false,-1);
        tracep->declBus(c+86,"test top_instantiation divider quotient", false,-1, 31,0);
        tracep->declBus(c+87,"test top_instantiation divider remain", false,-1, 31,0);
        {int i; for (i=0; i<17; i++) {
                tracep->declBus(c+127+i*1,"test top_instantiation divider quotient_pipe", true,(i+0), 31,0);}}
        {int i; for (i=0; i<17; i++) {
                tracep->declBus(c+144+i*1,"test top_instantiation divider remain_pipe", true,(i+0), 31,0);}}
        tracep->declBus(c+161,"test top_instantiation divider tmp_quotient", false,-1, 31,0);
        tracep->declBus(c+162,"test top_instantiation divider tmp_remain", false,-1, 31,0);
        tracep->declBus(c+336,"test top_instantiation divider not_numer", false,-1, 31,0);
        tracep->declBus(c+337,"test top_instantiation divider int_numer", false,-1, 31,0);
        tracep->declBus(c+338,"test top_instantiation divider not_denom", false,-1, 31,0);
        tracep->declBus(c+339,"test top_instantiation divider int_denom", false,-1, 31,0);
        tracep->declBus(c+163,"test top_instantiation divider t_numer", false,-1, 31,0);
        tracep->declBus(c+164,"test top_instantiation divider t_q", false,-1, 31,0);
        tracep->declBus(c+165,"test top_instantiation divider t_denom", false,-1, 31,0);
        tracep->declBus(c+166,"test top_instantiation divider t_r", false,-1, 31,0);
        tracep->declBit(c+320,"test top_instantiation divider sign_q", false,-1);
        tracep->declBit(c+320,"test top_instantiation divider sign_r", false,-1);
        tracep->declBit(c+320,"test top_instantiation divider sign_n", false,-1);
        tracep->declBit(c+320,"test top_instantiation divider sign_d", false,-1);
        tracep->declQuad(c+4,"test top_instantiation divider lpm_remainderpositive", false,-1, 40,1);
        tracep->declBus(c+6,"test top_instantiation divider i", false,-1, 31,0);
        tracep->declBus(c+340,"test top_instantiation divider rsig", false,-1, 31,0);
        tracep->declBus(c+167,"test top_instantiation divider pipe_ptr", false,-1, 31,0);
        tracep->declBit(c+320,"test top_instantiation divider i_aclr", false,-1);
        tracep->declBit(c+282,"test top_instantiation divider i_clock", false,-1);
        tracep->declBit(c+298,"test top_instantiation divider i_clken", false,-1);
    }
}

void Vtest::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtest::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtest__Syms* __restrict vlSymsp = static_cast<Vtest__Syms*>(userp);
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtest::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtest__Syms* __restrict vlSymsp = static_cast<Vtest__Syms*>(userp);
    Vtest* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*255:0*/ __Vtemp38[8];
    WData/*95:0*/ __Vtemp39[3];
    WData/*223:0*/ __Vtemp40[7];
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->test__DOT__i),32);
        tracep->fullBit(oldp+2,(vlTOPp->test__DOT__PS2_CLK));
        tracep->fullIData(oldp+3,(vlTOPp->test__DOT__sdram_module__DOT__i),32);
        tracep->fullQData(oldp+4,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__lpm_remainderpositive),40);
        tracep->fullIData(oldp+6,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__i),32);
        tracep->fullQData(oldp+7,(vlTOPp->test__DOT__top_instantiation__DOT__GPIO_0),36);
        tracep->fullIData(oldp+9,(vlTOPp->test__DOT__top_instantiation__DOT__i),32);
        tracep->fullCData(oldp+10,(vlTOPp->test__DOT__top_instantiation__DOT__operation),8);
        tracep->fullIData(oldp+11,(vlTOPp->test__DOT__top_instantiation__DOT__operand1),32);
        tracep->fullIData(oldp+12,(vlTOPp->test__DOT__top_instantiation__DOT__operand2),32);
        tracep->fullIData(oldp+13,(vlTOPp->test__DOT__top_instantiation__DOT__registers[0]),32);
        tracep->fullIData(oldp+14,(vlTOPp->test__DOT__top_instantiation__DOT__registers[1]),32);
        tracep->fullIData(oldp+15,(vlTOPp->test__DOT__top_instantiation__DOT__registers[2]),32);
        tracep->fullIData(oldp+16,(vlTOPp->test__DOT__top_instantiation__DOT__registers[3]),32);
        tracep->fullIData(oldp+17,(vlTOPp->test__DOT__top_instantiation__DOT__registers[4]),32);
        tracep->fullIData(oldp+18,(vlTOPp->test__DOT__top_instantiation__DOT__registers[5]),32);
        tracep->fullIData(oldp+19,(vlTOPp->test__DOT__top_instantiation__DOT__registers[6]),32);
        tracep->fullIData(oldp+20,(vlTOPp->test__DOT__top_instantiation__DOT__registers[7]),32);
        tracep->fullIData(oldp+21,(vlTOPp->test__DOT__top_instantiation__DOT__registers[8]),32);
        tracep->fullIData(oldp+22,(vlTOPp->test__DOT__top_instantiation__DOT__registers[9]),32);
        tracep->fullIData(oldp+23,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[0]),32);
        tracep->fullIData(oldp+24,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[1]),32);
        tracep->fullIData(oldp+25,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[2]),32);
        tracep->fullIData(oldp+26,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[3]),32);
        tracep->fullIData(oldp+27,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[4]),32);
        tracep->fullIData(oldp+28,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[5]),32);
        tracep->fullIData(oldp+29,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[6]),32);
        tracep->fullIData(oldp+30,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[7]),32);
        tracep->fullIData(oldp+31,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[8]),32);
        tracep->fullIData(oldp+32,(vlTOPp->test__DOT__top_instantiation__DOT__shadow_registers[9]),32);
        tracep->fullIData(oldp+33,(vlTOPp->test__DOT__top_instantiation__DOT__code_section_start_address),32);
        tracep->fullIData(oldp+34,(vlTOPp->test__DOT__top_instantiation__DOT__program_end_address),32);
        tracep->fullIData(oldp+35,(vlTOPp->test__DOT__top_instantiation__DOT__temp_address),32);
        tracep->fullIData(oldp+36,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[0]),32);
        tracep->fullIData(oldp+37,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[1]),32);
        tracep->fullIData(oldp+38,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[2]),32);
        tracep->fullIData(oldp+39,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[3]),32);
        tracep->fullIData(oldp+40,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[4]),32);
        tracep->fullIData(oldp+41,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[5]),32);
        tracep->fullIData(oldp+42,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[6]),32);
        tracep->fullIData(oldp+43,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_vector_table[7]),32);
        tracep->fullIData(oldp+44,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_in),32);
        tracep->fullBit(oldp+45,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_write));
        tracep->fullBit(oldp+46,(((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+47,(((0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullIData(oldp+48,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_data_out),32);
        tracep->fullBit(oldp+49,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_read));
        tracep->fullCData(oldp+50,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo_access_state),2);
        tracep->fullIData(oldp+51,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in),32);
        tracep->fullBit(oldp+52,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_write));
        tracep->fullIData(oldp+53,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out),32);
        tracep->fullBit(oldp+54,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo_read));
        tracep->fullCData(oldp+55,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out),8);
        tracep->fullBit(oldp+56,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read));
        tracep->fullBit(oldp+57,(((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullBit(oldp+58,(((5U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                   ? 1U : 0U)));
        tracep->fullCData(oldp+59,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state),3);
        tracep->fullSData(oldp+60,(vlTOPp->test__DOT__top_instantiation__DOT__gpu_cell_to_access),14);
        tracep->fullBit(oldp+61,(vlTOPp->test__DOT__top_instantiation__DOT__gpu_write_enable));
        tracep->fullCData(oldp+62,(vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_to_write),8);
        tracep->fullCData(oldp+63,(vlTOPp->test__DOT__top_instantiation__DOT__gpu_character_read),8);
        tracep->fullBit(oldp+64,(vlTOPp->test__DOT__top_instantiation__DOT__gpu_access_state));
        tracep->fullIData(oldp+65,(vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address),32);
        tracep->fullCData(oldp+66,(vlTOPp->test__DOT__top_instantiation__DOT__program_rom_byte),8);
        tracep->fullBit(oldp+67,((0x107aU == vlTOPp->test__DOT__top_instantiation__DOT__program_rom_address)));
        tracep->fullBit(oldp+68,(vlTOPp->test__DOT__top_instantiation__DOT__program_rom_read_state));
        tracep->fullIData(oldp+69,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_address_i),22);
        tracep->fullCData(oldp+70,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_be_n_i),2);
        tracep->fullBit(oldp+71,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_cs_i));
        tracep->fullSData(oldp+72,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_i),16);
        tracep->fullBit(oldp+73,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i));
        tracep->fullBit(oldp+74,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i));
        tracep->fullCData(oldp+75,(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_state),8);
        tracep->fullBit(oldp+76,(vlTOPp->test__DOT__top_instantiation__DOT__ram_write_complete));
        tracep->fullCData(oldp+77,(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_state),8);
        tracep->fullBit(oldp+78,(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_complete));
        tracep->fullSData(oldp+79,(vlTOPp->test__DOT__top_instantiation__DOT__ram_read_data),16);
        tracep->fullCData(oldp+80,(vlTOPp->test__DOT__top_instantiation__DOT__ram_stabilization_counter),8);
        tracep->fullCData(oldp+81,(vlTOPp->test__DOT__top_instantiation__DOT__operand_byte_index),8);
        tracep->fullCData(oldp+82,(vlTOPp->test__DOT__top_instantiation__DOT__state),8);
        tracep->fullCData(oldp+83,(vlTOPp->test__DOT__top_instantiation__DOT__division_delay_counter),5);
        tracep->fullIData(oldp+84,(vlTOPp->test__DOT__top_instantiation__DOT__divider_numerator),32);
        tracep->fullIData(oldp+85,(vlTOPp->test__DOT__top_instantiation__DOT__divider_denominator),32);
        tracep->fullIData(oldp+86,(((0x10U >= (0x1fU 
                                               & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                     ? vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe
                                    [(0x1fU & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                     : 0U)),32);
        tracep->fullIData(oldp+87,(((0x10U >= (0x1fU 
                                               & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                     ? vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe
                                    [(0x1fU & vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                     : 0U)),32);
        tracep->fullCData(oldp+88,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer),4);
        tracep->fullCData(oldp+89,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer),4);
        tracep->fullIData(oldp+90,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[0]),32);
        tracep->fullIData(oldp+91,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[1]),32);
        tracep->fullIData(oldp+92,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[2]),32);
        tracep->fullIData(oldp+93,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[3]),32);
        tracep->fullIData(oldp+94,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[4]),32);
        tracep->fullIData(oldp+95,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[5]),32);
        tracep->fullIData(oldp+96,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[6]),32);
        tracep->fullIData(oldp+97,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[7]),32);
        tracep->fullIData(oldp+98,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[8]),32);
        tracep->fullIData(oldp+99,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[9]),32);
        tracep->fullCData(oldp+100,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size),4);
        tracep->fullIData(oldp+101,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__i),32);
        tracep->fullBit(oldp+102,(((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                                    ? 1U : 0U)));
        tracep->fullBit(oldp+103,(((0xaU == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                                    ? 1U : 0U)));
        tracep->fullCData(oldp+104,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer),4);
        tracep->fullCData(oldp+105,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer),4);
        tracep->fullIData(oldp+106,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[0]),32);
        tracep->fullIData(oldp+107,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[1]),32);
        tracep->fullIData(oldp+108,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[2]),32);
        tracep->fullIData(oldp+109,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[3]),32);
        tracep->fullIData(oldp+110,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[4]),32);
        tracep->fullIData(oldp+111,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[5]),32);
        tracep->fullIData(oldp+112,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[6]),32);
        tracep->fullIData(oldp+113,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[7]),32);
        tracep->fullIData(oldp+114,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[8]),32);
        tracep->fullIData(oldp+115,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[9]),32);
        tracep->fullCData(oldp+116,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size),4);
        tracep->fullIData(oldp+117,(vlTOPp->test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__i),32);
        tracep->fullCData(oldp+118,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer),3);
        tracep->fullCData(oldp+119,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer),3);
        tracep->fullCData(oldp+120,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[0]),8);
        tracep->fullCData(oldp+121,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[1]),8);
        tracep->fullCData(oldp+122,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[2]),8);
        tracep->fullCData(oldp+123,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[3]),8);
        tracep->fullCData(oldp+124,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[4]),8);
        tracep->fullCData(oldp+125,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size),3);
        tracep->fullIData(oldp+126,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__i),32);
        tracep->fullIData(oldp+127,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[0]),32);
        tracep->fullIData(oldp+128,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[1]),32);
        tracep->fullIData(oldp+129,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[2]),32);
        tracep->fullIData(oldp+130,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[3]),32);
        tracep->fullIData(oldp+131,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[4]),32);
        tracep->fullIData(oldp+132,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[5]),32);
        tracep->fullIData(oldp+133,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[6]),32);
        tracep->fullIData(oldp+134,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[7]),32);
        tracep->fullIData(oldp+135,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[8]),32);
        tracep->fullIData(oldp+136,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[9]),32);
        tracep->fullIData(oldp+137,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[10]),32);
        tracep->fullIData(oldp+138,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[11]),32);
        tracep->fullIData(oldp+139,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[12]),32);
        tracep->fullIData(oldp+140,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[13]),32);
        tracep->fullIData(oldp+141,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[14]),32);
        tracep->fullIData(oldp+142,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[15]),32);
        tracep->fullIData(oldp+143,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[16]),32);
        tracep->fullIData(oldp+144,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[0]),32);
        tracep->fullIData(oldp+145,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[1]),32);
        tracep->fullIData(oldp+146,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[2]),32);
        tracep->fullIData(oldp+147,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[3]),32);
        tracep->fullIData(oldp+148,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[4]),32);
        tracep->fullIData(oldp+149,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[5]),32);
        tracep->fullIData(oldp+150,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[6]),32);
        tracep->fullIData(oldp+151,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[7]),32);
        tracep->fullIData(oldp+152,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[8]),32);
        tracep->fullIData(oldp+153,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[9]),32);
        tracep->fullIData(oldp+154,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[10]),32);
        tracep->fullIData(oldp+155,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[11]),32);
        tracep->fullIData(oldp+156,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[12]),32);
        tracep->fullIData(oldp+157,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[13]),32);
        tracep->fullIData(oldp+158,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[14]),32);
        tracep->fullIData(oldp+159,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[15]),32);
        tracep->fullIData(oldp+160,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[16]),32);
        tracep->fullIData(oldp+161,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient),32);
        tracep->fullIData(oldp+162,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain),32);
        tracep->fullIData(oldp+163,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_numer),32);
        tracep->fullIData(oldp+164,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_q),32);
        tracep->fullIData(oldp+165,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_denom),32);
        tracep->fullIData(oldp+166,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__t_r),32);
        tracep->fullIData(oldp+167,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr),32);
        tracep->fullCData(oldp+168,(vlTOPp->test__DOT__VGA_R),4);
        tracep->fullCData(oldp+169,(vlTOPp->test__DOT__VGA_G),4);
        tracep->fullCData(oldp+170,(vlTOPp->test__DOT__VGA_B),4);
        tracep->fullCData(oldp+171,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character),8);
        tracep->fullBit(oldp+172,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value));
        tracep->fullSData(oldp+173,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_data_o),16);
        tracep->fullBit(oldp+174,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_valid_o));
        tracep->fullCData(oldp+175,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid),3);
        tracep->fullBit(oldp+176,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__za_cannotrefresh));
        tracep->fullBit(oldp+177,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address));
        tracep->fullBit(oldp+178,((1U & (~ ((0x58U 
                                             <= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                            & (0x84U 
                                               > (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))))));
        tracep->fullBit(oldp+179,((1U & (~ ((0x43cU 
                                             <= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                            & (0x441U 
                                               > (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
        tracep->fullBit(oldp+180,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking));
        tracep->fullSData(oldp+181,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x),12);
        tracep->fullSData(oldp+182,(((0x438U <= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count))
                                      ? 0x437U : (0x7ffU 
                                                  & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))),11);
        tracep->fullCData(oldp+183,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x),3);
        tracep->fullCData(oldp+184,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y),4);
        tracep->fullSData(oldp+185,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell),14);
        tracep->fullCData(oldp+186,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column),8);
        tracep->fullBit(oldp+187,((1U & (~ ((0x118U 
                                             > (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                            | (0x437U 
                                               < (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
        tracep->fullBit(oldp+188,(((0x464U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                   & (0x898U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))));
        tracep->fullBit(oldp+189,(((0x437U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                   & (0x898U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))));
        tracep->fullSData(oldp+190,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count),13);
        tracep->fullSData(oldp+191,(vlTOPp->test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count),12);
        tracep->fullSData(oldp+192,(vlTOPp->test__DOT__sdram_module__DOT__addr_crb),14);
        tracep->fullCData(oldp+193,((7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                                           - (IData)(1U)))),3);
        tracep->fullCData(oldp+194,(vlTOPp->test__DOT__sdram_module__DOT__latency),3);
        tracep->fullCData(oldp+195,(vlTOPp->test__DOT__sdram_module__DOT__read_mask),2);
        tracep->fullIData(oldp+196,(vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_0),22);
        tracep->fullIData(oldp+197,(vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_1),22);
        tracep->fullIData(oldp+198,(vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_2),22);
        tracep->fullCData(oldp+199,(vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_0),2);
        tracep->fullCData(oldp+200,(vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_1),2);
        tracep->fullCData(oldp+201,(vlTOPp->test__DOT__sdram_module__DOT__rd_mask_pipe_2),2);
        tracep->fullCData(oldp+202,(vlTOPp->test__DOT__sdram_module__DOT__rd_valid_pipe),3);
        tracep->fullIData(oldp+203,(((0U == (7U & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                                                   - (IData)(1U))))
                                      ? vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_0
                                      : ((1U == (7U 
                                                 & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                                                    - (IData)(1U))))
                                          ? vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_1
                                          : vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_2))),22);
        tracep->fullBit(oldp+204,(vlTOPp->test__DOT__sdram_module__DOT__read_valid));
        tracep->fullQData(oldp+205,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0),41);
        tracep->fullQData(oldp+207,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1),41);
        tracep->fullCData(oldp+209,((0xffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register))),8);
        tracep->fullSData(oldp+210,(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register),11);
        tracep->fullCData(oldp+211,(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter),4);
        tracep->fullBit(oldp+212,(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__done));
        tracep->fullBit(oldp+213,(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter_finished));
        tracep->fullSData(oldp+214,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr),12);
        tracep->fullBit(oldp+215,((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
        tracep->fullBit(oldp+216,((1U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                                         >> 1U))));
        tracep->fullBit(oldp+217,((1U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                         >> 1U))));
        tracep->fullBit(oldp+218,((1U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                         >> 3U))));
        tracep->fullSData(oldp+219,(vlTOPp->test__DOT__DRAM_DQ),16);
        tracep->fullBit(oldp+220,((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))));
        tracep->fullBit(oldp+221,((1U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm) 
                                         >> 1U))));
        tracep->fullBit(oldp+222,((1U & ((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                         >> 2U))));
        tracep->fullBit(oldp+223,((1U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))));
        tracep->fullCData(oldp+224,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank),2);
        tracep->fullCData(oldp+225,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm),2);
        tracep->fullIData(oldp+226,(vlTOPp->test__DOT__sdram_module__DOT__CODE),24);
        tracep->fullCData(oldp+227,((0xffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr))),8);
        tracep->fullCData(oldp+228,((7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))),3);
        tracep->fullSData(oldp+229,(vlTOPp->test__DOT__sdram_module__DOT__read_data),16);
        tracep->fullSData(oldp+230,(vlTOPp->test__DOT__sdram_module__DOT__rmw_temp),16);
        tracep->fullIData(oldp+231,(vlTOPp->test__DOT__sdram_module__DOT__test_addr),22);
        tracep->fullIData(oldp+232,(((0U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                      ? 0x4c4d52U : 
                                     ((1U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                       ? 0x415246U : 
                                      ((2U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                        ? 0x505245U
                                        : ((3U == (7U 
                                                   & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x414354U
                                            : ((4U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x205752U
                                                : (
                                                   (5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x205244U
                                                    : 
                                                   ((6U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x425354U
                                                     : 
                                                    ((7U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x4e4f50U
                                                      : 0x424144U))))))))),24);
        tracep->fullBit(oldp+233,((0x205752U == vlTOPp->test__DOT__sdram_module__DOT__CODE)));
        tracep->fullBit(oldp+234,((2U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+235,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller_init_done));
        tracep->fullIData(oldp+236,(((0xfU == (7U | (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                      ? 0x494e48U : 
                                     ((0U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                       ? 0x4c4d52U : 
                                      ((1U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                        ? 0x415246U
                                        : ((2U == (7U 
                                                   & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x505245U
                                            : ((3U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x414354U
                                                : (
                                                   (4U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x205752U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x205244U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x425354U
                                                      : 
                                                     ((7U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                       ? 0x4e4f50U
                                                       : 0x424144U)))))))))),24);
        tracep->fullBit(oldp+237,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request));
        tracep->fullIData(oldp+238,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr),22);
        tracep->fullCData(oldp+239,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank),2);
        tracep->fullBit(oldp+240,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n));
        tracep->fullSData(oldp+241,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data),16);
        tracep->fullCData(oldp+242,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm),2);
        tracep->fullBit(oldp+243,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw));
        tracep->fullBit(oldp+244,((1U >= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+245,((1U <= (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+246,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match));
        tracep->fullCData(oldp+247,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr),8);
        tracep->fullCData(oldp+248,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd),4);
        tracep->fullCData(oldp+249,((7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))),3);
        tracep->fullBit(oldp+250,(((~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)) 
                                   & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n))));
        tracep->fullBit(oldp+251,((1U & (~ (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)))));
        tracep->fullIData(oldp+252,((0x3fffffU & (IData)(
                                                         (vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                          >> 0x12U)))),22);
        tracep->fullCData(oldp+253,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank),2);
        tracep->fullSData(oldp+254,((0xffffU & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data))),16);
        tracep->fullCData(oldp+255,((3U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                   >> 0x10U)))),2);
        tracep->fullBit(oldp+256,((0U == (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
        tracep->fullBit(oldp+257,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop));
        tracep->fullBit(oldp+258,((1U & (IData)((vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                 >> 0x28U)))));
        tracep->fullBit(oldp+259,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select));
        tracep->fullQData(oldp+260,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data),41);
        tracep->fullSData(oldp+262,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr),12);
        tracep->fullCData(oldp+263,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd),4);
        tracep->fullCData(oldp+264,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count),3);
        tracep->fullCData(oldp+265,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next),3);
        tracep->fullCData(oldp+266,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs),3);
        tracep->fullCData(oldp+267,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state),3);
        tracep->fullCData(oldp+268,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count),3);
        tracep->fullSData(oldp+269,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data),16);
        tracep->fullSData(oldp+270,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next),9);
        tracep->fullSData(oldp+271,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state),9);
        tracep->fullBit(oldp+272,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe));
        tracep->fullBit(oldp+273,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending));
        tracep->fullBit(oldp+274,((5U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))));
        tracep->fullSData(oldp+275,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter),13);
        tracep->fullBit(oldp+276,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request));
        tracep->fullBit(oldp+277,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match));
        tracep->fullBit(oldp+278,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match));
        tracep->fullIData(oldp+279,(((0U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                      ? 0x4c4d52U : 
                                     ((1U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                       ? 0x415246U : 
                                      ((2U == (7U & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                        ? 0x505245U
                                        : ((3U == (7U 
                                                   & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x414354U
                                            : ((4U 
                                                == 
                                                (7U 
                                                 & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x205752U
                                                : (
                                                   (5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x205244U
                                                    : 
                                                   ((6U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x425354U
                                                     : 
                                                    ((7U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x4e4f50U
                                                      : 0x424144U))))))))),24);
        tracep->fullCData(oldp+280,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries),2);
        tracep->fullBit(oldp+281,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address));
        tracep->fullBit(oldp+282,(vlTOPp->clk));
        tracep->fullBit(oldp+283,(vlTOPp->reset));
        tracep->fullBit(oldp+284,(vlTOPp->dram_clk_supplied));
        tracep->fullBit(oldp+285,(vlTOPp->vga_clk_supplied));
        tracep->fullIData(oldp+286,(((0x205752U == vlTOPp->test__DOT__sdram_module__DOT__CODE)
                                      ? vlTOPp->test__DOT__sdram_module__DOT__test_addr
                                      : ((0U == (7U 
                                                 & ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                                                    - (IData)(1U))))
                                          ? vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_0
                                          : ((1U == 
                                              (7U & 
                                               ((IData)(vlTOPp->test__DOT__sdram_module__DOT__latency) 
                                                - (IData)(1U))))
                                              ? vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_1
                                              : vlTOPp->test__DOT__sdram_module__DOT__rd_addr_pipe_2)))),22);
        tracep->fullSData(oldp+287,((((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_temp__out1) 
                                      & ((1U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
                                          ? 0U : 0xffU)) 
                                     | ((IData)(vlTOPp->test__DOT__sdram_module__DOT__read_temp__out2) 
                                        & (((2U & (IData)(vlTOPp->test__DOT__sdram_module__DOT__read_mask))
                                             ? 0U : 0xffU) 
                                           << 8U)))),16);
        tracep->fullCData(oldp+288,(vlTOPp->reset),4);
        tracep->fullBit(oldp+289,(vlTOPp->test__DOT__top_instantiation__DOT__keyboard_scancode_ready));
        tracep->fullBit(oldp+290,(vlTOPp->test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__other_done));
        tracep->fullBit(oldp+291,((1U & (~ (IData)(vlTOPp->reset)))));
        tracep->fullBit(oldp+292,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr));
        tracep->fullQData(oldp+293,(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data),41);
        tracep->fullCData(oldp+295,((((IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) 
                                      << 1U) | (IData)(vlTOPp->test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr))),2);
        tracep->fullIData(oldp+296,(0x898U),32);
        tracep->fullIData(oldp+297,(0x465U),32);
        tracep->fullBit(oldp+298,(1U));
        __Vtemp38[0U] = 0x2e646174U;
        __Vtemp38[1U] = 0x64756c65U;
        __Vtemp38[2U] = 0x725f6d6fU;
        __Vtemp38[3U] = 0x72746e65U;
        __Vtemp38[4U] = 0x6d5f7061U;
        __Vtemp38[5U] = 0x73647261U;
        __Vtemp38[6U] = 0x6572615fU;
        __Vtemp38[7U] = 0x616c74U;
        tracep->fullWData(oldp+299,(__Vtemp38),248);
        tracep->fullCData(oldp+307,(0U),8);
        tracep->fullCData(oldp+308,(1U),8);
        tracep->fullCData(oldp+309,(2U),8);
        tracep->fullIData(oldp+310,(0x20U),32);
        tracep->fullIData(oldp+311,(0xaU),32);
        tracep->fullIData(oldp+312,(8U),32);
        tracep->fullIData(oldp+313,(5U),32);
        tracep->fullIData(oldp+314,(0x58U),32);
        tracep->fullIData(oldp+315,(0x84U),32);
        tracep->fullIData(oldp+316,(0x118U),32);
        tracep->fullIData(oldp+317,(0x43cU),32);
        tracep->fullIData(oldp+318,(0x441U),32);
        tracep->fullIData(oldp+319,(0x438U),32);
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
        tracep->fullIData(oldp+336,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__not_numer),32);
        tracep->fullIData(oldp+337,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__int_numer),32);
        tracep->fullIData(oldp+338,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__not_denom),32);
        tracep->fullIData(oldp+339,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__int_denom),32);
        tracep->fullIData(oldp+340,(vlTOPp->test__DOT__top_instantiation__DOT__divider__DOT__rsig),32);
    }
}
