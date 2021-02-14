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
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->verilator_test__DOT__spi_sclk));
            tracep->chgBit(oldp+1,(vlTOPp->verilator_test__DOT__spi_copi));
            tracep->chgBit(oldp+2,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+3,(vlTOPp->verilator_test__DOT__VGA_R),4);
            tracep->chgCData(oldp+4,(vlTOPp->verilator_test__DOT__VGA_G),4);
            tracep->chgCData(oldp+5,(vlTOPp->verilator_test__DOT__VGA_B),4);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgSData(oldp+6,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr),12);
            tracep->chgBit(oldp+7,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
            tracep->chgBit(oldp+8,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                                          >> 1U))));
            tracep->chgBit(oldp+9,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                          >> 1U))));
            tracep->chgBit(oldp+10,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                           >> 3U))));
            tracep->chgSData(oldp+11,(vlTOPp->verilator_test__DOT__DRAM_DQ),16);
            tracep->chgBit(oldp+12,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))));
            tracep->chgBit(oldp+13,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm) 
                                           >> 1U))));
            tracep->chgBit(oldp+14,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                           >> 2U))));
            tracep->chgBit(oldp+15,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))));
        }
        tracep->chgBit(oldp+16,(vlTOPp->clk));
        tracep->chgBit(oldp+17,(vlTOPp->reset_n));
        tracep->chgBit(oldp+18,(vlTOPp->verilator_only_dram_clk));
        tracep->chgBit(oldp+19,(vlTOPp->verilator_only_vga_pixel_clock));
        tracep->chgBit(oldp+20,((1U & (~ ((0x58U <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                          & (0x84U 
                                             > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))))));
        tracep->chgBit(oldp+21,((1U & (~ ((0x43cU <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                          & (0x441U 
                                             > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
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
    }
}
