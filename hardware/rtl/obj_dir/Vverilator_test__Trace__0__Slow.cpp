// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vverilator_test__Syms.h"


VL_ATTR_COLD void Vverilator_test___024root__trace_init_sub_0(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vverilator_test___024root__trace_init_top(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_init_top\n"); );
    // Body
    Vverilator_test___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void Vverilator_test___024root__trace_init_sub_0(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBit(c+18,"reset_n", false,-1);
    tracep->declBit(c+19,"verilator_only_dram_clk", false,-1);
    tracep->declBit(c+20,"verilator_only_vga_pixel_clock", false,-1);
    tracep->declBit(c+17,"verilator_test clk", false,-1);
    tracep->declBit(c+18,"verilator_test reset_n", false,-1);
    tracep->declBit(c+19,"verilator_test verilator_only_dram_clk", false,-1);
    tracep->declBit(c+20,"verilator_test verilator_only_vga_pixel_clock", false,-1);
    tracep->declBus(c+23,"verilator_test i", false,-1, 31,0);
    tracep->declBit(c+24,"verilator_test PS2_CLK", false,-1);
    tracep->declBit(c+24,"verilator_test PS2_DAT", false,-1);
    tracep->declBit(c+19,"verilator_test SDRAM_CLK", false,-1);
    tracep->declBus(c+7,"verilator_test DRAM_ADDR", false,-1, 11,0);
    tracep->declBit(c+8,"verilator_test DRAM_BA_0", false,-1);
    tracep->declBit(c+9,"verilator_test DRAM_BA_1", false,-1);
    tracep->declBit(c+10,"verilator_test DRAM_CAS_N", false,-1);
    tracep->declBit(c+24,"verilator_test DRAM_CKE", false,-1);
    tracep->declBit(c+11,"verilator_test DRAM_CS_N", false,-1);
    tracep->declBus(c+12,"verilator_test DRAM_DQ", false,-1, 15,0);
    tracep->declBit(c+13,"verilator_test DRAM_LDQM", false,-1);
    tracep->declBit(c+14,"verilator_test DRAM_UDQM", false,-1);
    tracep->declBit(c+15,"verilator_test DRAM_RAS_N", false,-1);
    tracep->declBit(c+16,"verilator_test DRAM_WE_N", false,-1);
    tracep->declBus(c+4,"verilator_test VGA_R", false,-1, 3,0);
    tracep->declBus(c+5,"verilator_test VGA_G", false,-1, 3,0);
    tracep->declBus(c+6,"verilator_test VGA_B", false,-1, 3,0);
    tracep->declBit(c+21,"verilator_test VGA_HS", false,-1);
    tracep->declBit(c+22,"verilator_test VGA_VS", false,-1);
    tracep->declBit(c+20,"verilator_test VGA_PIXEL_CLOCK", false,-1);
    tracep->declBit(c+1,"verilator_test spi_sclk", false,-1);
    tracep->declBit(c+2,"verilator_test spi_copi", false,-1);
    tracep->declBit(c+3,"verilator_test spi_cs", false,-1);
}

VL_ATTR_COLD void Vverilator_test___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vverilator_test___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vverilator_test___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vverilator_test___024root__trace_register(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vverilator_test___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vverilator_test___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vverilator_test___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vverilator_test___024root__trace_full_sub_0(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vverilator_test___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_full_top_0\n"); );
    // Init
    Vverilator_test___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_test___024root*>(voidSelf);
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vverilator_test___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vverilator_test___024root__trace_full_sub_0(Vverilator_test___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+1,(vlSelf->verilator_test__DOT__spi_sclk));
    tracep->fullBit(oldp+2,(vlSelf->verilator_test__DOT__spi_copi));
    tracep->fullBit(oldp+3,(vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select));
    tracep->fullCData(oldp+4,(vlSelf->verilator_test__DOT__VGA_R),4);
    tracep->fullCData(oldp+5,(vlSelf->verilator_test__DOT__VGA_G),4);
    tracep->fullCData(oldp+6,(vlSelf->verilator_test__DOT__VGA_B),4);
    tracep->fullSData(oldp+7,(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr),12);
    tracep->fullBit(oldp+8,((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
    tracep->fullBit(oldp+9,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                                   >> 1U))));
    tracep->fullBit(oldp+10,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                    >> 1U))));
    tracep->fullBit(oldp+11,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                    >> 3U))));
    tracep->fullSData(oldp+12,(vlSelf->verilator_test__DOT__DRAM_DQ),16);
    tracep->fullBit(oldp+13,((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))));
    tracep->fullBit(oldp+14,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm) 
                                    >> 1U))));
    tracep->fullBit(oldp+15,((1U & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                    >> 2U))));
    tracep->fullBit(oldp+16,((1U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))));
    tracep->fullBit(oldp+17,(vlSelf->clk));
    tracep->fullBit(oldp+18,(vlSelf->reset_n));
    tracep->fullBit(oldp+19,(vlSelf->verilator_only_dram_clk));
    tracep->fullBit(oldp+20,(vlSelf->verilator_only_vga_pixel_clock));
    tracep->fullBit(oldp+21,((1U & (~ ((0x58U <= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                       & (0x84U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))))));
    tracep->fullBit(oldp+22,((1U & (~ ((0x43cU <= (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                       & (0x441U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
    tracep->fullIData(oldp+23,(vlSelf->verilator_test__DOT__i),32);
    tracep->fullBit(oldp+24,(1U));
}
