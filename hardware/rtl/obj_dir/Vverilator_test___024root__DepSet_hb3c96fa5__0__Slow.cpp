// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_test.h for the primary calling header

#include "verilated.h"

#include "Vverilator_test___024root.h"

VL_ATTR_COLD void Vverilator_test___024root___settle__TOP__7(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___settle__TOP__7\n"); );
    // Init
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom;
    IData/*31:0*/ verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r;
    // Body
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x 
        = ((0x118U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count))
            ? 0U : (0xfffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count) 
                              - (IData)(0x118U))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking 
        = ((0x118U > (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count)) 
           | (0x437U < (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count)));
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid 
        = (1U & ((0U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                               - (IData)(1U)))) ? (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe)
                  : ((1U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                                   - (IData)(1U))))
                      ? ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe) 
                         >> 1U) : ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe) 
                                   >> 2U))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data 
        = (((QData)((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)) 
            << 0x28U) | (((QData)((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i)) 
                          << 0x12U) | (QData)((IData)(
                                                      ((((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)
                                                          ? 0U
                                                          : (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i)) 
                                                        << 0x10U) 
                                                       | (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i))))));
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_numerator;
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom 
        = vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_denominator;
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q 
        = VL_DIV_III(32, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom);
    verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r 
        = VL_MODDIV_III(32, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_numer, verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_denom);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient 
        = verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_q;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain 
        = verilator_test__DOT__top_instantiation__DOT__divider__DOT__t_r;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_full 
        = ((0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_empty 
        = ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full 
        = ((0xaU == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty 
        = ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full 
        = ((5U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty 
        = ((0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size))
            ? 1U : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_done 
        = (0xdd7U == vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address);
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask 
        = ((0U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                         - (IData)(1U)))) ? (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0)
            : ((1U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                             - (IData)(1U)))) ? (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1)
                : (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_2)));
    if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) {
        if (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address) {
            vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1;
        }
    } else {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
            = vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0;
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match 
        = (1U & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o 
        = (2U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty 
        = (0U == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr 
        = (((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i)) 
            | (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i))) 
           & (2U != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)));
    vlSelf->verilator_test__DOT__sdram_module__DOT__CODE 
        = ((8U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd))
            ? 0x494e48U : ((0U == (7U & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                            ? 0x4c4d52U : ((1U == (7U 
                                                   & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                            ? 0x415246U
                                            : ((2U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                ? 0x505245U
                                                : (
                                                   (3U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                    ? 0x414354U
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                     ? 0x205752U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                      ? 0x205244U
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                       ? 0x425354U
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd)))
                                                        ? 0x4e4f50U
                                                        : 0x424144U)))))))));
    vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr 
        = (((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__addr_crb) 
            << 8U) | (0xffU & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank 
        = ((2U & (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                  >> 0x14U)) | (1U & (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                                      >> 8U)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_falling 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__previous_spi_clock) 
           & (~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock)));
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_temp__en1 
        = ((((2U & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
              ? 0U : 0xffU) << 8U) | ((1U & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
                                       ? 0U : 0xffU));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw) 
           == (1U & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                             >> 0x28U))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match 
        = ((0xfffU & (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr 
                      >> 9U)) == (0xfffU & (IData)(
                                                   (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                    >> 0x1bU))));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank 
        = ((2U & ((IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                           >> 0x27U)) << 1U)) | (1U 
                                                 & (IData)(
                                                           (vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                                            >> 0x1aU))));
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_data 
        = vlSelf->verilator_test__DOT__sdram_module__DOT__mem_array
        [((0x205752U == vlSelf->verilator_test__DOT__sdram_module__DOT__CODE)
           ? vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr
           : ((0U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                            - (IData)(1U)))) ? vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0
               : ((1U == (7U & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__latency) 
                                - (IData)(1U)))) ? vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1
                   : vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2)))];
    vlSelf->verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0 
        = ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid)
            ? (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_temp__en1)
            : 0U);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank) 
           == (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank));
    vlSelf->verilator_test__DOT__DRAM_DQ = (((((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid)
                                                ? (
                                                   ((((2U 
                                                       & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
                                                       ? 0U
                                                       : 
                                                      (0xffU 
                                                       & ((IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_data) 
                                                          >> 8U))) 
                                                     << 8U) 
                                                    | ((1U 
                                                        & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask))
                                                        ? 0U
                                                        : 
                                                       (0xffU 
                                                        & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_data)))) 
                                                   & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__read_temp__en1))
                                                : 0U) 
                                              & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0)) 
                                             & (IData)(vlSelf->verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0)) 
                                            | (((((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                   ? (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data)
                                                   : 0U) 
                                                 & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                     ? 0xffffU
                                                     : 0U)) 
                                                & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                    ? 0xffffU
                                                    : 0U)) 
                                               & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe)
                                                   ? 0xffffU
                                                   : 0U)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending 
        = (((((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n)) 
              & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match)) 
             & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match)) 
            & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match)) 
           & (0U != (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries)));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select 
        = ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop) 
           & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n 
        = ((~ (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)) 
           & (IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n));
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr 
        = (0xffU & ((IData)(vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select)
                     ? (0xffU & (IData)((vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data 
                                         >> 0x12U)))
                     : (0xffU & vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr)));
}

