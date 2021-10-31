// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vverilator_test__Syms.h"


void Vverilator_test___024root__trace_chg_sub_0(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep);

void Vverilator_test___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_chg_top_0\n"); );
    // Init
    Vverilator_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_test___024root*>(voidSelf);
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vverilator_test___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vverilator_test___024root__trace_chg_sub_0(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgBit(oldp+0,(vlSelf->verilator_test__DOT__spi_sclk));
        tracep->chgBit(oldp+1,(vlSelf->verilator_test__DOT__spi_copi));
        tracep->chgBit(oldp+2,(vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        tracep->chgCData(oldp+3,(vlSelf->verilator_test__DOT__VGA_R),4);
        tracep->chgCData(oldp+4,(vlSelf->verilator_test__DOT__VGA_G),4);
        tracep->chgCData(oldp+5,(vlSelf->verilator_test__DOT__VGA_B),4);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        tracep->chgSData(oldp+6,(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr),12);
        tracep->chgBit(oldp+7,((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
        tracep->chgBit(oldp+8,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                                      >> 1U))));
        tracep->chgBit(oldp+9,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                      >> 1U))));
        tracep->chgBit(oldp+10,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                       >> 3U))));
        tracep->chgSData(oldp+11,(vlSelf->verilator_test__DOT__DRAM_DQ),16);
        tracep->chgBit(oldp+12,((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))));
        tracep->chgBit(oldp+13,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm) 
                                       >> 1U))));
        tracep->chgBit(oldp+14,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                       >> 2U))));
        tracep->chgBit(oldp+15,((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))));
    }
    tracep->chgBit(oldp+16,(vlSelf->clk));
    tracep->chgBit(oldp+17,(vlSelf->reset_n));
    tracep->chgBit(oldp+18,(vlSelf->verilator_only_dram_clk));
    tracep->chgBit(oldp+19,(vlSelf->verilator_only_vga_pixel_clock));
    tracep->chgBit(oldp+20,((1U & (~ ((0x58U <= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                      & (0x84U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))))));
    tracep->chgBit(oldp+21,((1U & (~ ((0x43cU <= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                      & (0x441U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
}

void Vverilator_test___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_cleanup\n"); );
    // Init
    Vverilator_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_test___024root*>(voidSelf);
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
