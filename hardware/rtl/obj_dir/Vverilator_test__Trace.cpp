// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vverilator_test__Syms.h"


void Vverilator_test::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    Vverilator_test* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vverilator_test::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    Vverilator_test* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->verilator_test__DOT__i),32);
            tracep->chgIData(oldp+1,(vlTOPp->verilator_test__DOT__sdram_module__DOT__i),32);
            tracep->chgQData(oldp+2,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__lpm_remainderpositive),40);
            tracep->chgIData(oldp+4,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+5,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode),8);
            tracep->chgIData(oldp+6,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__i),32);
            tracep->chgCData(oldp+7,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operation),8);
            tracep->chgIData(oldp+8,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operand1),32);
            tracep->chgIData(oldp+9,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operand2),32);
            tracep->chgIData(oldp+10,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[0]),32);
            tracep->chgIData(oldp+11,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[1]),32);
            tracep->chgIData(oldp+12,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[2]),32);
            tracep->chgIData(oldp+13,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[3]),32);
            tracep->chgIData(oldp+14,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[4]),32);
            tracep->chgIData(oldp+15,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[5]),32);
            tracep->chgIData(oldp+16,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[6]),32);
            tracep->chgIData(oldp+17,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[7]),32);
            tracep->chgIData(oldp+18,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[8]),32);
            tracep->chgIData(oldp+19,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__registers[9]),32);
            tracep->chgIData(oldp+20,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[0]),32);
            tracep->chgIData(oldp+21,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[1]),32);
            tracep->chgIData(oldp+22,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[2]),32);
            tracep->chgIData(oldp+23,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[3]),32);
            tracep->chgIData(oldp+24,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[4]),32);
            tracep->chgIData(oldp+25,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[5]),32);
            tracep->chgIData(oldp+26,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[6]),32);
            tracep->chgIData(oldp+27,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[7]),32);
            tracep->chgIData(oldp+28,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[8]),32);
            tracep->chgIData(oldp+29,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__shadow_registers[9]),32);
            tracep->chgIData(oldp+30,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__code_section_start_address),32);
            tracep->chgIData(oldp+31,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_end_address),32);
            tracep->chgIData(oldp+32,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__temp_address),32);
            tracep->chgIData(oldp+33,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[0]),32);
            tracep->chgIData(oldp+34,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[1]),32);
            tracep->chgIData(oldp+35,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[2]),32);
            tracep->chgIData(oldp+36,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[3]),32);
            tracep->chgIData(oldp+37,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[4]),32);
            tracep->chgIData(oldp+38,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[5]),32);
            tracep->chgIData(oldp+39,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[6]),32);
            tracep->chgIData(oldp+40,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[7]),32);
            tracep->chgIData(oldp+41,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in),32);
            tracep->chgBit(oldp+42,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write));
            tracep->chgBit(oldp+43,(((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                      ? 1U : 0U)));
            tracep->chgBit(oldp+44,(((0xaU == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
                                      ? 1U : 0U)));
            tracep->chgIData(oldp+45,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out),32);
            tracep->chgBit(oldp+46,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read));
            tracep->chgCData(oldp+47,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state),2);
            tracep->chgIData(oldp+48,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in),32);
            tracep->chgBit(oldp+49,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write));
            tracep->chgIData(oldp+50,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out),32);
            tracep->chgBit(oldp+51,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read));
            tracep->chgBit(oldp+52,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready));
            tracep->chgCData(oldp+53,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out),8);
            tracep->chgBit(oldp+54,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read));
            tracep->chgBit(oldp+55,(((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                      ? 1U : 0U)));
            tracep->chgBit(oldp+56,(((5U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
                                      ? 1U : 0U)));
            tracep->chgCData(oldp+57,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state),3);
            tracep->chgSData(oldp+58,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access),14);
            tracep->chgBit(oldp+59,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_write_enable));
            tracep->chgCData(oldp+60,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write),8);
            tracep->chgCData(oldp+61,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_character_read),8);
            tracep->chgBit(oldp+62,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__gpu_access_state));
            tracep->chgIData(oldp+63,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_address),32);
            tracep->chgCData(oldp+64,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_byte),8);
            tracep->chgBit(oldp+65,((0x17f1U == vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_address)));
            tracep->chgBit(oldp+66,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__program_rom_read_state));
            tracep->chgIData(oldp+67,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i),22);
            tracep->chgCData(oldp+68,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i),2);
            tracep->chgBit(oldp+69,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_cs_i));
            tracep->chgSData(oldp+70,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i),16);
            tracep->chgBit(oldp+71,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i));
            tracep->chgBit(oldp+72,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i));
            tracep->chgCData(oldp+73,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_write_state),8);
            tracep->chgBit(oldp+74,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_write_complete));
            tracep->chgCData(oldp+75,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_read_state),8);
            tracep->chgBit(oldp+76,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_read_complete));
            tracep->chgSData(oldp+77,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_read_data),16);
            tracep->chgCData(oldp+78,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter),8);
            tracep->chgCData(oldp+79,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__operand_byte_index),8);
            tracep->chgCData(oldp+80,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__state),8);
            tracep->chgCData(oldp+81,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__division_delay_counter),5);
            tracep->chgIData(oldp+82,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider_numerator),32);
            tracep->chgIData(oldp+83,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider_denominator),32);
            tracep->chgIData(oldp+84,(((0x10U >= (0x1fU 
                                                  & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                        ? vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe
                                       [(0x1fU & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                        : 0U)),32);
            tracep->chgIData(oldp+85,(((0x10U >= (0x1fU 
                                                  & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr))
                                        ? vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe
                                       [(0x1fU & vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr)]
                                        : 0U)),32);
            tracep->chgCData(oldp+86,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer),4);
            tracep->chgCData(oldp+87,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer),4);
            tracep->chgIData(oldp+88,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[0]),32);
            tracep->chgIData(oldp+89,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[1]),32);
            tracep->chgIData(oldp+90,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[2]),32);
            tracep->chgIData(oldp+91,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[3]),32);
            tracep->chgIData(oldp+92,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[4]),32);
            tracep->chgIData(oldp+93,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[5]),32);
            tracep->chgIData(oldp+94,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[6]),32);
            tracep->chgIData(oldp+95,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[7]),32);
            tracep->chgIData(oldp+96,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[8]),32);
            tracep->chgIData(oldp+97,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[9]),32);
            tracep->chgCData(oldp+98,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size),4);
            tracep->chgIData(oldp+99,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__i),32);
            tracep->chgBit(oldp+100,(((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                                       ? 1U : 0U)));
            tracep->chgBit(oldp+101,(((0xaU == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
                                       ? 1U : 0U)));
            tracep->chgCData(oldp+102,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer),4);
            tracep->chgCData(oldp+103,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer),4);
            tracep->chgIData(oldp+104,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[0]),32);
            tracep->chgIData(oldp+105,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[1]),32);
            tracep->chgIData(oldp+106,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[2]),32);
            tracep->chgIData(oldp+107,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[3]),32);
            tracep->chgIData(oldp+108,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[4]),32);
            tracep->chgIData(oldp+109,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[5]),32);
            tracep->chgIData(oldp+110,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[6]),32);
            tracep->chgIData(oldp+111,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[7]),32);
            tracep->chgIData(oldp+112,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[8]),32);
            tracep->chgIData(oldp+113,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[9]),32);
            tracep->chgCData(oldp+114,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size),4);
            tracep->chgIData(oldp+115,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__i),32);
            tracep->chgCData(oldp+116,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer),8);
            tracep->chgBit(oldp+117,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state));
            tracep->chgBit(oldp+118,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state));
            tracep->chgBit(oldp+119,(((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state) 
                                      & (~ (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state)))));
            tracep->chgSData(oldp+120,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register),11);
            tracep->chgCData(oldp+121,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter),4);
            tracep->chgCData(oldp+122,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer),3);
            tracep->chgCData(oldp+123,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer),3);
            tracep->chgCData(oldp+124,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[0]),8);
            tracep->chgCData(oldp+125,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[1]),8);
            tracep->chgCData(oldp+126,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[2]),8);
            tracep->chgCData(oldp+127,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[3]),8);
            tracep->chgCData(oldp+128,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[4]),8);
            tracep->chgCData(oldp+129,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size),3);
            tracep->chgIData(oldp+130,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__i),32);
            tracep->chgIData(oldp+131,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[0]),32);
            tracep->chgIData(oldp+132,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[1]),32);
            tracep->chgIData(oldp+133,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[2]),32);
            tracep->chgIData(oldp+134,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[3]),32);
            tracep->chgIData(oldp+135,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[4]),32);
            tracep->chgIData(oldp+136,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[5]),32);
            tracep->chgIData(oldp+137,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[6]),32);
            tracep->chgIData(oldp+138,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[7]),32);
            tracep->chgIData(oldp+139,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[8]),32);
            tracep->chgIData(oldp+140,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[9]),32);
            tracep->chgIData(oldp+141,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[10]),32);
            tracep->chgIData(oldp+142,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[11]),32);
            tracep->chgIData(oldp+143,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[12]),32);
            tracep->chgIData(oldp+144,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[13]),32);
            tracep->chgIData(oldp+145,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[14]),32);
            tracep->chgIData(oldp+146,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[15]),32);
            tracep->chgIData(oldp+147,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[16]),32);
            tracep->chgIData(oldp+148,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[0]),32);
            tracep->chgIData(oldp+149,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[1]),32);
            tracep->chgIData(oldp+150,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[2]),32);
            tracep->chgIData(oldp+151,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[3]),32);
            tracep->chgIData(oldp+152,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[4]),32);
            tracep->chgIData(oldp+153,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[5]),32);
            tracep->chgIData(oldp+154,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[6]),32);
            tracep->chgIData(oldp+155,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[7]),32);
            tracep->chgIData(oldp+156,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[8]),32);
            tracep->chgIData(oldp+157,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[9]),32);
            tracep->chgIData(oldp+158,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[10]),32);
            tracep->chgIData(oldp+159,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[11]),32);
            tracep->chgIData(oldp+160,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[12]),32);
            tracep->chgIData(oldp+161,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[13]),32);
            tracep->chgIData(oldp+162,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[14]),32);
            tracep->chgIData(oldp+163,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[15]),32);
            tracep->chgIData(oldp+164,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[16]),32);
            tracep->chgIData(oldp+165,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient),32);
            tracep->chgIData(oldp+166,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain),32);
            tracep->chgIData(oldp+167,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer),32);
            tracep->chgIData(oldp+168,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q),32);
            tracep->chgIData(oldp+169,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom),32);
            tracep->chgIData(oldp+170,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r),32);
            tracep->chgIData(oldp+171,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+172,(vlTOPp->verilator_test__DOT__VGA_R),4);
            tracep->chgCData(oldp+173,(vlTOPp->verilator_test__DOT__VGA_G),4);
            tracep->chgCData(oldp+174,(vlTOPp->verilator_test__DOT__VGA_B),4);
            tracep->chgCData(oldp+175,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character),8);
            tracep->chgBit(oldp+176,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgSData(oldp+177,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o),16);
            tracep->chgBit(oldp+178,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o));
            tracep->chgCData(oldp+179,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid),3);
            tracep->chgBit(oldp+180,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__za_cannotrefresh));
            tracep->chgBit(oldp+181,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgBit(oldp+182,((1U & (~ ((0x58U 
                                                <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                               & (0x84U 
                                                  > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))))));
            tracep->chgBit(oldp+183,((1U & (~ ((0x43cU 
                                                <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                               & (0x441U 
                                                  > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
            tracep->chgBit(oldp+184,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking));
            tracep->chgSData(oldp+185,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x),12);
            tracep->chgSData(oldp+186,(((0x438U <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count))
                                         ? 0x437U : 
                                        (0x7ffU & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))),11);
            tracep->chgCData(oldp+187,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x),3);
            tracep->chgCData(oldp+188,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y),4);
            tracep->chgSData(oldp+189,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell),14);
            tracep->chgCData(oldp+190,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column),8);
            tracep->chgBit(oldp+191,((1U & (~ ((0x118U 
                                                > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                               | (0x437U 
                                                  < (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
            tracep->chgBit(oldp+192,(((0x464U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                      & (0x898U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))));
            tracep->chgBit(oldp+193,(((0x437U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                      & (0x898U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))));
            tracep->chgSData(oldp+194,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count),13);
            tracep->chgSData(oldp+195,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count),12);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgSData(oldp+196,(vlTOPp->verilator_test__DOT__sdram_module__DOT__addr_crb),14);
            tracep->chgCData(oldp+197,((7U & ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                              - (IData)(1U)))),3);
            tracep->chgCData(oldp+198,(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency),3);
            tracep->chgCData(oldp+199,(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_mask),2);
            tracep->chgIData(oldp+200,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0),22);
            tracep->chgIData(oldp+201,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1),22);
            tracep->chgIData(oldp+202,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2),22);
            tracep->chgCData(oldp+203,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0),2);
            tracep->chgCData(oldp+204,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1),2);
            tracep->chgCData(oldp+205,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_2),2);
            tracep->chgCData(oldp+206,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe),3);
            tracep->chgIData(oldp+207,(((0U == (7U 
                                                & ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                                   - (IData)(1U))))
                                         ? vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0
                                         : ((1U == 
                                             (7U & 
                                              ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__latency) 
                                               - (IData)(1U))))
                                             ? vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1
                                             : vlTOPp->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2))),22);
            tracep->chgBit(oldp+208,(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_valid));
            tracep->chgQData(oldp+209,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0),41);
            tracep->chgQData(oldp+211,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1),41);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgSData(oldp+213,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr),12);
            tracep->chgBit(oldp+214,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
            tracep->chgBit(oldp+215,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                                            >> 1U))));
            tracep->chgBit(oldp+216,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                            >> 1U))));
            tracep->chgBit(oldp+217,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                            >> 3U))));
            tracep->chgSData(oldp+218,(vlTOPp->verilator_test__DOT__DRAM_DQ),16);
            tracep->chgBit(oldp+219,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))));
            tracep->chgBit(oldp+220,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm) 
                                            >> 1U))));
            tracep->chgBit(oldp+221,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                            >> 2U))));
            tracep->chgBit(oldp+222,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))));
            tracep->chgCData(oldp+223,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank),2);
            tracep->chgCData(oldp+224,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm),2);
            tracep->chgIData(oldp+225,(vlTOPp->verilator_test__DOT__sdram_module__DOT__CODE),24);
            tracep->chgCData(oldp+226,((0xffU & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr))),8);
            tracep->chgCData(oldp+227,((7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))),3);
            tracep->chgSData(oldp+228,(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_data),16);
            tracep->chgSData(oldp+229,(vlTOPp->verilator_test__DOT__sdram_module__DOT__rmw_temp),16);
            tracep->chgIData(oldp+230,(vlTOPp->verilator_test__DOT__sdram_module__DOT__test_addr),22);
            tracep->chgIData(oldp+231,(((0U == (7U 
                                                & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                         ? 0x4c4d52U
                                         : ((1U == 
                                             (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                             ? 0x415246U
                                             : ((2U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                 ? 0x505245U
                                                 : 
                                                ((3U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                  ? 0x414354U
                                                  : 
                                                 ((4U 
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
                                                      : 0x424144U))))))))),24);
            tracep->chgBit(oldp+232,((0x205752U == vlTOPp->verilator_test__DOT__sdram_module__DOT__CODE)));
            tracep->chgBit(oldp+233,((2U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
            tracep->chgBit(oldp+234,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done));
            tracep->chgIData(oldp+235,(((0xfU == (7U 
                                                  | (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                         ? 0x494e48U
                                         : ((0U == 
                                             (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                             ? 0x4c4d52U
                                             : ((1U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                 ? 0x415246U
                                                 : 
                                                ((2U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                  ? 0x505245U
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                   ? 0x414354U
                                                   : 
                                                  ((4U 
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
            tracep->chgBit(oldp+236,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request));
            tracep->chgIData(oldp+237,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr),22);
            tracep->chgCData(oldp+238,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank),2);
            tracep->chgBit(oldp+239,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n));
            tracep->chgSData(oldp+240,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data),16);
            tracep->chgCData(oldp+241,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm),2);
            tracep->chgBit(oldp+242,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw));
            tracep->chgBit(oldp+243,((1U >= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
            tracep->chgBit(oldp+244,((1U <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
            tracep->chgBit(oldp+245,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match));
            tracep->chgCData(oldp+246,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr),8);
            tracep->chgCData(oldp+247,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd),4);
            tracep->chgCData(oldp+248,((7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))),3);
            tracep->chgBit(oldp+249,(((~ (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)) 
                                      & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n))));
            tracep->chgBit(oldp+250,((1U & (~ (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)))));
            tracep->chgIData(oldp+251,((0x3fffffU & (IData)(
                                                            (vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                             >> 0x12U)))),22);
            tracep->chgCData(oldp+252,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank),2);
            tracep->chgSData(oldp+253,((0xffffU & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data))),16);
            tracep->chgCData(oldp+254,((3U & (IData)(
                                                     (vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                      >> 0x10U)))),2);
            tracep->chgBit(oldp+255,((0U == (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries))));
            tracep->chgBit(oldp+256,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop));
            tracep->chgBit(oldp+257,((1U & (IData)(
                                                   (vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                    >> 0x28U)))));
            tracep->chgBit(oldp+258,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select));
            tracep->chgQData(oldp+259,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data),41);
            tracep->chgSData(oldp+261,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr),12);
            tracep->chgCData(oldp+262,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd),4);
            tracep->chgCData(oldp+263,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count),3);
            tracep->chgCData(oldp+264,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next),3);
            tracep->chgCData(oldp+265,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs),3);
            tracep->chgCData(oldp+266,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state),3);
            tracep->chgCData(oldp+267,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count),3);
            tracep->chgSData(oldp+268,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data),16);
            tracep->chgSData(oldp+269,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next),9);
            tracep->chgSData(oldp+270,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state),9);
            tracep->chgBit(oldp+271,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe));
            tracep->chgBit(oldp+272,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending));
            tracep->chgBit(oldp+273,((5U == (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))));
            tracep->chgSData(oldp+274,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter),13);
            tracep->chgBit(oldp+275,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request));
            tracep->chgBit(oldp+276,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match));
            tracep->chgBit(oldp+277,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match));
            tracep->chgIData(oldp+278,(((0U == (7U 
                                                & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                         ? 0x4c4d52U
                                         : ((1U == 
                                             (7U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                             ? 0x415246U
                                             : ((2U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                 ? 0x505245U
                                                 : 
                                                ((3U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                  ? 0x414354U
                                                  : 
                                                 ((4U 
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
                                                      : 0x424144U))))))))),24);
            tracep->chgCData(oldp+279,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries),2);
            tracep->chgBit(oldp+280,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address));
        }
        tracep->chgBit(oldp+281,(vlTOPp->clk));
        tracep->chgBit(oldp+282,(vlTOPp->reset_n));
        tracep->chgBit(oldp+283,(vlTOPp->verilator_only_dram_clk));
        tracep->chgBit(oldp+284,(vlTOPp->verilator_only_vga_pixel_clock));
        tracep->chgIData(oldp+285,(((0x205752U == vlTOPp->verilator_test__DOT__sdram_module__DOT__CODE)
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
        tracep->chgSData(oldp+286,((((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_temp__out1) 
                                     & ((1U & (IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_mask))
                                         ? 0U : 0xffU)) 
                                    | ((IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_temp__out2) 
                                       & (((2U & (IData)(vlTOPp->verilator_test__DOT__sdram_module__DOT__read_mask))
                                            ? 0U : 0xffU) 
                                          << 8U)))),16);
        tracep->chgCData(oldp+287,(vlTOPp->reset_n),4);
        tracep->chgBit(oldp+288,((1U & (~ (IData)(vlTOPp->reset_n)))));
        tracep->chgBit(oldp+289,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr));
        tracep->chgQData(oldp+290,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data),41);
        tracep->chgCData(oldp+292,((((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select) 
                                     << 1U) | (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr))),2);
    }
}

void Vverilator_test::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vverilator_test__Syms* __restrict vlSymsp = static_cast<Vverilator_test__Syms*>(userp);
    Vverilator_test* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
        vlTOPp->__Vm_traceActivity[6U] = 0U;
    }
}