VL_ATTR_COLD void Vverilator_test___024root___initial__TOP__1(Vverilator_test___024root* vlSelf);

VL_ATTR_COLD void Vverilator_test___024root___eval_initial(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___eval_initial\n"); );
    // Body
    Vverilator_test___024root___initial__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__verilator_only_vga_pixel_clock 
        = vlSelf->verilator_only_vga_pixel_clock;
    vlSelf->__Vclklast__TOP__reset_n = vlSelf->reset_n;
    vlSelf->__Vclklast__TOP__verilator_only_dram_clk 
        = vlSelf->verilator_only_dram_clk;
}

VL_ATTR_COLD void Vverilator_test___024root___eval_settle(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___eval_settle\n"); );
    // Body
    Vverilator_test___024root___settle__TOP__7(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vverilator_test___024root___final(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___final\n"); );
}

VL_ATTR_COLD void Vverilator_test___024root___ctor_var_reset(Vverilator_test___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_test___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset_n = VL_RAND_RESET_I(1);
    vlSelf->verilator_only_dram_clk = VL_RAND_RESET_I(1);
    vlSelf->verilator_only_vga_pixel_clock = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__DRAM_DQ = VL_RAND_RESET_I(16);
    vlSelf->verilator_test__DOT__VGA_R = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__VGA_G = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__VGA_B = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__spi_sclk = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__spi_copi = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__sdram_module__DOT__CODE = VL_RAND_RESET_I(24);
    vlSelf->verilator_test__DOT__sdram_module__DOT__addr_crb = VL_RAND_RESET_I(14);
    vlSelf->verilator_test__DOT__sdram_module__DOT__latency = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<4194304; ++__Vi0) {
        vlSelf->verilator_test__DOT__sdram_module__DOT__mem_array[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_0 = VL_RAND_RESET_I(22);
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_1 = VL_RAND_RESET_I(22);
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_addr_pipe_2 = VL_RAND_RESET_I(22);
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_0 = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_1 = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_mask_pipe_2 = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__sdram_module__DOT__rd_valid_pipe = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_mask = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_valid = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__sdram_module__DOT__test_addr = VL_RAND_RESET_I(22);
    vlSelf->verilator_test__DOT__sdram_module__DOT__zs_dq__out__en0 = 0;
    vlSelf->verilator_test__DOT__sdram_module__DOT__read_temp__en1 = 0;
    vlSelf->verilator_test__DOT__top_instantiation__DOT__SD_DAT = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operation = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operand1 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operand2 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<10; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<10; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__shadow_registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__code_section_start_address = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__temp_address = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_vector_table[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_in = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_write = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_full = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_data_out = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_read = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo_access_state = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_in = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_write = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_data_out = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo_read = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_ready = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_data_out = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_read = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_full = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancode_fifo_access_state = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_cell_to_access = VL_RAND_RESET_I(14);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_write_enable = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_to_write = VL_RAND_RESET_I(7);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_character_read = VL_RAND_RESET_I(7);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__gpu_access_state = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_address = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_byte = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_done = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom_read_state = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_address_i = VL_RAND_RESET_I(22);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_be_n_i = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_i = VL_RAND_RESET_I(16);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_rd_n_i = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_wr_n_i = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_data_o = VL_RAND_RESET_I(16);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_valid_o = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_waitrequest_o = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_state = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_write_complete = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_state = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_complete = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_read_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ram_stabilization_counter = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__operand_byte_index = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__state = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__division_delay_counter = VL_RAND_RESET_I(5);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_numerator = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider_denominator = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_clock_select = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_pulse = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_transmit_done = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_to_send = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_byte_received = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sd_card_spi_access_state = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__0 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__1 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__2 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__0 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__1 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__3 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__4 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__5 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h44090299__6 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h55dd1a36__2 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_h534bd7c9__1 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT____Vlvbound_hc918f5f0__0 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__write_pointer = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__read_pointer = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<10; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__items[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT__current_fifo_size = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_fifo__DOT____Vlvbound_ha352e82a__0 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__full = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__write_pointer = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__read_pointer = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<10; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__items[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT__current_fifo_size = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__interrupt_value_fifo__DOT____Vlvbound_ha352e82a__0 = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_buffer = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__ps2_clk_filtered_state = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__previous_ps2_clk_filtered_state = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__shift_register = VL_RAND_RESET_I(11);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__ps2_keyboard__DOT__bits_counter = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__write_pointer = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__read_pointer = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<5; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__items[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT__current_fifo_size = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__keyboard_scancodes_fifo__DOT____Vlvbound_h641c722f__0 = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__blanking = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__pixel_x = VL_RAND_RESET_I(12);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_x = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__character_cell_y = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character_cell = VL_RAND_RESET_I(14);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_column = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_character = VL_RAND_RESET_I(7);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__current_pixel_value = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<16080; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer[__Vi0] = VL_RAND_RESET_I(7);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT____Vlvbound_hc18ac365__0 = VL_RAND_RESET_I(7);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__h_count = VL_RAND_RESET_I(13);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__vga__DOT__v_count = VL_RAND_RESET_I(12);
    for (int __Vi0=0; __Vi0<128; ++__Vi0) {
        VL_RAND_RESET_W(128, vlSelf->verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__font_glyphs__DOT__font_storage[__Vi0]);
    }
    for (int __Vi0=0; __Vi0<3544; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__program_rom__DOT__rom_memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__ack_refresh_request = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr = VL_RAND_RESET_I(22);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_bank = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_cs_n = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__bank_match = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cas_addr = VL_RAND_RESET_I(8);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__cs_n = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__csn_match = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_bank = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_empty = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_select = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__fifo_read_data = VL_RAND_RESET_Q(41);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_addr = VL_RAND_RESET_I(12);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_cmd = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_addr = VL_RAND_RESET_I(12);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_bank = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_cmd = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_dqm = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = VL_RAND_RESET_I(9);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = VL_RAND_RESET_I(9);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__oe = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__pending = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rd_valid = VL_RAND_RESET_I(3);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter = VL_RAND_RESET_I(13);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__rnw_match = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__row_match = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr_data = VL_RAND_RESET_Q(41);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT____Vcellinp__the_sdram_system_new_sdram_controller_0_input_efifo_module__wr = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries = VL_RAND_RESET_I(2);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_0 = VL_RAND_RESET_Q(41);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entry_1 = VL_RAND_RESET_Q(41);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__rd_address = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<17; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__quotient_pipe[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<17; ++__Vi0) {
        vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__remain_pipe[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_quotient = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__tmp_remain = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__divider__DOT__pipe_ptr = VL_RAND_RESET_I(32);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_divider_counter = VL_RAND_RESET_I(10);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__previous_spi_clock = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__spi_clock_falling = VL_RAND_RESET_I(1);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__bits_to_send = VL_RAND_RESET_I(4);
    vlSelf->verilator_test__DOT__top_instantiation__DOT__spi_controller__DOT__ticks_since_transmit_pulse = VL_RAND_RESET_I(14);
    vlSelf->__Vdlyvdim0__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 = 0;
    vlSelf->__Vdlyvval__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 = VL_RAND_RESET_I(7);
    vlSelf->__Vdlyvset__verilator_test__DOT__top_instantiation__DOT__integrated_graphics__DOT__text_buffer__DOT__ram_buffer__v0 = 0;
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_counter = VL_RAND_RESET_I(13);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__refresh_request = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller_init_done = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_count = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_next = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__i_refs = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__f_pop = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_state = VL_RAND_RESET_I(9);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_next = VL_RAND_RESET_I(9);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__m_count = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_rnw = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_addr = VL_RAND_RESET_I(22);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_data = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__active_dqm = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__entries = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__verilator_test__DOT__top_instantiation__DOT__sdram_controller__DOT__the_sdram_system_new_sdram_controller_0_input_efifo_module__DOT__wr_address = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
