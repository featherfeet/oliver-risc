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
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->verilator_test__DOT__spi_sclk));
        tracep->fullBit(oldp+2,(vlTOPp->verilator_test__DOT__spi_copi));
        tracep->fullBit(oldp+3,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select));
        tracep->fullCData(oldp+4,(vlTOPp->verilator_test__DOT__VGA_R),4);
        tracep->fullCData(oldp+5,(vlTOPp->verilator_test__DOT__VGA_G),4);
        tracep->fullCData(oldp+6,(vlTOPp->verilator_test__DOT__VGA_B),4);
        tracep->fullSData(oldp+7,(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr),12);
        tracep->fullBit(oldp+8,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank))));
        tracep->fullBit(oldp+9,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank) 
                                       >> 1U))));
        tracep->fullBit(oldp+10,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                        >> 1U))));
        tracep->fullBit(oldp+11,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                        >> 3U))));
        tracep->fullSData(oldp+12,(vlTOPp->verilator_test__DOT__DRAM_DQ),16);
        tracep->fullBit(oldp+13,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm))));
        tracep->fullBit(oldp+14,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm) 
                                        >> 1U))));
        tracep->fullBit(oldp+15,((1U & ((IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd) 
                                        >> 2U))));
        tracep->fullBit(oldp+16,((1U & (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))));
        tracep->fullBit(oldp+17,(vlTOPp->clk));
        tracep->fullBit(oldp+18,(vlTOPp->reset_n));
        tracep->fullBit(oldp+19,(vlTOPp->verilator_only_dram_clk));
        tracep->fullBit(oldp+20,(vlTOPp->verilator_only_vga_pixel_clock));
        tracep->fullBit(oldp+21,((1U & (~ ((0x58U <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
                                           & (0x84U 
                                              > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)))))));
        tracep->fullBit(oldp+22,((1U & (~ ((0x43cU 
                                            <= (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)) 
                                           & (0x441U 
                                              > (IData)(vlTOPp->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)))))));
        tracep->fullIData(oldp+23,(vlTOPp->verilator_test__DOT__i),32);
        tracep->fullBit(oldp+24,(1U));
    }
}
